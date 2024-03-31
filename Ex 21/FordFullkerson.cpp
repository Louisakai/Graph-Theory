#define MAXN 100
#define oo 999999
#include <stdio.h>

typedef struct {
	int C[MAXN][MAXN];
	int F[MAXN][MAXN];
	int n;
}Graph;

void init_graph(Graph *pG, int n){
	pG->n=n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			pG->C[i][j]=0;
		}
	}
}

void init_flow(Graph *pG){
	for(int u=1; u<=pG->n; u++){
		for(int v=1; v<=pG->n; v++){
			pG->F[u][v]=0;
		}
	}
}

typedef struct{
	int data[MAXN];
	int front, rear;
}Queue;

void make_null_queue(Queue *pQ){
	pQ->front=0;
	pQ->rear=1;
}

int empty_queue(Queue *pQ){
	return (pQ->front > pQ->rear);
}

void enqueue(Queue *pQ, int x){
	pQ->data[++pQ->rear]=x;
}

void dequeue(Queue *pQ){
	pQ->front++;
}

int front(Queue *pQ){
	return pQ->data[pQ->front];
}

typedef struct{
	int dir;
	int p;
	int sigma;
}Label;

int min(int a, int b){
	if(a>b)
		return b;
	return a;
}

Label labels[MAXN];

int FordFullkerson(Graph *pG, int s, int t){
	init_flow(pG);
	int max_flow = 0;
	
	Queue Q;
	do {
		for(int u=1; u<=pG->n; u++)
			labels[u].dir=0;
		labels[s].dir = +1;
		labels[s].p = s;
		labels[s].sigma = oo;
		
		make_null_queue(&Q);
		enqueue(&Q, s);
		
		int found = 0;
		while(!empty_queue(&Q)){
			int u = front(&Q); dequeue(&Q);
			
			for(int v=1; v<=pG->n; v++){
				if(pG->C[u][v]!=0 && labels[v].dir == 0 && pG->F[u][v] < pG->C[u][v]){
					labels[v].dir = +1;
					labels[v].p = u;
					labels[v].sigma = min(labels[u].sigma, pG->C[u][v] - pG->F[u][v]);
					enqueue(&Q, v);
				}
			}
			
			for(int x=1; x<=pG->n; x++){
				if(pG->C[x][u]!=0 && labels[x].dir == 0 && pG->F[x][u]>0){
					labels[x].dir = -1;
					labels[x].p = u;
					labels[x].sigma = min(labels[u].sigma, pG->F[x][u]);
					enqueue(&Q, x);
				}
			}
			
			if(labels[t].dir !=0){
				found = 1;
				break;
			}
		}
		if(found == 1){
			int sigma = labels[t].sigma;
			
			int u = t;
			while(u != s){
				int p = labels[u].p;
				if(labels[u].dir > 0)
					pG->F[p][u] += sigma;
				else
					pG->F[u][p] -= sigma;
				u=p;
			}
			max_flow += sigma;
		} else
			break;
	} while(1);
	
	return max_flow;
}

int main(){
	Graph G;
	int n, m, u, v, e, c;
	freopen("data.txt","r",stdin);
	scanf("%d%d",&n ,&m);
	init_graph(&G, n);
	
	for(e=0; e<m; e++){
		scanf("%d%d%d",&u, &v, &c);
		G.C[u][v]=c;
	}
	int max_flow = FordFullkerson(&G, 1, n);
	printf("Max flow: %d\n", max_flow);
	
	return 0;
}
