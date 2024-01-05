#include <stdio.h>
#define Max_Vertices 100

typedef struct{
	int n,m;
	int A[Max_Vertices][Max_Vertices]; 
}Graph;

//khoi tao do thi
void init_graph(Graph *pG,int n){
	pG->n=n;
	pG->m=0;
	for(int u=1;u<=n;u++){
		for(int v=1;v<=n;v++){
			pG->A[u][v]=0;
		}
	}
}

//them cung vao do thi co huong
void add_edge(Graph *pG,int u, int v){
	if(u==v){
		pG->A[u][v]+=1;
		return;
	}
	pG->A[u][v]+=1;
	pG->A[v][u]+=1;
	pG->m++;
}
