#include<iostream>
using namespace std;
  
template<typename T1>//���һ�ڿν�����ģ������ 

class MyArray
{
private:
       T1* array; 
       T1 ans;
public:
	
       MyArray(int a) 
	   {
            array=new T1[a];//����ģ������ 
            ans=a;
        }
      
       friend ostream& operator<<(ostream& os, MyArray& a) //��һ������������ء��� 
	   {
          		T1 i;
                for (i=0;i<a.ans;i++) 
			    {
                    os<<a.array[i]<<",";
                }
               return os;
        }
        T1& operator [](int i)//��һ�齫�������ؽ����������array 
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

