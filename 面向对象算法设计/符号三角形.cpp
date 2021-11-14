#include<iostream>
#include <string.h>
using namespace std; 
int cot=0,ans=0,n=0,hf=0,a[30][30];
void function(int b)    
{     
    if(hf<((b*(b-1)/2)-cot)||(cot>hf))
	{
		return; 
	 }        
    if(n<b)
	{
		ans=ans+1;
	}    
    else if(n>=b)   
    {    
        for(int i=0;i<=1;++i)
		{       
            cot=cot+i;  
			a[1][b]=i;   
            for(int j=2;j<b+1;++j)
			{    
                a[j][b-j+1]=a[j-1][b-j+1]^a[j-1][b-j+2];      
                cot=cot+a[j][b-j+1];    
            }    
            function(b+1);    
            for(int j=2;j<=b;++j) 
			{
				cot-=a[j][b-j+1];
			}     
            cot=cot-i;    
        }    
    }    
}       
int main()    
{       
    cin>>n;    
    hf=n*(n+1)/2;    
    if(hf%2==1)
    {
		goto loop;  
	}         
    hf=hf/2;  
    function(1);       
    cout<<ans<<endl; 
    loop:
	return 0;     
}  
