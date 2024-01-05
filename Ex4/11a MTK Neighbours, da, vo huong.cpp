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

//them cung vao do thi vo huong
void add_edge(Graph *pG,int u, int v){
	if(u==v){
		pG->A[u][u]+=1;
		return;
	}
	pG->A[u][v]+=1;
	pG->A[v][u]+=1;
	pG->m++;
}

//in ma tran ke
void print_graph(Graph *pG){
	int i,j;
	printf("Ma tran ke: \n");
	for(i=1;i<=pG->n;i++){
		for(j=1;j<=pG->n;j++){
			printf("%d ",pG->A[i][j]);
		}
		printf("\n");
	}
}

//kiem tra u ke v
int adjacent(Graph *pG, int u, int v){
	return (pG->A[u][v]!=0);
}

//in ra dinh ke cua u
void neighbours(Graph *pG, int u){
	int i;
	for(i=1;i<=pG->n;i++){
		if(adjacent(pG,i,u))
			printf(" %d",i);
	}
}

//main
int main(){
	Graph G;
	int n,m,u,v,i;
	//freopen("test.txt","r",stdin);
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	for(i=1;i<=G.n;i++){
		printf("neighbours(%d) =",i);
		neighbours(&G,i);
		printf("\n");
	}
	return 0;
}
