/*wedding*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <vector>
#define MAX 501

using namespace std;
int n = 0, m = 0;
vector<int> map[MAX];
int c[MAX] = { 0 };
int cnt = 0;
queue<int> q;


void input() {
	scanf("%d %d", &n, &m);
	int a = 0, b = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		map[a].push_back(b);
		map[b].push_back(a);
	}
}

void countFriend(int x) {
	for (int i = 0; i < map[x].size(); i++) {
		int f = map[x][i];
		cnt++;
		c[f] = 1;
		q.push(f);
	}
	while (!q.empty()) {
		int g = q.front();
		q.pop();
		for (int i = 0; i < map[g].size(); i++) {
			int h = map[g][i];
			if (c[h] == 0 && map[g][i] != 1) {
				c[h] = 1;
				cnt++;
			}
		}
	}
}
int main() {
	input();
	countFriend(1);
	printf("%d", cnt);
	return 0;
}