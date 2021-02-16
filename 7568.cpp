/*size*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#define MAX 50
using namespace std;
int n, x, y, cnt;
vector<pair<int, int>> v;
vector<int> order;
void input() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		v.push_back(make_pair(x, y));
	}
}
void howBig() {
	for (int i = 0; i < v.size(); i++) {
		int weight = v[i].first;
		int height = v[i].second;
		for (int j = 0; j < v.size(); j++) {
			if (weight == v[j].first && height == v[j].second) {
				continue;
			}
			if (weight < v[j].first && height < v[j].second) {
				cnt++;
			}
		}
		order.push_back(cnt+1);
		cnt = 0;
	}
}
void print() {
	for (int i = 0; i < order.size(); i++) {
		printf("%d ", order[i]);
	}
}
int main() {
	input();
	howBig();
	print();
	return 0;
}