#include "DATE.h"
#include <iostream>
using namespace std;

Date::~Date(){}
void Date::SetNgay(){
    string newngay;
    int t = 1;
    do{
    cout<<"(dd/mm/yyyy): ";
    cin >> newngay;
    if(ValidDate(newngay)==false){
         cout << "Ngày tháng năm không hợp lệ vui lòng nhập lại!\n";
         t = 0;
    }
    else {t = 1;ngay = newngay;}
    }while(t == 0);
}


// bool Date::ValidDate(const string& date){
//     if (date.length() != 10 || date[2] != '/' || date[5] != '/'){ 
//         return false;
//     }
//     int day = stoi(date.substr(0, 2));
//     int month = stoi(date.substr(3, 2));
//     int year = stoi(date.substr(6, 4));

//     if (month < 1 || month > 12 || day < 1 || day > 31){
//         return false;
//     }
//     // Kiểm tra số ngày trong các tháng
//     if (month == 2) { // Tháng 2
//         if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) { // Năm nhuận
//             if (day > 29) return false;
//         } else {
//             if (day > 28) return false;
//         }
//     } else if (month == 4 || month == 6 || month == 9 || month == 11) { // Các tháng 30 ngày
//         if (day > 30) return false;
//     }
//     return true;
// }
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
        cout << "Định dạng ngày không hợp lệ!\n";
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
            cout << "Tháng " << month << " chỉ có 30 ngày!\n";
            return false;
        }
    }

    return true;
}

const string& Date::GetNgay()const{
    return ngay;
}


