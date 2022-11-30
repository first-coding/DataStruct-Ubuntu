#include"./Graph.h"
#include"../GraphAlgorithm/GraphAlgorithm.h"
#include"../GraphAlgorithm/SmallRoad.h"
int main(){
	AMGraph G = UDNInit();
	CreateUDN(G);
	Kruskal(G);
	printf("\n");
	Prim(G,G->points[0]);
	printf("\n");
	Dijksta(G,G->points[0]);
	return 0;
}

