/*worm virus with bfs*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#define MAX 101

using namespace std;

int n = 0, m = 0;
vector<int> map[MAX];
queue<int> q;
int cnt = 0;
int c[MAX];

void input() {
    scanf("%d", &n);
    scanf("%d", &m);
    int a = 0, b = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        map[a].push_back(b);
        map[b].push_back(a);
    }
}

void bfs() {
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < map[x].size(); i++) {
            int near = map[x][i];
            if (c[near] == 0) {
                q.push(near);
                cnt++;
                c[near] = 1;
            }
        }
    }
}
int main() {
    input();
    q.push(1);
    c[1] = 1;
    bfs();
    printf("%d", cnt);
	return 0;
}