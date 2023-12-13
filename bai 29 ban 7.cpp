#include<bits/stdc++.h>
using namespace std;

class KhachHang {
public:
    string hoTen;
    string soDienThoai;
};

class CuocGoi {
public:
    string soDienThoai;
    int soPhut;
    string thoiGian;
    string ngayThang;
    string vung;
};

class TinhTienDienThoai {
public:
    float GIA_CO_BAN = 1100;
    float HE_SO_MIEN_NH = 1;
    float HE_SO_MIEN_LC = 2;
    float HE_SO_MIEN_X = 3;
    float HE_SO_MIEN_RX = 4;

    float tinhTienCuoc(const CuocGoi& cuocGoi) {
        // Code c?a b?n...
    }
};

map<string, KhachHang> docKhachHangTuFile(const string& tenFile) {
    map<string, KhachHang> danhSachKhachHang;
    ifstream file(tenFile);
    
    if (!file.is_open()) {
        cerr << "Không th? m? file!" << endl;
        return danhSachKhachHang;
    }
    
    string dong;
    while (getline(file, dong)) {
        istringstream iss(dong);
        string hoTen, soDienThoai;
        getline(iss, hoTen, ';');
        getline(iss, soDienThoai, ';');
        danhSachKhachHang[soDienThoai] = {hoTen, soDienThoai};
    }
    
    file.close();
    return danhSachKhachHang;
}

vector<CuocGoi> docCuocGoiTuFile(const string& tenFile) {
   // Code c?a b?n...
}

void ghiKetQuaVaoFile(const map<string, float>& ketQua, const string& tenFile) {
   // Code c?a b?n...
}
int main() {
    // Ð?c d? li?u t? file
    map<string, KhachHang> danhSachKhachHang = docKhachHangTuFile("khachhang.txt");
    vector<CuocGoi> danhSachCuocGoi = docCuocGoiTuFile("cuocgoi.txt");

    // Tính ti?n di?n tho?i cho m?i khách hàng
    TinhTienDienThoai tinhTienDienThoai;
    map<string, float> ketQua;
    for (const auto& khachHang : danhSachKhachHang) {
        float tongTien = 0;
        for (const auto& cuocGoi : danhSachCuocGoi) {
            if (cuocGoi.soDienThoai == khachHang.second.soDienThoai) {
                tongTien += tinhTienDienThoai.tinhTienCuoc(cuocGoi);
            }
        }
        ketQua[khachHang.second.soDienThoai] = tongTien;
    }

    // Ghi k?t qu? vào file
    ghiKetQuaVaoFile(ketQua, "ketqua.txt");

    return 0;
}


