#ifndef QUANLY_H
#define QUANLY_H

#include "QUANLYNHANVIEN.h"
#include "QuanLyKH.h"
#include <iostream>
#include <string>
#include "QuanLyDatSan.h"
#include "QuanLyDatNuoc.h"
#include "QuanLyDatXe.h"

using namespace std;

class QuanLi : public NhanVien {
public:
    // Constructor
    QuanLi(const string& username, const string& password, const string& phonenumber, int gender, Date& ngsinh, int loaitk = 2);

    // Các phương thức quản lý nhân viên
    void themNhanVien(NhanVien* nv);
    void xoaNhanVien(string sdt);
    void capNhatNhanVien(string sdt);
    NhanVien* timKiemNhanVien(string sdt);
    void xuatDanhSachNV(QuanLyNV& qlnv);

    // Các phương thức quản lý khách hàng
    void themKhachHang(KhachHang* kh);
    void xoaKhachHang(QuanLyKH& qlkh, string sdt);
    void capNhatKhachHang(QuanLyKH& qlkh, string sdt);
    KhachHang* timKiemKhachHang(QuanLyKH& qlkh, string sdt);
    void xuatDanhSachKH(QuanLyKH& qlkh);

    // Các phương thức quản lý dịch vụ - Đặt sân
    void themDatSanLe(QuanLyDatSan& qlds);
    void themDatSanDinhKy(QuanLyDatSan &qlds);
    void xoaDatSan(QuanLyDatSan& qlds);
    void capNhatDatSan(QuanLyDatSan& qlds);
    void xuatDanhSachDatSan(QuanLyDatSan& qlds);

    // Các phương thức hiển thị danh sách
    void xuatDanhSachNhanVien();
    void xuatDanhSachKhachHang();
    void xuatDanhSachHoaDon();
    void xuatDanhSachDatSan();
    void xuatDanhSachDatNuoc();
    void xuatDanhSachDatXe();
};

#endif // QUANLY_H
