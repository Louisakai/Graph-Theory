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
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}

//kiem tra u ke voi v
int adjacent(Graph *pG,int u, int v){
	int e;
	for(e=0;e<pG->m;e++){
		if(pG->edges[e].u==u && pG->edges[e].v==v)
			return 1;
	}
	return 0;
}

//tinh bac cua dinh
int degree(Graph *pG,int u){
	int e,deg=0;
	for(e=0;e<pG->m;e++){
		if(pG->edges[e].u==u && pG->edges[e].v==u){
			deg+=2;
			continue;
		}
		if(pG->edges[e].u==u || pG->edges[e].v==u)
			deg++;
	}
	return deg;
}

//dinh ke cua do thi vo huong
void neighbors(Graph *pG,int u){
	int e;
	for(e=1;e<=pG->n;e++){
		print("neighbors(%d) = ",e);
		if(adjacent(pG,u,i)){
			print("%d ",i);
		}
	}
}

//ham main
int main(){
	Graph G;
	int n,m,u,v;
	freopen("dothi.txt","r",stdin);
	scanf("%d %d",&n,&m);
	init_graph(&G,n);
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	for(int i=1;i<=n;i++){
	    printf("deg(%d) = %d\n",i,degree(&G,i));
	}
	return 0;
}
