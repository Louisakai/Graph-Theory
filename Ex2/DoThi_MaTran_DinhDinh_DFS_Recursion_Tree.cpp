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
	G->A[y][x]=1;
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

//khai bao cau truc ngan xep
typedef struct{
	int data[Max_Element];
	int size;
}Stack;

//khoi tao ngan xep rong
void make_null_stack(Stack *stack){
	stack->size=0;
}

//them mot phan tu vao trong ngan xep
void push_stack(Stack *stack, int x){
	stack->data[stack->size] = x;
	stack->size++;
}

//lay mot phan tu trong ngan xep
int top(Stack *stack){
	return stack->data[stack->size-1];
}

//xoa mot phan tu cua stack
void pop(Stack *stack){
	stack->size--;
}

//kiem tra stack co rong khong
int emptystack(Stack *stack){
	return (stack->size == 0);
}

int mark[Max_Vertices];
int parent[Max_Vertices];
//duyet do thi theo chieu sau bang de quy
void DFS_Recursion(Graph *G, int u, int p){
	if(mark[u]==1)
		return;
	//printf("Duyet: %d\n",u);
	parent[u]=p;
	mark[u]=1;
	List list = neighbors(G,u);
	int i;
	for(i=1;i<=list.size;i++){
		int v = element_at(&list,i);
		DFS_Recursion(G,v,u);
	}
}

//ham main
int main() {
	Graph G;
	freopen("DFS_Recursion.txt","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	ini_Graph(&G,n);
	int i,u,v;
	for	(i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	
	for(i=1;i<=n;i++){
		mark[i]=0;
		parent[i]=-1;
	}
	
	for(i=1;i<=n;i++){
		if(mark[i]==0){
			DFS_Recursion(&G,i,0);
		}
	}
	
	for(i=1;i<=n;i++){
		printf("%d %d\n",i,parent[i]);
	}
	return 0;
}