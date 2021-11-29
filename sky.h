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
void rule();								//规则 
int hardchoice();							//玩家难度选择 
int ppp(int,int);									//迷宫游玩函数 
int result(int ,int);								//迷宫游玩结果函数 
void style();								//迷宫界面函数 
int Modify();								//管理员修改迷宫函数(参数) 
int MapChange(int);							//管理员修改迷宫函数(执行) 
int MapGet(char,int);						//迷宫信息获取函数 
void rule();
int sumtime(int ,double);
void FindPath(char,int);

int login();								//登陆选择函数 
void loginmenu();							//登陆菜单
int userregister();							//注册函数(用户) 
int userlogin();							//登陆函数(用户) 
int adminlogin(); 							//登陆函数(管理员) 
int admin();								//管理员操作
int useradmin();							//用户管理(管理员/用户) 
int adminregister();						//管理员创建 
int foundpw();
int user();									//用户操作  
void besttime();							//最佳通关时间
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
void first();								//管理员初始化 
/*----------------------------*/ 

