/*goto*/
#include<iostream>
using namespace std;
 
int main()
{
	int x,sum=0;
L1:cout<<"x=";//定义标记L1
   cin>>x;
   if(x==-2)
	   goto L2;//转到L2
   else
	   sum+=x;
		cout<<"sum="<<sum<<endl;
   goto L1;//转到L1
 
L2:cout<<"error!"<<"sum="<<sum<<endl;
   goto L1;
 
   return 0;
}
