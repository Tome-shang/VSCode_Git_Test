// hello.cpp : Defines the entry point for the console application.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct students
{
	char name[10];
    char number[10];
};
typedef struct node
{
	struct students data;
	struct node *next;
}JD;
JD *start;
JD *end;
FILE *fp;

void Exit();
void add();
void save();
void load();
void change();
void show();
void finding();
void Delete();
int checkRepeat(char s[]);

int main()
{
	int choose;
	while(1)
	{
	    printf("*********************************");
		printf("\n       ְ������ϵͳ");
		printf("\n1.���                   2.����");
		printf("\n3.����                   4.�鿴");
		printf("\n5.�޸�                   0.�˳�");
		printf("\n6.��ѯ                   7.ɾ��\n");
        printf("*********************************\n");
		printf("��ѡ��");
		scanf("%d",&choose);
		switch(choose)
		{
		case 0:Exit();      break;
		case 1:add();       break;
		case 2:save();      break;
		case 3:load();      break;
		case 4:show();      break;
		case 5:change();    break;
		case 6:finding();   break;
		case 7:Delete();    break;
		default:printf("<<<�������!!!\n");break;
		}
	}	return 0;
}
void Exit()
{
	exit(0);
}
void show()//���ְ����Ϣ
{
	JD *p;
	if(start->next == NULL){
		printf("\n>>>>>>>>>>��ʾ:û�м�¼������ʾ! ������������˵���\n");
		return;
	}
		printf("\t\t��ʾ���\n");
		p=start->next;
	while(p){
		printf("\n%s %s\n",p->data.name,p->data.number);
		p=p->next;
	}
}
void add()
{
    start=(JD*)malloc(sizeof(JD));
    start->next=NULL;
	JD *p,*temp;
	int m=1;
	end=start;
	do{
		p=(JD*)malloc(sizeof(JD));
		p->next=NULL;
		printf("�����ѧ����Ϣ!\n");

		printf("�����������\n");
        scanf("%s",p->data.name);
        printf("�����ѧ��ѧ�ţ�\n");
        scanf("%s",p->data.number);
        //if(strat����)//if(�ظ�)
        //��������
        //ѭ��
        if(start->next!=NULL)
        {
            while(checkRepeat(p->data.number)==0)
            {
                 scanf("%s",p->data.number);
            }
        }
        end->next=p;
        end=p;
		printf("�Ƿ�������?��1��ʾ��///0��ʾ��\n");
		scanf("%d",&m);
	}while(m==1);
}
int checkRepeat(char s[])
{
    int i=1;
    JD *start1;
    start1=start;
    //��tart1����start�Ƿ�ֹ����ظ�ʱ��������������
    while(start1->next!=NULL){
        start1=start1->next;
        if(strcmp(s,start1->data.number)==0){
            printf("ѧ���ظ�������������:");
            i=0;
        }
    }
    return i;
}
void save()
{
   char hu;
	printf("�Ƿ񸲸�ԭ�ļ���Ϣ[Y/N]?      ");
	scanf("%s", &hu);
	switch(hu){
	case 'Y':
	case 'y': break;
	case 'N':
	case 'n':
	default : return;
	}
	JD *p;
	if(start->next==NULL)
		printf("�޿ɱ�����Ϣ��\n");
	else
		p=start->next;
	if((fp=fopen("E:\\b\\ְ������ϵͳ.txt","w+"))==NULL)
		printf("�޷���!\n");
	while(p){
		fprintf(fp," %s %s",p->data.name,p->data.number);
		p=p->next;
	}
	fclose(fp);
	printf("����ɹ���\n");
}
void load(){
    char hu;
	printf("�Ƿ񸲸ǵ�ǰ������Ϣ[Y/N]?      ");
	scanf("%s", &hu);
	switch(hu){
	case 'Y':
	case 'y': break;
	case 'N':
	case 'n':
	default : return;
	}
	start=(JD*)malloc(sizeof(JD));
	start->next==NULL;
	end=start;
	JD *p;
	int count=0;
	if((fp=fopen("E:\\b\\ְ������ϵͳ.txt","r"))==NULL){
	    printf("���ļ�ʧ��!!\n");
	}
	printf("\t\t������ļ���Ϣ\n");
    while(!feof(fp)){
        p=(JD*)malloc(sizeof(JD));
        p->next=NULL;
        fscanf(fp,"%s %s",p->data.name,p->data.number);
        printf("\n%s %s\n",p->data.name,p->data.number);
        end->next=p;
        end=p;
        count++;
    }
    fclose(fp);
    printf("\n�ļ��ﹲ��%d����¼\n",count);
}
void finding(){
     JD *p;
     char finding[10];
     printf("������Ҫ��ѯ��ְ���ţ�");
     scanf("%s",finding);
     p=start->next;
     while(p!=NULL){
		  if(strcmp(p->data.number,finding)==0){     //����ҵ��Ļ����ص��Ƿ���Ҫ��
			printf("\n%s %s\n",p->data.name,p->data.number);
			break;
		  }
		   p=p->next;
     }
     if(p)
         printf("��ѯ�ɹ�!\n");
    else
        printf("��Ҫ���ҵ���Ϣ������!\n");
}
void change(){		//�޸�ְ����Ϣ����
	JD *p;
	char find[10];   //�洢��ѯְ����
	if(start->next == NULL){
		printf("\n>>>>>>>>>>��ʾ:û�����Ͽ����޸�! ������������˵���\n");
		getchar();
		getchar();
		return;
	}
	printf("������Ҫ�޸ĵ�ְ����:");
	scanf("%s",find);
    p=start->next;
    while(p!=NULL){
		  if(strcmp(p->data.number,find)==0){     //����ҵ��Ļ����ص��Ƿ���Ҫ��
			break;
		  }
		   p=p->next;
     }
    if(p){
           printf("��������ְ����(ԭ���� %s ):",p->data.number);
           scanf("%s",p->data.number);
           printf("��������ְ������(ԭ���� %s ):",p->data.name);
           scanf("%s",p->data.name);
           printf("�޸ĳɹ���\n");
    }
    else{
		printf("\n>>��ʾ:��Ҫ�޸ĵ���Ϣ������!\n");
	}
}
void Delete(){
     JD *p,*temp;
     char finding[10];
     printf("������Ҫɾ����ְ���ţ�");
     scanf("%s",finding);
     p=start;
     while(p!=NULL){

		  if(strcmp(p->data.number,finding)==0){     //����ҵ��Ļ����ص��Ƿ���Ҫ��
            printf("Ҫɾ����Ա����Ϣ��");
            printf("%s %s\n",p->data.name,p->data.number);
            break;
		  }
          temp=p;
          p=p->next;
     }
     if(p)
        if(temp->next==p){
            temp->next=p->next;
            printf("ɾ���ɹ�!\n");
		}
		else
            printf("%s %s\n",temp->data.name,temp->data.number);
    else
        printf("\n>>>>>>>>>>��ʾ:�Ҳ�������ɾ����ְ����!\n");
}

