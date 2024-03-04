#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

# define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int main() {
    int n, q;
    cin >> n >> q;

    dsu d(n);
    for (int i = 0; i < q; i++) {
        int t, u, v;
        cin >> t >> u >> v;

        if (t == 0) {
            d.merge(u, v);
        } else {
            if (d.same(u, v)) {
                cout << "1" << endl;
            } else {
                cout << "0" << endl;
            }
        }
    }
    return 0;
}