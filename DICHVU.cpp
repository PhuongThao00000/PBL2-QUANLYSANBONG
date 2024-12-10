#include "DICHVU.h"

// Khởi tạo giá trị ban đầu cho bộ đếm mã đơn
int DichVu::maDonCounter = 0;

// Hàm khởi tạo
DichVu::DichVu(string namenhanvien) 
    : tennhanvien(namenhanvien), maDon(++maDonCounter) {
        setNgayBan(ngayban);
        setGioBan(gioban);
    }

// Hàm hủy
DichVu::~DichVu() {}

// Getter cho tên nhân viên
string DichVu::getTenNhanVien() const {
    return tennhanvien;
}

// Getter cho mã đơn
int DichVu::getMaDon() const {
    return maDon;
}
