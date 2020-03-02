#include "Struct.h"
Stu *Itzlink(int n)  //head->kong->......->null
{   int n_id;
    link *p_head = NULL;
    link *p_init = (Stu *)malloc(sizeof(Stu));//初始化空结点 
	link *p_temp = (Stu *)malloc(sizeof(Stu));//临时结点 
	p_head=p_temp;
	p_init->m_pNext = NULL;
	p_temp->m_pNext = p_init;
	p_temp->m_nSign = 0;
	p_temp = p_init;
	for(n_id=1;n_id<=n;n_id++)
	{
		
		printf("输入学生信息(编号:%d):\n",n_id);
		printf("姓名(编号:%d):",n_id);
		scanf("%s",p_temp->m_name);
		printf("年级(编号:%d):",n_id);
		scanf("%s",temp->grade);
		printf("班级(编号:%d):",n_id);
		scanf("%s",temp->classs);
		printf("数学成绩(编号:%d):",n_id);
		scanf("%d",&temp->math);
		printf("语文成绩(编号:%d):",n_id);
		scanf("%d",&temp->chinese);
		printf("英语成绩(编号:%d):",n_id);
		scanf("%d",&temp->english);
		printf("专业成绩(编号:%d):",n_id);
		scanf("%d",&temp->computer);
		temp->sign=n_id;
		if(n_id<n)
		{
		link *a=(link *)malloc(sizeof(link));
		a->next=NULL;
		temp->next=a;
		temp=a;
	    }
	}
    return p;
}
