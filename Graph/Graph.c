#include<stdio.h>
#include<stdlib.h>
#define MaxInt 32767
typedef int ArcType;
typedef char VerTexType;
typedef struct graph* AMGraph;
typedef struct graph{
	int vexnum,topnum;
	ArcType ** arranges;
	VerTexType *points;
}Graph;

AMGraph UDNInit(){
	AMGraph G = (AMGraph)malloc(sizeof(Graph));
	return G;
}

int LocateTop(AMGraph G,char** topnum){
	int i;
	char c = **topnum;
	for(i=0;i<G->topnum;i++){
		char s = G->points[i];
		if(s==c){
			break;
		}
	}
      return i;
}


void CreateUDN(AMGraph G){
	printf("please input Vexnum and topnum:\n");
	scanf("%d%d",&G->vexnum,&G->topnum);
	G->points = (VerTexType*)malloc(sizeof(VerTexType)*G->topnum);
	G->arranges = (ArcType**)malloc(G->topnum*sizeof(ArcType*));
	for(int i=0;i<G->topnum;i++){
		G->arranges[i] = (ArcType*)malloc(G->topnum*sizeof(ArcType));
	}
	for(int i=0;i<G->topnum;i++){
		printf("please input topnum information:");
		scanf("%s",&G->points[i]);
	}
	for(int i=0;i<G->topnum;i++){
		for(int j=0;j<G->topnum;j++){
			G->arranges[i][j] = MaxInt;
		}
	}
	for(int k=0;k<G->vexnum;k++){
		printf("please input topnum_first topnum_second and power:\n");
		char *topnum_first=(char*)malloc(sizeof(char));
		char *topnum_second = (char*)malloc(sizeof(char));
		int power;
		scanf("%s%s%d",topnum_first,topnum_second,&power);
		int i =LocateTop(G,&topnum_first);
		int j = LocateTop(G,&topnum_second);
		G->arranges[i][j] = power;
		G->arranges[j][i] = G->arranges[i][j];
	}
	for(int q=0;q<G->topnum;q++){
		for(int w=0;w<G->topnum;w++){
			printf("%8d",G->arranges[q][w]);
		}
		printf("\n");
	}
}

int main(){
	AMGraph G = UDNInit();
	CreateUDN(G);
	return 0;
}

