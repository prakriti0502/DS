#include<iostream>
using namespace std;
int main()
{
	int v,e,visit[20]={0},visited[20]={0},adj[20][20]={0};
	int stk[20],top=0;
	cout<<"Vertices: \n";
	cin>>v;
	cout<<"Edges: \n";
	cin>>e;
	int x,y;
	cout<<"Enter connected edges\n";
	for(int i=0;i<e;i++)
	{
		cin>>x>>y;
		adj[x][y]=1;
		adj[y][x]=1;
	}
	int sou;
	cout<<"Source vertex: \n";
	cin>>sou;
	cout<<sou;
	visited[sou]=1;
	int k=1;
	while(k<v)
	{
		for(int j=v-1;j>=0;j--)
		{
			if(adj[sou][j]!=0 && visited[j]!=1 && visit[j]!=1)
			{
				visit[j]=1;
				stk[top]=j;
				top++;
			}
			
		}
		sou=stk[--top];
			cout<<" "<<sou;
			visited[sou]=1;
			visit[sou]=0;
			k++;
	}
	return 0;
}
