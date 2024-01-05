#define Max_N 100
#define Max_M 500
#include <stdio.h>

typedef struct{
	int A[Max_n][Max_M];
	int n,m;
}Graph;

//khoi tao do thi dinh cung
void init_graph(Graph *pG,n,m){
	pG->n=n;
	pG->m=m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			pG->A[i][j]=0;
		}
	}
}

//them cung e=(u,v) vao do thi
void add_edge(Graph *pG, int u, int v, int e){
	pG->A[u][e]+=1;
	pG->A[v][e]+=1;
}

//kiem tra u ke v
int adjacent(Graph *pG, int u, int v){
	int e;
	for(e=1;e<=pG->m;e++){
		if(pG->A[u][e]==1 && pG->A[v][e]==1)
			return 1;
	}
	return 0;
}