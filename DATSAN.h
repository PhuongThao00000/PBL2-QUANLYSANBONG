#ifndef DATSAN_H
#define DATSAN_H
#include <conio.h>
#include <iomanip>
#include <iostream>
#include <string>
#include "QuanLyDichVu.h"
using namespace std;

class DatSan {
    string sdtKH;  // Khoa ngoại
    int status=0;    // 0: chưa thanh toán, 1: đã thanh toán
    Date ngaysan;
    Date ngayend;
    LINKLIST<pair<string, int>> SanVaGio;  // Danh sách sân và chỉ số giờ
    int totalprice;
    const int giasan[4] = {270, 300, 290, 350};  // Hằng tĩnh
    static const string giosan[24];
    bool LeOrDinhKy;  // 0: Lẻ, 1: Định kỳ
    string paidtime="00:00";
    Date paidday=0;

public:
    DatSan(string customersdt = "", string ngaydat = "", string sandat = "", int giodat = -1, 
           string ngaykt = "",  bool loaikhach = 0,int trangthaitt = 0 ,int totalp = 0, string giott="00:00",string ngaytt="00/00/0000");
    DatSan(const DatSan* s);
    ~DatSan();

    void setSanDat(string tensan);
    void setGioDat(int giodat);
    void setTrangThaiTT(int trangthai);
    void setNgayDat(const string& ngaydat);
    void setNgayEnd(const string& ngaykt);
    void setTongTien();

    void xuat();
    void themSanVaGio(pair<string, int>& sanvagio);
    bool isKhachLe() const { return !LeOrDinhKy; }
    bool isKhachDinhKy() const { return LeOrDinhKy; }
    const string getSDTKH()const{
        return sdtKH;
    }
    const bool getDangKH();
    const int getTongTien() { return totalprice; }
    const string getSanDatODau() const;
    const int getGioDatODau() const;
    const string getSanDatOCuoi() const;
    const int getGioDatOCuoi() const;
    DatSan& operator=(DatSan&);
    bool operator==(DatSan& other){
        return sdtKH==other.sdtKH&&ngaysan==other.ngaysan; 
    }
    const int getGia(const string& tensan, int giodat);
    const int& getTrangThaiTT();
    const string getNgayDat() const;
    const string getNgayEnd() const;
    const string& getPaidDay()const;
    const string& getPaidTime()const; 
    static const string getGioDat(const int giosan);

    LINKLIST<pair<string, int>>& getSanVaGio();

    void setDangKH(bool leOrdinhky);
};
    bool operator<=(const string& date1, const string& date2) {
        // Kiểm tra độ dài để đảm bảo định dạng "dd/mm/yyyy"
        if (date1.length() != 10 || date2.length() != 10) {
            throw invalid_argument("Ngày phải ở định dạng dd/mm/yyyy");
        }

        // Tách ngày, tháng, năm từ chuỗi
        int day1 = stoi(date1.substr(0, 2));
        int month1 = stoi(date1.substr(3, 2));
        int year1 = stoi(date1.substr(6, 4));

        int day2 = stoi(date2.substr(0, 2));
        int month2 = stoi(date2.substr(3, 2));
        int year2 = stoi(date2.substr(6, 4));

        // So sánh lần lượt năm, tháng, ngày
        if (year1 < year2) return true;
        if (year1 > year2) return false;

        if (month1 < month2) return true;
        if (month1 > month2) return false;

        return day1 <= day2;
    }


#endif