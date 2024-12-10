#include "QuanLyDatNuoc.h"
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
int QuanLyDatNuoc::gianhapvao[4]={7,7,9,5};

void QuanLyDatNuoc::addWaterToWarehouse() {
    int numTypes;
    cout << "Nhập số loại nước muốn nhập vào kho: ";
    cin >> numTypes;

    for (int count = 0; count < numTypes; ++count) {
        cout << "Danh sách mã loại nước:\n";
        for (int i = 0; i < 4; ++i) {
            cout << "- Mã loại nước: " << i << ", Tên: " << DatNuoc("").getTenNuoc(i) << "\n";
        }

        cout << "Nhập mã loại nước muốn nhập kho: ";
        int selectedType;
        cin >> selectedType;

        if (selectedType < 0 || selectedType >= 4) {
            cout << "Mã loại nước không hợp lệ vui lòng nhập lại!\n";
            --count;
            continue;
        }

        cout << "Nhập số lượng cho loại nước " << DatNuoc("").getTenNuoc(selectedType) << ": ";
        int quantity;
        cin >> quantity;

        if (quantity < 0) {
            cout << "Số lượng không hợp lệ!\n";
            --count;
            continue;
        }
        waterquantityinWarehouse[selectedType] += quantity;

    cout << "Cập nhật kho thành công!\n";
}
}



// Hiển thị menu nước
void QuanLyDatNuoc::menuKho() {
    cout << "----- MENU KHO -----\n";
    for (int i = 0; i < 4; i++) {
        cout << i << ". " << DatNuoc("").getTenNuoc(i)
                  << " (Giá nhập: " <<gianhapvao[i] << "000 VND"
                  << ", Tồn kho: " << waterquantityinWarehouse[i] << ")\n";
    }
}

void QuanLyDatNuoc::menuNuoc() {
    cout << "----- MENU NƯỚC -----\n";
    for (int i = 0; i < 4; i++) {
        cout << i << ". " << DatNuoc("").getTenNuoc(i)
                  << " (Giá: " <<DatNuoc("").getGiaNuoc(i)   << "000 VND"
                  << ", Tồn kho: " << waterquantityinWarehouse[i] << ")\n";
    }
}


// Thêm đơn đặt nước
void QuanLyDatNuoc::them(string tennhanvien) {
    cout << "\n----- THÊM ĐƠN ĐẶT NƯỚC -----\n";
    menuNuoc();
    DatNuoc* donDatNuoc = new DatNuoc(tennhanvien, 0, 0);  // Thêm giờ bán vào trong constructor

    cout << "Nhập số loại nước: ";
    int soLoai;
    cin >> soLoai;
    donDatNuoc->setNumberOfType(soLoai);

    for (int i = 0; i < soLoai; i++) {
        cout << "Nhập mã nước (theo stt trên menu): ";
        int waterCode;
        cin >> waterCode;

        if (waterCode < 0 || waterCode >= 4) {
            cout << "Mã nước không hợp lệ!\n";
            i--;
            continue;
        }

        cout << "Nhập số lượng của mã nước " << waterCode << " ("
                  << donDatNuoc->getTenNuoc(waterCode) << "): ";
        int quantity;
        cin >> quantity;

        if (quantity > waterquantityinWarehouse[waterCode]) {
            cout << "Số lượng nước trong kho không đủ!\n";
            i--;
            continue;
        }

        donDatNuoc->setWaterCode(i, waterCode);
        donDatNuoc->setQuantity(i, quantity);
        waterquantityinWarehouse[waterCode] -= quantity;  // Trừ số lượng nước trong kho
    }

    donDatNuoc->setTotalPrice(0);  // Tính tổng tiền
    for (int i = 0; i < donDatNuoc->getNumberOfType(); i++) {
        int code = donDatNuoc->getWaterCode(i);
        donDatNuoc->setTotalPrice(donDatNuoc->getTotalPrice() +
                                  donDatNuoc->getquantity(i) *
                                      donDatNuoc->getGiaNuoc(code));
    }
    donDatNuoc->xuat();
    DanhSachdonDatNuoc.addFirst(donDatNuoc);
    cout << "Đơn bán nước ngày "<<donDatNuoc->getNgayGioBan()<<" đã được thêm thanh cong!\n";
}


// Xóa đơn đặt nước
//tìm kiếm trước nếu không muốn xóa thì quay lại
void QuanLyDatNuoc::xoa(const int &maDon) {
    DatNuoc* donDatNuoc = timkiem(maDon);
    if (donDatNuoc == nullptr) {
        cout << "Không tìm thấy đơn nước mã "<<maDon<<endl;
        return;
    }
    cout << "Thông tin đơn hiện tại:\n";
    donDatNuoc->xuat();
    cout << "Bạn có chắc chắn muốn xóa đơn đặt nước mã "<<maDon<<" không? (y/n)";
    int i=_getch();
    if(i=='n'||i=='N') return;
    // Trả lại số lượng nước vào kho
    for (int i = 0; i < donDatNuoc->getNumberOfType(); i++) {
        int code = donDatNuoc->getWaterCode(i);
        waterquantityinWarehouse[code] += donDatNuoc->getquantity(i);
    }

    // Xóa đơn đặt nước khỏi danh sách
    DanhSachdonDatNuoc.remove(DanhSachdonDatNuoc.find(donDatNuoc)); 
    cout << "Đơn bán nước mã "<<maDon<<" được xóa thành công!\n";
}

void QuanLyDatNuoc::menuCapNhat(){
    cout <<"\n-----------CẬP NHẬT---------------\n";
    cout << "1. Cập nhật số lượng\n";
    cout << "2. Thêm loại nước mới\n";
    cout << "3. Xoá loại nước cũ\n";
    cout <<"--------------------------------------";
    cout << "Vui lòng nhập lựa chọn(1,2,3): ";
}
// Cập nhật đơn đặt nước(tìm kiếm trước nếu không muốn cập nhật thì quay lại)
void QuanLyDatNuoc::capnhat(const int &maDon) {
    DatNuoc* donDatNuoc = timkiem(maDon);
    if (donDatNuoc == nullptr) {
        cout << "Không tìm thấy đơn nước mã "<<maDon<<endl;
        return;
    }
    cout << "Thông tin đơn hiện tại:\n";
    donDatNuoc->xuat();
    cout << "Bạn có chắc chắn muốn cập nhật đơn đặt nước mã "<<maDon<<" không? (y/n)";
    int i=_getch();
    if(i=='n'||i=='N') return;
    
    //cout << "4) Cap nhat ngay ban\n";
    menuCapNhat();
    int choice;
    cin >> choice;
    switch(choice){
        case 1:
        {
            // // Hiển thị danh sách mã nước trong đơn
            // cout << "Danh sách mã nước trong đơn:\n";
            // for (int i = 0; i < donDatNuoc->getNumberOfType(); ++i) {
            //     int code = donDatNuoc->getWaterCode(i);
            //     cout << "- Mã nước: " << code << ", Tên: " << donDatNuoc->getTenNuoc(code)
            //           << ", Số lượng hiện tại: " << donDatNuoc->getquantity(i) << "\n";
            // }

            // Yêu cầu khách hàng chọn mã nước để cập nhật
            cout << "Nhập mã nước muốn cập nhật: ";
            int selectedCode;
            cin >> selectedCode;

            // Tìm mã nước trong đơn
            int index = -1;
            for (int i = 0; i < donDatNuoc->getNumberOfType(); ++i) {
                if (donDatNuoc->getWaterCode(i) == selectedCode) {
                    index = i;
                    break;
                }
            }

            if (index == -1) {
                cout << "Mã nước không có trong đơn đặt nước!\n";
                return;
            }

            // Yêu cầu nhập số lượng mới
            int currentQuantity = donDatNuoc->getquantity(index); // Số lượng hiện tại
            cout << "Nhập số lượng mới cho mã nước " << selectedCode << " ("
                      << donDatNuoc->getTenNuoc(selectedCode) << ", hiện tại: " << currentQuantity << "): ";
            int newQuantity; // Số lượng mới
            cin >> newQuantity;

            if (newQuantity < 0) {
                cout << "Số lượng mới không hợp lệ!\n";
                return;
            }

            // Cập nhật số lượng và kho
            if (newQuantity < currentQuantity) {
                waterquantityinWarehouse[selectedCode] += (currentQuantity - newQuantity);
            } else if (newQuantity > currentQuantity) {
                int required = newQuantity - currentQuantity;
                if (required > waterquantityinWarehouse[selectedCode]) {
                    cout << "Kho không đủ nước! Chỉ còn " << waterquantityinWarehouse[selectedCode]
                          << " trong kho.\n";
                    return;
                }
                waterquantityinWarehouse[selectedCode] -= required;
            }
            donDatNuoc->setQuantity(index, newQuantity);
            cout << "Cập nhật thành công đơn đặt nước mã "<<maDon<<"!Thông tin đơn sau khi cập nhật:\n";
            donDatNuoc->xuat();
            break;
        }

        case 2:
        {
            // Hiển thị chi tiết đơn đặt nước hiện tại để khách hàng tham khảo

            cout << "Số loại nước mà bạn muốn thêm vào đơn: ";
            int soLoaiMoi;
            cin >> soLoaiMoi;

            // Kiểm tra tính hợp lệ của số loại nước mới
            if (soLoaiMoi <= 0) {
                cout << "Số loại nước không hợp lệ!\n";
                return;
            }

            // Cập nhật lại tổng số loại nước
            int soLoaiHienTai = donDatNuoc->getNumberOfType();
            int soLoaiCapNhat = soLoaiHienTai + soLoaiMoi;
            donDatNuoc->setNumberOfType(soLoaiCapNhat);

            // Thêm các loại nước mới vào đơn hàng
            for (int i = soLoaiHienTai; i < soLoaiCapNhat; i++) {
                menuNuoc();
                // Chọn mã nước
                cout << "Nhập mã nước muốn thêm: ";
                int waterCode;
                cin >> waterCode;

                // Kiểm tra tính hợp lệ của mã nước
                if (waterCode < 0 || waterCode >= 4) {
                    cout << "Mã nước không hợp lệ! Vui lòng nhập lại\n";
                    i--;
                    continue;
                }

                // Nhập số lượng nước
                cout << "Nhập số lượng của loại nước " << donDatNuoc->getTenNuoc(waterCode) << ": ";
                int quantity;
                cin >> quantity;

                if (quantity <= 0) {
                    cout << "Số lượng không hợp lệ!\n";
                    i--;
                    continue;
                }

                if (quantity > waterquantityinWarehouse[waterCode]) {
                    cout << "Số lượng nước trong kho không đủ! Chỉ còn " << waterquantityinWarehouse[waterCode] << " trong kho.\n";
                    i--;
                    continue;
                }

                // Cập nhật số lượng và mã nước mới vào đơn
                donDatNuoc->setWaterCode(i, waterCode);
                donDatNuoc->setQuantity(i, quantity);

                // Trừ số lượng nước trong kho
                waterquantityinWarehouse[waterCode] -= quantity;
            }

            // Cập nhật tổng tiền
            int tongTienMoi = 0;
            for (int i = 0; i < donDatNuoc->getNumberOfType(); i++) {
                int code = donDatNuoc->getWaterCode(i);
                tongTienMoi += donDatNuoc->getquantity(i) * donDatNuoc->getGiaNuoc(code);
            }
            donDatNuoc->setTotalPrice(tongTienMoi);

            cout << "Cập nhật thành công đơn đặt nước mã "<<maDon<<"!Thông tin đơn sau khi cập nhật:\n";
            donDatNuoc->xuat();
            break;
        }

        case 3:
        {
            // Xóa nhiều loại nước

            // cout << "Danh sach ma nuoc trong don:\n";
            // for (int i = 0; i < donDatNuoc->getNumberOfType(); ++i) {
            //     int code = donDatNuoc->getWaterCode(i);
            //     cout << "- Ma nuoc: " << code << ", Ten: " << donDatNuoc->getTenNuoc(code)
            //          << ", So luong: " << donDatNuoc->getquantity(i) << "\n";
            // }
            // donDatNuoc->xuat();

            cout << "Nhập số loại nước mà bạn muốn xóa: ";
            int soLoaiXoa;
            cin >> soLoaiXoa;

            if (soLoaiXoa <= 0 || soLoaiXoa > donDatNuoc->getNumberOfType()) {
                cout << "Số loại nước muốn xóa không hợp lệ!\n";
                return;
            }

            for (int j = 0; j < soLoaiXoa; ++j) {
                cout << "Nhap mã nước thứ " << j + 1 << " bạn muốn xóa: ";
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
                    cout << "Mã nước không có trong đơn đặt nước!\n";
                    continue; // Bỏ qua và tiếp tục xóa các mã khác
                }

                // Hoàn trả nước vào kho
                waterquantityinWarehouse[selectedCode] += donDatNuoc->getquantity(index);

                // Xóa nước khỏi đơn đặt nước
                for (int i = index; i < donDatNuoc->getNumberOfType() - 1; ++i) {
                    donDatNuoc->setWaterCode(i, donDatNuoc->getWaterCode(i + 1));
                    donDatNuoc->setQuantity(i, donDatNuoc->getquantity(i + 1));
                }

                donDatNuoc->setNumberOfType(donDatNuoc->getNumberOfType() - 1);
                cout << "Xoá mã nước " << selectedCode << " thành công.\n";
            }

            // Cập nhật tổng tiền
            int tongTien = 0;
            for (int i = 0; i < donDatNuoc->getNumberOfType(); i++) {
                int code = donDatNuoc->getWaterCode(i);
                tongTien += donDatNuoc->getquantity(i) * donDatNuoc->getGiaNuoc(code);
            }
            donDatNuoc->setTotalPrice(tongTien);

            cout << "Xoá các loại nước thành công! Thông tin đơn sau khi cập nhật:\n";
            donDatNuoc->xuat();
            break;
        }

        // case 4:
        // {
        //     Date newngay;
        //     cout << "Nhap ngay ban moi"; newngay.SetNgay();
        //     donDatNuoc->setNgayThongKe(newngay.ngay);
        //     cout << "Cap nhat ngay ban thanh cong! Thong tin don hang moi la:\n";
        //     donDatNuoc->xuat();
        //     break;
        // }

        default:
        {
            cout << "Lựa chọn không hợp lệ!\n";
            capnhat(maDon);  // Recurse lại nếu chọn không hợp lệ
            break;
        }
    }
}


// Xuất các đơn đặt xe theo ngày bán
void QuanLyDatNuoc::xuattheongay(int day, int month, int year) {
    auto x = DanhSachdonDatNuoc.begin();
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


// Tìm kiếm đơn đặt nước
DatNuoc* QuanLyDatNuoc::timkiem(const int& maDon) {
    auto x = DanhSachdonDatNuoc.begin();
        while (x != nullptr) {
            // Kiểm tra xem ngày bán và giờ bán có khớp không
            if (x->data->getMaDon() == maDon) {
                return x->data;
            }
            x = x->next;
        }
        return nullptr;  // Không tìm thấy
}

// Xuất tất cả đơn đặt nước
void QuanLyDatNuoc::xuat() {
    auto x = DanhSachdonDatNuoc.begin();
    cout << "\n=============================================\n";
    cout << "             DANH SÁCH ĐƠN ĐẶT NƯỚC            \n";
    cout << "==============================================\n";
    while (x != nullptr) {
        x->data->xuat();
        x = x->next;
    }
}

const int& QuanLyDatNuoc::getDoanhThuTheoNgay(int day, int month, int year) {
        doanhthuTheoNgay = 0;

        // Duyệt qua danh sách đơn đặt nước
        auto x = DanhSachdonDatNuoc.begin();
        while (x != nullptr) {
            string ngay = x->data->getNgayBan();

            // So sánh ngày, tháng, năm (không xét giờ)
            if ((day == 0 || stoi(ngay.substr(0, 2)) == day) &&
                (month == 0 || stoi(ngay.substr(3, 2)) == month) &&
                (year == 0 || stoi(ngay.substr(6, 4)) == year)) {
                for (int i = 0; i < x->data->getNumberOfType(); i++) {
                    int waterCode = x->data->getWaterCode(i);
                    int quantity = x->data->getquantity(i);

                    // Cộng doanh thu
                    doanhthuTheoNgay += quantity * x->data->getGiaNuoc(waterCode);
                }
            }
            x = x->next;
        }

        return doanhthuTheoNgay;
}

const int& QuanLyDatNuoc::getDoanhThuTheoQuy(int quy, int year) {
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
            auto x = DanhSachdonDatNuoc.begin();
            while (x != nullptr) {
                string ngay = x->data->getNgayBan();

                if (year == 0 || stoi(ngay.substr(6, 4)) == year) {
                int thang = stoi(ngay.substr(3, 2)); // Lấy tháng từ chuỗi ngày

                // Kiểm tra tháng thuộc quý
                if (thang >= thangBatDau && thang <= thangKetThuc) {
                    for (int i = 0; i < x->data->getNumberOfType(); i++) {
                        int waterCode = x->data->getWaterCode(i);
                        int quantity = x->data->getquantity(i);

                        // Cộng doanh thu
                        doanhthuTheoNgay += quantity * x->data->getGiaNuoc(waterCode);
                    }
                }
                
            }
            x = x->next;
        }   
        return doanhthuTheoNgay;
    }

const int& QuanLyDatNuoc::getChiPhiNhapTheoNgay(int day, int month, int year) {
        chiphinhapTheoNgay = 0;

        // Duyệt qua danh sách đơn đặt nước
        auto x = DanhSachdonDatNuoc.begin();
        while (x != nullptr) {
            string ngay = x->data->getNgayBan();
            
            // So sánh ngày, tháng, năm
            if ((day == 0 || stoi(ngay.substr(0, 2)) == day) &&
                (month == 0 || stoi(ngay.substr(3, 2)) == month) &&
                (year == 0 || stoi(ngay.substr(6, 4)) == year)) {
                for (int i = 0; i < x->data->getNumberOfType(); i++) {
                    int waterCode = x->data->getWaterCode(i);
                    int quantity = x->data->getquantity(i);
                    
                    // Cộng chi phí nhập
                    chiphinhapTheoNgay += quantity * gianhapvao[waterCode];
                }
            }
            x = x->next;
        }

        return chiphinhapTheoNgay;
    }

const int& QuanLyDatNuoc::getChiPhiNhapTheoQuy(int quy, int year) {
    chiphinhapTheoNgay=0;
        // Kiểm tra quý hợp lệ
    if (quy < 1 || quy > 4) {
        cout << "Quý không hợp lệ. Vui lòng nhập từ 1 đến 4.\n";
        return chiphinhapTheoNgay;
    }
    // Xác định tháng bắt đầu và kết thúc của quý
    int thangBatDau = (quy - 1) * 3 + 1;
    int thangKetThuc = thangBatDau + 2;
        // Duyệt qua danh sách đơn đặt nước
        auto x = DanhSachdonDatNuoc.begin();
        while (x != nullptr) {
            string ngay = x->data->getNgayBan();

            if (year == 0 || stoi(ngay.substr(6, 4)) == year) {
            int thang = stoi(ngay.substr(3, 2)); // Lấy tháng từ chuỗi ngày

            // Kiểm tra tháng thuộc quý
            if (thang >= thangBatDau && thang <= thangKetThuc) {
                for (int i = 0; i < x->data->getNumberOfType(); i++) {
                    int waterCode = x->data->getWaterCode(i);
                    int quantity = x->data->getquantity(i);

                    // Cộng doanh thu
                    chiphinhapTheoNgay += quantity * gianhapvao[waterCode];
                }
            }
            
        }
        x = x->next;
    }   
    return chiphinhapTheoNgay;
}

