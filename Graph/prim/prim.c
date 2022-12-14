#include<stdio.h>
#define V 6
typedef enum {false,true} bool;
int min_key(int key[],bool visited[]){
	int min = 2147483647,min_index;
	for(int v=0;v<V;v++){
		if(visited[v] == false && key[v]<min){
			min = key[v];
			min_index = v;
		}
	}
	printf("%2d",min_index);
	return min_index;
}

void print_MST(int parent[],int cost[V][V]){
	int minCost = 0;
	printf("small tree is :\n");
	for(int i=1;i<V;i++){
		printf("%d - %d wight:%d\n",parent[i]+1,i+1,cost[i][parent[i]]);
		minCost += cost[i][parent[i]];
	}
	printf("total wight:%d",minCost);
}

void find_MST(int cost[V][V]){
	int parent[V],key[V];
	bool visited[V];

	for(int i=0;i<V;i++){
		key[i] = 2147483647;
		visited[i] = false;
		parent[i] = -1;
	}
	key[0] = 0;
	parent[0] = -1;
	for(int x=0;x<V-1;x++){
		int u = min_key(key,visited);
		visited[u]=true;
		for(int v=0;v<V;v++){
			if(cost[u][v] !=0 && visited[v]==false && cost[u][v]<key[v]){
			parent[v] = u;
			key[v] = cost[u][v];
			}
		}
	}
	print_MST(parent,cost);
}

int main(){
	int p1,p2;
	int wight;
	int cost[V][V] = {0};
	printf("input graph(top_1 to top_2 road and width):\n");
	while(1){
		scanf("%d %d",&p1,&p2);
		if(p1 == -1 && p2 == -1){
			break;
		}
		scanf("%d",&wight);
		cost[p1-1][p2-1]=wight;
		cost[p2-1][p1-1]=wight;
	}
	find_MST(cost);
	return 0;
}
