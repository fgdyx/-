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
	printf("��ӭʹ�ò��Ϲ���ϵͳ\n");
	printf("\n����¼����ϻ�����Ϣ\n");
	system("pause");
	printf("�����š����ơ����ۡ����������������������������������ˡ�����ʱ�䡢����ʱ��\n");
	input(&head);
	while(flag)
	{
		system("cls");
		menu();
		printf("��ѡ��(0-5)");
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
				printf("�Ƿ�ȷ���˳���(1:�˳�/2:���˳�)\n");
				scanf("%d",&q);
				if(q==1)
				{
					flag=0;printf("\n      *** The End! ***\n");
					printf("\n ��л�㱾��ʹ�ã���ӭ�´ε�¼\n");system("pause");break;
				}
				else
				{
					back();break;
				}
		default:printf("\n Wrong Selection(ѡ���������ѡ!)\n");
			back();
		}
	}
}
void menu()
{
	printf("\n            ���Ϲ���ϵͳ            \n");
	printf("\n                �˵�                \n");
	printf("\n     1.  ��ʾ���в��ϵ���Ϣ         \n");
	printf("\n     2.  ����ĳ��Ų�����Ϣ         \n");
	printf("\n     3.   ����ĳ���ϵ���Ϣ          \n");
	printf("\n     4.  ɾ��ĳ��Ų�����Ϣ         \n");
	printf("\n     5.  ��������Ϣд���ļ�         \n");
	printf("\n     0.         �˳�                \n");
}
void back()
{
	float x;
	printf("\n");
	do{
		printf("��0���ز˵�����:");
		scanf("%f",&x);
	}while(x!=0);
}

void input(struct studcode **headp)
{

	struct studcode *p;
	while(1)
	{
		p=(struct studcode *)malloc(sizeof(struct studcode));
		printf("��������(����ֹͣ���룬������-1):");
		scanf("%d",&p->cl.No);
		if(p->cl.No==-1) break;
		printf("\n�������������:");
		scanf("%s",p->cl.name);
		printf("\n��������ϵ���:");
		scanf("%f",&p->cl.price);
		printf("\n�������������:");
		scanf("%d",&p->cl.input);
		printf("\n������������:");
		scanf("%d",&p->cl.put);
		printf("\n�������������:");
		scanf("%d",&p->cl.output);
		printf("\n�����뱣��������:");
		scanf("%s",p->cl.people);
		printf("\n���������ʱ��:");
		scanf("%d %d %d",&p->cl.intime1,&p->cl.intime2,&p->cl.intime3);
		printf("\n���������ʱ��:");
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
	printf("���   ����   ����   �������   �������   ��������   ������   ����ʱ��      ����ʱ��\n");
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
	printf("��������Ҫ���ҵĲ��ϵı�ţ�");
	scanf("%ld",&x);
	printf("\n");
	while(p!=NULL)
	{
		if(p->cl.No==x)
		{
			printf("�ò�����Ϣ���£� \n");
			printf("���   ����   ����   �������   �������   ��������   ������   ����ʱ��      ����ʱ��\n");
			printf("%ld       %s      %.2f     %d          %d          %d         %s      %d.%d.%d      %d.%d.%d\n",p->cl.No,p->cl.name,p->cl.price,p->cl.input,p->cl.put,p->cl.output,p->cl.people,p->cl.intime1,p->cl.intime2,p->cl.intime3,p->cl.outtime1,p->cl.outtime2,p->cl.outtime3);
			k=0;
			break;
		}
		p=p->next;
	}
	if(k) printf("û�д˲��ϵ���Ϣ \n");
}
void insert(struct studcode **headp)
{
	system("cls");
	struct studcode *p;
	p=(struct studcode *)malloc(sizeof(struct studcode));
	printf("�������������Ĳ��ϵ���Ϣ\n");
	    printf("��������:");
		scanf("%d",&p->cl.No);
		printf("\n�������������:");
		scanf("%s",p->cl.name);
		printf("\n��������ϵ���:");
		scanf("%f",&p->cl.price);
		printf("\n�������������:");
		scanf("%d",&p->cl.input);
		printf("\n������������:");
		scanf("%d",&p->cl.put);
		printf("\n�������������:");
		scanf("%d",&p->cl.output);
		printf("\n�����뱣��������:");
		scanf("%s",p->cl.people);
		printf("\n���������ʱ��:");
		scanf("%d%d%d",&p->cl.intime1,&p->cl.intime2,&p->cl.intime3);
		printf("\n���������ʱ��:");
		scanf("%d%d%d",&p->cl.outtime1,&p->cl.outtime2,&p->cl.outtime3);
	p->next=*headp;
	*headp=p;
	printf("*****����ɹ�*****\n");
}
void delet(struct studcode **headp)
{
	system("cls");
	struct studcode *p,*last;
	long x;
	p=*headp;
	printf("��������Ҫɾ���Ĳ��ϵı�ţ�");
	scanf("%ld",&x);
	int m;
	while(p->cl.No!=x&&p->next!=NULL)
	{
		last=p;
		p=p->next;
	}
	if(p->cl.No==x)
	{
		printf("���   ����   ����   �������   �������   ��������   ������   ����ʱ��      ����ʱ��\n");
		printf("%ld       %s      %.2f     %d          %d          %d         %s      %d.%d.%d      %d.%d.%d\n",p->cl.No,p->cl.name,p->cl.price,p->cl.input,p->cl.put,p->cl.output,p->cl.people,p->cl.intime1,p->cl.intime2,p->cl.intime3,p->cl.outtime1,p->cl.outtime2,p->cl.outtime3);
		printf("�Ƿ�ȷ��ɾ������1��ɾ��/0����ɾ����\n");
		scanf("%d",&m);
		if(m==1)
		{

			if(p==*headp)
				*headp=p->next;
			else
				last->next=p->next;
			free(p);
			printf("\n***ɾ���ɹ�***\n");
		}
		else
		{
			system("pause");
		}
	}
	else
	{
		printf("\n***ɾ��ʧ�ܣ��޸ò�����Ϣ***\n");
	}
}
void print(struct studcode *head)
{
	FILE *print=fopen("print.txt","w+");
	for(struct studcode* dp=head;dp;dp=dp->next)
	{
		fprintf(print,"��ţ�%ld ���ƣ�%s���ۣ�%.2f ���������%ld ��棺%ld ����������%ld �����ˣ�%s���ʱ�䣺%ld.%ld.%ld ����ʱ�䣺%ld.%ld.%ld\n",dp->cl.No,dp->cl.name,dp->cl.price,dp->cl.input,dp->cl.put,dp->cl.output,dp->cl.people,dp->cl.intime1,dp->cl.intime2,dp->cl.intime3,dp->cl.outtime1,dp->cl.outtime2,dp->cl.outtime3);
	}
	fclose(print);
	printf("�ɹ�����!");
	system("pause");
}