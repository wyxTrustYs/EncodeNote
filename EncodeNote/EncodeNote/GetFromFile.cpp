#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "NoteLib.h"
#include "data.h"

int GetFromFile(char *str) {
	FILE *file = NULL;
	char *FilePath = "D:\\data\\Encode";
	char TmpStr[100][2048];
	char *TmpAccount = NULL;
	char *TmpTips = NULL;
	char *TmpPassword = NULL;
	
	char AccountData[100][21];
	char PasswordData[100][21];
	char TipsData[100][1024];
	int i = 0;
	int n = 0;
	int Flat;
	int AccountNumber;
	int StringFlat;
	int SeeNum[100];

	for (int p = 0; p < 100; p++) {
		memset(TmpStr[p], 0, 2048 * sizeof(char));
	}

	if ((file = fopen(FilePath, "rb+")) == NULL) {
		printf("打开文件失败\n");
		return 0;
	}
	printf("\n");
	while (fgets(TmpStr[n], 2048, file) != NULL) {
		if (((TmpAccount = strstr(TmpStr[n], str)) != NULL) || ((TmpTips = strstr(TmpStr[n], str))) != NULL){
			TmpAccount = strtok(TmpStr[n], "    ");
			TmpPassword = strtok(NULL, "    ");
			TmpTips = strtok(NULL, "    ");
			strcpy(AccountData[i], TmpAccount);
			strcpy(PasswordData[i], TmpPassword);
			strcpy(TipsData[i], TmpTips);
			StringCat(TmpStr[n], AccountData[i], PasswordData[i], TipsData[i]);
			MyDecode(PasswordData[i]);
			printf("%d: %s %s %s\n", i, AccountData[i], PasswordData[i], TipsData[i]);
			SeeNum[i] = n;
			i++;
		}
		n++;
	}
	fclose(file);

	printf("是否要删除或者修改数据(1、修改 2、删除 3、添加 4、退出)：\n");
	scanf("%d", &Flat);
	switch (Flat)
	{
	case 1:
	{
		printf("请输入修改项：");
		scanf("%d", &AccountNumber);
		printf("请输入修改内容（1、账户 2、密码 3、备注）：\n");
		scanf("%d", &StringFlat);
		switch (StringFlat)
		{
		case 1:
		{
			printf("请输入修改的账号：");
			memset(AccountData[AccountNumber], 0, 21);
			scanf("%s", AccountData[AccountNumber]);
			Encode(PasswordData[AccountNumber]);
			StringCat(TmpStr[SeeNum[AccountNumber]],AccountData[AccountNumber],PasswordData[AccountNumber],TipsData[AccountNumber]);
			printf("%s\n", TmpStr[SeeNum[AccountNumber]]);
			getchar();
			break;
		}

		case 2: 
		{
			printf("请输入修改的密码：");
			while (PassWordConfirm(PasswordData[AccountNumber]) == 0) {
			}
			printf("修改成功\n");
			Encode(PasswordData[AccountNumber]);
			StringCat(TmpStr[SeeNum[AccountNumber]], AccountData[AccountNumber], PasswordData[AccountNumber], TipsData[AccountNumber]);
			printf("%s\n", TmpStr[SeeNum[AccountNumber]]);
			break;
		}
		case 3:
		{
			printf("请输入修改的备注：");
			memset(TipsData[AccountNumber], 0, 21);
			scanf("%s", TipsData[AccountNumber]);
			Encode(PasswordData[AccountNumber]);
			StringCat(TmpStr[SeeNum[AccountNumber]], AccountData[AccountNumber], PasswordData[AccountNumber], TipsData[AccountNumber]);
			printf("%s\n", TmpStr[SeeNum[AccountNumber]]);
			getchar();
			break;
		}
			
			break;
		default:
			break;
		}
		break;
	}
	case 2:
	{
		printf("请输入删除项：");
		scanf("%d", &AccountNumber);
		
		int tmpdata = SeeNum[AccountNumber]+1;
		while (strlen(TmpStr[tmpdata]) != 0) {
			memset(TmpStr[tmpdata-1], 0, 2048 * sizeof(char));
			strcpy(TmpStr[tmpdata - 1], TmpStr[tmpdata]);
			tmpdata++;
		}
		printf("删除成功\n");
		getchar();
		break;
	}
	case 3:
		if (InitAccount() == 1) {
			printf("添加成功");
		}
		break;
	case 4:
		break;
	default:
		break;
	}
	getchar();
	printf("修改完毕是否需要保存？(y/n)\n");
	char ch = getchar();
	switch (ch)
	{
	case 'y':
	{
		if ((file = fopen(FilePath, "wb+")) == NULL) {
			printf("打开文件失败\n");
			return 0;
		}
		int count = 0;
		while (strlen(TmpStr[count]) != 0) {
			printf("%s\n", TmpStr[count]);
			fputs(TmpStr[count], file);
			fputc('\0', file);
			fputc('\r', file);
			fputc('\n', file);
			count++;
		}
		fclose(file);
		break;
	}
	default:
		break;
	}

}

int GetFromFile() {
	FILE *file = NULL;
	char *FilePath = "D:\\data\\Encode";
	char TmpStr[100][2048];
	char *TmpAccount = NULL;
	char *TmpTips = NULL;
	char *TmpPassword = NULL;

	char AccountData[100][21];
	char PasswordData[100][21];
	char TipsData[100][1024];
	int n = 0;

	for (int p = 0; p < 100; p++) {
		memset(TmpStr[p], 0, 2048 * sizeof(char));
	}

	if ((file = fopen(FilePath, "rb+")) == NULL) {
		printf("打开文件失败\n");
		return 0;
	}
	printf("\n");
	while (fgets(TmpStr[n], 2048, file) != NULL) {
		
			TmpAccount = strtok(TmpStr[n], "    ");
			TmpPassword = strtok(NULL, "    ");
			TmpTips = strtok(NULL, "    ");
			strcpy(AccountData[n], TmpAccount);
			strcpy(PasswordData[n], TmpPassword);
			strcpy(TipsData[n], TmpTips);
			StringCat(TmpStr[n], AccountData[n], PasswordData[n], TipsData[n]);
			MyDecode(PasswordData[n]);
			printf("%d: %s %s %s\n", n, AccountData[n], PasswordData[n], TipsData[n]);
			n++;
	}
	fclose(file);
	return 1;
}