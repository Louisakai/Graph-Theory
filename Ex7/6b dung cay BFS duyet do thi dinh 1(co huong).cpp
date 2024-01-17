#include <stdio.h>
#define Max_Vertices 20
#define Max_Length 20
#define Max_Element 40

//khai bao cau truc do thi
typedef struct {
	int A[Max_Vertices][Max_Vertices];
	int n; //so luong dinh
} Graph;

//khoi tao do thi
void ini_Graph(Graph *G, int n) {
	int i,j;
	G->n = n;
	for (i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			G->A[i][j] = 0;
}

//in do thi
void print_Graph(Graph *G) {
	int i,j;
	for(i=1; i<=G->n; i++) {
		for(j=1; j<=G->n; j++)
			printf("%d ",G->A[i][j]);
		printf("\n");
	}
}

//them cung vao do thi
void add_edge(Graph *G,int x, int y) {
	G->A[x][y]=1;
//	G->A[y][x]=1;
}

//kiem tra dinh x, y co phai la lang gieng cua nhau k
int adjacent(Graph *G, int x, int y){
	return (G->A[x][y]!=0);
}

//tinh bac cua dinh x
int degree(Graph *G, int x){
	int i, deg=0;
	for(i=1;i<=G->n;i++){
			if(adjacent(G,i,x)==1)
				deg++;
	}
	return deg;
}

//khai bao cau truc danh sach list
typedef struct{
	int data[Max_Length];
	int size;
}List;

//khoi tao danh sach rong
void make_null(List *list){
	list->size=0;
}

//them mot phan tu vao cuoi danh sach
void push_back(List *list, int x){
	list->data[list->size] = x;
	list->size++;
}

//lay mot phan tu trong danh sach tai vi tri i
int element_at(List *list, int i){
	return list->data[i-1];
}

//them phan tu lang gieng cua dinh x vao danh sach
List neighbors(Graph *G, int x){
	List L;
	make_null(&L);
	int i;
	for(i=1;i<=G->n;i++)
		if(adjacent(G,i,x)==1)
			push_back(&L,i);
	return L;
}

typedef struct{
	int u,p;
}ElementType;

//cau truc hang doi
typedef struct{
	ElementType data[Max_Element];
	int front;
	int rear;
}Queue;

//khoi tao hang doi rong
void make_null_Queue(Queue *Q){
	Q->front=0;
	Q->rear=-1;
}

//them mot phan tu vao hang doi
void push_Queue(Queue *Q, ElementType x){
	Q->rear++;
	Q->data[Q->rear]=x;
}

//kiem tra hang doi co rong hay khong
int empty_Queue(Queue *Q){
	return (Q->front>Q->rear);
}

//lay mot phan tu o dau hang doi
ElementType top(Queue *Q){
	return Q->data[Q->front];
}

//xoa phan tu o dau hang doi
void pop(Queue *Q){
	Q->front++;
}

int mark[Max_Vertices];
int parent[Max_Vertices];

//duyet do thi theo chieu rong
void breath_first_search(Graph *G,int x){
	Queue Q;
	make_null_Queue(&Q);
	int i;
	ElementType tmp;
	tmp.u=x; tmp.p=-1;
	push_Queue(&Q,tmp);
	while(!empty_Queue(&Q)){
		ElementType tmp = top(&Q);
		pop(&Q);
		int u = tmp.u, p= tmp.p;
		if(mark[u]==1)
			continue;
		printf("Duyet: %d\n",u);
		mark[u]=1;
		parent[u]=p;
		List L;
		make_null(&L);
		L = neighbors(G,u);
		int v;
		for(i=1;i<=L.size;i++){
			v = element_at(&L,i);
			if(mark[v]==0){
				ElementType tmp;
				tmp.u=v; tmp.p=u;
				push_Queue(&Q,tmp);	
			}
		}
	}
}

//ham main
int main() {
	Graph G;
	//freopen("BFS.txt","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	ini_Graph(&G,n);
	int i,e,u,v;
	for(e=1;e<=m;e++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	for(i=1;i<=n;i++){
		mark[i]=0;
	}
	breath_first_search(&G,1);
	for(i=1;i<=n;i++){
		printf("dinh cha cua %d: %d\n",i,parent[i]);
	}
	return 0;
}
