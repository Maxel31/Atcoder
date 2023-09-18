#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int power (int a, int b){
    int ans = 1;
    rep(i, b){
        ans *= a;
    }
    return ans;
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << power(a,b) + power(b,a) << endl;
    return 0;
}