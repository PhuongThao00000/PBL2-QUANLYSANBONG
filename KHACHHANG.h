#ifndef KHACHHANG_H
#define KHACHHANG_H

#include "USER.h"
#include "USER.cpp"
#include "QuanLyDatSan.h"
#include "QuanLyDatSan.cpp"
#include <iostream>
#include <string>

using namespace std;

class KhachHang : public User { 
    int rankMember=0;//4: Member,3: Dong, 2: Bac, 1: Vang
public:
    KhachHang();  // Constructor 
    KhachHang(const string& username , const string& password ,const string& phonenumber,int gender, Date& ngsinh,int rankmember=0,int loaiTK=0); 
    KhachHang(const KhachHang *kh);
    ~KhachHang(){}  // Destructor
    void setRank(int rank){
        if(rank!=1&&rank!=2&&rank!=3&&rank!=4)
            throw invalid_argument("Hạng thành viên không hợp lệ!");
        rankMember=rank;
    }
    const int& getRank(){
        return rankMember;
    }
    void xuatthongtin() const{
        User::xuatthongtin();
        cout<<"Hạng thành viên(4:Member,3:Đồng,2:Bạc,1:Vàng): ";
        if(rankMember==0) cout << "Chưa có hạng\n";
        else{ cout<< rankMember;}
    };
    void themDonDatsanLe(QuanLyDatSan&qlds);
    
    void xoaSan(QuanLyDatSan&qlds);
    DatSan* timkiem(QuanLyDatSan&qlds);
    void suaDonDatsan(QuanLyDatSan&qlds);
    void xuatDonDatsan(QuanLyDatSan&qlds);
    // friend ostream& operator <<(ostream& os, const KhachHang& kh);
};

        
#endif
