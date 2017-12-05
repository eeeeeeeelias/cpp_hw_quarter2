#include <iostream>
#include <vector>

uint64_t ReadHacker(uint64_t numLangs) {
    uint64_t hacker = 0, doesKnow;
    for (uint64_t i = 0; i < numLangs; ++i) {
        std::cin >> doesKnow;
        hacker = (hacker << 1) + doesKnow;
    }
    return hacker;
}

bool IsDreamTeam(
        const std::vector<uint64_t>& persons,
        uint64_t whoPicked,
        uint64_t perfectKnowledge) {
    uint64_t teamKnowledge = 0;
    for (uint64_t i = 0; i < persons.size(); ++i) {
        if (whoPicked & 1) {  // recruiting this one
            teamKnowledge |= persons[i];
        }
        whoPicked >>= 1;
    }
    return teamKnowledge == perfectKnowledge;
}

int main() {
    uint64_t numHackers, numLangs;
    std::cin >> numHackers >> numLangs;
    std::vector<uint64_t> hackers(numHackers);
    for (uint64_t i = 0; i < numHackers; ++i) {
        hackers[i] = ReadHacker(numLangs);
    }

    uint64_t allLangs = (1 << numLangs) - 1, allHackers = (1 << numHackers) - 1;
    uint64_t dreamTeamCount = 0;
    for (uint64_t teamID = 0; teamID <= allHackers; ++teamID) {
        if (IsDreamTeam(hackers, teamID, allLangs)) {
            ++dreamTeamCount;
        }
    }

    std::cout << dreamTeamCount << '\n';
}
