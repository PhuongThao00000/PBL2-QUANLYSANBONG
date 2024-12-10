#include <iostream>
#include "KHACHHANG.h"
#include "NHANVIEN.h"

#include "QUANLY.h"
#include "DICHVU.h"  // Giả sử có lớp Dịch vụ

using namespace std;

void menuNhanVien() {
    cout << "===== MENU NHAN VIEN =====" << endl;
    cout << "1. Quan ly dat san" << endl;
    cout << "2. Quan ly nhan san" << endl;
    cout << "3. Thanh toan hoa don" << endl;
    cout << "4. Quan ly thong tin ca nhan" << endl;
    cout << "5. Dang xuat" << endl;
    cout << "==========================" << endl;
}

void menuQuanLy() {
    cout << "===== MENU QUAN LY =====" << endl;
    cout << "1. Quan ly danh sach nhan vien" << endl;
    cout << "2. Quan ly danh sach khach hang" << endl;
    cout << "3. Quan ly danh sach dich vu" << endl;
    cout << "4. Quan ly nhan vien" << endl;
    cout << "5. Hien thi danh sach nhan vien" << endl;
    cout << "6. Tinh tong luong nhan vien" << endl;
    cout << "7. Cap nhat so gio lam nhan vien part-time" << endl;
    cout << "8. Xoa nhan vien theo ID" << endl;
    cout << "9. Dang xuat" << endl;
    cout << "==========================" << endl;
}

int main() {
    QuanLi quanLy;  // Đối tượng quản lý nhân viên
    NhanVien nhanVien;  // Đối tượng nhân viên

    // Đặt thông tin đăng nhập mặc định
    quanLy.setUsername("admin");
    quanLy.setPassword("admin123");

    nhanVien.setUsername("staff");
    nhanVien.setPassword("staff123");

    while (true) {
        string username, password;
        cout << "===== DANG NHAP =====" << endl;
        cout << "Nhap ten dang nhap: ";
        cin >> username;
        cout << "Nhap mat khau: ";
        cin >> password;

        if (quanLy.DangNhap(username, password)) {
            cout << "Dang nhap thanh cong voi vai tro QUAN LY!\n";

            int choice;
            do {
                menuQuanLy();
                cin >> choice;

                switch (choice) {
                    case 1:
                        quanLy.quanLyNhanVien();
                        break;
                    case 2:
                        quanLy.quanLyKhachHang();
                        break;
                    case 3:
                        quanLy.quanLyDatNuoc();
                        break;
                    case 4:
                        quanLy.quanLyDatXE();
                        break;
                    case 5:
                        quanLy.quanlyHoadon();
                        break;
                    case 6:
                        quanLy.Hienthithongtin();
                        break;
                    case 7: {
                        string id;
                        int hours;
                        cout << "Nhap ID nhan vien: ";
                        cin >> id;
                        cout << "Nhap so gio moi: ";
                        cin >> hours;
                        quanLy.CapNhatTime(id, hours);
                        break;
                    }
                    case 8:
                        quanLy.XoaNhanVienTheoID();
                        break;
                    case 9:
                        cout << "Dang xuat thanh cong!\n";
                        break;
                    default:
                        cout << "Lua chon khong hop le!\n";
                        break;
                }
            } while (choice != 9);

        } else if (nhanVien.DangNhap(username, password)) {
            cout << "Dang nhap thanh cong voi vai tro NHAN VIEN!\n";

            int choice;
            do {
                menuNhanVien();
                cin >> choice;

                switch (choice) {
                    case 1: {
                        // Quan ly dat san
                        KhachHang kh;
                        kh.TimKiemKhachHang();
                        kh.ThemPhieuDatSan();
                        kh.XemThongTinDatSan();
                        break;
                    }
                    case 2: {
                        // Quan ly nhan san
                        KhachHang kh;
                        kh.TimPhieuNhanSan();
                        kh.ThemPhieuNhanSan();
                        kh.XemThongTinNhanSan();
                        break;
                    }
                    case 3: {
                        // Thanh toan hoa don
                        DichVu dv;
                        dv.ThemDichVu();
                        dv.ThanhToan();
                        break;
                    }
                    case 4: {
                        // Quan ly thong tin ca nhan
                        nhanVien.CapNhatTaiKhoan();
                        nhanVien.CapNhatThongTin();
                        break;
                    }
                    case 5:
                        cout << "Dang xuat thanh cong!\n";
                        break;
                    default:
                        cout << "Lua chon khong hop le!\n";
                        break;
                }
            } while (choice != 5);

        } else {
            cout << "Dang nhap that bai. Vui long thu lai!\n";
        }
    }

    return 0;
};
