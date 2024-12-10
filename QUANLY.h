#ifndef QUANLY_H
#define QUANLY_H

#include "QUANLYNHANVIEN.h"
#include "QUANLYNHANVIEN.cpp"
#include "QuanLyKH.h"
#include "QuanLyKH.cpp"


class QuanLi: public NhanVien {
public:
    QuanLi(const string& username , const string& password ,const string& phonenumber,int gender, Date& ngsinh,int loaitk=2);
   // Các phương thức quản lý nhân viên
    void themNhanVien(NhanVien* nv);

    void xoaNhanVien(string sdt);

    void capNhatNhanVien(string sdt);

    NhanVien* timKiemNhanVien(string sdt);
    void xuatDanhSachNV(QuanLyNV &qlnv);

    // Các phương thức quản lý khách hàng
    void themKhachHang(KhachHang* kh);

    void xoaKhachHang(QuanLyKH& qlkh,string sdt);

    void capNhatKhachHang(QuanLyKH& qlkh,string sdt);

    KhachHang* timKiemKhachHang(QuanLyKH& qlkh,string sdt);

    void xuatDanhSachKH(QuanLyKH &qlkh);
    // Các phương thức quản lý dịch vụ - Đặt sân
    void themDatSanLe(QuanLyDatSan& qlds) ;

    void themDatSanDinhKy(QuanLyDatSan &qlds) ;

    void xoaDatSan(QuanLyDatSan&qlds) ;

    void capNhatDatSan(QuanLyDatSan&qlds) ;
    
    void xuatDanhSachDatSan(QuanLyDatSan&qlds);


    // // Các phương thức quản lý hóa đơn
    // // void themHoaDon(HoaDon* hd) ;

    // void xoaHoaDon(string sdt);

    // void capNhatHoaDon(string sdt, string status);

    // void thongKeDoanhThu(string ngay) ;

    // Phương thức hiển thị thông tin thống kê
    // void thongKeDoanhThuTheoNgay(int day, int month, int year) {
    //     cout << "Doanh thu theo ngày " << day << "/" << month << "/" << year << ":\n";
    //     cout << "Doanh thu nước: " << qlDatNuoc.getDoanhThu() << endl;
    //     cout << "Doanh thu xe: " << qlDatXe.getDoanhThu() << endl;
    //     cout << "Doanh thu sân: " << qlDatSan.getDoanhThu() << endl;
    //     cout << "Tổng doanh thu: " << qlHoaDon.getDoanhThu() << endl;
    // }

    // Các phương thức hiển thị danh sách
    void xuatDanhSachNhanVien() ;

    void xuatDanhSachKhachHang();

    void xuatDanhSachHoaDon() ;

    void xuatDanhSachDatSan() ;
    void xuatDanhSachDatNuoc() ;
    void xuatDanhSachDatXe();
};

#endif
