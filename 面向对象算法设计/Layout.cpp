#include<iostream>
#include<queue> 
using namespace std; 
int head[100086],nxt[100086],dist[100086];
int n,sn=0,i,j,aa,bb,p,q,a,b,c;
bool ar[100086];
deque<int>x;
int t[100086];
struct cans
{
    int t,d;
}arr[100086];
void fuc(int aa,int t,int d)
{
    arr[++sn].t=t;
    arr[sn].d=d;
    nxt[sn]=head[aa];
    head[aa]=sn;
}
int function(int s)
{
    for(i=1;i<=n;++i)
	{
		dist[i]=1000086;
	} 
	ar[s]=1;
    dist[s]=0;
    x.push_front(s);
    while(x.size())
    {
        aa=x.front();
		x.pop_front();
        ar[aa]=0;
        for(i=head[aa];i;i=nxt[i])
        {
            bb=arr[i].t;
            if(dist[aa]+arr[i].d<dist[bb])
            {
                dist[bb]=dist[aa]+arr[i].d;
                if(!ar[bb])
                {
                	if(!x.empty())
                    {
                    	if(dist[x.front()]<=dist[bb])
                        {
                        	x.push_back(bb);
						}
                        else if(dist[x.front()]>dist[bb])
                        {
                        	x.push_front(bb);
						}    
                    }
                    else if(x.empty()) 
					{
						x.push_front(bb);
					}
                    if(t[bb]++>n)
					{
						return -1;
					} 
                }
            }
        }
    }
    if(dist[n]==1000086) 
	{
		return -2;
	}
    return dist[n];
}
int main()
{
    cin>>n>>p>>q;
    for(i=1;i<p+1;++i)
    {
        cin>>a>>b>>c;
        if(b<a) 
		{
			swap(a,b);	
		}
		else if(b>a)
		{
			fuc(a,b,c);
		}
        fuc(a,b,c);
    }
    for(i=1;i<q+1;++i)
    {
    	cin>>a>>b>>c;
        if(a<b)
		{
			swap(a,b);
		} 
		else if(a>b)
		{
			fuc(a,b,-c);
		}
        fuc(a,b,-c);
    }   
    for(i=1;i<n;i++)
    {
        fuc(i+1,i,0);
    }
    cout<<function(1)<<endl;
    return 0;
}
