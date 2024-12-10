#ifndef QUANLYDS_H
#define QUANLYDS_H

#include "DATSAN.h"
#include "DATSAN.cpp"
class QuanLyDatSan{
    private:
    LINKLIST<DatSan*>DanhSachDatSan;
    const string tensan[5]={"51","52","53","71","72"};
    const string giosan[24]={"5:00-5:30", "5:30-6:00", "6:00-6:30", "6:30-7:00", "7:00-7:30","7:30-8:00",
        "8:00-8:30", "8:30-9:00", "9:00-9:30", "9:30-10:00","15:00-15:30", "15:30-16:00","16:00-16:30", "16:30-17:00", "17:00-17:30", "17:30-18:00", "18:00-18:30",
        "18:30-19:00", "19:00-19:30", "19:30-20:00", "20:00-20:30", "20:30-21:00",
        "21:00-21:30", "21:30-22:00"};
        int doanhthuTheoNgay;
        
    public:
    QuanLyDatSan():doanhthuTheoNgay(0){}

    int getDoanhThuTheoNgay(int day,int month,int year);

    void themLe(string customersdt);

    DatSan* findDuplicate(DatSan*ds);

    bool IsEmpty(const Date& ngaydat,const string& tensan, const int& giosan);

    void themDinhKy(string customersdt);

    void TrangThaiSanTheoNgay(const Date& ngayDat);

    void xoa(string customersdt);

    void capnhat(string customersdt);

    void capnhatTrangThaiTT(const string& sdtKH, const int& status);

    DatSan* timkiem(string customerstd);

    void xuat();

    // Xuất các đơn đặt xe theo ngày bán
    void xuattheongay(int day, int month, int year) {
        auto x = DanhSachDatSan.begin();
        while (x != nullptr) {
            string ngay = x->data->getNgayDat();
            // So sánh ngày tháng năm
            if ((day == 0 || stoi(ngay.substr(0, 2)) == day) &&
                (month == 0 || stoi(ngay.substr(3, 2)) == month) &&
                (year == 0 || stoi(ngay.substr(6, 4)) == year)) {
                x->data->xuat();
            }
            x = x->next;
        }
    }


    void xuattheosdt(string customersdt);

    static void bangGia();

    void menuCapNhat();
    // static void XuatTenSan();
    // static void XuatKhungGio();
    // static void XuatGiaSan();
    static void setTenSan(string& sandat);

    static void setGioSan(int& giodat);
};

#endif
