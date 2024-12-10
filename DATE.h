#ifndef DATE_H
#define DATE_H
#include<iostream>
#include<string>
using namespace std;

class Date{
    public:
    string ngay;
    Date(string ngay = "");
    Date(const Date*date);
    ~Date();
    void SetNgay();
    const string& GetNgay() const;
    static bool ValidDate(const string& d);
    bool operator ==(const Date& d) const;
    void incrementWeek();
};
#endif
