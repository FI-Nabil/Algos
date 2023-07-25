
// Recursive (Top-Down)
const ll inf = 1e9+10;
const ll sz = 5e3+1;
ll dp[sz][sz];
string a,b;
ll n, m;
// rec(i, j) --> min operation required to convert a[i.....n-1] to b[j.....m-1]
ll rec (ll i, ll j){
    if(i== n and j == m){
      return 0;
    }
    if(i== n) return m-j;
    if(j==m) return n-i;

  if(dp[i][j] != -1) return dp[i][j];
  ll ans = inf;
  if(a[i] == b[j]) ans = rec(i+1, j+1);
    // replace a[i]
    ll replace = 1 + rec(i+1, j+1);
  // remove a[i]
    ll remove = 1 + rec(i+1, j);
  // add a new char (=b[j]) right before a[i]
    ll add = 1 + rec(i, j+1);
    replace = min(ans, replace);
    ans = min(replace, min(remove, add));
  
  return dp[i][j] = ans;
}

void dracarys(){
  cin >> a >> b;  
  memset(dp, -1 , sizeof dp);
  n = a.size();
  m = b.size();
  cout << rec(0, 0) << '\n';  
}

// Recursive (Bottom-Top)
ll rec(ll n, ll m){
	if(n < 0 and m < 0) return 0;
	if( n < 0) return m+1;
	if(m<0) return n+1;
	if(dp[n][m] != -1) return dp[n][m];

	ll ans = inf;
	if(a[n]==b[m]) ans = rec(n-1, m-1);
	ll add = 1 + rec(n, m-1);
	ll del = 1 + rec(n-1, m);
	ll rep = 1 + rec(n-1, m-1);
	ans = min(ans, add);
	ans = min(ans, min(del, rep));
	return dp[n][m] = ans;
}

// Iterative 
void dracarys(){
	
	memset(dp, -1, sizeof dp);
	cin >> a >> b;
	n = a.size();
	m = b.size();
	a = '#' + a;
	b = '#' + b;
	dp[0][0] = 0;
	for (ll i=1; i<=n; i++) dp[i][0] = i;
	for (ll j=1; j <= m; j++) dp[0][j] = j;

	for (ll i=1; i<=n; i++){
		for (ll j=1; j<=m; j++){
				ll ans = inf;
				if(a[i]==b[j]) ans = dp[i-1][j-1];
				ll add = 1 + dp[i][j-1]; //rec(n, m-1);
				ll del = 1 + dp[i-1][j]; //rec(n-1, m);
				ll rep = 1 + dp[i-1][j-1]; //rec(n-1, m-1);
				ans = min(ans, add);
				ans = min(ans, min(del, rep));
			   dp[i][j] = ans;
		}
	}
	cout << dp[n][m] << '\n';
}
