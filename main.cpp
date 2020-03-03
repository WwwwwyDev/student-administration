#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "Init.h"
#include "Sort.h"
#include "Search.h"
#include "Display.h"
#include "Add.h"
#include "Change.h"
#include "Del.h"
#include "Fprint.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	int n_num,i ;
	char a;
    char str_name[10];
    printf("请输入你要创建的学生个数:");  //初始化链表
    Stu *p_head=NULL; 
	scanf("%d",&n_num);
	if(n_num==0) 
	{   
	    p_head=Itzlink(n_num);
		printf("提示：你创建了一个空表"); 
	}
	else
	{
		p_head=Itzlink(n_num);
	}
while(1)
	{   
		printf("\n请选择你要进行的操作（A:插入表 B:删除表 C:修改表 D:输出表 E:查找表 F:打印表 G:退出）:"); 
		getchar();
		scanf("%c",&a);
		switch(a)
		{
			case 'A': 
			Add(p_head);
			n_num=n_num+1;
			break;
			case 'B': if(n_num==0)
			{
				printf("提示：请先添加一个表");
				break; 
			}
			else
			{ 
			Del(p_head);
			n_num=n_num-1;
			break;
			}
			case 'C': 
			if(n_num==0)
			{
				printf("提示：请先添加一个表");
				break; 
			}
			else
			{ 
			Change(p_head);
			break;
			}
			case 'D': 
			if(n_num==0)
			{
				printf("提示：请先添加一个表");
				break; 
			}
			else
			{ 
			Display(p_head);
			break;
			} 
			case 'E': 
			if(n_num==0)
			{
				printf("提示：请先添加一个表");
				break; 
			}
			else
			{ 
			printf("请输入你要查找学生的姓名：");
			scanf("%s",str_name);
			for(i=1;i<=n_num;i++)
			{
				if(strcmp(str_name,Search(i,p_head)->m_strName)==0)
				{
					break;
				}
			}
			Stu *temp=Search(i,p_head);
			printf("|编号:%d ",temp->m_nSign);
		    printf("|姓名:%s ",temp->m_strName);
		    printf("|年级:%s ",temp->m_strGrade);
		    printf("|班级:%s ",temp->m_strClass);
		    printf("|数学成绩:%d ",temp->m_nMath);
		    printf("|语文成绩:%d ",temp->m_nChinese);
		    printf("|英语成绩:%d ",temp->m_nEnglish);
		    printf("|专业成绩:%d\n",temp->m_nComputer);
			break;
			} 
			case 'F':
			if(n_num==0)
			{
				printf("提示：请先添加一个表");
				break; 
			}
			else
			{ 
			Fprint(p_head);
			break;
			} 
			case 'G':
			return 0;
			default: printf("提示：无此功能");
			break;	
		}
	    
	} 
    return 0;
}
