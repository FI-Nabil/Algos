const ll sz = 1e6 + 10;
ll parent[sz], SIZE[sz];
// get the ultimate parent of x
ll get(ll x) {
    if (parent[x] == x) return x;
    else return parent[x] = get(parent[x]);
}

void join(ll a, ll b) {
    ll ulp_a = get(a); // ultimate parent of a
    ll ulp_b = get(b); 
    if (ulp_a == ulp_b) return;
    // replacing the parent of smaller size to the parent of greater size
    if (SIZE[ulp_a] < SIZE[ulp_b])swap(ulp_a, ulp_b);
    parent[ulp_b] = ulp_a;
    SIZE[ulp_a] += SIZE[ulp_b];
}

void solve() {
    ll n; cin >> n;
    ll a[n + 1];
    for (ll i = 0; i < sz; i++) {
        parent[i] = i;
        SIZE[i] = 1;
    }
    set<ll>nodes;
    for (ll i = 1; i <= n; i++) {
        ll x, y; cin >> x >> y;
        join(x, y);
        nodes.insert(x);
        nodes.insert(y);
    }
    set<ll>S;
    for(auto nd : nodes) S.insert(get(nd));
    cout << S.size() << '\n';
}
