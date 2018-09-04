# include<iostream>
# include<vector>
# include<iterator>
using namespace std;

int main(){
    vector<int> temp_v;
    temp_v.push_back(1);
    temp_v.push_back(1);
    temp_v.push_back(5);

    vector<int>::iterator x = temp_v.begin();
    for (;x != temp_v.end();x++)
    {
        if (*x == temp_v[2]){
            cout << *x << " ";
            cout << "x" << endl;
        }
    }
}