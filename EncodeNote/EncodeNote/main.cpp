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
	@Description:�����˺�����
			  �洢ʱ�м򵥵ļ���
			  �ܰ����Ѹ������������е��˺���������
			  �����޸������˺���������
*/



int main() {
	int flat;
	int num = 0;

	printf("1������ 2���鿴 3���鿴ȫ��\n");
	while (scanf("%d", &flat) != EOF) {
		switch (flat)
		{
		case INIT:
			while (InitAccount() == 0) {
				printf("�˻�����ʧ��\n");
			}
			break;
		case CHECK:
			CheckData(); break;
		case CHECKALL:
			if (GetFromFile() == 0) {
				printf("�鿴ʧ��\n");
			}
			break;
		default:
			break;
		}
		printf("1������ 2���鿴 3���鿴ȫ��\n");
	}
}