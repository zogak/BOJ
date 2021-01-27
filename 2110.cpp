/*set wifi routers*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#define MAX 200000
using namespace std;

int n = 0, c = 0;
int house[MAX];

int main() {
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; i++) {
		scanf("%d", &house[i]);
	}
	sort(house, house + n);

	int l = 1, r = house[n - 1] - house[0];
	int result = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		int cnt = 1;
		int pre = house[0];
		for (int i = 1; i < n; i++) {
			if (house[i] - pre >= mid) {
				cnt++;
				pre = house[i];
			}
		}
		if (cnt < c) {
			r = mid - 1;
		}
		else {
			result = mid;
			l = mid + 1;
		}
	}
	printf("%d", result);
	return 0;
}