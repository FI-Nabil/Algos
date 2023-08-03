ll n;
double a[3003];
double dp[3003][3003];
bool vis[3003][3003];

double rec(ll i, ll h) {
    if (i  == n + 1) {
        if (h > n / 2) return 1;
        else return 0;
    }
    if (vis[i][h]) return dp[i][h];
    double ans = a[i] * rec(i + 1, h + 1);
    ans += (1 - a[i]) * rec(i + 1, h);
    vis[i][h] = 1;
    return dp[i][h] = ans;

}

void dracarys() {
    cin >> n;
    for (ll i = 1; i <= n; i++) cin >> a[i];
    memset(vis, 0, sizeof vis);
  // rec(1,0)
    for (ll i = n + 1; i >= 1; i--) {
        for (ll h = n; h >= 0; h--) {
            if (i  == n + 1) {
                if (h > n / 2) dp[i][h] = 1;
                else dp[i][h] = 0;
                continue;
            }
            double ans = a[i] * dp[i + 1][h + 1]; // rec(i + 1, h + 1);
            ans += (1 - a[i]) * dp[i + 1][h]; // rec(i + 1, h);
            dp[i][h] = ans;
        }
    }
    cout << fixed << setprecision(10) << dp[1][0] << '\n';
}
