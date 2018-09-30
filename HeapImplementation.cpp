#include<iostream>
using namespace std;
class heap
{
	int l,r,F=0,largest;
	public:
		void build_max_heap(int arr[],int n)
		{
			for(int i=n/2;i>=1;i--)
				max_heapify(arr,i,n);
		}
		void max_heapify(int arr[],int i,int n)
		{
			F=0;
			l=2*i;
			r=(2*i)+1;
			if(l<=n && arr[l]>arr[r])
			{
				F=1;
				largest = l;
			}
			else if(l<=n && arr[i]>arr[l])
				largest=i;
			if(r<=n && arr[r]>arr[largest])
			{
				F=1;
				largest=r;
			}
			if(F==1)
			{
				int temp;
				temp=arr[i];
				arr[i]=arr[largest];
				arr[largest]=temp;
				max_heapify(arr,largest,n);
			}
		}
};
int main()
{
	heap obj;
	int n;
	cout<<"Enter number of elements in you want in heap\n";
	cin>>n;
	int arr[n];
	cout<<"Enter elements in array\n";
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	int choice;
	cout<<"Enter 1 to create max heap\n";
	cin>>choice;
	switch(choice)
	{
		case 1:
			{
				obj.build_max_heap(arr,n);
			}
	}
	for(int i=1;i<=n;i++)
		cout<<arr[i]<<"\t";
	return 0;
}
