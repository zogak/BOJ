/*color weakness*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <cstring>
#define MAX 101
using namespace std;

int n = 0; // will make n*n map
int map[MAX][MAX];
int visited[MAX][MAX]; // check if visited
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0}; // up, right, down, left
int normal = 0, weakness = 0;

void dfs(int x, int y){
	int colorCheck = map[x][y];
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n)
			continue;

		if (visited[nx][ny] == 0 && map[nx][ny] == colorCheck) {
			dfs(nx, ny);
		}
	}
}

int main() {
	scanf("%d", &n);
	//fill a map
	char color; 
	int c = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %1c", &color); //wow

			if (color == 'R') {
				c = 1;
				map[i][j] = c;
			}
			else if (color == 'G') {
				c = 2;
				map[i][j] = c;
			}
			else { // color == 'B'
				c = 3;
				map[i][j] = c;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0) {
				normal++; //count first
				dfs(i, j); //then go to dfs
			}
		}
	}

	//make 'R' and 'G' same
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//visited[i][j] = 0; // reset visited
			if (map[i][j] == 2) {
				map[i][j] = 1;
			}
		}
	}
	memset(visited, 0, sizeof(visited)); // reset visited

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0) {
				weakness++;
				dfs(i, j);
			}
		}
	}

	printf("%d %d", normal, weakness);

	return 0;
}
