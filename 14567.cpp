/*prerequisition*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#define MAX 1001

using namespace std;
void topology(int n);

int inDegree[MAX];
vector<int> arr[MAX];
int result[MAX];

int main() {
	int n = 0, m = 0;
	scanf("%d %d", &n, &m);

	int a = 0, b = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		arr[a].push_back(b);
		inDegree[b]++;
	}
	topology(n);
	return 0;
}

void topology(int n) {
	queue<int> q;
	int cnt = 1;

	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			result[i] = cnt;
			q.push(i);
		}
	}

	for (int i = 1; i <= n; i++) {
		int x = q.front();
		q.pop();

		for (int j = 0; j < arr[x].size(); j++) {
			int y = arr[x][j];
			result[y] = max(result[y], result[x] + cnt);
			if (--inDegree[y] == 0) q.push(y);
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d ", result[i]);
	}
}