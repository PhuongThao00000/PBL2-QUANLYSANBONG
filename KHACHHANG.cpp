
#include "KHACHHANG.h"


#include <algorithm>

#include <iomanip>
#include <iostream>
using namespace std;

KhachHang::KhachHang() : User(),rankMember(4){}

KhachHang::KhachHang(const string& username,const string& password,const string& phonenumber,int gender, Date& ngsinh,int rankmember,int loaitaikhoan)
    :User(username,password,phonenumber,gender,ngsinh,loaitaikhoan),rankMember(rankmember){
}

KhachHang::KhachHang(const KhachHang* kh){
    if(this!=kh){
        username=kh->username;
        password = kh->password;
        isLoggedIn=kh->isLoggedIn;
        sdt = kh->sdt;
        gioitinh = kh->gioitinh;
        ngaysinh=kh->ngaysinh;
        rankMember=kh->rankMember;
    }
}

DatSan* KhachHang::timkiem(QuanLyDatSan&qlds){
    if (!isLoggedIn) {
        throw runtime_error("Khách hàng chưa đăng nhập! Không thể thực hiện tìm kiếm.");
    }
    return qlds.timkiem(getSDT());
}

void KhachHang::themDonDatsanLe(QuanLyDatSan&qlds){
    if (!isLoggedIn) {
        throw runtime_error("Khách hàng chưa đăng nhập! Không thể thêm đơn đặt sân định kỳ.");
    }
    qlds.themLe(getSDT());
}
// void KhachHang::themDonDatsanDinhKy(QuanLyDatSan&qlds){
//     if (!isLoggedIn) {
//         throw runtime_error("Khách hàng chưa đăng nhập! Không thể thêm đơn đặt sân định kỳ.");
//     }
//     qlds.themDinhKy(getSDT());
// }// phương thức này dành cho quản lý
void KhachHang::suaDonDatsan(QuanLyDatSan&qlds){
    if (!isLoggedIn) {
        throw runtime_error("Khách hàng chưa đăng nhập! Không thể sửa đơn đặt sân.");
    }
    qlds.capnhat(getSDT());
}

void KhachHang::xuatDonDatsan(QuanLyDatSan&qlds){
    if (!isLoggedIn) {
        throw runtime_error("Khách hàng chưa đăng nhập! Không thể xuất thông tin đơn đặt sân.");
    }
    qlds.xuattheosdt(getSDT());
}

void KhachHang::xoaSan(QuanLyDatSan& qlds) {
    if (!isLoggedIn) {
        throw runtime_error("Khách hàng chưa đăng nhập! Không thể xóa sân.");
    }
    qlds.xoa(getSDT());
}

