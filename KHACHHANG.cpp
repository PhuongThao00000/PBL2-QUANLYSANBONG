#include "KhachHang.h"
#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;

// Constructor mac dinh
KhachHang::KhachHang() : User(), rankMember(4) {}

// Constructor voi tham so
KhachHang::KhachHang(const string& username, const string& password, const string& phonenumber, int gender, Date& ngsinh, int rankmember, int loaitaikhoan)
    : User(username, password, phonenumber, gender, ngsinh, loaitaikhoan), rankMember(rankmember) {}

// Constructor copy
KhachHang::KhachHang(const KhachHang* kh) {
    if (this != kh) {
        username = kh->username;
        password = kh->password;
        isLoggedIn = kh->isLoggedIn;
        sdt = kh->sdt;
        gioitinh = kh->gioitinh;
        ngaysinh = kh->ngaysinh;
        rankMember = kh->rankMember;
    }
}

// Tim kiem don dat san theo so dien thoai
DatSan* KhachHang::timkiem(QuanLyDatSan& qlds) {
    if (!isLoggedIn) {
        throw runtime_error("Khach hang chua dang nhap! Khong the thuc hien tim kiem.");
    }
    return qlds.timkiem(getSDT());
}

// Them don dat san le
void KhachHang::themDonDatsanLe(QuanLyDatSan& qlds) {
    if (!isLoggedIn) {
        throw runtime_error("Khach hang chua dang nhap! Khong the them don dat san dinh ky.");
    }
    qlds.themLe(getSDT());
}

// Sua don dat san
void KhachHang::suaDonDatsan(QuanLyDatSan& qlds) {
    if (!isLoggedIn) {
        throw runtime_error("Khach hang chua dang nhap! Khong the sua don dat san.");
    }
    qlds.capnhat(getSDT());
}

// Xuat don dat san
void KhachHang::xuatDonDatsan(QuanLyDatSan& qlds) {
    if (!isLoggedIn) {
        throw runtime_error("Khach hang chua dang nhap! Khong the xuat thong tin don dat san.");
    }
    qlds.xuattheosdt(getSDT());
}

// Xoa san theo so dien thoai
void KhachHang::xoaSan(QuanLyDatSan& qlds) {
    if (!isLoggedIn) {
        throw runtime_error("Khach hang chua dang nhap! Khong the xoa san.");
    }
    qlds.xoa(getSDT());
}

// Setter cho rank
void KhachHang::setRank(int rank) {
    if (rank != 1 && rank != 2 && rank != 3 && rank != 4)
        throw invalid_argument("Hang thanh vien khong hop le!");
    rankMember = rank;
}

// Getter cho rank
const int& KhachHang::getRank() {
    return rankMember;
}

// Xuat thong tin KhachHang
void KhachHang::xuatthongtin() const {
    User::xuatthongtin();
    cout << "Hang thanh vien(4:Thanh Vien, 3:Dong, 2:Bac, 1:Vang): ";
    if (rankMember == 0) cout << "Chua co hang\n";
    else { cout << rankMember; }
}
