//Root to Leaf path that sums up to given value
#include<iostream>
#include<stack>
#include<cstdlib>
using namespace std;
class tree
{ 
  private:
   struct bst
   {
     int info;
     struct bst*left;
     struct bst*right;
   };
  struct bst*root;
  struct bst*check;
  struct bst*new_node;
  struct bst*parent;
  public:
   int add,sum;
   stack<int> stk;
   tree()
    {
      root=NULL;
      parent=NULL;
      add=0;
    }
  void findhaspath(bst *p)
     {
        if(p==NULL)
         {
            return;
         }
       add=add+p->info;
       stk.push(p->info);
       if(add==sum && p->left==NULL && p->right==NULL)
        {
          while(!stk.empty())
          {
             cout<<stk.top()<<" ";
             stk.pop();
          }
         exit(0);
        }
       findhaspath(p->left);
       findhaspath(p->right);
       add=add-p->info;
       stk.pop();
    }  
   void create_bst()
    {
     int num;
      cin>>num;
      while(num!=-1)
       {
         new_node=new bst;
         new_node->info=num;
         new_node->left=NULL;
         new_node->right=NULL;
         if(root==NULL)
          {
            root=new_node;
          }
         else
          {
            check=root;
            while(1)
             {
               if(num>check->info)
                {
                  if(check->right==NULL)
                   {
                     check->right=new_node;
                     cout<<"Parent is"<<check->info<<" ";
                     break;
                   }
                  else
                   {
                     check=check->right;
                   }
                }
               else
                {
                  if(check->left==NULL)
                   {
                     check->left=new_node;
                     cout<<"Parent is"<<check->info<<" ";
                     break;
                   }
                  else
                   {
                     check=check->left;
                   }
                }
             }
         cin>>num;
       }
    }
    cout<<"Enter the sum"<<endl;
      cin>>sum;
      findhaspath(root);
  }
};
int main()
{
  tree t;
  t.create_bst();
}
