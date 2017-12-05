#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<vector<int>> transpose(const vector<vector<int>>& matrix) {
        size_t n = matrix.size();
            size_t m = matrix[0].size();
                vector<vector<int>> newVector;
                    newVector.resize(m);
                        for (int i = 0; i < m; ++i) {
                                        newVector[i].resize(n);
                                                for (int j = 0; j < n; ++j) {
                                                                newVector[i][j] = matrix[j][i];
                                                                        }
                                                    }
                            return newVector;
}

int main() {
        int n, m;
            cin >> n >> m;
                vector<vector<int>> myVector;
                    myVector.resize(n);
                    std::cout << "first reserving\n";
                        for (int i = 0; i < n; ++i) {
                                    myVector[i].resize(m);
                                    std::cout << "here i = " << i << "\n";
                                            for (int j = 0; j < m; ++j) {
                                                            cin >> myVector[i][j];
                                                                    }
                                                }
                            vector<vector<int>> newvec;
                                newvec = transpose (myVector);
                                system("pause");
                                cout << "we're here\n";
                                cout << newvec.size() << "x" << newvec[0].size() << "\n";
                                    for (int i = 0; i < m; ++i) {
                                                for (int j = 0; j < n; ++j) {
                                                                cout << newvec [i][j] << " ";
                                                                        }
                                                        cout << endl;
                                                            }
                                        return 0;
}
