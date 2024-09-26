#include <iostream>
using namespace std;

int main() {
    int n;
    unsigned i;
    cin>>n;
    for (int i = n / 2; i >= 2; --i) {
        if (n % i == 0) {
            cout << i<< endl;
            return 0;
        }
    }
    cout << "Number is prime"<< endl;
}