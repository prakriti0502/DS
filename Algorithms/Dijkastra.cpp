#include<iostream>
using namespace std;
#define V 5

int minDistance(int dist[],bool sptSet[])
{
	int min=INT_MAX,min_index;
	for(int v=0;v<V;v++)
	{
		if(!sptSet[v] && dist[v]<=min)
		{
			min=dist[v];
			min_index=v;
		}
		return min_index;
	}
}

int main()
{
	int graph[V][V]={  {0,3,4,0,0},
					{3,0,5,2,0}, {4,5,0,0,1}, {0,2,0,0,6}, {0,0,1,6,0} }
	
	return 0;
}
