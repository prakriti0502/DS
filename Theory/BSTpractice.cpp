#include <iostream>
using namespace std;
struct BST
{
  int info;
  BST *left;
  BST *right;
} *root = NULL;
void
create_BST ()
{
  int num;
  BST *check = new BST;
  cout << "Enter values in Tree,to stop press -1\n";
  cin >> num;
  while (num != -1)
    {
      BST *new_node = new BST;
      new_node->info = num;
      new_node->left = NULL;
      new_node->right = NULL;
      if (root == NULL)
	root = new_node;
      else
	{
	  check = root;
	  while (1)
	    {
	      if (check->info < num)
		{
		  if (check->right == NULL)
		    {
		      check->right = new_node;
		      cout << "Parent is " << check->info << endl;
		      break;
		    }
		  else
		    check = check->right;
		}
	      else
		{
		  if (check->left == NULL)
		    {
		      check->left = new_node;
		      cout << "Parent is " << check->info << endl;
		      break;
		    }
		  else
		    check = check->left;
		}
	    }
	}
      cin >> num;
    }
}

void
inOrder (BST * curr)
{
  cout << "Inside";
  if (root == NULL)
    return;
  if (curr != NULL)
    {
      inOrder (curr->left);
      cout << curr->info;
      inOrder (curr->right);
    }
}

int
main ()
{
  create_BST ();
  BST *ptr = root;
  inOrder (ptr);
  return 0;
}

