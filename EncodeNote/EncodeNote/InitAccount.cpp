
/*

	@Name:InitAccount.cpp
	@author;wyxTrustYs
	@Time:2018-7-11
	@Argument:
	@Description:�����˻�

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

	printf("�������˺�(���20λ)��\n");
	scanf_s("%s", account, 20);
	getchar();
	printf("����������(���20λ)��\n");
	i = 0;
	
	//�������루���������ַ���

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


	//ȷ�����루�����ַ���
	printf("\n");
	printf("ȷ�����룺\n");
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


	//����ȷ���Ƿ�һ�£���һ����մ�������ַ��������ش�����Ϣ
	if (strcmp(password, tmp_password) != 0) {
		printf("�����������벻һ��\n");
		system("pause");
		memset(password, 0, 21);
		return 0;
	}


	//�����˺ŵı�ע��Ϣ����PutToFile����
	printf("�������˺ű�ע��Ϣ��\n");
	scanf_s("%s", tips, 1024);
	printf("�����ɹ�\n");
	if (PutToFile(account,password,tips)) {
		printf("�˻��ļ������ɹ�\n");
	}
	return 1;
}