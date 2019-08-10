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
		printf("\n       职工管理系统");
		printf("\n1.添加                   2.保存");
		printf("\n3.载入                   4.查看");
		printf("\n5.修改                   0.退出");
		printf("\n6.查询                   7.删除\n");
        printf("*********************************\n");
		printf("请选择：");
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
		default:printf("<<<输入错误!!!\n");break;
		}
	}	return 0;
}
void Exit()
{
	exit(0);
}
void show()//输出职工信息
{
	JD *p;
	if(start->next == NULL){
		printf("\n>>>>>>>>>>提示:没有记录可以显示! 按任意键回主菜单。\n");
		return;
	}
		printf("\t\t显示结果\n");
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
		printf("请添加学生信息!\n");

		printf("请添加姓名：\n");
        scanf("%s",p->data.name);
        printf("请添加学生学号：\n");
        scanf("%s",p->data.number);
        //if(strat不空)//if(重复)
        //重新输入
        //循环
        if(start->next!=NULL)
        {
            while(checkRepeat(p->data.number)==0)
            {
                 scanf("%s",p->data.number);
            }
        }
        end->next=p;
        end=p;
		printf("是否继续添加?（1表示是///0表示否）\n");
		scanf("%d",&m);
	}while(m==1);
}
int checkRepeat(char s[])
{
    int i=1;
    JD *start1;
    start1=start;
    //用tart1代替start是防止多次重复时，检测起点有问题
    while(start1->next!=NULL){
        start1=start1->next;
        if(strcmp(s,start1->data.number)==0){
            printf("学号重复，请重新输入:");
            i=0;
        }
    }
    return i;
}
void save()
{
   char hu;
	printf("是否覆盖原文件信息[Y/N]?      ");
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
		printf("无可保存信息！\n");
	else
		p=start->next;
	if((fp=fopen("E:\\b\\职工管理系统.txt","w+"))==NULL)
		printf("无法打开!\n");
	while(p){
		fprintf(fp," %s %s",p->data.name,p->data.number);
		p=p->next;
	}
	fclose(fp);
	printf("保存成功！\n");
}
void load(){
    char hu;
	printf("是否覆盖当前链表信息[Y/N]?      ");
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
	if((fp=fopen("E:\\b\\职工管理系统.txt","r"))==NULL){
	    printf("打开文件失败!!\n");
	}
	printf("\t\t载入的文件信息\n");
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
    printf("\n文件里共有%d条记录\n",count);
}
void finding(){
     JD *p;
     char finding[10];
     printf("请输入要查询的职工号：");
     scanf("%s",finding);
     p=start->next;
     while(p!=NULL){
		  if(strcmp(p->data.number,finding)==0){     //如果找到的话返回的是符合要求
			printf("\n%s %s\n",p->data.name,p->data.number);
			break;
		  }
		   p=p->next;
     }
     if(p)
         printf("查询成功!\n");
    else
        printf("你要查找的信息不存在!\n");
}
void change(){		//修改职工信息函数
	JD *p;
	char find[10];   //存储查询职工号
	if(start->next == NULL){
		printf("\n>>>>>>>>>>提示:没有资料可以修改! 按任意键回主菜单。\n");
		getchar();
		getchar();
		return;
	}
	printf("请输入要修改的职工号:");
	scanf("%s",find);
    p=start->next;
    while(p!=NULL){
		  if(strcmp(p->data.number,find)==0){     //如果找到的话返回的是符合要求
			break;
		  }
		   p=p->next;
     }
    if(p){
           printf("请输入新职工号(原来是 %s ):",p->data.number);
           scanf("%s",p->data.number);
           printf("请输入新职工姓名(原来是 %s ):",p->data.name);
           scanf("%s",p->data.name);
           printf("修改成功！\n");
    }
    else{
		printf("\n>>提示:你要修改的信息不存在!\n");
	}
}
void Delete(){
     JD *p,*temp;
     char finding[10];
     printf("请输入要删除的职工号：");
     scanf("%s",finding);
     p=start;
     while(p!=NULL){

		  if(strcmp(p->data.number,finding)==0){     //如果找到的话返回的是符合要求
            printf("要删除的员工信息：");
            printf("%s %s\n",p->data.name,p->data.number);
            break;
		  }
          temp=p;
          p=p->next;
     }
     if(p)
        if(temp->next==p){
            temp->next=p->next;
            printf("删除成功!\n");
		}
		else
            printf("%s %s\n",temp->data.name,temp->data.number);
    else
        printf("\n>>>>>>>>>>提示:找不到您想删除的职工号!\n");
}

