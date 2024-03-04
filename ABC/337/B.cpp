#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int main(){
    string S;
    cin >> S;

    string S_sorted = S;
    sort(S_sorted.begin(), S_sorted.end());

    if (S == S_sorted){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}