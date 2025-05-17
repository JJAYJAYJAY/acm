#include <iostream>

using namespace std;

void solve() {
    int R,X;
    cin>>R>>X;
    if ((X == 1 && R >= 1600 && R <= 2999) ||
         (X == 2 && R >= 1200 && R <= 2399)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("src/atCode/BeginerContest405/in/A.in","r",stdin);
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