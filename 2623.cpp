/*fix the order of music programs*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#define MAX 1001
using namespace std;

void topology(int n);
vector<int> arr[MAX];
int inDegree[MAX];
int result[MAX];

int main() {
	int n = 0, m = 0; //n is the number of singers, m is the number of assistant PDs
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < m; i++) {
		int num = 0; //number of singers that each PD is responsible for
		scanf("%d", &num);

		int from = 0, after=0; 
		scanf("%d", &from);
		for (int j = 1; j <= num-1; j++) {
			scanf("%d", &after);
			arr[from].push_back(after);
			inDegree[after]++;
			from = after;
		}
	}
	topology(n);
	return 0;
}

void topology(int n) {
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}

	for (int i = 1; i <= n; i++) {
		if (q.empty()) {
			printf("0");
			return; //finish the function
		}
		int x = q.front();
		q.pop();
		result[i] = x;

		for (int j = 0; j < arr[x].size(); j++) {
			int y = arr[x][j];
			if (--inDegree[y] == 0) q.push(y);
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d\n", result[i]);
	}
}