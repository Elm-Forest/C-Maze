#include<iostream>
#include<cstdio>
#include<Windows.h>
#include<conio.h>
#include<ctime>
#include<stdlib.h>
#include<string.h>
#define MAX 16
#define high 20
#define mid 15
#define low 10
#define right 0
#define under 1
#define up 2
#define left 3
#define max 100
#define MaxSize 100
using namespace std;

/*****Function Declaration*****/
void rule();								//���� 
int hardchoice();							//����Ѷ�ѡ�� 
int ppp(int,int);									//�Թ����溯�� 
int result(int ,int);								//�Թ����������� 
void style();								//�Թ����溯�� 
int Modify();								//����Ա�޸��Թ�����(����) 
int MapChange(int);							//����Ա�޸��Թ�����(ִ��) 
int MapGet(char,int);						//�Թ���Ϣ��ȡ���� 
void rule();
int sumtime(int ,double);
void FindPath(char,int);

int login();								//��½ѡ���� 
void loginmenu();							//��½�˵�
int userregister();							//ע�ắ��(�û�) 
int userlogin();							//��½����(�û�) 
int adminlogin(); 							//��½����(����Ա) 
int admin();								//����Ա����
int useradmin();							//�û�����(����Ա/�û�) 
int adminregister();						//����Ա���� 
int foundpw();
int user();									//�û�����  
void besttime();							//���ͨ��ʱ��
int hardchoice(); 
void besttime();
void cuttime();
int founduser(int);
int deleteuser();
int seekuser(int);
int modifyuser(int);
void adminmenu();
void usermenu();
void useradminmenu();
void userusermenu();
void modifyusermenu();
void first();								//����Ա��ʼ�� 
/*----------------------------*/ 

