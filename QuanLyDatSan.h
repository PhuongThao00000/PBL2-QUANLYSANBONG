#ifndef QUANLYDATSAN_H
#define QUANLYDATSAN_H

#include <iostream>
#include <string>
#include "DATSAN.h"
#include "LINKLIST.h"
#include "Date.h"

class QuanLyDatSan {
private:
    LINKLIST<DatSan*> DanhSachDatSan;  // Danh sách đơn đặt sân
    const string tensan[5] = {"51", "52", "53", "71", "72"};
    const string giosan[24] = {
        "5:00-5:30", "5:30-6:00", "6:00-6:30", "6:30-7:00", "7:00-7:30", "7:30-8:00",
        "8:00-8:30", "8:30-9:00", "9:00-9:30", "9:30-10:00", "15:00-15:30", "15:30-16:00",
        "16:00-16:30", "16:30-17:00", "17:00-17:30", "17:30-18:00", "18:00-18:30", "18:30-19:00",
        "19:00-19:30", "19:30-20:00", "20:00-20:30", "20:30-21:00", "21:00-21:30", "21:30-22:00"
    };
    int doanhthuTheoNgay;

public:
    QuanLyDatSan();
    ~QuanLyDatSan();

    // Các phương thức quản lý đơn đặt sân
    void menuGiuXe();
    void menuCapNhat();
    void themLe(string customersdt);
    bool IsEmpty(const Date& ngaydat, const string& tensan, const int& giosan);
    void themDinhKy(string customersdt);
    void TrangThaiSanTheoNgay(const Date& ngayDat);
    void xoa(string customersdt);
    void capnhat(string customersdt);
    void capnhatTrangThaiTT(const string& sdtKH, const int& status);
    DatSan* timkiem(string customersdt);
    void xuat();
    void xuattheongay(int day, int month, int year);
    void xuattheosdt(string customersdt);
    static void bangGia();
    static void setTenSan(string& sandat);
    static void setGioSan(int& giodat);

    // Thống kê doanh thu
    const int& getDoanhThuTheoNgay(int day, int month, int year);
    const int& getDoanhThuTheoQuy(int quy, int year);
    const int& getChiPhiNhapTheoNgay(int day, int month, int year);
    const int& getChiPhiNhapTheoQuy(int quy, int year);
};

#endif // QUANLYDATSAN_H
