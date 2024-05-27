#include <bits/stdc++.h>
#define endl '\n'
using namespace std;



signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string so;
    cin>>so;
    long long d=so.size();
    cout<<d<<endl;
    int s=0;
    for (int i=0;i<d;i++){
        s=s+(so[i]-'0');
    }
    long long a = stoll(so); //stoll chuyển kiểu string sang long long
    long long k = floor(log2(a)); //floor hàm lam2 tron2
    if (pow(2, k) > a) {
        k--;
    }
    cout<<s<<endl;
    long long n=stoll(so);
    cout<<k;
    return 0;
}