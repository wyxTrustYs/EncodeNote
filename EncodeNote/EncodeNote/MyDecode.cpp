
/*
	@Name:MyDecode.cpp
	@Programe:EncodeNoteBook
	@Author:wyxTrustYs
	@Time:2018-7-9
	@Argument:char*
	@Description£º½âÂë
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "NoteLib.h"

void MyDecode(char *str) {
	int i = 0;
	while (str[i] != 0) {
		str[i] = ~str[i];
		i++;
	}
}

