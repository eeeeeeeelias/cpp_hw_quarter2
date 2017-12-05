template <typename InIter, typename OutIter>
OutIter reverse_copy(InIter first, InIter last, OutIter out) {
    while (last != first) {
        *out++ = *--last;
    }
    return out;
}

