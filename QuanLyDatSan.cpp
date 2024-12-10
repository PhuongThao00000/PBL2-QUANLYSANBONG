#include "QuanLyDatSan.h"
#include <iostream>
#include <conio.h>

using namespace std;

// Constructor va Destructor
QuanLyDatSan::QuanLyDatSan() : doanhthuTheoNgay(0) {}

QuanLyDatSan::~QuanLyDatSan() {}

// Menu lua chon loai san
void QuanLyDatSan::menuGiuXe() {
    cout << "----- MENU XE -----\n";
    for (int i = 0; i < 5; i++) {
        cout << i << ". " << tensan[i] << "\n";
    }
}

// Them don dat san le
void QuanLyDatSan::themLe(string sdtkh) {
    int status;
    Date ngaydat;
    cout << "\nTHONG TIN DON DAT SAN:\n";
    cout << "Nhap ngay dat san: ";
    ngaydat.SetNgay();
    DatSan *ds = new DatSan(sdtkh, ngaydat.GetNgay());

    while (true) {
        pair<string, int> sanvagio;
        while (true) {
            setTenSan(sanvagio.first);
            setGioSan(sanvagio.second);

            if (IsEmpty(ngaydat, sanvagio.first, sanvagio.second) == true) {
                ds->themSanVaGio(sanvagio);
                break;
            }
            else {
                cout << "San " << sanvagio.first << ": " << sanvagio.second << " da co nguoi dat\n";
                continue;
            }
        }
        cout << "San " << ds->getSanDatODau() << ": " << ds->getGioDat(ds->getGioDatODau()) << endl;
        cout << "Ban co muon chon them san va khung gio khac trong hom nay " << ds->getNgayDat() << " khong?\n";
        cout << "Nhan c de tiep tuc chon\n";
        int i = _getch();
        if (i == 'c' || i == 'C') {
            continue;
        }
        else {
            break;
        }
    }
    ds->setDangKH(false);
    cout << "Don dat san so " << sdtkh << " dat thanh cong!\n";
    ds->setTongTien();
    cout << "Tong tien can thanh toan: " << ds->getTongTien() << endl;
    status = 0;
    cout << "Tinh trang: " << (status == 0 ? "Chua thanh toan" : "Da thanh toan") << endl;
    ds->setTrangThaiTT(status);
    DanhSachDatSan.addFirst(ds);
}

// Kiem tra san da duoc dat hay chua
bool QuanLyDatSan::IsEmpty(const Date& ngaydat, const string& tensan, const int& giosan) {
    auto current = DanhSachDatSan.begin();
    while (current != nullptr) {
        if (current->data->getNgayDat() == ngaydat.GetNgay()) {
            LINKLIST<pair<string, int>>& sanVaGio = current->data->getSanVaGio();
            auto datsan = sanVaGio.begin();
            while (datsan != sanVaGio.end()) {
                if (datsan->data.first == tensan && datsan->data.second == giosan) {
                    return false;
                }
                datsan = datsan->next;
            }
        }
        current = current->next;
    }
    return true;
}

// Xuat bang gia san
void QuanLyDatSan::bangGia() {
    cout << endl;
    cout << "_____________________________________________________\n";
    cout << "|               BANG GIA SAN CHI TIET(vnd)            |\n";
    cout << "|_____________________________________________________|\n";
    cout << "|    San    |     Buoi sang     |      Buoi chieu     |\n";
    cout << "|___________|__(5:30 - 10:30)___|____(15:00 - 22:00)__|\n";
    cout << "|     5     |      200.000      |       300.000       |\n";
    cout << "|     7     |      270.000      |       400.000       |\n";
    cout << "|___________|___________________|_____________________|\n";
}

// In thong tin trang thai san theo ngay
void QuanLyDatSan::TrangThaiSanTheoNgay(const Date& ngaykiemtra) {
    cout << "\n============================================================" << endl;
    cout << "            Bang trang thai san-" << ngaykiemtra.GetNgay() << endl;
    cout << "==============================================================" << endl;
    cout << setw(12) << "Khung gio";
    for (const auto& san : tensan) {
        cout << setw(10) << san;
    }
    cout << endl;

    for (int i = 0; i < sizeof(giosan) / sizeof(string); i++) {
        cout << setw(11) << giosan[i];
        for (const auto& san : tensan) {
            if (!IsEmpty(ngaykiemtra, san, i)) {
                cout << setw(10) << "[X]";
            }
            else {
                cout << setw(10) << "[ ]";
            }
        }
        cout << endl;
    }
    bangGia();
}

// Them don dat san dinh ky
void QuanLyDatSan::themDinhKy(string sdtkh) {
    string sandat;
    int giodat;
    Date startDate, endDate;
    cout << "Nhap ngay bat dau: ";
    startDate.SetNgay();
    cout << "Nhap ngay ket thuc: ";
    endDate.SetNgay();

    if (endDate.GetNgay() <= startDate.GetNgay()) {
        throw invalid_argument("Ngay ket thuc phai lon hon ngay bat dau.");
    }

    setTenSan(sandat);
    setGioSan(giodat);

    Date currentDate = startDate;
    while (currentDate.GetNgay() <= endDate.GetNgay()) {
        DatSan* ds = new DatSan(sdtkh, currentDate.GetNgay(), sandat, giodat);

        while (DanhSachDatSan.find(ds)) {
            cout << "Khung gio hoac san da co nguoi dat vao ngay " << currentDate.GetNgay() << ".\n";
            TrangThaiSanTheoNgay(currentDate.GetNgay());
            cout << "Lua chon:\n";
            cout << "1. Doi sang ngay khac\n";
            cout << "2. Doi san va gio\n";
            cout << "3. Giu san nhung doi gio\n";
            cout << "Nhap lua chon cua ban (1/2/3): ";
            int choice;
            cin >> choice;

            if (choice == 1) {
                currentDate.SetNgay();
                setTenSan(sandat);
                setGioSan(giodat);
            }
            else if (choice == 2) {
                setTenSan(sandat);
                setGioSan(giodat);
            }
            else if (choice == 3) {
                setGioSan(giodat);
            }
            else {
                cout << "Lua chon khong hop le.\n";
                continue;
            }

            delete ds;
            ds = new DatSan(sdtkh, currentDate.GetNgay(), sandat, giodat);
        }

        ds->setTongTien();
        DanhSachDatSan.addFirst(ds);
        cout << "Dat thanh cong cho ngay " << currentDate.GetNgay() << " tai san " << sandat << " khung gio " << ds->getGioDat(giodat) << ".\n";
        currentDate.incrementWeek();
    }
}
