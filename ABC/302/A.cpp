#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll A, B;
int main(){
    cin >> A >> B;
    if(A <= B) cout << 1 << endl;
    else if(A % B == 0) cout << A / B << endl;
    else cout << A / B + 1 << endl;
    return 0;
}