#include <iostream>
#include <cmath>
#include <vector>

struct Point {
    int value; //group
    double x, y, distance;
};

//knn func
bool classify(std::vector<Point> arr, int n, int k, Point p) {
    for (int i = 0; i < n; i++) {
        arr[i].distance = std::sqrt((arr[i].x - p.x) * (arr[i].x - p.x) +
                                    (arr[i].y - p.y) * (arr[i].y - p.y));
    }//fill distances
    std::sort(arr.begin(), arr.end(), [](Point a, Point b) { return a.distance < b.distance; });
    //order by distance
    int a = 0;
    int b = 0;
    for (int i = 0; i < k; i++) {
        (arr[i].value == 0) ? a++ : b++;
    }//classify by greatest
    return ((a > b) ? 0 : 1);
}
