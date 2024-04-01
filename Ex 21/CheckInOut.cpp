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
			pG->F[i][j]=0;
		}
	}
}

int main(){
	Graph G;
	int n, m, u, v, e, c, f;
 	freopen("data.txt","r",stdin);
	scanf("%d%d",&n ,&m);
	init_graph(&G, n);
	
	for(e=0; e<m; e++){
		scanf("%d%d%d%d",&u, &v, &c, &f);
		G.C[u][v]=c;
		G.F[u][v]=f;
	}

	int check, sum_out=0, sum_in=0;
	for(int i=1; i<=G.n; i++){
		sum_out+= G.F[1][i];
		sum_in+= G.F[i][G.n];		
	}
	if(sum_out != sum_in)
		check = 1;
		
	for(int i=1;i<=G.n;i++){
		for(int j=1;j<=G.n;j++){
			if(G.F[i][j] > G.C[i][j])
				check = 1;
		}
	}
	
	for(int i=2;i<G.n;i++){
		int out=0, in=0;
		for(int j=1;j<=G.n;j++){
			out += G.F[i][j];
			in += G.F[j][i];
		}
		if(out!=in){
				check = 1;
				break;
			}
	}
	
	printf((check==1) ? "NO" : "YES");
	return 0;
}
