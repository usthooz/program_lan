#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct _Test
{
	int value;
	char name[32];
}Test;
typedef struct Value 
{
	Test d;
	int a;
	short b;
	char c[28];
	
}Value;

/************************************************************************
* 基于强制类型转换，延伸出来的关于寻址的小问题。
* 建议，运行后，对照数字查看。
*
* 代码中，(5)真正的能够体现出问题所在，其他仅仅为促进思考，可以注释掉
* 
************************************************************************/

void main()
{
	Value v;
	Test t;
	/************************************************************************/
	/*(1)测试基本数据类型大小                                                 */
	/************************************************************************/
	printf("int struct size:%d\n", sizeof(int));
	printf("char struct size:%d\n", sizeof(char));
	printf("short struct size:%d\n", sizeof(short));
	printf("long struct size:%d\n", sizeof(long));
	printf("Test struct size:%d\n", sizeof(Test));	//36
	printf("Test float size:%d\n", sizeof(float));
	printf("Test double size:%d\n", sizeof(double));
	printf("v.d size:%d\n", sizeof(v.d));
	printf("v.a size:%d\n", sizeof(v.a));
	printf("v.b size:%d\n", sizeof(v.b));
	printf("v.c size:%d\n", sizeof(v.c));
	printf("Value struct size:%d\n", sizeof(Value));
	printf("-------------------------------\n");


	/************************************************************************/
	/*(2) 初始化结构体                                                         */
	/************************************************************************/
	//赋值
	v.a = 10;
	v.b = 2;
	strcpy(v.c, "aaa");
	v.d.value = 30;
	strcpy(v.d.name, "bbb");


	/************************************************************************/
	/* (3)强制类型转换后，各种类型指针首地址都相同                             */
	/************************************************************************/
	printf("%d\n", &v);						   //未转换前v所占空间的起始				   
	printf("%d\n", (char*)&v);			       //进行类型转换后，发现与转换前起始地址一样。
	printf("%d\n", (int*)&v);
	printf("%d\n", (long*)&v);
	printf("%d\n", (short*)&v);
	printf("%d\n", (float*)&v);
	printf("%d\n", (double*)&v);
	printf("-------------------------------\n");


	/************************************************************************/
	/* (4)指针类型，大小都为4字节                                              */
	/************************************************************************/
	printf("%d\n", sizeof(&v));
	printf("%d\n", sizeof((char*)&v));		   //指针所占内存大小与int和long类型相同
	printf("sizeof(char*) = %d\n", sizeof(char*));
	printf("-------------------------------\n");


	/************************************************************************
	* (5)强制转换成各种类型指针，发现地址相差很多(并不是int* 型差4、short*型差2) 
	*问题：如何解释这种现象？
	*
	************************************************************************/
	printf("&v addrr: %d\n", &v + sizeof(Test));		   
	printf("(char*)&v addrr: %d\n", (char*)&v + sizeof(Test));  //同（3）中首地址相差36
	printf("(int*)&v addrr: %d\n", (int*)&v + sizeof(Test));	//同（3）中首地址相差144
	printf("(long*)&v addrr: %d\n", (long*)&v + sizeof(Test));	//同（3）中首地址相差144
	printf("(short*)&v addrr: %d\n", (short*)&v + sizeof(Test));	//同（3）中首地址相差72
	printf("(float*)&v  addrr: %d\n", (float*)&v + sizeof(Test));	//同（3）中首地址相差144
	printf("(double*)&v  addrr: %d\n", (double*)&v + sizeof(Test)); //同（3）中首地址相差288

	/************************************************************************/
	/*(6)各种基本数据类型，的首地址                                         */
	/************************************************************************/
	printf("-------------------------------\n");
	char aa;
	printf("char addr:%d\n", &aa);
	int bb;
	printf("int addr:%d\n", &bb);
	long cc;
	printf("long addr:%d\n", &cc);
	short dd;
	printf("short addr:%d\n", &dd);
	float ee;
	printf("float addr:%d\n", &ee);
	double ff;
	printf("double addr:%d\n", &ff);

	/************************************************************************
	* (7)强制类型转换，Value结构体强转成Test结构体。
	* 能够访问Test中的变量，但是Value中的Test类型必须放于首位，进行声明
	************************************************************************/
	printf("-------------------------------\n");
	//取值
	Test *test = (Test*)&v;//强制类型转换，根据什么类型来取出什么样的内存块
	printf("Test value = %d, name = %s\n", test->value, test->name);


	/************************************************************************
	*(8) v.a可以访问Value中成员变量；
	*   提供访问Value中成员变量的底层实现原理：                                                                    
	************************************************************************/
	//根据偏移量，计算结构体内其他变量地址
	//v.a
	int a = *(int *)((char*)&v + sizeof(Test));
	printf("v.a = %d\n", a);
	//v.b
	short b = *(short*)((char*)&v + sizeof(Test) + sizeof(int));
	printf("v.b = %d\n", b);
	//v.c
	char* c = ((char*)&v + sizeof(Test) + sizeof(int) + sizeof(short));
	printf("v.c = %s\n", c);

	

}
