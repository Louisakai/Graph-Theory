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

int in_deg[MAXN];

void topo_sort(Graph *pG, List *pL){
	for(int u=1;u<=pG->n;u++){
		in_deg[u]=0;
	}
	
	for(int u=1;u<=pG->n;u++){
		for(int x=1;x<=pG->n;x++){
			if(pG->A[u][x]!=0)
				in_deg[x]++;
		}
	}
	
	Queue Q;
	make_null_queue(&Q);
	
	for(int u=1;u<=pG->n;u++){
		if(in_deg[u]==0)
			enqueue(&Q,u);
	}
	
	make_null_list(pL);
	while(!empty(&Q)){
		int u = front(&Q);
		dequeue(&Q);
		push_back(pL,u);
		
		for(int v=1;v<=pG->n;v++){
			if(pG->A[u][v]!=0){
				in_deg[v]--;
				if(in_deg[v]==0)
					enqueue(&Q,v);
			}
		}
	}
}

int max(int u, int v){
	if(u>v)
		return u;
	return v;
}

int min(int u, int v){
	if(u>v)
		return v;
	return u;
}

int d[MAXN]; //thoi gian hoan thanh cong viec

int main(){
	Graph G;
	int n, m;
	freopen("6.txt","r", stdin);
	scanf("%d",&n);
	init_graph(&G,n+2);
	int alpha = n+1, beta = n+2;
	d[alpha]=0;
	int e, u, v, x, j;
	
	for(e=1;e<=n;e++){
		scanf("%d ",&d[e]);
	}
	
	scanf("%d",&m);
	for(e=1;e<=m;e++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	
	for(u=1;u<=n;u++){
		int deg_neg=0; //bac vao
		for(x=1;x<=n;x++)
			if(G.A[x][u]>0)
				deg_neg++;
		if(deg_neg == 0)
			add_edge(&G,alpha,u);
	}
	
	for(u=1;u<=n;u++){
		int deg_pos=0; //bac ra
		for(v=1;v<=n;v++)
			if(G.A[u][v]>0)
				deg_pos++;
		if(deg_pos == 0)
			add_edge(&G,u,beta);
	}
	
	List L;
	topo_sort(&G,&L);
	
	int t[MAXN];
	t[alpha]=0;
	
	for(j=2;j<=L.size;j++){
		int u = element_at(&L,j);
		t[u]= -999999;
		for(x=1;x<=G.n;x++)
			if(G.A[x][u]>0)
				t[u] = max(t[u],t[x]+d[x]);
	}
	
	int T[MAXN];
	T[beta] = t[beta];
	
	for(j=L.size-1 ; j>=1 ; j--){
		int u = element_at(&L, j);
		T[u] = 999999;
		for(v=1 ; v<=G.n ;v++)
			if(G.A[u][v]>0)
				T[u] = min(T[u],T[v]-d[u]);
	}
	
	printf("%d", t[G.n]);
	
	return 0;
}
