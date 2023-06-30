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
const long long INF = 1LL << 60;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
} // aとbを比較してbの方が大きい場合はaをbで更新する
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
} // aとbを比較してbの方が小さい場合はaをbで更新する

int N;
ll A[200009], B[200009]; // コイントスの成功回数，失敗回数

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    // 入力
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i] >> B[i];

    // コイントスの成功確率と番号の組みを作成
    vector<pair<pair<ll, ll>, int>> successRateAndIndex;
    for (int i = 1; i <= N; i++)
    {
        ll successRateNum = A[i];
        ll successRateDen = A[i] + B[i];
        ll commonDivisor = gcd(successRateNum, successRateDen);
        successRateNum /= commonDivisor;
        successRateDen /= commonDivisor;
        successRateAndIndex.push_back({{successRateNum, successRateDen}, i});
    }

    // ソート
    sort(successRateAndIndex.begin(), successRateAndIndex.end(), [](const pair<pair<ll, ll>, int> &a, const pair<pair<ll, ll>, int> &b) {
        if (a.first.first * b.first.second != a.first.second * b.first.first) {
            return a.first.first * b.first.second > a.first.second * b.first.first; // 成功確率の比較
        } else {
            return a.second < b.second; // 成功確率が同じ場合は番号の昇順にソート
        }
    });

    // 結果を出力
    for (const auto &p : successRateAndIndex)
    {
        cout << p.second << " ";
    }
    cout << endl;
    return 0;
}
