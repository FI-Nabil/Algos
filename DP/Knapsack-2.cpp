/* Recursive */
/*
1. rec(i, val) returns minimum weight, taking any subsets from 1........i
2. masximum value which retursn (weight <= given_weight) is the answer.
*/


ll n, weight;
ll v[101], w[101];
const ll mx = 1e5 +10;
const ll inf = 1e12;
ll dp[101][mx];
ll rec (ll i, ll val){
    if(val == 0) return 0;
    if(val < 0 or i == 0) return inf;
    if(dp[i][val] != -1) return dp[i][val];

    ll wt = 0;
    wt = w[i] + rec(i-1, val-v[i]);
    wt = min(wt, rec(i-1, val));
    return dp[i][val] = wt;
}

void dracarys(){
        cin >> n >> weight;
        for (ll i=1; i<=n; i++){
            cin >> w[i] >> v[i];
        }
        memset(dp, -1, sizeof dp);
        for (ll i=mx-5; i>=0; i--){
            if(rec(n, i) <= weight){
                cout << i <<'\n';
                return;
            }
        }
}


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
