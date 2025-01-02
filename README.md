# PTTKGT
Phan tich thiet ke va giai thuat
# Bài toán Triangulation của Đa giác Lồi

## Mô tả bài toán
Cho một đa giác lồi với \( N \) đỉnh. Bằng các đường chéo không cắt nhau, chúng ta có thể chia đa giác thành \( N - 2 \) tam giác. Nhiệm vụ là tìm cách chia sao cho tổng độ dài các đường chéo được sử dụng là **nhỏ nhất**.

---

## Ý tưởng giải bài toán

### Biểu diễn bài toán
- Đa giác lồi được biểu diễn bằng \( N \) đỉnh, đánh số từ \( 1 \) đến \( N \).
- Mỗi cách chia đa giác thành tam giác có thể được biểu diễn bằng tập hợp các đường chéo không cắt nhau.

### Mục tiêu
- Tính tổng độ dài của các đường chéo được sử dụng.
- Tìm cách chia sao cho tổng độ dài này là nhỏ nhất.

---

## Quy hoạch động

### Định nghĩa
- Đặt \( dp[i][j] \) là **chi phí tối thiểu** để chia nhỏ phần đa giác từ đỉnh \( i \) đến \( j \).

### Công thức truy hồi
\[
dp[i][j] = \min_{k=i+1}^{j-1} \left( dp[i][k] + dp[k][j] + \text{cost}(i, k, j) \right)
\]
Trong đó:
- \( \text{cost}(i, k, j) \): độ dài của đường chéo giữa \( i \) và \( j \).

---

## Cách tính độ dài đường chéo
- Nếu tọa độ các đỉnh của đa giác là \( (x_i, y_i) \), thì độ dài đường chéo giữa hai đỉnh \( i \) và \( j \) là:
\[
\text{distance}(i, j) = \sqrt{(x_j - x_i)^2 + (y_j - y_i)^2}
\]

---

## Thuật toán
1. **Khởi tạo:**
   - \( dp[i][j] = 0 \) nếu \( j - i < 2 \) (không thể tạo tam giác).

2. **Quá trình duyệt:**
   - Duyệt qua các đoạn \( dp[i][j] \) với \( j - i \geq 2 \), tính giá trị tối ưu dựa trên công thức truy hồi.

3. **Kết quả:**
   - Trả về \( dp[1][N] \), chi phí tối thiểu cho toàn bộ đa giác.

---

## Triển khai thuật toán (C++)

```cpp
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
