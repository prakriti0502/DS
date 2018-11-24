#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
class inf
{
	int top,topp,i,j,h,res;
	char stk[50];
	char post[50];
	char infi[50];
	char stack[50];
	public:
		inf()
		{
			top=-1;
			topp=-1;
			i=0;
			j=0;
			h=0;
		}
		void get()
		{
			cout<<"Enter infix\n";
			cin>>infi;
			int l = strlen(infi);
			infi[l]=')';
			infi[l+1]='\0';
			top++;
			stk[top]='(';
		}
	    int prece(char ch)
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
		void calculate()
		{
			//cout<<"inside calculate";
			while(infi[i]!='\0')
			{
				//cout<<"\nsomething going in while\n";
				if(isalnum(infi[i]))
					inspo(infi[i]);
				else if(infi[i]=='+'||infi[i]=='-'||infi[i]=='*'||infi[i]=='/'||infi[i]=='^')
				{
					//cout<<"True";
					if(prece(infi[i])<=prece(stk[top]))
					{
						//cout<<"\nPreless";
						while(prece(infi[i])<=prece(stk[top]))
							pop();  
 						push(infi[i]);
					}
					else if(prece(infi[i])>prece(stk[top]))
					{	push(infi[i]);  }
				}
				else if(infi[i]=='(')
				{
					//push(infi[i]);
					top++;
					stk[top]=infi[i];
				}
				else if(infi[i]==')')
				{
					while(stk[top]!='(')
						pop();  
					pop();
				}
				i++;
			}
		}
		void inspo(char ch)
		{
			if(ch!='(' && ch!=')')
			{
				post[j]=ch;
				j++;
			}
		}
		void push(char ch)
		{
			top++;
			stk[top]=ch;
		}
		void pop()
		{
			inspo(stk[top]);
			top--;
		}
		void disp()
		{
			post[j]='\0';
			cout<<"Postfix is\n"<<post;
		}
		void find()
		{
			while(post[h]!='\0')
			{
				if(isdigit(post[h]))
					res=post[h]-48;
				else
				{
					int B=popG();
					int A=popG();
					switch(post[h])
					{
						case '+':
							{
								res=A+B;
								break;
							}
						case '-':
							{
								res=A-B;
								break;
							}
						case '*':
							{
								res=A*B;
								break;
							}
						case '/':
							{
								res=A/B;
								break;
							}
						case '^':
							{
								res=pow(A,B);
								break;
							}
					}
				}
				pushG(res);
				//cout<<res;
				//cout<<stack[topp]<<"\t";
				h++;
			}
			cout<<"\nResult is "<<stack[topp];
		}
		int popG()
		{
			int x=stack[topp];
			topp--;
			return x;
		}
		void pushG(int num)
		{
			topp++;
			stack[topp]=num;
		}
};
int main()
{
	inf ob;
	ob.get();
	ob.calculate();
	ob.disp();
	ob.find();
	return 0;
}
