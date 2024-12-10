#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <iomanip>
#include <memory>
#include "DATE.h"

using namespace std;

class User {
protected:
    string username;  // Ho ten day du
    string password;  // Password (should be securely handled)
    bool isLoggedIn;  // Login status
    //string ten;
    string sdt;
    int gioitinh;//0: nam, 1: nữ
    Date ngaysinh;
    int loaiTaiKhoan;

public:
    // Constructor with member initializer list
    User(const string& username , const string& password ,const string& phonenumber,int gender, const Date& ngsinh,int usertype);  // Default constructor
    User();
    // Virtual Destructor for polymorphism
    virtual ~User();

   
    bool DangNhap(const string& user, const string& pass);
    void DangXuat();
    bool DaDangNhap() const;
    void DangKy(const string &user, const string &pass, const string &phonenumber, int gender, const Date& ngsinh,int loaiTK);
    void DoiMKhau();
    
    // Getter và Setter
    string getUsername() const;
    void setUsername(const string& ten);
    
    string getSDT() const;
    void setSDT(const string sdt);

    string getNgaysinh() const;
    void setNgaysinh(const Date& ngsinh);

    void setGioiTinh(int gioitinh){
        this->gioitinh = gioitinh;
    };
    int getGioiTinh() const{
        return gioitinh;
    };
    const int& getLoaiTK()const{
        return loaiTaiKhoan;
    }
    void setLoaiTK(const int& loaitk){
        loaiTaiKhoan=loaitk;
    }
    static bool ktsdt(const string& phonenumber);  // Kiểm tra số điện thoại hợp lệ
    bool operator==(const User&);
    // virtual void Nhap();
    virtual void xuatthongtin() const;
};

#endif
