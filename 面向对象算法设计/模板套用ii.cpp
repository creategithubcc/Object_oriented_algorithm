#include<iostream>
using namespace std;
  
template<typename T1>//最后一节课讲到的模板运用 

class MyArray
{
private:
       T1* array; 
       T1 ans;
public:
	
       MyArray(int a) 
	   {
            array=new T1[a];//定义模板数组 
            ans=a;
        }
      
       friend ostream& operator<<(ostream& os, MyArray& a) //这一块输出运算重载《《 
	   {
          		T1 i;
                for (i=0;i<a.ans;i++) 
			    {
                    os<<a.array[i]<<",";
                }
               return os;
        }
        T1& operator [](int i)//这一块将【】重载结果返回数组array 
	    { 
            if(i>=0&&i<ans)
            {
            	return array[i];
			}
        }
};
int main()
{
MyArray<int>  intArray(10);	 // 10 is the number of elements in intArray
for (int i=0; i<10; i++)
intArray[i] = i * i;
cout << intArray << endl;
}

