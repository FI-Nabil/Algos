
// Recursive
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
