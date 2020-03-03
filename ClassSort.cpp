#include "struct.h"
#include "Search.h"
#include <string.h>
int ClassSort(Stu *p_head,int n_ID,int n_subject)
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
