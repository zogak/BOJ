/*zero*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stack>
using namespace std;
int k, num, result;
stack <int> s;
int main() {
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &num);
		if (num == 0) {
			s.pop();
		}
		else {
			s.push(num);
		}
	}
	while (!s.empty()) {
		result += s.top();
		s.pop();
	}
	printf("%d", result);
	return 0;
}