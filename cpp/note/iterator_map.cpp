#include <iostream>
#include <map>
 
using namespace std;
 
int main(void)
{
    int i;
    int a[] = { 1, 2, 3, 4, 5, 5, 5 };
    map<int, int> m;
    for (i = 0; i < 7; i++)
    {
        if (m.end() != m.find(a[i])) m[a[i]]++;
        else m.insert(pair<int, int>(a[i], 1));
    }
	map<int,int>::iterator it;
    for (it = m.begin(); it != m.end(); ++it)
    {
        cout << it->first << ends << it->second << endl;
    }
	system("pause");
    return 0;
}