#include <stdio.h>

#include <vector>
using namespace std;

#define Max_N 100

//cau truc do thi su dung vecto
typedef struct{
	int n;
	vector<int> adj[Max_N];
}Graph;

//ham khoi tao
void init_graph(Graph *pG, int n){
	pG->n=n;
	int u;
	for(u=1;u<=n;u++){
		pG->adj[u].clear();
	}
}

//ham them cung (u,v)
void add_edge(Graph *pG, int u, int v){
	if(u==v){
		pG->adj[u].push_back(v);
		return;
	}
	pG->adj[u].push_back(v);
}

//ham tinh bac dinh u
int degree(Graph *pG, int u){
	return pG->adj[u].size();
}

//ham in
void print_graph(Graph *pG){
	int i,j;
	for(i=1;i<=pG->n;i++){
		printf("dinh %d:",i);
		for(j=0;j<pG->adj[i].size();j++){
			printf(" %d",pG->adj[i].at(j));
			}
		printf("\n");
	}
}

//ham main
int main(){
	Graph G;
	int n,m,u,v,i,e;
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(i=1;i<=m;i++){
		printf("nhap cung: ");
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	print_graph(&G);
	printf("nhap dinh ban muon tim bac: ");
	scanf("%d",&e);
	int k=degree(&G,e);
	printf("dinh %d co bac: %d",e,k);
	return 0;
}