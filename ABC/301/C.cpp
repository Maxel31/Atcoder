#include <bits/stdc++.h>
using namespace std;
int main(){
    string S;
    cin >> S;
    string T;
    cin >> T;
    int N = S.size();
    vector<int> cntS(26, 0), cntT(26, 0);
    for (int i = 0; i < N; i++){
        if (S[i] != '@'){
        cntS[S[i] - 'a']++;
        }
        if (T[i] != '@'){
        cntT[T[i] - 'a']++;
        }
    }
    bool ok = true;
    int s = 0;
    for (int i = 0; i < 26; i++){
        s += max(cntS[i], cntT[i]);
    }
    if (s > N){
        ok = false;
    }
    string x = "atcoder";
    for (int i = 0; i < 26; i++){
        bool ok2 = false;
        for (int j = 0; j < 7; j++){
        if (x[j] == 'a' + i){
            ok2 = true;
        }
        }
        if (!ok2 && cntS[i] != cntT[i]){
        ok = false;
        }
    }
    if (ok){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}