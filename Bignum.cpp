#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
//cong;
string ADD(string a, string b){
      reverse(a.begin(),a.end());
      reverse(b.begin(),b.end());
      while (a.size() != b.size()){
            if (a.size() < b.size()) a.push_back('0');
            else b.push_back('0');
      }
      string res;
      int carry = 0;
      for(int i = 0; i < a.size(); i++){
            int temp = (a[i] - '0') + (b[i] - '0') + carry;
            int dv = temp % 10;
            carry = temp / 10;
            res.push_back(dv + '0');
      }
      if (carry != 0) res.push_back(carry + '0');
      reverse(res.begin(),res.end());
      return res;
}
bool isSmaller(string a, string b){
      if (a.size() < b.size()) return true;
      if (b.size() < a.size()) return false;
      return a < b;
}
//tru
string SUB(string a, string b){
      //So sanh
      bool sign = false;
      if (isSmaller(a,b)) {
            swap(a,b);
            sign = true;
      }
      reverse(a.begin(),a.end());
      reverse(b.begin(),b.end());
      //Chuan hoa du lieu
      while (a.size() != b.size()){
            if (a.size() < b.size()) a.push_back('0');
            else b.push_back('0');
      }
      int carry = 0;
      string res;
      for(int i = 0; i < a.size(); i++){
            int temp = (a[i]-'0') - (b[i] -'0' + carry);
            if (temp < 0){
                  temp += 10;
                  carry = 1;
            } 
            else carry = 0;
            res.push_back(temp + '0');
      }
      //Loai 0
      int n = res.size();
      while(res[n-1] =='0' && n > 1) {
            res.pop_back();
            n--;
      }

      if (sign) res.push_back('-');
      reverse(res.begin(),res.end());
      return res;
}
//chia
string MULINT(string a, int b){
      reverse(a.begin(),a.end());
      string res = "";
      int carry = 0;
      for(int i = 0; i < a.size(); i++){
            int temp = (a[i]-'0')*b + carry;
            int dv = temp % 10;
            carry = temp/10;
            res.push_back(dv + '0');
      }
      if (carry != 0) res.push_back(carry + '0');
      reverse(res.begin(), res.end());
      return res;
}
//nhan
string MULSTR(string a, string b){
      reverse(b.begin(), b.end());
      string res = "0";
      string bonus = "";
      for(int i = 0; i < b.size(); i++){
            string temp = MULINT(a,b[i]-'0') + bonus;
            res = ADD(res,temp);
            reverse(res.begin(),res.end());
            while(res[res.size() - 1] == '0' && res.size() > 1){
                  res.pop_back();
            }
            reverse(res.begin(),res.end());
            bonus += "0";
      }
      return res;
}
signed main()
{
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      string a,b;
      cout<<ADD(a,b);

}