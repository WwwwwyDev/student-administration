#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "Search.h"
void Add(Stu *p_head)
{
	int n;
	printf("请输入你想添加的表的位置（输入0则插在开头，输入1则插在1-2之间,以此类推）:");
	scanf("%d",&n);
	Stu *p_new = (Stu *)malloc(sizeof(Stu));
	if(p_new == NULL)
    {
    	printf("空间分配失败\n");
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
	Stu *p_temp1 = Search(n,p_head);
    Stu *p_temp2 = Search(n+1,p_head);
    Stu *p_temp = Search(n+1,p_head);
    while(p_temp)
    {
    	p_temp->m_nSign++;
    	p_temp = p_temp->m_pNext;
	}
	p_temp1->m_pNext = p_new;
	p_new->m_pNext = p_temp2;
	p_new->m_nSign = n+1; 
}
