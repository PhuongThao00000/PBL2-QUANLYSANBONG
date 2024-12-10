#include "NHANVIEN.h"

    
    // Quản lý khách hàng
    // void NhanVien::themKhachHang(KhachHang* kh) {
    //     qlKhachHang.them(kh);
    // }

    // void NhanVien::xoaKhachHang(string sdt) {
    //     qlKhachHang.xoa(sdt);
    // }

    // void NhanVien::capNhatKhachHang(string sdt) {
    //     qlKhachHang.capnhat(sdt);
    // }

    // void NhanVien::timKiemKhachHang(string sdt) {
    //     qlKhachHang.timkiem(sdt);
    // }

    // // Quản lý đặt sân
    // void NhanVien::themDatSanLe(string sdt) {
    //     qlDatSan.themLe(sdt);
    // }

    // void NhanVien::themDatSanDinhKy(string sdt) {
    //     qlDatSan.themDinhKy(sdt);
    // }

    // void NhanVien::xoaDatSan(string sdt) {
    //     qlDatSan.xoa(sdt);
    // }

    // void NhanVien::capNhatDatSan(string sdt) {
    //     qlDatSan.capnhat(sdt);
    // }

    // // Quản lý hóa đơn
    // void NhanVien::themHoaDon(HoaDon* hd) {
    //     qlHoaDon.them(hd);
    // }

    // void NhanVien::xoaHoaDon(string sdt) {
    //     qlHoaDon.xoa(sdt);
    // }

    // void NhanVien::capNhatHoaDon(string sdt, string status) {
    //     qlHoaDon.capnhatTrangThai(sdt, status);
    // }

    // void NhanVien::thongKeDoanhThu(string ngay) {
    //     qlHoaDon.thongkeDoanhThuTheoNgayTuychon(qlDatNuoc); // Sử dụng thông tin từ QuanLyDatNuoc
    // }

    // Quản lý đặt nước
    void NhanVien::themDatNuoc(QuanLyDatNuoc&qldn){
        if (!isLoggedIn) {
        throw runtime_error("Nhân viên chưa đăng nhập! Không thể thêm đơn bán nước.");
    }
        qldn.them(getUsername());
    }

    DatNuoc* NhanVien::timkiemDatNuoc(QuanLyDatNuoc&qldn, const int& maDon){
        if (!isLoggedIn) {
        throw runtime_error("Nhân viên chưa đăng nhập! Không thể thực hiện tìm kiếm.");
    }
        
        return qldn.timkiem(maDon);
    }

    void NhanVien::capnhatDatNuoc(QuanLyDatNuoc&qldn, const int &maDon){
        if (!isLoggedIn) {
        throw runtime_error("Nhân viên chưa đăng nhập! Không thể sửa đơn bán nước.");
    }
        qldn.capnhat(maDon);
    }

    void NhanVien::xoaDatNuoc(QuanLyDatNuoc&qldn,const int &maDon){
        qldn.xoa(maDon);
    }

    void NhanVien::xuatDatNuocTheoNgay(QuanLyDatNuoc&qldn,int day, int month, int year){
        if (!isLoggedIn) {
        throw runtime_error("Khách hàng chưa đăng nhập! Không thể xóa sân.");
    }
        qldn.xuattheongay(day,month,year);
    }
    void NhanVien::xuatthongtin()const{
        User::xuatthongtin();
        cout << "Trạng thái hoạt động: "<<(DaDangNhap()==false?"Offline":"Online")<<endl;
    }

    void NhanVien::themDatXe(QuanLyDatXe&qldx){
        if (!isLoggedIn) {
        throw runtime_error("Nhân viên chưa đăng nhập! Không thể thêm đơn giữ xe.");
    }
        qldx.them(getUsername());
    }

    DatXe* NhanVien::timkiemDatXe(QuanLyDatXe&qldx, const int& maDon){
        if (!isLoggedIn) {
        throw runtime_error("Nhân viên chưa đăng nhập! Không thể thực hiện tìm kiếm.");
    }
        return qldx.timkiem(maDon);
    }

    void NhanVien::capnhatGiuXe(QuanLyDatXe&qldx,const int &maDon){
        if (!isLoggedIn) {
        throw runtime_error("Nhân viên chưa đăng nhập! Không thể sửa đơn bán nước.");
    }
        qldx.capnhat(maDon);
    }

    void NhanVien::xoaGiuXe(QuanLyDatXe&qldx,const int &maDon){
                qldx.xoa(maDon);
    }

    void NhanVien::xuatGiuXeTheoNgay(QuanLyDatXe&qldx,int day, int month, int year){
        qldx.xuattheongay(day,month,year);
    }

// void QuanLyNhanVien::XoaNhanVien(const string& sdt) {
//     auto x = danhSachNhanVien.begin();
//     while(x!=nullptr){
//         if(x->data->getSDT() == sdt){
//             delete x;
//             cout << "Nhan vien co sdt " << sdt << " da duoc xoa.\n";
//         }
        
//     }
// }
// for (int i = 0; i < danhSachNhanVien.getSize(); i++) {
//         if (danhSachNhanVien[i]->getID() == id) {
//             delete danhSachNhanVien[i];
//             danhSachNhanVien.remove(DanhSachNhanVien.find());
//             cout << 
//             return;
//         }
//     }
//     cout << "Khong tim thay nhan vien co ID: " << id << endl;