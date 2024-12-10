#ifndef NHANVIEN_H
#define NHANVIEN_H

#include "USER.h"
#include "QuanLyDatNuoc.h"
#include "QuanLyDatXe.h"
#include <iostream>
#include <string>

class NhanVien : public User {
public:
    NhanVien();  // Constructor mac dinh
    NhanVien(const string& username, const string& password, const string& phonenumber, int gender, Date& ngsinh, int loaitk = 1); 
    ~NhanVien();  // Destructor

    // Xuat thong tin NhanVien
    void xuatthongtin() const;

    // Quản lý đặt nước
    void themDatNuoc(QuanLyDatNuoc& qldn);
    DatNuoc* timkiemDatNuoc(QuanLyDatNuoc& qldn, const int& maDon);
    void capnhatDatNuoc(QuanLyDatNuoc& qldn, const int& maDon);
    void xoaDatNuoc(QuanLyDatNuoc& qldn, const int& maDon);
    void xuatDatNuocTheoNgay(QuanLyDatNuoc& qldn, int day, int month, int year);

    // Quản lý giữ xe
    void themDatXe(QuanLyDatXe& qldx);
    DatXe* timkiemDatXe(QuanLyDatXe& qldx, const int& maDon);
    void capnhatGiuXe(QuanLyDatXe& qldx, const int& maDon);
    void xoaGiuXe(QuanLyDatXe& qldx, const int& maDon);
    void xuatGiuXeTheoNgay(QuanLyDatXe& qldx, int day, int month, int year);
};

#endif // NHANVIEN_H
