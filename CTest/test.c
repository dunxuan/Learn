#include <stdio.h>
#include <stdbool.h>

bool judgment(int num);
bool judgmentPrime(int num);

int main(void)
{
	int num = 0;

	scanf("%d", &num);

	while(num) {
		if(judgment(num)) {
			printf("%d\n", num);
		}
		scanf("%d", &num);
	}

	return 0;
}

bool judgment(int num)
{
	if(!judgmentPrime(num)) {
		return false;
	}
	int sum = 0;
	while(num) {
		sum += num % 10;
		num /= 10;
	}
	if(judgmentPrime(sum)) {
		return true;
	} else {
		return false;
	}
}

bool judgmentPrime(int num)
{
	for(int i = 2; i * i <= num; i++) {
		if(!(num % i)) {
			return false;
		}
	}
	return true;
}