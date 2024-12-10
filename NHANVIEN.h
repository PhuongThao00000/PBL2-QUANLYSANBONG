#ifndef NHANVIEN_H
#define NHANVIEN_H

#include "QuanLyDatNuoc.h"
#include "QuanLyDatNuoc.cpp"
#include "USER.h"
// #include "QuanLyDatSan.h"
// #include "QuanLyDatSan.cpp"
#include "QuanLyDatXe.h"
#include "QuanLyDatXe.cpp"
// #include "QuanLyHoaDon.h"
// #include "QuanLyHoaDon.cpp"
// #include "QuanLyKH.h"
// #include "QuanLyKH.cpp"

class NhanVien : public User {

public:
    NhanVien():User(){}
    NhanVien(const string& username , const string& password ,const string& phonenumber,int gender, Date& ngsinh,int loaitk=1)
        : User(username,password,phonenumber,gender,ngsinh,loaitk){}

    ~NhanVien() {}

    void xuatthongtin()const;
    // Quản lý khách hàng
    // void themKhachHang(KhachHang* kh);

    // void xoaKhachHang(string sdt);

    // void capNhatKhachHang(string sdt) ;
    // void timKiemKhachHang(string sdt);

    // Quản lý đặt sân
    // void themDatSanLe(string sdt) ;

    // void themDatSanDinhKy(string sdt) ;

    // void xoaDatSan(string sdt) ;

    // void capNhatDatSan(string sdt) ;

    // Quản lý hóa đơn
    // void themHoaDon(HoaDon* hd) ;

    // void xoaHoaDon(string sdt) ;

    // void capNhatHoaDon(string sdt, string status) ;

    // void thongKeDoanhThu(string ngay) ;

    // Quản lý đặt nước(co ngay va gio ban)
    void themDatNuoc(QuanLyDatNuoc&qldn) ;

    DatNuoc* timkiemDatNuoc(QuanLyDatNuoc&qldn, const int& maDon);

    void capnhatDatNuoc(QuanLyDatNuoc&qldn, const int& maDon);

    void xoaDatNuoc(QuanLyDatNuoc&qldn,const int& maDon);

    void xuatDatNuocTheoNgay(QuanLyDatNuoc&qldn,int day, int month, int year);
    //Quan ly cac ve giu xe(co ngay va gio giu xe)
    void themDatXe(QuanLyDatXe&qldx) ;

    DatXe* timkiemDatXe(QuanLyDatXe&qldx, const int& maDon);

    void capnhatGiuXe(QuanLyDatXe&qldx,const int& maDon);

    void xoaGiuXe(QuanLyDatXe&qldx,const int& maDon);

    void xuatGiuXeTheoNgay(QuanLyDatXe&qldx,int day, int month, int year);

};


#endif