#include <iostream>
#include <deque>
#include <string>
#include <cassert>

using namespace std;

template<typename T, typename Container = deque<T> >
class Queue {
    Container container;

public:
    T &top() {
        return container.front();
    }

    void push(const T &value) {
        container.push_back(value);
    }

    bool empty() const {
        return container.empty();
    }

    void pop() {
        if (!empty()) {
            container.pop_front();
        }
    }

    size_t len() const {
        return container.size();
    }
};

// Полная специализация для string
template<>
class Queue<char, string> {
    string container;

public:
    char top() const {
        return container.front();
    }

    void push(char c) {
        container.push_back(c);
    }

    bool empty() const {
        return container.empty();
    }

    void pop() {
        if (!empty()) {
            container.erase(0, 1);
        }
    }

    size_t len() const {
        return container.size();
    }
};


int main() {
    Queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    assert(q1.top() == 1);
    assert(q1.len() == 3);
    assert(q1.empty() == 0);
    q1.pop();
    assert(q1.top() == 2);


    Queue<char, string> q2;
    q2.push('a');
    q2.push('b');
    assert(q2.top() == 'a');
    assert(q2.len() == 2);
    q2.pop();
    assert(q2.top() == 'b');

    return 0;
}
