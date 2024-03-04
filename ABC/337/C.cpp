#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int main(){
    int N;
    cin >> N;
    vector<int> A(300009);
    rep(i, N){
        cin >> A.at(i);
    }

    vector<int> B(N,N);
    int front;

    for(int i = 0; i < N; i++){
        A.at(i)--; // 0-indexed
        if (A.at(i) < 0){
            front = i;
        } else {
            B.at(A.at(i)) = i;
        }
    }

    while (front < N){
        cout << front+1 << " ";
        front = B.at(front);
    }

    cout << endl;
    return 0;
}