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
        cout << "M� kh�ch: " << maKhach << endl;
        cout << "Ho t�n: " << hoTen << endl;
        cout << "�ia chi: " << diaChi << endl;
        cout << "So th�ng truoc: " << thangTruoc << endl;
        cout << "So th�ng sau: " << thangSau << endl;
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
            tien *= 0.95; // Giam 5% cho uu ti�n 1
        } else if (uuTien == 2) {
            tien *= 0.9;  // Giam 10% cho uu ti�n 2
        }
    }

private:
    int uuTien;
};

int main() {
    vector<KhachHang*> danhSachKhachHang;

    // Nhap th�ng tin danh s�ch c�c kh�ch h�ng
    int soLuongKhachHang;
    cout << "Nhap so long kh�ch h�ng: ";
    cin >> soLuongKhachHang;

    for (int i = 0; i < soLuongKhachHang; i++) {
        int maKhach, thangTruoc, thangSau, uuTien;
        string hoTen, diaChi;

        cout << "Nhap th�ng tin kh�ch h�ng #" << i + 1 << endl;
        cout << "M� kh�ch: ";
        cin >> maKhach;
        cin.ignore(); // �?c k� t? '\n' sau s? nguy�n
        cout << "Ho t�n: ";
        cin.ignore();
        getline(cin, hoTen);
        cout << "�ia chi: ";
        getline(cin, diaChi);
        cout << "So th�ng tru?c: ";
        cin >> thangTruoc;
        cout << "So th�ng sau: ";
        cin >> thangSau;
        cout << "Uu ti�n (0: kh�ng giam gi�, 1: giam 5%, 2: giam 10%): ";
        cin >> uuTien;

        if (uuTien == 0) {
            danhSachKhachHang.push_back(new KhachHang(maKhach, hoTen, diaChi, thangTruoc, thangSau));
        } else {
            danhSachKhachHang.push_back(new KhachHangUuTien(maKhach, hoTen, diaChi, thangTruoc, thangSau, uuTien));
        }
    }

    // T�nh tien cho tung kh�ch h�ng
    for (KhachHang* khachHang : danhSachKhachHang) {
        khachHang->TinhTien();
    }
    //Sap xep mang theo danh Sach
    sort(danhSachKhachHang.begin(), danhSachKhachHang.end(), [](const KhachHang* a, const KhachHang* b) {
        return a->LayTien() > b->LayTien();
    });

    // In danh s�ch kh�ch h�ng
    for (KhachHang* khachHang : danhSachKhachHang){
        khachHang->InThongTin();}
    }
        
