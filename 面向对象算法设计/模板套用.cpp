#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;
void require(bool requirement,const std::string& msg = "Requirement failed")
{
    using namespace std;
    if (!requirement) 
	{
        fputs(msg.c_str(), stderr);//将字符串写入，并移动指针 
        fputs("\n", stderr);
        exit(1);
    }
}
template<typename T1,T1 n>//本周学习重点内容，说真的当看到main函数里 Array<int,5>的时候 一时半会没反应过来 
class Array               //想了一整个晚上该怎么把int类型的5传到类里面，因为迄今为止看到的样例都是<int,double>这样的 
{                         //后来看了csdn的博客，发现如果后面是参数的情况的话可以直接传给类，不用再写typename T2 
public:                   //因此就写成这个形式，大部分代码都是以 IostreamOperatorOverloading.cpp 里为原型的 
	T1 a[n];              
	Array() 
	{ 
		memset(a,0,sizeof(*a)); 
	}
	int& operator[](T1 x) 
	{
		require(x>=0&&x<5,"IntArray::operator[] out of range");
		return a[x];
	}
	friend ostream&operator<<(ostream& os,const Array<T1,n>& ia)//把在外面的友元函数放进类里面 
	{                                                           //友元模板函数定义在函数内
		for(int j=0;j<5;j++)                                    // 就不需要在写 Array<T1,n>：：了 
		{
			os<<ia.a[j];
			if(j!=4)
			os<<", ";
		}
		os<<endl;
		return os;
	} 
	friend istream&operator>>(istream& is,Array& ia)
	{
		for(int j=0;j<5;j++)
		is>>ia.a[j];
		return is;
	}
};


int main() 
{
    stringstream input("47 34 56 92 103");
    Array<int,5> a;
    input>>a;
    a[4]=-1;           // Use overloaded operator[]
    cout<<a;
}


