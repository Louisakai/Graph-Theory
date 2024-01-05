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