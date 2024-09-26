#include <iostream>
using namespace std;

int main() {
    int n,sum;
    while(true) {
        cin >> n;
        if (n>0) {
            sum+=n;
        } else if(n==0) {
            return 0;
        }
        cout<<sum<<endl;
    }
}