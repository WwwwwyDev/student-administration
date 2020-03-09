#include "list.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void InitItem(Stu *plist) //初始化结点，将plist指向一个空链表
{     strcpy(plist->m_nComputer,"0");
      strcpy(plist->m_nChinese,"0");
      strcpy(plist->m_nEnglish,"0");
      strcpy(plist->m_nMath,"0");
      plist->m_pNext = NULL;
} 

void AddItem(Stu *plist)  //尾插结点，传入前置结点，遍历到NULL，将尾部的指针域指向尾部新结点 ，完成添加 
{   
	struct Stu *temp = (struct Stu*)malloc(sizeof(struct Stu));
	if(temp == NULL)
    {
    	printf("空间分配失败\n");
    	exit(-1);	 
    }
	InitItem(temp); 
	temp->m_nSign=plist->m_nSign+1;
	plist->m_pNext=temp;
	temp->m_pNext=NULL;
}
Stu *NextItem(Stu *plist) //传入当前结点，传出下一结点 
{   if(plist==NULL)
	return NULL;
	else
	return plist->m_pNext;
}

Stu *InitList(int num) //初始化链表 
{   int i;
	struct Stu *phead = (struct Stu*)malloc(sizeof(struct Stu)); //创建头结点，编号为0，不存任何数据 
	struct Stu *temp = phead;
	if(phead == NULL)
    {
    	printf("空间分配失败\n");
    	exit(-1);	 
    }
    phead->m_pNext = NULL;
    InitItem(phead);
	phead->m_nSign = 0;
	for(i=1;i<=num;i++)
	{
		AddItem(temp);
		temp=NextItem(temp); 
		temp->m_nSign = i; 
	}
	return phead;
}

Stu *SearchItem(int num,Stu *phead)  //传入头指针，返回编号为num的结点位置 
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





