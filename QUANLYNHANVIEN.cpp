#include "QUANLYNHANVIEN.h"

void QuanLyNV::xuat() const {
    auto x = DanhSachNV.begin();
    while(x != nullptr){
        x->data->xuatthongtin();
        x = x->next;
    }
}

void QuanLyNV::them(NhanVien* nv){
    //Qua trinh DownCast
    //Tim neu trung lap thi khong add them
    if(!DanhSachNV.find(nv)){
        DanhSachNV.addFirst(nv);
        cout << "Nhan Vien "<<nv->getUsername()<< " da duoc them vao thanh cong!\n";
    }
    else{
    cout << "Nhan Vien "<<nv->getUsername()<<" da co trong csdl!\n";
    return;
    }  
}

NhanVien* QuanLyNV::timkiem(const string& nv_sdt){
    auto x=DanhSachNV.begin();
    while(x!=nullptr){
        if(x->data->getSDT()==nv_sdt){
            return x->data;
        }
        x=x->next;
    }
    return nullptr;
}

void QuanLyNV::menuCapNhat(){
    cout <<"\n-----------CẬP NHẬT---------------\n";
    cout << "1. Cập nhật username\n";
    cout << "2. Cập nhật sdt\n";
    cout << "3. Cập nhật giới tính\n";
    cout << "4. Cập nhật ngày sinh \n";
    cout << "5. Cập nhật mật khẩu \n";
    cout <<"--------------------------------------";
    cout << "Vui lòng nhập lựa chọn(1,2,3,4): ";
}

void QuanLyNV::capnhat(const string& nv_sdt){
    //sau khi da cap nhat xong
    NhanVien* nv = timkiem(nv_sdt);
        if (nv == nullptr) {
            cout << "Không tìm thấy nhân viên có SDT: " << nv_sdt << endl;
            return;
        }
        menuCapNhat();
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string newTen;
                cout << "Nhập username mới: ";
                cin.ignore();
                getline(cin, newTen);
                nv->setUsername(newTen);
                break;
            }
            case 2: {
                string newSDT;
                cout << "Nhập số điện thoại mới: ";
                cin >> newSDT;
                
                if (User::ktsdt(newSDT)) {
                    nv->setSDT(newSDT);
                } else {
                    cout << "Số điện thoại không hợp lệ!\n";
                }
                break;
            }
            case 3: {
                int newGioiTinh;
                cout << "Nhập giới tính (0: Nam, 1: Nữ): ";
                cin >> newGioiTinh;
                if (newGioiTinh == 0 || newGioiTinh == 1) {
                    nv->setGioiTinh(newGioiTinh);
                } else {
                    cout << "Giới tính không hợp lệ!\n";
                }
                break;
            }
            case 4: {
                Date newngsinh;
                cout << "Nhập ngày sinh";
                newngsinh.SetNgay();
                nv->setNgaysinh(newngsinh);
                break;
            }
            default:
                cout << "Lua chon khong hop le!\n";
        }

        cout << "Cap nhat thong tin thanh cong!\n";
}

void QuanLyNV::xoa(const string& nv_sdt){
    NhanVien*nv=timkiem(nv_sdt);
    if(nv){
        DanhSachNV.remove(DanhSachNV.find(nv));
        cout << "Nhan vien "<<nv->getUsername()<<" da duoc xoa thanh cong!\n";
    }
    else{
        cout << "Nhan vien co sdt "<<nv_sdt<<" xoa khong thanh cong! Khong co trong du lieu!\n";
        return;
    }
}