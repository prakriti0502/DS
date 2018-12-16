#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	int n,m,x,y,visited[20]={0},visit[20]={0},queue[20],rear=0,front=0,adj[20][20];
	cin>>n;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		adj[x][y]=1;
	//	adj[y][x]=1;
	}
	int v=2;
	cout<<v;
	visited[v]=1;
	int k=1;
	while(k<n)
	{
		for(int j=0;j<n;j++)
		{
			if(adj[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
			{
				visit[j]=1;
				queue[rear]=j;
				rear++;
			}
		}
		v=queue[front++];
		cout<<" "<<v;
		visit[v]=0;
		visited[v]=1;
		k++;
	}
	return 0;
}
