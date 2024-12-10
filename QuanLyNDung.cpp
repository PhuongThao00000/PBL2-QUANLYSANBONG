#include "QuanLyNDung.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

bool QuanLyNDung::DangKyTaiKhoan(const string &username, const string &password, const string &phonenumber, int gender, Date& ngsinh, int loaiTaiKhoan) {
    try {
        // Kiểm tra tài khoản đã tồn tại
        if (TimKiemTaiKhoan(phonenumber) != nullptr) {
            throw invalid_argument("Tai khoan da ton tai!");
        }
        else{

        User* newUser = nullptr;
        
        // Kiểm tra loại tài khoản hợp lệ
        switch (loaiTaiKhoan) {
            case 0: // Khach hang
                newUser = new KhachHang(username, password, phonenumber, gender, ngsinh,loaiTaiKhoan);
                break;
            case 1: // Nhan vien
                newUser = new NhanVien(username, password, phonenumber, gender, ngsinh);
                break;
            case 2: // Quan Ly
                newUser = new QuanLi(username, password, phonenumber, gender, ngsinh);
                break;
            default:
                throw invalid_argument("Loai tai khoan khong hop le!");
        }

        // Thêm tài khoản vào danh sách người dùng
        DanhSachNDung.addFirst(newUser);

        cout << "Đăng ký thành công!\n";
        return true;
        }

    } catch (const invalid_argument& e) {
        // Xử lý ngoại lệ và in thông báo lỗi
        cout << "Loi: " << e.what() << endl;
        return false;
    } catch (const exception& e) {
        // Xử lý các ngoại lệ khác nếu cần
        cout << "Loi ngoai le: " << e.what() << endl;
        return false;
    }
}

void QuanLyNDung::DangKyTuFile(const string& fileName){
    ifstream file;
    try {
        file.open(fileName);
        if(!file.is_open()){
            throw runtime_error("Không thể mở file: "+fileName);
        }
        string line;
        int count = 0; // Số tài khoản đăng ký thành công
        int lineNumber = 0; // Dòng hiện tại trong file
        while(getline(file,line)){
            lineNumber++;
            try {
                stringstream ss(line);
                string username,password,phonenumber,genderStr,dobStr,accountTypeStr;
                if(!(getline(ss, username, ',') &&
                      getline(ss, password, ',') &&
                      getline(ss, phonenumber, ',') &&
                      getline(ss, genderStr, ',') &&
                      getline(ss, dobStr, ',') &&
                      getline(ss, accountTypeStr) )){
                        throw invalid_argument("Dòng không hợp lệ");
                }
                // Loại bỏ khoảng trắng dư thừa
                username = Trim(username);
                password = Trim(password);
                phonenumber = Trim(phonenumber);
                genderStr = Trim(genderStr);
                dobStr = Trim(dobStr);
                accountTypeStr = Trim(accountTypeStr);

                // Chuyển đổi dữ liệu
                int gender = stoi(genderStr);
                int accountType = stoi(accountTypeStr); // Loại tài khoản
                Date birthDate(dobStr);                // Giả sử Date có constructor nhận chuỗi

                // Đăng ký tài khoản
                if (DangKyTaiKhoan(username, password, phonenumber, gender, birthDate,accountType)) {
                    count++;
                } else {
                    throw runtime_error("Dang ky tai khoan that bai: " + username);
                }
            } catch (const exception& e) {
                // Xử lý lỗi cho từng dòng cụ thể
                cout << "Loi tai dong " << lineNumber << ": " << e.what() << endl;
            }
        }
        file.close();
        cout << "Da dang ky thanh cong " << count << " tai khoan tu file." << endl;
        } catch (const exception& e) {
            // Xử lý lỗi liên quan đến file
            cout << "Loi trong qua trinh doc file: " << e.what() << endl;
            if (file.is_open()) {
                file.close();
        }
    }
}


User* QuanLyNDung::DangNhapTaiKhoan(const string& username, const string& password){
    if(currentLoggedInUser!=nullptr){
        cout<<"Đã có người đăng nhập!Vui lòng đăng xuất trước!\n";
        return nullptr;
    }
    auto current = DanhSachNDung.begin();
    while(current != nullptr){
        User* user = current->data;
        if(user->getUsername()==username && user->DangNhap(username,password)){
            currentLoggedInUser=user;
            return user;
        }
        current = current->next;
    }
    cout << "Thong tin dang nhap khong dung!\n";
    return nullptr;
}

void QuanLyNDung::DangXuatTaiKhoan() {
    if (currentLoggedInUser == nullptr) {
            cout << "Khong co tai khoan nao dang nhap.\n";
            return;
        }
    currentLoggedInUser->DangXuat();
    currentLoggedInUser = nullptr;
    cout << "Dang xuat thanh cong.\n";
}

User* QuanLyNDung::TimKiemTaiKhoan(const string &sdt){
    auto current = DanhSachNDung.begin();
    while(current!=nullptr){
        if(current->data->getSDT()==sdt){
            return current->data;
        }
        current = current->next;
    }
    return nullptr;  
}

void QuanLyNDung::HienThiDanhSach()const{
    auto current = DanhSachNDung.begin();
    while(current!=nullptr){
        current->data->xuatthongtin();
        current=current->next;
    }
}