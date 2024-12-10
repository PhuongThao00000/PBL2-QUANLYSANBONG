#include "QuanLyNDung.h"
#include "QuanLyNDung.cpp"
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <limits>

using namespace std;


// Giao diện menu
vector<string> dangnhap = {
    "DANG KY",
    "DANG NHAP",
    "THOAT"
};
//Sau khi đăng nhập thì loại người dùng nếu là nhân viên thì hiển thị hethong_nv
vector<string> hethong_nv={//nhan vien chi coi duoc cac don dat san theo ngay chu ko duoc them don dat san
    "TRANG CHU",
    "CAC DON DAT SAN THEO NGAY",
    "THONG TIN TAI KHOAN",
    "DANG XUAT"
};
//Sau khi đăng nhập thì loại người dùng nếu là quản lý thì hiển thị hethong_ql
vector<string> hethong_ql={
    "TRANG CHU",
    "CAC DON DAT SAN THEO NGAY",
    "THEM LICH DAT SAN",
    "DUYET DON",
    "THONG TIN TAI KHOAN",
    "DANG XUAT"
};

// nếu trong hethong_ql chọn trang chủ thì hiện trangchu_ql
vector<string> trangchu_ql = {
    "TRANG THAI SAN",
    "DICH VU (BAN NUOC, GIU XE)",
    "QUAN LY KHO",
    "QUAN LY KHACH HANG", //them khach hang va xep hang thanh vien
    "QUAN LY NHAN VIEN",
    "DOANH THU VA LOI NHAN",
    "QUAY LAI"

};
//trong trangchu của cả nhân viên và quản lý nếu chọn bán nước thì hiện Giao diện cho dịch vụ bán nước và giữ xe
vector<string> dichvu={
    "THEM DON BAN NUOC",
    "CAC DON BAN NUOC THEO NGAY",
    "THEM VE GIU XE",
    "CAC VE GIU XE THEO NGAY",
    "QUAY LAI"
};//nhập ngày cần xem sau khi xuất các đơn đặt nước thì tìm kiếm theo giờ 

//Sau khi chọn lựa chọn các đơn đặt nước hoặc giữ xe theo ngày thì yêu cầu khách hàng nhập ngày sau đó mới hiển tị menu cacdondichvutheongay
vector<string> cacdondichvutheongay={
    "XOA",
    "CAP NHAT",
    "TIM KIEM",
    "QUAY LAI"

};

//Menu quản lý kho của quản lý
vector<string> quanlykho={
    "TRANG THAI KHO",
    "NHAP LO HANG",
    "QUAY LAI"

};

//Menu quản lý khách hàng của quản lý
vector<string> quanlykh={
    "DANH SACH KHACH HANG",
    "THEM KHACH HANG",
    "QUAY LAI"

};

//sau khi chọn danh sách khách hàng thì xuất thông tin các khách hàng và hiển thị menu danhsachkhachhang
vector<string> danhsachkhachhang={
    "XOA KHACH HANG",
    "CAP NHAT HANG KHACH HANG",
    "TIM KIEM KHACH HANG",
    "QUAY LAI"

};

//Menu quản lý nhân viên của quản lý
vector<string> quanlynv={
    "DANH SACH NHAN VIEN",
    "THEM NHAN VIEN",
    "QUAY LAI"

};
vector<string> danhsachnhanvien={
   "XOA NHAN VIEN",
   "CAP NHAT THONG TIN NHAN VIEN",
   "TIM KIEM NHAN VIEN",
   "QUAY LAI"

};
//Menu doanh thu và lợi nhuận của quản lý
vector<string> doanhthu={
    "THONG KE NGAY",
    "THONG KE THANG",
    "THONG KE QUA",
    "THONG KE NAM",
    "QUAY LAI"

};

// Giao diện menu trang chủ cho nhân viên
vector<string> trangchu_nhanvien = {
    "TRANG THAI SAN",
    "DICH VU (BAN NUOC, GIU XE)",
    "THONG TIN TAI KHOAN",
    "DANG XUAT"

};


// Giao diện menu chính cho khách hàng
vector<string> Mainmenu1 = {
    "DAT LICH",
    "THONG TIN TAI KHOAN",
    "CAC DON DAT SAN",
    "DANG XUAT"

};

//Sau khi khách hàng xem thông tin tài khoản thì mới hiển thị menu capnhatthongtintk
vector<string> capnhatthongtin={//áp dụng cho cả nhân viên, khách hàng và quản lý nhân viên của quản lý
    "CAP NHAT USERNAME",
    "CAP NHAT SO DIEN THOAI",
    "CAP NHAT GIOI TINH",
    "CAP NHAT NGAY SINH",
    "DOI MAT KHAU",
    "QUAY LAI"

};

vector<string> loaingdung={
    "KHACH HANG",
    "NHAN VIEN",
    "QUAN LY"

};


void clearScreen(){
    cout << "\033[2J\033[1;1H";  // Lệnh để xóa màn hình trên terminal
}


void DN(){
    cout << "\n================================" << endl;
    cout << "           DANG NHAP           " << endl;
    cout << "================================" << endl;
}

void DK(){
    cout << "\n================================" << endl;
    cout << "           DANG KY            " << endl;
    cout << "================================" << endl;
}



// Hàm hiển thị menu và xử lý lựa chọn
int menuDangNhap(const vector<string>& menu) {
    int luaChon = 0; // Vị trí lựa chọn hiện tại
    const int len = menu.size();

    while (true) {
        clearScreen();
        cout << "==============================" << endl;
        cout << "    CHAO MUNG DEN VOI HE THONG    " << endl;
        cout << "==============================" << endl;
        for (int i = 0; i < len; i++) {
            if (i == luaChon)
                cout << ">> " << menu[i] << " <<\n"; // Hiển thị lựa chọn hiện tại
            else
                cout << "   " << menu[i] << "\n";
        }

        // Xử lý phím nhập
        int phim = _getch(); // Lấy mã phím
        if (phim == 224) {   // Phím mũi tên
            phim = _getch();
            if (phim == 72) { // Mũi tên lên
                luaChon = (luaChon - 1 + len) % len; // Di chuyển lên, vòng lại cuối danh sách
            } else if (phim == 80) { // Mũi tên xuống
                luaChon = (luaChon + 1) % len; // Di chuyển xuống, vòng lại đầu danh sách
            }
        } else if (phim == 13) { // Phím Enter
            return luaChon; // Trả về lựa chọn hiện tại
        }
    }
}


// Hàm hiển thị menu và xử lý lựa chọn
int menuKhachHang(const vector<string>& menu) {
    int luaChon = 0; // Vị trí lựa chọn hiện tại
    const int len = menu.size();

    while (true) {
        clearScreen();
        cout << "~o~o~~CHAO MUNG DEN VOI SAN BONG DA EMIRATE~~o~o~"<<endl;
        cout << "\n==============================" << endl;
        cout << "           BANG LUA CHON       " << endl;
        cout << "==============================" << endl;
        
        for (int i = 0; i < len; i++) {
            if (i == luaChon)
                cout << ">> " << menu[i] << " <<\n"; // Hiển thị lựa chọn hiện tại
            else
                cout << "   " << menu[i] << "\n";
        }

        // Xử lý phím nhập
        int phim = _getch(); // Lấy mã phím
        if (phim == 224) {   // Phím mũi tên
            phim = _getch();
            if (phim == 72) { // Mũi tên lên
                luaChon = (luaChon - 1 + len) % len; // Di chuyển lên, vòng lại cuối danh sách
            } else if (phim == 80) { // Mũi tên xuống
                luaChon = (luaChon + 1) % len; // Di chuyển xuống, vòng lại đầu danh sách
            }
        } else if (phim == 13) { // Phím Enter
            return luaChon; // Trả về lựa chọn hiện tại
        }
    }
}

// Hàm hiển thị menu và xử lý lựa chọn
int menuNhanVien(const vector<string>& menu) {
    int luaChon = 0; // Vị trí lựa chọn hiện tại
    const int len = menu.size();

    while (true) {
        clearScreen();
        cout << "~o~o~~CHAO MUNG DEN VOI SAN BONG DA EMIRATE~~o~o~"<<endl;
        cout << "\n==============================" << endl;
        cout << "       BANG LUA CHON         " << endl;
        cout << "==============================" << endl;
        
        for (int i = 0; i < len; i++) {
            if (i == luaChon)
                cout << ">> " << menu[i] << " <<\n"; // Hiển thị lựa chọn hiện tại
            else
                cout << "   " << menu[i] << "\n";
        }

        // Xử lý phím nhập
        int phim = _getch(); // Lấy mã phím
        if (phim == 224) {   // Phím mũi tên
            phim = _getch();
            if (phim == 72) { // Mũi tên lên
                luaChon = (luaChon - 1 + len) % len; // Di chuyển lên, vòng lại cuối danh sách
            } else if (phim == 80) { // Mũi tên xuống
                luaChon = (luaChon + 1) % len; // Di chuyển xuống, vòng lại đầu danh sách
            }
        } else if (phim == 13) { // Phím Enter
            return luaChon; // Trả về lựa chọn hiện tại
        }
    }
}

int menuQuanLy(const vector<string>& menu) {
    int luaChon = 0; // Vị trí lựa chọn hiện tại
    const int len = menu.size();

    while (true) {
        clearScreen();
        cout << "~o~o~~CHAO MUNG DEN VOI SAN BONG DA EMIRATE~~o~o~"<<endl;
        cout << "\n==============================" << endl;
        cout << "         BANG LUA CHON         " << endl;
        cout << "==============================" << endl;
        
        for (int i = 0; i < len; i++) {
            if (i == luaChon)
                cout << ">> " << menu[i] << " <<\n"; // Hiển thị lựa chọn hiện tại
            else
                cout << "   " << menu[i] << "\n";
        }

        // Xử lý phím nhập
        int phim = _getch(); // Lấy mã phím
        if (phim == 224) {   // Phím mũi tên
            phim = _getch();
            if (phim == 72) { // Mũi tên lên
                luaChon = (luaChon - 1 + len) % len; // Di chuyển lên, vòng lại cuối danh sách
            } else if (phim == 80) { // Mũi tên xuống
                luaChon = (luaChon + 1) % len; // Di chuyển xuống, vòng lại đầu danh sách
            }
        } else if (phim == 13) { // Phím Enter
            return luaChon; // Trả về lựa chọn hiện tại
        }
    }
}

// Hàm hiển thị menu và xử lý lựa chọn
int GeneralMenu(const vector<string>& menu) {
    int luaChon = 0; // Vị trí lựa chọn hiện tại
    const int len = menu.size();

    while (true) {
        clearScreen();
        for (int i = 0; i < len; i++) {
            if (i == luaChon)
                cout << ">> " << menu[i] << " <<\n"; // Hiển thị lựa chọn hiện tại
            else
                cout << "   " << menu[i] << "\n";
        }

        // Xử lý phím nhập
        int phim = _getch(); // Lấy mã phím
        if (phim == 224) {   // Phím mũi tên
            phim = _getch();
            if (phim == 72) { // Mũi tên lên
                luaChon = (luaChon - 1 + len) % len; // Di chuyển lên, vòng lại cuối danh sách
            } else if (phim == 80) { // Mũi tên xuống
                luaChon = (luaChon + 1) % len; // Di chuyển xuống, vòng lại đầu danh sách
            }
        } else if (phim == 13) { // Phím Enter
            return luaChon; // Trả về lựa chọn hiện tại
        }
    }
}

void Continue(){
    cout << "......Enter để tiếp tục\n";
    getch();
}

vector<string> dangky={
    "Đọc từ file",
    "Nhập từ bàn phím"
};

int main() {

    QuanLyNDung qlnd;
    QuanLyDatSan qlds;
    QuanLyDatNuoc qldn;
    QuanLyDatXe qlgx;
    int choice;
    string tenndung, mkhau, sdt;
    Date ngsinh;
    int gender;
        while (true) {
            choice=menuDangNhap(dangnhap);
            if (choice == 2) { // Quay lại loại người dùng
                cout << "CAM ON VI DA SU DUNG HE THONG!\n";
                return 0;
            }
            // Đăng ký tài khoản
            if (choice == 0) {
                int ff;
                ff=GeneralMenu(dangky);
                if(ff==1){
                    int Usertype;
                    Usertype=GeneralMenu(loaingdung);
                    QuanLyNDung::SetTenNguoiDung(tenndung);
                    QuanLyNDung::SetPassWord(mkhau);
                    QuanLyNDung::SetSoDienThoai(sdt);
                    cout << "Birth date ";
                    ngsinh.SetNgay();
                    QuanLyNDung::SetGioiTinh(gender);

                    if (qlnd.DangKyTaiKhoan(tenndung, mkhau, sdt, gender, ngsinh, Usertype)) {
                        cout << "Tai khoan da duoc tao thanh cong.\n";
                        Continue();
                        continue;
                    } else {
                        cout << "Dang ky that bai.\n";
                        Continue();
                        continue;
                    }
                } else if(ff==0){
                    string fileName;
                    cout << "Nhap file du lieu: (.txt): ";
                    cin>>fileName; // Đọc tên file từ bàn phím
                    // Tự động thêm đuôi .txt nếu chưa có
                    if (fileName.size() < 4 || fileName.substr(fileName.size() - 4) != ".txt") {
                        fileName += ".txt";
                    }
                    // Gọi hàm để đăng ký tài khoản từ file
                    qlnd.DangKyTuFile(fileName);

                    // Hiển thị danh sách tài khoản đã đăng ký
                    cout << "\nDanh sach tai khoan sau khi dang ky:\n";
                    qlnd.HienThiDanhSach();
                    Continue();

                }
            }
            // Đăng nhập tài khoản
            if (choice == 1) {
                cin.ignore();
                cout << "Username: ";
                getline(cin, tenndung);
                cout << "Password(KHONG chua dau cach): ";
                cin >> mkhau;
                // qlnd.HienThiDanhSach();
                User* user = qlnd.DangNhapTaiKhoan(tenndung, mkhau);
                Continue();
                if (user == nullptr) {
                    cout << "Dang nhap that bai. Vui long thu lai!\n";
                    Continue();
                    continue;
                }

                // Xử lý sau khi đăng nhập thành công
                //1) KHÁCH HÀNG
                if (dynamic_cast<KhachHang*>(user)) {
                    KhachHang* kh = static_cast<KhachHang*>(user);

                    while (true) {
                        choice=menuKhachHang(Mainmenu1);
                        switch(choice){
                            case 0:// Đặt lịch lẻ còn nếu muốn đặt cố định phải để cho quản lý đặt sân
                            { 
                                Date ngaydat;
                                cout << "Nhap ngay muon dat san: ";
                                ngaydat.SetNgay();
                                qlds.TrangThaiSanTheoNgay(ngaydat);
                                kh->themDonDatsanLe(qlds);
                                break;
                            }
                            case 1:// Xem thông tin tài khoản
                            {
                                kh->xuatthongtin();
                                Continue();
                                break;
                            }
                            case 2:
                            {
                                DatSan* ds = qlds.timkiem(kh->getSDT());
                                if(ds!=nullptr){
                                    ds->xuat();
                                }
                                else{ cout << "Khach hang chua co don dat san nao!\n";}
                                Continue();
                                break;
                            }
                        }
                            if(choice==3)
                            {
                                qlnd.DangXuatTaiKhoan();
                                Continue();
                                break;
                            }

                         
                    }
                } 
                //2) NHÂN VIÊN
                else if (dynamic_cast<NhanVien*>(user)) {
                    NhanVien* nv = static_cast<NhanVien*>(user);
                    while (true) {
                        choice=menuNhanVien(hethong_nv);
                        switch(choice){
                            case 0:
                            {
                                Date ngaydat;
                                cout << "Nhap ngay muon xem trang thai san: ";
                                ngaydat.SetNgay();
                                qlds.TrangThaiSanTheoNgay(ngaydat);
                                break;
                            }
                            case 1:
                            {
                                nv->themDatNuoc(qldn);
                                break;
                            }
                            case 2:
                            {
                                nv->xuatthongtin();
                                cout << "Ban co muon cap nhat thong tin tai khoan?(C/K)";
                                int i=_getch();
                                if(i=='k'||i=='K'){break;}
                            }
                        }
                        if (choice == 3) { // Go back
                            qlnd.DangXuatTaiKhoan();
                            break;
                        } 
                    }
                } 
                //3)QUẢN LÝ
                else if (dynamic_cast<QuanLi*>(user)) {
                    QuanLi* ql = static_cast<QuanLi*>(user);

                    while (true) {
                        choice=menuQuanLy(hethong_ql);
                        switch(choice){
                            case 0:
                            {
                                Date ngaydat;
                                cout << "Nhap ngay muon xem trang thai san: ";
                                ngaydat.SetNgay();
                                qlds.TrangThaiSanTheoNgay(ngaydat);
                                break;
                            }
                            case 1:
                            {
                                ql->themDatNuoc(qldn);
                                break;
                            }
                            case 2:
                            {
                                break;
                            }
                            case 3:
                            {
                                break;
                            }
                            case 4:
                            {
                                break;
                            }
                        } if(choice==5){
                            qlnd.DangXuatTaiKhoan();
                            break;
                        }
                    }
                }
                
            }
        }
    
    return 0;
}
    
