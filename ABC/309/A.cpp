#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL<<60;

int main(){
    int A, B;
    cin >> A >> B;
    int diff = B - A;
    if(diff == 1 && A%3 != 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}