char CaseChange(char c) {
    if ('a' <= c && c <= 'z') {
        return c - 'a' + 'A';
    } else if ('A' <= c && c <= 'Z') {
        return c - 'A' + 'a';
    } else {
        return c;
    }
}

