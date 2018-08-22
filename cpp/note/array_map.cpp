#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main() {
   // var
   map<int, int*> m;
   // array
   int a[4] = {1,2,3,4};
   // insert map elem
   for (int i=0;i<4;++i) {
        m.insert(make_pair(i,a));
   }
   // out put
    map<int,int*>::iterator it;
   for (it = m.begin(); it != m.end(); ++it)
   {
       cout << it->first << ':' <<ends << it->second << endl;
   }
   return 0;
}