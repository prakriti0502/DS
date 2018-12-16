#include<iostream>
#define SIZE 5
using namespace std;
class node
{
  public:
  node()
  {
   next=NULL;
  }
  int data;
  node *next;
}*front=NULL,*rear=NULL; //objects created outside the class but still are included inside the class as ; is at end
class circular_queue
{
 public:
 void enqueue();
 void dequeue();
 void disp();
};
void circular_queue::enqueue()
{
  int ele,i;
  cout<<"Enter the element";
  cin>>ele;
  node *temp;
  temp=new node;
  temp->data=ele;
  temp->next=temp;
  if(front==NULL)
  {
    front=temp;
    rear=temp;
  }
  else if((rear->next)==front)
  {
      cout<<"Overflow";
  }
  else
  {
       rear->next=temp;
       temp->next=front;
       rear=temp;
 }
}
void circular_queue::dequeue()
{
    if(front==NULL)
    {
        cout<<"Underflow";
    }
    else if(front==rear)
    {
        front=NULL;

        rear=NULL;
    }
    else
    {
        node *ptr;
        ptr=front;
        front=front->next;
        delete ptr;
        rear->next=front;

    }

}
void circular_queue::disp()
{
    if(front==NULL)
    {
        cout<<"Empty";
    }
    node *ptr=front;
    while(ptr->next!=front)
    {
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
    cout<<ptr->data<<"->";
    cout<<front->data<<"->";
}
int main()
{
 int ch;
 circular_queue c;
 cin>>ch;
 while(ch!=4)
 {
   cout<<"1.Enqueue\n2.Dequeue\n3.Display";
   cin>>ch;
   switch(ch)
   {
   case 1:
          c.enqueue();
          break;
   case 2:
          c.dequeue();
          break;
   case 3:
          c.disp();
          break;
   default:
          cout<<"Wrong choice";
   }
 }
}
