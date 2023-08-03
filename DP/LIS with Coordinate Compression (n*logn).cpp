// Problem : https://vjudge.net/contest/476645#problem/AE

map<ll, ll>mp;
ll n;
const ll N = 2e5 + 10;
ll a[N];
ll inf = 1e16;
struct val
{
    ll mxx;
    ll freq;
} tr[4 * N];

void build (ll node, ll b, ll e) {
    if (b == e) {
        tr[node].mxx = a[b];
        return;
    }
    ll mid = (b + e) / 2;
    ll left_node = 2 * node;
    ll right_node = left_node + 1;
    build(left_node, b, mid);
    build(right_node, mid + 1, e);

    tr[node].mxx = max(tr[left_node].mxx , tr[right_node].mxx);

}

void update(ll node, ll b, ll e, ll ind, ll new_val) {
    if (ind > e or ind < b)
        return;
    if (b == e and b == ind) {
        tr[node].mxx = new_val;
        return;
    }

    ll mid = (b + e) / 2;
    ll left_node = 2 * node;
    ll right_node = left_node + 1;
    update(left_node, b, mid, ind, new_val);
    update(right_node, mid + 1, e, ind, new_val);
    tr [node].mxx = max( tr[left_node].mxx , tr[right_node].mxx);
}

ll query(ll node, ll b, ll e, ll i, ll j) {
    if (e<i or b>j) {
        return 0;
    }
    if (b >= i and e <= j) {
        return tr[node].mxx;
    }

    ll mid = (b + e) / 2;
    ll left_node = 2 * node;
    ll right_node = left_node + 1;

    ll left_max = query(left_node, b, mid, i, j);
    ll right_max = query(right_node, mid + 1, e, i, j);
    ll mn = max(left_max , right_max);
    return mn;
}



void dracarys() {
    cin >> n;
    vector<ll>v;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i]; v.pb(a[i]);
    }
    sort(v.begin(), v.end());
    ll id = 1;
    for (auto u : v) {
        if (mp[u] == 0) mp[u] = id++;
    }
    ll dp[n + 1];
    ll res = 0;
    memset(dp, 0, sizeof dp);
    for (ll i = 1; i <= n; i++) {
        ll ans = query(1, 1, N, 1, mp[a[i]] - 1) + 1;
        dp[i] = max(1LL, ans);
        update(1, 1, N, mp[a[i]], dp[i]);
        res = max(res, dp[i]);
    }
    cout << res << '\n';
}
