
/*
	@Name:PassWordConfirm
	@Programe:EncodeNoteBook
	@Author;wyxTrustYs
	@Time:2018-7-11
	@Argument：char* PasswordData
	@Description:修改密码确认函数
*/


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "NoteLib.h"
#include "data.h"

int PassWordConfirm(char *PasswordData) {
	char ch;
	char *OldPassWord = NULL;
	char *NewPassWord = NULL;
	char *Confirm = NULL;
	int j;
	OldPassWord = (char *)malloc(21 * sizeof(char));
	NewPassWord = (char *)malloc(21 * sizeof(char));
	Confirm = (char *)malloc(21 * sizeof(char));
	memset(OldPassWord, 0, 21);
	memset(NewPassWord, 0, 21);
	memset(Confirm, 0, 21);

	printf("请输入旧的密码(最多20位)：\n");

	j = 0;
	while ((ch = getch()) != 13) {
		if (ch != 8) {
			OldPassWord[j] = ch;
			putch('*');
			j++;
		}
		else if (ch == 8) {
			OldPassWord[j - 1] = 0;
			printf("\b \b");
			j--;
		}
	}

	while (strcmp(OldPassWord, PasswordData) != 0) {
		printf("输入的密码不正确\n");
		system("pause");
		memset(OldPassWord, 0, 21);
		return 0;
	}
	memset(PasswordData, 0, 21);
	printf("\n");
	printf("请输入新密码：\n");
	j = 0;
	while ((ch = getch()) != 13) {
		if (ch != 8) {
			PasswordData[j] = ch;
			putch('*');
			j++;
		}
		else if (ch == 8) {
			PasswordData[j - 1] = 0;
			printf("\b \b");
			j--;
		}
	}
	printf("\n");
	//	printf("%s\n", tmp_password);
	printf("\n");
	printf("密码确认：\n");
	j = 0;
	while ((ch = getch()) != 13) {
		if (ch != 8) {
			Confirm[j] = ch;
			putch('*');
			j++;
		}
		else if (ch == 8) {
			Confirm[j - 1] = 0;
			printf("\b \b");
			j--;
		}
	}
	if (strcmp(PasswordData, Confirm) != 0) {
		printf("两次输入密码不一致\n");
		system("pause");
		memset(PasswordData, 0, 21);
		return 0;
	}
	return 1;
}