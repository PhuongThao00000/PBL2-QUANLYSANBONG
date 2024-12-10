#ifndef QUANLYDATXE_H
#define QUANLYDATXE_H

#include <iostream>
#include <string>
#include "DATXE.h"
#include "DATXE.cpp"
#include "QuanLyDichVu.h"

using namespace std;

class QuanLyDatXe : public QuanLyDichVu {
private:
    LINKLIST<DatXe*> DanhSachdonDatXe;  // Danh sách đơn đặt xe
    int tongSoVe;
public:
    // Constructor và Destructor
    QuanLyDatXe() : QuanLyDichVu(),tongSoVe(0) {}; // Khởi tạo tiền vốn bằng 0
    ~QuanLyDatXe() {}

    void menuGiuXe();
    void menuCapNhat();
    // Thêm đơn đặt xe
    void them(string tennhanvien);

    // Xóa đơn đặt xe theo ngày bán và giờ bán
    void xoa(const int&maDon);

    // Cập nhật đơn đặt xe theo ngày bán và giờ bán
    void capnhat(const int&maDon);

    // Tìm kiếm đơn đặt xe theo ngày bán và giờ bán
    DatXe* timkiem(const int&maDon);

    // Xuất tất cả các đơn đặt xe
    void xuat();
 // Xuất các đơn đặt xe theo ngày bán
    const int& getTongSoVe(){
        return tongSoVe;
    }
    void xuattheongay(int day, int month, int year);

    const int& getChiPhiNhapTheoNgay(int day, int month, int year);
    const int& getChiPhiNhapTheoQuy(int quy, int year);
    // Thống kê doanh thu theo ngày
    const int& getDoanhThuTheoNgay(int day, int month, int year);
    const int& getDoanhThuTheoQuy(int quy, int year);

};

#endif // QUANLYDATXE_H
