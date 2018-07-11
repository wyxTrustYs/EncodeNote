
/*

	@Name:InitAccount.cpp
	@author;wyxTrustYs
	@Time:2018-7-11
	@Argument:
	@Description:创建账户

*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "NoteLib.h"
#include "data.h"

int InitAccount() {
	system("cls");
	char *tmp_password;
	char ch;
	int i;
	char account[21];
	char password[21];
	char tips[1024];
	memset(password, 0, 20 * sizeof(char));
	memset(account, 0, 20 * sizeof(char));
	memset(tips, 0, 1024 * sizeof(char));

	printf("请输入账号(最多20位)：\n");
	scanf_s("%s", account, 20);
	getchar();
	printf("请输入密码(最多20位)：\n");
	i = 0;
	
	//输入密码（隐藏输入字符）

	while ((ch = getch()) != 13) {
		if (ch != 8) {
			password[i] = ch;
			putch('*');
			i++;
		}
		else if (ch == 8) {
			password[i - 1] = 0;
			printf("\b \b");
			i--;
		}
	}
//	printf("%s\n", password);


	//确认密码（隐藏字符）
	printf("\n");
	printf("确认密码：\n");
	tmp_password = (char *)malloc(21 * sizeof(char));
	memset(tmp_password, 0, 21);
	i = 0;
	while ((ch = getch()) != 13) {
		if (ch != 8) {
			tmp_password[i] = ch;
			putch('*');
			i++;
		}
		else if (ch == 8) {
			tmp_password[i - 1] = 0;
			printf("\b \b");
			i--;
		}
	}
	printf("\n");
//	printf("%s\n", tmp_password);


	//密码确认是否一致，不一致清空存放密码字符串并返回错误信息
	if (strcmp(password, tmp_password) != 0) {
		printf("两次输入密码不一致\n");
		system("pause");
		memset(password, 0, 21);
		return 0;
	}


	//创建账号的备注信息调用PutToFile函数
	printf("请输入账号备注信息：\n");
	scanf_s("%s", tips, 1024);
	printf("创建成功\n");
	if (PutToFile(account,password,tips)) {
		printf("账户文件创建成功\n");
	}
	return 1;
}