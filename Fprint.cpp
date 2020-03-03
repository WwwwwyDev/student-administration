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
	    sprintf(Str,"|编号:%d",p_temp->m_nSign);
		fputs(Str,fp );
		fputs("|姓名:",fp );
		fputs(p_temp->m_strName,fp );
		fputs("|年级:",fp );
		fputs(p_temp->m_strGrade,fp );
		fputs("|班级:",fp );
		fputs(p_temp->m_strClass,fp );
		sprintf(Str,"|数学成绩:%d",p_temp->m_nMath);
		fputs(Str,fp );
		sprintf(Str,"|院系排名:%d",Sort(p_head,i,1));
		fputs(Str,fp );
		sprintf(Str,"|语文成绩:%d",p_temp->m_nChinese);
		fputs(Str,fp );
		sprintf(Str,"|院系排名:%d",Sort(p_head,i,2));
		fputs(Str,fp );
		sprintf(Str,"|英语成绩:%d",p_temp->m_nEnglish);
		fputs(Str,fp );
		sprintf(Str,"|院系排名:%d",Sort(p_head,i,3));
		fputs(Str,fp );
		sprintf(Str,"|专业成绩:%d",p_temp->m_nComputer);
		fputs(Str,fp );
		sprintf(Str,"|院系排名:%d",Sort(p_head,i,4));
		fputs(Str,fp );
		sprintf(Str,"|总成绩:%d",p_temp->m_nComputer+p_temp->m_nEnglish+p_temp->m_nChinese+p_temp->m_nMath);
		fputs(Str,fp );
		sprintf(Str,"|院系排名:%d\n",Sort(p_head,i,5));
		fputs(Str,fp );
	    i=i+1;
	    p_temp=p_temp->m_pNext;
	
	} 
	printf("文件已保存在当前目录下，文件名：File.txt\n"); 
	fclose(fp);	
	} 


 
