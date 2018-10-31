#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter size\n";
    cin>>n;
    int j;
    int arr[100];
    int index;
    cout<<"Enter array elements\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
 for(int i=0;i<n;i++)
 {
   index=i;
   for(int j=i+1;j<n;j++)
   {
    if(arr[j]<arr[index])
    {
      index=j; //finding smallest element in array and putting it to first position
    }
   }
   if(index!=i)
   { 
    int t=arr[i];
    arr[i]=arr[index];
    arr[index]=t;
   }
    cout<<arr[i];
 }

 return 0;
}
