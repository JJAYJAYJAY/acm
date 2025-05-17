#include <iostream>
#include <unordered_map>
#include <any>
using namespace std;
int pos = 0;
string s;
struct Node {
    bool isInt;
    int val;
    unordered_map<string, Node> obj;
};

string getString() {
    pos++;
    string res;
    while (s[pos] != '"') res += s[pos++];
    pos++;
    return res;
}

int getInt() {
    int res = 0;
    while (pos < (int)s.size() && isdigit(s[pos])) {
        res = res * 10 + (s[pos] - '0');
        pos++;
    }
    return res;
}

Node getJson() {
    if (s[pos] == '{') {
        pos++;
        Node node;
        node.isInt = false;
        while (s[pos] != '}') {
            string key = getString();
            pos++;
            Node val = getJson();
            node.obj[key] = val;
            if (s[pos] == ',') pos++;
        }
        pos++;
        return node;
    } else {
        Node node;
        node.isInt = true;
        node.val = getInt();
        return node;
    }
}

void solve() {
    cin>>s;

    Node root = getJson();
    Node* cur = &root;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++) {
        string t;
        cin>>t;
        cur = &cur->obj[t];
    }
    cout<<cur->val<<endl;
}

int main() {
#ifdef LOCAL
    freopen("src/luogu/contest/LGR-226-Div4/in/T609495.in", "r", stdin);
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