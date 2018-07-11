
/*
	@Name:Encode.cpp
	@Author:wyxTrustYs
	@time:2018-7-9
	@Argument:char*
	@Description：对密码进行按位取反加密
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "NoteLib.h"

void Encode(char *str) {
	int i = 0;
	while (str[i] != 0) {
		str[i] = ~str[i];
		i++;
	}
}

