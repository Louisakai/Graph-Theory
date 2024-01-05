#define Max_N 100
#define Max_M 500
#include <stdio.h>

typedef struct{
	int A[Max_n][Max_M];
	int n,m;
}Graph;

//in do thi
void print_graph(Graph *pG){
	int i,j;
	for(i=1;i<=pG->n;i++){
		for(j=1;j<=pG->m;j++){
			printf(" %d",pG->A[i][j]);
		}
		printf("\n");
	}
}