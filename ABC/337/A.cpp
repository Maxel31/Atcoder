#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int main(){
    int N;
    cin >> N;
    vector<int> X(109), Y(109);
    rep(i, N) cin >> X.at(i) >> Y.at(i);

    int T_Score = 0, A_Score = 0;

    rep(i, N){
        T_Score += X.at(i);
        A_Score += Y.at(i);
    }

    if (T_Score > A_Score){
        cout << "Takahashi" << endl;
    } else if (T_Score < A_Score) {
        cout << "Aoki" << endl;
    } else {
        cout << "Draw" << endl;
    }

    return 0;
}