#include<iostream>
using namespace std;
#define max 10
int a[max];
int index(int val,int mod)
{
	int k=val%mod;
	return k;
}

void linear(int k,int val)
{
	int f=0,i,count=0;
	if(a[k]==0)
	{
		a[k]=val;
	}
	else
	{
		i=0;
		while(i<max)
		{
			if(a[i]!=0)
				count++;
			i++;
		}
		if(count==max)
			cout<<"Hash table is full\n";
		for(i=k+1;i<max;i++)
		{
			if(a[i]==0)
			{
				f=1;
				a[i]=val;
				break;
			}
		}
		for(i=0;i<k&&f==0;i++)
		{
			if(a[i]==0)
			{
				f=1;
				a[i]=val;
				break;
			}
		}
	}
}
void display()
{
	for(int i=0;i<max;i++)
	{
		cout<<i<<" "<<a[i]<<endl;
	}
}

int main()
{
	int size;
	int mod;
	int val,k;
	cout<<"Enter number of elements in hash table\n";
	cin>>size;
	cout<<"Enter what modulus you want to do\n";
	cin>>mod;
	cout<<"Enter the elements you want to put in hash table\n";
	for(int i=0;i<size;i++)
	{
		cin>>val;
		k=index(val,mod);
		linear(k,val);
	}
	display();
}
