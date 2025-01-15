#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    int n;
    cout << "Nhap so luong so nguyen: ";
    cin >> n;

    int* A = new int[n]; // Mảng lưu các số nguyên
    cout << "Nhap cac so nguyen: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // Tính tổng của tất cả các phần tử
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += A[i];
    }

    int half = total / 2; // Mục tiêu là tìm tổng gần nhất với total/2

    // Mảng dp để lưu các khả năng tổng
    bool* dp = new bool[half + 1]{ false };
    dp[0] = true; // Luôn có thể tạo được tổng 0

    // Quy hoạch động
    for (int i = 0; i < n; i++) {
        for (int j = half; j >= A[i]; j--) {
            dp[j] = dp[j] || dp[j - A[i]];
        }
    }

    // Tìm tổng gần nhất với total/2
    int sum1 = 0;
    for (int i = half; i >= 0; i--) {
        if (dp[i]) {
            sum1 = i;
            break;
        }
    }

    int sum2 = total - sum1; // Tổng còn lại
    int maxProduct = sum1 * sum2; // Tích lớn nhất

    // In kết quả
    cout << "Tong nhom 1: " << sum1 << endl;
    cout << "Tong nhom 2: " << sum2 << endl;
    cout << "Tich lon nhat giua tong hai nhom: " << maxProduct << endl;

    // Giải phóng bộ nhớ
    delete[] A;
    delete[] dp;

    return 0;
}
