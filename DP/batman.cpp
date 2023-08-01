

string a, b, c;
ll dp[55][55][55];
// Recursive
ll lcs(ll i, ll j, ll k) {
    if (i == a.size() or j == b.size() or k == c.size())
        return 0;
    if (dp[i][j][k] != -1) return dp[i][j][k];

    if (a[i] == b[j] and a[i] == c[k]) {
        return 1 + lcs(i + 1, j + 1, k + 1);
    }
    ll ans = 0;
    ans = max(ans, lcs(i, j , k + 1));
    ans = max(ans, lcs(i, j + 1 , k));
    ans = max(ans, lcs(i + 1, j, k));
    return dp[i][j][k] = ans;
}
ll cs = 0;
void dracarys() {
    cin >> a >> b >> c;
    memset(dp, -1, sizeof dp);
   // cout << "Case " << ++cs << ": " << lcs(0, 0, 0) << '\n';

  // Iterative
    for (ll i = a.size() - 1; i >= 0; i--) {
        for (ll j = b.size() - 1; j >= 0; j--) {
            for (ll k = c.size() - 1; k >= 0; k--) {
                if (a[i] == b[j] and a[i] == c[k]) {
                    dp[i][j][k] = 1 + dp[i + 1][j + 1][k + 1];
                }
                else {
                    ll ans = 0;
                    ans = max(ans, dp[i][j][k + 1]);
                    ans = max(ans, dp[i][j + 1][k]);
                    ans = max(ans, dp[i + 1][j][k]);
                    dp[i][j][k] = ans;
                }
            }
        }
    }
    cout << "Case " << ++cs << ": " << dp[0][0][0] << '\n';
}
