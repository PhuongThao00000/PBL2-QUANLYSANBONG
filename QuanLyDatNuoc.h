#ifndef QUANLYDN_H
#define QUANLYDN_H

// #include "DATNUOC.h"

#include "QuanLyDichVu.h"
#include "DATNUOC.h"
#include "DATNUOC.cpp"


class QuanLyDatNuoc: public QuanLyDichVu{
    LINKLIST<DatNuoc*>DanhSachdonDatNuoc;
    int waterquantityinWarehouse[4]={100,100,100,100};//cho so luong 4 loai nuoc ban du bang khong
    //const string tennuoc[4]= {"Khoang Ngot","Khoang lat","Revive","Suoi"}; // theo so thu tu trong menu de in ra ten nuoc
    //int gianuoc[4]= {10,10,13,8}; //gia nuoc co the thay doi
    static int gianhapvao[4];//
    public:
    QuanLyDatNuoc():QuanLyDichVu(){};
    void addWaterToWarehouse();//Nhap nuoc vao kho va dien vao gia nhap de cuoi ngay thong ke tien loi
    void menuKho();
    void menuNuoc();//in ra menu nuoc de khach chon//hienn thi ca so luong con lai cua loai nuoc do trong kho
    void them(string nhanvienname);
    void xoa(const int &maDon);
    void capnhat(const int &maDon);
    void xuattheongay(int day, int month, int year);
    DatNuoc* timkiem(const int &maDon);
    void xuat();
    // void thongKeTheoNgay(string ngaythongke);
    void menuCapNhat();
    //thống kê doanh thu
    const int& getDoanhThuTheoNgay(int day, int month, int year);
    const int& getDoanhThuTheoQuy(int quy, int year);
    const int& getChiPhiNhapTheoNgay(int day, int month, int year);
    const int& getChiPhiNhapTheoQuy(int quy, int year);
};
#endif