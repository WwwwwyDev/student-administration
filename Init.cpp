#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
Stu *Itzlink(int n_num) 
{   
    int n_id;
    Stu *p_head = NULL;//ͷָ�� 
    Stu *p_init = (Stu *)malloc(sizeof(Stu));//��ʼ���ս�� 
    if(p_init == NULL)
    {
    	printf("�ռ����ʧ��\n");
    	exit(-1);	 
    }
	Stu *p_temp = (Stu *)malloc(sizeof(Stu));//��ʱ��� 
	if(p_temp == NULL)
    {
    	printf("�ռ����ʧ��\n");
    	exit(-1);	 
    }
	p_head=p_temp;
	p_init->m_pNext = NULL;
	p_temp->m_pNext = p_init;
	p_temp->m_nSign = 0;
	p_temp = p_init;
	for(n_id = 1;n_id <= n_num;n_id++)
	{
		
		printf("����ѧ����Ϣ(���:%d):\n",n_id);
		printf("����(���:%d):",n_id);
		scanf("%s",p_temp->m_strName);
		printf("�꼶(���:%d):",n_id);
		scanf("%s",p_temp->m_strGrade);
		printf("�༶(���:%d):",n_id);
		scanf("%s",p_temp->m_strClass);
		printf("��ѧ�ɼ�(���:%d):",n_id);
		scanf("%d",&p_temp->m_nMath);
		printf("���ĳɼ�(���:%d):",n_id);
		scanf("%d",&p_temp->m_nChinese);
		printf("Ӣ��ɼ�(���:%d):",n_id);
		scanf("%d",&p_temp->m_nEnglish);
		printf("רҵ�ɼ�(���:%d):",n_id);
		scanf("%d",&p_temp->m_nComputer);
		p_temp->m_nSign=n_id;
		if(n_id < n_num)
		{
		Stu *p_init = (Stu *)malloc(sizeof(Stu));
			if(p_init == NULL)
        	{
    			printf("�ռ����ʧ��\n");
    			exit(-1);	 
        	}
		p_init->m_pNext = NULL;
		p_temp->m_pNext = p_init;
		p_temp=p_init;
	    }
	}
    return p_head;
}
