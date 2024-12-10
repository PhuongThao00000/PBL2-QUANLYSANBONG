//#include "NHANVIEN_PARTTIME.h"
#include "QUANLY.h"
// #include <vector>
// #include <iostream>
// #include <stdexcept>
// #include <algorithm>
// #include <cctype>  
// #include <iomanip>

QuanLi::QuanLi(const string& username , const string& password ,const string& phonenumber,int gender, Date& ngsinh, int loaitk)
:NhanVien(username,password,phonenumber,gender,ngsinh,loaitk){}
// void QuanLi::themNhanVien(NhanVien* nv) {
//         qlNhanVien.them(nv);
//     }

//     void QuanLi::xoaNhanVien(string sdt) {
//         qlNhanVien.xoa(sdt);
//     }

//     void QuanLi::capNhatNhanVien(string sdt) {
//         qlNhanVien.capnhat(sdt);
//     }

//     void QuanLi::timKiemNhanVien(string sdt) {
//         qlNhanVien.timkiem(sdt);
//     }

    // Các phương thức quản lý khách hàng
    // void QuanLi::themKhachHang(KhachHang* kh) {
    //     qlKhachHang.them(kh);
    // }

    // void QuanLi::xoaKhachHang(string sdt) {
    //     qlKhachHang.xoa(sdt);
    // }

    // void QuanLi::capNhatKhachHang(string sdt) {
    //     qlKhachHang.capnhat(sdt);
    // }

    // void QuanLi::timKiemKhachHang(string sdt) {
    //     qlKhachHang.timkiem(sdt);
    // }

    // Các phương thức quản lý dịch vụ - Đặt sân
    // void QuanLi::themDatSanLe(string sdt) {
    //     qlDatSan.themLe(sdt);
    // }

    // void QuanLi::themDatSanDinhKy(string sdt) {
    //     qlDatSan.themDinhKy(sdt);
    // }

    // void QuanLi::xoaDatSan(string sdt) {
    //     qlDatSan.xoa(sdt);
    // }

    // void QuanLi::capNhatDatSan(string sdt) {
    //     qlDatSan.capnhat(sdt);
    // }

    // Các phương thức quản lý dịch vụ - Đặt nước
    // void QuanLi::themDatNuoc(string sdt) {
    //     qlDatNuoc.them(sdt);
    // }

    // void QuanLi::xoaDatNuoc(string sdt) {
    //     qlDatNuoc.xoa(sdt);
    // }

    // void QuanLi::capNhatDatNuoc(string sdt) {
    //     qlDatNuoc.capnhat(sdt);
    // }

    // // Các phương thức quản lý dịch vụ - Đặt xe
    // void QuanLi::themDatXe(string sdt) {
    //     qlDatXe.them(sdt);
    // }

    // void QuanLi::xoaDatXe(string sdt) {
    //     qlDatXe.xoa(sdt);
    // }

    // void QuanLi::capNhatDatXe(string sdt) {
    //     qlDatXe.capnhat(sdt);
    // }

    // // Các phương thức quản lý hóa đơn
    // void QuanLi::themHoaDon(HoaDon* hd) {
    //     qlHoaDon.them(hd);
    // }

    // void QuanLi::xoaHoaDon(string sdt) {
    //     qlHoaDon.xoa(sdt);
    // }

    // void QuanLi::capNhatHoaDon(string sdt, string status) {
    //     qlHoaDon.capnhatTrangThai(sdt, status);
    // }

    // void QuanLi::thongKeDoanhThu(string ngay) {
    //     qlHoaDon.thongkeDoanhThuTheoNgayTuychon(qlDatNuoc); // Thống kê doanh thu theo ngày/tháng/năm tùy chọn
    // }

    // Phương thức hiển thị thông tin thống kê
    // void thongKeDoanhThuTheoNgay(int day, int month, int year) {
    //     cout << "Doanh thu theo ngày " << day << "/" << month << "/" << year << ":\n";
    //     cout << "Doanh thu nước: " << qlDatNuoc.getDoanhThu() << endl;
    //     cout << "Doanh thu xe: " << qlDatXe.getDoanhThu() << endl;
    //     cout << "Doanh thu sân: " << qlDatSan.getDoanhThu() << endl;
    //     cout << "Tổng doanh thu: " << qlHoaDon.getDoanhThu() << endl;
    // }

    // Các phương thức hiển thị danh sách
    // void QuanLi::xuatDanhSachNhanVien() {
    //     qlNhanVien.xuat();
    // }

    // void QuanLi::xuatDanhSachKhachHang() {
    //     qlKhachHang.xuat();
    // }

    // void QuanLi::xuatDanhSachHoaDon() {
    //     qlHoaDon.xuat();
    // }

    // void QuanLi::xuatDanhSachDatSan() {
    //     qlDatSan.xuat();
    // }

    // void QuanLi::xuatDanhSachDatNuoc() {
    //     qlDatNuoc.xuat();
    // }

    // void QuanLi::xuatDanhSachDatXe() {
    //     qlDatXe.xuat();
    // }

// string QuanLi::toLowerString(const string& str) const {
//     string lowerStr = str;
//     transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), [](unsigned char c) {
//         return std::tolower(c);
//     });
//     return lowerStr;
// }

// QuanLi::~QuanLi() {
//     nhansu.~LINKLIST();
// }

// void QuanLi::ThemNV(NhanVien* nv) {
//     for (const auto& x : nhansu) {
//         if (toLowerString(x.data->getSDT()) == toLowerString(nv->getSDT())) {
//             throw invalid_argument("Duplicate employee ID");  // Prevent adding duplicate IDs
//         }
//     }
//     nhansu.addLast(nv);  
// }

// void QuanLi::nhap_dltruoc() {
//     try {
//         ThemNV(new NhanVien("01", "Nguyen Van A", "0123568749", "01/11/2024", 1800000, 3.0, 5));
//         ThemNV(new NhanVien("02", "Nguyen Van B", "0554789962", "02/10/2024", 1800000, 3.0, 5));
//         ThemNV(new NhanVien("03", "Nguyen Van C", "0187456921", "25/10/2024", 1800000, 3.0, 5));
//         ThemNV(new NhanVien("04", "Tran Thi D", "0958746321", "21/09/2024", 1800000, 3.0, 5));
//         ThemNV(new NhanVien("05", "Le Van NC", "0165874952", "15/08/2024", 1800000, 3.0, 5));         
//     } catch (const invalid_argument& e) {
//         cout << "Error: " << e.what() << endl;
//     }
// }

// void QuanLi::nhap_dlngoai() {
//     do {
//         NhanVien* nv = nullptr;
//         try {
//             nv = new NhanVien();  
//             cin >> *nv; 
//             ThemNV(nv); 
//         } 
//         catch(const std::invalid_argument& e) {
//             cout << "Loi: " << e.what() << endl;
//             delete nv;  
//             nv = nullptr;
//             continue;
//         }
//         cout << "Ban muon nhap them nhan vien? (Y/N): ";
//         char opt;
//         cin >> opt;
//         if (opt != 'y' && opt != 'Y') {
//             break;
//         }
//     } while (true);
// }

// void QuanLi::HienThiThongTin() {
//     cout << "Nhan Vien Part Time " << endl;
//     cout << setw(10) << "ID" << setw(20) << "Ho ten" << setw(15) <<"So Dien Thoai" 
//          << setw(15) <<"Ngay bat dau" << setw(15) <<"Luong can ban" << setw(15) 
//          << "So gio lam" << setw(15) <<" He so luong" << setw(10) << endl;
    
//     for (const auto &x : nhansu) {
//         auto nhanvien = x.data;//
//         if (dynamic_cast<NhanVien_PartTime*>(nhanvien)) {
//             nhanvien->Xuat();// 
//         }
//     }
// }

// void QuanLi::tongLuong() {
//     double TL = 0;
//     for (const auto& x : nhansu) {
//         auto nhanvien = x.data;
//         TL += nhanvien->getLuongCanBan();  
//     }
//     cout << "Tong tien luong la: " << TL << endl;
// }

// void QuanLi::demSoLuong() {
//     int year;
//     cout << "Nhap so nam ban muon: ";
//     cin >> year;
//     int count = 0;
//     for (const auto& x : nhansu) {
//         auto nhanvien = x.data;
//         int years = stoi(nhanvien->getNgayVaoLam().substr(6,4));
//         if (years == year) {
//             count++;
//         }
//     }
//     cout << "So luong nhan vien vao trong nam: " << count << endl;
// }

// void QuanLi::CapNhatTime(const string& id, int new_hours) {
//     for (auto& x : nhansu) {
//         auto nhanvien = x.data;
//         NhanVien_PartTime* ptx = dynamic_cast<NhanVien_PartTime*>(nhanvien);
//         if (ptx != nullptr && toLowerString(ptx->getID()) == toLowerString(id)) {
//             ptx->CapNhatTime(new_hours);  // Update working hours for the employee
//             return;
//         }
//     }
//     throw invalid_argument("Nhan vien khong tim thay! ");  // Throw an error if the employee ID is not found
// }

// void QuanLi::sapXep() {
//     sort(nhansu.begin(), nhansu.end(), [](NhanVien* a, NhanVien* b) {
//         int day_a = stoi(a->getNgayVaoLam().substr(0,2));
//         int month_a = stoi(a->getNgayVaoLam().substr(3,2));
//         int year_a = stoi(a->getNgayVaoLam().substr(6,4));

//         int day_b = stoi(b->getNgayVaoLam().substr(0,2));
//         int month_b = stoi(b->getNgayVaoLam().substr(3,2));
//         int year_b = stoi(b->getNgayVaoLam().substr(6,4));

//         if (year_a != year_b) return year_a > year_b;
//         if (month_a != month_b) return month_a > month_b;
//         return day_a > day_b;        
//     });
//     HienThiThongTin();
// }

// void QuanLi::Xoa() {
//     do {
//         string id;
//         cout << "Nhap ID cua nhan vien can xoa: ";
//         cin >> id;
//         id = toLowerString(id);  // Convert input to lowercase

//         auto it = std::find_if(nhansu.begin(), nhansu.end(),
//         [this, &id](NhanVien* x) {
//             return toLowerString(x->getID()) == id;
//         });

//         if (it != nhansu.end()) {
//             cout << "Ban co chac chan muon xoa nhan vien voi ID " << (*it)->getID() << "? (Y/N): ";
//             char opt;
//             cin >> opt;
//             if (opt == 'y' || opt == 'Y') {
//                 delete it;  // Delete the employee
//                 nhansu.remove(it);  // Remove from the vector
//                 cout << "Nhan vien voi ID da duoc xoa." << endl;
//             } else {
//                 cout << "Nhan vien voi ID " << id << "khong bi xoa." << endl;
//             }
//         } else {
//             cout << "Khong tim thay nhan vien voi ID " << id << "." << endl;
//         }

//         cout << "Ban co muon tiep tuc xoa nhan vien khac khong? (Y/N): ";
//         char opt;
//         cin >> opt;
//         if (opt != 'y' && opt != 'Y') {
//             break;
//         }
//     } while (true);
// };
