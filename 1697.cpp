/*hide and seek*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#define MAX 100001
using namespace std;
int n, k;
int v[MAX];
queue <pair<int, int>> q;
int main() {
	scanf("%d %d", &n, &k);
	q.push({ n,0 });
	v[n] = 1;
	while (!q.empty()) {
		int loc = q.front().first;
		int t = q.front().second;
		q.pop();
		if (loc == k) {
			printf("%d", t);
			return 0;
		}
		if (loc + 1 < MAX && v[loc + 1] == 0) {
			q.push({ loc + 1, t + 1 });
			v[loc + 1] = 1;
		}
		if (loc - 1 >= 0 && v[loc - 1] == 0) {
			q.push({ loc - 1, t + 1 });
			v[loc - 1] = 1;
		}
		if (2 * loc < MAX && v[2 * loc] == 0) {
			q.push({ 2 * loc, t + 1 });
			v[2 * loc] = 1;
		}
	}
	return 0;
}