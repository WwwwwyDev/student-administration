#include <stdio.h>
#include "struct.h"
#include "Sort.h"
void Display(Stu *p_head)
{   int i = 1;
	Stu *p_temp = p_head->m_pNext;
	while(p_temp)
	{   
		printf("|���:%d ",p_temp->m_nSign);
		printf("|����:%s ",p_temp->m_strName);
		printf("|�꼶:%s ",p_temp->m_strGrade);
		printf("|�༶:%s ",p_temp->m_strClass);
		printf("|��ѧ�ɼ�:%d Ժϵ����:%d",p_temp->m_nMath,Sort(p_head,i,1));
		printf("|���ĳɼ�:%d Ժϵ����:%d",p_temp->m_nChinese,Sort(p_head,i,2));
		printf("|Ӣ��ɼ�:%d Ժϵ����:%d",p_temp->m_nEnglish,Sort(p_head,i,3));
		printf("|רҵ�ɼ�:%d Ժϵ����:%d\n",p_temp->m_nComputer,Sort(p_head,i,4));
		i=i+1;
	    p_temp=p_temp->m_pNext;
	}
}
