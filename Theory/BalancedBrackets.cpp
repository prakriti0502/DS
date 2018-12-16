#include<iostream>
using namespace std;
int main()
{
    int top=-1;
    string s;
    int i=0;
    cin>>s;
    int l=s.length();
    char arr[l];
    for(int i=0;i<l;i++)
    {
        if(s[i]=='{' || s[i]=='(' || s[i]=='[')
        {
            top++;
            arr[top]=s[i];
        }
        if(s[i]==')')
        {
           if(arr[top]=='(')
           {
                top--;
            }
            else
            {
                cout<"no";
                return 0;
              }
        }
        if(s[i]=='}')
        {
            if(arr[top]=='{')
            {
                top--;
            }
            else
            {
                cout<<"no";
                return 0;
            }
        }
        if(s[i]==']')
        {
            if(arr[top]=='[')
            {
                top--;
            }
            else
            {
                cout<<"no";
                return 0;
            }
        }
    }
    //cout<<top;
    if(top!=-1)
    {
        cout<<"no";
    }
    else
    {
        cout<<"yes";
    }
}
