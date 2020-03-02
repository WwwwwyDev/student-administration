#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "Search.h"
void Del(Stu *p_head)
{   int n_ID;
    printf("请输入你想删除的表的编号：");
    scanf("%d",&n_ID);
	free(Search(n_ID,p_head));
    Stu *p_temp1=Search(n_ID-1,p_head);
    Stu *p_temp2=Search(n_ID+1,p_head);  
    p_temp1->m_pNext = p_temp2;
    while(p_temp2)
    {
    	p_temp2->m_nSign = (p_temp2->m_nSign)-1;
    	p_temp2 = p_temp2->m_pNext;
	}    	
}
