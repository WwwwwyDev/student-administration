#include <stdio.h>
#include "struct.h"
#include "Sort.h"
#include "ClassSort.h"
void NoPass(Stu *p_head)
{
	int i = 1;
	Stu *p_temp = p_head->m_pNext;
	int sum = 0;
	while(p_temp)
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
			printf("|���:%d ",p_temp->m_nSign);
		    printf("|����:%s ",p_temp->m_strName);
		    printf("|�༶:%s ",p_temp->m_strClass);
			printf("|�꼶:%s ",p_temp->m_strGrade);
			printf("|��ѧ�ɼ�:%d Ժϵ����:%d �༶����:%d",p_temp->m_nMath,Sort(p_head,i,1),ClassSort(p_head,i,1));
			printf("|���ĳɼ�:%d Ժϵ����:%d �༶����:%d",p_temp->m_nChinese,Sort(p_head,i,2),ClassSort(p_head,i,2));
			printf("|Ӣ��ɼ�:%d Ժϵ����:%d �༶����:%d",p_temp->m_nEnglish,Sort(p_head,i,3),ClassSort(p_head,i,3));
			printf("|רҵ�ɼ�:%d Ժϵ����:%d �༶����:%d",p_temp->m_nComputer,Sort(p_head,i,4),ClassSort(p_head,i,4));
			printf("|�ܳɼ�:%d Ժϵ����:%d �༶����:%d\n",p_temp->m_nComputer+p_temp->m_nEnglish+p_temp->m_nChinese+p_temp->m_nMath,Sort(p_head,i,5),ClassSort(p_head,i,5));
		}
		i=i+1;
		p_temp=p_temp->m_pNext;
		sum=0;
	}
}
