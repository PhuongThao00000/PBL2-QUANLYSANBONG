#ifndef DICHVU_H
#define DICHVU_H

#include <string>
#include <iostream>
using namespace std;
#include <ctime>
#include "DATE.h"

class DichVu {
protected:
    string tennhanvien;
    static int maDonCounter; // Bộ đếm mã đơn (tĩnh, dùng chung cho tất cả đối tượng)
    int maDon; // Mã đơn của từng đối tượng
    Date ngayban; // Ngày bán
    string gioban;  // Giờ bán
public:
    DichVu(string namenhanvien);
    virtual ~DichVu();
    virtual void xuat()=0;
    // virtual const int& getGia()= 0;
    string getTenNhanVien() const;
	bool operator==(const DichVu&dv){
		return maDon==dv.maDon;
	}
    // Getter cho mã đơn
    int getMaDon() const;
    static void setGioBan(string& gioban) {
			std::time_t now = std::time(0);           // Lấy thời gian hiện tại
    		std::tm* ltm = std::localtime(&now);      // Chuyển đổi sang cấu trúc thời gian

    		// Thiết lập giờ bán (hh:mm)
    		char buffer[6];
    		std::sprintf(buffer, "%02d:%02d", ltm->tm_hour, ltm->tm_min);
    		gioban = buffer;
		}
	static void setNgayBan(Date& ngayban) {
		std::time_t now = std::time(0);           // Lấy thời gian hiện tại
    	std::tm* ltm = std::localtime(&now);      // Chuyển đổi sang cấu trúc thời gian

    // Thiết lập ngày bán
    	ngayban.ngay=(ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900); // Ngày, tháng, năm
	}
        // Getter and Setter for gioBan
		const string getGioBan() const {
			return gioban;
		}

		// Thêm hàm để lấy ngày và giờ bán (ngày + giờ)
		const string getNgayGioBan() const {
			return ngayban.GetNgay() + " " + gioban;
		}
        // Lấy ngày thông kê
		const string getNgayBan() const {
			return ngayban.GetNgay();
		}
};

#endif // DICHVU_H
