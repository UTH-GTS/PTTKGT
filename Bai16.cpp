#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

// Hàm tính khoảng cách giữa hai điểm (x1, y1) và (x2, y2)
double distance(pair<double, double> p1, pair<double, double> p2)
{
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) +
                (p1.second - p2.second) * (p1.second - p2.second));
}

// Hàm tính tổng độ dài nhỏ nhất của các đường chéo để chia đa giác lồi
// Sử dụng Quy Hoạch Động (Dynamic Programming)
double minTriangulation(vector<pair<double, double>> &points, vector<vector<int>> &trace)
{
    int n = points.size(); // Số đỉnh của đa giác

    // Bảng DP: dp[i][j] lưu tổng độ dài nhỏ nhất để chia đoạn từ i đến j
    vector<vector<double>> dp(n, vector<double>(n, 0));

    // Duyệt khoảng cách giữa các đỉnh d (số lượng đỉnh giữa i và j)
    for (int d = 2; d < n; ++d)
    { // d bắt đầu từ 2 vì cần ít nhất 3 đỉnh để tạo tam giác
        for (int i = 0; i + d < n; ++i)
        {                  // i là đỉnh bắt đầu
            int j = i + d; // j là đỉnh kết thúc (cách i một khoảng d)

            dp[i][j] = INT_MAX; // Khởi tạo giá trị lớn để tìm min

            // Duyệt qua các đỉnh trung gian k giữa i và j
            for (int k = i + 1; k < j; ++k)
            {
                // Chi phí của tam giác (i, k, j):
                double cost = dp[i][k] + dp[k][j] +
                              distance(points[i], points[k]) +
                              distance(points[k], points[j]) +
                              distance(points[i], points[j]);

                // Cập nhật giá trị nhỏ nhất cho dp[i][j]
                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                    trace[i][j] = k; // Lưu đỉnh trung gian tốt nhất
                }
            }
        }
    }

    // Kết quả: Tổng độ dài nhỏ nhất từ đỉnh 0 đến đỉnh n-1
    return dp[0][n - 1];
}

// Hàm truy vết các đường chéo từ bảng trace
void printDiagonals(int i, int j, vector<vector<int>> &trace)
{
    if (j - i < 2)
        return; // Không có đường chéo trong đoạn nhỏ hơn 3 đỉnh

    int k = trace[i][j]; // Đỉnh trung gian tốt nhất
    cout << "Đường chéo: (" << i << ", " << k << ") và (" << k << ", " << j << ")\n";

    // Truy vết tiếp các đoạn trái và phải
    printDiagonals(i, k, trace);
    printDiagonals(k, j, trace);
}

int main()
{
    // Bước 1: Nhập số đỉnh và tọa độ các đỉnh của đa giác
    int n;
    cout << "Nhập số đỉnh của đa giác: ";
    cin >> n;

    if (n < 3)
    {
        cout << "Một đa giác cần ít nhất 3 đỉnh!" << endl;
        return 0;
    }

    vector<pair<double, double>> points(n);
    cout << "Nhập tọa độ các đỉnh (x y) theo thứ tự ngược chiều kim đồng hồ:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "Đỉnh " << i + 1 << ": ";
        cin >> points[i].first >> points[i].second;
    }

    // Bảng trace để lưu lại các đường chéo tốt nhất
    vector<vector<int>> trace(n, vector<int>(n, -1));

    // Bước 2: Gọi hàm tính tổng độ dài nhỏ nhất
    double result = minTriangulation(points, trace);

    // Bước 3: Xuất kết quả tổng độ dài
    cout << "Tổng độ dài nhỏ nhất của các đường chéo: " << result << endl;

    // Bước 4: Xuất các đường chéo chi tiết
    cout << "Danh sách các đường chéo: \n";
    printDiagonals(0, n - 1, trace);

    return 0;
}
