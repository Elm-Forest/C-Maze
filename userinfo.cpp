#include"sky.h"

typedef struct{
	char id[100];
	char pw[100];
	int pn;
	double time1;
	double time2;
	double time3;
	int *next;
}users; 

typedef struct{
	char id[100];
	char pw[100];
}admins;

const char adminid[]={"admin"};				//管理员初始账号，请勿更改 
const char adminpw[]={"admin123456"};		//此为管理员初始密码，请勿更改
const char back[] = { "5" };				//登陆时返回上一级命令 ,此处默认为5,严禁更改！！！ 
const char back2[]={"4"};					//操作时返回上一级命令 ,此处默认为4，严禁更改！！！ 
users total[max];
admins adminl[max];							
int  usernum = 0;							//已注册的用户数 
int adminnum=1;								//已注册管理员数 
int ccc=0;									//当前登陆的用户记录值 
int bbb=0;									//当前登陆的管理员记录值
 
void first(){
	strcpy(adminl[0].id,adminid);
	strcpy(adminl[0].pw,adminpw);
}

int adminlogin() {
	int couts = 0;
	int temp = 0;
	int in = 5;
	int k = 5;
	char id[20];

	char pw[20];
	if (adminnum==0) {
		cout << "           录入用户数为0，请先注册" << endl;
		return 3;
	}
	cout << "           请输入管理员账号" << endl;
	while (in) {
		scanf("%s", &id);
		if(strcmp(id, back) == 0)
			return 3;
		for (int i = 0; i < adminnum; i++)
			if (strcmp(adminl[i].id, id) == 0) {
				couts++;
				temp = i;
				break;
			}
		if (couts == 0) {
			cout << "            账号不存在,请重试" << endl;
			continue;
		}
		if (couts != 0)
			break;
	}
	cout << "             请输入管理员密码" << endl;
	while (k) {
		scanf("%s", &pw);
		if (strcmp(pw, back) == 0)
			return 3;
		if (strcmp(pw, adminl[temp].pw) != 0)
			cout << "           猜的好！剩余尝试次数" << --k << "次" << endl;
		else {
			k = 0;
			cout << "           欢迎回来,管理员" << endl;
			return 1;
		}
	}
	return 2;
}


int userlogin() {
	int couts = 0;
	int temp = 0;
	int in = 5;
	int k = 5;
	char id[20];
	char pw[20];
	if (usernum==0) {
		cout << "           录入用户数为0，请先注册" << endl;
		Sleep(1000); 
		return 3;
	}
	cout << "           请输入用户账号" << endl;
	while (in) {
		scanf("%s", &id);
		if(strcmp(id, back) == 0)
			return 3;
		for (int i = 0; i < usernum; i++)
			if (strcmp(total[i].id, id) == 0) {
				couts++;
				temp = i;
				break;
			}
		if (couts == 0) {
			cout << "            玩家不存在,请重试" << endl;
			continue;
		}
		if (couts != 0) {
			break;
		}
	}
	cout << "             请输入玩家密码" << endl;
	while (k) {
		scanf("%s", &pw);
		if (strcmp(pw, back) == 0)
			return 3;
		if (strcmp(pw, total[temp].pw) != 0)
			cout << "           猜的好！剩余尝试次数" << --k << "次" << endl;
		else {
			k = 0;
			cout << "           欢迎回来,玩家" << endl;
			ccc=temp;
			return 1;
		}
	}
	return 2;
}

int adminregister(){
	int k=5;
	if(adminnum==max-1){
		cout<<"注册管理员数已达大最大值，请重新分配内存"<<endl;
		return 0;
	}
	char pw[20];
	cout<<"欢迎注册新管理员,请输入管理员账号:"<<endl;
	cin>>adminl[adminnum].id;
	while(k){
		cout<<"请输入管理员密码："<<endl;
		cin>>adminl[adminnum].pw;
		cout<<"请再次输入:"<<endl;
		cin>>pw;
		if(strcmp(adminl[adminnum].pw,pw)==0)
			k=0;
		else
			cout<<"前后密码不一致，请重试！"<<endl;
	}
	cout<<"您已成功注册,正在返回登陆"<<endl;
	adminnum++;
	return 1;
}

int userregister() {
	char id[20];
	char pw[20];
	char pw2[20];
	int pn;
	int t;
	if (usernum == max - 1) {
		cout << "           注册玩家数已达上限，请联系管理员" << endl;
		return 3;
	}
	cout << "           欢迎注册，请输入您的帐号,长度须为8位" << endl;
	scanf("%s", &total[usernum].id);
	if (strcmp(total[usernum].id, back) == 0) {
		return 3;
	}
	while (5) {
		cout << "           请输入您的密码，长度须位6位" << endl;
		scanf("%s", &total[usernum].pw);
		if (strcmp(total[usernum].pw, back) == 0) {
			return 3;
		}
		cout << "           请确认您的密码" << endl;
		scanf("%s", &pw);
		if (strcmp(total[usernum].pw, back) == 0) {
			return 3;
		}
		if (strcmp(pw, total[usernum].pw) != 0) {
			cout << "           与第一次结果不一致，请重试！" << endl;
			continue;
		}
		else {
			while(1){
				cout<<  "            请输入您的手机号后四位，将作为个人pn凭证，用于密码找回"<<endl;
				cin>>total[usernum].pn;
				if (total[usernum].pn==4)
					return 3;
				cout<<  "请检查上述信息，确认是否有误,如无误，请输入1，否则输入2"<<endl;
				cin>>t;
				if(t==1)
					break;
				if(t==2)
					return 3;		 
			}
			usernum++;
			cout << "您已成功注册！请返回登陆" << endl;
			return 1;
		}
	}
}

void loginmenu() {
    cout<<"_________________________________________"<<endl;
    cout<<"|*****************迷宫******************|"<<endl;
	cout<<"|*             1.管理员登陆            *|"<<endl;
	cout<<"|*             2.用户登录              *|"<<endl;
	cout<<"|*             3.用户注册              *|"<<endl;
	cout<<"|*             4.找回密码              *|"<<endl;
	cout<<"|*             5.返回上一级            *|"<<endl;
	cout<<"|*             6.退出系统              *|"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
}

int login(){
	char t;
	int temp;
	loginmenu();
	while (1) {
		t = getchar();
		if (t == '1') {
			temp = adminlogin();
			if (temp == 1) {
				printf("login successed!");
				Sleep(1000);
				system("cls");
				return 1;
			}
			if (temp == 2) {
				printf("尝试次数已耗尽，重启系统ing...");
				Sleep(3000); 
				system("cls");
				return login();
			}
			if (temp == 3) {
				system("cls");
				return login();
			}
		}
		
		if (t == '2') {
			temp = userlogin();
			if (temp == 1) {
				printf("login successed!");
				Sleep(1000);
				system("cls");
				return 2;
			}
			if (temp == 2) {
				printf("猜的好！请重新登陆......");
				system("cls");
				return login();
			}
			if (temp == 3) {
				system("cls");
				return login();
			}
		} 
		if (t == '3') {
			temp = userregister();
			if (temp == 1) {
				system("cls");
				return login();
			}
			if (temp == 3) {
				system("cls");
				return login();
			}
		}
		if(t=='4'){
			founduser(3);
			system("cls");
			return login();
		}
		if (t == '5') {
			system("cls");
			return login();
		}
		if(t=='6'){
			system("cls");
			cout<<"谢谢使用！"<<endl;
			Sleep(2000);
			return 0;
		}
		if(t!='1'&&t!='2'&&t!='3'&&t!='4'&&t!='5'&&t!='6'){
			system("cls");
			return login();
		}
	}
}

int memberchoice(int t){
	switch(t){
		case 1:admin();break;
		case 2:user();break;
	}
}

void adminmenu(){
    cout<<"_________________________________________"<<endl;
    cout<<"|*****************管理员****************|"<<endl;
	cout<<"|*             1.管理员创建            *|"<<endl;
	cout<<"|*             2.迷宫修改              *|"<<endl;
	cout<<"|*             3.用户管理              *|"<<endl;
	cout<<"|*             4.管理员退出            *|"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
} 

void usermenu(){
    cout<<"_________________________________________"<<endl;
    cout<<"|*****************玩家******************|"<<endl;
	cout<<"|*             1.更改个人信息          *|"<<endl;
	cout<<"|*             2.开始游戏              *|"<<endl;
	cout<<"|*             3.查看最高成绩          *|"<<endl;
	cout<<"|*             4.玩家退出              *|"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
} 

void useradminmenu(){
	cout<<"_________________________________________"<<endl;
	cout<<"|*****这是面向管理员的用户管理界面******|"<<endl;
	cout<<"|*          1.查询用户基本信息         *|"<<endl;
	cout<<"|*          2.修改用户数据             *|"<<endl;
	cout<<"|*          3.删除用户数据             *|"<<endl;
	cout<<"|*          4.返回上一层               *|"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
}

void userusermenu(){
	cout<<"_________________________________________"<<endl;
    cout<<"|*******这是面向用户的用户管理界面******|"<<endl;
	cout<<"|*             1.查询用户基本信息      *|"<<endl;
	cout<<"|*             2.修改用户数据          *|"<<endl;
	cout<<"|*             3.清空最佳成绩          *|"<<endl;
	cout<<"|*             4.管理员退出            *|"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
}

void modifyusermenu(){
	cout<<"_________________________________________"<<endl;
    cout<<"|***********这是用户数据修改界面********|"<<endl;
	cout<<"|*             1.修改用户账号          *|"<<endl;
	cout<<"|*             2.修改用户密码          *|"<<endl;
	cout<<"|*             3.修改用户pn            *|"<<endl;
	cout<<"|*             4.管理员退出            *|"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
}

int deleteuser(){
	char id[20];
	char q[]={"4"};
	int n=-1;
	int t=0;
	cout<<"您正在删除用户，按4即可返回上一层"<<endl; 
	cout<<"请输入你想删除的用户账号"<<endl;
	scanf("%s",&id);
	if(strcmp(id,q)==0)
			return 0;
	for(int i=0;i<usernum;i++)
		if(strcmp(id,total[i].id)==0)
			n=i;
	if(n==-1){
		cout<<"用户不存在，请重试！"<<endl;
		Sleep(1000);
		system("cls");
		return deleteuser();
	}
	cout<<"您确认删除该用户吗？确认请按1，撤回请按2"<<endl;
	cin>>t;
	if(t==2){
		return deleteuser();
	}
	for(int i=n;i<usernum-1;i++){
		strcpy(total[i].id,total[i+1].id);
		strcpy(total[i].pw,total[i+1].pw);
		total[i].pn=total[i+1].pn;
	}
	usernum--;
	cout<<"用户删除成功！"<<endl;
	return 0;
}

void cuttime(){
	total[ccc].time1=0;
	total[ccc].time2=0;
	total[ccc].time3=0;
}

void besttime(){
	printf("难度1的最佳通关时间为：%.2fs\n",total[ccc].time1); 
	printf("难度2的最佳通关时间为：%.2fs\n",total[ccc].time2);
	printf("难度3的最佳通关时间为：%.2fs\n",total[ccc].time3);
}

int seekuser(int p){
	if(p==1){
		int pn;
		cout<<"请输入用户pn凭证:"<<endl;
		cin>>pn;
		if(pn==4)
			return 0;
		if(pn!=total[ccc].pn){
			cout<<"pn错误，请重试"<<endl;
			return seekuser(1);
		}
	}
	cout<<"此用户账号："<<total[ccc].id<<endl;
	cout<<"此用户密码:"<<total[ccc].pw<<endl;
	cout<<"用户的pn凭证："<<total[ccc].pn<<endl; 
}

int modifyuser(int p){
	if(p==1){
		int pn;
		cout<<"请输入用户pn凭证"<<endl;
		cin>>pn;
		if(pn==4)
			return 0;
		if(pn!=total[ccc].pn){
			cout<<"pn错误，请重试"<<endl;
			return modifyuser(1);
		}
	}
	char temp;
	int t;
	modifyusermenu();
	cin>>temp;
	t=temp;
	switch(t){
		case 49:
			cout<<"请输入修改后的账号："<<endl; 
			cin>>total[ccc].id;
			return modifyuser(2);
		case 50:
			cout<<"请输入修改后的密码："<<endl; 
			cin>>total[ccc].pw;
			return modifyuser(2);
		case 51:
			cout<<"请输入修改后的pn"<<endl; 
			cin>>total[ccc].pn;
			return modifyuser(2);
		case 52:
			return 0;
	}
	cout<<"不存在该选项，请重试！"<<endl;
	Sleep(1000);
	system("cls");
	return modifyuser(p);
	
}

int founduser(int n){
	char id[20];
	int t=0;
	cout<<"输入用户账号"<<endl;
	cin>>id;
	if(strcmp(id, back) == 0&&n==3)
		return 3;
	if(strcmp(id, back2) == 0&&(n==1||n==2))
		return 0;
	for (int i = 0; i < usernum; i++)
		if (strcmp(total[i].id, id) == 0) {
			ccc = i;
			t++;
			break;
		}
	if(t==0){
		cout<<"用户不存在"<<endl;
		return founduser(n);
	}
	switch(n){
		case 1:
			return seekuser(2);
		case 2:
			return modifyuser(2);
		case 3:
			return foundpw();
	}
		
}

int foundpw(){
	int pn;
	char p[50];
	int k=5;
	cout<<"请输入您的pn凭证："<<endl;
	cin>>pn;
	if(pn==5)
		return 3;
	if(pn!=total[ccc].pn){
		cout<<"pn凭证错误，请重试"<<endl;
		return foundpw();
	}
	cout<<"已找回您的密码："<<total[ccc].pw<<endl;
	cout<<"您应当牢记您的密码，按3即可返回主菜单"<<endl;
	while(k){
		cin>>p;
		if(p[0]!='3')
			cout<<"请不要瞎按！"<<endl;
		if(p[0]=='3')
			return 3;
		memset(p,'\0',sizeof(p)); 
	} 
}

int useradmin(int t){
	char pp;
	int p;
	if(t==2) {
		useradminmenu();
		cin>>pp;
		p=pp;
		system("cls");
		switch(p){
			case 49:
				founduser(1);
				return useradmin(2);
			case 50:
				founduser(2);
				return useradmin(2);
			case 51:
				deleteuser();
				return useradmin(2);
			case 52:
				return 0;
		} 
	}
	if(t==1){
		userusermenu();
		cin>>pp;
		p=pp;
		system("cls");
		switch(p){
			case 49:
				seekuser(1);
				return useradmin(1);
			case 50:
				modifyuser(1);
				return useradmin(1);
			case 51:
				cuttime();
				return useradmin(1);
			case 52:
				return 0;
		}
	}
	cout<<"不存在该选项，请重试！"<<endl;
	Sleep(1000);
	system("cls");
	return useradmin(t);
}




int admin() {
	int t;
	char temp;
	adminmenu();
	cout<<"输入你的选择:"<<endl;
	cin>>temp;
	t=temp;
	system("cls");
	switch(t){
		case 49:
			adminregister();
			return admin();
		case 50:
			Modify();
			return admin();					
		case 51:
			useradmin(2);
			return admin();									
		case 52:
			return login();
	}
	cout<<"不存在该选项，请重试！"<<endl;
	Sleep(1000);
	system("cls");
	return admin();
}

int sumtime(int hard, double time){
	switch(hard){
		case 1:total[ccc].time1=total[ccc].time1>time?total[ccc].time1:time;return 0;
		case 2:total[ccc].time2=total[ccc].time2>time?total[ccc].time2:time;return 0;
		case 3:total[ccc].time3=total[ccc].time3>time?total[ccc].time3:time;return 0;
	}
}
int user(){
	char temp;
	double time1;
	double time2;
	double time3;
	int t;
	usermenu();
	cout<<"输入你的选择:"<<endl;
	cin>>temp;
	t=temp;
	system("cls");
	switch(t){
		case 49:
			useradmin(1);
			return user();
		case 50:
			hardchoice();
			return user();			
		case 51:
			besttime();
			return user();
		case 52:
			return login();
	} 
	cout<<"不存在该选项，请重试！"<<endl;
	Sleep(1000);
	system("cls");
	return user();
}


