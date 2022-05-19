#include <bits/stdc++.h>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> a;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int main() {
	cin >> n >> m;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		a[i].resize(m);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int max_height = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			max_height = max(max_height, a[i][j]);
		}
	}

	vector<vector<int>> mmax(n, vector<int>(m, -1));
	set<pair<int, pair<int,int>>> s;
	for (int i = 0; i < n; i++) {
		s.insert({a[i][0], {i, 0}});
		s.insert({a[i][m - 1], {i, m - 1}});
		mmax[i][0] = a[i][0];
		mmax[i][m - 1] = a[i][m - 1];
	}
	for (int i = 0; i < m; i++) {
		s.insert({a[0][i], {0, i}});
		s.insert({a[n - 1][i], {n - 1, i}});
		mmax[0][i] = a[0][i];
		mmax[n - 1][i] = a[n - 1][i];
	}
	while (!s.empty()) {
		auto x = s.begin();
		int i = x->second.first;
		int j = x->second.second;
		s.erase(s.begin());
		for (int k = 0; k < 4; ++k) {
			int ri = i + dx[k];
			int rj = j + dy[k];
			if (ri >= 0 && rj >= 0 && ri < n && rj < m && mmax[ri][rj] == -1) {
				mmax[ri][rj] = max(mmax[i][j], a[ri][rj]);
				s.insert({mmax[ri][rj], {ri, rj}});
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans += mmax[i][j] - a[i][j];
		}
	}
	cout << ans << '\n';

	return 0;
}
