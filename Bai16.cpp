#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

// Hàm tính khoảng cách giữa hai điểm
double distance(pair<double, double> a, pair<double, double> b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

// Hàm tính chi phí của tam giác
double cost(int i, int j, int k, const vector<pair<double, double>> &points) {
    return distance(points[i], points[j]) + distance(points[j], points[k]) + distance(points[k], points[i]);
}

// Hàm tìm chi phí tối thiểu để chia đa giác
double minTriangulationCost(const vector<pair<double, double>> &points) {
    int n = points.size();
    vector<vector<double>> dp(n, vector<double>(n, 0));

    // Duyệt qua các độ dài đoạn (j - i)
    for (int length = 2; length < n; ++length) {
        for (int i = 0; i < n - length; ++i) {
            int j = i + length;
            dp[i][j] = numeric_limits<double>::infinity();
            // Duyệt qua tất cả các điểm k nằm giữa i và j
            for (int k = i + 1; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cost(i, k, j, points));
            }
        }
    }
    return dp[0][n - 1]; // Kết quả cuối cùng
}

int main() {
    // Nhập số đỉnh và tọa độ các đỉnh của đa giác
    int n;
    cout << "Nhập số đỉnh của đa giác: ";
    cin >> n;

    vector<pair<double, double>> points(n);
    cout << "Nhập tọa độ các đỉnh (x, y):" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    // Tính chi phí tối thiểu
    double result = minTriangulationCost(points);
    cout << "Tổng độ dài tối thiểu của các đường chéo: " << result << endl;

    return 0;
}
