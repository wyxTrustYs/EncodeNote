
/*

	@Name:StringCat.cpp
	@Programe:EncodeNoteBook
	@Author;wyxTrustYs
	@Time:2018-7-11
	@Argument:char *TmpStr, char *Account, char *PassWord, char *Tips
	@Description:���ַ����� �˻�+"    "+����+"    "+��ע ����ʽƴ������
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "NoteLib.h"
#include "data.h"

void StringCat(char *TmpStr, char *Account, char *PassWord, char *Tips) {

	memset(TmpStr, 0, 2048 * sizeof(char));
	strcat(TmpStr, Account);
	strcat(TmpStr, "    ");
	strcat(TmpStr, PassWord);
	strcat(TmpStr, "    ");
	strcat(TmpStr, Tips);
}