#include <iostream>
#include "algorithm"
using namespace std;
class BigInt {
public:
    bool negative;
    string val;

    BigInt() : negative(false), val("0") {}
    BigInt(const string &s) {
        if (!s.empty() && s[0]=='-') {
            negative = true;
            val = s.substr(1);
        } else {
            negative = false;
            val = s;
        }
        normalize();
    }
    BigInt(int num) {
        if(num < 0) {
            negative = true;
            num = -num;
        } else {
            negative = false;
        }
        if(num == 0) {
            val = "0";
        } else {
            string s;
            while(num > 0) {
                s.push_back('0' + num % 10);
                num /= 10;
            }
            reverse(s.begin(), s.end());
            val = s;
        }
    }
    BigInt(const BigInt &other) : negative(other.negative), val(other.val) {}

    void normalize() {
        int i = 0;
        while (i < (int)val.size()-1 && val[i]=='0') i++;
        val = val.substr(i);
        if(val=="0") negative = false;
    }

    static string add_str(const string &a, const string &b) {
        int i = a.size()-1, j = b.size()-1, carry = 0;
        string res;
        while(i >= 0 || j >= 0 || carry) {
            int x = (i >= 0) ? a[i]-'0' : 0;
            int y = (j >= 0) ? b[j]-'0' : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            res.push_back('0' + sum % 10);
            i--; j--;
        }
        reverse(res.begin(), res.end());
        int pos = 0;
        while(pos < res.size()-1 && res[pos]=='0') pos++;
        return res.substr(pos);
    }

    static int compare_str(const string &a, const string &b) {
        if(a.size() != b.size()) return a.size() < b.size() ? -1 : 1;
        if(a==b) return 0;
        return a < b ? -1 : 1;
    }

    static string sub_str(const string &a, const string &b) {
        int i = a.size()-1, j = b.size()-1;
        int carry = 0;
        string res;
        while(i >= 0) {
            int x = a[i] - '0';
            int y = (j >= 0) ? b[j] - '0' : 0;
            int sub = x - y - carry;
            if(sub < 0) { sub += 10; carry = 1; } else { carry = 0; }
            res.push_back('0' + sub);
            i--; j--;
        }
        reverse(res.begin(), res.end());
        int pos = 0;
        while(pos < res.size()-1 && res[pos]=='0') pos++;
        return res.substr(pos);
    }

    static string mul_str(const string &a, int b) {
        if(b == 0 || a=="0") return "0";
        int carry = 0;
        string res;
        for (int i = a.size()-1; i >= 0; i--) {
            int prod = (a[i]-'0') * b + carry;
            carry = prod / 10;
            res.push_back('0' + prod % 10);
        }
        while(carry){
            res.push_back('0' + carry % 10);
            carry /= 10;
        }
        reverse(res.begin(), res.end());
        int pos = 0;
        while(pos < res.size()-1 && res[pos]=='0') pos++;
        return res.substr(pos);
    }

    BigInt operator+(const BigInt &other) const {
        BigInt result;
        if(negative == other.negative) {
            result.val = add_str(val, other.val);
            result.negative = negative;
        } else {
            int cmp = compare_str(val, other.val);
            if(cmp == 0) {
                result.val = "0";
                result.negative = false;
            } else if(cmp > 0) { // |*this| > |other|
                result.val = sub_str(val, other.val);
                result.negative = negative;
            } else {
                result.val = sub_str(other.val, val);
                result.negative = other.negative;
            }
        }
        result.normalize();
        return result;
    }

    BigInt operator*(int b) const {
        BigInt result;
        if(b < 0) {
            result = (*this) * (-b);
            result.negative = !result.negative;
            return result;
        }
        result.val = mul_str(val, b);
        result.negative = negative;
        if(result.val=="0") result.negative = false;
        return result;
    }


    BigInt& operator+=(const BigInt &other) {
        *this = *this + other;
        return *this;
    }
    BigInt& operator*=(int b) {
        *this = *this * b;
        return *this;
    }
};

ostream& operator<<(ostream &os, const BigInt &bi) {
    if(bi.negative && bi.val != "0") os << '-';
    os << bi.val;
    return os;
}

void solve() {
    int n;
    cin>>n;
    BigInt p=0,ans=0;
    for(int i=0;i<n;i++){
        long long x;
        cin>>x;
        ans += p * x;
        p += x;
    }
    cout<<ans<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/atCode/BeginerContest405/in/C.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int work = 1;
    while (work--) {
        solve();
    }
#ifdef LOCAL
    fclose(stdin);
#endif
}