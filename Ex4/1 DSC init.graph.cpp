#include <stdio.h>
#define Max_M 500

//khai bao cau truc canh
typedef struct {
	int u, v;
}Edge;

//khai bao cau truc do thi
typedef struct {
	int n,m;
	Edge edge[Max_M];
}Graph;

//ham khoi tao do thi
void init_graph(Graph *pG, int n){
	pG->n=n;
	pG->m=0;
}

//ham main
int main(){
	Graph G;
	int n;
	scanf("%d",&n);
	init_graph(&G,n);
	printf("Do thi co %d dinh va %d cung",G.n,G.m);
	return 1;
}