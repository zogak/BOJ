/*game development*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <vector>
#define MAX 501
using namespace std;

void topology(int n);

vector<int> arr[MAX];
int inDegree[MAX];
int time[MAX];
queue<int> q;
int result[MAX];

int main() {
	int n = 0; //different kinds of buildings
	scanf("%d", &n);

	int t = 0, num = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		time[i] = t;
		while (1) {
			scanf("%d", &num);
			if (num == -1) break;
			arr[num].push_back(i);
			inDegree[i]++;
		}
	}
	topology(n);
	return 0;
}

void topology(int n) {

	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			result[i] = time[i];
			q.push(i);
		}
	}

	for (int i = 1; i <= n ; i++) {
		int x = q.front();
		q.pop();
			
		for (int j = 0; j < arr[x].size(); j++) {
			int y = arr[x][j];
			result[y] = max(result[x] + time[y], result[y]);

			if (--inDegree[y] == 0) q.push(y);
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d\n", result[i]);
	}
}