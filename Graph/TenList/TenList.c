#include<stdio.h>
#include<stdlib.h>
#define  VertexType char
typedef struct Arcbox* ArcboxList;
typedef struct Arcbox{
	int tail,head;
	ArcboxList hlink,tlink;
	int info;
}ArcBox;

typedef struct head{
	char data;
	ArcboxList firstin,firstout;
}HEAD;
typedef struct graph* GList;
typedef struct graph{
	int topnum,sidenum;
	HEAD* arrays;	
}Graph;

GList Init(){
	GList G = (GList)malloc(sizeof(Graph));
	return G;
}

int Local_index(GList G,char data){
	int i;
	for(i=0;i<G->topnum;i++){
		if(G->arrays[i].data==data){
			break;
		}
	}
	return i;
}

ArcboxList NewNode(){
	return (ArcboxList)malloc(sizeof(ArcBox));
}

void Create_Graph(GList G){
	printf("please input topnum and sidenum:");
	scanf("%d%d",&G->topnum,&G->sidenum);
	G->arrays = (HEAD*)malloc(sizeof(HEAD)*G->topnum);
	for(int i=0;i<G->topnum;i++){
		printf("please input numbers %d infomation:",i+1);
		scanf("%s",&G->arrays[i].data);
		G->arrays[i].firstin = G->arrays[i].firstout=NULL;
	}
	for(int j = 0;j<G->sidenum;j++){
		char first_top,second_top;
		printf("please input first_top and second_top:");
		scanf("%s%s",&first_top,&second_top);
		ArcboxList p = NewNode();
		int q = Local_index(G,first_top);
		int w = Local_index(G,second_top);
		p->tail = q;
       		p->head = w;
       		p->hlink = G->arrays[w].firstin;
       		p->tlink = G->arrays[q].firstout;
        	G->arrays[w].firstin = G->arrays[q].firstout = p;
	}
}

int indegree(GList G, VertexType x) {
    int i;
    int num = 0;
    for (i = 0; i < G->topnum; i++) {
        if (x == G->arrays[i].data) {
            ArcboxList p = G->arrays[i].firstin;
            while (p)
            {
                num++;
                p = p->hlink;
            }
            break;
        }
    }
    if (i == G->topnum) {
        printf("图中没有指定顶点\n");
        return -1;
    }
    return num;
}

int outdegree(GList G, VertexType x) {
    int i;
    int num = 0;
    for (i = 0; i < G->topnum; i++) {
        if (x == G->arrays[i].data) {
            ArcboxList p = G->arrays[i].firstout;
            while (p)
            {
                num++;
                p = p->tlink;
            }
            break;
        }
    }
    if (i == G->topnum) {
        printf("图中没有指定顶点\n");
        return -1;
    }
    return num;
}


int main(){
	GList G = Init();
	Create_Graph(G);
	for(int i=0;i<G->topnum;i++){
		int in = indegree(G,G->arrays[i].data);
		int out = outdegree(G,G->arrays[i].data);
		printf("top %c has in degree:%d\n",G->arrays[i].data,in);
		printf("top %c has out degree:%d\n",G->arrays[i].data,out);

	}
	printf("Finish");
	return 0;
}
