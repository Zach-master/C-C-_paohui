#include<stdio.h>
#include<string.h>
#include<stdlib.h>//��ͣ����
typedef struct {
    char na[20],gender[20],spe[20],cla[20],jy[20],bz[20];
    int xh,age;
} student;

typedef struct LNode {
	student date ;
	struct LNode *next;
} LNode, *Linklist;

void PrintList (Linklist L) {
    Linklist p;
    p=L;
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~��ҵ����ҵ�����~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("ѧ�� ����  �Ա�    ����\t �༶\t  \tרҵ\t\t��ҵ���\t ��ע\n");
    while ( p->next )
    {
    	printf("%d  %s  %s \t    %d\t%s  %16s  \t  %s  \t%s\n",p->next->date.xh,p->next->date.na,p->next->date.gender,p->next->date.age,p->next->date.cla,p->next->date.spe,p->next->date.jy,p->next->date.bz);
    	p = p -> next;
    }
    printf("\n");
}

void shanchu( Linklist L )
 {
    int i,j=0,q=5;
    Linklist p, r;
    p = L;
    printf("����Ҫɾ����Ϣ��ѧ����ѧ�ţ�(5������)\n");
    scanf("%d", &i);
    if(q==i)
    {
        return ;
    }
    while(p->next)
    {
        if(p->next->date.xh==i)
        {
           r = p->next;
           p->next=r->next;
           free(r);
           j=1;
        }
        p = p -> next;
    }
    if(j==0)
    {
        printf("��ѧ�Ų����ڣ�\n");
    }
    else
    printf("��ҵ����Ϣ��ɾ����\n");
}

void Openfile ( Linklist L )
{
    char na[20],gender[20],spe[20],cla[20],jy[20],bz[20];
    int xh,age;
    Linklist p, newn;
    p = L;   
    FILE *r;
    if ( ( r = fopen ("graduate.txt", "r" ) ) == NULL ) {
		printf("can't open the file!!!\n");
		return ;
    }
    while ( fscanf ( r, "%d %s %s %d %s %s %s %s",&xh,na,gender,&age,cla,spe,jy,bz) != EOF ) {
		newn = ( LNode * ) malloc ( sizeof ( LNode ) );
		newn -> date.xh = xh ;
        strcpy ( newn -> date.na, na );
        strcpy ( newn -> date.gender, gender );
        newn -> date.age = age;
        strcpy ( newn -> date.spe, spe );
        strcpy ( newn -> date.cla, cla );
        strcpy ( newn -> date.jy, jy );
        strcpy ( newn -> date.bz, bz );
		newn->next=NULL;    
		p->next=newn;       
		p=newn;       
    }
    fclose(r);
}

void zengjia(Linklist L )
{
    int q=5,i;
    Linklist p,newn;
    student s;
    p=L;
    printf("========================����Ҫ����ı�ҵ����Ϣ========================\n");
    printf("*****ѧ��:");	scanf("%d",&s.xh);
    printf("*****����:");	scanf("%s",s.na);
	printf("*****�Ա�:");	scanf("%s",s.gender);
    printf("*****����:");	scanf("%d",&s.age);
    printf("*****�༶:");	scanf("%s",s.cla);
    printf("*****רҵ:");	scanf("%s",s.spe);
    printf("*****��ҵ״��:");	scanf("%s",s.jy);
    printf("*****��ע:");	scanf("%s",s.bz);
	printf("�������\n\n");
    newn=(LNode*)malloc(sizeof(LNode));
    newn->date= s ;
    newn->next=p->next;
    p->next=newn;
}

void chaxun(Linklist L){
    int s,j=0,q=5;
    printf("������Ҫ���ҵ�ѧ����ѧ�ţ�(5������)\n");
    scanf("%d",&s);       
    if(q==s)
    {
        return ;
    }
    Linklist p;
    p=L->next;
    while(p)
	{
		if(p->date.xh==s)
        {
            j=1;
            printf("����ѧ��Ϊ:%d\n����Ϊ:%s\n�Ա�Ϊ:%s\n����:%d\n�༶:%s\nרҵ:%s\n��ҵ״��:%s\n��ע:%s\n",p->date.xh,p->date.na,p->date.gender,p->date.age,p->date.cla,p->date.spe,p->date.jy,p->date.bz);
        }
		p=p->next;
	}
	if(j==0)
    {
        printf("��ѧ�Ų����ڣ�");
    }
}

void xiugai(Linklist L)
{
    int x,choice,x2,j=0,q=5;
    char n[20];
    Linklist p;
    p=L->next;
    printf("������Ҫ�޸���Ϣ��ѧ����ѧ�ţ�(5������)");
    scanf("%d",&x);
    if(q==x)
    {
        return ;
    }
    while(p)
	{
		if(p->date.xh==x)
        {
            j=1;
            printf("1.�޸�ѧ��---2.�޸�����---3.�޸��Ա�---4.����---5.�޸İ༶---6.�޸�רҵ---7.�޸ľ�ҵ״��---8.�޸ı�ע---0.�˳�\n");
            printf("��ѡ��");
            scanf("%d",&choice);
            switch(choice)
            {
                case 0:break;
                case 1:printf("�������޸ĺ��ѧ�ţ�");scanf("%d",&x);p->date.xh=x;printf("�޸���ɡ�\n");break;
                case 2:printf("�������޸ĺ��������");scanf("%s",n);strcpy(p->date.na,n);printf("�޸���ɡ�\n");break;
                case 3:printf("�������޸ĺ���Ա�");scanf("%s",n);strcpy(p->date.gender,n);printf("�޸���ɡ�\n");break;
                case 4:printf("�������޸ĺ�����䣺");scanf("%d",&x);p->date.age=x;printf("�޸���ɡ�\n");break;
                case 5:printf("�������޸ĺ�İ༶��");scanf("%s",n);strcpy(p->date.cla,n);printf("�޸���ɡ�\n");break;
                case 6:printf("�������޸ĺ��רҵ��");scanf("%s",n);strcpy(p->date.spe,n);printf("�޸���ɡ�\n");break;
                case 7:printf("�������޸ĺ�ľ�ҵ״����");scanf("%s",n);strcpy(p->date.jy,n);printf("�޸���ɡ�\n");break;
                case 8:printf("�������޸ĺ�ı�ע��");scanf("%s",n);strcpy(p->date.bz,n);;printf("�޸���ɡ�\n");break;
            }
        }
		p=p->next;

    }
    if(j==0)
    {
        printf("��ѧ�Ų����ڣ�\n");
    }
}

void jiangxu(Linklist B)
{
    Linklist tail = NULL;
    while (tail != B->next)
    {
        Linklist pre = B;
        Linklist cur = pre->next;
        while (cur != tail && cur->next != tail)
        {
            if (cur->date.xh< cur->next->date.xh)
            {
                pre->next = cur->next;
                cur->next = cur->next->next;
                pre->next->next = cur;
            }
            pre = pre->next;
            cur = pre->next;
        }
        tail = cur;
    }
    PrintList(B);
}

void save(Linklist L)
{
    Linklist p;
    p=L->next;
    FILE *fp;
    fp = fopen("graduate.txt", "w");
    while (p)
    {
     fprintf(fp, "%d %s %s %d %s %s %s %s\n", p->date.xh, p->date.na, p->date.gender,p->date.age,p->date.cla,p->date.spe,p->date.jy,p->date.bz);
     p = p->next;
    }
    fprintf(fp, "\r\n");
    fclose(fp);
}

int main()
{
    int xuanze,jx=0;
    Linklist L,B;
	L = ( Linklist ) malloc ( sizeof (LNode) );
    B = ( Linklist ) malloc ( sizeof (LNode) );
	L -> next = NULL;
    B -> next = NULL;
    Openfile(B);
    Openfile(L);
	printf("`~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~��ҵ����ҵ�������ϵͳ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`\n");
	while(1)
    {
        printf("1-��ҵ����Ϣ����||2-��ҵ����Ϣ��ѯ||3-��ҵ����Ϣ����||4-��ҵ����Ϣ����||5-��ҵ����Ϣɾ��||6-�����ҵ����Ϣ||7-����||8-�˳�ϵͳ\n");
	    printf("��ѡ��: ");
	    scanf("%d",&xuanze);
	    switch(xuanze)
	    {
          case 1:jiangxu(B);system("pause");break;
	      case 2:chaxun(L);system("pause");break;
          case 3:xiugai(L);system("pause");break;
          case 4:zengjia(L);system("pause");break;
          case 5:shanchu(L);system("pause");break;
          case 6:PrintList(L);system("pause");break;
          case 7:save(L);printf("����ɹ�!\n");system("pause");break;
          case 8:jx=1;break;
	    }
	    if(jx==1){
         save(L);
         printf("�ټ�!");
         system("pause");
         break;
        }
    }
	return 0;
}







