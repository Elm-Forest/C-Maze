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

const char adminid[]={"admin"};				//����Ա��ʼ�˺ţ�������� 
const char adminpw[]={"admin123456"};		//��Ϊ����Ա��ʼ���룬�������
const char back[] = { "5" };				//��½ʱ������һ������ ,�˴�Ĭ��Ϊ5,�Ͻ����ģ����� 
const char back2[]={"4"};					//����ʱ������һ������ ,�˴�Ĭ��Ϊ4���Ͻ����ģ����� 
users total[max];
admins adminl[max];							
int  usernum = 0;							//��ע����û��� 
int adminnum=1;								//��ע�����Ա�� 
int ccc=0;									//��ǰ��½���û���¼ֵ 
int bbb=0;									//��ǰ��½�Ĺ���Ա��¼ֵ
 
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
		cout << "           ¼���û���Ϊ0������ע��" << endl;
		return 3;
	}
	cout << "           ���������Ա�˺�" << endl;
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
			cout << "            �˺Ų�����,������" << endl;
			continue;
		}
		if (couts != 0)
			break;
	}
	cout << "             ���������Ա����" << endl;
	while (k) {
		scanf("%s", &pw);
		if (strcmp(pw, back) == 0)
			return 3;
		if (strcmp(pw, adminl[temp].pw) != 0)
			cout << "           �µĺã�ʣ�ೢ�Դ���" << --k << "��" << endl;
		else {
			k = 0;
			cout << "           ��ӭ����,����Ա" << endl;
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
		cout << "           ¼���û���Ϊ0������ע��" << endl;
		Sleep(1000); 
		return 3;
	}
	cout << "           �������û��˺�" << endl;
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
			cout << "            ��Ҳ�����,������" << endl;
			continue;
		}
		if (couts != 0) {
			break;
		}
	}
	cout << "             �������������" << endl;
	while (k) {
		scanf("%s", &pw);
		if (strcmp(pw, back) == 0)
			return 3;
		if (strcmp(pw, total[temp].pw) != 0)
			cout << "           �µĺã�ʣ�ೢ�Դ���" << --k << "��" << endl;
		else {
			k = 0;
			cout << "           ��ӭ����,���" << endl;
			ccc=temp;
			return 1;
		}
	}
	return 2;
}

int adminregister(){
	int k=5;
	if(adminnum==max-1){
		cout<<"ע�����Ա���Ѵ�����ֵ�������·����ڴ�"<<endl;
		return 0;
	}
	char pw[20];
	cout<<"��ӭע���¹���Ա,���������Ա�˺�:"<<endl;
	cin>>adminl[adminnum].id;
	while(k){
		cout<<"���������Ա���룺"<<endl;
		cin>>adminl[adminnum].pw;
		cout<<"���ٴ�����:"<<endl;
		cin>>pw;
		if(strcmp(adminl[adminnum].pw,pw)==0)
			k=0;
		else
			cout<<"ǰ�����벻һ�£������ԣ�"<<endl;
	}
	cout<<"���ѳɹ�ע��,���ڷ��ص�½"<<endl;
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
		cout << "           ע��������Ѵ����ޣ�����ϵ����Ա" << endl;
		return 3;
	}
	cout << "           ��ӭע�ᣬ�����������ʺ�,������Ϊ8λ" << endl;
	scanf("%s", &total[usernum].id);
	if (strcmp(total[usernum].id, back) == 0) {
		return 3;
	}
	while (5) {
		cout << "           �������������룬������λ6λ" << endl;
		scanf("%s", &total[usernum].pw);
		if (strcmp(total[usernum].pw, back) == 0) {
			return 3;
		}
		cout << "           ��ȷ����������" << endl;
		scanf("%s", &pw);
		if (strcmp(total[usernum].pw, back) == 0) {
			return 3;
		}
		if (strcmp(pw, total[usernum].pw) != 0) {
			cout << "           ���һ�ν����һ�£������ԣ�" << endl;
			continue;
		}
		else {
			while(1){
				cout<<  "            �����������ֻ��ź���λ������Ϊ����pnƾ֤�����������һ�"<<endl;
				cin>>total[usernum].pn;
				if (total[usernum].pn==4)
					return 3;
				cout<<  "����������Ϣ��ȷ���Ƿ�����,������������1����������2"<<endl;
				cin>>t;
				if(t==1)
					break;
				if(t==2)
					return 3;		 
			}
			usernum++;
			cout << "���ѳɹ�ע�ᣡ�뷵�ص�½" << endl;
			return 1;
		}
	}
}

void loginmenu() {
    cout<<"_________________________________________"<<endl;
    cout<<"|*****************�Թ�******************|"<<endl;
	cout<<"|*             1.����Ա��½            *|"<<endl;
	cout<<"|*             2.�û���¼              *|"<<endl;
	cout<<"|*             3.�û�ע��              *|"<<endl;
	cout<<"|*             4.�һ�����              *|"<<endl;
	cout<<"|*             5.������һ��            *|"<<endl;
	cout<<"|*             6.�˳�ϵͳ              *|"<<endl;
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
				printf("���Դ����Ѻľ�������ϵͳing...");
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
				printf("�µĺã������µ�½......");
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
			cout<<"ллʹ�ã�"<<endl;
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
    cout<<"|*****************����Ա****************|"<<endl;
	cout<<"|*             1.����Ա����            *|"<<endl;
	cout<<"|*             2.�Թ��޸�              *|"<<endl;
	cout<<"|*             3.�û�����              *|"<<endl;
	cout<<"|*             4.����Ա�˳�            *|"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
} 

void usermenu(){
    cout<<"_________________________________________"<<endl;
    cout<<"|*****************���******************|"<<endl;
	cout<<"|*             1.���ĸ�����Ϣ          *|"<<endl;
	cout<<"|*             2.��ʼ��Ϸ              *|"<<endl;
	cout<<"|*             3.�鿴��߳ɼ�          *|"<<endl;
	cout<<"|*             4.����˳�              *|"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
} 

void useradminmenu(){
	cout<<"_________________________________________"<<endl;
	cout<<"|*****�����������Ա���û��������******|"<<endl;
	cout<<"|*          1.��ѯ�û�������Ϣ         *|"<<endl;
	cout<<"|*          2.�޸��û�����             *|"<<endl;
	cout<<"|*          3.ɾ���û�����             *|"<<endl;
	cout<<"|*          4.������һ��               *|"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
}

void userusermenu(){
	cout<<"_________________________________________"<<endl;
    cout<<"|*******���������û����û��������******|"<<endl;
	cout<<"|*             1.��ѯ�û�������Ϣ      *|"<<endl;
	cout<<"|*             2.�޸��û�����          *|"<<endl;
	cout<<"|*             3.�����ѳɼ�          *|"<<endl;
	cout<<"|*             4.����Ա�˳�            *|"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
}

void modifyusermenu(){
	cout<<"_________________________________________"<<endl;
    cout<<"|***********�����û������޸Ľ���********|"<<endl;
	cout<<"|*             1.�޸��û��˺�          *|"<<endl;
	cout<<"|*             2.�޸��û�����          *|"<<endl;
	cout<<"|*             3.�޸��û�pn            *|"<<endl;
	cout<<"|*             4.����Ա�˳�            *|"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
}

int deleteuser(){
	char id[20];
	char q[]={"4"};
	int n=-1;
	int t=0;
	cout<<"������ɾ���û�����4���ɷ�����һ��"<<endl; 
	cout<<"����������ɾ�����û��˺�"<<endl;
	scanf("%s",&id);
	if(strcmp(id,q)==0)
			return 0;
	for(int i=0;i<usernum;i++)
		if(strcmp(id,total[i].id)==0)
			n=i;
	if(n==-1){
		cout<<"�û������ڣ������ԣ�"<<endl;
		Sleep(1000);
		system("cls");
		return deleteuser();
	}
	cout<<"��ȷ��ɾ�����û���ȷ���밴1�������밴2"<<endl;
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
	cout<<"�û�ɾ���ɹ���"<<endl;
	return 0;
}

void cuttime(){
	total[ccc].time1=0;
	total[ccc].time2=0;
	total[ccc].time3=0;
}

void besttime(){
	printf("�Ѷ�1�����ͨ��ʱ��Ϊ��%.2fs\n",total[ccc].time1); 
	printf("�Ѷ�2�����ͨ��ʱ��Ϊ��%.2fs\n",total[ccc].time2);
	printf("�Ѷ�3�����ͨ��ʱ��Ϊ��%.2fs\n",total[ccc].time3);
}

int seekuser(int p){
	if(p==1){
		int pn;
		cout<<"�������û�pnƾ֤:"<<endl;
		cin>>pn;
		if(pn==4)
			return 0;
		if(pn!=total[ccc].pn){
			cout<<"pn����������"<<endl;
			return seekuser(1);
		}
	}
	cout<<"���û��˺ţ�"<<total[ccc].id<<endl;
	cout<<"���û�����:"<<total[ccc].pw<<endl;
	cout<<"�û���pnƾ֤��"<<total[ccc].pn<<endl; 
}

int modifyuser(int p){
	if(p==1){
		int pn;
		cout<<"�������û�pnƾ֤"<<endl;
		cin>>pn;
		if(pn==4)
			return 0;
		if(pn!=total[ccc].pn){
			cout<<"pn����������"<<endl;
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
			cout<<"�������޸ĺ���˺ţ�"<<endl; 
			cin>>total[ccc].id;
			return modifyuser(2);
		case 50:
			cout<<"�������޸ĺ�����룺"<<endl; 
			cin>>total[ccc].pw;
			return modifyuser(2);
		case 51:
			cout<<"�������޸ĺ��pn"<<endl; 
			cin>>total[ccc].pn;
			return modifyuser(2);
		case 52:
			return 0;
	}
	cout<<"�����ڸ�ѡ������ԣ�"<<endl;
	Sleep(1000);
	system("cls");
	return modifyuser(p);
	
}

int founduser(int n){
	char id[20];
	int t=0;
	cout<<"�����û��˺�"<<endl;
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
		cout<<"�û�������"<<endl;
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
	cout<<"����������pnƾ֤��"<<endl;
	cin>>pn;
	if(pn==5)
		return 3;
	if(pn!=total[ccc].pn){
		cout<<"pnƾ֤����������"<<endl;
		return foundpw();
	}
	cout<<"���һ��������룺"<<total[ccc].pw<<endl;
	cout<<"��Ӧ���μ��������룬��3���ɷ������˵�"<<endl;
	while(k){
		cin>>p;
		if(p[0]!='3')
			cout<<"�벻ҪϹ����"<<endl;
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
	cout<<"�����ڸ�ѡ������ԣ�"<<endl;
	Sleep(1000);
	system("cls");
	return useradmin(t);
}




int admin() {
	int t;
	char temp;
	adminmenu();
	cout<<"�������ѡ��:"<<endl;
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
	cout<<"�����ڸ�ѡ������ԣ�"<<endl;
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
	cout<<"�������ѡ��:"<<endl;
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
	cout<<"�����ڸ�ѡ������ԣ�"<<endl;
	Sleep(1000);
	system("cls");
	return user();
}


