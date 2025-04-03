#include<iostream>
using namespace std;

int x[50];

int place(int r, int c)
{
    
    for(int i=1; i<=r-1;i++)
    {
        if((x[i] == c) || abs(x[i]-c)==abs(i-r))
        {
            return(0);
        }
    }
    return(1);
}

void print(int n)
{
    for(int i=1; i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(x[i]==j)
            {
                cout<<"Q ";
            }
            else
            {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
    cout<<endl;

}

int Nqueen(int r, int n)
{
    for(int c=1; c<=n; c++)
    {
        if(place(r,c)==1)
        {
            x[r]=c;
            if(r==n)
            {
                print(n);
            }
        
            else
            {
                 Nqueen(r+1,n);
            }
        }
        
    }
    return(0);
}

int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    Nqueen(1,n);
    return 0;
}
