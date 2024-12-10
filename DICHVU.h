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

    string getTenNhanVien() const;

	bool operator==(const DichVu&dv);

    // Getter cho mã đơn
    int getMaDon() const;

    static void setGioBan(string& gioban) ;

	static void setNgayBan(Date& ngayban);

    // Getter and Setter for gioBan
	const string getGioBan() const;

	// Thêm hàm để lấy ngày và giờ bán (ngày + giờ)
	const string getNgayGioBan() const;
	
    // Lấy ngày thông kê
	const string getNgayBan() const;
};

#endif // DICHVU_H
