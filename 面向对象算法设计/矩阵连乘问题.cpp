#include <iostream>
int a[100];
int b[100][100];
int c[100][100];
//int min=100086;
namespace min
{
	int t=15200;
}
//#define min 15200
using namespace std;
int function(int i,int j)
{
    if(i==j) 
	{
		return 1;
	}
	cout<<"(";
    if(function(i,b[i][j]))
	{
        if(i==b[i][j]) 
		{
			cout<<"A"<<i;
        }
    }
    if(function(b[i][j]+1,j))
	{
        if(j==b[i][j]+1) 
		{
			cout<<"A"<<j;
        }
    }
    cout<<")";
    return 0;
}

int fuc(int n)
{
	//using namespace min;
    int p,i,j,k,cnt=0;
    p=i=1;
    j=k=0;
    for(p=1;p<n;p++)
    {
        for(i=1,j=i+p;j<n;i++)
        {
            int t=214748364;//2^31
            for(k=i;k<j;k++)
            {
                cnt=c[i][k]+c[k+1][j]+a[i-1]*a[k]*a[j];
                if(t>cnt)
                {
                    t=cnt;
                    //min=cnt;
                    b[i][j]=k;
                }
            }
            c[i][j]=t;
            j++;
        }
    }
    return c[1][n-1];
}
int main() 
{
    int n,i;
    cin>>n;
    for(i=0;i<=n;i++)
	{
		cin>>a[i];
    }
    cout<<fuc(n+1)<<endl;
    if(n!=1)
	{
    	function(1,n);
    }
    else if(n==1) 
	{
		cout<<"(A1)";
    }
    cout<<endl;
}
