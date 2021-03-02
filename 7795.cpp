/*will eat or will be eaten*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int t, n, m, life1, life2;
int left, right, mid, ans, result;
vector <int> a, b;
void input() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &life1);
		a.push_back(life1);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &life2);
		b.push_back(life2);
	}
}
int binary() {
	sort(b.begin(), b.end());
	for (int i = 0; i < a.size(); i++) {
		int current = a[i];
		left = 0;
		right = b.size() - 1;
		ans = 0;
		while (left <= right) {
			mid = (left + right) / 2;
			if (current > b[mid]) {
				left = mid + 1;
				ans = mid + 1;
			}
			else{
				right = mid - 1;
			}
		}
		result += ans;
	}
	return result;
}
int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		input();
		printf("%d\n", binary());
		a.clear();
		b.clear();
		result = 0;
	}

	return 0;
}