#include<iostream>
#include<string.h> 
using namespace std;  
int min(int a,int b)
{
	int c;
	c=a>b?b:a;
	return c;
} 
int max(int a,int b)
{
	int c;
	c=a<b?b:a;
	return c;
} 
int arr[1500][2],fujiedian[1500],arr2[1500],n,a,p,q,r,gen=0; 
void fuc(int gen)    
{    
    arr2[gen]=1;    
    for(int i=0;i<n;++i)
	{    
        if(fujiedian[i]==gen&&!arr2[i])
		{    
            fuc(i);    
            arr[gen][0]=min(arr[i][0],arr[i][1])+arr[gen][0];  
			arr[gen][1]=arr[i][0]+arr[gen][1];  
        }    
    }    
    arr[gen][0]+=1;    
}  
int main()    
{     
    void fuc(int gen);    
    while(scanf("%d",&n)!=EOF)
	{    
		memset(arr2,0,sizeof(arr2));  
		memset(fujiedian,0,sizeof(fujiedian));  
        memset(arr,0,sizeof(arr));    
        for(int j=0;j<n;++j)
		{    
            scanf("%d:(%d)",&p,&q);
			if(j==0)
			{
				gen=p; 	
			}    
            for(int m=0;m<q;++m)
			{    
                cin>>a;    
                fujiedian[a]=p;    
            }           
        }    
        fuc(gen);    
        cout<<min(arr[gen][0],arr[gen][1])<<endl;    
    }    
    return 0;    
}
