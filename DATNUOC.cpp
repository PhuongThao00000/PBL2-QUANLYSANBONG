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

DatNuoc::DatNuoc(string tennhanvien, int soloainuoc = 0, int TongTien = 0)
			: DichVu(tennhanvien), NumberOfType(soloainuoc), totalprice(TongTien) {
			setNgayBan(ngayban);
			setGioBan(gioban);
			quantityOfEachType = new int[soloainuoc];
			watercode = new int[soloainuoc];
		}
DatNuoc::~DatNuoc() {
	delete[]quantityOfEachType;
	delete[]watercode;
}

    
const string& DatNuoc::getTenNuoc(int index) {
    return tennuoc[index];
}//tra ve ten nuoc theo ma nuoc khach chon
		
int& DatNuoc::getGiaNuoc(int index) {
	return gianuoc[index];
}

int& DatNuoc::getquantity(int index) {
	return quantityOfEachType[index];//tra ve so luong cua moi ma nuoc
}

int& DatNuoc::getNumberOfType() {
	return NumberOfType;//tra ve so loai nuoc khach dat
};
int& DatNuoc::getWaterCode(int index) {
	return watercode[index];//tra ve ma nuoc
}

// Hàm thiết lập mã nước cho từng loại nước
void DatNuoc::setWaterCode(int index, int code) {
	if (index >= 0 && index < NumberOfType) { // Kiểm tra index hợp lệ
		watercode[index] = code;
	} else {
		cout << "Index không hợp lệ!\n";
	}
}


// Hàm thiết lập số lượng nước cho từng loại nước
void DatNuoc::setQuantity(int index, int quantity) {
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
int& DatNuoc::getTotalPrice() {
	return totalprice;
}
// Hàm thiết lập giá nước cho từng loại nước
void DatNuoc::setGiaNuoc(int index, int price) {
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
void DatNuoc::setNumberOfType(int numberOfType) {
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
void DatNuoc::setTotalPrice(int total) {
	if (total >= 0) { // Kiểm tra tổng tiền không âm
		totalprice = total;
	} else {
		cout << "Tổng tiền không hợp lệ!\n";
	}
}
		



		

