#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
    return a > b;
}

void nhap(int a[], int b[], int n) {
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n, compare);
}

int main() {
    const int max_n = 100000;
    int n;
    cin >> n;
    int a[max_n], b[max_n];
    nhap(a, b, n);
    long long res = 0;
    for(int i = 0; i < n; i++) {
        res += (long long)a[i] * b[i];
    }
    cout << res;
    return 0;
}