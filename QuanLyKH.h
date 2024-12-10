#ifndef QUANLYKH_H
#define QUANLYKH_H
#include "PersonManage.h"
#include "KHACHHANG.h"

class QuanLyKH: public PersonManage{
    private:
    LINKLIST<KhachHang*>DanhSachKH;
    public:
    void them(KhachHang*kh);//them mot khach hang moi
    void xoa(const string& customersdt);
    void capnhat(const string& customersdt);
    KhachHang* timkiem(const string& customerstd);
    void xuat()const;
    void ghiDanhSachRaFile(const string& fileName);
    void docDanhSachTuFile(const string& fileName);

};
#endif