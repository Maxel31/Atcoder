#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    map<char,int> mp;
    mp['A'] = 0;
    mp['B'] = 3;
    mp['C'] = 4;
    mp['D'] = 8;
    mp['E'] = 9;
    mp['F'] = 14;
    mp['G'] = 23;

    char p,q;
    cin >> p >> q;
    cout << abs(mp[p] - mp[q]) << endl;
    return 0;
}