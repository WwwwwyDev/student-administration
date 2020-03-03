//函数定义
#include "sys.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
			printf("|年级:%s\n",p_temp->m_strGrade);
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
		printf("年级(编号:%d):",n_id);
		scanf("%s",p_temp->m_strGrade);
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
		fputs("|年级:",fp );
		fputs(p_temp->m_strGrade,fp );
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
		printf("|年级:%s\n",p_temp->m_strGrade);
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
	printf("请选择你想修改的值（A:姓名，B:年级，C:班级，D:数学成绩，E:语文成绩，F:英语成绩，G:专业成绩）：");  
	scanf("%s",c_value);
	printf("请输入你修改后的内容：");
	if(strcmp(c_value,"A") == 0)
	    {
		scanf("%s",p_temp->m_strName);
	    printf("(提示：修改成功！)");
	    } 
	else if(strcmp(c_value,"B") == 0)
	    {
		scanf("%s",p_temp->m_strGrade);
	    printf("(提示：修改成功！)");
	    } 
    else if(strcmp(c_value,"C") == 0)
	    {
		scanf("%s",p_temp->m_strClass);
	    printf("(提示：修改成功！)");
	    } 
	else if (strcmp(c_value,"D") == 0)
		{
		scanf("%d",&p_temp->m_nMath);
		printf("(提示：修改成功！)");
		} 
	else if (strcmp(c_value,"E") == 0)
		{
		scanf("%d",&p_temp->m_nChinese);
		printf("(提示：修改成功！)");
		} 
	else if (strcmp(c_value,"F") == 0)
		{
		scanf("%d",&p_temp->m_nEnglish);
		printf("(提示：修改成功！)");
		} 
	else if (strcmp(c_value,"G") == 0)
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
	printf("年级(%d):",n+1);
	scanf("%s",p_new->m_strGrade);
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
