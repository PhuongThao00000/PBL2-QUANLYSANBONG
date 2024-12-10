#ifndef PERSONMANAGE_H
#define PERSONMANAGE_H
#include "LINKLIST.h"
#include "LINKLIST.cpp"
class PersonManage{
    public:
    virtual void xoa(const string& customersdt)=0;
    virtual void capnhat(const string& customersdt)=0;
    virtual void xuat()const=0;
    virtual void ghiDanhSachRaFile(const string& fileName)=0;
    // virtual void docDanhSachTuFile(const string& fileName)=0;
    
};
#endif