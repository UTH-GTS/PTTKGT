# **Chương trình tính tổng độ dài các đường chéo tối ưu trong đa giác lồi**

## **Giới thiệu**
Chương trình được viết bằng C++ nhằm tìm cách chia một đa giác lồi \( N \) đỉnh thành \( N-2 \) tam giác sao cho tổng độ dài các đường chéo là nhỏ nhất. Kết quả bao gồm tổng độ dài tối thiểu và danh sách các đường chéo tối ưu.


## Cách hoạt động

- **Bước 1**: Nhập tọa độ các đỉnh của đa giác.
- **Bước 2**: Sử dụng công thức tính khoảng cách giữa hai điểm để khởi tạo độ dài các đường chéo.
- **Bước 3**: Áp dụng Quy hoạch động để tính tổng độ dài nhỏ nhất của các đường chéo.
- **Bước 4**: Truy vết để tìm các đường chéo tối ưu.

## Cấu trúc chương trình

- `KhoangCach(int i, int j)`: Hàm tính khoảng cách giữa hai điểm.
- `TinhKhoangCachCacDuongCheo()`: Hàm khởi tạo độ dài các đường chéo.
- `QHD()`: Hàm thực hiện Quy hoạch động để tính tổng độ dài nhỏ nhất.
- `TruyVet(int i, int j)`: Hàm truy vết để xác định các đường chéo tối ưu.
- `main()`: Hàm chính điều khiển chương trình.

---

## **Hướng dẫn sử dụng**

   ```bash
   git clone https://github.com/UTH-GTS/PTTKGT.git
   cd PTTKGT/output
   ./Bai16
   ```



---
## **Ví dụ**
# Đầu vào:
   ```bash
   Nhap so dinh cua da giac: 4
   Nhap toa do cac dinh (x, y):
   Dinh 1: 0 0
   Dinh 2: 1 0
   Dinh 3: 1 1
   Dinh 4: 0 1
   ```

# Đầu ra:

   ```bash
   Tong do dai nho nhat: 2.83
   Cac duong cheo toi uu:
   Noi dinh 1 voi dinh 3
   Noi dinh 3 voi dinh 4
   ```


# Ghi chú
Đa giác phải được nhập theo thứ tự ngược chiều kim đồng hồ.
Đa giác cần có ít nhất 3 đỉnh.
Chương trình sẽ tính toán và in ra kết quả chính xác với độ chính xác 2 chữ số thập phân.