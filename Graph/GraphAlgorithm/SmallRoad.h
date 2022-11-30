void Dijksta(AMGraph G,VerTexType v0){
	ArcType wight[G->topnum];
	int locate = LocateVex(G,v0);
	bool Sure[G->topnum];
	ArcType path[G->topnum];
	for(int i = 0;i<G->topnum;i++){
		Sure[i]=false;
		wight[i] = G->arranges[locate][i];
		if(wight[i]<MaxInt) path[i] = locate;
		else path[i] = -1;
	}
	Sure[locate] = true;
	wight[locate] = 0;
	int v;
	for(int i=1;i<G->topnum;i++){
		ArcType Min=MaxInt;
		for(int w=0;w<G->topnum;w++){
			if(!Sure[w]&&wight[w]<Min){
				v = w;
				Min = wight[w];
			}
		Sure[v] = true;
		for(int w=0;w<G->topnum;w++){
			if(!Sure[w]&&(wight[v]+G->arranges[v][w]<wight[w])){
				wight[w] = wight[w]+G->arranges[v][w];
				path[w]= v;
			}
		}
		}
	}
}
