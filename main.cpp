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
		printf("\n��ѡ����Ҫ���еĲ�����A:����� B:ɾ���� C:�޸ı� D:����� E:���ұ� F:��ӡ�� G:��������� H:�˳���:"); 
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
			Stu *temp = NULL;
			for(i=1;i<=n_num;i++)
			{
				if(strcmp(str_name,Search(i,p_head)->m_strName)==0)
				{   temp=Search(i,p_head);
					printf("|���:%d ",temp->m_nSign);
		    		printf("|����:%s ",temp->m_strName);
		    		printf("|�༶:%s ",temp->m_strClass);
					printf("|�꼶:%s\n",temp->m_strGrade);
					printf("|��ѧ�ɼ�:%d Ժϵ����:%d �༶����:%d\n",temp->m_nMath,Sort(p_head,i,1),ClassSort(p_head,i,1));
					printf("|���ĳɼ�:%d Ժϵ����:%d �༶����:%d\n",temp->m_nChinese,Sort(p_head,i,2),ClassSort(p_head,i,2));
					printf("|Ӣ��ɼ�:%d Ժϵ����:%d �༶����:%d\n",temp->m_nEnglish,Sort(p_head,i,3),ClassSort(p_head,i,3));
					printf("|רҵ�ɼ�:%d Ժϵ����:%d �༶����:%d\n",temp->m_nComputer,Sort(p_head,i,4),ClassSort(p_head,i,4));
					printf("|�ܳɼ�:%d   Ժϵ����:%d �༶����:%d\n\n",temp->m_nComputer+temp->m_nEnglish+temp->m_nChinese+temp->m_nMath,Sort(p_head,i,5),ClassSort(p_head,i,5));
				}
			}
			if(temp==NULL)
			{
				printf("(��ʾ:���޴���)");
			}
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
			if(n_num==0)
			{
				printf("��ʾ���������һ����");
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
			printf("(��ʾ���޴˹���)");
			break;	
		}
	    
	} 
    return 0;
}
