#include "DATE.h"
#include <iostream>
using namespace std;

Date::Date(string ngay):ngay(ngay){}

Date::Date(const Date*date){
        ngay = date->ngay;
}

Date::~Date(){}

void Date::SetNgay(){
    string newngay;
    int t = 1;
    do{
    cout<<"(dd/mm/yyyy): ";
    cin >> newngay;
    if(ValidDate(newngay)==false){
         cout << "Ngay thang nam khong hop le! Vui long nhap lai!\n";
         t = 0;
    }
    else {t = 1;ngay = newngay;}
    }while(t == 0);
}

bool Date::operator ==(const Date& d) const{
        return ngay==d.ngay;
    }


bool Date::ValidDate(const string& date) {
    if (date.length() != 10 || date[2] != '/' || date[5] != '/') {
        return false;
    }

    int day, month, year;
    try {
        day = stoi(date.substr(0, 2));
        month = stoi(date.substr(3, 2));
        year = stoi(date.substr(6, 4));
    } catch (...) {
        cout << "Dinh dang ngay khong hop le!\n";
        return false;
    }

    if (month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }

    // Kiểm tra số ngày trong tháng
    if (month == 2) { // Tháng 2
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (isLeapYear) {
            if (day > 29) {
                return false;
            }
        } else {
            if (day > 28) {
                return false;
            }
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) { // Các tháng 30 ngày
        if (day > 30) {
            cout << "Thang " << month << " chi co 30 ngays!\n";
            return false;
        }
    }

    return true;
}

const string& Date::GetNgay()const{
    return ngay;
}

void Date::incrementWeek(){
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


