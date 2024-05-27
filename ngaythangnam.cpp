#include <iostream>
#include <string>
#define endl '\n'
#define space ' '
using namespace std;

struct Date {
    int ngay, thang, nam;
};

void nhap(Date &thongtin) {
    cin >> thongtin.ngay >> thongtin.thang >> thongtin.nam; 
}

bool checkNhap(Date &thongtin) {
    if (thongtin.ngay < 1 || thongtin.thang < 1 || thongtin.nam < 1900 || thongtin.nam > 2024) 
        return false;
    
    if (thongtin.thang > 12) 
        return false;
    
    if (thongtin.ngay > 31) 
        return false;
    
    if (thongtin.thang == 2 && ((thongtin.nam % 4 == 0 && thongtin.nam % 100 != 0) || thongtin.nam % 400 == 0)) {
        return thongtin.ngay <= 29;
    } else if (thongtin.thang == 2) {
        return thongtin.ngay <= 28;
    } else if (thongtin.thang == 4 || thongtin.thang == 6 || thongtin.thang == 9 || thongtin.thang == 11) {
        return thongtin.ngay <= 30;
    } else {
        return true;
    }
}

int thang(Date &thongtin) {
    if (thongtin.thang == 2) {
        if ((thongtin.nam % 4 == 0 && thongtin.nam % 100 != 0) || thongtin.nam % 400 == 0) {
            return 29;
        } else {
            return 28;
        }
    } else if (thongtin.thang == 4 || thongtin.thang == 6 || thongtin.thang == 9 || thongtin.thang == 11) {
        return 30;
    } else {
        return 31;
    }
}

void tangNgay(Date &thongtin, int soNgay) {
    thongtin.ngay += soNgay;
    while (thongtin.ngay > thang(thongtin)) {
        thongtin.ngay -= thang(thongtin);
        thongtin.thang++;
        if (thongtin.thang > 12) {
            thongtin.thang = 1;
            thongtin.nam++;
        }
    }
    cout << thongtin.ngay << space << thongtin.thang << space << thongtin.nam << endl;
}

void giamNgay(Date &thongtin, int soNgay) {
    while (soNgay > 0) {
        int soNgayTrongThang = thang(thongtin);
        
        if (soNgay >= thongtin.ngay) {
            soNgay -= thongtin.ngay;
            thongtin.ngay = 0;
        } else {
            thongtin.ngay -= soNgay;
            soNgay = 0;
        }
        
        if (thongtin.ngay == 0) {
            if (thongtin.thang > 1) {
                thongtin.thang--;
            } else {
                thongtin.thang = 12;
                thongtin.nam--;
            }
            thongtin.ngay = thang(thongtin);
        }
    }
    cout << thongtin.ngay << space << thongtin.thang << space << thongtin.nam << endl;
}

int kiemTraQuy(Date &thongtin) {
    if (thongtin.thang >= 1 && thongtin.thang <= 3) {
        return 1;
    } else if (thongtin.thang >= 4 && thongtin.thang <= 6) {
        return 2;
    } else if (thongtin.thang >= 7 && thongtin.thang <= 9) {
        return 3;
    } else if (thongtin.thang >= 10 && thongtin.thang <= 12) {
        return 4;
    } else {
        return -1;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Date thongtin;
    nhap(thongtin);
    bool checkIn = checkNhap(thongtin);
    if (checkIn) {
        cout << "HOP LE" << endl;
        int checkQuy = kiemTraQuy(thongtin);
        cout << checkQuy << endl;
        int checkThang = thang(thongtin);
        cout << checkThang << endl;
        tangNgay(thongtin, 1);
        giamNgay(thongtin, 2); 
    } else {
        cout << "KHONG HOP LE" << endl;
    }
    return 0;
}