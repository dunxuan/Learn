void StringCount(char * s);

#include <stdio.h>
#define MAXS 15

void StringCount(char * s);
void ReadString(char * s); /* 由裁判实现，略去不表 */

int main()
{
	char s[MAXS];

	ReadString(s);
	StringCount(s);

	return 0;
}

/* Your function will be put here */
#include <string.h>
void StringCount(char * s)
{
	int upper = 0, lower = 0, space = 0, digit = 0, other = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (isupper(s[i])) {
			upper++;
		} else if (islower(s[i])) {
			lower++;
		} else if (s[i] == ' ') {
			space++;
		} else if (isdigit(s[i])) {
			digit++;
		} else {
			other++;
		}
	}
	printf("%d %d %d %d %d", upper, lower, space, digit, other);
}