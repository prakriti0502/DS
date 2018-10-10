#include<iostream>
using namespace std;
struct node
{
	int data;
	int *node;
};
class GRAPH
{
	int v,e;
	node *start;
	public:
		GRAPH(int ver)
		{
			node *start = new int[ver];
		}
};
int main()
{
	int ver;
	cout<<"Enter number of vertices\n";
	cin>>ver;
	GRAPH g(ver);
}
