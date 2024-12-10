#ifndef DATNUOC_H
#define DATNUOC_H
#include <iostream>
using namespace std;
#include <string>
#include <ctime>
#include "DICHVU.h"
#include "DICHVU.cpp"



class DatNuoc: public DichVu {
		//string tennhanvien;//khoa ngoai de ket noi voi lop khach hang
		const string tennuoc[4]= {"Khoang Ngot","Khoang lat","Revive","Suoi"}; // theo so thu tu trong menu de in ra ten nuoc
		int gianuoc[4]= {10,10,13,8}; //gia nuoc co the thay doi
		int *quantityOfEachType;
		int NumberOfType;
		int totalprice;
		int *watercode;//tao ra nhieu don dat dat nuoc moi don moi loai nuoc

	public:

	DatNuoc(string tennhanvien, int soloainuoc = 0, int TongTien = 0);
	~DatNuoc();
	DatNuoc(const DatNuoc* dn);
    
	const string& getTenNuoc(int index);//tra ve ten nuoc theo ma nuoc khach chon

	int& getGiaNuoc(int index);

	int& getquantity(int index);

	int& getNumberOfType();

	int& getWaterCode(int index);

// Hàm thiết lập mã nước cho từng loại nước
	void setWaterCode(int index, int code);

// Hàm thiết lập số lượng nước cho từng loại nước
	void setQuantity(int index, int quantity);

// Hàm thiết lập giá nước cho từng loại nước
	void setGiaNuoc(int index, int price);

// Hàm thiết lập tổng số loại nước khách đặt
	void setNumberOfType(int numberOfType);

// Hàm thiết lập tổng tiền
	void setTotalPrice(int total);
	int& getTotalPrice();
	void xuat();


};
#endif
