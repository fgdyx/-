#include"stdio.h"
#include"string.h"
#include"stdlib.h"

struct cailiao
{
	long No;
	char name[20];
	float price;
	int input;
	int put;
	int output;
	char people[20];
	int intime1,intime2,intime3;
	int outtime1,outtime2,outtime3;
	char bz[20];
};
struct studcode{
	struct cailiao cl;
	struct studcode *next;
};

void menu();
void input(struct studcode **);
void output(struct studcode *);
void binsearch(struct studcode *);
void insert(struct studcode **);
void delet(struct studcode **);
void sort(struct studcode *);
void print(struct studcode *);
void back();

void main()
{
	char choose;
	int flag=1;
	struct studcode *head;
	head=NULL;
	printf("欢迎使用材料管理系统\n");
	printf("\n请先录入材料基本信息\n");
	system("pause");
	printf("输入编号、名称、单价、入库数量、库存数量、出库数量、保管人、进货时间、出货时间\n");
	input(&head);
	while(flag)
	{
		system("cls");
		menu();
		printf("请选择：(0-5)");
		getchar();
		choose=getchar();
		int q;
		switch(choose)
		{
		case'1':output(head);back();break;
		case'2':binsearch(head);back();break;
		case'3':insert(&head);output(head);back();break;
		case'4':delet(&head);output(head);back();break;
		case'5':print(head);back();break;
		case'0':system("cls");
				printf("是否确定退出？(1:退出/2:不退出)\n");
				scanf("%d",&q);
				if(q==1)
				{
					flag=0;printf("\n      *** The End! ***\n");
					printf("\n 感谢你本次使用，欢迎下次登录\n");system("pause");break;
				}
				else
				{
					back();break;
				}
		default:printf("\n Wrong Selection(选择错误，请重选!)\n");
			back();
		}
	}
}
void menu()
{
	printf("\n            材料管理系统            \n");
	printf("\n                菜单                \n");
	printf("\n     1.  显示所有材料的信息         \n");
	printf("\n     2.  查找某编号材料信息         \n");
	printf("\n     3.   插入某材料的信息          \n");
	printf("\n     4.  删除某编号材料信息         \n");
	printf("\n     5.  将材料信息写入文件         \n");
	printf("\n     0.         退出                \n");
}
void back()
{
	float x;
	printf("\n");
	do{
		printf("按0返回菜单界面:");
		scanf("%f",&x);
	}while(x!=0);
}

void input(struct studcode **headp)
{

	struct studcode *p;
	while(1)
	{
		p=(struct studcode *)malloc(sizeof(struct studcode));
		printf("请输入编号(若想停止输入，请输入-1):");
		scanf("%d",&p->cl.No);
		if(p->cl.No==-1) break;
		printf("\n请输入材料名称:");
		scanf("%s",p->cl.name);
		printf("\n请输入材料单价:");
		scanf("%f",&p->cl.price);
		printf("\n请输入入库数量:");
		scanf("%d",&p->cl.input);
		printf("\n请输入库存数量:");
		scanf("%d",&p->cl.put);
		printf("\n请输入出库数量:");
		scanf("%d",&p->cl.output);
		printf("\n请输入保管人姓名:");
		scanf("%s",p->cl.people);
		printf("\n请输入进货时间:");
		scanf("%d %d %d",&p->cl.intime1,&p->cl.intime2,&p->cl.intime3);
		printf("\n请输入出货时间:");
		scanf("%d %d %d",&p->cl.outtime1,&p->cl.outtime2,&p->cl.outtime3);
		p->next=*headp;
		*headp=p;
		
	}
}
void output(struct studcode *head)
{
	system("cls");
	struct studcode *p;
	p=head;
	printf("编号   名称   单价   入库数量   库存数量   出库数量   保管人   进库时间      出库时间\n");
	while(p!=NULL)
	{
		printf("%ld       %s      %.2f     %d          %d          %d         %s      %d.%d.%d      %d.%d.%d\n",p->cl.No,p->cl.name,p->cl.price,p->cl.input,p->cl.put,p->cl.output,p->cl.people,p->cl.intime1,p->cl.intime2,p->cl.intime3,p->cl.outtime1,p->cl.outtime2,p->cl.outtime3);
		p=p->next;
	}
	printf("\n");
}
void binsearch(struct studcode *head)
{
	system("cls");
	struct studcode *p;
	int k=1;
	long x;
	p=head;
	printf("请输入需要查找的材料的编号：");
	scanf("%ld",&x);
	printf("\n");
	while(p!=NULL)
	{
		if(p->cl.No==x)
		{
			printf("该材料信息如下： \n");
			printf("编号   名称   单价   入库数量   库存数量   出库数量   保管人   进库时间      出库时间\n");
			printf("%ld       %s      %.2f     %d          %d          %d         %s      %d.%d.%d      %d.%d.%d\n",p->cl.No,p->cl.name,p->cl.price,p->cl.input,p->cl.put,p->cl.output,p->cl.people,p->cl.intime1,p->cl.intime2,p->cl.intime3,p->cl.outtime1,p->cl.outtime2,p->cl.outtime3);
			k=0;
			break;
		}
		p=p->next;
	}
	if(k) printf("没有此材料的信息 \n");
}
void insert(struct studcode **headp)
{
	system("cls");
	struct studcode *p;
	p=(struct studcode *)malloc(sizeof(struct studcode));
	printf("请输入你想插入的材料的信息\n");
	    printf("请输入编号:");
		scanf("%d",&p->cl.No);
		printf("\n请输入材料名称:");
		scanf("%s",p->cl.name);
		printf("\n请输入材料单价:");
		scanf("%f",&p->cl.price);
		printf("\n请输入入库数量:");
		scanf("%d",&p->cl.input);
		printf("\n请输入库存数量:");
		scanf("%d",&p->cl.put);
		printf("\n请输入出库数量:");
		scanf("%d",&p->cl.output);
		printf("\n请输入保管人姓名:");
		scanf("%s",p->cl.people);
		printf("\n请输入进货时间:");
		scanf("%d%d%d",&p->cl.intime1,&p->cl.intime2,&p->cl.intime3);
		printf("\n请输入出货时间:");
		scanf("%d%d%d",&p->cl.outtime1,&p->cl.outtime2,&p->cl.outtime3);
	p->next=*headp;
	*headp=p;
	printf("*****插入成功*****\n");
}
void delet(struct studcode **headp)
{
	system("cls");
	struct studcode *p,*last;
	long x;
	p=*headp;
	printf("请输入你要删除的材料的编号：");
	scanf("%ld",&x);
	int m;
	while(p->cl.No!=x&&p->next!=NULL)
	{
		last=p;
		p=p->next;
	}
	if(p->cl.No==x)
	{
		printf("编号   名称   单价   入库数量   库存数量   出库数量   保管人   进库时间      出库时间\n");
		printf("%ld       %s      %.2f     %d          %d          %d         %s      %d.%d.%d      %d.%d.%d\n",p->cl.No,p->cl.name,p->cl.price,p->cl.input,p->cl.put,p->cl.output,p->cl.people,p->cl.intime1,p->cl.intime2,p->cl.intime3,p->cl.outtime1,p->cl.outtime2,p->cl.outtime3);
		printf("是否确认删除？（1：删除/0：不删除）\n");
		scanf("%d",&m);
		if(m==1)
		{

			if(p==*headp)
				*headp=p->next;
			else
				last->next=p->next;
			free(p);
			printf("\n***删除成功***\n");
		}
		else
		{
			system("pause");
		}
	}
	else
	{
		printf("\n***删除失败，无该材料信息***\n");
	}
}
void print(struct studcode *head)
{
	FILE *print=fopen("print.txt","w+");
	for(struct studcode* dp=head;dp;dp=dp->next)
	{
		fprintf(print,"编号：%ld 名称：%s单价：%.2f 入库数量：%ld 库存：%ld 出库数量：%ld 保管人：%s入库时间：%ld.%ld.%ld 出库时间：%ld.%ld.%ld\n",dp->cl.No,dp->cl.name,dp->cl.price,dp->cl.input,dp->cl.put,dp->cl.output,dp->cl.people,dp->cl.intime1,dp->cl.intime2,dp->cl.intime3,dp->cl.outtime1,dp->cl.outtime2,dp->cl.outtime3);
	}
	fclose(print);
	printf("成功导入!");
	system("pause");
}