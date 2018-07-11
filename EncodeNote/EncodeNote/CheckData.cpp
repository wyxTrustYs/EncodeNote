
/*
	@Name:GetFromFile.cpp
	@Author;wyxTrustYs
	@Time:2018-7-11
	@Description:按条件查看数据
*/


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "NoteLib.h"
#include "data.h"

void CheckData() {

	char Str[1024];
	printf("请输入账户或者备注信息：\n");
	printf("账户或备注：");
	
	scanf("%s", Str);
	GetFromFile(Str);
}