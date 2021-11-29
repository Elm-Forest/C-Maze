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
        printf("�����ڸ�ѡ�����������");
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
        printf("������޸ģ�������ѡ��");
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
	printf("�޸ĳɹ�"); 
    fclose(fp);
}


int Modify(){
	int hard=1,i,j;
	char p[50];
	int k=5;
	cout<<"ע��:���ǽ����㲻Ҫ����ʹ�ô˹���"<<endl;
	cout<<"һ���������˽�Ҫ�޸ĵ��Ѷȣ���ͱ�������Ѷȵ��޸ģ�ֱ���˳���ᵼ�������Թ�����"<<endl;
	cout<<"���Ҫʹ���뽫ԭ�����ı��ļ�����һ�ݱ���"<<endl;
	cout<<"ע�Ᵽ�����ı��ļ���������ԭ����������ͬ������data1.txt...,��������Ҫ���Ǳ��ݵ��ļ�Ӧ�뵱ǰ�ļ�����ͬһ�ļ��У�"<<endl<<endl;
	cout<<"������Ҳ����ѡ�񷵻���һ������3���ɣ���ȷ��Ҫ�����޸��밴2"<<endl<<endl; 
	while(k){
		cin>>p;
		if(p[0]=='2')
			break; 
		if(p[0]!='3')
			cout<<"�벻ҪϹ����"<<endl;
		if(p[0]=='3')
			return 0;
		memset(p,'\0',sizeof(p)); 
	} 
	cout<<"ע�⣺"<<endl<<"�Ѷȴӵ͵��߷�Ϊ1��2��3,ĿǰĬ���Ѷ�Ϊ1"<<endl;
	cout<<"ѡ����Ҫ�޸ĵ��Ѷȣ�"<<endl;
	cin>>hard;
	cout<<"�����޸Ķ�Ӧ�Ѷȵ��Թ���ע�⣺"<<endl;
	switch(hard){
		case 1:cout<<"�Ѷ�1Ϊ  10(��)x15(��)"<<endl;break;
		case 2:cout<<"�Ѷ�2Ϊ  15(��)x15(��)"<<endl;break;
		case 3:cout<<"�Ѷ�3Ϊ  20(��)x15(��)"<<endl;break;
	}
	cout<<"�뱣֤���е��ַ�����Ϊ��ӦҪ��"<<endl;
	char a[high][MAX];
	MapGet(a,3); 
	MapChange(hard);
	switch(hard){
		case 1:return 1;
		case 2:return 2;
		case 3:return 3;
	} 
}
