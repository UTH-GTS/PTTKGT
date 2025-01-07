# Bài Toán: Chia Đa Giác Lồi Thành Tam Giác Với Tổng Độ Dài Các Đường Chéo Nhỏ Nhất

## Mô Tả Bài Toán
Cho một đa giác lồi có \(N\) đỉnh, được xác định bởi tọa độ của các đỉnh theo thứ tự ngược chiều kim đồng hồ. Bằng cách sử dụng các đường chéo không cắt nhau, đa giác được chia thành \(N-2\) tam giác. Mục tiêu là xác định cách chia sao cho **tổng độ dài các đường chéo** là nhỏ nhất.

---

## Công Thức Sử Dụng

Bài toán được giải quyết bằng phương pháp **Quy Hoạch Động (Dynamic Programming)**. Công thức tính tổng độ dài nhỏ nhất được mô tả như sau:

\[
dp[i][j] = \min_{k=i+1}^{j-1} \big( dp[i][k] + dp[k][j] + \text{distance}(i, k) + \text{distance}(k, j) + \text{distance}(i, j) \big)
\]

### Giải Thích Công Thức:
- **\(dp[i][j]\):** Tổng độ dài nhỏ nhất của các đường chéo để chia đoạn từ đỉnh \(i\) đến \(j\).
- **\(k\):** Điểm trung gian để chia đoạn \(i \to j\) thành hai phần: \(i \to k\) và \(k \to j\).
- **\(\text{distance}(x, y)\):** Độ dài đoạn thẳng giữa hai điểm \(x\) và \(y\), được tính bằng công thức:
  \[
  \text{distance}(x, y) = \sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2}
  \]

---

## Giải Pháp

### Ý Tưởng Chính
1. **Chia để trị:**
   - Chia đoạn \(i \to j\) thành hai đoạn nhỏ hơn thông qua điểm trung gian \(k\).
   - Tính tổng độ dài tối ưu cho từng đoạn nhỏ, sau đó cộng với độ dài của tam giác \((i, k, j)\).

2. **Quy Hoạch Động:**
   - Sử dụng bảng \(dp\) để lưu trữ kết quả tối ưu của từng đoạn \(i \to j\).
   - Lặp qua tất cả các đoạn và các điểm trung gian để cập nhật giá trị tối ưu.

### Quy Trình Tính Toán
1. Khởi tạo bảng \(dp\):
   - \(dp[i][j] = 0\) nếu \(j - i < 2\) (không cần chia).
2. Lặp qua tất cả các đoạn \(i \to j\):
   - Tìm giá trị nhỏ nhất \(dp[i][j]\) bằng cách thử tất cả các điểm trung gian \(k\).
3. Truy vết từ bảng \(trace\) để xác định các tam giác trong cách chia tối ưu.

---

## Hướng Dẫn Chạy

1. **Nhập Tọa Độ Đa Giác:**
   - Nhập số đỉnh \(N\).
   - Nhập tọa độ của từng đỉnh theo thứ tự ngược chiều kim đồng hồ.

2. **Kết Quả Xuất Ra:**
   - Danh sách các tam giác trong cách chia tối ưu.
   - Độ dài các đường chéo của từng tam giác.
   - Tổng độ dài nhỏ nhất của các đường chéo.

---

## Ví Dụ

### Đầu Vào:
```
Nhập số đỉnh của đa giác: 5
Nhập tọa độ các đỉnh (x y) theo thứ tự ngược chiều kim đồng hồ:
Đỉnh A (x y): 0 0
Đỉnh B (x y): 1 0
Đỉnh C (x y): 1 1
Đỉnh D (x y): 0.5 1.5
Đỉnh E (x y): 0 1
```

### Đầu Ra:
```
Danh sách các tam giác và đường chéo chi tiết:
Tam giác: (A - C - E)
Đường chéo: (A, C) = 1.41, (C, E) = 1.11, (A, E) = 1.81
Tổng độ dài các đường chéo của tam giác: 4.33

Tam giác: (A - B - C)
Đường chéo: (A, B) = 1.00, (B, C) = 1.41, (A, C) = 1.41
Tổng độ dài các đường chéo của tam giác: 3.82

Tam giác: (C - D - E)
Đường chéo: (C, D) = 1.12, (D, E) = 1.12, (C, E) = 1.11
Tổng độ dài các đường chéo của tam giác: 3.35

Tổng độ dài nhỏ nhất của các đường chéo (dp[0][n-1]): 11.50
```

---

## Ghi Chú
- **Yêu Cầu:**
  - Đảm bảo các đỉnh được nhập theo thứ tự ngược chiều kim đồng hồ.
  - Đầu vào phải là một đa giác lồi hợp lệ.
- **Ứng Dụng:**
  - Bài toán này có thể áp dụng trong các lĩnh vực như đồ họa máy tính, xử lý hình học, và tối ưu hóa.

---

## Liên Hệ
Nếu có thắc mắc hoặc cần hỗ trợ thêm, vui lòng liên hệ!

