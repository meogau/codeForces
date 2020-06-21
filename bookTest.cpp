#include <bits/stdc++.h>
 
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define for1(i, n) for (int i = 1; i < (int)(n); i++)
#define fore(i, l, r) for (int i = (int)(l); i <= (int)(r); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef set<int> si;
typedef pair<int, int> pii;
typedef set<pii> spii;

int N;
int k, m;
int p[500];

int check(ll max_val) {
	ll sum = 0;
	int cnt = 1;
	for (int i = m - 1; i >= 0; --i) {
		if (sum + p[i] <= max_val) {
			sum += p[i];

		} else {
			sum = p[i];
			++cnt;
			if (sum > max_val) return 0;
		}
	}
	if (cnt > k) return 0;
	return 1;
}

int main() {

	cin >> N;
	forn(t, N) {
		cin >> m >> k;

		forn(i, m) cin >> p[i];

		ll left, right;
		left = 0;
		right = 5e9;
		while (right - left > 1) {
			ll mid = (right + left) / 2;
			if (check(mid)) {
				right = mid;
			} else {
				left = mid;
			}
		}

		stack<int> pos_slash;
		ll sum = 0;
		for (int i = m - 1; i >= 0; --i) {
			if (sum + p[i] <= right) {
				sum += p[i];
			} else {
				sum = p[i];
				pos_slash.push(i);
			}
		}
		
		int deficient_slash = k - pos_slash.size() - 1;
		int i = 0;
		while (deficient_slash) {
			cout << p[i] << "  / ";
			if (pos_slash.size() && pos_slash.top() == i) pos_slash.pop();
			else --deficient_slash;
			++i;
		}
		while (i < m) {
			cout << p[i] << " ";
			if (pos_slash.size() && pos_slash.top() == i) {
					cout << " / ";
					pos_slash.pop();
				}
			++i;
		}
		cout << "\n";

	}


	return 0;
}
