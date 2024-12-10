#ifndef KHACHHANG_H
#define KHACHHANG_H

#include "USER.h"
#include "QuanLyDatSan.h"
#include <iostream>
#include <string>

using namespace std;

class KhachHang : public User {
private:
    int rankMember = 0; // 4: Thanh Vien, 3: Dong, 2: Bac, 1: Vang

public:
    // Constructor
    KhachHang();  // Constructor mac dinh
    KhachHang(const string& username, const string& password, const string& phonenumber, int gender, Date& ngsinh, int rankmember = 0, int loaiTK = 0); 
    KhachHang(const KhachHang *kh);  // Constructor copy
    ~KhachHang();  // Destructor

    // Getter, Setter cho rankMember
    void setRank(int rank);
    const int& getRank();

    // Xuat thong tin KhachHang
    void xuatthongtin() const;

    // Phuong thuc them, sua, xoa, tim kiem don dat san
    void themDonDatsanLe(QuanLyDatSan& qlds);
    void xoaSan(QuanLyDatSan& qlds);
    DatSan* timkiem(QuanLyDatSan& qlds);
    void suaDonDatsan(QuanLyDatSan& qlds);
    void xuatDonDatsan(QuanLyDatSan& qlds);
};

#endif // KHACHHANG_H
