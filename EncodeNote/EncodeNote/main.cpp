#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "NoteLib.h"
/*
	@Name:main.cpp
	@Programe:EncodeNoteBook
	@Author;wyxTrustYs
	@Time:2018-7-11
	@Description:保存账号密码
			  存储时有简单的加密
			  能按照已给条件查找已有的账号密码数据
			  可以修改已有账号密码数据
*/



int main() {
	int flat;
	int num = 0;

	printf("1、增加 2、查看 3、查看全部\n");
	while (scanf("%d", &flat) != EOF) {
		switch (flat)
		{
		case INIT:
			while (InitAccount() == 0) {
				printf("账户创建失败\n");
			}
			break;
		case CHECK:
			CheckData(); break;
		case CHECKALL:
			if (GetFromFile() == 0) {
				printf("查看失败\n");
			}
			break;
		default:
			break;
		}
		printf("1、增加 2、查看 3、查看全部\n");
	}
}