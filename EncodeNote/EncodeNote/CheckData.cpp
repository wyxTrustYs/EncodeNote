
/*
	@Name:GetFromFile.cpp
	@Author;wyxTrustYs
	@Time:2018-7-11
	@Description:�������鿴����
*/


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "NoteLib.h"
#include "data.h"

void CheckData() {

	char Str[1024];
	printf("�������˻����߱�ע��Ϣ��\n");
	printf("�˻���ע��");
	
	scanf("%s", Str);
	GetFromFile(Str);
}