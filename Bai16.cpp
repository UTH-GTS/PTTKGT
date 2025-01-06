#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

// Cấu trúc điểm trong không gian 2D
struct Point
{
    double x, y;
};

// Hàm tính khoảng cách giữa hai điểm
double distance(const Point &p1, const Point &p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// Hàm tính chi phí tạo tam giác từ 3 đỉnh
double triangleCost(const vector<Point> &points, int i, int j, int k)
{
    return distance(points[i], points[j]) + distance(points[j], points[k]) + distance(points[k], points[i]);
}

// Hàm tìm cách chia đa giác với tổng độ dài đường chéo nhỏ nhất
double minCostTriangulation(const vector<Point> &points)
{
    int n = points.size();
    vector<vector<double>> dp(n, vector<double>(n, 0));

    // Duyệt khoảng cách giữa các đỉnh (length = j - i)
    for (int length = 2; length < n; ++length)
    {
        for (int i = 0; i < n - length; ++i)
        {
            int j = i + length;
            dp[i][j] = numeric_limits<double>::max();

            // Chọn điểm k giữa i và j
            for (int k = i + 1; k < j; ++k)
            {
                double cost = dp[i][k] + dp[k][j] + triangleCost(points, i, k, j);
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[0][n - 1];
}

int main()
{
    int n;
    cout << "Nhập số đỉnh của đa giác: ";
    cin >> n;

    vector<Point> points(n);
    cout << "Nhập tọa độ các đỉnh (x, y):" << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> points[i].x >> points[i].y;
    }

    double result = minCostTriangulation(points);
    cout << "Tổng độ dài các đường chéo ngắn nhất là: " << result << endl;

    return 0;
}
