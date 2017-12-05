#include <iostream>
#include <vector>

template <class InputIt, class T>
T accumulate_range(InputIt first, InputIt last, T init) {
    while (first != last) {
        init += *first++;
    }
    return init;
}
