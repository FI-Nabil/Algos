

/* Iterative */
ll n, weight;
ll v[101], w[101];
const ll mx = 1e5 +10;
const ll inf = 1e12;
ll dp[101][mx];
void dracarys(){
        cin >> n >> weight;
        for (ll i=1; i<=n; i++){
            cin >> w[i] >> v[i];
        }
        memset(dp, -1, sizeof dp);
        for (ll i=0; i<=n; i++) dp[i][0] = 0;
        ll ans = 0;
        for (ll val=1; val<=mx-5; val++){
            for (ll j=1; j<=n; j++){
                ll wt = inf;
                   if(val-v[j] >= 0 and dp[j-1][val-v[j]] != -1)
                   wt = w[j] + dp[j-1][val-v[j]]; 
                   if(dp[j-1][val] != -1)
                   wt = min(wt, dp[j-1][val]);
                dp[j][val] = wt;
            }
            if(dp[n][val] <= weight) ans = max(ans, val);
        }
        cout << ans <<'\n';
}
