#include <iostream>
#include <string>
using namespace std;

class Nguoi {
protected:
    string hoten;
    string ngaythang;
    string diachi;

public:
    Nguoi(const string& _hoten, const string& _ngaythang, const string& _diachi)
        : hoten(_hoten), ngaythang(_ngaythang), diachi(_diachi) {}
};

class Khachhang : public Nguoi {
private:
    string makhachhang;
    int chisotruoc, chisosau;
    float tiendien;

public:
    Khachhang(const string& _hoten, const string& _ngaythang, const string& _diachi,
              const string& _makhachhang, int _chisotruoc, int _chisosau)
        : Nguoi(_hoten, _ngaythang, _diachi), makhachhang(_makhachhang),
          chisotruoc(_chisotruoc), chisosau(_chisosau), tiendien(0.0) {}

    void TinhTienDien() {
        int chisodien = chisosau - chisotruoc;
        if (chisodien <= 50) {
            tiendien = chisodien * 1500;
        } else if (chisodien <= 100) {
            tiendien = 50 * 1500 + (chisodien - 50) * 2000;
        } else {
            tiendien = 50 * 1500 + 50 * 2000 + (chisodien - 100) * 3000;
        }
    }

    void HienThiThongTin() {
        cout << "Thong tin khach hang:\n";
        cout << "Ho ten: " << hoten << "\n";
        cout << "Ngay thang: " << ngaythang << "\n";
        cout << "Dia chi: " << diachi << "\n";
        cout << "Ma khach hang: " << makhachhang << "\n";
        cout << "Tien dien: " << tiendien << "\n";
    }
};

int main() {
    Khachhang khach1("Nguyen Van A", "99 Nguyen Chi Thanh", "26/04/2003", "221230456", 400, 300);
    khach1.TinhTienDien();
    khach1.HienThiThongTin();

    Khachhang khach2("Nguyen Thi B", "33 Nguyen Khac Minh", "23/09/2004", "221234994", 300, 100);
    khach2.TinhTienDien();
    khach2.HienThiThongTin();

    return 0;
}
