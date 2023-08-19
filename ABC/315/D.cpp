#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// using P = pair<int, int>;
const long long INF = 1LL<<60;

int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<char>> c(h, vector<char>(w));
	rep(i, h) rep(j, w) cin >> c[i][j];
	vector<vector<int>> x(h, vector<int>(26));
	vector<vector<int>> y(w, vector<int>(26));
	rep(i, h) rep(j, w) {
		x[i][c[i][j] - 'a']++;
		y[j][c[i][j] - 'a']++;
	}
	int hc = h, wc = w;
	vector<bool> fx(h), fy(w);
	rep(_, h + w) {
		vector<pair<int, int>> ux, uy;
		rep(i, h) {
			if (fx[i]) continue;
			rep(j, 26) {
				if (x[i][j] == wc && wc >= 2) {
					ux.push_back({ i, j });
				}
			}
		}
		rep(i, w) {
			if (fy[i]) continue;
			rep(j, 26) {
				if (y[i][j] == hc && hc >= 2) {
					uy.push_back({ i, j });
				}
			}
		}
		for (pair<int, int> p : ux) {
			fx[p.first] = true;
			rep(i, w) y[i][p.second]--;
			hc--;
		}
		for (pair<int, int> p : uy) {
			fy[p.first] = true;
			rep(i, h) x[i][p.second]--;
			wc--;
		}
	}
	cout << hc * wc << '\n';
}