#include "QuanLyDatSan.h"
#include <iostream>
using namespace std;
#include <conio.h>

void QuanLyDatSan::setTenSan(string& sandat){
    bool t = true;
    string tensan;
    do{
    cout << "Nhap ten san:";
    cin >> tensan;
    if(tensan != "51" && tensan != "52" && tensan != "53" && tensan != "71" && tensan != "72"){
        t = false;
        cout << "Ten san khong hop le!\n";
    }
    else{t=true;}
    }while(t == false);
    sandat = tensan;
}

void QuanLyDatSan::themLe(string sdtkh){
    // if(timkiem(sdtkh)==nullptr){
    //     cout << "Don dat san so "<<sdtkh<<" da ton tai! Khong the them\n";
    //     return;
    // }
    
    int status;
    Date ngaydat; 
    cout << "\nTHÔNG TIN ĐƠN ĐẶT SÂN:\n";
    cout <<"Nhập ngày đặt sân: ";
    ngaydat.SetNgay();
    DatSan *ds = new DatSan(sdtkh,ngaydat.GetNgay());
    while(true){
    pair<string,int>sanvagio;
        while(true){
            setTenSan(sanvagio.first);
            setGioSan(sanvagio.second);
            if(IsEmpty(ngaydat,sanvagio.first,sanvagio.second)==true){
            ds->themSanVaGio(sanvagio);
            break;
            }
            else{ 
                cout << "Sân "<<sanvagio.first<<": "<< sanvagio.second<<" đã có người đặt\n"; 
                continue;
                }
        }
        cout<<"Sân "<<ds->getSanDatODau()<<": "<< ds->getGioDat(ds->getGioDatODau())<<endl;
        cout<< "Bạn có muốn chọn thêm sân và khung giờ khác trong hôm nay " << ds->getNgayDat()<<" không?\n";
        cout<<"Nhấn c để tiếp tục chọn\n";
        int i = _getch();
        if(i =='c'||i=='C'){
            continue;
        }
        else{break;}
        }
    ds->setDangKH(false); 
    cout << "Don dat san so "<<sdtkh<<" dat thanh cong!\n";
    ds->setTongTien();
    cout << "Tong tien can thanh toan: "<<ds->getTongTien()<<endl;
    status = 0;
    cout << "Tinh trang: "<<(status == 0 ? "Chua thanh toan" : "Da thanh toan")<<endl;
    ds->setTrangThaiTT(status);
    DanhSachDatSan.addFirst(ds);  
}

bool QuanLyDatSan::IsEmpty(const Date& ngaydat,const string& tensan, const int& giosan){
        auto current=DanhSachDatSan.begin();
        while(current!=nullptr){
            if(current->data->getNgayDat()==ngaydat.GetNgay()){
                LINKLIST<pair<string, int>>& sanVaGio = current->data->getSanVaGio();
                // if (sanVaGio.begin() == nullptr) {
                //     continue; // Bỏ qua nếu danh sách rỗng
                // }
                auto datsan=sanVaGio.begin();
                while(datsan!=sanVaGio.end()){
                // Kiểm tra sân và giờ đã đặt
                    if(datsan->data.first==tensan && datsan->data.second==giosan){
                        return false;
                    }
                    datsan=datsan->next;
                }
            }
            current=current->next;
        }
    return true;
}

// void QuanLyDatSan::TrangThaiSanTheoNgay(const Date& ngayDat) {
//     cout << "Trạng thái sân vào ngày " << ngayDat.GetNgay() << ":\n";

//     // Duyệt qua tất cả các tên sân và khung giờ để kiểm tra trống
//     for (const auto& san : tensan) {
//         bool isSanTrung = false;
//         cout << "Sân " << san << ":\n";
//         for (const auto& gio : giosan) {
//             isSanTrung = false;
//             for (auto ds : DanhSachDatSan) {
//                 if (ds.data->getNgayDat() == ngayDat.GetNgay() && ds.data->getSanDat() == san && ds.data->getGioDat() == gio) {
//                     isSanTrung = true;
//                     break;
//                 }
//             }
//             if (!isSanTrung) {
//                 cout << "- Khung giờ: " << gio << endl;
//             }
//         }
//     }
// }

void QuanLyDatSan::bangGia(){
    cout << endl;
    cout << "_____________________________________________________\n";
    cout <<"|               BẢNG GIÁ SÂN CHI TIẾT(vnd)            |\n";
    cout <<"|_____________________________________________________|\n";
    cout <<"|    Sân    |     Buổi sáng     |      Buổi chiều     |\n";
    cout <<"|___________|__(5:30 - 10:30)___|____(15:00 - 22:00)__|\n";
    cout <<"|     5     |      270.000      |       300.000       |\n";
    cout <<"|     7     |      290.000      |       350.000       |\n";
    cout <<"|___________|___________________|_____________________|\n";
}
void QuanLyDatSan::TrangThaiSanTheoNgay(const Date& ngaykiemtra) {
    cout << "\n============================================================" << endl;
    cout << "            Bảng trạng thái sân-"<<ngaykiemtra.GetNgay()<< endl;
    cout << "==============================================================" << endl;
    cout << setw(12) << "Khung giờ";
    for (const auto& san : tensan) {
        cout << setw(10) << san;
    }
    cout << endl;

    for (int i=0; i<sizeof(giosan)/sizeof(string); i++) {
        cout << setw(11) << giosan[i];
            for (const auto& san : tensan) {
            // Kiểm tra trạng thái sân
                if (!IsEmpty(ngaykiemtra, san, i)) {
                    cout << setw(10) << "[X]";
                } else {
                    cout << setw(10) << "[ ]";
            }
        }
        cout << endl;
    }
    bangGia();
}

void QuanLyDatSan::themDinhKy(string sdtkh) {
    string sandat, ngayMoi;
    int giodat;
    Date startDate, endDate;
    cout << "Nhập ngày bắt đầu: ";
    startDate.SetNgay();
    cout << "Nhập ngày kết thúc: ";
    endDate.SetNgay();

    // Kiểm tra tính hợp lệ của ngày bắt đầu và ngày kết thúc
    if (endDate.GetNgay() <= startDate.GetNgay()) {
        throw invalid_argument("Ngày kết thúc phải lớn hơn ngày bắt đầu.");
    }  

    setTenSan(sandat);
    setGioSan(giodat);

    Date currentDate = startDate;
    while (currentDate.GetNgay() <= endDate.GetNgay()) {
        DatSan* ds = new DatSan(sdtkh, currentDate.GetNgay(), sandat, giodat);

        while (DanhSachDatSan.find(ds)) { // Nếu trùng lặp
            cout << "Khung giờ hoặc sân đã có người đặt vào ngày " << currentDate.GetNgay() << ".\n";
            TrangThaiSanTheoNgay(currentDate.GetNgay()); // Hiển thị các sân trống

            // Hiển thị các tùy chọn cho khách hàng
            cout << "Lựa chọn:\n";
            cout << "1. Đổi sang ngày khác (yêu cầu đổi sân và giờ)\n";
            cout << "2. Đổi sân và giờ\n";
            cout << "3. Giữ sân nhưng đổi giờ\n";
            cout << "Nhập lựa chọn của bạn (1/2/3): ";
            int choice;
            cin >> choice;

            if (choice == 1) {
                // Đổi ngày, yêu cầu nhập tên sân và giờ mới
                cout << "Nhập ngày mới (dd/mm/yyyy): ";
                // cin >> ngayMoi;
                currentDate.SetNgay(); // Đặt ngày mới
                setTenSan(sandat);           // Nhập tên sân mới
                setGioSan(giodat);           // Nhập giờ mới
            } else if (choice == 2) {
                // Đổi sân và giờ
                setTenSan(sandat);
                setGioSan(giodat);
            } else if (choice == 3) {
                // Giữ sân nhưng đổi giờ
                setGioSan(giodat);
            } else {
                cout << "Lựa chọn không hợp lệ. Vui lòng thử lại.\n";
                continue; // Quay lại vòng lặp để chọn lại
            }

            // Cập nhật thông tin đặt sân
            delete ds; // Xóa đối tượng cũ để tránh rò rỉ bộ nhớ
            ds = new DatSan(sdtkh, currentDate.GetNgay(), sandat, giodat);
        }
        ds->setTongTien();
        // Thêm đơn đặt sân hợp lệ vào danh sách
        DanhSachDatSan.addFirst(ds);
        cout << "Đặt thành công cho ngày " << currentDate.GetNgay() << " tại sân " << sandat << " khung giờ " << ds->getGioDat(giodat) << ".\n";
    
        // Chuyển sang tuần kế tiếp
        currentDate.incrementWeek();
    }
}


void QuanLyDatSan::setGioSan(int& giodat){
    bool t = true;
    int giosan;
    do{
    cout << "Nhap gio san:";
    cin >> giosan; 
    if(giosan<0||giosan>23){
        t = false;
        cout << "Gio san khong hop le!\n";
    }
    else{t=true;}
    }while(t==false);
    // Chuyển chuỗi `giosan` thành in hoa
    giodat = giosan;

}
//truoc khi cap nhat trang thai thi phai tim kiem 
void QuanLyDatSan::capnhatTrangThaiTT(const string& sdtKH, const int& status){
    DatSan* ds=timkiem(sdtKH);
    if (ds) {
        ds->setTrangThaiTT(status);
        cout << "Trang thai thanh toan cua hoa don da duoc cap nhat!" << endl;
    }
}

void QuanLyDatSan::xoa(string sdtkh){
    DatSan* s = timkiem(sdtkh);
    if(s==nullptr){
        cout << "Don dat san so "<<sdtkh<<" khong ton tai!\n";
        return;
    }
    DanhSachDatSan.remove(DanhSachDatSan.find(s));
    cout << "Don dat san so "<< sdtkh<<" da xoa thanh cong\n!"; 
}

DatSan* QuanLyDatSan::findDuplicate(DatSan*ds){
    auto x = DanhSachDatSan.begin();
    while(x!=nullptr){
        if((x->data->getSDTKH()!=ds->getSDTKH()) && (x->data==ds)){
            return x->data;
        }
        x= x->next;
    }
    return nullptr;
}

void QuanLyDatSan::menuCapNhat(){
    cout <<"\n-----------CẬP NHẬT---------------\n";
    cout <<"1. Đổi ngày đặt sân\n"//đổi sân đặt
         <<"2. Đổi sân đặt\n"
         <<"3) Đổi giờ đặt\n"
         <<"4) Đổi trạng thái thanh toán\n";
    cout <<"--------------------------------------";
    cout << "Vui lòng nhập lựa chọn(1,2,3): ";
}

void QuanLyDatSan::capnhat(string sdtkh){
    DatSan*s = timkiem(sdtkh);
    if(s==nullptr){ 
    cout << "Đơn đặt sân số "<<sdtkh<<" không tồn tại!\n";
    return;
    }
    DatSan oldS = *s;
    int i=_getch();//cau lenh cin se khong dung chuong trinh
    switch(i){
        case '1':{
            cout <<"1) Doi ngay dat san\n";
            Date ngaydat;
            ngaydat.SetNgay();
            s->setNgayDat(ngaydat.GetNgay());
            cout << "Ngay sau khi cap nhat: " << s->getNgayDat() << endl;
            break;
        }
        case '2':{
            cout <<"2) Doi san dat\n";
            string sandat;
            setTenSan(sandat);
            s->setSanDat(sandat);
            break;
        }
        case '3':{
            cout <<"3) Doi gio dat\n";
            int giodat;
            setGioSan(giodat);
            s->setGioDat(giodat);
            break;
        }
        case '4':
        {
            cout <<"4) Doi trang thai thanh toan\n";
            int status;
            cout << "Thanh toan hay chua?(0: chua thanh toan, 1: da thanh toan):";
            cin >> status;
            s->setTrangThaiTT(status);
            break;
        }
        default:
        cout << "Nhap lua chon khong hop le!\n";
        capnhat(sdtkh);
        break;
    }

    if(findDuplicate(s)==nullptr){
    cout << "Ban da doi thanh cong!\n";
    cout << "THONG TIN SAN SAU KHI THAY DOI!\n";
    s->xuat();      
    }
    else{
        cout << "SAN NAY DA CO NGUOI DAT!\n";
        *s = oldS;
        cout << "Ban co muon tiep tuc thay doi?(Y/N)\n";
        int ch = getch();
        switch(ch){
            case 'Y':case 'y':{
                capnhat(sdtkh);
                break;
            }
            case 'N': case 'n':{
                exit(1);
            }
       }
    }   
}

DatSan* QuanLyDatSan::timkiem(string customersdt){
    auto x = DanhSachDatSan.begin();
    while(x!=nullptr){
        if(x->data->getSDTKH()==customersdt){
            return x->data;
        }
        x=x->next;
    }
    return nullptr;
}
void QuanLyDatSan::xuat(){
    auto x = DanhSachDatSan.begin();
    while(x != nullptr){
    cout << "---------------------------------------------------------------"<<endl;    
        x->data->xuat();
        x = x->next;
    }
}

void QuanLyDatSan::xuattheosdt(string customersdt){
    auto x = DanhSachDatSan.begin();
    cout << "Danh sach cac don dat san cua khach hang so "<<customersdt<<endl;
    while(x!=nullptr){
        if(x->data->getSDTKH()==customersdt){
        cout << "---------------------------------------------------------"<<endl;
        x->data->xuat();
        }
        x=x->next;
    }
}

int QuanLyDatSan::getDoanhThuTheoNgay(int day,int month,int year){
    doanhthuTheoNgay=0;
    auto x=DanhSachDatSan.begin();
    while(x!=nullptr){
        int trangthaiTT=x->data->getTrangThaiTT();
        if(trangthaiTT==0)continue;
        string ngay=x->data->getPaidDay();
         if ((day == 0 || stoi(ngay.substr(0, 2)) == day) &&
                (month == 0 || stoi(ngay.substr(3, 2)) == month) &&
                (year == 0 || stoi(ngay.substr(6, 4)) == year)) {
                    doanhthuTheoNgay+=x->data->getTongTien();
        }
        x=x->next;
    }
return doanhthuTheoNgay;
}
