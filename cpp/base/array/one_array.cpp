/*数组*/
#include<iostream>
using namespace std;
 
int  main()
{
	//声明数组和变量
	int i,sum=0,a[5];
	//从键盘上循环为数组赋值
	for(i=0;i<5;i++)
	{
		cout<<"a["<<i<<"]=";
		cin>>a[i];
	}
 
	//直接显示数组元素
	cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<endl;
 
	//利用for循环显示数组各元素的值
	for(i=0;i<5;i++)
		cout<<a[i]<<" "<<endl;
 
	//计算数组之和
	sum=a[0]+a[1]+a[2]+a[3]+a[4];
 
	//利用for循环计算数组之和
	for(i=0;i<5;i++)
		sum+=a[i];
 
	//显示累加和及平均值
	cout<<"sum="<<sum<<endl;
	double avg=sum/5.0;
	cout<<"avg="<<avg<<endl;
 
	return 0;
}
