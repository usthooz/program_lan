#include <stdexcept>
#include <iostream>

using namespace std;

void test() {
    throw runtime_error("pass");
}

int main() {
    try {
        test();
    } catch(runtime_error err) {
        cout << err.what() << endl;
    }
    return 0;
}