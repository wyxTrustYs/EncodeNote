#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char ch1[10] = "abcdefg";
	char ch2[10] = "def";
	printf("%d ", strstr(ch1, ch2));
	return 0;
}