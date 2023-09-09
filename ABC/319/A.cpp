#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int main(){
    map<string, int> mp;
    mp["tourist"] = 3858;
    mp["ksun48"] = 3679;
    mp["Benq"] = 3658;
    mp["Um_nik"] = 3648;
    mp["apiad"] = 3638;
    mp["Stonefeang"] = 3630;
    mp["ecnerwala"] = 3613;
    mp["mnbvmar"] = 3555;
    mp["newbiedmy"] = 3516;
    mp["semiexp"] = 3481;

    string s;
    cin >> s;
    cout << mp[s] << endl;
    return 0;
}