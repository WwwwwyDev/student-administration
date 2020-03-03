#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "Sort.h"
void Fprint(Stu *p_head)
{   char Str[256];
    int i = 1; 
    Stu *p_temp = p_head->m_pNext; 
    FILE *fp;
    fp = fopen("File.txt", "w");
    if (fp == NULL)
    {
    printf("cannot open file\n");
    exit(-1);
    }
    while(p_temp)
	{   
	    sprintf(Str,"|���:%d",p_temp->m_nSign);
		fputs(Str,fp );
		fputs("|����:",fp );
		fputs(p_temp->m_strName,fp );
		fputs("|�꼶:",fp );
		fputs(p_temp->m_strGrade,fp );
		fputs("|�༶:",fp );
		fputs(p_temp->m_strClass,fp );
		sprintf(Str,"|��ѧ�ɼ�:%d",p_temp->m_nMath);
		fputs(Str,fp );
		sprintf(Str,"|Ժϵ����:%d",Sort(p_head,i,1));
		fputs(Str,fp );
		sprintf(Str,"|���ĳɼ�:%d",p_temp->m_nChinese);
		fputs(Str,fp );
		sprintf(Str,"|Ժϵ����:%d",Sort(p_head,i,2));
		fputs(Str,fp );
		sprintf(Str,"|Ӣ��ɼ�:%d",p_temp->m_nEnglish);
		fputs(Str,fp );
		sprintf(Str,"|Ժϵ����:%d",Sort(p_head,i,3));
		fputs(Str,fp );
		sprintf(Str,"|רҵ�ɼ�:%d",p_temp->m_nComputer);
		fputs(Str,fp );
		sprintf(Str,"|Ժϵ����:%d",Sort(p_head,i,4));
		fputs(Str,fp );
		sprintf(Str,"|�ܳɼ�:%d",p_temp->m_nComputer+p_temp->m_nEnglish+p_temp->m_nChinese+p_temp->m_nMath);
		fputs(Str,fp );
		sprintf(Str,"|Ժϵ����:%d\n",Sort(p_head,i,5));
		fputs(Str,fp );
	    i=i+1;
	    p_temp=p_temp->m_pNext;
	
	} 
	printf("�ļ��ѱ����ڵ�ǰĿ¼�£��ļ�����File.txt\n"); 
	fclose(fp);	
	} 


 
