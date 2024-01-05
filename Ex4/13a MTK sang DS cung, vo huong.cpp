#define Max_N 100
#define Max_Elements 100
#include <stdio.h>

//cau truc ma tran ke
typedef struct{
	int A[Max_N][Max_N];
	int n,m;
}Graph;

//khoi tao do thi
void init_graph(Graph *pG,int n){
	pG->n=n;
	int i,j;
	for(i=1;i<=pG->n;i++){
		for(j=1;j<=pG->n;j++){
			pG->A[i][j]=0;
		}
	}
}

//in ma tran ke sang danh sach cung
void mtk_dscung(Graph *pG){
	int i,j,tmp;
	for(i=1;i<=pG->n;i++){
		for(j=1;j<=pG->n;j++){
			if(pG->A[i][i]!=0){
				for(tmp=1;tmp<=pG->A[i][j];tmp++){
					printf("%d %d\n",i,j);
				}
			}
			if(pG->A[i][j]==pG->A[j][i])
				pG->A[j][i]=0;
			for(tmp=1;tmp<=pG->A[i][j];tmp++){
				printf("%d %d\n",i,j);
			}	
		}
	}
}

//main
int main(){
	Graph G;
	int n,m,i,j;
	scanf("%d",&n);
	init_graph(&G,n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&m);
			G.A[i][j]=m;
		}
	}
	mtk_dscung(&G);
	return 0;
}