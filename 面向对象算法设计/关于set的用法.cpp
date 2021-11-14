#include<iostream>
#include<vector>
#include<set>
using namespace std;
set<int >setd;                   //这三个函数是为了让不同的构造函数能使用对方的变量参数而设置的 
set<int >sete;
set<int >setf;
class  CSet
{
private:
    set<int>::iterator iter;   //这两个函数最重要 
    set<int>::iterator iter2;
public:
	CSet()
    {
    	set<int >seta;	
	}
   CSet(int *a,int i)
    {
    	set<int > setb(a,a+i);          //将参数传递到构造成员并在内部自动排序，同时不会有重复的数字 
		for(int j=0;j<i;j++)             
		setb.insert(a[j]);
		set<int>::iterator iter=setb.begin();
		while(iter!=setb.end())
		{
			cout<<*iter<<' ';            // 1 2 3 4 5 6 7 
			iter++;
		}
		cout<<endl;
		int num=0;
		iter=setb.begin();
		cout<<"请输入一个数字，我将会查询该数字有没有在集合里面"<<endl;
		while(scanf("%d",&num)!=EOF)     //其实应该有更好的优化方式的，但实在想不出来了，只好用while来循环了 
		{
			while(iter!=setb.end())
			{
				if(num==*iter)
				{
					cout<<"重复数字："<<num<<endl; 
					break;
				}
				else
				{
					iter++;
					if(iter==setb.end())
					{
						cout<<"没有重复"<<endl;
						break;
					}
				}
			}
			iter=setb.begin();
		}
		cout<<"输入一个数字删除"<<endl;
		while(scanf("%d",&num)!=EOF)
		{
			setb.erase(num);              //删除数字 
			iter=setb.begin();
			while(iter!=setb.end())
			{
				cout<<*iter<< ' ';  
				iter++;
			}
			cout<<endl;
		}
		setd=setb;                      //这一步，为了保存setb也就是删除后的s1和之后的s2进行对比求交 
		setf=setb;                      //将参数赋值给全局变量，这样就可以在任何地方使用了 
		return;	
	}
	CSet  operator+(int k)              //这个地方是我认为最难的地方，主要还是第一次接触这种操作 
	{                                   //后来找到诀窍后就简单多了 
		setd.insert(k);
		iter=setd.begin();
			while(iter!=setd.end())
			{
				cout<<*iter<< ' ';  
				iter++;
			}
			sete=setd;
			cout<<endl;		
	}
	CSet  operator+(CSet S2)            //这个地方也用了笨办法while来循环 
	{                                   //把前面赋值了的变量进行一一对比，如果重复则保存并输出 
		iter=setf.begin();
		while(iter!=setf.end())
		{
			for(iter2=sete.begin();iter2!=sete.end();iter2++)
			{
				if(*iter2==*iter)
				{
					cout<<*iter2<<" "; 
					break;
				}
			}
			iter++;
		}		
	}
};
int main() 
{
	int a[ ]={1,3,5,7,6,4,2},k;
	CSet S1,S2(a,7);
	cout<<"输入一个数字添加"<<endl;
	while(scanf("%d",&k)!=EOF)
	{
		CSet S1=S2+k;
	} 
	cout<<"S1和S2的交集为："<<endl;
	CSet S3=S1+S2;
	cout<<endl;
}

