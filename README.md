# Phân Chia Đa Giác Lồi Tối Đa Chiều Dài Đường Chéo

Dự án này triển khai thuật toán tìm đường chéo ngắn nhất để chia một đa giác lồi với `N` đỉnh thành `N-2` tam giác sao cho tổng độ dài các đường chéo là nhỏ nhất. Chương trình được viết bằng C++ và sử dụng kỹ thuật lập trình động để giải quyết vấn đề.

## Đặc điểm

- Tính tổng chi phí đường chéo tối thiểu khi chia đa giác.
- Hỗ trợ đa giác lồi với bất kỳ số lượng đỉnh.
- Tính toán tổng độ dài đường chéo cho phương án tối ưu.

## Đầu vào

1. Số đỉnh của đa giác (`N`).
2. Tọạ độ của từng đỉnh theo thứ tự kim đồng hồ hoặc ngược chiều kim đồng hồ.

## Đầu ra

Chương trình xuất ra tổng độ dài đường chéo nhỏ nhất cần thiết để chia đa giác.

## Ví dụ

### Đầu vào
```
Nhập số đỉnh của đa giác: 4
Nhập tọạ độ của các đỉnh:
0 0
1 0
1 1
0 1
```

### Đầu ra
```
Tổng độ dài các đường chéo ngắn nhất là: 3.41421
```

## Thuật toán

### Ý tưởng

1. **Lập trình động:**
   - Sử dụng mảng 2D `dp[i][j]` để lưu chi phí nhỏ nhất khi chia đa giác từ đỉnh `i` đến `j`.
   - Với mỗi đa giác con (định từ `i` đến `j`), xét mỗi đường chéo `k` nằm giữa `i` và `j`.
   - Tính chi phí dài đường chéo và tổng chi phí của hai đa giác con chia bởi đường chéo.

2. **Công thức quy hoạch:**
   - Với mỗi đa giác con từ đỉnh `i` đến `j`, công thức:
     ```
     dp[i][j] = min(dp[i][k] + dp[k][j] + cost(i, j, k)) 
                 for all i < k < j
     ```
   - `cost(i, j, k)`: Chi phí tạo tam giác giữa các đỉnh `i, j, k`.

3. **Khởi tạo:**
   - Nếu `j - i < 2` (chỉ có 2 đỉnh hoặc ít hơn), không thể chia được, do đó `dp[i][j] = 0`.

4. **Kết quả:**
   - Giá trị cuối cùng `dp[0][N-1]` là chi phí nhỏ nhất để chia toàn bộ đa giác.

## Triển khai

1. **Cài đặt tọn khoảng cách:**
   - Khoảng cách giữa hai điểm `p1` và `p2` tính bằng công thức Euclid:
     ```
     distance = sqrt((x1 - x2)^2 + (y1 - y2)^2)
     ```

2. **Tính chi phí tam giác:**
   - Tam giác có 3 đỉnh `i, j, k` có chi phí:
     ```
     cost(i, j, k) = distance(i, j) + distance(j, k) + distance(k, i)
     ```

3. **Duyệt tất cả các đỉnh:**
   - Xét tất cả các cặp đỉnh `i` và `j`, với khoảng cách tăng dần (từ 2 đến `N-1`).
   - Tính `dp[i][j]` bằng cách thử mọi đường chéo `k` nằm giữa `i` và `j`.

4. **Kết quả cuối:**
   - Giá trị tại `dp[0][N-1]` chính là tổng chi phí đường chéo nhỏ nhất.

## Cách chạy chương trình

1. Clone repository này:
   ```bash
   git clone https://github.com/UTH-GTS/PTTKGT.git
   cd PTTKGT
   ```

2. Biên dịch chương trình:
   ```bash
   g++ -o Bai16.cpp bai16 -std=c++11
   ```

3. Chạy chương trình:
   ```bash
   ./bai16
   ```

4. Nhập các tọạ độ của đa giác theo hướng dẫn.

## Cấu trúc thư mục

```
PTTKGT/
├── Bai16.cpp   # Tệp mã nguồn chính
├── README.md           # Tài liệu hướng dẫn
```


