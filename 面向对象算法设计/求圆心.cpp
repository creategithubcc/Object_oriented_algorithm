#include <iostream>
#include <stdio.h>  //�����ԣ�����һ�����ʱ�����ڰ�ʵ���д���� ������Ԥ��������֮ǰ�ǿ���д��ʵ���
#include <stdlib.h> // �����;���г����ʱ�����ͻȻ���������ˣ�д��һ����Ĵ���ȫ����ʧ......
using namespace std;// �ò����װѵ����޺ú����±�д���룬ȴ������������д�Ĵ���˼·��ôҲʵ�ֲ�����
#include<math.h>    // ���ǻ�������������Ǹ�����......�������ڷ�������Ӧ���ǳ�����������int����
	int xx[50];     // ���ǰѲ���������΢�޸����Ժ�����ͨ���ˡ�������ô˵��������������ᵽ��д����д��һ��� 
	int yy[50];     //����ͻȻ�������Ƿݾ������ˣ����ᶼ����������ˣ��������������ڰѴ��������ˣ�ϲ�������� 
	int rr[50];
namespace CPOINT
{
	class Point 
{
	private:	
	    int  x,y,r;
	public: 

		Point(int x1,int y1,int r1,int i)//���������������ȫ���ŵ������棬ѭ���������ڵ������������������ 
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
	}                                          //�����������ĵ���� 
	for(j=1;j<i;j++)
	{
		if((rr1[j-1]+rr1[j])>juli[j])         //�������Բ�뾶��ӳ�������Ļ��϶��ཻ 
		{                                     //�����ȵĻ�����һ����ͬ���� 
			cout<<"�ص�"<<endl;               //����Ƚϳ��Ļ����ǲ��ཻ 
		}
		else if((rr1[j-1]+rr1[j])==juli[j])
		{
			cout<<"�պ�����һ��"<<endl;
		}
		else if((rr1[j-1]+rr1[j])<juli[j])
		{
			cout<<"û���ص�"<<endl;
		}
		cout<<"�����������ĵ���������Ϊ��"<<juli[j]<<endl;
		cout<<"����Բ�뾶��ӣ�"<<rr1[j-1]+rr1[j]<<endl;	
	}
}
int main()
{
	int n,i,j,x1,y1,r1;
	double *x2,*y2,*r2;                          //�����ط��ʼû��ָ�룬�������©���ٳ��������ĳ�ָ���Ϳ��������� 
	i=0;                                         //ע����������ʱҪ��double���壬�����int�Ļ��𰸻�ȡ�� 
	while(scanf("%d %d %d",&x1,&y1,&r1)!=EOF)
	{
		Point(x1,y1,r1,i);                       //����������ݴ�ŵ���Point���棬����ѭ����������ú��� 
		i++;                                      //����Print����Print��������������� 
	}
	Print(xx,yy,rr,i);
}

