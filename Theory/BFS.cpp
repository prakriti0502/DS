#include<iostream>
using namespace std;
int main()
{
	int v,e,x,y;
	cout<<"Vertices\n";
	cin>>v;
	cout<<"Edges\n";
	cin>>e;
	int adj[20][20]={0},visited[20]={0},visit[20]={0},queue[20]={0},rear=0,front=0;
	for(int i=0;i<e;i++)
	{
		cin>>x>>y;
		adj[x][y]=1;
		adj[y][x]=1;
	}
	int sou;
	cout<<"Source vertex\n";
	cin>>sou;
	cout<<sou<<" ";
	visited[sou]=1;
	int k=1;
	while(k<v)
	{
		for(int j=0;j<v;j++)
		{
			if(adj[sou][j]==1 && visit[j]==0 && visited[j]==0)
			{
				visit[j]=1;
				queue[rear]=j;
				rear++;
			}
		}
		sou=queue[front++];
		cout<<sou<<" ";
		visit[sou]=0;
		visited[sou]=1;
		k++;
	}
	return 0;
}
