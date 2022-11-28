#include"../array of Graph/Graph.h"
typedef struct edge{
	VerTexType Head;
	VerTexType Tail;
	ArcType wight;
}Edge;

typedef struct primedge{
	VerTexType adjvex;
	ArcType wight;
}PrimEdge;

int LocateVex(AMGraph G,VerTexType topnum){
	int i;
	for(i=0;i<G->topnum;i++){
		if(G->points[i]==topnum){
			break;
		}
	}
	return i;
}

void sort(Edge *arrays,AMGraph G){
	for(int i=0;i<G->vexnum;i++){
		for(int j=0;j<G->vexnum;j++){
			if(arrays[i].wight<arrays[j].wight){
				ArcType t = arrays[i].wight;
				VerTexType Head_2 = arrays[i].Head;
				VerTexType Tail_2 = arrays[i].Tail;
				arrays[i].Head = arrays[j].Head;
				arrays[i].Tail = arrays[j].Tail;
				arrays[j].Head = Head_2;
				arrays[j].Tail = Tail_2;
				arrays[i].wight = arrays[j].wight;
				arrays[j].wight = t;
			}
		}
	}

}

void Kruskal(AMGraph G){
	Edge arrays[G->vexnum];
	int Vexset[G->topnum];
	int i=0;
	for(int j=0;j<G->topnum;j++){
		for(int z=j;z<G->topnum;z++){
			if(G->arranges[j][z]!=32767){
				arrays[i].wight = G->arranges[j][z];
				arrays[i].Head = G->points[j];
				arrays[i].Tail = G->points[z];
				i++;
			}
		}
		}
	sort(arrays,G);
	printf("\n");
	for(int i=0;i<G->topnum;i++){
		Vexset[i]=i;
	}
	int sum = 0;
	for(int i=0;i<G->vexnum;i++){
		int v1 = LocateVex(G,arrays[i].Head);
		int v2 = LocateVex(G,arrays[i].Tail);
		int vs1 = Vexset[v1];
		int vs2 = Vexset[v2];
		if(vs1!=vs2){
			printf("%2c-%2c\n",arrays[i].Head,arrays[i].Tail);
			sum = sum+arrays[i].wight;
			for(int j=0;j<G->vexnum;j++){
				if(Vexset[j]==vs2){
					Vexset[j]=vs1;
				}
			}
		
		}
	}
	printf("total wight=%2d\n",sum);
}

int Min(AMGraph G,PrimEdge *arrays){
	int j=0;
	ArcType middle = arrays[0].wight;
	for(int i=1;i<G->topnum;i++){
		//printf("%2d,%2d\n",middle,arrays[i].wight);
		if(middle>arrays[i].wight){
			middle = arrays[i].wight;
			j=i;
		}
	}
	return j;
}

void Prim(AMGraph G,VerTexType u){
	PrimEdge arrays[G->topnum];
	int k = LocateVex(G,u);
	for(int j=0;j<G->topnum;j++){
		if(j!=k) arrays[j]=(PrimEdge){u,G->arranges[k][j]};
	}
	arrays[k].wight = MaxInt;
	int total = 0;
	for(int i=1;i<G->topnum;i++){
		int last = k;
		k = Min(G,arrays);
		printf("%d",k);
		VerTexType u0 = arrays[k].adjvex;
		VerTexType v0 = G->points[k];
		printf("%2c-%2c\n",u0,v0);
		total = arrays[k].wight+total;
		arrays[k].wight=MaxInt;
		for(int j=0;j<G->topnum;j++){
			if(G->arranges[k][j]<arrays[j].wight && j!=last){
				arrays[j] = (PrimEdge){G->points[k],G->arranges[k][j]};
			}
		}
	}
	printf("total=%d",total);
}

