#ifndef QUANLYNV_H
#define QUANLYNV_H
#include "NHANVIEN.h"
#include "NHANVIEN.cpp"
#include "PersonManage.h"

class QuanLyNV: public PersonManage{
    private:
    LINKLIST<NhanVien*>DanhSachNV;
    public:
    void menuCapNhat();
    void them(NhanVien*nv);//them mot khach hang moi
    void xoa(const string& nv_sdt);
    void capnhat(const string& nv_sdt);
    NhanVien* timkiem(const string& nv_sdt);
    void xuat() const;
    void ghiDanhSachRaFile(const string& fileName);
    // void docDanhSachTuFile(const string& fileName);

};
#endif