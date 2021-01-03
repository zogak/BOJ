/*sugar delivery - deliver requested amount of sugar with the least packs*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//#define pack1 5
//#define pack2 3

int main() {
	int n = 0; // needed amount of sugar(kg)
	scanf("%d", &n);

	int cnt = 0; //number of total packs of sugar
	if (n % 5 == 0) { 
		cnt = n / 5;
	}
	else if ((n % 5) % 3 == 0) {
		cnt += n / 5;
		cnt += (n % 5) / 3;
	}
	else if ((n % 5) % 3 != 0) {
		int quotient = n / 5;
		int remainder = n % 5;
		while(remainder%3 !=0){
			quotient -= 1;
			if (quotient < 0) {
				printf("-1");
				return 0;
			}
			remainder = n - 5 * quotient;
		}
		cnt = quotient + remainder / 3;
	}
	printf("%d", cnt);
	return 0;
}