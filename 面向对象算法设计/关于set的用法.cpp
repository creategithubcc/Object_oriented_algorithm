#include<iostream>
#include<vector>
#include<set>
using namespace std;
set<int >setd;                   //������������Ϊ���ò�ͬ�Ĺ��캯����ʹ�öԷ��ı������������õ� 
set<int >sete;
set<int >setf;
class  CSet
{
private:
    set<int>::iterator iter;   //��������������Ҫ 
    set<int>::iterator iter2;
public:
	CSet()
    {
    	set<int >seta;	
	}
   CSet(int *a,int i)
    {
    	set<int > setb(a,a+i);          //���������ݵ������Ա�����ڲ��Զ�����ͬʱ�������ظ������� 
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
		cout<<"������һ�����֣��ҽ����ѯ��������û���ڼ�������"<<endl;
		while(scanf("%d",&num)!=EOF)     //��ʵӦ���и��õ��Ż���ʽ�ģ���ʵ���벻�����ˣ�ֻ����while��ѭ���� 
		{
			while(iter!=setb.end())
			{
				if(num==*iter)
				{
					cout<<"�ظ����֣�"<<num<<endl; 
					break;
				}
				else
				{
					iter++;
					if(iter==setb.end())
					{
						cout<<"û���ظ�"<<endl;
						break;
					}
				}
			}
			iter=setb.begin();
		}
		cout<<"����һ������ɾ��"<<endl;
		while(scanf("%d",&num)!=EOF)
		{
			setb.erase(num);              //ɾ������ 
			iter=setb.begin();
			while(iter!=setb.end())
			{
				cout<<*iter<< ' ';  
				iter++;
			}
			cout<<endl;
		}
		setd=setb;                      //��һ����Ϊ�˱���setbҲ����ɾ�����s1��֮���s2���жԱ��� 
		setf=setb;                      //��������ֵ��ȫ�ֱ����������Ϳ������κεط�ʹ���� 
		return;	
	}
	CSet  operator+(int k)              //����ط�������Ϊ���ѵĵط�����Ҫ���ǵ�һ�νӴ����ֲ��� 
	{                                   //�����ҵ����Ϻ�ͼ򵥶��� 
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
	CSet  operator+(CSet S2)            //����ط�Ҳ���˱��취while��ѭ�� 
	{                                   //��ǰ�渳ֵ�˵ı�������һһ�Աȣ�����ظ��򱣴沢��� 
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
	cout<<"����һ���������"<<endl;
	while(scanf("%d",&k)!=EOF)
	{
		CSet S1=S2+k;
	} 
	cout<<"S1��S2�Ľ���Ϊ��"<<endl;
	CSet S3=S1+S2;
	cout<<endl;
}

