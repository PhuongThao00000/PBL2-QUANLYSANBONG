#ifndef QUANLYDATXE_H
#define QUANLYDATXE_H

#include <iostream>
#include <string>
#include "DATXE.h"
#include "QuanLyDichVu.h"
#include "LINKLIST.h"  // Đảm bảo bạn đã định nghĩa lớp LINKLIST trong dự án

using namespace std;

class QuanLyDatXe : public QuanLyDichVu {
private:
    LINKLIST<DatXe*> DanhSachdonDatXe;  // Danh sách đơn đặt xe
    int tongSoVe;  // Tổng số vé xe đã bán

public:
    // Constructor và Destructor
    QuanLyDatXe(); 
    ~QuanLyDatXe();

    // Phương thức menu
    void menuGiuXe();
    void menuCapNhat();

    // Các phương thức quản lý đơn đặt xe
    void them(string tennhanvien);
    void xoa(const int& maDon);
    void capnhat(const int& maDon);
    DatXe* timkiem(const int& maDon);
    void xuat();
    void xuattheongay(int day, int month, int year);

    // Các phương thức thống kê doanh thu và chi phí
    const int& getTongSoVe();
    const int& getChiPhiNhapTheoNgay(int day, int month, int year);
    const int& getChiPhiNhapTheoQuy(int quy, int year);
    const int& getDoanhThuTheoNgay(int day, int month, int year);
    const int& getDoanhThuTheoQuy(int quy, int year);
};

#endif // QUANLYDATXE_H
