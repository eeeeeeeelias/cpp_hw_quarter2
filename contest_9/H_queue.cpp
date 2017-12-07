#include <cstdlib>
#include <deque>
#include <iostream>

template <typename T, typename Container = std::deque<T>>
class Queue {
 private:
    Container source_;

 public:
    Queue() {
        source_.clear();
    }

    bool empty() {
        return source_.empty();
    }

    T front() const {
        return source_.front();
    }

    T& front() {
        return *source_.begin();
    }

    void pop() {
        source_.pop_front();
    }

    void push(const T& element) {
        source_.push_back(element);
    }

    size_t size() {
        return source_.size();
    }

    bool operator== (const Queue<T>& rhs) {
        return source_ == rhs.source_;
    }

    bool operator!= (const Queue<T>& rhs) {
        return source_ != rhs.source_;
    }
};

/*
int main() {
    Queue<int> q1;
    Queue<int> q2;
    q1.push(5);
    std::cout << q1.size() << '\n';
    q2.push(6);
    std::cout << (q1 == q2) << '\n';
    q2.push(5);
    std::cout << q2.front() << '\n';
    q2.pop();
    std::cout << (q1 == q2) << '\n';
    q2.pop();
    std::cout << q2.empty() << '\n';
    return 0;
}
*/

