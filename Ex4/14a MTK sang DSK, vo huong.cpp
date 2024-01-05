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

//kiem tra u ke v
int adjacent(Graph *pG, int u, int v){
	return (pG->A[u][v]!=0);
}

//in ra dinh ke cua u
void neighbours(Graph *pG, int u){
	int i,j;
	for(i=1;i<=pG->n;i++){
		for(j=1;j<=pG->n;j++){
			while(pG->A[i][j]!=0){
				printf("%d ",j);
				pG->A[i][j]--;
			}
		}
		printf("0 \n");
	}
}

//main
int main(){
	Graph G;
	int n,i,j,v;
	scanf("%d",&n);
	init_graph(&G,n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&v);
			G.A[i][j]=v;
		}
	}
	neighbours(&G,i);
	return 0;
}
