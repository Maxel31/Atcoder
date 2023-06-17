#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    int A[300009];
    for(int i = 1; i <= 3 * N; i++) cin >> A[i];
    map<int,int> mp;
    map<int,int> mp2;

    for(int i = 1; i <= N; i++) mp[i] = 0;

    for(int i = 1; i <= 3 * N; i++){
        mp[A[i]]++;
        if(mp[A[i]] == 2) mp2[A[i]] = i;
    }

    // mp2.second順にソート
    vector<pair<int,int>> vec;
    for(auto itr = mp2.begin(); itr != mp2.end(); ++itr){
        vec.push_back(make_pair(itr->second, itr->first));
    }

    sort(vec.begin(), vec.end());

    for(int i = 0; i < N; i++){
        cout <<  vec[i].second << " ";
    }
    cout << endl;
    return 0;
}