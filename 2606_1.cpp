/*worm virus with dfs*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#define MAX 101
 
using namespace std;
int n = 0, m = 0;
vector<int> map[MAX];
int c[MAX];
int cnt = 0;

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

void dfs(int x) {
    cnt++;
    c[x] = 1;
    for (int i = 0; i < map[x].size(); i++) {
        int next = map[x][i];
        if (next != 1 && c[next] == 0) {
            dfs(next);
        }
    }
}
int main() {
    input();
    dfs(1);
    printf("%d", cnt-1);
    return 0;
}