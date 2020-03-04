#include "list.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void InitItem(Stu *plist) //��ʼ����㣬��plistָ��һ��������
{     /*strcpy(plist->m_nComputer,"0");
      strcpy(plist->m_nChinese,"0");
      strcpy(plist->m_nEnglish,"0");
      strcpy(plist->m_nMath,"0");
      strcpy(plist->m_strName,"�޷�����");
	  strcpy(plist->m_strClass,"None");*/
      plist->m_pNext = NULL;
} 

void AddItem(Stu *plist)  //β���㣬������һ��㣬����һ����ָ����ָ��β���½�� 
{
	struct Stu *temp = (struct Stu*)malloc(sizeof(struct Stu));
	if(temp == NULL)
    {
    	printf("�ռ����ʧ��\n");
    	exit(-1);	 
    }
	InitItem(temp); 
	temp->m_nSign=plist->m_nSign+1;
	plist->m_pNext=temp;
}
Stu *NextItem(Stu *plist) //���뵱ǰ��㣬������һ��� 
{
	return plist->m_pNext;
}

Stu *InitList(int num) //��ʼ������ 
{   int i;
	struct Stu *phead = (struct Stu*)malloc(sizeof(struct Stu)); //����ͷ��㣬���Ϊ0�������κ����� 
	struct Stu *temp = phead;
	if(phead == NULL)
    {
    	printf("�ռ����ʧ��\n");
    	exit(-1);	 
    }
    InitItem(phead);
	phead->m_nSign = 0;
	for(i=1;i<=num;i++)
	{
		AddItem(temp);
		temp=NextItem(temp);  //��ʱtemp->NULL 
		temp->m_nSign = i; 
	}
	return phead;
}

Stu *SearchItem(int num,Stu *phead)  //����ͷָ�룬���ر��Ϊnum�Ľ��λ�� 
{   struct Stu *temp = phead;
    while(temp)
    {
		if(num == temp->m_nSign)
    	{
    		return temp;
		}
		else
		{
			temp = NextItem(temp); 
		}
	}
	return NULL;
} 



