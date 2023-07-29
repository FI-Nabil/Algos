ll n, q, d, m;
ll a[210];
ll dp[210][22][22];
// recursive
ll rec(ll i, ll cnt, ll sum) {

	if (cnt < 0) return 0;
	if (i < 1) {
		if (cnt == 0 and sum == 0) return 1;
		return 0;
	}
	if (dp[i][cnt][sum] != -1) return dp[i][cnt][sum];
	ll ans = rec(i - 1, cnt - 1, (sum + ((a[i] % d) + d) % d) % (d));
	ans += rec(i - 1, cnt, sum);
	return dp[i][cnt][sum] = ans;

}
ll cs = 0;
void dracarys() {
	cin >> n >> q;
	for (ll i = 1; i <= n; i++) {cin >> a[i];}
	cout << "Case " << ++cs << ":\n";
	while (q--) {
		cin >> d >> m;
		memset(dp, 0, sizeof dp);
   // cout << rec(n,m,0);

  // Iterative
		for (ll i = 0; i <= n; i++) {
			dp[i][0][0] = 1;
		}
		for (ll i = 1; i <= n; i++) {
			for (ll cnt = 1; cnt <= m; cnt++) {
				for (ll sum = 0; sum < d; sum++) {
					//ll ans = rec(i - 1, cnt - 1, (sum + ((a[i] % d) + d) % d) % (d));
					ll ans = dp[i - 1][cnt - 1][((sum + a[i]) % d + d) % d];
					if (ans < 0) ans = 0;
					// ans += rec(i - 1, cnt, sum);
					ans += dp[i - 1][cnt][sum];
					dp[i][cnt][sum] = ans;
				}
			}
		}
		cout << dp[n][m][0] << '\n';
	}

}
