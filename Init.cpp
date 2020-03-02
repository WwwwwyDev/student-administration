#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
Stu *Itzlink(int n_num) 
{   
    int n_id;
    Stu *p_head = NULL;//头指针 
    Stu *p_init = (Stu *)malloc(sizeof(Stu));//初始化空结点 
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
	p_head=p_temp;
	p_init->m_pNext = NULL;
	p_temp->m_pNext = p_init;
	p_temp->m_nSign = 0;
	p_temp = p_init;
	for(n_id = 1;n_id <= n_num;n_id++)
	{
		
		printf("输入学生信息(编号:%d):\n",n_id);
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
		Stu *p_init = (Stu *)malloc(sizeof(Stu));
			if(p_init == NULL)
        	{
    			printf("空间分配失败\n");
    			exit(-1);	 
        	}
		p_init->m_pNext = NULL;
		p_temp->m_pNext = p_init;
		p_temp=p_init;
	    }
	}
    return p_head;
}
