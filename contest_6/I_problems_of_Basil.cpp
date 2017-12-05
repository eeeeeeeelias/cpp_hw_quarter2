#include <cctype>
#include <iostream>
#include <set>
#include <vector>

struct Contest{
    bool isNamingDigital = true;  // true = 1..20, false = A..T
    int numProblems = 0, contestID = 0;
    std::set<int> unsolvedProblems = {};
};

void AddProblems(Contest& contest, int first, int last) {
    for (int i = first; i <= last; ++i) {
        contest.unsolvedProblems.insert(i);
    }
}

void PrintContest(const Contest& contest, bool OneLiner) {
    if (OneLiner) {
        std::cout << contest.contestID;
        if (contest.isNamingDigital) {
            for (auto problemID : contest.unsolvedProblems) {
                std::cout << ' ' << problemID;
            }
        } else {
            for (auto problemID : contest.unsolvedProblems) {
                std::cout << ' ' << static_cast<char>('A' + problemID - 1);
            }
        }
        std::cout << '\n';
    } else {
        std::cout << "Contest ID: #" << contest.contestID << '\n';
        std::cout << contest.numProblems << " problems from ";
        if (contest.isNamingDigital) {
            std::cout << 1 << " to " << contest.numProblems << '\n';
            std::cout << "Unsolved problems are ";
            for (auto i : contest.unsolvedProblems) {
                std::cout << i << ' ';
            }
        } else {
            std::cout << "A to " << static_cast<char>('A' + contest.numProblems - 1) << '\n';
            for (auto i : contest.unsolvedProblems) {
                std::cout << static_cast<char>('A' + i - 1) << ' ';
            }
        }
        std::cout << '\n';
    }
}

void PrintUnsolvedProblems(const std::vector<Contest>& contests) {
    for (const auto& contest : contests) {
        PrintContest(contest, true);
    }
}

Contest LineToContest(std::string& rawData) {
    Contest currentContest;
    int spacePos = rawData.find(' ');
    currentContest.contestID = std::stoi(rawData.substr(0, spacePos));

    rawData = rawData.substr(spacePos + 1);
    spacePos = rawData.find(' ');
    if (spacePos != -1) {  // some problems are solved
        currentContest.numProblems = std::stoi(rawData.substr(0, spacePos));
        AddProblems(currentContest, 1, currentContest.numProblems);

        rawData = rawData.substr(spacePos + 1);
        if (std::isdigit(rawData[0])) {  // 1 2 3...
            currentContest.isNamingDigital = true;

            int problemID;
            while (rawData.size() > 0) {
                spacePos = rawData.find(' ');
                if (spacePos != -1) {
                    problemID = std::stoi(rawData.substr(0, spacePos));
                    currentContest.unsolvedProblems.erase(problemID);
                    rawData = rawData.substr(spacePos + 1);
                } else {  // last problem
                    problemID = std::stoi(rawData);
                    currentContest.unsolvedProblems.erase(problemID);
                    break;
                }
            }
        } else {  // A B C...
            currentContest.isNamingDigital = false;

            char problemID;
            while (rawData.size() > 2) {
                problemID = rawData[0] - 'A' + 1;
                currentContest.unsolvedProblems.erase(problemID);
                rawData = rawData.substr(2);
            }
            problemID = rawData[0] - 'A' + 1;
            currentContest.unsolvedProblems.erase(problemID);
        }
    } else {  // no solved problems
        currentContest.isNamingDigital = true;
        currentContest.numProblems = std::stoi(rawData);
        AddProblems(currentContest, 1, currentContest.numProblems);
    }

    return currentContest;
}

void ReadContests(std::vector<Contest>& contests) {
    std::string rawData;
    while (std::getline(std::cin, rawData)) {
        contests.push_back(LineToContest(rawData));
    }
}

int main() {
    std::vector<Contest> contests;
    ReadContests(contests);

    PrintUnsolvedProblems(contests);
}

