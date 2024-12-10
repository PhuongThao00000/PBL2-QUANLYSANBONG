#include "QuanLy.h"
#include <iostream>

using namespace std;

// Constructor
QuanLi::QuanLi(const string& username, const string& password, const string& phonenumber, int gender, Date& ngsinh, int loaitk)
    : NhanVien(username, password, phonenumber, gender, ngsinh, loaitk) {}

// Các phương thức quản lý nhân viên
void QuanLi::themNhanVien(NhanVien* nv) {
    // Kiểm tra nhân viên hợp lệ và thêm vào danh sách
    cout << "Them nhan vien: " << nv->getUsername() << endl;
    // Ví dụ giả sử bạn có một danh sách nhân viên để lưu trữ:
    // qlNhanVien.them(nv);
}

void QuanLi::xoaNhanVien(string sdt) {
    // Tìm và xóa nhân viên theo số điện thoại
    cout << "Xoa nhan vien voi so dien thoai: " << sdt << endl;
    // qlNhanVien.xoa(sdt);
}

void QuanLi::capNhatNhanVien(string sdt) {
    // Cập nhật thông tin nhân viên theo số điện thoại
    cout << "Cap nhat thong tin nhan vien voi so dien thoai: " << sdt << endl;
    // qlNhanVien.capnhat(sdt);
}

NhanVien* QuanLi::timKiemNhanVien(string sdt) {
    // Tìm nhân viên theo số điện thoại
    cout << "Tim nhan vien voi so dien thoai: " << sdt << endl;
    // return qlNhanVien.timkiem(sdt);
    return nullptr; // Placeholder
}

void QuanLi::xuatDanhSachNV(QuanLyNV& qlnv) {
    cout << "Xuat danh sach nhan vien." << endl;
    // qlnv.xuat();
}

// Các phương thức quản lý khách hàng
void QuanLi::themKhachHang(KhachHang* kh) {
    cout << "Them khach hang: " << kh->getUsername() << endl;
    // qlKhachHang.them(kh);
}

void QuanLi::xoaKhachHang(QuanLyKH& qlkh, string sdt) {
    cout << "Xoa khach hang voi so dien thoai: " << sdt << endl;
    // qlKhachHang.xoa(sdt);
}

void QuanLi::capNhatKhachHang(QuanLyKH& qlkh, string sdt) {
    cout << "Cap nhat thong tin khach hang voi so dien thoai: " << sdt << endl;
    // qlKhachHang.capnhat(sdt);
}

KhachHang* QuanLi::timKiemKhachHang(QuanLyKH& qlkh, string sdt) {
    cout << "Tim khach hang voi so dien thoai: " << sdt << endl;
    // return qlKhachHang.timkiem(sdt);
    return nullptr; // Placeholder
}

void QuanLi::xuatDanhSachKH(QuanLyKH& qlkh) {
    cout << "Xuat danh sach khach hang." << endl;
    // qlKhachHang.xuat();
}

// Các phương thức quản lý dịch vụ - Đặt sân
void QuanLi::themDatSanLe(QuanLyDatSan& qlds) {
    cout << "Them don dat san le." << endl;
    // qlds.themLe(getUsername());
}

void QuanLi::themDatSanDinhKy(QuanLyDatSan& qlds) {
    cout << "Them don dat san dinh ky." << endl;
    // qlds.themDinhKy(getUsername());
}

void QuanLi::xoaDatSan(QuanLyDatSan& qlds) {
    cout << "Xoa don dat san." << endl;
    // qlds.xoa(getUsername());
}

void QuanLi::capNhatDatSan(QuanLyDatSan& qlds) {
    cout << "Cap nhat don dat san." << endl;
    // qlds.capnhat(getUsername());
}

void QuanLi::xuatDanhSachDatSan(QuanLyDatSan& qlds) {
    cout << "Xuat danh sach dat san." << endl;
    // qlds.xuat();
}

// Các phương thức hiển thị danh sách
void QuanLi::xuatDanhSachNhanVien() {
    cout << "Xuat danh sach nhan vien." << endl;
    // qlNhanVien.xuat();
}

void QuanLi::xuatDanhSachKhachHang() {
    cout << "Xuat danh sach khach hang." << endl;
    // qlKhachHang.xuat();
}

void QuanLi::xuatDanhSachHoaDon() {
    cout << "Xuat danh sach hoa don." << endl;
    // qlHoaDon.xuat();
}

void QuanLi::xuatDanhSachDatSan() {
    cout << "Xuat danh sach dat san." << endl;
    // qlDatSan.xuat();
}

void QuanLi::xuatDanhSachDatNuoc() {
    cout << "Xuat danh sach dat nuoc." << endl;
    // qlDatNuoc.xuat();
}

void QuanLi::xuatDanhSachDatXe() {
    cout << "Xuat danh sach dat xe." << endl;
    // qlDatXe.xuat();
}
