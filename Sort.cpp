#include "struct.h"
#include "Search.h"
int Sort(Stu *p_head,int n_ID,int n_subject)
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
 } 
