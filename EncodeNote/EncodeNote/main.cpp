#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "NoteLib.h"
//�����˺�����
//�洢ʱ�м򵥵ļ���
//�ܰ����Ѹ������������е��˺���������
//�����޸������˺���������


int main() {
	int flat;
	int num = 0;

	printf("1������ 2���鿴\n");
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
		default:
			break;
		}
		printf("1������ 2���鿴\n");
	}
}