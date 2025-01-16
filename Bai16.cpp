#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

const int MAXN = 100;
const double INF = 1e9;

// Khai báo các biến toàn cục
int n;                   // Số đỉnh của đa giác
double a[MAXN], b[MAXN]; // Tọa độ các đỉnh
double d[MAXN][MAXN];    // Độ dài đường chéo
double L[MAXN][MAXN];    // Tổng độ dài các đường chéo nhỏ nhất
int H[MAXN][MAXN];       // Lưu đỉnh trung gian để truy vết

// Hàm tính khoảng cách giữa hai điểm
double KhoangCach(int i, int j)
{
    return sqrt(pow(a[i] - a[j], 2) + pow(b[i] - b[j], 2));
}

// Hàm khởi tạo độ dài các đường chéo
void TinhKhoangCachCacDuongCheo()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j || abs(i - j) == 1 || (i == 1 && j == n) || (j == 1 && i == n))
            {
                d[i][j] = 0; // Không có đường chéo nếu hai đỉnh liền kề
            }
            else
            {
                d[i][j] = KhoangCach(i, j);
            }
        }
    }
}

// Hàm Quy hoạch động để tính tổng độ dài nhỏ nhất
void QHD()
{
    // Khởi tạo bảng L
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            L[i][j] = (i == j || j == i + 1) ? 0 : INF;
        }
    }

    // Xây dựng bảng L và H
    for (int m = 2; m <= n - 1; m++)
    { // m là độ dài khoảng cách giữa i và j
        for (int i = 1; i <= n - m; i++)
        {
            int j = i + m;
            for (int k = i + 1; k < j; k++)
            {
                double tong = L[i][k] + L[k][j] + d[i][k] + d[k][j];
                if (tong < L[i][j])
                {
                    L[i][j] = tong;
                    H[i][j] = k; // Lưu đỉnh trung gian tốt nhất
                }
            }
        }
    }
}

// Hàm truy vết kết quả
void TruyVet(int i, int j)
{
    if (j - i >= 3)
    {
        int k = H[i][j];
        cout << "Noi dinh " << i << " voi k = " << k << " va noi k = " << k << " voi dinh " << j << " => L[" << i << "]" << "[" << j << "]" << endl;
        TruyVet(i, k);
        TruyVet(k, j);
    }
}

// Hàm chính
int main()
{
    // Nhập dữ liệu từ người dùng
    cout << "Nhap so dinh cua da giac: ";
    cin >> n;
    if (n < 3)
    {
        cout << "Da giac phai co it nhat 3 dinh!" << endl;
        return 0;
    }

    cout << "Nhap toa do cac dinh (x, y):" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "Dinh " << i << ": ";
        cin >> a[i] >> b[i];
    }

    // Tính toán
    TinhKhoangCachCacDuongCheo();
    QHD();

    // In kết quả
    cout << fixed << setprecision(2) << "Tong do dai nho nhat " << "L[1]" << "[" << n << "]" << ": " << L[1][n] << endl;
    cout << "Cac duong cheo toi uu:" << endl;
    TruyVet(1, n);

    return 0;
}
