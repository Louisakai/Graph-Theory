#define MAX_N 100
#define MAX_M 500
#define oo 999999
#define NO_EDGE 0
#include <stdio.h>

typedef struct {
	int A[MAX_N][MAX_N];
	int n;
}Graph;

void init_graph(Graph *pG, int n){
	pG->n=n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			pG->A[i][j]=0;
		}
	}
}

void add_edge(Graph *pG, int u, int v, int w){
	pG->A[u][v]=w;
}

int adjacent(Graph *pG, int u, int v){
	return pG->A[u][v]!=0;
}

int mark[MAX_N], pi[MAX_N], p[MAX_N];

void Moore_Dijkstra(Graph *pG,int s){
	int it, min_pi, i, j, v, u;
	for(i=1;i<=pG->n;i++){
		pi[i]=oo;
		p[i]=0;
		mark[i]=0;
	}
	pi[s]=0;
	p[s]=-1;
	
	for(it=1;it<pG->n;it++){
		min_pi = oo;
		for(j=1;j<=pG->n;j++){
			if(mark[j]==0 && pi[j]<min_pi){
				min_pi=pi[j];
				u=j;
			}
		}
		mark[u]=1;
		for(v=1; v<=pG->n;v++){
			if(pG->A[u][v]!=NO_EDGE && mark[v]==0){
				if(pi[u]+pG->A[u][v]<pi[v]){
					pi[v] = pi[u] + pG->A[u][v];
					p[v]=u;
				}
			}
		}
	}
}

int main(){
	int maze[MAX_N][MAX_N];
	int m, n, i, j, k, x, u, v, ii, jj;
	scanf("%d%d",&m,&n);
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&x);
			maze[i][j]=x;
		}
	}
	
//	for(i=0;i<m;i++){
//		for(j=0;j<n;j++){
//			printf("%d ",maze[i][j]);
//		}
//		printf("\n");
//	}

	Graph G;
	init_graph(&G,m*n);
	int di[]={-1, 1, 0, 0};
	int dj[]={0, 0, -1, 1};
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			u=(i*n+j)+1;
			for(k=0;k<=3;k++){
				ii = i + di[k];
				jj = j + dj[k];
				if(ii>=0 && ii<m && jj>=0 && jj<n){
					v = ii*n + jj +1;
					add_edge(&G,u,v,maze[(v-1)/n][(v-1)%n]);
				}
			}
		}
	}
	
	for(i=1;i<=m*n;i++){
		for(j=1;j<=n*m;j++){
			if(adjacent(&G,i,j))
				printf("%d %d %d\n",i,j,maze[(j-1)/n][(j-1)%n]);
		}
	}

//	Moore_Dijkstra(&G,1);
//	printf("%d\n",pi[m*n]);
	
	return 0;
}
