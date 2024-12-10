#include "DatNuoc.h"
#include <iomanip>
DatNuoc::DatNuoc(const DatNuoc* dn)
    : DichVu(dn->getTenNhanVien()), NumberOfType(dn->NumberOfType), totalprice(dn->totalprice), quantityOfEachType(new int[dn->NumberOfType]), watercode(new int[dn->NumberOfType]) {
        for (int i = 0; i < NumberOfType; ++i) {
            quantityOfEachType[i] = dn->quantityOfEachType[i];
            watercode[i] = dn->watercode[i];
        }
}
void DatNuoc::xuat() {
        cout << "---------------------------------------" << endl;
        cout << "Mã đơn: " << getMaDon() << endl; // Hiển thị mã đơn
        cout << setw(10) << getNgayGioBan()<< endl;

        for (int i = 0; i < NumberOfType; i++) {
            cout << watercode[i] << setw(10) << getTenNuoc(watercode[i])
                 << "x" << setw(5) << quantityOfEachType[i] << endl;
        }

        cout << "Tổng tiền nước: " << totalprice << endl;
        cout<< setw(15) << getTenNhanVien();
        cout << "---------------------------------------" << endl;
    }

