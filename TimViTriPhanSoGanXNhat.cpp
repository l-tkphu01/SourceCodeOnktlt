#include <iostream>
#include <cmath>

using namespace std;

struct Phanso {
    int t, m;
};

void nhap(Phanso arr[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i].t >> arr[i].m;
    }
}

int timsogannhat(Phanso arr[], int n, double x) {
    double sogan = fabs((double)arr[0].t / arr[0].m - x);
    int gannhat = 0;

    for (int i = 1; i < n; i++) {
        double sokhac = fabs((double)arr[i].t / arr[i].m - x);
        if (sokhac < sogan) {
            sogan = sokhac;
            gannhat = i;
        }
    }
    return gannhat;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    Phanso* arr = new Phanso[n]; 
    double x;
    cin >> x;
    nhap(arr, n);

    int gan = timsogannhat(arr, n, x);
    cout << gan;
    delete[] arr; 
    return 0;
}