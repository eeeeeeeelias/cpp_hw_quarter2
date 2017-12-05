#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

struct Point{
    int x, y;
};

double Distance(double y1, double x1, double y2, double x2) {
    return sqrt((y1 - y2) * (y1 - y2) + (x1 - x2) * (x1 - x2));
}

bool operator<(const Point& p1, const Point& p2) {
    return Distance(0, 0, p1.y, p1.x) < Distance(0, 0, p2.y, p2.x);
}

void ReadPoints(std::vector<Point>& points) {
    size_t vectorSize;
    std::cin >> vectorSize;
    points.resize(vectorSize);
    for (size_t i = 0; i < vectorSize; ++i) {
        std::cin >> points[i].x >> points[i].y;
    }
}

void PrintPoints(const std::vector<Point>& points) {
    for (auto point : points) {
        std::cout << point.x << ' ' << point.y << '\n';
    }
}

int main() {
    std::vector<Point> points;
    ReadPoints(points);
    std::sort(points.begin(), points.end());
    PrintPoints(points);
    return 0;
}
