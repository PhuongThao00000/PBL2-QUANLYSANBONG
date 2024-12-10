#include "DATXE.h"
#include <iostream>
#include <string>
#include<iomanip>

using namespace std;

// Constructor
DatXe::DatXe(string tennhanvien, int soloaixe, int TongTien, string gioBan, const Date& ngay)
    : DichVu(tennhanvien), NumberOfType(soloaixe), totalprice(TongTien){
    quantityOfEachType = new int[soloaixe]();
    vehiclecode = new int[soloaixe]();
}


// Copy Constructor
DatXe::DatXe(const DatXe* dx)
    : DichVu(dx->getTenNhanVien()), NumberOfType(dx->NumberOfType), totalprice(dx->totalprice){

    quantityOfEachType = new int[dx->NumberOfType];
    vehiclecode = new int[dx->NumberOfType];

    for (int i = 0; i < dx->NumberOfType; ++i) {
        quantityOfEachType[i] = dx->quantityOfEachType[i];
        vehiclecode[i] = dx->vehiclecode[i];
    }
}

// Destructor
DatXe::~DatXe() {
    // Release memory
    delete[] quantityOfEachType;
    delete[] vehiclecode;

}



// Getter và Setter
const string& DatXe::getTenXe(int index) {
    return tenxe[index];
}

int& DatXe::getGiaXe(int index) {
    return giaxe[index];
}

int& DatXe::getQuantity(int index) {
    return quantityOfEachType[index];
}

int& DatXe::getNumberOfType() {
    return NumberOfType;
}

int& DatXe::getVehicleCode(int index) {
    return vehiclecode[index];
}



void DatXe::setVehicleCode(int index, int code) {
    vehiclecode[index] = code;
}

void DatXe::setQuantity(int index, int quantity) {
    quantityOfEachType[index] = quantity;
}

void DatXe::setGiaXe(int index, int price) {
    giaxe[index] = price;
}

void DatXe::setNumberOfType(int numberOfType) {
    delete[] quantityOfEachType;
    delete[] vehiclecode;
    quantityOfEachType = new int[numberOfType]();
    vehiclecode = new int[numberOfType]();
    NumberOfType = numberOfType;
}

void DatXe::setTotalPrice(int total) {
    totalprice = total;
}



int& DatXe::getTotalPrice() {
    return totalprice;
}



// Phương thức xuất thông tin đơn đặt xe
void DatXe::xuat() {
    cout << "---------------------------------------" << endl;
    cout << "Mã đơn: " << getMaDon() << endl; // Hiển thị mã đơn
    cout << setw(10) << getNgayGioBan() << endl;
    cout << "Số loại xe: " << NumberOfType << endl;
    for (int i = 0; i < NumberOfType; ++i) {
        cout << i + 1 << ") Lọai xe: " << getTenXe(i) 
             << " | Số lượng: " << getQuantity(i) << " xe" 
             << " | Giá: " << getGiaXe(i) << " 000/xe" << endl;
    }
    // cout << "Ngay ban: " << getNgayBan() << " | Gio ban: " << getGioBan() << endl;
    cout << "Tổng tiền: " << getTotalPrice() << " 000 VND" << endl;
    cout << getTenNhanVien() << endl;
    cout << "---------------------------------------" << endl;
}

// Hàm thiết lập các loại xe và số lượng
void DatXe::incrementNumberOfType() {
    NumberOfType++;
}

