#ifndef QUANLYNDUNG_H
#define QUANLYNDUNG_H

#include "KHACHHANG.h"
#include "QUANLY.h"
#include "LINKLIST.h"
#include "USER.h"
#include <iostream>
#include <string>

using namespace std;

class QuanLyNDung {
private:
    LINKLIST<User*> DanhSachNDung;  // Danh sách người dùng
    User* currentLoggedInUser;      // Con trỏ lưu tài khoản đang đăng nhập

public:
    QuanLyNDung() : currentLoggedInUser(nullptr) {};

    // Phương thức đăng ký tài khoản từ bàn phím
    bool DangKyTaiKhoan(const string &username, const string &password, const string& phonenumber, int gioitinh, Date& ngsinh, int loaiTaiKhoan);

    // Phương thức đăng ký tài khoản từ file
    void DangKyTuFile(const string& fileName);
    
    // Phương thức ghi danh sách người dùng ra file
    void ghiDanhSachRaFile(const string& fileName);

    // Phương thức đăng nhập tài khoản
    User* DangNhapTaiKhoan(const string& username, const string &password);

    // Phương thức đăng xuất tài khoản
    void DangXuatTaiKhoan();

    // Hiển thị tất cả tài khoản
    void HienThiDanhSach() const;

    // Tìm kiếm tài khoản theo số điện thoại
    User* TimKiemTaiKhoan(const string& phonenumber);

    // Hàm loại bỏ dấu cách ở đầu và cuối chuỗi
    static string Trim(const string& input);

    // Hàm nhập tên người dùng (không cho phép dấu cách thừa)
    static void SetTenNguoiDung(string& tenndung);

    // Hàm kiểm tra số điện thoại hợp lệ
    static bool IsValidPhoneNumber(const string& sdt);

    // Hàm nhập số điện thoại
    static void SetSoDienThoai(string& sdt);

    // Hàm nhập giới tính
    static void SetGioiTinh(int& gender);

    // Hàm nhập mật khẩu
    static void SetPassWord(string& password);
};

#endif // QUANLYNDUNG_H
