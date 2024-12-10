#ifndef QuanLyNDung_H
#define QuanLyNDung_H

#include "KHACHHANG.h"
#include "KHACHHANG.cpp"



#include "QUANLY.h"
#include "QUANLY.cpp"

class QuanLyNDung{
    private:
    LINKLIST<User*>DanhSachNDung;
    User* currentLoggedInUser; // Con trỏ lưu tài khoản đang đăng nhập

    public:
    QuanLyNDung():currentLoggedInUser(nullptr){};

    //Phuong thuc dang ky từ bàn phím
    bool DangKyTaiKhoan(const string &username, const string &password, const string& phonenumber, int gioitinh, Date& ngsinh, int loaiTaiKhoan);
    //Phương thức đăng ký từ file
    void DangKyTuFile(const string& fileName);
    void ghiDanhSachRaFile(const string& fileName);
    //Phuong thuc dang nhap
    User* DangNhapTaiKhoan(const string& username, const string &password);

    void DangXuatTaiKhoan();
    //Hien thi tat ca tai khoan
    void HienThiDanhSach()const;
//Tim kiem tai khoan
    User* TimKiemTaiKhoan(const string& phonenumber);//dung hash table  

    // Hàm loại bỏ dấu cách ở đầu và cuối chuỗi
    static string Trim(const string& input) {
            size_t start = input.find_first_not_of(" ");
            size_t end = input.find_last_not_of(" ");
            return (start == string::npos) ? "" : input.substr(start, end - start + 1);
        };
// Hàm nhập tên người dùng (không cho phép dấu cách thừa)
    static void  SetTenNguoiDung(string& tenndung){
        do {
            cout << "Username (ho va ten cua ban): ";
            getline(cin, tenndung);
            tenndung = Trim(tenndung);
            if (tenndung.empty()) {
                cout << "Ten nguoi dung khong duoc de trong. Vui long nhap lai.\n";
            }
        } while (tenndung.empty());
    };
    // Hàm kiểm tra số điện thoại hợp lệ
    static bool IsValidPhoneNumber(const string& sdt) {
        if (sdt.length() < 10 || sdt.length() > 11) return false; // Số điện thoại thường dài 10-11 chữ số
        for (char c : sdt) {
            if (!isdigit(c)) return false; // Chỉ chứa ký tự số
        }
        return true;
    };

// Hàm nhập số điện thoại
    static void SetSoDienThoai(string& sdt) {
        do {
            cout << "Phone number: ";
            cin >> sdt;
            if (!IsValidPhoneNumber(sdt)) {
                cout << "So dien thoai khong hop le. Vui long nhap lai (chi chua 10-11 so).\n";
            }
        } while (!IsValidPhoneNumber(sdt));
    };
    static void SetGioiTinh(int& gender){
        do{
            cout << "Gender (0: Male, 1: Female): ";
            cin >> gender;
            if(gender!=0&&gender!=1){
                cout << "Giới tính không hợp lệ. Vui lòng nhập lại\n";
            }
        }while(gender!=0&&gender!=1);
    }
    static void SetPassWord(string& password){
        string pass, againpass;
        do{
        cout << "Password(KHÔNG chứa dấu cách) : ";
        cin >> pass;
        cout << "Nhập lại password: ";
        cin >> againpass;
        }while(againpass!=pass);
        pass=againpass;
        password=pass;
    }
};
#endif