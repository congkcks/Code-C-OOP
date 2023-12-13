#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Sach {
public:
    string tieude;
    string tacgia;
    float gia;
    bool cosan;

    Sach(string tieude, string tacgia, float gia) : tieude(tieude), tacgia(tacgia), gia(gia), cosan(true) {}
};

class NguoiMuon {
public:
    string ten;
    string diachi;
    string sodienthoai;
    vector<Sach*> sachdamuon;

    NguoiMuon(string ten, string diachi, string sodienthoai) : ten(ten), diachi(diachi), sodienthoai(sodienthoai) {}
};

class ThuVien {
public:
    vector<Sach> sach;
    vector<NguoiMuon> nguoimuon;

    void themSach(Sach s) {
        sach.push_back(s);
    }

    void themNguoiMuon(NguoiMuon nm) {
        nguoimuon.push_back(nm);
    }

    // Các phuong th?c khác nhu xoaSach, capnhatSach, timkiemSach, muonSach, traSach, etc.
};

int main() {
    ThuVien thuVien;
    thuVien.themSach(Sach("Sach 1", "Tac gia 1", 100.0));
    thuVien.themNguoiMuon(NguoiMuon("Nguoi muon 1", "Dia chi 1", "0123456789"));

    // Th?c hi?n các thao tác khác trên thu vi?n

    return 0;
}

