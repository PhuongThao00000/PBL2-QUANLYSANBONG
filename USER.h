#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include "DATE.h"

using namespace std;

class User {
protected:
    string username;  // Ho ten day du
    string password;  // Mat khau
    bool isLoggedIn;  // Trang thai dang nhap
    string sdt;       // So dien thoai
    int gioitinh;     // Gioi tinh (0: nam, 1: nu)
    Date ngaysinh;    // Ngay sinh
    int loaiTaiKhoan; // Loai tai khoan

public:
    // Constructor voi list khoi tao
    User(const string& username, const string& password, const string& phonenumber, int gender, const Date& ngsinh, int usertype);
    User();  // Constructor mac dinh

    // Virtual Destructor de ho tro polymorphism
    virtual ~User();

    // Cac phuong thuc
    bool DangNhap(const string& user, const string& pass);
    void DangXuat();
    bool DaDangNhap() const;
    void DangKy(const string& user, const string& pass, const string& phonenumber, int gender, const Date& ngsinh, int loaiTK);
    void DoiMKhau();
    
    // Getter va Setter
    string getUsername() const;
    void setUsername(const string& ten);

    string getSDT() const;
    void setSDT(const string sdt);

    string getNgaysinh() const;
    void setNgaysinh(const Date& ngsinh);

    void setGioiTinh(int gioitinh);
    int getGioiTinh() const;

    const int& getLoaiTK() const;
    void setLoaiTK(const int& loaitk);

    static bool ktsdt(const string& phonenumber);  // Kiem tra so dien thoai hop le
    bool operator==(const User& nguoidung);
    
    // Phuong thuc xuat thong tin
    virtual void xuatthongtin() const;
};

#endif // USER_H
