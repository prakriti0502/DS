#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	int n,m,x,y,visited[20]={0},visit[20]={0},stk[20],top=0,adj[20][20];
	cin>>n; //vertices
	cin>>m; //edges
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		adj[x][y]=1;
		adj[y][x]=1;
	}
	int v=2; //source vertex
	cout<<v;
	visited[v]=1;
	int k=1;
	while(k<n)
	{
		for(int j=n-1;j>=0;j--)
		{
			if(adj[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
			{
				visit[j]=1;
				stk[top]=j;
				top++;
			}
		}
		v=stk[--top];
		cout<<" "<<v;
		visit[v]=0;
		visited[v]=1;
		k++;
	}
	return 0;
}
