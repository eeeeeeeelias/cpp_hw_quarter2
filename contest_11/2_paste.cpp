#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

size_t ReadFile(
        std::vector<std::vector<std::string>>& files,
        size_t fileNumber) {
    size_t fileLength;
    std::cin >> fileLength;
    std::string myLine;
    std::getline(std::cin, myLine);

    files[fileNumber].resize(fileLength);
    for (size_t i = 0; i != fileLength; ++i) {
        std::getline(std::cin, myLine);
        files[fileNumber][i] = myLine;
    }
    return fileLength;
}

void PrintFiles(
        const std::vector<std::vector<std::string>>& files,
        size_t maxFileLength) {
    for (size_t i = 0; i != maxFileLength; ++i) {
        if (files[0].size() > i) {
            std::cout << files[0][i];
        }
        for (size_t fileNumber = 1; fileNumber != files.size(); ++fileNumber) {
            std::cout << '\t';
            if (files[fileNumber].size() > i) {
                std::cout << files[fileNumber][i];
            }
        }
        std::cout << '\n';
    }
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    size_t numFiles;
    std::cin >> numFiles;
    std::string fictiveLine;
    std::getline(std::cin, fictiveLine);

    std::vector<std::vector<std::string>> files(numFiles);

    size_t maxFileLength = 0, currentLength;
    for (size_t i = 0; i != numFiles; ++i) {
        currentLength = ReadFile(files, i);
        maxFileLength = std::max(maxFileLength, currentLength);
    }
    PrintFiles(files, maxFileLength);
}
