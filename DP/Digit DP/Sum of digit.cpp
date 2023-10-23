#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ff first
#define ss second
#define pb push_back
#define pf push_front
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define YES cout <<"YES\n"
#define NO cout <<"NO\n"
#define inf 1e18
typedef tree<ll, null_type, greater_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;


ll cnt (string& R, ll n, bool tight) {
    if (tight == 0)
        return (pow(10, n) + 0.1);
    if (n == 0) return 1;
    ll numbers = 0;
    ll ub =  (R[R.length() - n] - '0');
    for (ll dig = 0; dig <= ub; dig++) {
        numbers += cnt(R, n - 1, (tight & (dig == ub)));
    }
    return numbers;
}

ll dp[20][2];
ll solve(string& R, ll n, bool tight) {
    if (n == 0) return 0;
    if (dp[n][tight] != -1) return dp[n][tight];
    ll ub = tight ? (R[R.length() - n] - '0') : 9;
    ll total = 0;
    for (ll dig = 0; dig <= ub; dig++) {
        total += dig * cnt(R, n - 1, (tight & (dig == ub)));
        total += solve(R, n - 1, (tight & (dig == ub)));
    }
    return  dp[n][tight] = total;
}

void dracarys() {
    ll l , r;
    cin >> l >> r;
    if (l != 0) l--;
    string L = to_string(l);
    string R = to_string(r);
    memset(dp, -1, sizeof dp);
    ll sodR = solve(R, R.length(), 1);
    memset(dp, -1, sizeof dp);
    ll sodL = solve(L, L.length(), 1);
    cout << sodR - sodL << '\n';

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll tc = 1;  cin >> tc;
    while (tc--) {
        dracarys();
    }
}
