#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class KhachHang {
public:
    KhachHang(int maKhach, string hoTen, string diaChi, int thangTruoc, int thangSau)
        : maKhach(maKhach), hoTen(hoTen), diaChi(diaChi), thangTruoc(thangTruoc), thangSau(thangSau) {}

    void TinhTien() {
        tien = (thangSau - thangTruoc) * 3000;
    }

    void InThongTin() {
        cout << "Mã khách: " << maKhach << endl;
        cout << "Ho tên: " << hoTen << endl;
        cout << "Ðia chi: " << diaChi << endl;
        cout << "So tháng truoc: " << thangTruoc << endl;
        cout << "So tháng sau: " << thangSau << endl;
        cout << "Tien phi truoc: " << tien << " VND" << endl;
    }

    int LayTien() const {
        return tien;
    }
protected:
    int maKhach;
    string hoTen;
    string diaChi;
    int thangTruoc;
    int thangSau;
    int tien;
};

class KhachHangUuTien : public KhachHang {
public:
    KhachHangUuTien(int maKhach, string hoTen, string diaChi, int thangTruoc, int thangSau, int uuTien)
        : KhachHang(maKhach, hoTen, diaChi, thangTruoc, thangSau), uuTien(uuTien) {}

    void TinhTien() {
        tien = (thangSau - thangTruoc) * 3000;
        if (uuTien == 1) {
            tien *= 0.95; // Giam 5% cho uu tiên 1
        } else if (uuTien == 2) {
            tien *= 0.9;  // Giam 10% cho uu tiên 2
        }
    }

private:
    int uuTien;
};

int main() {
    vector<KhachHang*> danhSachKhachHang;

    // Nhap thông tin danh sách các khách hàng
    int soLuongKhachHang;
    cout << "Nhap so long khách hàng: ";
    cin >> soLuongKhachHang;

    for (int i = 0; i < soLuongKhachHang; i++) {
        int maKhach, thangTruoc, thangSau, uuTien;
        string hoTen, diaChi;

        cout << "Nhap thông tin khách hàng #" << i + 1 << endl;
        cout << "Mã khách: ";
        cin >> maKhach;
        cin.ignore(); // Ð?c ký t? '\n' sau s? nguyên
        cout << "Ho tên: ";
        cin.ignore();
        getline(cin, hoTen);
        cout << "Ðia chi: ";
        getline(cin, diaChi);
        cout << "So tháng tru?c: ";
        cin >> thangTruoc;
        cout << "So tháng sau: ";
        cin >> thangSau;
        cout << "Uu tiên (0: không giam giá, 1: giam 5%, 2: giam 10%): ";
        cin >> uuTien;

        if (uuTien == 0) {
            danhSachKhachHang.push_back(new KhachHang(maKhach, hoTen, diaChi, thangTruoc, thangSau));
        } else {
            danhSachKhachHang.push_back(new KhachHangUuTien(maKhach, hoTen, diaChi, thangTruoc, thangSau, uuTien));
        }
    }

    // Tính tien cho tung khách hàng
    for (KhachHang* khachHang : danhSachKhachHang) {
        khachHang->TinhTien();
    }
    //Sap xep mang theo danh Sach
    sort(danhSachKhachHang.begin(), danhSachKhachHang.end(), [](const KhachHang* a, const KhachHang* b) {
        return a->LayTien() > b->LayTien();
    });

    // In danh sách khách hàng
    for (KhachHang* khachHang : danhSachKhachHang){
        khachHang->InThongTin();}
    }
        
