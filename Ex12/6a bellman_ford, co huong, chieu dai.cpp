#define Max_N 100
#define Max_M 500
#define Max_W 1000
#define inf 999999
#define No_edge 0
#include <stdio.h>

//cau truc edge
typedef struct {
	int u, v;
	int w;
}Edge;

//cau truc graph
typedef struct {
	int n,m;
	Edge edge[Max_M];
}Graph;

//khoi tao do thi
void init_graph(Graph *pG, int n){
	pG->m=0;
	pG->n=n;
}

//ham them cung vao do thi
void add_edge(Graph *pG, int u, int v, int w){
	pG->edge[pG->m].u=u;
	pG->edge[pG->m].v=v;
	pG->edge[pG->m].w=w;
	pG->m++;
}

int pi[Max_N];
int p[Max_N];

//thuat toan Bellman-Ford
void Bellman_Ford(Graph *pG, int s){
	int u, v, w, it, k;
	for(u=1;u<=pG->n;u++){
		pi[u]=inf;
	}
	pi[s]=0;
	p[s]=-1;
	for(it=1;it<pG->n;it++){
		for(k=0;k<pG->m;k++){
			u=pG->edge[k].u;
			v=pG->edge[k].v;
			w=pG->edge[k].w;
			
			if(pi[u] == inf)
				continue;
			if(pi[u]+w<pi[v]){
				pi[v]=pi[u]+w;
				p[v]=u;
			}
		}
	}
	
	//kiem tra co chu trinh am hay khong
	int negative_cycle =0;
	for(k=0;k<pG->m;k++){
		u=pG->edge[k].u;
		v=pG->edge[k].v;
		w=pG->edge[k].w;
		if(pi[u]+w<pi[v]){
			negative_cycle = 1;
			break;
		}
	}
}

//ham main
int main(){
	Graph G;
	int n,m,u,v,w,i,s,t;
	printf("Nhap n, m: ");
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(i=1;i<=m;i++){
		printf("Nhap u, v, w: ");
		scanf("%d%d%d",&u,&v,&w);
		add_edge(&G,u,v,w);
	}
	
	printf("Nhap s, t: ");
	scanf("%d%d",&s,&t);
	Bellman_Ford(&G,s);
	printf("%d",pi[t]);
	return 0;
}
