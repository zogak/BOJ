/*startlink*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#define MAX 1000001
using namespace std;
int F, S, G, U, D;
int v[MAX];
queue<pair<int, int>> q;
int main() {
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	//total F floors, now on the S floor, office is on the G floor
	q.push(make_pair(S, 0));
	v[S] = 1;
	while (!q.empty()) {
		int loc = q.front().first;
		int btn = q.front().second;
		if (loc == G) {
			printf("%d", btn);
			return 0;
		}
		q.pop();
		if (loc + U <= F && v[loc + U] == 0) {
			q.push({ loc + U, btn + 1 });
			v[loc + U] = 1;
		}
		if (loc - D > 0 && v[loc - D] == 0) {
			q.push({ loc - D, btn + 1 });
			v[loc - D] = 1;
		}
	}
	printf("use the stairs");
	return 0;
}