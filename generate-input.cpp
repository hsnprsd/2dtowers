#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
	int seed = atoi(argv[1]);
	srand(seed);

	int n, m;
	cin >> n >> m;
	cout << n << ' ' << m << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << rand() % 128 << ' ';
		}
		cout << '\n';
	}
	return 0;
}
