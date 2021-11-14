#include <iostream>
#include <stdio.h>  //码后感言：花了一整天的时间终于把实验八写完了 ，本来预计在下午之前是可以写完实验的
#include <stdlib.h> // 结果中途运行程序的时候电脑突然蓝屏崩溃了，写了一大早的代码全部丢失......
using namespace std;// 好不容易把电脑修好后重新编写代码，却发现昨天晚上写的代码思路怎么也实现不出来
#include<math.h>    // 总是会遇到这个错误那个错误......后来终于发现问题应该是出在整型数组int身上
	int xx[50];     // 于是把参数定义稍微修改了以后终于通过了。不管怎么说，今天总算是体会到了写代码写到一半后 
	int yy[50];     //电脑突然崩溃的那份绝望感了（眼泪都差点留下来了），好在终于现在把代码打出来了（喜极而泣） 
	int rr[50];
namespace CPOINT
{
	class Point 
{
	private:	
	    int  x,y,r;
	public: 

		Point(int x1,int y1,int r1,int i)//主函数输入的数据全部放到这里面，循环结束后在调用这里的数据做计算 
	    {
	    	xx[i]=x1;
			yy[i]=y1;
			rr[i]=r1;
			return;
		}	
};
}
using namespace CPOINT;
void Print(int *xx1,int *yy1,int *rr1,int i)
{ 
	double juli[52];int j=0;
	for(j=1;j<i;j++)
	{
		juli[j]=sqrt((xx1[j]-xx1[j-1])*(xx1[j]-xx1[j-1])+(yy1[j]-yy1[j-1])*(yy1[j]-yy1[j-1])); 
	}                                          //计算两个中心点距离 
	for(j=1;j<i;j++)
	{
		if((rr1[j-1]+rr1[j])>juli[j])         //如果两个圆半径相加超过距离的话肯定相交 
		{                                     //如果相等的话则有一条共同切线 
			cout<<"重叠"<<endl;               //距离比较长的话就是不相交 
		}
		else if((rr1[j-1]+rr1[j])==juli[j])
		{
			cout<<"刚好连在一起"<<endl;
		}
		else if((rr1[j-1]+rr1[j])<juli[j])
		{
			cout<<"没有重叠"<<endl;
		}
		cout<<"相邻两个中心点的两点距离为："<<juli[j]<<endl;
		cout<<"两个圆半径相加："<<rr1[j-1]+rr1[j]<<endl;	
	}
}
int main()
{
	int n,i,j,x1,y1,r1;
	double *x2,*y2,*r2;                          //在这块地方最开始没用指针，结果导致漏洞百出，后来改成指针后就可以运行了 
	i=0;                                         //注意输入和输出时要用double定义，如果用int的话答案会取整 
	while(scanf("%d %d %d",&x1,&y1,&r1)!=EOF)
	{
		Point(x1,y1,r1,i);                       //将输入的数据存放到类Point里面，当类循环结束后调用函数 
		i++;                                      //函数Print，在Print函数里面计算数据 
	}
	Print(xx,yy,rr,i);
}

