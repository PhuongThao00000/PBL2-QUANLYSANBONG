#include "QuanLyDatXe.h"
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

void QuanLyDatXe::menuGiuXe(){
    cout << "----- MENU XE -----\n";
    for (int i = 0; i < 4; i++) {
        cout << i << ". " << DatXe("").getTenXe(i)
                  << " (Giá: " << DatXe("").getGiaXe(i) << "000 VND"<< ")\n";
    }
}
// Thêm đơn đặt xe
void QuanLyDatXe::them(string tennhanvien) {
    cout << "\n----- THÊM ĐƠN GIỮ XE -----\n";
    menuGiuXe();
    cout << "Nhập số loại xe: ";
    int soLoaiXe;
    cin >> soLoaiXe;

    DatXe* donDatXe = new DatXe(tennhanvien, soLoaiXe);  // Khởi tạo đơn đặt xe

    cout << "Nhập thông tin giữ xe:\n";
    for (int i = 0; i < soLoaiXe; i++) {
        cout << "Nhập mã loại xe (theo stt trên menu) : ";
        int vehicleCode;
        cin >> vehicleCode;

        cout << "Nhập số lượng xe: ";
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
    cout << "Đơn giữ xe ngày "<<donDatXe->getNgayGioBan()<<"đã được thêm vào thành công!\n";
}

// Xóa đơn đặt xe theo ngày bán và giờ bán
void QuanLyDatXe::xoa(const int&maDon) {
    DatXe* donDatXe = timkiem(maDon);
    if (donDatXe == nullptr) {
        cout << "Không tìm thấy đơn giữ xe mã "<<maDon<< endl;
        return;
    }
    
    DanhSachdonDatXe.remove(DanhSachdonDatXe.find(donDatXe));
    cout << "Đơn giữ xe mã "<<maDon<<" được xóa thành công!\n";
}
void QuanLyDatXe::menuCapNhat(){
    cout <<"\n-----------CẬP NHẬT---------------\n";
    cout << "1. Cập nhật số lượng\n";
    cout << "2. Thêm loại xe \n";
    cout << "3. Xoá loại xe\n";
    cout <<"--------------------------------------";
    cout << "Vui lòng nhập lựa chọn(1,2,3): ";
}
// Cập nhật đơn đặt xe theo ngày bán và giờ bán
void QuanLyDatXe::capnhat(const int&maDon) {
    DatXe* donDatXe = timkiem(maDon);
    if (donDatXe == nullptr) {
        cout << "Không tìm thấy đơn giữ xe mã "<<maDon<< endl;
        return;
    }

    cout << "Thông tin đơn hiện tại:\n";
    donDatXe->xuat();
    cout << "Bạn có chắc chắn muốn cập nhật đơn đặt nước mã "<<maDon<<" không? (y/n)";
    int i=_getch();
    if(i=='n'||i=='N') return;


    menuCapNhat();
    int choice;
    cin >> choice;

    switch (choice) {
        case 1: { // Cập nhật số lượng xe
                cout << "Nhập mã loại xe cần cập nhật số lượng: ";
                int vehicleCode;
                cin >> vehicleCode;
                cout << "Nhập số lượng mới: ";
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
                    cout << "Mã loại xe không tồn tại trong đơn.\n";
                } else {
                    int tongTien = 0;
            for (int i = 0; i < donDatXe->getNumberOfType(); i++) {
                int code = donDatXe->getVehicleCode(i);
                tongTien += donDatXe->getQuantity(i) * donDatXe->getGiaXe(code);
            }
            donDatXe->setTotalPrice(tongTien);
                    cout << "Cập nhật thành công đơn giữ xe mã "<<maDon<<"!Thông tin đơn sau khi cập nhật:\n";
                    donDatXe->xuat();
                }
                break;
            }
        case 2: { // Thêm loại xe mới
                cout << "Số loại xe mà bạn muốn thêm vào đơn:";
                int soLoaiMoi;
                cin >> soLoaiMoi;
                int soLoaiHienTai = donDatXe->getNumberOfType();
                // Kiểm tra tính hợp lệ của số loại nước mới
            if (soLoaiMoi <= 0||soLoaiHienTai+soLoaiMoi>=3) {
                cout << "Số loại nước không hợp lệ!\n";
                return;
            }
            int soLoaiCapNhat = soLoaiHienTai + soLoaiMoi;
            donDatXe->setNumberOfType(soLoaiCapNhat);
            for (int i = soLoaiHienTai; i < soLoaiCapNhat; i++) {
                menuGiuXe();
                // Chọn mã nước
                cout << "Nhập mã xe muốn thêm: ";
                int vehicleCode;
                cin >> vehicleCode;

                // Kiểm tra tính hợp lệ của mã nước
                if (vehicleCode < 0 ||vehicleCode >= 3) {
                    cout << "Mã xe không hợp lệ! Vui lòng nhập lại\n";
                    i--;
                    continue;
                }

                // Nhập số lượng nước
                cout << "Nhập số lượng của loại xe " << donDatXe->getTenXe(vehicleCode) << ": ";
                int quantity;
                cin >> quantity;

                if (quantity <= 0) {
                    cout << "Số lượng không hợp lệ!\n";
                    i--;
                    continue;
                }

                // Cập nhật số lượng và mã nước mới vào đơn
                donDatXe->setVehicleCode(i, vehicleCode);
                donDatXe->setQuantity(i, quantity);
            }

            int tongTien = 0;
            for (int i = 0; i < donDatXe->getNumberOfType(); i++) {
                int code = donDatXe->getVehicleCode(i);
                tongTien += donDatXe->getQuantity(i) * donDatXe->getGiaXe(code);
            }
            donDatXe->setTotalPrice(tongTien);
            cout << "Cập nhật thành công đơn đặt nước mã "<<maDon<<"!Thông tin đơn sau khi cập nhật:\n";
            donDatXe->xuat();
                break;
            }
        case 3: { // Xóa loại xe
               cout << "Nhập số loại xe mà bạn muốn xóa: ";
                int soLoaiXoa;
                cin >> soLoaiXoa;

            if (soLoaiXoa <= 0 || soLoaiXoa > donDatXe->getNumberOfType()) {
                cout << "Số loại nước muốn xóa không hợp lệ!\n";
                return;
            }

            for (int j = 0; j < soLoaiXoa; ++j) {
                cout << "Nhập mã xe thứ " << j + 1 << " bạn muốn xóa: ";
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
                    cout << "Mã nước không có trong đơn đặt nước!\n";
                    continue; // Bỏ qua và tiếp tục xóa các mã khác
                }

                // Xóa nước khỏi đơn đặt nước
                for (int i = index; i < donDatXe->getNumberOfType() - 1; ++i) {
                    donDatXe->setVehicleCode(i, donDatXe->getVehicleCode(i + 1));
                    donDatXe->setQuantity(i, donDatXe->getQuantity(i + 1));
                }

                donDatXe->setNumberOfType(donDatXe->getNumberOfType() - 1);
                cout << "Xoá mã xe " << selectedCode << " thành công.\n";
            }
             int tongTien = 0;
            for (int i = 0; i < donDatXe->getNumberOfType(); i++) {
                int code = donDatXe->getVehicleCode(i);
                tongTien += donDatXe->getQuantity(i) * donDatXe->getGiaXe(code);
            }
            donDatXe->setTotalPrice(tongTien);
            cout << "Xoá các loại xe thành công! Thông tin đơn sau khi cập nhật:\n";
            donDatXe->xuat();
                break;
            }

    // Tính lại tổng tiền
            default:
                {
                    cout << "Lựa chọn không hợp lệ!\n";
                    capnhat(maDon);  // Recurse lại nếu chọn không hợp lệ
                    break;
                }
}
}


// Tìm kiếm đơn đặt xe theo ngày bán và giờ bán
DatXe* QuanLyDatXe::timkiem(const int&maDon) {
    auto x = DanhSachdonDatXe.begin();
    while (x != nullptr) {
        if (x->data->getMaDon()==maDon) {
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

// Thống kê doanh thu theo ngày
const int& QuanLyDatXe::getDoanhThuTheoNgay(int day, int month, int year) {
   doanhthuTheoNgay = 0;
    auto x = DanhSachdonDatXe.begin();
    while (x != nullptr) {
        string ngay = x->data->getNgayBan();
        // So sánh ngày tháng năm
        if ((day == 0 || stoi(ngay.substr(0, 2)) == day) &&
            (month == 0 || stoi(ngay.substr(3, 2)) == month) &&
            (year == 0 || stoi(ngay.substr(6, 4)) == year)) {
            for (int i = 0; i < x->data->getNumberOfType(); i++) {
                int vehicleCode = x->data->getVehicleCode(i);
                int quantity = x->data->getQuantity(i);
                doanhthuTheoNgay += quantity * x->data->getGiaXe(vehicleCode);
            }
        }
        x = x->next;
    }
    return doanhthuTheoNgay;
}

const int& QuanLyDatXe::getDoanhThuTheoQuy(int quy, int year) {
    doanhthuTheoNgay=0;
        // Kiểm tra quý hợp lệ
        if (quy < 1 || quy > 4) {
            cout << "Quý không hợp lệ. Vui lòng nhập từ 1 đến 4.\n";
            return doanhthuTheoNgay;
        }
        // Xác định tháng bắt đầu và kết thúc của quý
        int thangBatDau = (quy - 1) * 3 + 1;
        int thangKetThuc = thangBatDau + 2;
        
            // Duyệt qua danh sách đơn đặt nước
            auto x = DanhSachdonDatXe.begin();
            while (x != nullptr) {
                string ngay = x->data->getNgayBan();

                if (year == 0 || stoi(ngay.substr(6, 4)) == year) {
                int thang = stoi(ngay.substr(3, 2)); // Lấy tháng từ chuỗi ngày

                // Kiểm tra tháng thuộc quý
                if (thang >= thangBatDau && thang <= thangKetThuc) {
                    for (int i = 0; i < x->data->getNumberOfType(); i++) {
                        int vehicleCode = x->data->getVehicleCode(i);
                        int quantity = x->data->getQuantity(i);

                        // Cộng doanh thu
                        doanhthuTheoNgay += quantity * x->data->getGiaXe(vehicleCode);
                    }
                }
                
            }
            x = x->next;
        }   
        return doanhthuTheoNgay;
    }

const int& QuanLyDatXe::getChiPhiNhapTheoNgay(int day, int month, int year) {
    chiphinhapTheoNgay=0;
    tongSoVe=0;
    auto x = DanhSachdonDatXe.begin();
    while (x != nullptr) {
        string ngay = x->data->getNgayBan();
        // So sánh ngày tháng năm
        if ((day == 0 || stoi(ngay.substr(0, 2)) == day) &&
            (month == 0 || stoi(ngay.substr(3, 2)) == month) &&
            (year == 0 || stoi(ngay.substr(6, 4)) == year)) {
            for (int i = 0; i < x->data->getNumberOfType(); i++) {
                int quantity = x->data->getQuantity(i);
                tongSoVe += quantity;
            }
        }
        x = x->next;
    }
    chiphinhapTheoNgay = tongSoVe * 1000;
    // Sử dụng `tienVon` để in kết quả
    cout << "Tổng số vé xe đã bán: " << tongSoVe << "\n";
    cout << "Tổng tiền vốn đã dành để in vé: " << chiphinhapTheoNgay << " VND\n";
    return chiphinhapTheoNgay;
}

const int& QuanLyDatXe::getChiPhiNhapTheoQuy(int quy, int year) {
    chiphinhapTheoNgay=0;
    tongSoVe=0;
    if (quy < 1 || quy > 4) {
            cout << "Quý không hợp lệ. Vui lòng nhập từ 1 đến 4.\n";
            return chiphinhapTheoNgay;
        }
    // Xác định tháng bắt đầu và kết thúc của quý
        int thangBatDau = (quy - 1) * 3 + 1;
        int thangKetThuc = thangBatDau + 2;
            // Duyệt qua danh sách đơn đặt nước
            auto x = DanhSachdonDatXe.begin();
            while (x != nullptr) {
                string ngay = x->data->getNgayBan();

                if (year == 0 || stoi(ngay.substr(6, 4)) == year) {
                int thang = stoi(ngay.substr(3, 2)); // Lấy tháng từ chuỗi ngày

                // Kiểm tra tháng thuộc quý
                if (thang >= thangBatDau && thang <= thangKetThuc) {
                    for (int i = 0; i < x->data->getNumberOfType(); i++) {
                        int quantity = x->data->getQuantity(i);
                        // Cộng doanh thu
                        tongSoVe+=quantity;
                    }
                }
                
            }
            x = x->next;
        }
    chiphinhapTheoNgay = tongSoVe * 1000;
    // Sử dụng `tienVon` để in kết quả
    cout << "Tổng số vé xe đã bán: " << tongSoVe << "\n";
    cout << "Tổng tiền vốn đã dành để in vé: " << chiphinhapTheoNgay << " VND\n";
    return chiphinhapTheoNgay;
}


