#include<iostream>
#include<time.h> 
#include<stdlib.h> 
using namespace std;
#define MAX 2000000 
int fenzhi(int a[],int b,int c)
{
    int x=a[b],d=b,e=c+1,t=0;
    while(1)
    {
    loop:
        if(c>d&&x>a[++d])
        {
            goto loop;
        }
        else
        {
        liip:
            if(x<a[--e])
            {
                goto liip;
            }
            else
            {
                if(d>=e)
                {
                    goto luup;
                }
                t=a[d];
                a[d]=a[e];
                a[e]=t;
            }
        }

    }luup:
    a[b]=a[e];
    a[e]=x;
    return e;
}
int RP(int a[],int b,int c)
{
    int d=0,t=0,ans=0;
    ans=rand()%(1+c-b);
    d=ans+b;
    t=a[d];
    a[d]=a[b];
    a[b]=t;
    return fenzhi(a,b,c);
}
int function(int a[],int b,int c,int k)
{
    int d=RP(a,b,c);
    int tt=0;
    int e=d-b+1;
    if(b!=c)
    {
        if(k>e)
        {
            return  function(a,d+1,c,k-e);
        }
        else if(k<=e)
        {
            return function(a,b,d,k);
        }
        tt++;
    }
    else if (b==c)
    {
        return a[b];
    }
}
int aa[MAX];
int main()
{
    int x=0,y=0,mid=0,n=0,q;
    while(scanf("%d,%d",&x,&y)!=EOF)
    {
        q=n+1;
        aa[n++]=y;
    }
    if(n%2!=0)
    {
        mid=(n+1)>>1;
    }
    else if(n%2==0)
    {
        mid=n>>1;
    }
    printf("%d\n", function(aa,0,n-1,mid));
}
