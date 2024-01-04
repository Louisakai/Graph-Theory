#include <stdio.h>
#define Max_M 500
typedef struct{
	int u,v;
}Edge;

typedef struct{
	Edge edges[Max_M];
	int n,m;
}Graph;

//khoi tao do thi
void init_graph(Graph *pG, int n){
	pG->n=n;
	pG->m=0;
}

//them cung vao do thi
void add_edge(Graph *pG, int u, int v){
	if(u<1 || v<1 || u>pG->n || v>pG->n)
			return;
	for(int i=0;i<pG->m;i++){
		if(pG->edges[i].u==u && pG->edges[i].v==v || pG->edges[i].u==v && pG->edges[i].v==u)
			return;
	}
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

//ham main
int main(){
	Graph G;
	int n,m,u,v;
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(int i=0;i<m;i++){
		printf("nhap cung: ");
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	return 0;
}
