#include<stdio.h>
#include<string.h>
#include<stdlib.h>//暂停函数
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
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~毕业生就业情况表~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("学号 姓名  性别    年龄\t 班级\t  \t专业\t\t就业情况\t 备注\n");
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
    printf("输入要删除信息的学生的学号：(5键返回)\n");
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
        printf("该学号不存在！\n");
    }
    else
    printf("毕业生信息已删除。\n");
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
    printf("========================输入要插入的毕业生信息========================\n");
    printf("*****学号:");	scanf("%d",&s.xh);
    printf("*****姓名:");	scanf("%s",s.na);
	printf("*****性别:");	scanf("%s",s.gender);
    printf("*****年龄:");	scanf("%d",&s.age);
    printf("*****班级:");	scanf("%s",s.cla);
    printf("*****专业:");	scanf("%s",s.spe);
    printf("*****就业状况:");	scanf("%s",s.jy);
    printf("*****备注:");	scanf("%s",s.bz);
	printf("输入完成\n\n");
    newn=(LNode*)malloc(sizeof(LNode));
    newn->date= s ;
    newn->next=p->next;
    p->next=newn;
}

void chaxun(Linklist L){
    int s,j=0,q=5;
    printf("请输入要查找的学生的学号：(5键返回)\n");
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
            printf("该生学号为:%d\n姓名为:%s\n性别为:%s\n年龄:%d\n班级:%s\n专业:%s\n就业状况:%s\n备注:%s\n",p->date.xh,p->date.na,p->date.gender,p->date.age,p->date.cla,p->date.spe,p->date.jy,p->date.bz);
        }
		p=p->next;
	}
	if(j==0)
    {
        printf("该学号不存在！");
    }
}

void xiugai(Linklist L)
{
    int x,choice,x2,j=0,q=5;
    char n[20];
    Linklist p;
    p=L->next;
    printf("请输入要修改信息的学生的学号：(5键返回)");
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
            printf("1.修改学号---2.修改姓名---3.修改性别---4.年龄---5.修改班级---6.修改专业---7.修改就业状况---8.修改备注---0.退出\n");
            printf("请选择：");
            scanf("%d",&choice);
            switch(choice)
            {
                case 0:break;
                case 1:printf("请输入修改后的学号：");scanf("%d",&x);p->date.xh=x;printf("修改完成。\n");break;
                case 2:printf("请输入修改后的姓名：");scanf("%s",n);strcpy(p->date.na,n);printf("修改完成。\n");break;
                case 3:printf("请输入修改后的性别：");scanf("%s",n);strcpy(p->date.gender,n);printf("修改完成。\n");break;
                case 4:printf("请输入修改后的年龄：");scanf("%d",&x);p->date.age=x;printf("修改完成。\n");break;
                case 5:printf("请输入修改后的班级：");scanf("%s",n);strcpy(p->date.cla,n);printf("修改完成。\n");break;
                case 6:printf("请输入修改后的专业：");scanf("%s",n);strcpy(p->date.spe,n);printf("修改完成。\n");break;
                case 7:printf("请输入修改后的就业状况：");scanf("%s",n);strcpy(p->date.jy,n);printf("修改完成。\n");break;
                case 8:printf("请输入修改后的备注：");scanf("%s",n);strcpy(p->date.bz,n);;printf("修改完成。\n");break;
            }
        }
		p=p->next;

    }
    if(j==0)
    {
        printf("该学号不存在！\n");
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
	printf("`~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~毕业生就业情况管理系统~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`\n");
	while(1)
    {
        printf("1-毕业生信息排序||2-毕业生信息查询||3-毕业生信息更新||4-毕业生信息插入||5-毕业生信息删除||6-浏览毕业生信息||7-保存||8-退出系统\n");
	    printf("请选择: ");
	    scanf("%d",&xuanze);
	    switch(xuanze)
	    {
          case 1:jiangxu(B);system("pause");break;
	      case 2:chaxun(L);system("pause");break;
          case 3:xiugai(L);system("pause");break;
          case 4:zengjia(L);system("pause");break;
          case 5:shanchu(L);system("pause");break;
          case 6:PrintList(L);system("pause");break;
          case 7:save(L);printf("保存成功!\n");system("pause");break;
          case 8:jx=1;break;
	    }
	    if(jx==1){
         save(L);
         printf("再见!");
         system("pause");
         break;
        }
    }
	return 0;
}







