#include <iostream>
#include <vector>

template <typename Iter>
Iter unique(Iter first, Iter last) {
    if (!(first == last)) {
        Iter currentIt = first;
        for (auto it = first; it != last; ++it) {
            if (*it != *currentIt) {
                ++currentIt;
                *currentIt = *it;
            }
        }
        return ++currentIt;
    } else {
        return last;
    }
}

