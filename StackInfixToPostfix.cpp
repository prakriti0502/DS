#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;
class Post
{
	int top,i=0,j=0;
	char stack_[50],infix[50],postfix[50];
	int index;
	public:
		Post()
		{
			top=-1;
			cout<<"Enter infix expression\n";
			cin>>infix;
			index=strlen(infix);
			infix[index]=')';
			infix[index+1]='\0';
			stack_[0]='(';
		}
		void stackIns()
		{
			while(infix[i]!='\0')
			{
				if(isalpha(infix[i]))
				{
					insert_postfix(infix[i]);
				}
				else if(infix[i]==')')
				{
					while(stack_[top]!='(')
						pop();
					pop(); //to pop '(' bracket
				}
				else if(infix[i]=='*'||infix[i]=='/'||infix[i]=='+'||infix[i]=='-'||infix[i]=='^'||infix[i]=='(')
				{
					if(infix[i]=='(')
						push(infix[i]);
					else if(preced(infix[i])>preced(infix[stack_[top]]))
						push(infix[i]);
					else if(preced(infix[i])<=preced(infix[stack_[top]]))
					{
						while(preced(infix[i])<=preced(infix[stack_[top]]))
							pop();
					}
				}
				i++;
			}
		}
		int preced(char ch)
		{
			if(ch=='^')
				return 3;
			else if(ch=='*'||ch=='/')
				return 2;
			else if(ch=='+'||ch=='-')
				return 1;
			else
				return 0;
		}
		void insert_postfix(char ch)
		{
			postfix[j]=ch;
			j++;
		}
		void push(char num)
		{
			top++;
			stack_[top]=num;
		}
		void pop()
		{
			if(stack_[top]=='(')
			{
				
			}
			else
			{
				insert_postfix(stack_[top]);
				top--;
			}
		}
		bool isEmpty()
		{
			if(top<0)
				return 1;
			else
				return 0;
		}
		void display()
		{
			cout<<postfix;
		}
};
int main()
{
	Post p;
	p.stackIns();
	p.display();
	return 0;
}
