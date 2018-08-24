// 对应参数传递笔记
#include<iostream>
using namespace std;

void Fun(int a[],int b)
{
      for(int i=0; i < b; i++)
      {
		(*a)++;
		a++;
	}
}

void Fun1(int &b)
{
	b++;
}

int main()
{
	// 数组操作
	int array[]={1,2,3,4}; 
	// 数组的长度
	int length = sizeof(array)/sizeof(array[0]);
	cout << "old data:" << endl;
	for (int i = 0;i< length;i++)
	{
		cout << "Index:" << i << "  " <<"Value:" << array[i] <<endl;
	}
	// 传入数组首地址，第一个元素被更改
	Fun(array,length);
	cout << "new data:" << endl;
	for (int i = 0;i< length;i++)
	{
		cout << "Index:" << i << "  " <<"Value:" << array[i] <<endl;
	}
	// 单个变量
	int b = 2;
	cout << "old const:" << b << endl;	
	Fun1(b);
	cout << "new const:" << b << endl;
}