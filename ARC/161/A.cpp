#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    // 入力
    int N;
    cin >> N;
    int A[200009];
    for(int i = 1; i <= N; i++) cin >> A[i];

    // 偶数番目の要素が隣接する奇数番目の要素より大きくなるように並び替えられるか
    vector<int> B, C;
    sort(A + 1, A + N + 1);
    for(int i = 1; i <= N/2+1; i++){
        B.push_back(A[i]); // 奇数番目
    }
    for(int i = N/2 + 2; i <= N; i++){
        C.push_back(A[i]); // 偶数番目
    }
    

    bool flag = true;
    for(int i = 0; i < C.size(); i++){
        if(C[i] <= B[i+1]){
            flag = false;
            break;
        }
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}