/*a strange bar*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using namespace std;
int n = 0, k = 0; //kettle, people
int v = 0;
int result = 0;
vector<int> volume;
int left = 0, mid = 0, right = 0;

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v);

		if (right < v) {
			right = v;
		}
		volume.push_back(v);
	}
	
	while (left <= right) {
		mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += volume[i] / mid;
		}
		if (cnt < k) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
			result = mid;
		}
	}
	printf("%d", result);
	return 0;
}
