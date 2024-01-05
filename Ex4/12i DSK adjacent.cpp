#define Max_Elements 100
#define Max_N 100
#include <stdio.h>

typedef struct{
	int data[Max_Elements];
	int size;
}List;

typedef struct{
	List adj[Max_N];
	int n;
}Graph;

//khoi tao list
void make_null(List *pL){
	pL->size=0;
}

//them phan tu x vao cuoi danh sach
void push_back(List *pL, int x){
	pL->data[pL->size]=x;
	pL->size++;
}

//phan tu tai vi tri i, bat dau tu 1
int element_at(List *pL, int i){
	return pL->data[i-1];
}

//so phan tu cua danh sach
int count_list(List *pL){
	return pL->size;
}

//khoi tao do thi
void init_graph(Graph *pG, int n){
	int u;
	pG->n=n;
	for(u=1;u<=n;u++){
		make_null(&pG->adj[u]);
	}
}

//in do thi
void printf_graph(Graph *pG){
	int i,j;
	for(i=1;i<=pG->n;i++){
		printf("adj(%d) =",i);
		for(j=0;j<pG->adj[i].size;j++){
			printf(" %d",pG->adj[i].data[j]);
		}
		printf("\n");
	}
}

//them cung vao do thi vo huong
void add_edge(Graph *pG, int u, int v){
	push_back(&pG->adj[u],v);
	push_back(&pG->adj[v],u);
}

//kiem tra u ke v
int adjacent(Graph *pG, int u, int v){
	int i;
	for(i=1;i<=pG->adj[u].size;i++){
		if(element_at(&pG->adj[u],i)==v)
			return 1;
	}
	return 0;
}