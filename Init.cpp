#include "Struct.h"
Stu *Itzlink(int n)  //head->kong->......->null
{   int n_id;
    link *p_head = NULL;
    link *p_init = (Stu *)malloc(sizeof(Stu));//��ʼ���ս�� 
	link *p_temp = (Stu *)malloc(sizeof(Stu));//��ʱ��� 
	p_head=p_temp;
	p_init->m_pNext = NULL;
	p_temp->m_pNext = p_init;
	p_temp->m_nSign = 0;
	p_temp = p_init;
	for(n_id=1;n_id<=n;n_id++)
	{
		
		printf("����ѧ����Ϣ(���:%d):\n",n_id);
		printf("����(���:%d):",n_id);
		scanf("%s",p_temp->m_name);
		printf("�꼶(���:%d):",n_id);
		scanf("%s",temp->grade);
		printf("�༶(���:%d):",n_id);
		scanf("%s",temp->classs);
		printf("��ѧ�ɼ�(���:%d):",n_id);
		scanf("%d",&temp->math);
		printf("���ĳɼ�(���:%d):",n_id);
		scanf("%d",&temp->chinese);
		printf("Ӣ��ɼ�(���:%d):",n_id);
		scanf("%d",&temp->english);
		printf("רҵ�ɼ�(���:%d):",n_id);
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
