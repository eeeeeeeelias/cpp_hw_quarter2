#include <iostream>

int main() {
    int wTotal, wWorkpiece, wDetail;
    std::cin >> wTotal >> wWorkpiece >> wDetail;
    int detailCount = 0;
    if (wTotal < wWorkpiece || wWorkpiece < wDetail) {  // too big workpiece/detail
        detailCount = 0;
    } else {
        int detailsPerWorkpiece = wWorkpiece / wDetail;
        int wRemaining = wTotal;
        while (wRemaining >= wWorkpiece) {
            int currentNWorkpiece = wRemaining / wWorkpiece;
            detailCount += currentNWorkpiece * detailsPerWorkpiece;
            wRemaining -= currentNWorkpiece * detailsPerWorkpiece * wDetail;
        }
    }
    std::cout << detailCount << "\n";
}

