#include<iostream>
using namespace std;
int count=0;
struct BST
{
	int info;
	BST *left;
	BST *right;
}*root=NULL;
void create()
{
	int num;
	BST *check = new BST;
	cout<<"Enter values in Tree,to stop press -1\n";
	cin>>num;
	while(num!=-1)
	{
		BST *new_node = new BST;
		new_node->info = num;
		new_node->left = NULL;
		new_node->right = NULL;
		if(root == NULL)
			root = new_node;
		else
		{
			check = root;
			while(1)
			{
				if(check->info<num)
				{
					if(check->right==NULL)
					{
						check->right = new_node;
						cout<<"Parent is "<<check->info<<endl;
						break;
					}
					else
						check = check->right;
				}
				else
				{
					if(check->left == NULL)
					{
						check->left = new_node;
						cout<<"Parent is "<<check->info<<endl;
						break;
					}
					else
						check = check->left;
				}
			}
		}
		cin>>num;
		count++;
	}
}
void inOrder(BST *curr)
{
	if(curr==NULL)
		return;
	if(curr!=NULL)
	{
		inOrder(curr->left);
		cout<<curr->info<<"\t";
		inOrder(curr->right);
	}
	cout<<endl;
}
int main()
{
	create();
	cout<<"Inorder is ";
	inOrder(root);
	cout<<"Total nodes are "<<count;
}
