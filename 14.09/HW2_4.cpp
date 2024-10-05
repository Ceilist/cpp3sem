#include <iostream>
#include <string>

using namespace std;

int main() {
    string first, second;
    cin >> first;
    cin >> second;

    int count = 0;

    for (unsigned i{}; i <= first.length() - second.length();) {
        size_t position = first.find(second, i);
        if (position == string::npos) break;
        ++count;
        i = position + 1;
    }
    cout << count << endl;
}
