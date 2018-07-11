
/*
	@Name:PassWordConfirm
	@Programe:EncodeNoteBook
	@Author;wyxTrustYs
	@Time:2018-7-11
	@Argument��char* PasswordData
	@Description:�޸�����ȷ�Ϻ���
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

	printf("������ɵ�����(���20λ)��\n");

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
		printf("��������벻��ȷ\n");
		system("pause");
		memset(OldPassWord, 0, 21);
		return 0;
	}
	memset(PasswordData, 0, 21);
	printf("\n");
	printf("�����������룺\n");
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
	printf("����ȷ�ϣ�\n");
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
		printf("�����������벻һ��\n");
		system("pause");
		memset(PasswordData, 0, 21);
		return 0;
	}
	return 1;
}