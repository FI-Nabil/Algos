string s, t;
bool vis[105][105];
string dp[105][105];

string lcs(ll i, ll j) {
	if (i >= s.size() or j >= t.size()) return "";
	if (vis[i][j]) return dp[i][j];
	string ans; ans = "";
	if (s[i] == t[j]) {
		ans = string(1, s[i]) + lcs(i + 1, j + 1);
	}
	else {
		string x = lcs(i + 1, j);
		string y = lcs(i, j + 1);
		if (x.size() == y.size()) {
			ans = min(x, y);
		}
		else if (x.size() < y.size()) {
			ans = y;
		}
		else ans = x;
	}
	vis[i][j] = 1;
	return dp[i][j] = ans;
}
ll cs = 0;
void dracarys() {
	cin >> s >> t;
	memset(vis, 0, sizeof vis);
	string str = lcs(0, 0);
	cout << "Case " << ++cs << ": ";
	if (str.size() == 0) str = ":(";
	cout << str << '\n';

}


