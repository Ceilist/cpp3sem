
#include <iostream>
using namespace std;

#define SIZE 10

#ifdef DYNAMIC_MEMORY
#define array(name,size) type *name = new int[size]
#else
#define array(name,size) int name[size]
#endif
void fill(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
}

void output(int *array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << endl;
    }
}

int main() {
    array(arr, SIZE);
    fill(arr, SIZE);
    output(arr, SIZE);
#ifdef DYNAMIC_MEMORY
    delete[] arr
#endif
}
