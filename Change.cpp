#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "Search.h"
void Change(Stu *p_head)
{   char c_value[20];
    int n_ID;
    printf("�����������޸ĵı�ı�ţ�");
    scanf("%d",&n_ID);
	Stu *p_temp = Search(n_ID,p_head);
	printf("��ѡ�������޸ĵ�ֵ���������꼶���༶����ѧ�ɼ������ĳɼ���Ӣ��ɼ���רҵ�ɼ�����");
	scanf("%s",c_value);
	printf("���������޸ĺ�����ݣ�");
	if(strcmp(c_value,"����") == 0)
	    scanf("%s",p_temp->m_strName);
	else if(strcmp(c_value,"�꼶") == 0)
	    scanf("%s",p_temp->m_strGrade);
    else if(strcmp(c_value,"�༶") == 0)
	    scanf("%s",p_temp->m_strClass);
	else if (strcmp(c_value,"��ѧ�ɼ�") == 0)
		scanf("%d",&p_temp->m_nMath);
	else if (strcmp(c_value,"���ĳɼ�") == 0)
		scanf("%d",&p_temp->m_nChinese);
	else if (strcmp(c_value,"Ӣ��ɼ�") == 0)
		scanf("%d",&p_temp->m_nEnglish);
	else if (strcmp(c_value,"רҵ�ɼ�") == 0)
		scanf("%d",&p_temp->m_nComputer);
	else 
	    printf("���޴���");   
}
