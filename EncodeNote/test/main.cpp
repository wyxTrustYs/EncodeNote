#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main() {
	int a = 10;
	int *p = &a;
	printf("%x ", p);
	*p++;
	printf("%x %d", p,*p);
}