//函数定义
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sys.h"
//系统操作函数 
void Adminmenu(Stu *p_head)  //管理员菜单显示函数 
{
	printf("(权限:管理员)请输入你要进行的操作\nA:输出所有学生信息 B:查找学生 C:删除学生:"); 
	Admininput(p_head);
} 

void Admininput(Stu *p_head)   //管理员菜单输入函数
{   char choice[20];
	scanf("%s",choice);
    while(choice[20]!='\0')
    {   printf("提示：字符串长度过长");
        while(getchar()!='\n');
    	scanf("%s",choice);
	}
	if(strcmp(choice,"A")==0)
	{
		Display(p_head);
	}
	else if(strcmp(choice,"B")==0)
	{   char name[50]; 
	    printf("请输入你要查找学生姓名:");
	    scanf("%s",name);
	    if(scanf("%s",name)!=1)
		{
		printf("提示：读入姓名失败\n");
		while(getchar()!='\n');
	    }
	    if(strlen(name)<=50) 
	    {
		Search(p_head,name);
		}
		else
		{
		printf("提示：你输入的学生姓名过长");
		while(getchar()!='\n');
		} 
		
	}
	else if(strcmp(choice,"C")==0)
	{   int n_ID ;
	    printf("请输入你要删除的学生的编号:");
	    if(scanf("%d",&n_ID)!=1)
		{
		printf("提示：你没有输入正确编号或者编号数据过大导致溢出\n");
		while(getchar()!='\n');
	    }
		else 
		{
		Del(p_head,n_ID);
	    }
	}
	else
	{
		printf("没有这个操作，请重新选择\n"); 
	}
} 




//功能函数 
void Display(Stu *p_head)   //遍历并输出链表,传入头指针 
{   
    int i = 1;
	Stu *p_temp = NextItem(p_head);
	while(p_temp)
	{   
		printf("|编号:%d ",p_temp->m_nSign);
		printf("|姓名:%s ",p_temp->m_strName);
		printf("|班级:%s\n ",p_temp->m_strClass);
		printf("|数学成绩:%s 院系名次:%d 班级名次:%d\n",p_temp->m_nMath,Sort(p_head,i,1),ClassSort(p_head,i,1));
		printf("|语文成绩:%s 院系名次:%d 班级名次:%d\n",p_temp->m_nChinese,Sort(p_head,i,2),ClassSort(p_head,i,2));
		printf("|英语成绩:%s 院系名次:%d 班级名次:%d\n",p_temp->m_nEnglish,Sort(p_head,i,3),ClassSort(p_head,i,3));
		printf("|专业成绩:%s 院系名次:%d 班级名次:%d\n",p_temp->m_nComputer,Sort(p_head,i,4),ClassSort(p_head,i,4));
		printf("|总成绩:%d   院系名次:%d 班级名次:%d\n\n",Strtoint(p_temp->m_nComputer)+Strtoint(p_temp->m_nEnglish)+Strtoint(+p_temp->m_nChinese)+Strtoint(p_temp->m_nMath),Sort(p_head,i,5),ClassSort(p_head,i,5));
		i=i+1;
	    p_temp=NextItem(p_temp);
	}
}

void InitSys(Stu *p_head)      //初始化学生系统后，管理员输入数据层 
{       Stu *p_temp = NextItem(p_head);
        while(p_temp)
        {
		printf("输入学生信息(编号:%d):\n",p_temp->m_nSign);   //对结点写入数据
		printf("姓名(编号:%d):",p_temp->m_nSign);
		scanf("%s",p_temp->m_strName);
		printf("班级(编号:%d):",p_temp->m_nSign);
		scanf("%s",p_temp->m_strClass);
		printf("数学成绩(编号:%d):",p_temp->m_nSign);
		scanf("%s",p_temp->m_nMath);
		while(Strtoint(p_temp->m_nMath) == -1)
		{   
			printf("提示:您的输入有问题(成绩为0-100的整数),请重新输入:"); 
			scanf("%s",p_temp->m_nMath);
		}
		printf("语文成绩(编号:%d):",p_temp->m_nSign);
		scanf("%s",p_temp->m_nChinese);
		while(Strtoint(p_temp->m_nChinese) == -1)
		{   
			printf("提示:您的输入有问题(成绩为0-100的整数),请重新输入:");
			scanf("%s",p_temp->m_nChinese);
		}
		printf("英语成绩(编号:%d):",p_temp->m_nSign);
		scanf("%s",p_temp->m_nEnglish);
		while(Strtoint(p_temp->m_nEnglish) == -1)
		{   
			printf("提示:您的输入有问题(成绩为0-100的整数),请重新输入:");
			scanf("%s",p_temp->m_nEnglish);
		}
		printf("专业成绩(编号:%d):",p_temp->m_nSign);
		scanf("%s",p_temp->m_nComputer);
		while(Strtoint(p_temp->m_nComputer) == -1)
		{   
			printf("提示:您的输入有问题(成绩为0-100的整数),请重新输入:");
			scanf("%s",p_temp->m_nComputer);
		}
        p_temp = NextItem(p_temp);
        }
} 


int Pow(int num,int n) //传入数字，返回其n次方 
{ if(n == 1)
  return num;
  else
  return num*Pow(num,n-1);
} 


int Strtoint(char *str)    //传入0-100的字符串返回整型函数，若传入其他字符串，则返回-1
{
   int sum = 0;
   while(*str!='\0')
   {
   	sum = 10*sum + *str - '0';
   	str++;
   }
   if(sum >= 0 && sum <= 100)
   return sum;
   else
   return -1;
} 

void Search(Stu *p_head,char *name)     //搜索学生信息，传入头指针，传入学生姓名 
{   Stu *p_temp = NextItem(p_head);
    int i = 1;
    int sign=0;
    while(p_temp)
    {
	if(strcmp(name,p_temp->m_strName)==0)
	{   sign=1;
		printf("|编号:%d ",p_temp->m_nSign);
		printf("|姓名:%s ",p_temp->m_strName);
		printf("|班级:%s\n ",p_temp->m_strClass);
		printf("|数学成绩:%s 院系名次:%d 班级名次:%d\n",p_temp->m_nMath,Sort(p_head,i,1),ClassSort(p_head,i,1));
		printf("|语文成绩:%s 院系名次:%d 班级名次:%d\n",p_temp->m_nChinese,Sort(p_head,i,2),ClassSort(p_head,i,2));
		printf("|英语成绩:%s 院系名次:%d 班级名次:%d\n",p_temp->m_nEnglish,Sort(p_head,i,3),ClassSort(p_head,i,3));
		printf("|专业成绩:%s 院系名次:%d 班级名次:%d\n",p_temp->m_nComputer,Sort(p_head,i,4),ClassSort(p_head,i,4));
		printf("|总成绩:%d   院系名次:%d 班级名次:%d\n\n",Strtoint(p_temp->m_nComputer)+Strtoint(p_temp->m_nEnglish)+Strtoint(+p_temp->m_nChinese)+Strtoint(p_temp->m_nMath),Sort(p_head,i,5),ClassSort(p_head,i,5));
	}
	p_temp = NextItem(p_temp);
	i=i+1;
	}
	if(sign == 0)
	{
		printf("提示：无此学生\n");
	}
	
}


void Del(Stu *p_head,int n_ID)    //删除表，传入头指针，传入删除学生编号 
{   if(SearchItem(n_ID,p_head)==NULL)
    {
    	printf("提示：没有这个编号\n");
	}
	else
	{
	free(SearchItem(n_ID,p_head));  //释放内存空间 
    Stu *p_temp1=SearchItem(n_ID-1,p_head);   //删除结点前后关联 
    Stu *p_temp2=SearchItem(n_ID+1,p_head);  
    p_temp1->m_pNext = p_temp2;
    while(p_temp2)
    {
    	p_temp2->m_nSign = (p_temp2->m_nSign)-1;
    	p_temp2 = p_temp2->m_pNext;
	}    	
	printf("提示：删除成功\n");
    }
}


int Sort(Stu *p_head,int n_ID,int n_subject)   //院系总排名，传入头指针、学生编号、所要排名的数据类型 
{
    Stu *p_thisStudent=SearchItem(n_ID,p_head);
    int num;
	int i = 1;
	int sum = 1;
    if(n_subject == 1)   //用Search()函数对每一个结点该编号数据值进行检索，遇到比被排序结点数值大时sum+1
    {
    	num = Strtoint(p_thisStudent->m_nMath);
    	while(SearchItem(i,p_head))
    	{
    	if(num < Strtoint(SearchItem(i,p_head)->m_nMath))
		{
		sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
	if(n_subject == 2)
	{
		num = Strtoint(p_thisStudent->m_nChinese);
    	while(SearchItem(i,p_head))
    	{
    	if(num < Strtoint(SearchItem(i,p_head)->m_nChinese))
		{
		sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
	if(n_subject == 3)
	{
		num = Strtoint(p_thisStudent->m_nEnglish);
    	while(SearchItem(i,p_head))
    	{
    	if(num < Strtoint(SearchItem(i,p_head)->m_nEnglish))
		{
		sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
	if(n_subject == 4)
	{
		num = Strtoint(p_thisStudent->m_nComputer);
    	while(SearchItem(i,p_head))
    	{
    	if(num < Strtoint(SearchItem(i,p_head)->m_nComputer))
		{
		sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
	if(n_subject == 5)
	{
		num = Strtoint(p_thisStudent->m_nComputer)+Strtoint(p_thisStudent->m_nEnglish)+Strtoint(p_thisStudent->m_nChinese)+Strtoint(p_thisStudent->m_nMath);
    	while(SearchItem(i,p_head))
    	{
    	int n_sumScore = Strtoint(SearchItem(i,p_head)->m_nComputer)+Strtoint(SearchItem(i,p_head)->m_nEnglish)+Strtoint(SearchItem(i,p_head)->m_nChinese)+Strtoint(SearchItem(i,p_head)->m_nMath);
    	if(num < n_sumScore)
		{
		sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
 } 
 
 int ClassSort(Stu *p_head,int n_ID,int n_subject)   //班级排名，传入头指针、学生编号、所要排名的数据类型 
{
    Stu *p_thisStudent=SearchItem(n_ID,p_head);
    int num;
	int i = 1;
	int sum = 1;
    if(n_subject == 1)   //用Search()函数对每一个结点该编号数据值进行检索，遇到比被排序结点数值大时sum+1
    {
    	num = Strtoint(p_thisStudent->m_nMath);
    	while(SearchItem(i,p_head))
    	{
    	if(num < Strtoint(SearchItem(i,p_head)->m_nMath) && strcmp(p_thisStudent->m_strClass,SearchItem(i,p_head)->m_strClass) == 0)
		{
		sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
	if(n_subject == 2)
	{
		num = Strtoint(p_thisStudent->m_nChinese);
    	while(SearchItem(i,p_head))
    	{
    	if(num < Strtoint(SearchItem(i,p_head)->m_nChinese) && strcmp(p_thisStudent->m_strClass,SearchItem(i,p_head)->m_strClass) == 0)
		{
		sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
	if(n_subject == 3)
	{
		num = Strtoint(p_thisStudent->m_nEnglish);
    	while(SearchItem(i,p_head))
    	{
    	if(num < Strtoint(SearchItem(i,p_head)->m_nEnglish) && strcmp(p_thisStudent->m_strClass,SearchItem(i,p_head)->m_strClass) == 0)
		{
		sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
	if(n_subject == 4)
	{
		num = Strtoint(p_thisStudent->m_nComputer);
    	while(SearchItem(i,p_head))
    	{
    	if(num < Strtoint(SearchItem(i,p_head)->m_nComputer) && strcmp(p_thisStudent->m_strClass,SearchItem(i,p_head)->m_strClass) == 0)
		{
		sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
	if(n_subject == 5)
	{
		num = Strtoint(p_thisStudent->m_nComputer)+Strtoint(p_thisStudent->m_nEnglish)+Strtoint(p_thisStudent->m_nChinese)+Strtoint(p_thisStudent->m_nMath);
    	while(SearchItem(i,p_head))
    	{
    	int n_sumScore = Strtoint(SearchItem(i,p_head)->m_nComputer)+Strtoint(SearchItem(i,p_head)->m_nEnglish)+Strtoint(SearchItem(i,p_head)->m_nChinese)+Strtoint(SearchItem(i,p_head)->m_nMath);
    	if(num < n_sumScore && strcmp(p_thisStudent->m_strClass,SearchItem(i,p_head)->m_strClass) == 0)
		{
		sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
 } 

/*
Stu *Search(int n_ID,Stu *p_head)
{   
     Stu *p_temp = p_head;
     while(p_temp->m_nSign != n_ID)   //n_ID=遍历到链表的ID
     {
	     p_temp = p_temp->m_pNext;
	     if(p_temp == NULL) 
	     {
	     	return NULL;
		 }
	 } 
	return p_temp;
}


int Sort(Stu *p_head,int n_ID,int n_subject)
{
    Stu *p_thisStudent=Search(n_ID,p_head);
    int num;
	int i = 1;
	int sum = 0;
    if(n_subject == 1)   //用Search()函数对每一个结点该编号数据值进行检索，遇到比被排序结点数值大时sum+1
    {
    	num = p_thisStudent->m_nMath;
    	while(Search(i,p_head))
    	{
    	if(num <= Search(i,p_head)->m_nMath)
		{
		sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
	if(n_subject == 2)
	{
		num = p_thisStudent->m_nChinese;
    	while(Search(i,p_head))
    	{
    	if(num <= Search(i,p_head)->m_nChinese)
		{
		sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
	if(n_subject == 3)
	{
		num = p_thisStudent->m_nEnglish;
    	while(Search(i,p_head))
    	{
    	if(num <= Search(i,p_head)->m_nEnglish)
		{
		sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
	if(n_subject == 4)
	{
		num = p_thisStudent->m_nComputer;
    	while(Search(i,p_head))
    	{
    	if(num <= Search(i,p_head)->m_nComputer)
		{
		sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
	if(n_subject == 5)
	{
		num = p_thisStudent->m_nComputer+p_thisStudent->m_nEnglish+p_thisStudent->m_nChinese+p_thisStudent->m_nMath;
    	while(Search(i,p_head))
    	{
    	int n_sumScore = Search(i,p_head)->m_nComputer+Search(i,p_head)->m_nEnglish+Search(i,p_head)->m_nChinese+Search(i,p_head)->m_nMath;
    	if(num <= n_sumScore)
		{
		sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
 } 
 
 
 
void NoPass(Stu *p_head)
{   if(p_head == NULL)
    {
    	printf("WRONG:未进行初始化表\n");
    	return;	 
    }
	int i = 1;
	Stu *p_temp = p_head->m_pNext;
	int sum = 0;
	while(p_temp)   //判断不及格 
	{
		if(p_temp->m_nMath < 60)
		{
			sum = sum+1;
		}
		if(p_temp->m_nEnglish < 60)
		{
			sum = sum+1;
		}
		if(p_temp->m_nChinese < 60)
		{
			sum = sum+1;
		}
		if(p_temp->m_nComputer < 60)
		{
			sum = sum+1;
		}
		if(sum >= 2)
		{
			printf("|编号:%d ",p_temp->m_nSign);
		    printf("|姓名:%s ",p_temp->m_strName);
		    printf("|班级:%s ",p_temp->m_strClass);
			printf("|数学成绩:%d 院系名次:%d 班级名次:%d\n",p_temp->m_nMath,Sort(p_head,i,1),ClassSort(p_head,i,1));
			printf("|语文成绩:%d 院系名次:%d 班级名次:%d\n",p_temp->m_nChinese,Sort(p_head,i,2),ClassSort(p_head,i,2));
			printf("|英语成绩:%d 院系名次:%d 班级名次:%d\n",p_temp->m_nEnglish,Sort(p_head,i,3),ClassSort(p_head,i,3));
			printf("|专业成绩:%d 院系名次:%d 班级名次:%d\n",p_temp->m_nComputer,Sort(p_head,i,4),ClassSort(p_head,i,4));
			printf("|总成绩:%d   院系名次:%d 班级名次:%d\n\n",p_temp->m_nComputer+p_temp->m_nEnglish+p_temp->m_nChinese+p_temp->m_nMath,Sort(p_head,i,5),ClassSort(p_head,i,5));
		}
		i=i+1;
		p_temp=p_temp->m_pNext;
		sum=0;
	}
}

Stu *Itzlink(int n_num) 
{   
    int n_id;
    Stu *p_head = NULL;//头指针 
    Stu *p_init = (Stu *)malloc(sizeof(Stu));//初始化头结点 
    if(p_init == NULL)
    {
    	printf("空间分配失败\n");
    	exit(-1);	 
    }
	Stu *p_temp = (Stu *)malloc(sizeof(Stu));//临时结点 
	if(p_temp == NULL)
    {
    	printf("空间分配失败\n");
    	exit(-1);	 
    }
	p_head=p_init;
	p_init->m_pNext = p_temp;
	p_temp->m_pNext = NULL;
	p_init->m_nSign = 0;  //创建临时结点,头指针指向头结点，头结点next指针指向临时结点，临时结点指向NULL
	for(n_id = 1;n_id <= n_num;n_id++)
	{
		
		printf("输入学生信息(编号:%d):\n",n_id);   //对临时结点写入数据
		printf("姓名(编号:%d):",n_id);
		scanf("%s",p_temp->m_strName);
		printf("班级(编号:%d):",n_id);
		scanf("%s",p_temp->m_strClass);
		printf("数学成绩(编号:%d):",n_id);
		scanf("%d",&p_temp->m_nMath);
		printf("语文成绩(编号:%d):",n_id);
		scanf("%d",&p_temp->m_nChinese);
		printf("英语成绩(编号:%d):",n_id);
		scanf("%d",&p_temp->m_nEnglish);
		printf("专业成绩(编号:%d):",n_id);
		scanf("%d",&p_temp->m_nComputer);
		p_temp->m_nSign=n_id;
		if(n_id < n_num)
		{
		Stu *p_new = (Stu *)malloc(sizeof(Stu));  //创建一个新的结点指向NULL，并将临时结点next指针指向新结点，临时结点指向新结点
			if(p_new == NULL)
        	{
    			printf("空间分配失败\n");
    			exit(-1);	 
        	}
		p_new->m_pNext = NULL;
		p_temp->m_pNext = p_new;
		p_temp=p_new;
	    }
	}
    return p_head;
}


void Fprint(Stu *p_head)
{   if(p_head == NULL)
    {
    	printf("WRONG:未进行初始化表\n");
    	exit(-1);	 
    }
    char Str[256];
    int i = 1; 
    Stu *p_temp = p_head->m_pNext; 
    FILE *fp;
    fp = fopen("File.txt", "w");    //以可读打开文件 
    if (fp == NULL)
    {
    printf("cannot open file\n");
    exit(-1);
    }
    while(p_temp)  //写入文件 
	{   
	    sprintf(Str,"|编号:%d",p_temp->m_nSign);
		fputs(Str,fp );
		fputs("|姓名:",fp );
		fputs(p_temp->m_strName,fp );
		fputs("|班级:",fp );
		fputs(p_temp->m_strClass,fp );
		sprintf(Str,"|数学成绩:%d",p_temp->m_nMath);
		fputs(Str,fp );
		sprintf(Str,"|院系排名:%d",Sort(p_head,i,1));
		fputs(Str,fp );
		sprintf(Str,"|班级排名:%d",ClassSort(p_head,i,1));
		fputs(Str,fp );
		sprintf(Str,"|语文成绩:%d",p_temp->m_nChinese);
		fputs(Str,fp );
		sprintf(Str,"|院系排名:%d",Sort(p_head,i,2));
		fputs(Str,fp );
		sprintf(Str,"|班级排名:%d",ClassSort(p_head,i,2));
		fputs(Str,fp );
		sprintf(Str,"|英语成绩:%d",p_temp->m_nEnglish);
		fputs(Str,fp );
		sprintf(Str,"|院系排名:%d",Sort(p_head,i,3));
		fputs(Str,fp );
		sprintf(Str,"|班级排名:%d",ClassSort(p_head,i,3));
		fputs(Str,fp );
		sprintf(Str,"|专业成绩:%d",p_temp->m_nComputer);
		fputs(Str,fp );
		sprintf(Str,"|院系排名:%d",Sort(p_head,i,4));
		fputs(Str,fp );
		sprintf(Str,"|班级排名:%d",ClassSort(p_head,i,4));
		fputs(Str,fp );
		sprintf(Str,"|总成绩:%d",p_temp->m_nComputer+p_temp->m_nEnglish+p_temp->m_nChinese+p_temp->m_nMath);
		fputs(Str,fp );
		sprintf(Str,"|院系排名:%d",Sort(p_head,i,5));
		fputs(Str,fp );
		sprintf(Str,"|班级排名:%d\n",ClassSort(p_head,i,5));
		fputs(Str,fp );
	    i=i+1;
	    p_temp=p_temp->m_pNext;
	
	} 
	printf("(提示:文件已保存在当前目录下，文件名：File.txt)\n"); 
	fclose(fp);	
} 
	
	
void Display(Stu *p_head)
{   if(p_head == NULL)
    {
    	printf("WRONG:未进行初始化表\n");
    	return;	 
    }
    int i = 1;
	Stu *p_temp = p_head->m_pNext;
	while(p_temp)
	{   
		printf("|编号:%d ",p_temp->m_nSign);
		printf("|姓名:%s ",p_temp->m_strName);
		printf("|班级:%s ",p_temp->m_strClass);
		printf("|数学成绩:%d 院系名次:%d 班级名次:%d\n",p_temp->m_nMath,Sort(p_head,i,1),ClassSort(p_head,i,1));
		printf("|语文成绩:%d 院系名次:%d 班级名次:%d\n",p_temp->m_nChinese,Sort(p_head,i,2),ClassSort(p_head,i,2));
		printf("|英语成绩:%d 院系名次:%d 班级名次:%d\n",p_temp->m_nEnglish,Sort(p_head,i,3),ClassSort(p_head,i,3));
		printf("|专业成绩:%d 院系名次:%d 班级名次:%d\n",p_temp->m_nComputer,Sort(p_head,i,4),ClassSort(p_head,i,4));
		printf("|总成绩:%d   院系名次:%d 班级名次:%d\n\n",p_temp->m_nComputer+p_temp->m_nEnglish+p_temp->m_nChinese+p_temp->m_nMath,Sort(p_head,i,5),ClassSort(p_head,i,5));
		i=i+1;
	    p_temp=p_temp->m_pNext;
	}
}


void Del(Stu *p_head)
{   if(p_head == NULL)
    {
    	printf("WRONG:未进行初始化表\n");
    	return;	 
    }
    int n_ID;
    printf("请输入你想删除的表的编号：");
    scanf("%d",&n_ID);
	free(Search(n_ID,p_head));  //释放内存空间 
    Stu *p_temp1=Search(n_ID-1,p_head);   //删除结点前后关联 
    Stu *p_temp2=Search(n_ID+1,p_head);  
    p_temp1->m_pNext = p_temp2;
    while(p_temp2)
    {
    	p_temp2->m_nSign = (p_temp2->m_nSign)-1;
    	p_temp2 = p_temp2->m_pNext;
	}    	
	printf("(提示：删除成功)");
}


int ClassSort(Stu *p_head,int n_ID,int n_subject)   //同sort类似，只是判断了班级是否相同 
{   
    Stu *p_thisStudent=Search(n_ID,p_head);
    int num;
	int i = 1;
	int sum = 0;
    if(n_subject == 1)
    {
    	num = p_thisStudent->m_nMath;
    	while(Search(i,p_head))
    	{
    	if(num <= Search(i,p_head)->m_nMath && strcmp(p_thisStudent->m_strClass,Search(i,p_head)->m_strClass) == 0)
		{
		sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
	if(n_subject == 2)
	{
		num = p_thisStudent->m_nChinese;
    	while(Search(i,p_head))
    	{
    	if(num <= Search(i,p_head)->m_nChinese && strcmp(p_thisStudent->m_strClass,Search(i,p_head)->m_strClass) == 0)
		{
		sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
	if(n_subject == 3)
	{
		num = p_thisStudent->m_nEnglish;
    	while(Search(i,p_head))
    	{
    	if(num <= Search(i,p_head)->m_nEnglish && strcmp(p_thisStudent->m_strClass,Search(i,p_head)->m_strClass) == 0)
		{
		sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
	if(n_subject == 4)
	{
		num = p_thisStudent->m_nComputer;
    	while(Search(i,p_head))
    	{
    	if(num <= Search(i,p_head)->m_nComputer && strcmp(p_thisStudent->m_strClass,Search(i,p_head)->m_strClass) == 0)
		{
		sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
	if(n_subject == 5)
	{
		num = p_thisStudent->m_nComputer+p_thisStudent->m_nEnglish+p_thisStudent->m_nChinese+p_thisStudent->m_nMath;
    	while(Search(i,p_head))
    	{
    	int n_sumScore = Search(i,p_head)->m_nComputer+Search(i,p_head)->m_nEnglish+Search(i,p_head)->m_nChinese+Search(i,p_head)->m_nMath;
    	if(num <= n_sumScore && strcmp(p_thisStudent->m_strClass,Search(i,p_head)->m_strClass) == 0)
		{
		sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
 } 
 
 void Change(Stu *p_head)
{   if(p_head == NULL)
    {
    	printf("WRONG:未进行初始化表\n");
    	return;	 
    }
    if(p_head == NULL)
    {
    	printf("WRONG:空间分配失败\n");
    	exit(-1);	 
    }
    char c_value[20];
    int n_ID;
    printf("请输入你想修改的表的编号：");
    scanf("%d",&n_ID);
	Stu *p_temp = Search(n_ID,p_head);    //通过编号搜索结点位置 
	printf("请选择你想修改的值（A:姓名，B:班级，C:数学成绩，D:语文成绩，E:英语成绩，F:专业成绩）：");  
	scanf("%s",c_value);
	printf("请输入你修改后的内容：");
	if(strcmp(c_value,"A") == 0)
	    {
		scanf("%s",p_temp->m_strName);
	    printf("(提示：修改成功！)");
	    } 
    else if(strcmp(c_value,"B") == 0)
	    {
		scanf("%s",p_temp->m_strClass);
	    printf("(提示：修改成功！)");
	    } 
	else if (strcmp(c_value,"C") == 0)
		{
		scanf("%d",&p_temp->m_nMath);
		printf("(提示：修改成功！)");
		} 
	else if (strcmp(c_value,"D") == 0)
		{
		scanf("%d",&p_temp->m_nChinese);
		printf("(提示：修改成功！)");
		} 
	else if (strcmp(c_value,"E") == 0)
		{
		scanf("%d",&p_temp->m_nEnglish);
		printf("(提示：修改成功！)");
		} 
	else if (strcmp(c_value,"F") == 0)
		{
		scanf("%d",&p_temp->m_nComputer);
		printf("(提示：修改成功！)");
		} 
	else 
	    printf("(提示：没有这个功能)");   
}


void Add(Stu *p_head)
{   if(p_head == NULL)
    {
    	printf("WRONG:未进行初始化表\n");
    	return;	 
    }
    if(p_head == NULL)
    {
    	printf("WRONG:空间分配失败\n");
    	exit(-1);	 
    }
	int n;
	printf("请输入你想添加的表的位置（输入0则插在开头，输入1则插在1-2之间,以此类推）:");
	scanf("%d",&n);
	Stu *p_new = (Stu *)malloc(sizeof(Stu));   //分配新结点 
	if(p_new == NULL)
    {
    	printf("WRONG:空间分配失败\n");
    	exit(-1);	 
    }
	printf("输入新增表:\n");
	printf("姓名(%d):",n+1);
	scanf("%s",p_new->m_strName);
	printf("班级(%d):",n+1);
	scanf("%s",p_new->m_strClass);
	printf("数学成绩(%d):",n+1);
	scanf("%d",&p_new->m_nMath);
	printf("语文成绩(%d):",n+1);
	scanf("%d",&p_new->m_nChinese);
	printf("英语成绩(%d):",n+1);
	scanf("%d",&p_new->m_nEnglish);
	printf("专业成绩(%d):",n+1);
	scanf("%d",&p_new->m_nComputer);
	Stu *p_temp1 = Search(n,p_head);    //搜索新结点插入位置的前后结点 
    Stu *p_temp2 = Search(n+1,p_head);
    Stu *p_temp = Search(n+1,p_head);
    while(p_temp)
    {
    	p_temp->m_nSign++;      //对后续结点编号加一 
    	p_temp = p_temp->m_pNext;
	}
	p_temp1->m_pNext = p_new;    //将新增结点前一结点指向新结点，将新结点指向后一结点，完成关联 
	p_new->m_pNext = p_temp2;
	p_new->m_nSign = n+1; 
}	 
*/ 
