#include "QuanLyNDung.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

bool QuanLyNDung::DangKyTaiKhoan(const string &username, const string &password, const string &phonenumber, int gender, Date& ngsinh, int loaiTaiKhoan) {
    try {
        // Kiem tra tai khoan da ton tai
        if (TimKiemTaiKhoan(phonenumber) != nullptr) {
            throw invalid_argument("Tai khoan da ton tai!");
        } else {
            User* newUser = nullptr;

            // Kiem tra loai tai khoan hop le
            switch (loaiTaiKhoan) {
                case 0: // Khach hang
                    newUser = new KhachHang(username, password, phonenumber, gender, ngsinh, loaiTaiKhoan);
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

            // Them tai khoan vao danh sach nguoi dung
            DanhSachNDung.addFirst(newUser);

            cout << "Dang ky thanh cong!\n";
            return true;
        }
    } catch (const invalid_argument& e) {
        cout << "Loi: " << e.what() << endl;
        return false;
    } catch (const exception& e) {
        cout << "Loi ngoai le: " << e.what() << endl;
        return false;
    }
}

void QuanLyNDung::DangKyTuFile(const string& fileName) {
    ifstream file;
    try {
        file.open(fileName);
        if (!file.is_open()) {
            throw runtime_error("Khong the mo file: " + fileName);
        }
        string line;
        int count = 0;
        int lineNumber = 0;
        while (getline(file, line)) {
            lineNumber++;
            try {
                stringstream ss(line);
                string username, password, phonenumber, genderStr, dobStr, accountTypeStr;
                if (!(getline(ss, username, ',') &&
                      getline(ss, password, ',') &&
                      getline(ss, phonenumber, ',') &&
                      getline(ss, genderStr, ',') &&
                      getline(ss, dobStr, ',') &&
                      getline(ss, accountTypeStr))) {
                    throw invalid_argument("Dong khong hop le");
                }
                username = Trim(username);
                password = Trim(password);
                phonenumber = Trim(phonenumber);
                genderStr = Trim(genderStr);
                dobStr = Trim(dobStr);
                accountTypeStr = Trim(accountTypeStr);

                int gender = stoi(genderStr);
                int accountType = stoi(accountTypeStr); // Loai tai khoan
                Date birthDate(dobStr); // Gia su Date co constructor nhan chuoi

                if (DangKyTaiKhoan(username, password, phonenumber, gender, birthDate, accountType)) {
                    count++;
                } else {
                    throw runtime_error("Dang ky tai khoan that bai: " + username);
                }
            } catch (const exception& e) {
                cout << "Loi tai dong " << lineNumber << ": " << e.what() << endl;
            }
        }
        file.close();
        cout << "Da dang ky thanh cong " << count << " tai khoan tu file." << endl;
    } catch (const exception& e) {
        cout << "Loi trong qua trinh doc file: " << e.what() << endl;
        if (file.is_open()) {
            file.close();
        }
    }
}

User* QuanLyNDung::DangNhapTaiKhoan(const string& username, const string& password) {
    if (currentLoggedInUser != nullptr) {
        cout << "Da co nguoi dang nhap! Vui long dang xuat truoc!\n";
        return nullptr;
    }
    auto current = DanhSachNDung.begin();
    while (current != nullptr) {
        User* user = current->data;
        if (user->getUsername() == username && user->DangNhap(username, password)) {
            currentLoggedInUser = user;
            return user;
        }
        current = current->next;
    }
    cout << "Thong tin dang nhap khong dung!\n";
    return nullptr;
}

void QuanLyNDung::DangXuatTaiKhoan() {
    if (currentLoggedInUser == nullptr) {
        cout << "Khong co tai khoan nao dang dang nhap.\n";
        return;
    }
    currentLoggedInUser->DangXuat();
    currentLoggedInUser = nullptr;
    cout << "Dang xuat thanh cong.\n";
}

User* QuanLyNDung::TimKiemTaiKhoan(const string& sdt) {
    auto current = DanhSachNDung.begin();
    while (current != nullptr) {
        if (current->data->getSDT() == sdt) {
            return current->data;
        }
        current = current->next;
    }
    return nullptr;
}

void QuanLyNDung::HienThiDanhSach() const {
    auto current = DanhSachNDung.begin();
    while (current != nullptr) {
        current->data->xuatthongtin();
        current = current->next;
    }
}

// Ham loai bo dau cach o dau va cuoi chuoi
string QuanLyNDung::Trim(const string& input) {
    size_t start = input.find_first_not_of(" ");
    size_t end = input.find_last_not_of(" ");
    return (start == string::npos) ? "" : input.substr(start, end - start + 1);
}

// Ham nhap ten nguoi dung (khong cho phep dau cach thua)
void QuanLyNDung::SetTenNguoiDung(string& tenndung) {
    do {
        cout << "Username (ho va ten cua ban): ";
        getline(cin, tenndung);
        tenndung = Trim(tenndung);
        if (tenndung.empty()) {
            cout << "Ten nguoi dung khong duoc de trong. Vui long nhap lai.\n";
        }
    } while (tenndung.empty());
}

// Ham kiem tra so dien thoai hop le
bool QuanLyNDung::IsValidPhoneNumber(const string& sdt) {
    if (sdt.length() < 10 || sdt.length() > 11) return false; // So dien thoai thuong dai 10-11 chu so
    for (char c : sdt) {
        if (!isdigit(c)) return false; // Chi chua ky tu so
    }
    return true;
}

// Ham nhap so dien thoai
void QuanLyNDung::SetSoDienThoai(string& sdt) {
    do {
        cout << "Phone number: ";
        cin >> sdt;
        if (!IsValidPhoneNumber(sdt)) {
            cout << "So dien thoai khong hop le. Vui long nhap lai (chi chua 10-11 so).\n";
        }
    } while (!IsValidPhoneNumber(sdt));
}

// Ham nhap gioi tinh
void QuanLyNDung::SetGioiTinh(int& gender) {
    do {
        cout << "Gender (0: Male, 1: Female): ";
        cin >> gender;
        if (gender != 0 && gender != 1) {
            cout << "Gioi tinh khong hop le. Vui long nhap lai\n";
        }
    } while (gender != 0 && gender != 1);
}

// Ham nhap mat khau
void QuanLyNDung::SetPassWord(string& password) {
    string pass, againpass;
    do {
        cout << "Password (KHONG chua dau cach): ";
        cin >> pass;
        cout << "Nhap lai password: ";
        cin >> againpass;
    } while (againpass != pass);
    password = pass;
}
