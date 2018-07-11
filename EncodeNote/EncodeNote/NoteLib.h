#include "data.h"
int PutToFile(char *account, char *password, char *tips);
void Encode(char *str);
int InitAccount();
void MyDecode(char *str);
void CheckData();
int GetFromFile();
int GetFromFile(char *str);
int PassWordConfirm(char *PasswordData);
void StringCat(char *TmpStr, char *Account, char *PassWord, char *Tips);