#include<stdio.h> 
#include<iostream>
#include<math.h> 
#include<map> 
using namespace std;
int n,i,j,k,l;
int arra[128][128]={0};
int arrb[128][128]={0}; 
int p,q,a,b,cot,sum;
map<int,int>points; 
int main() 
{ 
    cin>>n;
 	for(i=0;i<=n;++i)
    { 
        p=0; 
    	q=pow(2.0,i-1);
      	for(j=0;j<q;++j)
     	{ 
          	for(k=0;k<q;k++) 
           	{ 
            	arrb[j+q][k+q]=arrb[j][k]; 
         	} 
      	}  
      	sum=q*2;
		for(j=q;j<sum;++j)
      	{ 
        	arrb[p][j]=1;
			arrb[j][p]=1; 
         	p+=1; 
       	} 
   } 
  	i=0; 
    while(scanf("%d",&cot)!=EOF) 
   	{ 
	    points.insert(pair<int,int>(cot,i)); 
	    i+=1; 
   	} 
  	l=pow(2.0,n); 
 	for(i=0;i<l-1;++i) 
 	{ 
      	for(j=i+1;j<l;++j) 
       	{ 
          	if(arrb[i][j]) 
           	{ 
              a=points.find(i)->second;
			  b=points.find(j)->second; 
              arra[a][b]=1;
			  arra[b][a]=1; 
          	} 
      	} 
  	} 
  	for(i=0;i<l;++i) 
 	{ 
      	for(j=0;j<l;++j) 
     	{ 
     	    if(j!=l-1)
            {
            	cout<<arra[i][j]<<" ";
			} 
          	else if(j==l-1) 
            {
            	cout<<arra[i][j]<<endl;
			}
       	} 
  	}  
} 
