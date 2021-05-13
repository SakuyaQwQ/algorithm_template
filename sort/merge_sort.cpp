#include<unordered_map>
#include<vector>
#include<algorithm>
#include<iostream>
#include<map>
#include<set>
#include<string>
#include<cmath>

using namespace std;

int temp[100005];
int ans = 0;

void merge_sort(int l, int r, vector<int>& v) {

	if (l >= r)return;

	int m = (l + r) / 2;

	merge_sort(l, m, v);
	merge_sort(m + 1, r, v);

	int now = 0, i = l, j = m + 1;

	while (i <= m && j <= r) {
		if (v[i] <= v[j]) {
			temp[now++] = v[i++];
		}
		else {
			temp[now++] = v[j++];
			ans += m - i + 1;
		}
	}
	while (i <= m) temp[now++] = v[i++];
	while (j <= r) temp[now++] = v[j++];
	for (int k = 0, i = l; i <= r; ++i, ++k) {
		v[i] = temp[k];
	}
}


int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	merge_sort(0, n - 1, v);
	cout << ans << endl;
}
