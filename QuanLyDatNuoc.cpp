#include "QuanLyDatNuoc.h"
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

int QuanLyDatNuoc::gianhapvao[4] = {7, 7, 9, 5}; // Gia nhap kho cho 4 loai nuoc

// Them nuoc vao kho
void QuanLyDatNuoc::addWaterToWarehouse() {
    int numTypes;
    cout << "Nhap so loai nuoc muon nhap vao kho: ";
    cin >> numTypes;

    for (int count = 0; count < numTypes; ++count) {
        cout << "Danh sach ma loai nuoc:\n";
        for (int i = 0; i < 4; ++i) {
            cout << "- Ma loai nuoc: " << i << ", Ten: " << DatNuoc("").getTenNuoc(i) << "\n";
        }

        cout << "Nhap ma loai nuoc muon nhap kho: ";
        int selectedType;
        cin >> selectedType;

        if (selectedType < 0 || selectedType >= 4) {
            cout << "Ma loai nuoc khong hop le vui long nhap lai!\n";
            --count;
            continue;
        }

        cout << "Nhap so luong cho loai nuoc " << DatNuoc("").getTenNuoc(selectedType) << ": ";
        int quantity;
        cin >> quantity;

        if (quantity < 0) {
            cout << "So luong khong hop le!\n";
            --count;
            continue;
        }
        waterquantityinWarehouse[selectedType] += quantity;

        cout << "Cap nhat kho thanh cong!\n";
    }
}

// Hien thi menu kho nuoc
void QuanLyDatNuoc::menuKho() {
    cout << "----- MENU KHO -----\n";
    for (int i = 0; i < 4; i++) {
        cout << i << ". " << DatNuoc("").getTenNuoc(i)
                  << " (Gia nhap: " << gianhapvao[i] << "000 VND"
                  << ", Ton kho: " << waterquantityinWarehouse[i] << ")\n";
    }
}

// Hien thi menu nuoc
void QuanLyDatNuoc::menuNuoc() {
    cout << "----- MENU NUOC -----\n";
    for (int i = 0; i < 4; i++) {
        cout << i << ". " << DatNuoc("").getTenNuoc(i)
                  << " (Gia: " << DatNuoc("").getGiaNuoc(i) << "000 VND"
                  << ", Ton kho: " << waterquantityinWarehouse[i] << ")\n";
    }
}

// Them don dat nuoc
void QuanLyDatNuoc::them(string tennhanvien) {
    cout << "\n----- THEM DON DAT NUOC -----\n";
    menuNuoc();
    DatNuoc* donDatNuoc = new DatNuoc(tennhanvien, 0, 0);  // Them gio ban vao trong constructor

    cout << "Nhap so loai nuoc: ";
    int soLoai;
    cin >> soLoai;
    donDatNuoc->setNumberOfType(soLoai);

    for (int i = 0; i < soLoai; i++) {
        cout << "Nhap ma nuoc (theo stt tren menu): ";
        int waterCode;
        cin >> waterCode;

        if (waterCode < 0 || waterCode >= 4) {
            cout << "Ma nuoc khong hop le!\n";
            i--;
            continue;
        }

        cout << "Nhap so luong cua ma nuoc " << waterCode << " ("
                  << donDatNuoc->getTenNuoc(waterCode) << "): ";
        int quantity;
        cin >> quantity;

        if (quantity > waterquantityinWarehouse[waterCode]) {
            cout << "So luong nuoc trong kho khong du!\n";
            i--;
            continue;
        }

        donDatNuoc->setWaterCode(i, waterCode);
        donDatNuoc->setQuantity(i, quantity);
        waterquantityinWarehouse[waterCode] -= quantity;  // Tru so luong nuoc trong kho
    }

    donDatNuoc->setTotalPrice(0);  // Tinh tong tien
    for (int i = 0; i < donDatNuoc->getNumberOfType(); i++) {
        int code = donDatNuoc->getWaterCode(i);
        donDatNuoc->setTotalPrice(donDatNuoc->getTotalPrice() +
                                  donDatNuoc->getquantity(i) *
                                      donDatNuoc->getGiaNuoc(code));
    }
    donDatNuoc->xuat();
    DanhSachdonDatNuoc.addFirst(donDatNuoc);
    cout << "Don ban nuoc ngay "<<donDatNuoc->getNgayGioBan()<<" da duoc them thanh cong!\n";
}

// Xoa don dat nuoc
void QuanLyDatNuoc::xoa(const int& maDon) {
    DatNuoc* donDatNuoc = timkiem(maDon);
    if (donDatNuoc == nullptr) {
        cout << "Khong tim thay don nuoc ma " << maDon << endl;
        return;
    }
    cout << "Thong tin don hien tai:\n";
    donDatNuoc->xuat();
    cout << "Ban co chac chan muon xoa don dat nuoc ma " << maDon << " khong? (y/n)";
    int i = _getch();
    if (i == 'n' || i == 'N') return;

    // Tra lai so luong nuoc vao kho
    for (int i = 0; i < donDatNuoc->getNumberOfType(); i++) {
        int code = donDatNuoc->getWaterCode(i);
        waterquantityinWarehouse[code] += donDatNuoc->getquantity(i);
    }

    // Xoa don dat nuoc khoi danh sach
    DanhSachdonDatNuoc.remove(DanhSachdonDatNuoc.find(donDatNuoc));
    cout << "Don ban nuoc ma " << maDon << " duoc xoa thanh cong!\n";
}

// Menu cap nhat don dat nuoc
void QuanLyDatNuoc::menuCapNhat() {
    cout << "\n-----------CAP NHAT---------------\n";
    cout << "1. Cap nhat so luong\n";
    cout << "2. Them loai nuoc moi\n";
    cout << "3. Xoa loai nuoc cu\n";
    cout << "--------------------------------------";
    cout << "Vui long nhap lua chon(1,2,3): ";
}

// Cap nhat don dat nuoc
void QuanLyDatNuoc::capnhat(const int& maDon) {
    DatNuoc* donDatNuoc = timkiem(maDon);
    if (donDatNuoc == nullptr) {
        cout << "Khong tim thay don nuoc ma " << maDon << endl;
        return;
    }
    cout << "Thong tin don hien tai:\n";
    donDatNuoc->xuat();
    cout << "Ban co chac chan muon cap nhat don dat nuoc ma " << maDon << " khong? (C/K)";
    int i = _getch();
    if (i == 'k' || i == 'K') return;

    menuCapNhat();
    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            cout << "Nhap ma nuoc muon cap nhat: ";
            int selectedCode;
            cin >> selectedCode;

            int index = -1;
            for (int i = 0; i < donDatNuoc->getNumberOfType(); ++i) {
                if (donDatNuoc->getWaterCode(i) == selectedCode) {
                    index = i;
                    break;
                }
            }

            if (index == -1) {
                cout << "Ma nuoc khong co trong don dat nuoc!\n";
                return;
            }

            cout << "Nhap so luong moi cho ma nuoc " << selectedCode << " ("
                      << donDatNuoc->getTenNuoc(selectedCode) << "): ";
            int newQuantity;
            cin >> newQuantity;

            if (newQuantity < 0) {
                cout << "So luong moi khong hop le!\n";
                return;
            }

            if (newQuantity < donDatNuoc->getquantity(index)) {
                waterquantityinWarehouse[selectedCode] += (donDatNuoc->getquantity(index) - newQuantity);
            } else if (newQuantity > donDatNuoc->getquantity(index)) {
                int required = newQuantity - donDatNuoc->getquantity(index);
                if (required > waterquantityinWarehouse[selectedCode]) {
                    cout << "Kho khong du nuoc! Chi con " << waterquantityinWarehouse[selectedCode]
                          << " trong kho.\n";
                    return;
                }
                waterquantityinWarehouse[selectedCode] -= required;
            }

            donDatNuoc->setQuantity(index, newQuantity);
            cout << "Cap nhat thanh cong don dat nuoc ma " << maDon << "!\n";
            donDatNuoc->xuat();
            break;
        }
        case 2: {
            cout << "So loai nuoc ma ban muon them vao don: ";
            int soLoaiMoi;
            cin >> soLoaiMoi;

            int soLoaiHienTai = donDatNuoc->getNumberOfType();
            int soLoaiCapNhat = soLoaiHienTai + soLoaiMoi;
            donDatNuoc->setNumberOfType(soLoaiCapNhat);

            for (int i = soLoaiHienTai; i < soLoaiCapNhat; i++) {
                menuNuoc();
                cout << "Nhap ma nuoc muon them: ";
                int waterCode;
                cin >> waterCode;

                if (waterCode < 0 || waterCode >= 4) {
                    cout << "Ma nuoc khong hop le! Vui long nhap lai\n";
                    i--;
                    continue;
                }

                cout << "Nhap so luong cua loai nuoc " << donDatNuoc->getTenNuoc(waterCode) << ": ";
                int quantity;
                cin >> quantity;

                if (quantity <= 0) {
                    cout << "So luong khong hop le!\n";
                    i--;
                    continue;
                }

                if (quantity > waterquantityinWarehouse[waterCode]) {
                    cout << "So luong nuoc trong kho khong du! Chỉ còn " << waterquantityinWarehouse[waterCode] << " trong kho.\n";
                    i--;
                    continue;
                }

                donDatNuoc->setWaterCode(i, waterCode);
                donDatNuoc->setQuantity(i, quantity);
                waterquantityinWarehouse[waterCode] -= quantity;
            }

            int tongTienMoi = 0;
            for (int i = 0; i < donDatNuoc->getNumberOfType(); i++) {
                int code = donDatNuoc->getWaterCode(i);
                tongTienMoi += donDatNuoc->getquantity(i) * donDatNuoc->getGiaNuoc(code);
            }
            donDatNuoc->setTotalPrice(tongTienMoi);

            cout << "Cap nhat thanh cong don dat nuoc ma " << maDon << "!\n";
            donDatNuoc->xuat();
            break;
        }
        case 3: {
            cout << "Nhap so loai nuoc muon xoa: ";
            int soLoaiXoa;
            cin >> soLoaiXoa;

            if (soLoaiXoa <= 0 || soLoaiXoa > donDatNuoc->getNumberOfType()) {
                cout << "So loai nuoc muon xoa khong hop le!\n";
                return;
            }

            for (int j = 0; j < soLoaiXoa; ++j) {
                cout << "Nhap ma nuoc thu " << j + 1 << " ban muon xoa: ";
                int selectedCode;
                cin >> selectedCode;

                int index = -1;
                for (int i = 0; i < donDatNuoc->getNumberOfType(); ++i) {
                    if (donDatNuoc->getWaterCode(i) == selectedCode) {
                        index = i;
                        break;
                    }
                }

                if (index == -1) {
                    cout << "Ma nuoc khong co trong don dat nuoc!\n";
                    continue;
                }

                waterquantityinWarehouse[selectedCode] += donDatNuoc->getquantity(index);

                for (int i = index; i < donDatNuoc->getNumberOfType() - 1; ++i) {
                    donDatNuoc->setWaterCode(i, donDatNuoc->getWaterCode(i + 1));
                    donDatNuoc->setQuantity(i, donDatNuoc->getquantity(i + 1));
                }

                donDatNuoc->setNumberOfType(donDatNuoc->getNumberOfType() - 1);
                cout << "Xoa ma nuoc " << selectedCode << " thanh cong.\n";
            }

            int tongTien = 0;
            for (int i = 0; i < donDatNuoc->getNumberOfType(); i++) {
                int code = donDatNuoc->getWaterCode(i);
                tongTien += donDatNuoc->getquantity(i) * donDatNuoc->getGiaNuoc(code);
            }
            donDatNuoc->setTotalPrice(tongTien);

            cout << "Xoa cac loai nuoc thanh cong! Thong tin don sau khi cap nhat:\n";
            donDatNuoc->xuat();
            break;
        }

        default: {
            cout << "Lua chon khong hop le!\n";
            capnhat(maDon);  // Recurse lai neu chon khong hop le
            break;
        }
    }
}

// Xuất các đơn đặt nước theo ngày bán
void QuanLyDatNuoc::xuattheongay(int day, int month, int year) {
    auto x = DanhSachdonDatNuoc.begin();
    while (x != nullptr) {
        string ngay = x->data->getNgayBan();
        if ((day == 0 || stoi(ngay.substr(0, 2)) == day) &&
            (month == 0 || stoi(ngay.substr(3, 2)) == month) &&
            (year == 0 || stoi(ngay.substr(6, 4)) == year)) {
            x->data->xuat();
        }
        x = x->next;
    }
}

// Tim kiem don dat nuoc theo ma don
DatNuoc* QuanLyDatNuoc::timkiem(const int& maDon) {
    auto x = DanhSachdonDatNuoc.begin();
    while (x != nullptr) {
        if (x->data->getMaDon() == maDon) {
            return x->data;
        }
        x = x->next;
    }
    return nullptr;
}

// Xuất tất cả các đơn đặt nước
void QuanLyDatNuoc::xuat() {
    auto x = DanhSachdonDatNuoc.begin();
    cout << "\n=============================================\n";
    cout << "             DANH SACH DON DAT NUOC            \n";
    cout << "==============================================\n";
    while (x != nullptr) {
        x->data->xuat();
        x = x->next;
    }
}

// Tính doanh thu theo ngày
const int& QuanLyDatNuoc::getDoanhThuTheoNgay(int day, int month, int year) {
    doanhthuTheoNgay = 0;
    auto x = DanhSachdonDatNuoc.begin();
    while (x != nullptr) {
        string ngay = x->data->getNgayBan();
        if ((day == 0 || stoi(ngay.substr(0, 2)) == day) &&
            (month == 0 || stoi(ngay.substr(3, 2)) == month) &&
            (year == 0 || stoi(ngay.substr(6, 4)) == year)) {
            for (int i = 0; i < x->data->getNumberOfType(); i++) {
                int waterCode = x->data->getWaterCode(i);
                int quantity = x->data->getquantity(i);
                doanhthuTheoNgay += quantity * x->data->getGiaNuoc(waterCode);
            }
        }
        x = x->next;
    }
    return doanhthuTheoNgay;
}

// Tính doanh thu theo quý
const int& QuanLyDatNuoc::getDoanhThuTheoQuy(int quy, int year) {
    doanhthuTheoNgay = 0;
    if (quy < 1 || quy > 4) {
        cout << "Quy khong hop le. Vui long nhap tu 1 den 4.\n";
        return doanhthuTheoNgay;
    }

    int thangBatDau = (quy - 1) * 3 + 1;
    int thangKetThuc = thangBatDau + 2;
    auto x = DanhSachdonDatNuoc.begin();
    while (x != nullptr) {
        string ngay = x->data->getNgayBan();
        if (year == 0 || stoi(ngay.substr(6, 4)) == year) {
            int thang = stoi(ngay.substr(3, 2));
            if (thang >= thangBatDau && thang <= thangKetThuc) {
                for (int i = 0; i < x->data->getNumberOfType(); i++) {
                    int waterCode = x->data->getWaterCode(i);
                    int quantity = x->data->getquantity(i);
                    doanhthuTheoNgay += quantity * x->data->getGiaNuoc(waterCode);
                }
            }
        }
        x = x->next;
    }
    return doanhthuTheoNgay;
}
