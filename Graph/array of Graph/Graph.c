#include"../GraphAlgorithm/GraphAlgorithm.h"
int main(){
	AMGraph G = UDNInit();
	CreateUDN(G);
	Kruskal(G);
	printf("\n");
	Prim(G,G->points[0]);
	return 0;
}

