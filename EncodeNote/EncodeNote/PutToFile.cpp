
/*
	@Name:PutToFile.cpp
	@Author:wyxTrustYs
	@Time:2018-7-11
	@Argument:char* account char* password char *tips
	@Descreaption:在D:\\data文件下建立一个存放密码的密码本Encode

*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "NoteLib.h"
//#include "data.h"
int PutToFile(char *account,char *password,char *tips) {
	FILE *file = NULL;
	char *FilePath = "D:\\data\\Encode";
	int count = 0;

	Encode(password);
//	printf("%s %s %s ", account, password, tips);
	if ((file = fopen(FilePath, "ab+")) == NULL) {
		printf("打开文件失败\n");
		return 0;
	}
//	fwrite(person, sizeof(PassWord), 1, file);
	while (account[count] != 0)
	{
		fputc(account[count],file);
		count++;
	}
	fputs("    ",file);

	count = 0;
	while (password[count] != 0)
	{
		fputc(password[count],file);
		count++;
	}
	fputs("    ", file);

	count = 0;
	while (tips[count] != 0)
	{
		fputc(tips[count], file);
		count++;
	}
	fputc('\0', file);
	fputc('\r', file);
	fputc('\n', file);
	fclose(file);
	return 1;
}