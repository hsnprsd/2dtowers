#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> a;

vector<vector<bool>> visited;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

void dfs(int i, int j, int x) {
	visited[i][j] = true;
	for (int d = 0; d < 4; d++) {
		int sx = dx[d] + i;
		int sy = dy[d] + j;
		if (sx >= 0 && sy >= 0 && sx < n && sy < m && a[sx][sy] < x && !visited[sx][sy]) {
			dfs(sx, sy, x);
		}
	}
}

bool is_valid(int i, int j, int x) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}

	dfs(i, j, x);

	bool bad = false;
	for (int i = 0; i < n && !bad; i++) {
		if (visited[i][0] || visited[i][m - 1]) {
			bad = true;
		}
	}
	for (int i = 0; i < m && !bad; i++) {
		if (visited[0][i] || visited[n - 1][i]) {
			bad = true;
		}
	}
	return !bad;
}

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

	visited.resize(n);
	for (int i = 0; i < n; i++) {
		visited[i].resize(m);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int x = a[i][j] + 1; x <= max_height + 1; x++) {
				if (!is_valid(i, j, x)) {
					ans += x - a[i][j] - 1;
					break;
				}
			}

		}
	}

	cout << ans << '\n';

	return 0;
}
