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
	}
	pG->adj[u].push_back(v);
	pG->adj[v].push_back(u);
}