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

//them cung vao da do thi co huong
void add_edge(Graph *pG, int u, int v){
	if(u==v){
		push_back(&pG->adj[u],v);
		return;	
	}
	push_back(&pG->adj[u],v);
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

//tinh bac cua u
int degree(Graph *pG, int u){
	return count_list(&pG->adj[u]);
}

//ham main
int main(){
	Graph G;
	int n,m,u,v,i;
	printf("Nhap n,m: ");
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(i=0;i<m;i++){
		printf("Nhap cung: ");
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	printf_graph(&G);
	printf("Nhap dinh ban muon tim bac: ");
	scanf("%d",&n);
	printf("bac cua dinh %d la: %d",n,degree(&G,n)); 
	return 0;
}