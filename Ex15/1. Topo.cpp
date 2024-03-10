#define MAXN 100
#define MAXM 500
#include <stdio.h>

typedef struct {
	int A[MAXN][MAXN];
	int n;
}Graph;

void init_graph(Graph *pG, int n){
	pG->n=n;
	for(int i=1;i<=pG->n;i++){
		for(int j=1;j<=pG->n;j++){
			pG->A[i][j]=0;
		}
	}
}

void add_edge(Graph *pG,int u, int v){
	pG->A[u][v]=1;
}

int adjacent(Graph *pG, int u, int v){
	return pG->A[u][v]!=0;
}

typedef struct{
	int data[MAXN];
	int rear, front;
}Queue;

void make_null_queue(Queue *pQ){
	pQ->front=0;
	pQ->rear=-1;
}

int empty(Queue *pQ){
	return pQ->front > pQ->rear;
}

void enqueue(Queue *pQ, int x){
	pQ->rear++;
	pQ->data[pQ->rear]=x;
}

void dequeue(Queue *pQ){
	pQ->front++;
}

int front(Queue *pQ){
	return pQ->data[pQ->front];
}

typedef struct{
	int data[MAXN];
	int size;
}List;

void make_null_list(List *pL){
	pL->size=0;
}

void push_back(List *pL,int x){
	pL->data[pL->size]=x;
	pL->size++;
}

int element_at(List *pL, int i){
	return pL->data[i-1];
}

int d[MAXN];

void topo_sort(Graph *pG, List *pL){

	
	for(int u=1;u<=pG->n;u++){
		d[u]=0;
	}
	
	for(int u=1;u<=pG->n;u++){
		for(int x=1;x<=pG->n;x++){
			if(pG->A[u][x]!=0)
				d[x]++;
		}
	}
	
//	for(int u=1;u<=pG->n;u++){
//		d[u]=0;
//		for(int x=1;x<=pG->n;x++){
//			if(pG->A[x][u]!=0)
//				d[u]++;
//		}
//	}
	
	Queue Q;
	make_null_queue(&Q);
	
	for(int u=1;u<=pG->n;u++){
		if(d[u]==0)
			enqueue(&Q,u);
	}
	
	make_null_list(pL);
	while(!empty(&Q)){
		int u = front(&Q);
		dequeue(&Q);
		push_back(pL,u);
		
		for(int v=1;v<=pG->n;v++){
			if(pG->A[u][v]!=0){
				d[v]--;
				if(d[v]==0)
					enqueue(&Q,v);
			}
		}
	}
}

int main(){
	Graph G;
	int n,m;
	freopen("1.txt","r", stdin);
	scanf("%d%d",&n,&m);
	init_graph(&G,n);

	int e, u, v;
	for(e=1;e<=m;e++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	
	List L;
	topo_sort(&G,&L);
	for(e=1;e<=L.size;e++){
		printf("%d ",element_at(&L, e)); 
	}

	return 0;
}
