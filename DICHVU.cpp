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

bool DichVu::operator==(const DichVu&dv){
		return maDon==dv.maDon;
}

void DichVu::setGioBan(string& gioban) {
    std::time_t now = std::time(0);           // Lấy thời gian hiện tại
    std::tm* ltm = std::localtime(&now);      // Chuyển đổi sang cấu trúc thời gian

    // Thiết lập giờ bán (hh:mm)
    char buffer[6];
    std::sprintf(buffer, "%02d:%02d", ltm->tm_hour, ltm->tm_min);
    gioban = buffer;
}
void DichVu::setNgayBan(Date& ngayban) {
	std::time_t now = std::time(0);           // Lấy thời gian hiện tại
    std::tm* ltm = std::localtime(&now);      // Chuyển đổi sang cấu trúc thời gian

    // Thiết lập ngày bán
    ngayban.ngay=(ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900); // Ngày, tháng, năm
}

// Getter and Setter for gioBan
const string DichVu::getGioBan() const {
	return gioban;
}

// Thêm hàm để lấy ngày và giờ bán (ngày + giờ)
const string DichVu::getNgayGioBan() const {
	return ngayban.GetNgay() + " " + gioban;
}

// Lấy ngày thông kê
const string DichVu::getNgayBan() const {
	return ngayban.GetNgay();
}
