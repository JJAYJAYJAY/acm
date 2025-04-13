#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;
class BigInt {
public:
    // negative 为 true 表示负数，val 存储绝对值（无前导零，零储存为 "0"）
    bool negative;
    string val;

    BigInt() : negative(false), val("0") {}
    // 从字符串构造，可含'-'号
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
    // 从整型构造
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

    // 去除前导零，并保证 0 的符号为正
    void normalize() {
        int i = 0;
        while (i < (int)val.size()-1 && val[i]=='0') i++;
        val = val.substr(i);
        if(val=="0") negative = false;
    }

    // 仅处理非负数：返回 a + b 的和（字符串形式，a,b 为十进制数，均无前导零）
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
        // 去除前导零（理论上不会出现）
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
        // 同符号直接加
        if(negative == other.negative) {
            result.val = add_str(val, other.val);
            result.negative = negative;
        } else {
            // 异号相减：比较绝对值大小
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

    BigInt operator-(const BigInt &other) const {
        BigInt negOther = other;
        negOther.negative = !negOther.negative;
        return (*this) + negOther;
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
    BigInt& operator-=(const BigInt &other) {
        *this = *this - other;
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


int main(){
#ifdef LOCAL
    freopen("src/codeforce/Round1017(Div4)/in/G.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int q;
        cin >> q;
        deque<BigInt> a;
        BigInt ans("0"), sum("0");
        bool rev = false;
        while(q--){
            int op;
            cin >> op;
            if(op == 1){
                if(!rev) {
                    BigInt last = a.back();
                    a.pop_back();
                    a.push_front(last);
                    int factor = a.size() + 1;  // 转换为 int
                    ans = ans - (last * factor) + sum + last;
                } else {
                    BigInt first = a.front();
                    a.pop_front();
                    a.push_back(first);
                    int factor = a.size() + 1;
                    ans = ans - (first * factor) + sum + first;
                }
            } else if(op == 2){
                rev = !rev;
                int factor = a.size() + 1;
                ans = (sum * factor) - ans;
            } else if(op == 3){
                int x;
                cin >> x;
                BigInt bx(x);
                if(!rev) {
                    a.push_back(bx);
                    int factor = a.size();
                    ans = ans + (bx * factor);
                } else {
                    a.push_front(bx);
                    int factor = a.size();
                    ans = ans + (bx * factor);
                }
                sum = sum + bx;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}


//int main() {
//
//    int work = 1;
//    while (work--) {
//        solve();
//    }
//#ifdef LOCAL
//    fclose(stdin);
//#endif
//}