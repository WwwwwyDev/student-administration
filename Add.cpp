#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "Search.h"
void Add(Stu *p_head)
{
	int n;
	printf("������������ӵı��λ�ã�����0����ڿ�ͷ������1�����1-2֮��,�Դ����ƣ�:");
	scanf("%d",&n);
	Stu *p_new = (Stu *)malloc(sizeof(Stu));
	if(p_new == NULL)
    {
    	printf("�ռ����ʧ��\n");
    	exit(-1);	 
    }
	printf("����������:\n");
	printf("����(%d):",n+1);
	scanf("%s",p_new->m_strName);
	printf("�꼶(%d):",n+1);
	scanf("%s",p_new->m_strGrade);
	printf("�༶(%d):",n+1);
	scanf("%s",p_new->m_strClass);
	printf("��ѧ�ɼ�(%d):",n+1);
	scanf("%d",&p_new->m_nMath);
	printf("���ĳɼ�(%d):",n+1);
	scanf("%d",&p_new->m_nChinese);
	printf("Ӣ��ɼ�(%d):",n+1);
	scanf("%d",&p_new->m_nEnglish);
	printf("רҵ�ɼ�(%d):",n+1);
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
