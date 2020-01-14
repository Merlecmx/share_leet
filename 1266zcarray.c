int Max(int a, int b) {
        return a > b ? a : b;
    }
int abs(int n) {
    return n > 0 ? n : -n;
}
int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize) {
    int time = 0;
    int i = 1;
    for (time, i; i < pointsSize; i++) {
        int x_dist = abs(points[i][0] - points[i - 1][0]);
        int y_dist = abs(points[i][1] - points[i - 1][1]);
        time += Max(x_dist, y_dist);
    }
    return time;
}
