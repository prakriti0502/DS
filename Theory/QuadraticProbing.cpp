#include<iostream>
using namespace std;
#define max 10
int a[max];
int index(int val,int mod)
{
	int k = val%mod;
	return k;
}

void quadratic(int k,int val)
{
	int i,f=0,count=0,c=1;
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
			cout<<"Hash Table is Full\n";
		for(i=k+c*c;i<max;i++)
		{
			if(a[i]==0)
			{
				a[i]=val;
				f=1;
				break;
			}
		}
	}
}

void display()
{
	int i;
    for(i=0;i<max;i++)
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
		quadratic(k,val);
	}
	display();
}
