/*find parent of the tree*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#define MAX 100001
using namespace std;
int n, a, b;
int r [MAX], v[MAX];
vector <int> map[MAX];
void input() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", &a, &b);
		map[a].push_back(b);
		map[b].push_back(a);
	}
}
void dfs(int node) {
	v[node] = 1;
	for (int i = 0; i < map[node].size(); i++) {
		if (v[map[node][i]] == 1) {
			continue;
		}
		r[map[node][i]] = node;
		dfs(map[node][i]);
	}
}
void print() {
	for (int i = 2; i <= n; i++) {
		printf("%d\n", r[i]);
	}
}
int main() {
	input();
	dfs(1);
	print();
	return 0;
}