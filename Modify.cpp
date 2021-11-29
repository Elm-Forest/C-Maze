#include"sky.h"

int MapGet(char a[][MAX],int hard){
	int num,i,j;
	if(hard==1) 
		num=low;
	else if(hard==2) 
		num=mid;
	else 
		num=high; 
    FILE *fp;
    if(hard==1) 
		fp=fopen("data1.txt","r");
	else if(hard==2) 
		fp=fopen("data2.txt","r");
	else 
		fp=fopen("data3.txt","r"); 
    if(fp==NULL){
        printf("不存在该选项，请重新输入");
        return 0; 
    }
    for(i=0; i<num; i++)
        for(j=0; j<MAX; j++)
            fscanf(fp,"%c",&a[i][j]);
    fclose(fp);
    return 0;
}


int MapChange(int hard){
    int num,i,j;
	if(hard==1) 
		num=low;
	else if(hard==2) 
		num=mid;
	else num=high; 
    FILE *fp;
    if(hard==1) 
		fp=fopen("data1.txt","w");
	else if(hard==2) 
		fp=fopen("data2.txt","w");
	else 
		fp=fopen("data3.txt","w"); 
    if(fp==NULL){
        printf("错误的修改，请重新选择");
        return 0;
    }
    char a[num][MAX];
    for(i=0; i<num; i++)
    	for(j=0;j<MAX;j++)
       		scanf("%c",&a[i][j]);
    for(i=0; i<num; i++){
    	for(j=0; j<MAX-1; j++)
        	fprintf(fp,"%c",a[i][j]);
    	fprintf(fp,"\n");
	}
	printf("修改成功"); 
    fclose(fp);
}


int Modify(){
	int hard=1,i,j;
	char p[50];
	int k=5;
	cout<<"注意:我们建议你不要随意使用此功能"<<endl;
	cout<<"一旦你输入了将要修改的难度，你就必须完成难度的修改，直接退出则会导致已有迷宫清零"<<endl;
	cout<<"如非要使用请将原来的文本文件保留一份备份"<<endl;
	cout<<"注意保留的文本文件备份需与原来的名称相同，例如data1.txt...,而且最重要的是备份的文件应与当前文件不在同一文件夹！"<<endl<<endl;
	cout<<"您现在也可以选择返回上一级，按3即可！，确认要继续修改请按2"<<endl<<endl; 
	while(k){
		cin>>p;
		if(p[0]=='2')
			break; 
		if(p[0]!='3')
			cout<<"请不要瞎按！"<<endl;
		if(p[0]=='3')
			return 0;
		memset(p,'\0',sizeof(p)); 
	} 
	cout<<"注意："<<endl<<"难度从低到高分为1，2，3,目前默认难度为1"<<endl;
	cout<<"选择需要修改的难度："<<endl;
	cin>>hard;
	cout<<"以下修改对应难度的迷宫，注意："<<endl;
	switch(hard){
		case 1:cout<<"难度1为  10(行)x15(列)"<<endl;break;
		case 2:cout<<"难度2为  15(行)x15(列)"<<endl;break;
		case 3:cout<<"难度3为  20(行)x15(列)"<<endl;break;
	}
	cout<<"请保证行列的字符数均为对应要求！"<<endl;
	char a[high][MAX];
	MapGet(a,3); 
	MapChange(hard);
	switch(hard){
		case 1:return 1;
		case 2:return 2;
		case 3:return 3;
	} 
}
