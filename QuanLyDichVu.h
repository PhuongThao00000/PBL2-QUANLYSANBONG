#ifndef QUANLYDV_H
#define QUANLYDV_H
#include "LINKLIST.h"
#include "LINKLIST.cpp"
#include "DATE.h"
#include "DATE.cpp"
// #include "HOADON.h"
// #include "HOADON.cpp"

class QuanLyDichVu {
    protected:
    int doanhthuTheoNgay;
    int chiphinhapTheoNgay;
    public:
    QuanLyDichVu():doanhthuTheoNgay(0),chiphinhapTheoNgay(0){};
    virtual ~QuanLyDichVu(){};
    virtual void xuat()=0;
    virtual void xoa(const int&maDon)=0;
    virtual void capnhat(const int&maDon)=0;
    // Xuất các đơn theo ngày bán
    virtual void xuattheongay(int day, int month, int year)=0;
    virtual const int& getChiPhiNhapTheoNgay(int day, int month, int year)=0;
    virtual const int& getChiPhiNhapTheoQuy(int quy, int year)=0;
    virtual const int& getDoanhThuTheoNgay(int day, int month, int year)=0;
    virtual const int& getDoanhThuTheoQuy(int quy, int year)=0;
};
#endif