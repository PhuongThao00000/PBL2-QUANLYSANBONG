#include "QuanLyDatXe.h"
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

QuanLyDatXe::QuanLyDatXe() : QuanLyDichVu(), tongSoVe(0) {}

QuanLyDatXe::~QuanLyDatXe() {}

// Menu lựa chọn loại xe
void QuanLyDatXe::menuGiuXe() {
    cout << "----- MENU XE -----\n";
    for (int i = 0; i < 4; i++) {
        cout << i << ". " << DatXe("").getTenXe(i)
             << " (Gia: " << DatXe("").getGiaXe(i) << "000 VND)" << "\n";
    }
}

// Thêm đơn đặt xe
void QuanLyDatXe::them(string tennhanvien) {
    cout << "\n----- THÊM ĐƠN GIỮ XE -----\n";
    menuGiuXe();
    cout << "Nhap so loai xe: ";
    int soLoaiXe;
    cin >> soLoaiXe;

    DatXe* donDatXe = new DatXe(tennhanvien, soLoaiXe);  // Khởi tạo đơn đặt xe

    cout << "Nhap thong tin giu xe:\n";
    for (int i = 0; i < soLoaiXe; i++) {
        cout << "Nhap ma loai xe (theo stt tren menu): ";
        int vehicleCode;
        cin >> vehicleCode;

        cout << "Nhap so luong xe: ";
        int quantity;
        cin >> quantity;

        donDatXe->setVehicleCode(i, vehicleCode);
        donDatXe->setQuantity(i, quantity);
    }

    // Tính tổng tiền
    int tongTien = 0;
    for (int i = 0; i < donDatXe->getNumberOfType(); i++) {
        tongTien += donDatXe->getQuantity(i) * donDatXe->getGiaXe(donDatXe->getVehicleCode(i));
    }
    donDatXe->setTotalPrice(tongTien);

    DanhSachdonDatXe.addFirst(donDatXe);
    cout << "Don giu xe ngay " << donDatXe->getNgayGioBan() << " da duoc them vao thanh cong!\n";
}

// Xóa đơn đặt xe theo mã đơn
void QuanLyDatXe::xoa(const int& maDon) {
    DatXe* donDatXe = timkiem(maDon);
    if (donDatXe == nullptr) {
        cout << "Khong tim thay don giu xe ma " << maDon << endl;
        return;
    }
    
    DanhSachdonDatXe.remove(DanhSachdonDatXe.find(donDatXe));
    cout << "Don giu xe ma " << maDon << " duoc xoa thanh cong!\n";
}

// Menu cập nhật đơn đặt xe
void QuanLyDatXe::menuCapNhat() {
    cout << "\n-----------CẬP NHẬT---------------\n";
    cout << "1. Cap nhat so luong\n";
    cout << "2. Them loai xe \n";
    cout << "3. Xoa loai xe\n";
    cout << "--------------------------------------";
    cout << "Vui long nhap lua chon (1, 2, 3): ";
}

// Cập nhật đơn đặt xe theo mã đơn
void QuanLyDatXe::capnhat(const int& maDon) {
    DatXe* donDatXe = timkiem(maDon);
    if (donDatXe == nullptr) {
        cout << "Khong tim thay don giu xe ma " << maDon << endl;
        return;
    }

    cout << "Thong tin don hien tai:\n";
    donDatXe->xuat();
    cout << "Ban co chac chan muon cap nhat don dat nuoc ma " << maDon << " khong? (y/n)";
    int i = _getch();
    if (i == 'n' || i == 'N') return;

    menuCapNhat();
    int choice;
    cin >> choice;

    switch (choice) {
        case 1: { // Cập nhật số lượng xe
                cout << "Nhap ma loai xe can cap nhat so luong: ";
                int vehicleCode;
                cin >> vehicleCode;
                cout << "Nhap so luong moi: ";
                int newQuantity;
                cin >> newQuantity;

                bool found = false;
                for (int i = 0; i < donDatXe->getNumberOfType(); i++) {
                    if (donDatXe->getVehicleCode(i) == vehicleCode) {
                        donDatXe->setQuantity(i, newQuantity);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Ma loai xe khong ton tai trong don.\n";
                } else {
                    int tongTien = 0;
                    for (int i = 0; i < donDatXe->getNumberOfType(); i++) {
                        int code = donDatXe->getVehicleCode(i);
                        tongTien += donDatXe->getQuantity(i) * donDatXe->getGiaXe(code);
                    }
                    donDatXe->setTotalPrice(tongTien);
                    cout << "Cap nhat thanh cong don giu xe ma " << maDon << "! Thong tin don sau khi cap nhat:\n";
                    donDatXe->xuat();
                }
                break;
            }
        case 2: { // Thêm loại xe mới
                cout << "So loai xe ma ban muon them vao don:";
                int soLoaiMoi;
                cin >> soLoaiMoi;
                int soLoaiHienTai = donDatXe->getNumberOfType();
                if (soLoaiMoi <= 0 || soLoaiHienTai + soLoaiMoi >= 3) {
                    cout << "So loai xe khong hop le!\n";
                    return;
                }
                int soLoaiCapNhat = soLoaiHienTai + soLoaiMoi;
                donDatXe->setNumberOfType(soLoaiCapNhat);
                for (int i = soLoaiHienTai; i < soLoaiCapNhat; i++) {
                    menuGiuXe();
                    cout << "Nhap ma xe muon them: ";
                    int vehicleCode;
                    cin >> vehicleCode;

                    if (vehicleCode < 0 || vehicleCode >= 3) {
                        cout << "Ma xe khong hop le! Vui long nhap lai\n";
                        i--;
                        continue;
                    }

                    cout << "Nhap so luong cua loai xe " << donDatXe->getTenXe(vehicleCode) << ": ";
                    int quantity;
                    cin >> quantity;

                    if (quantity <= 0) {
                        cout << "So luong khong hop le!\n";
                        i--;
                        continue;
                    }

                    donDatXe->setVehicleCode(i, vehicleCode);
                    donDatXe->setQuantity(i, quantity);
                }

                int tongTien = 0;
                for (int i = 0; i < donDatXe->getNumberOfType(); i++) {
                    int code = donDatXe->getVehicleCode(i);
                    tongTien += donDatXe->getQuantity(i) * donDatXe->getGiaXe(code);
                }
                donDatXe->setTotalPrice(tongTien);
                cout << "Cap nhat thanh cong don dat nuoc ma " << maDon << "! Thong tin don sau khi cap nhat:\n";
                donDatXe->xuat();
                break;
            }
        case 3: { // Xóa loại xe
                cout << "Nhap so loai xe ma ban muon xoa: ";
                int soLoaiXoa;
                cin >> soLoaiXoa;

                if (soLoaiXoa <= 0 || soLoaiXoa > donDatXe->getNumberOfType()) {
                    cout << "So loai xe muon xoa khong hop le!\n";
                    return;
                }

                for (int j = 0; j < soLoaiXoa; ++j) {
                    cout << "Nhap ma xe thu " << j + 1 << " ban muon xoa: ";
                    int selectedCode;
                    cin >> selectedCode;

                    int index = -1;
                    for (int i = 0; i < donDatXe->getNumberOfType(); ++i) {
                        if (donDatXe->getVehicleCode(i) == selectedCode) {
                            index = i;
                            break;
                        }
                    }

                    if (index == -1) {
                        cout << "Ma xe khong co trong don dat!\n";
                        continue;
                    }

                    for (int i = index; i < donDatXe->getNumberOfType() - 1; ++i) {
                        donDatXe->setVehicleCode(i, donDatXe->getVehicleCode(i + 1));
                        donDatXe->setQuantity(i, donDatXe->getQuantity(i + 1));
                    }

                    donDatXe->setNumberOfType(donDatXe->getNumberOfType() - 1);
                    cout << "Xoa ma xe " << selectedCode << " thanh cong.\n";
                }
                int tongTien = 0;
                for (int i = 0; i < donDatXe->getNumberOfType(); i++) {
                    int code = donDatXe->getVehicleCode(i);
                    tongTien += donDatXe->getQuantity(i) * donDatXe->getGiaXe(code);
                }
                donDatXe->setTotalPrice(tongTien);
                cout << "Xoa loai xe thanh cong! Thong tin don sau khi cap nhat:\n";
                donDatXe->xuat();
                break;
            }
        default:
            cout << "Lua chon khong hop le!\n";
            capnhat(maDon); // Thực hiện lại nếu chọn không hợp lệ
            break;
    }
}

// Tìm kiếm đơn đặt xe theo mã đơn
DatXe* QuanLyDatXe::timkiem(const int& maDon) {
    auto x = DanhSachdonDatXe.begin();
    while (x != nullptr) {
        if (x->data->getMaDon() == maDon) {
            return x->data;
        }
        x = x->next;
    }
    return nullptr;
}

// Xuất tất cả các đơn đặt xe
void QuanLyDatXe::xuat() {
    auto x = DanhSachdonDatXe.begin();
    cout << "Danh sach don dat xe:\n";
    while (x != nullptr) {
        x->data->xuat();
        x = x->next;
    }
}

// Xuất các đơn đặt xe theo ngày bán
void QuanLyDatXe::xuattheongay(int day, int month, int year) {
    auto x = DanhSachdonDatXe.begin();
    while (x != nullptr) {
        string ngay = x->data->getNgayBan();
        // So sánh ngày tháng năm
        if ((day == 0 || stoi(ngay.substr(0, 2)) == day) &&
            (month == 0 || stoi(ngay.substr(3, 2)) == month) &&
            (year == 0 || stoi(ngay.substr(6, 4)) == year)) {
            x->data->xuat();
        }
        x = x->next;
    }
}
