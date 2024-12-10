#include "DATSAN.h"
#include "DICHVU.h"
const string DatSan::giosan[24] = {
        "5:00-5:30", "5:30-6:00", "6:00-6:30", "6:30-7:00", "7:00-7:30", "7:30-8:00",
        "8:00-8:30", "8:30-9:00", "9:00-9:30", "9:30-10:00", "15:00-15:30", "15:30-16:00",
        "16:00-16:30", "16:30-17:00", "17:00-17:30", "17:30-18:00", "18:00-18:30",
        "18:30-19:00", "19:00-19:30", "19:30-20:00", "20:00-20:30", "20:30-21:00",
        "21:00-21:30", "21:30-22:00"};



DatSan::DatSan(string customersdt, string ngaydat, string sandat, int giodat, string ngaykt, 
               bool loaikhach ,int trangthai , int totalp,string giott,string ngaytt) {
    sdtKH = customersdt;
    status = trangthai;
    ngaysan = Date(ngaydat);
    ngayend = Date(ngaykt);
    LeOrDinhKy = loaikhach;
    totalprice = totalp;
    paidtime=giott;
    paidday=ngaytt;
    if (!sandat.empty() && giodat >= 0) {
        SanVaGio.addFirst(make_pair(sandat, giodat));
    }
}
        
DatSan::~DatSan(){
}

DatSan::DatSan(const DatSan* other) {
    sdtKH = other->sdtKH;
    status = other->status;
    ngaysan = other->ngaysan;
    ngayend = other->ngayend;
    SanVaGio = other->SanVaGio;
    totalprice = other->totalprice;
    LeOrDinhKy = other->LeOrDinhKy;
}

void DatSan::themSanVaGio(pair<string,int>& sanvagio){
    SanVaGio.addFirst(sanvagio);
}

const string DatSan:: getSanDatODau() const{
    return SanVaGio.begin()->data.first;
}
    const int DatSan::getGioDatODau()const{
        return SanVaGio.begin()->data.second;
    }

// Phương thức xuất thông tin
    void DatSan::xuat() {
        cout << "Số điện thoại khách hàng: " << sdtKH << endl;
        cout << "Loại khách: " << (LeOrDinhKy == 0 ? "Lẻ" : "Định kỳ") << endl;
        cout << "Ngày đặt: " << ngaysan.GetNgay() << endl;  

        if(LeOrDinhKy){
        cout << "Ngày kết thúc: " << ngayend.GetNgay() << endl;
        }
    
        cout << "Danh sách sân và giờ: " << endl;
        // Duyệt danh sách liên kết SanVaGio
        Node<pair<string, int>>* current = SanVaGio.begin();
    
    // Tính tổng tiền cho tất cả các sân và giờ đã đặt
    while (current != nullptr) {
        cout << "Sân: "<< current->data.first;  // Tên sân
        cout << ": "<<getGioDat(current->data.second)<<endl; // Giờ sân
        // Tính giá cho từng sân và giờ và cộng vào tổng tiền
        current = current->next;
    }
        setTongTien();
        cout << "Tổng tiền: " << totalprice << endl;
        cout << "Trạng thái thanh toán: " << (status == 0 ? "Chưa thanh toán" : "Đã thanh toán") << endl;
        if(status==1) cout << "Đã thanh toán vào "<<paidtime<<" ngày "<<paidday.GetNgay();
    }

void DatSan::setSanDat(string tensan) {
        // Cập nhật tên sân
        SanVaGio.end()->data.first = tensan; 
     // Giả sử getLast() trả về phần tử cuối trong danh sách
    }

void DatSan::setGioDat(int giosan){
    SanVaGio.end()->data.second = giosan;
}

void DatSan::setTrangThaiTT(int trangthai){
    this->status=trangthai;
    if(trangthai==1){
        DichVu::setNgayBan(paidday);
        DichVu::setGioBan(paidtime);
    }
    else{
        paidday.ngay="00/00/0000";
        paidtime="00:00";
    }
}//Trang thai thanh toan cua don dat san

void DatSan::setNgayDat(const string&ngaydat){
    this->ngaysan.ngay=ngaydat;
}
const bool DatSan::getDangKH(){
    return LeOrDinhKy;
}
void DatSan::setDangKH(bool leOrdinhky){
    this->LeOrDinhKy=leOrdinhky;
}
DatSan& DatSan::operator=(DatSan& other){
    if (this != &other) { // Kiểm tra tự gán
        this->status = other.status;
        this->ngaysan = other.ngaysan;
        SanVaGio=other.SanVaGio;
        this->LeOrDinhKy=other.LeOrDinhKy;
        this->ngayend=other.ngayend;
        this->totalprice=other.totalprice;
        // Không cần gán mảng hằng tĩnh giasan vì giá trị này không thay đổi
    }
    return *this; // Trả về tham chiếu tới đối tượng hiện tại
}

const int DatSan::getGia(const string& tensan, int giodat) {
    if (giodat >= 0 && giodat <= 9) {
        return tensan[0] == '5' ? giasan[0] : giasan[2];
    } else if (giodat >= 10 && giodat <= 23) {
        return tensan[0] == '5' ? giasan[1] : giasan[3];
    }
    return 0;
}


void DatSan::setTongTien() {
    totalprice = 0;
    Node<pair<string, int>>* current = SanVaGio.begin();
    while (current != nullptr) {
        totalprice += getGia(current->data.first, current->data.second);
        current = current->next;
    }
}

const int& DatSan::getTrangThaiTT() {
    return status;
}//0: chua, 1:roi

const string DatSan::getSanDatOCuoi()const{
    return SanVaGio.end()->data.first;
}
const int DatSan::getGioDatOCuoi()const{
    return SanVaGio.end()->data.second;
}

const string DatSan::getGioDat(const int giodat) {
    if (giodat < 0 || giodat >= sizeof(giosan) / sizeof(giosan[0])) {
        throw out_of_range("Chỉ số giờ đặt không hợp lệ.");
    }

    // Trả về chuỗi khung giờ tương ứng
    return giosan[giodat];
}

const string& DatSan::getPaidDay()const{
    if(status==0){
        throw invalid_argument("Đơn đặt sân chưa được thanh toán!");
        return paidday.GetNgay() ;
    }
    return paidday.GetNgay();
        
}
const string& DatSan::getPaidTime()const{
    if(status==0){
        throw invalid_argument("Đơn đặt sân chưa được thanh toán!");
        return paidtime ;
    }
    return paidtime;
}
const string DatSan::getNgayDat() const{
    return ngaysan.GetNgay();
}
const string DatSan::getNgayEnd() const{
    return ngayend.GetNgay();
}

void DatSan::setNgayEnd(const string& ngaykt){
    if (LeOrDinhKy && ngaykt <= ngaysan.GetNgay()) {
        throw invalid_argument("Ngay ket thuc phai lon hon ngay bat dau.");
    }
    ngayend.ngay = ngaykt;
}

LINKLIST<pair<string, int>>& DatSan::getSanVaGio() {
    return SanVaGio;
}


