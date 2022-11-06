#include<stdio.h>
#include<stdlib.h>
#define MVNum 100
typedef char VerTexType;
typedef int ArcType;
typedef struct arcnode* ArcList;
typedef struct graph* GraphList;
typedef struct head* HeadList;
typedef struct arcnode{
	int adjvex;
	ArcList next;
	ArcType info;
}ArcNode;

typedef struct head{
	VerTexType data;
	ArcList next;
}Head,AdjList[MVNum];

typedef struct graph{
	AdjList	vertices;
	int topnum,sidenum;
}Graph;

GraphList UDNInit(){
	GraphList G = (GraphList)malloc(sizeof(Graph));
	return G;
}

int LocateIndex(GraphList G,char **topnum){
	char c = **topnum;
	int i;
	for(i=0;i<G->topnum;i++){
		if(c==G->vertices[i].data){
			break;
		}
	}
	return i;
}

void NewNode(GraphList G,int i,int j,int power){
       	ArcList New_1 = (ArcList)malloc(sizeof(ArcNode));
        New_1->adjvex = j;
	New_1->info = power;
        New_1->next = G->vertices[i].next;
        G->vertices[i].next = New_1;
}


void CreateUDN(GraphList G){
	int power;
	printf("please input topnum and sidenum:\n");
	scanf("%d%d",&G->topnum,&G->sidenum);
	for(int i=0;i<G->topnum;i++){
    		printf("please input number %d topnum information:",i+1);
    		scanf("%s",&G->vertices[i].data);
		G->vertices[i].next = NULL;
    }
	for(int j=0;j<G->topnum;j++){
		printf("number %d data is %c\n" ,j+1,G->vertices[j].data);
	}
	for(int k=0;k<G->sidenum;k++){
		printf("please input topnum_first topnum_second and power:");
		char *topnum_first = (char *)malloc(sizeof(char));
		char *topnum_second = (char *)malloc(sizeof(char));
		scanf("%s%s%d",topnum_first,topnum_second,&power);
		int i = LocateIndex(G,&topnum_first);
		int j = LocateIndex(G,&topnum_second);
		NewNode(G,i,j,power);
		NewNode(G,j,i,power);		
	}
}

int Len_Traverse(ArcList A){
	int i=1;
	while(A->next!=NULL){
		i++;
		printf("index is %d and Power is %d \n",A->adjvex,A->info);
		A=A->next;	
	}
	printf("index is %d and Power is %d",A->adjvex,A->info);
	printf("\n");
	return i;
}

void FinallyResult(GraphList G){
	int lens;
	for(int i=0;i<G->topnum;i++){
		if(G->vertices[i].next!=NULL){
			lens = Len_Traverse(G->vertices[i].next);
			printf("number %d has %d sides.\n",i,lens);		
		}

	}
}


int main(){
	GraphList G = UDNInit();
	CreateUDN(G);
	FinallyResult(G);	
	return 0;
}
