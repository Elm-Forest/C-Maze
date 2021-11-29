#include"sky.h" 

typedef struct stark{
  	int i;
  	int j;
	int d;
}stark;
  
stark path[MaxSize]; 
int top = -1;    //��ʼ��ջָ�� 
  
void FindPath(char a[][MAX],int hard) {
	int xb=1,yb=0,xe=hard*5+5-1,ye=MAX-3;
	//�����ջ
	top++;
	path[top].i = xb;
	path[top].j = yb;
	path[top].d = -1;
	a[xb][yb] = 2;    						//������     
	int i,j,k,d,find;    			//ӳ����������ı��� 
	while(top>-1){
		i = path[top].i;
		j = path[top].j;
		d = path[top].d;
		if(i == xe && j == ye){
			cout << "�Թ�·�����£�" << endl;
			for(int i = 0 ;i<hard*5+5; i++){
				for(int j = 0;j<MAX-1;j++)
					cout<<a[i][j];
				cout << endl;
			}
			return ; 
		}
		find = 0;
		while(d<4 && find == 0){    //ѭ���ж���������ÿһ����������������1ֱ����ջ����1�ٴ�ѭ����ѭ���Ĵζ���1��ջ 
			d++;
			switch(d){
				case 0:
					i = path[top].i-1;
					j = path[top].j;
					break;
				case 1:
					i = path[top].i;
					j = path[top].j+1;
					break;
				case 2:
					i = path[top].i+1;
					j = path[top].j;
					break;
				case 3:
					i = path[top].i; 
					j = path[top].j-1;
					break;
			}
			if(a[i][j]=='0') find = 1;
		}
		if(find == 1){
			path[top].d = d;
			top ++;
			path[top].i = i;
			path[top].j = j;
			path[top].d = -1;
			a[i][j] = '2';    //���ÿһ��ͨ·Ϊ-1����ֹԭ·���أ������ջ����Ӧ��-1��Ϊ0 
		}
		else{
			a[path[top].i][path[top].j] = 0;
			top--;
		}
	}
	cout << "��·���ߣ�" << endl; 
}

void style(){
	system("mode con cols=270 lines=90");
    system("color 80");
} 

int ppp(int hard,int f){
	char plt[high][MAX];
	int n;
	int i=0,j=0;
	char p[50];
	int k=5;
	FILE* fp;
	switch(hard){
		case 1:fp=fopen("data1.txt","r");n=low;break;
		case 2:fp=fopen("data2.txt","r");n=mid;break;
		case 3:fp=fopen("data3.txt","r");n=high;break;
	}
	if(fp!=NULL)
		for(int i=0;i<n;i++)
			for(int j=0;j<MAX;j++)
				plt[i][j]=fgetc(fp);
	if(f==2){
		FindPath(plt,hard);
		cout<<"����Ϊͨ�ط�ʽ����2�Լ���"<<endl;
		while(k){
		cin>>p;
		if(p[0]!=2)
			cout<<"�벻ҪϹ����"<<endl;
		if(p[0]=='2'){
			system("cls");
			return ppp(hard,1);
		}
		memset(p,'\0',sizeof(p)); 
	}
	} 
	i=1,j=0;
	int t=0;
	while(1){
		for(int k=0;k<n;k++){
			for(int p=0;p<MAX;p++)
				cout<<plt[k][p]<<" ";
			cout<<endl;
		}
		t=getch();
		switch(t){
			case 119:
				plt[--i][j]+=2;
				break;
			case 115:
				plt[++i][j]+=2;
				break;
			case 97:
				plt[i][--j]+=2;
				break;
			case 100:
				plt[i][++j]+=2;
				break;
		}
		t=0;
		Sleep(100);
		system("cls");
		if(plt[i][j]=='3'||plt[i][j]=='4'){
			cout<<"������˼����·��ͨ��������!"<<endl;
			i=1,j=1;
			Sleep(2000);
			return ppp(hard,f);
		}
		if(i==n-1)
			return 1;
	}
}

int result(int hard,int f){
	clock_t start, stop;
	double t;
	double time;
	int temp;
    start=clock();
    temp=ppp(hard,f);
	stop=clock();
	t=(double)(stop-start)/CLK_TCK;
	if(temp==1){
		cout<<"̫���ˣ���ϲ�����Ϸ!"<<endl;
		printf("ͨ�ص�ʱ��Ϊ��%.2fs\n",t);
		Sleep(3000);
		system("cls");	
	}
    
    
    return t;
}
void rule(){
	cout<<"________________________________________________"<<endl;
	cout<<"|*****************��Ϸ����*********************|"<<endl;
	cout<<"|       ��Ϸ���Ѷȴ�С�����1��2��3�����ȼ�    |"<<endl;
	cout<<"|       1��Ϊ10x15��2��Ϊ15X15,3��Ϊ20X15      |"<<endl;
	cout<<"|     ����������������ѡ����ʵ��ѶȻ���     |"<<endl;
	cout<<"|  ������wΪ���ϣ�sΪ���£�aΪ����dΪ����    |"<<endl;
	cout<<"|             �쿪�������ս֮�ðɣ�           |"<<endl; 
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
}

int hardchoice(){
	int hard;
	double time;
	int k=5;
	char p[50];
	rule();
	cout<<"��ѡ����Ѷȵȼ�Ϊ��"<<endl;
	cin>>hard;
	style();
	cout<<"��3�ɲ鿴���Ѷ��Թ�ͨ�ط�������2�ɼ�������"<<endl;
 	while(k){
		cin>>p;
		if(p[0]=='3'){
			time=result(hard,2);
			break; 
		}
		if(p[0]=='2'){
			time=result(hard,1);
			break;
		}
		cout<<"�벻ҪϹ����"<<endl;
		memset(p,'\0',sizeof(p)); 
	}
	return sumtime(hard,time);
}
