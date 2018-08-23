/*数组排序*/
#include<iostream>
using namespace std;
 
int main()
{
	int i,j;
	float t,a[5];
	
	//从键盘为数组赋值
	for(i=0;i<5;i++)
	{
		cout<<"a["<<i<<"]=";
		cin>>a[i];
	}
 
	//对数组按从大到小顺序排序
		for(i=0;i<4;i++)
			for(j=i+1;j<5;j++)
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
	//显示排序结果
		for(i=0;i<5;i++)
			cout<<a[i]<<" ";
}
