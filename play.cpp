#include"sky.h" 

typedef struct stark{
  	int i;
  	int j;
	int d;
}stark;
  
stark path[MaxSize]; 
int top = -1;    //初始化栈指针 
  
void FindPath(char a[][MAX],int hard) {
	int xb=1,yb=0,xe=hard*5+5-1,ye=MAX-3;
	//起点入栈
	top++;
	path[top].i = xb;
	path[top].j = yb;
	path[top].d = -1;
	a[xb][yb] = 2;    						//标记起点     
	int i,j,k,d,find;    			//映射变量与旗帜变量 
	while(top>-1){
		i = path[top].i;
		j = path[top].j;
		d = path[top].d;
		if(i == xe && j == ye){
			cout << "迷宫路径如下：" << endl;
			for(int i = 0 ;i<hard*5+5; i++){
				for(int j = 0;j<MAX-1;j++)
					cout<<a[i][j];
				cout << endl;
			}
			return ; 
		}
		find = 0;
		while(d<4 && find == 0){    //循环判断上下左右每一个方向的情况，不是1直接入栈，是1再次循环，循环四次都是1则弹栈 
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
			a[i][j] = '2';    //标记每一个通路为-1，防止原路返回，如果弹栈则将相应的-1换为0 
		}
		else{
			a[path[top].i][path[top].j] = 0;
			top--;
		}
	}
	cout << "无路可走！" << endl; 
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
		cout<<"以上为通关方式，按2以继续"<<endl;
		while(k){
		cin>>p;
		if(p[0]!=2)
			cout<<"请不要瞎按！"<<endl;
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
			cout<<"不好意思，此路不通，请重试!"<<endl;
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
		cout<<"太棒了，恭喜完成游戏!"<<endl;
		printf("通关的时间为：%.2fs\n",t);
		Sleep(3000);
		system("cls");	
	}
    
    
    return t;
}
void rule(){
	cout<<"________________________________________________"<<endl;
	cout<<"|*****************游戏规则*********************|"<<endl;
	cout<<"|       游戏按难度从小到大分1，2，3三个等级    |"<<endl;
	cout<<"|       1级为10x15，2级为15X15,3级为20X15      |"<<endl;
	cout<<"|     玩家请根据自身需求选择合适的难度基数     |"<<endl;
	cout<<"|  操作：w为向上，s为向下，a为向左，d为向右    |"<<endl;
	cout<<"|             快开启你的挑战之旅吧！           |"<<endl; 
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
}

int hardchoice(){
	int hard;
	double time;
	int k=5;
	char p[50];
	rule();
	cout<<"你选择的难度等级为："<<endl;
	cin>>hard;
	style();
	cout<<"按3可查看改难度迷宫通关方法，按2可继续闯关"<<endl;
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
		cout<<"请不要瞎按！"<<endl;
		memset(p,'\0',sizeof(p)); 
	}
	return sumtime(hard,time);
}
