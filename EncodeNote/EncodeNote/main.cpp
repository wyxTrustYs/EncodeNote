#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "NoteLib.h"
//保存账号密码
//存储时有简单的加密
//能按照已给条件查找已有的账号密码数据
//可以修改已有账号密码数据


int main() {
	int flat;
	int num = 0;

	printf("1、增加 2、查看\n");
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
		default:
			break;
		}
		printf("1、增加 2、查看\n");
	}
}