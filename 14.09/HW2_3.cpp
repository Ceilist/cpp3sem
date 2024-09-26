#include <iostream>
using namespace std;

int main() {
    int n, sum;
    cin >> n;
    int* mass=  new int[n]; // последнее предложение из второго задания
    for (int i = 0; i < n; i++) {
        *(mass+i)=i*i; // не понял, наверное здесь надо указателями..?
    }
    for (int i = 0; i < n; i++) {
        sum+=mass[i];

    }
    cout << sum << endl;
}