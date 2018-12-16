#include<iostream>
using namespace std;
int a[10][10],i,j,k,n,stk[10],top=0,v,visit[10],visited[10],x,y,m;
void DFS(int i)
{
    int j;
    cout<<i<<" ";
    visited[i]=1;
    for(j=0;j<n;j++)
    {
       if(!visited[j]&&a[i][j]==1)
            DFS(j);
	}
}
int main()
{
cout<<"enter no. of vertices and edges";
cin >> n>>m;
cout<<"enter edges for undirected grah"<<endl;
    if(x>=n&&y>=n)
        cout<<"please enter within range"<<endl;
    else
    {
	    for(int w=0;w<m;w++)
	    {
	        a[x][y]=1;
	        a[y][x]=1;
	        cin>>x>>y;
	    }
    }
cout <<"enter initial vertex";
cin >>v;
cout <<"Traversal is:"<<endl;
for(i=0;i<n;i++)
    visited[i]=0;
DFS(v);
}
