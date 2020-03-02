#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "Search.h"
void Change(Stu *p_head)
{   char c_value[20];
    int n_ID;
    printf("请输入你想修改的表的编号：");
    scanf("%d",&n_ID);
	Stu *p_temp = Search(n_ID,p_head);
	printf("请选择你想修改的值（姓名，年级，班级，数学成绩，语文成绩，英语成绩，专业成绩）：");
	scanf("%s",c_value);
	printf("请输入你修改后的内容：");
	if(strcmp(c_value,"姓名") == 0)
	    scanf("%s",p_temp->m_strName);
	else if(strcmp(c_value,"年级") == 0)
	    scanf("%s",p_temp->m_strGrade);
    else if(strcmp(c_value,"班级") == 0)
	    scanf("%s",p_temp->m_strClass);
	else if (strcmp(c_value,"数学成绩") == 0)
		scanf("%d",&p_temp->m_nMath);
	else if (strcmp(c_value,"语文成绩") == 0)
		scanf("%d",&p_temp->m_nChinese);
	else if (strcmp(c_value,"英语成绩") == 0)
		scanf("%d",&p_temp->m_nEnglish);
	else if (strcmp(c_value,"专业成绩") == 0)
		scanf("%d",&p_temp->m_nComputer);
	else 
	    printf("查无此名");   
}
