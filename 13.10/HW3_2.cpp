
#include <iostream>
#include <windows.h>
using namespace std;

int find(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int find(float arr[], int size, float target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int find(char arr[], int size, char target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}
int main() {
    SetConsoleOutputCP(CP_UTF8);
    float arr1[] = {1.1, 2, 3.4, 4, 5, 6, 7, 8.5, 9, 10};
    float target;
    cin >> target;
    if (find(arr1, 10, target) == -1) {
        cout << "Элемента нет в массиве" << endl;
    } else {
        cout << "Индекс элемента: " << find(arr1, 10, target) << endl;
    }
    return 0;
}