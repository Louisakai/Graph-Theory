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

void copy_list(List *pL1, List *pL2){
	pL1->size=pL2->size;
	for(int i=0;i<pL2->size;i++){
		pL1->data[i] = pL2->data[i];
	}
}

int d[MAXN];
int r[MAXN];

void rank(Graph *pG){
	
	for(int u=1;u<=pG->n;u++){
		d[u]=0;
	}
	
	for(int u=1;u<=pG->n;u++){
		for(int x=1;x<=pG->n;x++){
			if(pG->A[u][x]!=0)
				d[x]++;
		}
	}
	
	List L1, L2;
	make_null_list(&L1);
	
	for(int u=1;u<=pG->n;u++){
		if(d[u]==0)
			push_back(&L1, u);
	}
	
	int k=0;
	while(L1.size>0){
		make_null_list(&L2);
		for(int i=1;i<=L1.size;i++){
			int u = element_at(&L1,i);
			r[u]=k;
			
			for(int v=1;v<=pG->n;v++)
				if(pG->A[u][v]!=0){
					d[v]--;
					if(d[v]==0)
						push_back(&L2,v);
			}
		}
		copy_list(&L1,&L2);
		k++;
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
	int sum=0;
	rank(&G);
	for(e=1;e<=n;e++){
		printf("r[%d] = %d\n",e,r[e]);
	}
	return 0;
}
