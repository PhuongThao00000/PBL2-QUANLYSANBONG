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
    "Đăng ký",
    "Đăng nhập",
    "Kết thúc"
};
//Sau khi đăng nhập thì loại người dùng nếu là nhân viên thì hiển thị hethong_nv
vector<string> hethong_nv={//nhan vien chi coi duoc cac don dat san theo ngay chu ko duoc them don dat san
    "Trang chủ",
    "Các đơn đặt sân theo ngày",
    "Thông tin tài khoản",
    "Đăng xuất"
};
//Sau khi đăng nhập thì loại người dùng nếu là quản lý thì hiển thị hethong_ql
vector<string> hethong_ql={
    "Trang chủ",
    "Các đơn đặt sân theo ngày",
    "Thêm lịch đặt",
    "Duyệt đơn",
    "Thông tin tài khoản",
    "Đăng xuất"
};

// nếu trong hethong_ql chọn trang chủ thì hiện trangchu_ql
vector<string> trangchu_ql = {
    "Trạng thái sân",
    "Dịch vụ (Bán nước, giữ xe)",
    "Quản lý kho",
    "Quản lý khách hàng",//them khach hang va xep hang thanh vien
    "Quản lý nhân viên",
    "Doanh thu và lợi nhuận",
    "Quay lại"
};
//trong trangchu của cả nhân viên và quản lý nếu chọn bán nước thì hiện Giao diện cho dịch vụ bán nước và giữ xe
vector<string> dichvu={
    "Thêm đơn bán nước",
    "Các đơn bán nước theo ngày",
    "Thêm vé giữ xe",
    "Các vé giữ xe theo ngày",
    "Quay lại"
};//nhập ngày cần xem sau khi xuất các đơn đặt nước thì tìm kiếm theo giờ 

//Sau khi chọn lựa chọn các đơn đặt nước hoặc giữ xe theo ngày thì yêu cầu khách hàng nhập ngày sau đó mới hiển tị menu cacdondichvutheongay
vector<string> cacdondichvutheongay={
    "Xóa",
    "Cập nhật",
    "Tìm kiếm",
    "Quay lại"
};

//Menu quản lý kho của quản lý
vector<string> quanlykho={
    "Trạng thái kho",
    "Nhập lô hàng",
    "Quay lại"
};

//Menu quản lý khách hàng của quản lý
vector<string> quanlykh={
    "Danh sách khách hàng",
    "Thêm khách hàng",
    "Quay lại"
};

//sau khi chọn danh sách khách hàng thì xuất thông tin các khách hàng và hiển thị menu danhsachkhachhang
vector<string> danhsachkhachhang={
    "Xóa khách hàng",
    "Cập nhật hạng khách hàng",
    "Tìm kiếm khách hàng",
    "Quay lại"
};

//Menu quản lý nhân viên của quản lý
vector<string> quanlynv={
    "Danh sách nhân viên",
    "Thêm nhân viên",
    "Quay lại"
};
vector<string> danhsachnhanvien={
    "Xóa nhân viên",
    "Cập nhật thông tin nhân viên",
    "Tìm kiếm nhân viên",
    "Quay lại"
};
//Menu doanh thu và lợi nhuận của quản lý
vector<string> doanhthu={
    "Thống kê ngày",
    "Thống kê tháng",
    "Thống kê quý",
    "Thống kê năm",
    "Quay lại"
};

// Giao diện menu trang chủ cho nhân viên
vector<string> trangchu_nhanvien = {
    "Trạng thái sân",
    "Dịch vụ (Bán nước, giữ xe)",
    "Thông tin tài khoản",
    "Đăng xuất"
};


// Giao diện menu chính cho khách hàng
vector<string> Mainmenu1 = {
    "Đặt lịch",
    "Thông tin tài khoản",
    "Các đơn đặt sân",
    "Đăng xuất"
};

//Sau khi khách hàng xem thông tin tài khoản thì mới hiển thị menu capnhatthongtintk
vector<string> capnhatthongtin={//áp dụng cho cả nhân viên, khách hàng và quản lý nhân viên của quản lý
    "Cập nhật username",
    "Cập nhật số điện thoại",
    "Cập nhật giới tính",
    "Cập nhật ngày sinh",
    "Đổi mật khẩu",
    "Quay lại"
};

vector<string> loaingdung={
    "Khách hàng",
    "Nhân viên",
    "Quản lý"
};


void clearScreen(){
    cout << "\033[2J\033[1;1H";  // Lệnh để xóa màn hình trên terminal
}


void DN(){
    cout << "\n================================" << endl;
    cout << "           Đăng nhập          " << endl;
    cout << "================================" << endl;
}

void DK(){
    cout << "\n================================" << endl;
    cout << "           Đăng ký            " << endl;
    cout << "================================" << endl;
}



// Hàm hiển thị menu và xử lý lựa chọn
int menuDangNhap(const vector<string>& menu) {
    int luaChon = 0; // Vị trí lựa chọn hiện tại
    const int len = menu.size();

    while (true) {
        clearScreen();
        cout << "==============================" << endl;
        cout << "    CHÀO MỪNG ĐẾN HỆ THỐNG    " << endl;
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
        cout << "~o~o~~Chào mừng đến với sân bóng đá Emiraté~~o~o~"<<endl;
        cout << "\n==============================" << endl;
        cout << "       Menu Khách hàng       " << endl;
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
        cout << "~o~o~~Chào mừng đến với sân bóng đá Emiraté~~o~o~"<<endl;
        cout << "\n==============================" << endl;
        cout << "       Menu Nhân viên         " << endl;
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
        cout << "~o~o~~Chào mừng đến với sân bóng đá Emiraté~~o~o~"<<endl;
        cout << "\n==============================" << endl;
        cout << "         Menu Quản lý         " << endl;
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
                cout << "Cảm ơn bạn đã sử dụng hệ thống!\n";
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
                    cout << "Nhập tên file chứa thông tin tài khoản (.txt): ";
                    cin>>fileName; // Đọc tên file từ bàn phím
                    // Tự động thêm đuôi .txt nếu chưa có
                    if (fileName.size() < 4 || fileName.substr(fileName.size() - 4) != ".txt") {
                        fileName += ".txt";
                    }
                    // Gọi hàm để đăng ký tài khoản từ file
                    qlnd.DangKyTuFile(fileName);

                    // Hiển thị danh sách tài khoản đã đăng ký
                    cout << "\nDanh sách tài khoản sau khi đăng ký:\n";
                    qlnd.HienThiDanhSach();
                    Continue();

                }
            }
            // Đăng nhập tài khoản
            if (choice == 1) {
                cin.ignore();
                cout << "Username: ";
                getline(cin, tenndung);
                cout << "Password(KHÔNG chứa dấu cách): ";
                cin >> mkhau;
                // qlnd.HienThiDanhSach();
                User* user = qlnd.DangNhapTaiKhoan(tenndung, mkhau);
                Continue();
                if (user == nullptr) {
                    cout << "Đăng nhập thất bại. Vui lòng thử lại!\n";
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
                                cout << "Nhập ngày muốn đặt sân: ";
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
                                else{ cout << "Khách hàng chưa có đơn đặt sân nào!\n";}
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
                                cout << "Nhập ngày muốn xem trạng thái sân: ";
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
                                cout << "Bạn có muốn cập nhật thông tin tài khoản không?(y/n)";
                                int i=_getch();
                                if(i=='n'||i=='N'){break;}
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
                                cout << "Nhập ngày muốn xem trạng thái sân: ";
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
    