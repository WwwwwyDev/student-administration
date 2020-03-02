#include <stdio.h>
#include "struct.h"
#include "Sort.h"
void Display(Stu *p_head)
{   int i = 1;
	Stu *p_temp = p_head->m_pNext;
	while(p_temp)
	{   
		printf("|编号:%d ",p_temp->m_nSign);
		printf("|姓名:%s ",p_temp->m_strName);
		printf("|年级:%s ",p_temp->m_strGrade);
		printf("|班级:%s ",p_temp->m_strClass);
		printf("|数学成绩:%d 名次:%d",p_temp->m_nMath,Sort(p_head,i,1));
		printf("|语文成绩:%d 名次:%d",p_temp->m_nChinese,Sort(p_head,i,2));
		printf("|英语成绩:%d 名次:%d",p_temp->m_nEnglish,Sort(p_head,i,3));
		printf("|专业成绩:%d 名次:%d\n",p_temp->m_nComputer,Sort(p_head,i,4));
		i=i+1;
	    p_temp=p_temp->m_pNext;
	}
}
