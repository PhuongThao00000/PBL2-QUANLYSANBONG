#ifndef DATE_H
#define DATE_H
#include<iostream>
#include<string>
using namespace std;

class Date{
    // static int daytab[13];
    public:
    string ngay;
    Date(string ngay = ""):ngay(ngay){}
    Date(const Date*date){
        ngay = date->ngay;
    }
    ~Date();
    void SetNgay();
    const string& GetNgay() const;
    static bool ValidDate(const string& d);
    bool operator ==(const Date& d) const{
        return ngay==d.ngay;
    };
    void incrementWeek(){
        int day, month, year;

    // Tách chuỗi ngày tháng năm (ngay có định dạng dd/mm/yyyy)
    sscanf(this->ngay.c_str(), "%d/%d/%d", &day, &month, &year);

    // Mảng số ngày trong mỗi tháng (không năm nhuận)
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Kiểm tra năm nhuận và cập nhật ngày tháng 2 nếu cần
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        daysInMonth[1] = 29;
    }

    // Tăng 7 ngày
    day += 7;

    // Xử lý nếu vượt quá số ngày trong tháng
    while (day > daysInMonth[month - 1]) {
        day -= daysInMonth[month - 1];
        month++;

        // Xử lý nếu vượt quá tháng 12
        if (month > 12) {
            month = 1;
            year++;
        }

        // Cập nhật năm nhuận nếu cần
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            daysInMonth[1] = 29;
        } else {
            daysInMonth[1] = 28;
        }
    }

    // Cập nhật chuỗi ngày
    char buffer[11];
    sprintf(buffer, "%02d/%02d/%04d", day, month, year);
    this->ngay = string(buffer);
    }
};
#endif