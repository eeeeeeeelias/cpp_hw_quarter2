std::string ExtractDigits(const std::string& s) {
    std::string answer = "";
    for (char c : s) {
        if ('0' <= c && c <= '9') {
            answer += c;
        }
    }
    return answer;
}

