#define Max_N 100
#define Max_Elements 100
#include <stdio.h>

//cau truc danh sach
typedef struct{
	int data[Max_Elements];
	int size;
}List;

//cau truc danh sach ke
typedef struct{
	List adj[Max_N];
	int n;
}Graph;

//cau truc ma tran ke
typedef struct{
	int A[Max_N][Max_N];
	int n;
}MTK_Graph;

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

//khoi tao do thi MTK
void init_mtk_graph(MTK_Graph *pG, int n){
	pG->n=n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			pG->A[i][j]=0;
		}
	}
}

//them cung vao MTK
void add_edge(MTK_Graph *pG, int u, int v){
	if(u==v){
		pG->A[u][u]+=1;
		return;
	}
	pG->A[u][v]+=1;
}

//DSK sang MTK
void dsk_mtk(Graph *pG, MTK_Graph *pR){
	int i,j=0;
	for(i=1;i<=pG->n;i++){
		while(pG->adj[i].data[j]!=0){
			add_edge(pR,i,pG->adj[i].data[j]);
			j++;
		}
		j=0;
	}
}

//in ma tran ke
void print_graph(MTK_Graph *pG){
	int i,j;
	for(i=1;i<=pG->n;i++){
		for(j=1;j<=pG->n;j++){
			printf("%d ",pG->A[i][j]);
		}
		printf("\n");
	}
}


//ham main
int main(){
	Graph G;
	MTK_Graph R;
	int n,v=1,i;
	scanf("%d",&n);
	init_graph(&G,n);
	init_mtk_graph(&R,n);
	for(i=1;i<=n;i++){
		while(v!=0){
			scanf("%d",&v);
			push_back(&G.adj[i],v);	
		}
		v=1;
	}
	dsk_mtk(&G,&R);
	print_graph(&R);
	return 0;
}