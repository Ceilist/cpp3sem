#include <iostream>
using namespace std;

template<unsigned int n>
struct vector {
    double coords[n];

    vector operator *(float a) {
        vector<n> res;
        for (int i = 0; i < n; i++) {
            res.coords[i] = a * this->coords[i];
        };

        return res;
    }

    vector operator +(vector c) {
        vector<n> res;
        for (int i = 0; i < n; i++) {
            res.coords[i] = this->coords[i] + c.coords[i];
        };
        return res;
    }

    float operator *(vector c) {
        float a = 0;
        for (int i = 0; i < n; i++) {
            a += this->coords[i] * c.coords[i];
        };

        return a;
    }
};

int main() {
    vector<3> v = {{1, 2, 3}};
    vector<3> vv = v * 3.0;
    for (int i = 0; i < 3; i++) {
        cout << vv.coords[i]<<" ";
    }
    cout<<endl;
    vector<3> k = vv + v;
    for (int i = 0; i < 3; i++) {
        cout << k.coords[i]<<" ";
    }
    cout<<endl;
    float n = vv * v;
    cout << n << endl;
};
