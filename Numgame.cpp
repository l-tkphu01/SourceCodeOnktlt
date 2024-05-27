#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    int b[100005], c[100005];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }


    sort(c, c + n);

    int giatrinho = 2000000000; 
    for (int i = 0; i < n; i++) {

        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int sum = b[i] + c[mid];


            giatrinho = min(giatrinho, abs(sum));

            if (sum < 0) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }

    cout << giatrinho;

    return 0;
}