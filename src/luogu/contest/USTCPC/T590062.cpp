#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> P(n + 1);
    for (int i = 0; i <= n; ++i) {
        cin >> P[i];
    }

    vector<int> Q;
    vector<int> P_work = P;

    while (P_work.size() >= 3) {
        int deg = P_work.size() - 1;
        int coeff = P_work.back();
        int term_deg = deg - 2;
        if (Q.size() <= term_deg) {
            Q.resize(term_deg + 1, 0);
        }
        Q[term_deg] += coeff;
        if (P_work.size() < term_deg + 3) {
            P_work.resize(term_deg + 3, 0);
        }
        P_work[term_deg] -= coeff;
        P_work[term_deg + 2] -= coeff;
        while (!P_work.empty() && P_work.back() == 0) {
            P_work.pop_back();
        }
    }

    int c = (P_work.size() > 0) ? P_work[0] : 0;
    int d = (P_work.size() > 1) ? P_work[1] : 0;

    double integral_Q = 0.0;
    for (int k = 0; k < Q.size(); ++k) {
        integral_Q += Q[k] / (k + 1.0);
    }

    double integral_R = c * atan(1.0) + (d / 2.0) * log(2.0);

    double result = integral_Q + integral_R;

    cout << fixed << setprecision(10) << result << endl;

    return 0;
}