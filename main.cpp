#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sys.h"

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
		printf("\n请选择你要进行的操作（A:插入表 B:删除表 C:修改表 D:输出表 E:查找表 F:打印表 G:输出不及格 H:退出）:"); 
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
			Stu *temp = NULL;
			for(i=1;i<=n_num;i++)
			{
				if(strcmp(str_name,Search(i,p_head)->m_strName)==0)
				{   temp=Search(i,p_head);
					printf("|编号:%d ",temp->m_nSign);
		    		printf("|姓名:%s ",temp->m_strName);
		    		printf("|班级:%s ",temp->m_strClass);
					printf("|年级:%s\n",temp->m_strGrade);
					printf("|数学成绩:%d 院系名次:%d 班级名次:%d\n",temp->m_nMath,Sort(p_head,i,1),ClassSort(p_head,i,1));
					printf("|语文成绩:%d 院系名次:%d 班级名次:%d\n",temp->m_nChinese,Sort(p_head,i,2),ClassSort(p_head,i,2));
					printf("|英语成绩:%d 院系名次:%d 班级名次:%d\n",temp->m_nEnglish,Sort(p_head,i,3),ClassSort(p_head,i,3));
					printf("|专业成绩:%d 院系名次:%d 班级名次:%d\n",temp->m_nComputer,Sort(p_head,i,4),ClassSort(p_head,i,4));
					printf("|总成绩:%d   院系名次:%d 班级名次:%d\n\n",temp->m_nComputer+temp->m_nEnglish+temp->m_nChinese+temp->m_nMath,Sort(p_head,i,5),ClassSort(p_head,i,5));
				}
			}
			if(temp==NULL)
			{
				printf("(提示:查无此人)");
			}
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
			if(n_num==0)
			{
				printf("提示：请先添加一个表");
				break; 
			}
			else
			{ 
			NoPass(p_head);
			break;
			} 
			case 'H':
			return 0;
			default: 
			printf("(提示：无此功能)");
			break;	
		}
	    
	} 
    return 0;
}
