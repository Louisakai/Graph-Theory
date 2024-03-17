#include <stdio.h>
#define MAXN 100
#define MAXM 500

typedef struct {
	int u, v;
	int w;
}Edge;

typedef struct {
	Edge edge[MAXN];
	int n, m;
}Graph;

void init_graph(Graph *pG, int n){
	pG->n=n;
	pG->m=0;
}

void add_edge(Graph *pG, int u, int v, int w){
	pG->edge[pG->m].u=u;
	pG->edge[pG->m].v=v;
	pG->edge[pG->m].w=w;
	pG->m++;
}

int parent[MAXN];

int findroot(int u){
	if(parent[u] == u)
		return u;
	return findroot(parent[u]);
}

int Kruskal(Graph *pG, Graph *pT){
	Edge tmp;
	int i, j, e;
	for(i=0;i<pG->m-1;i++){
		for(j=i+1;j<pG->m;j++){
			if(pG->edge[j].w < pG->edge[i].w || (pG->edge[j].w == pG->edge[i].w && pG->edge[j].v < pG->edge[i].v)){
				tmp = pG->edge[i];
				pG->edge[i] = pG->edge[j];
				pG->edge[j] = tmp;
			}
		}
	}
	
	for(int u=1; u<=pG->n;u++){
		parent[u]=u;
	}
	int sum_w=0;
	
	for(e=0;e<pG->m;e++){
		int u = pG->edge[e].u;
		int v = pG->edge[e].v;
		int w = pG->edge[e].w;
		int root_u = findroot(u);
		int root_v = findroot(v);
		if(root_u != root_v){
			add_edge(pT, u, v, w);
			
			parent[root_v]= root_u;
			sum_w+= w;
		}
	}
	return sum_w;
}

int main(){
	Graph G, T;
	int n, m;
	freopen("Kruskal.txt","r",stdin);
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	init_graph(&T,n);
	int e, u, v, w;
	for(e=0;e<m;e++){
		scanf("%d%d%d",&u,&v,&w);
		add_edge(&G, u, v, w);
	}
	
	int sum_w = Kruskal(&G, &T);
	printf("%d\n",sum_w);
	for(e=0;e<T.m;e++){
		if(T.edge[e].u > T.edge[e].v){
			int temp = T.edge[e].u;
			T.edge[e].u = T.edge[e].v;
			T.edge[e].v = temp;
		}
		printf("%d %d %d\n",T.edge[e].u ,T.edge[e].v ,T.edge[e].w);
	}
	
	
	return 0;
}
