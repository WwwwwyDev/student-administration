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
    printf("��������Ҫ������ѧ������:");  //��ʼ������
    Stu *p_head=NULL; 
	scanf("%d",&n_num);
	if(n_num==0) 
	{   
	    p_head=Itzlink(n_num);
		printf("��ʾ���㴴����һ���ձ�"); 
	}
	else
	{
		p_head=Itzlink(n_num);
	}
while(1)
	{   
		printf("\n��ѡ����Ҫ���еĲ�����A:����� B:ɾ���� C:�޸ı� D:����� E:���ұ� F:��ӡ�� G:�˳���:"); 
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
				printf("��ʾ���������һ����");
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
				printf("��ʾ���������һ����");
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
				printf("��ʾ���������һ����");
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
				printf("��ʾ���������һ����");
				break; 
			}
			else
			{ 
			printf("��������Ҫ����ѧ����������");
			scanf("%s",str_name);
			for(i=1;i<=n_num;i++)
			{
				if(strcmp(str_name,Search(i,p_head)->m_strName)==0)
				{
					break;
				}
			}
			Stu *temp=Search(i,p_head);
			printf("|���:%d ",temp->m_nSign);
		    printf("|����:%s ",temp->m_strName);
		    printf("|�꼶:%s ",temp->m_strGrade);
		    printf("|�༶:%s ",temp->m_strClass);
		    printf("|��ѧ�ɼ�:%d ",temp->m_nMath);
		    printf("|���ĳɼ�:%d ",temp->m_nChinese);
		    printf("|Ӣ��ɼ�:%d ",temp->m_nEnglish);
		    printf("|רҵ�ɼ�:%d\n",temp->m_nComputer);
			break;
			} 
			case 'F':
			if(n_num==0)
			{
				printf("��ʾ���������һ����");
				break; 
			}
			else
			{ 
			Fprint(p_head);
			break;
			} 
			case 'G':
			return 0;
			default: printf("��ʾ���޴˹���");
			break;	
		}
	    
	} 
    return 0;
}
