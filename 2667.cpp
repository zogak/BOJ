/*count the houses*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 26
using namespace std;

int map[MAX][MAX] = { 0 };
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1, 0, 1,0 };
int cnt = 0; //number of villages
int n = 0; //width and height of the map
int house = 0;
vector<int> houses;

void dfs(int x, int y) {
	map[x][y] = 2;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < n && ny < n && map[nx][ny] == 1) {
			house++;
			dfs(nx, ny);
		}
	}
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			house = 1;
			if (map[i][j] == 1) {
				cnt++;
				dfs(i, j);
				houses.push_back(house);
			}
		}
	}
	printf("%d\n", cnt);
	sort(houses.begin(), houses.end());
	for (int i = 0; i < houses.size(); i++) {
		printf("%d\n", houses[i]);
	}
	return 0;
}