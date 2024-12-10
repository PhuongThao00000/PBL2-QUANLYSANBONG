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
		DatNuoc(string tennhanvien, int soloainuoc = 0, int TongTien = 0)
			: DichVu(tennhanvien), NumberOfType(soloainuoc), totalprice(TongTien) {
			setNgayBan(ngayban);
			setGioBan(gioban);
			quantityOfEachType = new int[soloainuoc];
			watercode = new int[soloainuoc];
		}
		~DatNuoc() {
			delete[]quantityOfEachType;
			delete[]watercode;
		};
		DatNuoc(const DatNuoc* dn);
    
		const string& getTenNuoc(int index) {
			return tennuoc[index];
		};//tra ve ten nuoc theo ma nuoc khach chon
		int& getGiaNuoc(int index) {
			return gianuoc[index];
		};
		int& getquantity(int index) {
			return quantityOfEachType[index];//tra ve so luong cua moi ma nuoc
		};
		int& getNumberOfType() {
			return NumberOfType;//tra ve so loai nuoc khach dat
		};
		int& getWaterCode(int index) {
			return watercode[index];//tra ve ma nuoc
		};

		// Hàm thiết lập mã nước cho từng loại nước
		void setWaterCode(int index, int code) {
			if (index >= 0 && index < NumberOfType) { // Kiểm tra index hợp lệ
				watercode[index] = code;
			} else {
				cout << "Index không hợp lệ!\n";
			}
		};


// Hàm thiết lập số lượng nước cho từng loại nước
		void setQuantity(int index, int quantity) {
			if (index >= 0 && index < NumberOfType) { // Kiểm tra index hợp lệ
				if (quantity >= 0) { // Kiểm tra số lượng không âm
					quantityOfEachType[index] = quantity;
				} else {
					cout << "Số lượng không hợp lệ!\n";
				}
			} else {
				cout << "Index không hợp lệ!\n";
			}
		}
		int& getTotalPrice() {
			return totalprice;
		}
// Hàm thiết lập giá nước cho từng loại nước
		void setGiaNuoc(int index, int price) {
			if (index >= 0 && index < 4) { // Kiểm tra index hợp lệ (do tennuoc có 4 phần tử)
				if (price > 0) { // Kiểm tra giá nước không âm
					gianuoc[index] = price;
				} else {
					cout << "Giá nước phải lớn hơn 0!\n";
				}
			} else {
				cout << "Index không hợp lệ!\n";
			}
		}

// Hàm thiết lập tổng số loại nước khách đặt
		void setNumberOfType(int numberOfType) {
			if (numberOfType >= 0) { // Kiểm tra số loại nước không âm
				NumberOfType = numberOfType;
				// Cấp phát lại bộ nhớ cho mảng quantityOfEachType và watercode
				delete[] quantityOfEachType;
				delete[] watercode;
				quantityOfEachType = new int[numberOfType]();
				watercode = new int[numberOfType]();
			} else {
				cout << "Số loại nước không hợp lệ!\n";
			}
		}

// Hàm thiết lập tổng tiền
		void setTotalPrice(int total) {
			if (total >= 0) { // Kiểm tra tổng tiền không âm
				totalprice = total;
			} else {
				cout << "Tổng tiền không hợp lệ!\n";
			}
		}
		

// bool operator==(DatNuoc& dn) {
//     // So sánh ngày bán và giờ bán
//     if (this->ngayban.GetNgay() != dn.ngayban.GetNgay() || this->gioBan != dn.gioBan) {
//         return false;
//     }

//     // So sánh số loại nước (NumberOfType)
//     if (this->NumberOfType != dn.NumberOfType) {
//         return false;
//     }

//     // So sánh từng loại nước (cả mã nước và số lượng)
//     for (int i = 0; i < this->NumberOfType; ++i) {
//         if (this->watercode[i] != dn.watercode[i] || this->quantityOfEachType[i] != dn.quantityOfEachType[i]) {
//             return false;
//         }
//     }

//     // Nếu không có sự khác biệt thì trả về true
//     return true;
// }

		void xuat();


};
#endif