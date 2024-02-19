#define Max_N 100
#define Max_M 500
#define Max_W 1000
#define inf 999999
#define No_edge 0
#include <stdio.h>

//cau truc graph
typedef struct {
	int n;
	int w[Max_N][Max_N];
}Graph;

//Ham khoi tao do thi
void init_graph(Graph *pG, int n){
	pG->n=n;
	int u, v;
	for(u=1;u<=n;u++){
		for(v=1;v<=n;v++){
			pG->w[u][v]=No_edge;
		}
	}
}

//Ham them cung do thi vo huong
void add_edge(Graph *pG,int u,int v, int w){
	pG->w[u][v]=w;
//	pG->w[v][u]=w;
}

//Ham kiem tra dinh ke
int adjacent(Graph *pG, int u, int v){
	if(pG->w[u][v]!=No_edge)
		return 1;
	else return 0;
}

//cau truc List
typedef struct {
	int size;
	int Data[Max_N];
}List;

//ham khoi tao list
void init_list(List *pL){
	pL->size=0;
}

//ham them vao list
void push_list(List *pL,int n){
	pL->Data[pL->size]=n;
	pL->size++;
}

//ham tra ve phan tu thu i
int element_at(List *pL,int i){
	return pL->Data[i-1];
}

int mark[Max_N];
int pi[Max_N];
int p[Max_N];

//Moore Dijkstra
void Moore_Dijkstra(Graph *pG,int s){
	int i,u,v,it;
	for(i=1;i<=pG->n;i++){
		pi[i]=inf;
		mark[i]=0;
	}
	p[s]=-1;
	pi[s]=0;
	for(it=1;it<pG->n;it++){
		int j, min_pi=inf;
		for(j=1;j<=pG->n;j++){
			if(mark[j]==0 && pi[j]<min_pi){
				min_pi=pi[j];
				u=j;
			}
		}
		
		mark[u]=1;
		
		for(v=1;v<=pG->n;v++){
			if(pG->w[u][v]!=No_edge && mark[v]==0)
				if(pi[u]+pG->w[u][v]<pi[v]){
					pi[v]=pi[u] + pG->w[u][v];
					p[v]=u;
				}
		}
	}
}

//Ham main
int main(){
	Graph G;
	int i,s,n,m,u,v,w,e,tmp,z;
	List A;
	init_list(&A);
	printf("Nhap n, m: ");
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(i=0;i<m;i++){
		printf("Nhap u, v, w: ");
		scanf("%d%d%d",&u,&v,&w);
		add_edge(&G,u,v,w);
	}
	
	printf("nhap s: ");
	scanf("%d",&s);
	Moore_Dijkstra(&G,s);
	
	printf("Nhap dinh ban muon tim duong di: ");
	scanf("%d",&e);
	i=0; z=e;
	while(p[e]!=-1){
		push_list(&A,p[e]);
		tmp=p[e];
		p[e]=p[tmp];
	}
	
	for(i=A.size;i>0;i--){
		printf("%d ",element_at(&A,i));
	}
	printf("%d",z);
	
	return 1;
}
