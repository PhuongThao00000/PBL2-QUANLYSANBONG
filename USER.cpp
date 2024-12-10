#include "User.h"
#include <iostream>
#include <limits>
#include <sstream>
#include <algorithm>
#include <conio.h>

using namespace std;

// Constructor voi list khoi tao
User::User(const string& username, const string& password, const string& phonenumber, int gender, const Date& ngsinh, int usertype) 
    : username(username), password(password), isLoggedIn(false), sdt(phonenumber), gioitinh(gender), ngaysinh(ngsinh), loaiTaiKhoan(usertype) {
    if (!ktsdt(sdt)) 
        throw invalid_argument("Loi So Dien Thoai!");
    if(gioitinh != 0 && gioitinh != 1)
        throw invalid_argument("Loi Gioi Tinh!"); // Check gioi tinh neu khac 0 hoac 1
    setNgaysinh(ngsinh);
}

// Constructor mac dinh
User::User() : username("default_username"), password("default_password"), isLoggedIn(false), sdt(""), gioitinh(0), ngaysinh("01/01/2000") {}

// Destructor
User::~User() {
    // Destructor mac dinh
}

// Phuong thuc dang nhap
bool User::DangNhap(const string& user, const string& pass) {
    if (username == user && password == pass) {
        isLoggedIn = true;
        cout << "Dang nhap thanh cong.\n";
        return true;
    }
    cout << "Sai ten dang nhap hoac mat khau.\n";
    return false;
}

// Phuong thuc dang xuat
void User::DangXuat() {
    isLoggedIn = false;
    cout << "Dang xuat thanh cong.\n";
}

// Kiem tra trang thai dang nhap
bool User::DaDangNhap() const {
    return isLoggedIn;
}

// Phuong thuc dang ky
void User::DangKy(const string& user, const string& pass, const string& phonenumber, int gender, const Date& ngsinh, int loaiTK) {
    if (user.empty() || pass.empty()) {
        cout << "Ten dang nhap va mat khau khong duoc de trong!\n";
        return;
    }
    if (!ktsdt(phonenumber)) {
        cout << "Loi so dien thoai.\n";
        return;
    }
    username = user;
    password = pass;
    sdt = phonenumber;
    gioitinh = gender;
    ngaysinh = ngsinh;
    loaiTaiKhoan = loaiTK;
    cout << "Dang ky thanh cong.\n";
}

// Kiem tra so dien thoai hop le
bool User::ktsdt(const string& phonenumber) {
    return phonenumber.length() == 10 && phonenumber[0] == '0' && all_of(phonenumber.begin(), phonenumber.end(), ::isdigit);
}

// Phuong thuc doi mat khau
void User::DoiMKhau() {
    string oldpass;
    while (true) {
        cout << "Nhap mat khau cu: ";
        cin >> oldpass;
        if (oldpass == password) break;   
        cout << "Mat khau chua dung. Vui long nhap lai!\n";    
    }

    string newpass;
    while (true) {
        cout << "Nhap mat khau moi (KHONG chua dau cach): ";
        cin >> newpass;
        string againpass;
        cout << "Nhap lai mat khau: ";
        cin >> againpass;

        if (newpass == againpass) {
            password = newpass;
            cout << "Doi mat khau thanh cong!\n";
            break;
        } else {
            cout << "Hai mat khau khong khop. Vui long nhap lai!\n";
        }
    }
}

// Phuong thuc xuat thong tin
void User::xuatthongtin() const {
    cout << "So dien thoai: " << sdt << endl;
    cout << "Ho va ten: " << username << endl;
    cout << "Gioi tinh: " << (gioitinh == 0 ? "Nam" : "Nu") << endl;
    cout << "Ngay sinh: " << ngaysinh.GetNgay() << endl;
    cout << "Loai tai khoan: " << loaiTaiKhoan << endl;
}

// Toan tu so sanh
bool User::operator==(const User& nguoidung) {
    return sdt == nguoidung.sdt;
}

// Getter va Setter cho cac thuoc tinh
string User::getUsername() const {
    return username;
}

void User::setUsername(const string& ten) {
    this->username = ten;
}

string User::getSDT() const {
    return sdt;
}

void User::setSDT(const string sdt) {
    this->sdt = sdt;
}

string User::getNgaysinh() const {
    return ngaysinh.GetNgay();
}

void User::setNgaysinh(const Date& ngsinh) {
    this->ngaysinh = ngsinh;
}

void User::setGioiTinh(int gioitinh) {
    this->gioitinh = gioitinh;
}

int User::getGioiTinh() const {
    return gioitinh;
}

const int& User::getLoaiTK() const {
    return loaiTaiKhoan;
}

void User::setLoaiTK(const int& loaitk) {
    loaiTaiKhoan = loaitk;
}
