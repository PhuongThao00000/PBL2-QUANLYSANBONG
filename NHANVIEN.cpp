#include "NhanVien.h"
#include <algorithm>
#include <iostream>

using namespace std;

// Constructor mac dinh
NhanVien::NhanVien() : User() {}

// Constructor voi tham so
NhanVien::NhanVien(const string& username, const string& password, const string& phonenumber, int gender, Date& ngsinh, int loaitk)
    : User(username, password, phonenumber, gender, ngsinh, loaitk) {}

// Destructor
NhanVien::~NhanVien() {}

// Xuat thong tin NhanVien
void NhanVien::xuatthongtin() const {
    User::xuatthongtin();
    cout << "Trang thai hoat dong: " << (DaDangNhap() == false ? "Offline" : "Online") << endl;
}

// Quản lý đặt nước
void NhanVien::themDatNuoc(QuanLyDatNuoc& qldn) {
    if (!isLoggedIn) {
        throw runtime_error("Nhan vien chua dang nhap! Khong the them don ban nuoc.");
    }
    qldn.them(getUsername());
}

DatNuoc* NhanVien::timkiemDatNuoc(QuanLyDatNuoc& qldn, const int& maDon) {
    if (!isLoggedIn) {
        throw runtime_error("Nhan vien chua dang nhap! Khong the thuc hien tim kiem.");
    }
    return qldn.timkiem(maDon);
}

void NhanVien::capnhatDatNuoc(QuanLyDatNuoc& qldn, const int& maDon) {
    if (!isLoggedIn) {
        throw runtime_error("Nhan vien chua dang nhap! Khong the sua don ban nuoc.");
    }
    qldn.capnhat(maDon);
}

void NhanVien::xoaDatNuoc(QuanLyDatNuoc& qldn, const int& maDon) {
    qldn.xoa(maDon);
}

void NhanVien::xuatDatNuocTheoNgay(QuanLyDatNuoc& qldn, int day, int month, int year) {
    if (!isLoggedIn) {
        throw runtime_error("Khach hang chua dang nhap! Khong the xoa san.");
    }
    qldn.xuattheongay(day, month, year);
}

// Quản lý giữ xe
void NhanVien::themDatXe(QuanLyDatXe& qldx) {
    if (!isLoggedIn) {
        throw runtime_error("Nhan vien chua dang nhap! Khong the them don giu xe.");
    }
    qldx.them(getUsername());
}

DatXe* NhanVien::timkiemDatXe(QuanLyDatXe& qldx, const int& maDon) {
    if (!isLoggedIn) {
        throw runtime_error("Nhan vien chua dang nhap! Khong the thuc hien tim kiem.");
    }
    return qldx.timkiem(maDon);
}

void NhanVien::capnhatGiuXe(QuanLyDatXe& qldx, const int& maDon) {
    if (!isLoggedIn) {
        throw runtime_error("Nhan vien chua dang nhap! Khong the sua don giu xe.");
    }
    qldx.capnhat(maDon);
}

void NhanVien::xoaGiuXe(QuanLyDatXe& qldx, const int& maDon) {
    qldx.xoa(maDon);
}

void NhanVien::xuatGiuXeTheoNgay(QuanLyDatXe& qldx, int day, int month, int year) {
    qldx.xuattheongay(day, month, year);
}
