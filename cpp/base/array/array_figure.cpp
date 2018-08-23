/*数组计算*/
#include<iostream>
using namespace std;
 
int main()
{
	int i,max,index,a[5];
	//从键盘上为数组赋值
	for(i=0;i<5;i++)
	{
		cout<<"a["<<i<<"]=";
		cin>>a[i];
	}
	//利用循环遍历数组，并找出最大值与下标
		max=a[0];
	for(i=0;i<5;i++)
	{
		if(max<a[i])
		{
			max=a[i];
			index=i;
		}
	}
	cout<<"\nmax="<<max<<" index="<<index<<endl;
	return 0;
}
