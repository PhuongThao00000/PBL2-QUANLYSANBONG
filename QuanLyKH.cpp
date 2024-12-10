#include "QuanLyKH.h"

void QuanLyKH::xuat() const {
    auto x = DanhSachKH.begin();
    while(x != nullptr){
        x->data->xuatthongtin();
        x = x->next;
    }
}

void QuanLyKH::them(KhachHang* kh){
    //Qua trinh DownCast
    //Tim neu trung lap thi khong add them
    if(!DanhSachKH.find(kh)){
        DanhSachKH.addFirst(kh);
        cout << "Khach Hang "<<kh->getUsername()<< " da duoc them vao thanh cong!\n";
    }
    else{
    cout << "Khach hang "<<kh->getUsername()<<" da co trong csdl!\n";
    return;
    }  
}

KhachHang* QuanLyKH::timkiem(const string& customersdt){
    auto x=DanhSachKH.begin();
    while(x!=nullptr){
        if(x->data->getSDT()==customersdt){
            return x->data;
        }
        x=x->next;
    }
    return nullptr;
}

void QuanLyKH::capnhat(const string& customersdt){
    //sau khi da cap nhat xong
    KhachHang* kh = timkiem(customersdt);
        if (kh == nullptr) {
            cout << "Khong tim thay khach hang co SDT: " << customersdt << "\n";
            return;
        }

        cout << "1) Cap nhat ten\n";
        cout << "2) Cap nhat so dien thoai\n";
        cout << "3) Cap nhat gioi tinh\n";
        cout << "Nhap lua chon: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string newTen;
                cout << "Nhap ten moi: ";
                cin.ignore();
                getline(cin, newTen);
                kh->setUsername(newTen);
                break;
            }
            case 2: {
                string newSDT;
                cout << "Nhap so dien thoai moi: ";
                cin >> newSDT;
                if (User::ktsdt(newSDT)) {
                    kh->setSDT(newSDT);
                } else {
                    cout << "So dien thoai khong hop le!\n";
                }
                break;
            }
            case 3: {
                int newGioiTinh;
                cout << "Nhap gioi tinh (0: Nam, 1: Nu): ";
                cin >> newGioiTinh;
                if (newGioiTinh == 0 || newGioiTinh == 1) {
                    kh->setGioiTinh(newGioiTinh);
                } else {
                    cout << "Gioi tinh khong hop le!\n";
                }
                break;
            }
            // case 4: {
            //     string newQuocTich;
            //     cout << "Nhap quoc tich moi: ";
            //     cin.ignore();
            //     getline(cin, newQuocTich);
            //     kh->setQuocTich(newQuocTich);
            //     break;
            // }
            default:
                cout << "Lua chon khong hop le!\n";
        }

        cout << "Cap nhat thong tin thanh cong!\n";
}

void QuanLyKH::xoa(const string& customersdt){
    KhachHang*kh=timkiem(customersdt);
    if(kh){
        DanhSachKH.remove(DanhSachKH.find(kh));
        cout << "Khach Hang "<<kh->getUsername()<<" da duoc xoa thanh cong!\n";
    }
    else{
        cout << "Khach Hang co sdt "<<customersdt<<" xoa khong thanh cong! Khong co trong du lieu!\n";
        return;
    }
}