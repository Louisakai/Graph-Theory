#include <stdio.h>
#define MAXN 100
#define MAXM 500
#define oo 999999

typedef struct {
	int W[MAXN][MAXN];
	int n;
}Graph;

void init_graph(Graph *pG, int n){
	pG->n=n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			pG->W[i][j]=0;
}

void add_edge(Graph *pG, int u, int v, int w){
	pG->W[u][v]=w;
	pG->W[v][u]=w;
}

int pi[MAXN];
int p[MAXN];
int mark[MAXN];

int Prim (Graph *pG, Graph *pT, int s){
	int i, u, x, y;
	
	for(i = 1; i <= pG->n ; i++){
		pi[i]=oo;
		p[i]=-1;
		mark[i]=0;
	}
	
	pi[s]=0;
	
	for(i=1; i<pG->n; 	i++){
		int min_dist=oo;
		for(x=1;x<=pG->n;x++){
			if(mark[x]==0 && pi[x]<min_dist){
				min_dist = pi[x];
				u = x;
			}
		}
		
		mark[u]=1;
		
		for(y=1;y<=pG->n;y++){
			if(pG->W[u][y]!=0)
				if(mark[y]==0 && pi[y] > pG->W[u][y]){
						pi[y]=pG->W[u][y];
						p[y]=u;
				}
		}
	}
	
	int sum_w=0;
	
	for(u=1;u<=pG->n;u++){
		if(p[u]!=-1){
			int w = pG->W[p[u]][u];
			add_edge(pT, p[u], u, w);
			sum_w+=w;
		}
	}
	return sum_w;
}

int main(){
	Graph G, T;
	int n, m;
	freopen("Prim.txt" , "r" , stdin);
	scanf("%d%d",&n, &m);
	init_graph(&G, n);
	init_graph(&T, n);
	int e, u, v, w;
	for(e=1;e<=m;e++){
		scanf("%d%d%d",&u, &v, &w);
		add_edge(&G,u,v,w);
	}
	int sum_w = Prim(&G, &T, 1);
	
	int i, j;
	printf("%d\n",sum_w);
	
	for(i=1;i<=T.n;i++){
		for(j=1;j<=T.n;j++){
			if(T.W[i][j]!=0){
				printf("%d %d %d\n",i,j,T.W[i][j]);
				T.W[j][i]=0;	
			}
		}
	}
	
	return 0;
}
