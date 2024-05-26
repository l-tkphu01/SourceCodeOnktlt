#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

int main() {
    const int max_s = 10000000;
    int s, n;
    cin >>n>>s;

      if (s == 0) {
        if (n == 1) {
            cout << "0\n";
        } else {
            cout << "-1\n";
        }
        return 0;
    }
        
    if (s > 9 * n) {cout << "-1" << endl;  return 0;}

    string res(n, '0');
    for (int i = 0; i < n; ++i) {
        int dig = min(s, 9);
        res[i] += dig;
        s -= dig;
    }
    cout << res << endl;
    return 0;
}