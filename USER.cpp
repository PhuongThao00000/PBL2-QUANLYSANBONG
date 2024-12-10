#include "USER.h"
#include <iostream>
#include <limits>
#include <sstream>
#include <algorithm>
#include <conio.h>

using namespace std;

// Constructor initialization with default values for username and password
User::User(const string& username, const string& password,const string& phonenumber, int gender, const Date& ngsinh,int usertype) 
 :username(username), password(password), isLoggedIn(false),sdt(phonenumber),gioitinh(gender),ngaysinh(ngsinh),loaiTaiKhoan(usertype){
    if (!ktsdt(sdt)) 
        throw invalid_argument("Loi So Dien Thoai!");
    if(gioitinh!=0&&gioitinh!=1)
        throw invalid_argument("Loi Gioi Tinh!");//check dieu kien neu gioi tinh khac 0 hoac 1
    setNgaysinh(ngsinh);
 }

// Default constructor
User::User():username("default_username"),password("default_password"), isLoggedIn(false),sdt(""),gioitinh(0),ngaysinh("01/01/2000"){
}


// Login method (password is now securely handled)
// Ví dụ sử dụng mã hóa bcrypt (cần thư viện bcrypt++)


bool User::DangNhap(const string& user, const string& pass) {
    if (username == user && password==pass) {
        isLoggedIn = true;
        cout << "Dang nhap thanh cong.\n";
        return true;
    }
    cout << "Sai ten dang nhap hoac mat khau.\n";
    return false;
}


// Logout method
void User::DangXuat() {
    isLoggedIn = false;
    cout << "Dang xuat thanh cong.\n";
}

// Check if user is logged in
bool User::DaDangNhap() const {
    return isLoggedIn;
}

// Register method (with input validation)
void User::DangKy(const string &user, const string &pass, const string &phonenumber, int gender, const Date& ngsinh,int loaiTK) {
    if (user.empty() || pass.empty()) {
        cout << "Username and password cannot be empty.\n";
        return;
    }
    if (!ktsdt(phonenumber)) {
        cout << "Invalid phone number.\n";
        return;
    }
    username = user;
    password = pass;
    sdt = phonenumber;
    gioitinh = gender;
    ngaysinh = ngsinh;
    loaiTaiKhoan=loaiTK;
    cout << "Dang ky thanh cong.\n";
}


// Destructor - nothing to clean up for this class
User::~User() {
    // Default destructor
}

// Getter và Setter
string User::getUsername() const {
    return username;
}

void User::setUsername(const string& tenndung) {
    this->username=tenndung;
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

void User::setNgaysinh(const Date& ngsinh){
    this->ngaysinh = ngsinh;
}
//getGioitinh,getQuoctinh
// void User::Nhap(){
//     cout << "Nhap ten tai khoan(ho ten): "; 
//     getline(cin, username);  
//     cout << "Nhap so dien thoai: ";
//     cin >> sdt;
//     cout << "Nhap ngay thang nam sinh: ";
//     ngaysinh.SetNgay();
//     cout << "Nhap gioi tinh: ";
//     cin >> gioitinh; 
// }
bool User::ktsdt(const string& phonenumber) {
    return phonenumber.length() == 10 && phonenumber[0] == '0' && all_of(phonenumber.begin(), phonenumber.end(), ::isdigit);
}

void User::DoiMKhau() {
    string oldpass;
    while (true) {
        cout << "Nhập mật khẩu cũ: ";
        cin >> oldpass;
        if (oldpass == password) break;   
        cout << "Mật khẩu chưa đúng. Vui lòng nhập lại!\n";    
    }

    string newpass;
    while (true) {
        cout << "Nhập mật khẩu mới (KHÔNG chứa dấu cách): ";
        cin >> newpass;
        string againpass;
        cout << "Nhập lại mật khẩu: ";
        cin >> againpass;

        if (newpass == againpass) {
            password = newpass;
            cout << "Đổi mật khẩu thành công!\n";
            break;
        } else {
            cout << "Hai mật khẩu không khớp. Vui lòng nhập lại!\n";
        }
    }
}


// Phuong thuc Xuat Thong Tin
void User::xuatthongtin() const {
    cout << "Số điện thoại: "<<sdt<<endl;
    cout <<"Họ và tên: "<< username<<endl;
    cout << "Giới tính: "<<gioitinh<<endl;
    cout<<"Ngày sinh: "<<ngaysinh.GetNgay()<<endl;
    cout <<"Loại tài khoản: "<< loaiTaiKhoan<<endl;
}

bool User::operator==(const User& nguoidung){
    return (sdt==nguoidung.sdt);
}
