#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Sach {
private:
    string maso, tensach, tentacgia;

public:
    void nhap() {
        cin.ignore();
        getline(cin, tensach);
        getline(cin, tentacgia);
        cin >> maso;
    }

    void in() { 
        cout << tensach << " " << tentacgia << " " << maso << endl;
    }

    string getTenTacGia() {
        return tentacgia;
    }

    string getTenSach() {
        return tensach;
    }
};

void timkiem(const map<string, vector<Sach>>& mp) { 
    string s;
    cin.ignore();
    getline(cin, s);
    for (auto pair : mp) {
        if (pair.first == s) {
        	for( auto sach: pair.second)
        	{
        		sach.in();
			}
        }
    }
    cout << "Khong tim thay sach cua tac gia: " << s << endl;
}

int main() {
    int n;
    cin >> n;
    map<string, vector<Sach>> mp;
    Sach a[n];
    for (int i = 0; i < n; i++) {
        a[i].nhap();
        mp[a[i].getTenTacGia()].push_back(a[i]);
    }
    timkiem(mp);
    return 0;
}
