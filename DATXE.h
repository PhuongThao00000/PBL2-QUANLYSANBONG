#ifndef DATXE_H
#define DATXE_H

#include <iostream>
#include <string>
#include "DICHVU.h"


using namespace std;

class DatXe : public DichVu {
private:
    const string tenxe[3] = {"Xe máy", "Xe Oto", "Xe đạp"}; // Loại xe
    int giaxe[3] = {5, 10, 2}; // Giá cho từng loại xe
    int *quantityOfEachType; // Số lượng của từng loại xe
    int NumberOfType; // Số lượng loại xe khách hàng đặt
    int totalprice; // Tổng tiền của đơn đặt xe
    int *vehiclecode; // Mã xe cho từng loại xe

public:
    // Constructor, Destructor và Copy Constructor
    DatXe(string tennhanvien, int soloaixe=0, int TongTien=0, string gioBan="00:00", const Date& ngay=0);
    ~DatXe();
    DatXe(const DatXe* dx);

    // Getter và Setter
    const string& getTenXe(int index);
    int& getGiaXe(int index);
    int& getQuantity(int index);
    int& getNumberOfType();
    int& getVehicleCode(int index);
   
    void setVehicleCode(int index, int code);
    void setQuantity(int index, int quantity);
    void setGiaXe(int index, int price);
    void setNumberOfType(int numberOfType);
    void setTotalPrice(int total);
    
    
    int& getTotalPrice();

    // Phương thức xuất thông tin đơn đặt xe
    void xuat();

    // Hàm thiết lập các loại xe và số lượng
    void incrementNumberOfType();

};

#endif // DATXE_H
