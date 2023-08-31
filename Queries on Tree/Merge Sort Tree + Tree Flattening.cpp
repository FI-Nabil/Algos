/*
https://vjudge.net/problem/Toph-tree-queries

a tree is given, with value of every node.
find the number of element greater than k-1 of a sub-tree v for every query 

Input :

3 2
1 2
5 6 7
1 3
1 6

Output :

3
2

*/


#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
#define ll long long
typedef tree<ll, null_type, greater_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
const ll MAXN = 1e6 + 10;

ll a[MAXN];
ll val[MAXN];
ll FT[MAXN * 2];
ll Start[MAXN];
ll End[MAXN];

vector<ll>g[MAXN * 4], gp[MAXN];

void build (ll node, ll b, ll e) {

    if (b == e) {
        g[node].pb(val[b]);
        return;
    }
    ll left_node = 2 * node;
    ll right_node = 2 * node + 1;
    ll mid = (b + e) / 2;
    build(left_node, b, mid);
    build (right_node, mid + 1, e);
    g[node].resize(g[left_node].size() + g[right_node].size());
    merge(g[left_node].begin(), g[left_node].end(), g[right_node].begin(), g[right_node].end(), g[node].begin());

}
ll query(ll node, ll b, ll e, ll i , ll j, ll k) {
    if (e<i or b>j) return 0;
    if (b >= i and e <= j) {
        // returning the number of values which is greater than k-1
        ll ans = g[node].end() - lower_bound(g[node].begin(), g[node].end(), k);
        return ans;
    }
    ll mid = (b + e) / 2;
    ll left_node = 2 * node;
    ll right_node = left_node + 1;
    return query(left_node , b , mid , i, j, k ) + query (right_node , mid + 1, e, i, j, k);
}
ll timer = 0;

// Tree Flattening
/*
after flattening, every node will have a starting index and ending index like -
1 2 2 3 4 4 3 1
Now I can make operation on any subtree of a node
*/
void dfs(ll node, ll par) {

    Start[node] = timer;
    FT[timer] = node;
    timer++;
    for (auto child : gp[node])
        if (child != par) dfs(child, node);
    End[node] = timer;
    FT[timer] = node;
    timer++;
}



void solve() {
    ll n, q; cin >> n >> q;
    for (ll i = 2; i <= n; i++) {
        ll x; cin >> x;
        gp[x].pb(i);
        gp[i].pb(x);
    }
    for (ll i = 1; i <= n; i++)
        cin >> a[i];

    dfs(1, -1);
    for (ll i = 0; i < timer; i++) {
        val[i + 1] = a[FT[i]];
    }
    build(1, 1, timer);

    while (q--) {

        ll in, k; cin >> in >> k;
        cout << query(1, 1, timer, Start[in] + 1, End[in] + 1, k) / 2 << '\n';

    }


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll tc = 1; //cin >> tc;
    while (tc--) {
        solve();
    }
}
