#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

bool isPalindrome(string str) {
    string reversed = str;
    reverse(reversed.begin(), reversed.end());
    return str == reversed;
}

int main() {
    int N;
    cin >> N;
    
    vector<string> S(N);
    for (int i = 0; i < N; i++)
        cin >> S[i];
    
    // S[i] と S[j] を繋げて回文になるかどうかを判定する
    bool flag = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j && isPalindrome(S[i] + S[j])) {
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    return 0;
}
