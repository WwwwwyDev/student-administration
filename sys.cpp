//��������
#include "sys.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Stu *Search(int n_ID,Stu *p_head)
{   
     Stu *p_temp = p_head;
     while(p_temp->m_nSign != n_ID)   //n_ID=�����������ID
     {
	     p_temp = p_temp->m_pNext;
	     if(p_temp == NULL) 
	     {
	     	return NULL;
		 }
	 } 
	return p_temp;
}


int Sort(Stu *p_head,int n_ID,int n_subject)
{
    Stu *p_thisStudent=Search(n_ID,p_head);
    int num;
	int i = 1;
	int sum = 0;
    if(n_subject == 1)   //��Search()������ÿһ�����ñ������ֵ���м����������ȱ���������ֵ��ʱsum+1
    {
    	num = p_thisStudent->m_nMath;
    	while(Search(i,p_head))
    	{
    	if(num <= Search(i,p_head)->m_nMath)
		{
		sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
	if(n_subject == 2)
	{
		num = p_thisStudent->m_nChinese;
    	while(Search(i,p_head))
    	{
    	if(num <= Search(i,p_head)->m_nChinese)
		{
		sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
	if(n_subject == 3)
	{
		num = p_thisStudent->m_nEnglish;
    	while(Search(i,p_head))
    	{
    	if(num <= Search(i,p_head)->m_nEnglish)
		{
		sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
	if(n_subject == 4)
	{
		num = p_thisStudent->m_nComputer;
    	while(Search(i,p_head))
    	{
    	if(num <= Search(i,p_head)->m_nComputer)
		{
		sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
	if(n_subject == 5)
	{
		num = p_thisStudent->m_nComputer+p_thisStudent->m_nEnglish+p_thisStudent->m_nChinese+p_thisStudent->m_nMath;
    	while(Search(i,p_head))
    	{
    	int n_sumScore = Search(i,p_head)->m_nComputer+Search(i,p_head)->m_nEnglish+Search(i,p_head)->m_nChinese+Search(i,p_head)->m_nMath;
    	if(num <= n_sumScore)
		{
		sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
 } 
 
 
 
void NoPass(Stu *p_head)
{   if(p_head == NULL)
    {
    	printf("WRONG:δ���г�ʼ����\n");
    	return;	 
    }
	int i = 1;
	Stu *p_temp = p_head->m_pNext;
	int sum = 0;
	while(p_temp)   //�жϲ����� 
	{
		if(p_temp->m_nMath < 60)
		{
			sum = sum+1;
		}
		if(p_temp->m_nEnglish < 60)
		{
			sum = sum+1;
		}
		if(p_temp->m_nChinese < 60)
		{
			sum = sum+1;
		}
		if(p_temp->m_nComputer < 60)
		{
			sum = sum+1;
		}
		if(sum >= 2)
		{
			printf("|���:%d ",p_temp->m_nSign);
		    printf("|����:%s ",p_temp->m_strName);
		    printf("|�༶:%s ",p_temp->m_strClass);
			printf("|�꼶:%s\n",p_temp->m_strGrade);
			printf("|��ѧ�ɼ�:%d Ժϵ����:%d �༶����:%d\n",p_temp->m_nMath,Sort(p_head,i,1),ClassSort(p_head,i,1));
			printf("|���ĳɼ�:%d Ժϵ����:%d �༶����:%d\n",p_temp->m_nChinese,Sort(p_head,i,2),ClassSort(p_head,i,2));
			printf("|Ӣ��ɼ�:%d Ժϵ����:%d �༶����:%d\n",p_temp->m_nEnglish,Sort(p_head,i,3),ClassSort(p_head,i,3));
			printf("|רҵ�ɼ�:%d Ժϵ����:%d �༶����:%d\n",p_temp->m_nComputer,Sort(p_head,i,4),ClassSort(p_head,i,4));
			printf("|�ܳɼ�:%d   Ժϵ����:%d �༶����:%d\n\n",p_temp->m_nComputer+p_temp->m_nEnglish+p_temp->m_nChinese+p_temp->m_nMath,Sort(p_head,i,5),ClassSort(p_head,i,5));
		}
		i=i+1;
		p_temp=p_temp->m_pNext;
		sum=0;
	}
}

Stu *Itzlink(int n_num) 
{   
    int n_id;
    Stu *p_head = NULL;//ͷָ�� 
    Stu *p_init = (Stu *)malloc(sizeof(Stu));//��ʼ��ͷ��� 
    if(p_init == NULL)
    {
    	printf("�ռ����ʧ��\n");
    	exit(-1);	 
    }
	Stu *p_temp = (Stu *)malloc(sizeof(Stu));//��ʱ��� 
	if(p_temp == NULL)
    {
    	printf("�ռ����ʧ��\n");
    	exit(-1);	 
    }
	p_head=p_init;
	p_init->m_pNext = p_temp;
	p_temp->m_pNext = NULL;
	p_init->m_nSign = 0;  //������ʱ���,ͷָ��ָ��ͷ��㣬ͷ���nextָ��ָ����ʱ��㣬��ʱ���ָ��NULL
	for(n_id = 1;n_id <= n_num;n_id++)
	{
		
		printf("����ѧ����Ϣ(���:%d):\n",n_id);   //����ʱ���д������
		printf("����(���:%d):",n_id);
		scanf("%s",p_temp->m_strName);
		printf("�꼶(���:%d):",n_id);
		scanf("%s",p_temp->m_strGrade);
		printf("�༶(���:%d):",n_id);
		scanf("%s",p_temp->m_strClass);
		printf("��ѧ�ɼ�(���:%d):",n_id);
		scanf("%d",&p_temp->m_nMath);
		printf("���ĳɼ�(���:%d):",n_id);
		scanf("%d",&p_temp->m_nChinese);
		printf("Ӣ��ɼ�(���:%d):",n_id);
		scanf("%d",&p_temp->m_nEnglish);
		printf("רҵ�ɼ�(���:%d):",n_id);
		scanf("%d",&p_temp->m_nComputer);
		p_temp->m_nSign=n_id;
		if(n_id < n_num)
		{
		Stu *p_new = (Stu *)malloc(sizeof(Stu));  //����һ���µĽ��ָ��NULL��������ʱ���nextָ��ָ���½�㣬��ʱ���ָ���½��
			if(p_new == NULL)
        	{
    			printf("�ռ����ʧ��\n");
    			exit(-1);	 
        	}
		p_new->m_pNext = NULL;
		p_temp->m_pNext = p_new;
		p_temp=p_new;
	    }
	}
    return p_head;
}


void Fprint(Stu *p_head)
{   if(p_head == NULL)
    {
    	printf("WRONG:δ���г�ʼ����\n");
    	exit(-1);	 
    }
    char Str[256];
    int i = 1; 
    Stu *p_temp = p_head->m_pNext; 
    FILE *fp;
    fp = fopen("File.txt", "w");    //�Կɶ����ļ� 
    if (fp == NULL)
    {
    printf("cannot open file\n");
    exit(-1);
    }
    while(p_temp)  //д���ļ� 
	{   
	    sprintf(Str,"|���:%d",p_temp->m_nSign);
		fputs(Str,fp );
		fputs("|����:",fp );
		fputs(p_temp->m_strName,fp );
		fputs("|�꼶:",fp );
		fputs(p_temp->m_strGrade,fp );
		fputs("|�༶:",fp );
		fputs(p_temp->m_strClass,fp );
		sprintf(Str,"|��ѧ�ɼ�:%d",p_temp->m_nMath);
		fputs(Str,fp );
		sprintf(Str,"|Ժϵ����:%d",Sort(p_head,i,1));
		fputs(Str,fp );
		sprintf(Str,"|�༶����:%d",ClassSort(p_head,i,1));
		fputs(Str,fp );
		sprintf(Str,"|���ĳɼ�:%d",p_temp->m_nChinese);
		fputs(Str,fp );
		sprintf(Str,"|Ժϵ����:%d",Sort(p_head,i,2));
		fputs(Str,fp );
		sprintf(Str,"|�༶����:%d",ClassSort(p_head,i,2));
		fputs(Str,fp );
		sprintf(Str,"|Ӣ��ɼ�:%d",p_temp->m_nEnglish);
		fputs(Str,fp );
		sprintf(Str,"|Ժϵ����:%d",Sort(p_head,i,3));
		fputs(Str,fp );
		sprintf(Str,"|�༶����:%d",ClassSort(p_head,i,3));
		fputs(Str,fp );
		sprintf(Str,"|רҵ�ɼ�:%d",p_temp->m_nComputer);
		fputs(Str,fp );
		sprintf(Str,"|Ժϵ����:%d",Sort(p_head,i,4));
		fputs(Str,fp );
		sprintf(Str,"|�༶����:%d",ClassSort(p_head,i,4));
		fputs(Str,fp );
		sprintf(Str,"|�ܳɼ�:%d",p_temp->m_nComputer+p_temp->m_nEnglish+p_temp->m_nChinese+p_temp->m_nMath);
		fputs(Str,fp );
		sprintf(Str,"|Ժϵ����:%d",Sort(p_head,i,5));
		fputs(Str,fp );
		sprintf(Str,"|�༶����:%d\n",ClassSort(p_head,i,5));
		fputs(Str,fp );
	    i=i+1;
	    p_temp=p_temp->m_pNext;
	
	} 
	printf("(��ʾ:�ļ��ѱ����ڵ�ǰĿ¼�£��ļ�����File.txt)\n"); 
	fclose(fp);	
} 
	
	
void Display(Stu *p_head)
{   if(p_head == NULL)
    {
    	printf("WRONG:δ���г�ʼ����\n");
    	return;	 
    }
    int i = 1;
	Stu *p_temp = p_head->m_pNext;
	while(p_temp)
	{   
		printf("|���:%d ",p_temp->m_nSign);
		printf("|����:%s ",p_temp->m_strName);
		printf("|�༶:%s ",p_temp->m_strClass);
		printf("|�꼶:%s\n",p_temp->m_strGrade);
		printf("|��ѧ�ɼ�:%d Ժϵ����:%d �༶����:%d\n",p_temp->m_nMath,Sort(p_head,i,1),ClassSort(p_head,i,1));
		printf("|���ĳɼ�:%d Ժϵ����:%d �༶����:%d\n",p_temp->m_nChinese,Sort(p_head,i,2),ClassSort(p_head,i,2));
		printf("|Ӣ��ɼ�:%d Ժϵ����:%d �༶����:%d\n",p_temp->m_nEnglish,Sort(p_head,i,3),ClassSort(p_head,i,3));
		printf("|רҵ�ɼ�:%d Ժϵ����:%d �༶����:%d\n",p_temp->m_nComputer,Sort(p_head,i,4),ClassSort(p_head,i,4));
		printf("|�ܳɼ�:%d   Ժϵ����:%d �༶����:%d\n\n",p_temp->m_nComputer+p_temp->m_nEnglish+p_temp->m_nChinese+p_temp->m_nMath,Sort(p_head,i,5),ClassSort(p_head,i,5));
		i=i+1;
	    p_temp=p_temp->m_pNext;
	}
}


void Del(Stu *p_head)
{   if(p_head == NULL)
    {
    	printf("WRONG:δ���г�ʼ����\n");
    	return;	 
    }
    int n_ID;
    printf("����������ɾ���ı�ı�ţ�");
    scanf("%d",&n_ID);
	free(Search(n_ID,p_head));  //�ͷ��ڴ�ռ� 
    Stu *p_temp1=Search(n_ID-1,p_head);   //ɾ�����ǰ����� 
    Stu *p_temp2=Search(n_ID+1,p_head);  
    p_temp1->m_pNext = p_temp2;
    while(p_temp2)
    {
    	p_temp2->m_nSign = (p_temp2->m_nSign)-1;
    	p_temp2 = p_temp2->m_pNext;
	}    	
	printf("(��ʾ��ɾ���ɹ�)");
}


int ClassSort(Stu *p_head,int n_ID,int n_subject)   //ͬsort���ƣ�ֻ���ж��˰༶�Ƿ���ͬ 
{   
    Stu *p_thisStudent=Search(n_ID,p_head);
    int num;
	int i = 1;
	int sum = 0;
    if(n_subject == 1)
    {
    	num = p_thisStudent->m_nMath;
    	while(Search(i,p_head))
    	{
    	if(num <= Search(i,p_head)->m_nMath && strcmp(p_thisStudent->m_strClass,Search(i,p_head)->m_strClass) == 0)
		{
		sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
	if(n_subject == 2)
	{
		num = p_thisStudent->m_nChinese;
    	while(Search(i,p_head))
    	{
    	if(num <= Search(i,p_head)->m_nChinese && strcmp(p_thisStudent->m_strClass,Search(i,p_head)->m_strClass) == 0)
		{
		sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
	if(n_subject == 3)
	{
		num = p_thisStudent->m_nEnglish;
    	while(Search(i,p_head))
    	{
    	if(num <= Search(i,p_head)->m_nEnglish && strcmp(p_thisStudent->m_strClass,Search(i,p_head)->m_strClass) == 0)
		{
		sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
	if(n_subject == 4)
	{
		num = p_thisStudent->m_nComputer;
    	while(Search(i,p_head))
    	{
    	if(num <= Search(i,p_head)->m_nComputer && strcmp(p_thisStudent->m_strClass,Search(i,p_head)->m_strClass) == 0)
		{
		sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
	if(n_subject == 5)
	{
		num = p_thisStudent->m_nComputer+p_thisStudent->m_nEnglish+p_thisStudent->m_nChinese+p_thisStudent->m_nMath;
    	while(Search(i,p_head))
    	{
    	int n_sumScore = Search(i,p_head)->m_nComputer+Search(i,p_head)->m_nEnglish+Search(i,p_head)->m_nChinese+Search(i,p_head)->m_nMath;
    	if(num <= n_sumScore && strcmp(p_thisStudent->m_strClass,Search(i,p_head)->m_strClass) == 0)
		{
		sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
 } 
 
 void Change(Stu *p_head)
{   if(p_head == NULL)
    {
    	printf("WRONG:δ���г�ʼ����\n");
    	return;	 
    }
    if(p_head == NULL)
    {
    	printf("WRONG:�ռ����ʧ��\n");
    	exit(-1);	 
    }
    char c_value[20];
    int n_ID;
    printf("�����������޸ĵı�ı�ţ�");
    scanf("%d",&n_ID);
	Stu *p_temp = Search(n_ID,p_head);    //ͨ������������λ�� 
	printf("��ѡ�������޸ĵ�ֵ��A:������B:�꼶��C:�༶��D:��ѧ�ɼ���E:���ĳɼ���F:Ӣ��ɼ���G:רҵ�ɼ�����");  
	scanf("%s",c_value);
	printf("���������޸ĺ�����ݣ�");
	if(strcmp(c_value,"A") == 0)
	    {
		scanf("%s",p_temp->m_strName);
	    printf("(��ʾ���޸ĳɹ���)");
	    } 
	else if(strcmp(c_value,"B") == 0)
	    {
		scanf("%s",p_temp->m_strGrade);
	    printf("(��ʾ���޸ĳɹ���)");
	    } 
    else if(strcmp(c_value,"C") == 0)
	    {
		scanf("%s",p_temp->m_strClass);
	    printf("(��ʾ���޸ĳɹ���)");
	    } 
	else if (strcmp(c_value,"D") == 0)
		{
		scanf("%d",&p_temp->m_nMath);
		printf("(��ʾ���޸ĳɹ���)");
		} 
	else if (strcmp(c_value,"E") == 0)
		{
		scanf("%d",&p_temp->m_nChinese);
		printf("(��ʾ���޸ĳɹ���)");
		} 
	else if (strcmp(c_value,"F") == 0)
		{
		scanf("%d",&p_temp->m_nEnglish);
		printf("(��ʾ���޸ĳɹ���)");
		} 
	else if (strcmp(c_value,"G") == 0)
		{
		scanf("%d",&p_temp->m_nComputer);
		printf("(��ʾ���޸ĳɹ���)");
		} 
	else 
	    printf("(��ʾ��û���������)");   
}


void Add(Stu *p_head)
{   if(p_head == NULL)
    {
    	printf("WRONG:δ���г�ʼ����\n");
    	return;	 
    }
    if(p_head == NULL)
    {
    	printf("WRONG:�ռ����ʧ��\n");
    	exit(-1);	 
    }
	int n;
	printf("������������ӵı��λ�ã�����0����ڿ�ͷ������1�����1-2֮��,�Դ����ƣ�:");
	scanf("%d",&n);
	Stu *p_new = (Stu *)malloc(sizeof(Stu));   //�����½�� 
	if(p_new == NULL)
    {
    	printf("WRONG:�ռ����ʧ��\n");
    	exit(-1);	 
    }
	printf("����������:\n");
	printf("����(%d):",n+1);
	scanf("%s",p_new->m_strName);
	printf("�꼶(%d):",n+1);
	scanf("%s",p_new->m_strGrade);
	printf("�༶(%d):",n+1);
	scanf("%s",p_new->m_strClass);
	printf("��ѧ�ɼ�(%d):",n+1);
	scanf("%d",&p_new->m_nMath);
	printf("���ĳɼ�(%d):",n+1);
	scanf("%d",&p_new->m_nChinese);
	printf("Ӣ��ɼ�(%d):",n+1);
	scanf("%d",&p_new->m_nEnglish);
	printf("רҵ�ɼ�(%d):",n+1);
	scanf("%d",&p_new->m_nComputer);
	Stu *p_temp1 = Search(n,p_head);    //�����½�����λ�õ�ǰ���� 
    Stu *p_temp2 = Search(n+1,p_head);
    Stu *p_temp = Search(n+1,p_head);
    while(p_temp)
    {
    	p_temp->m_nSign++;      //�Ժ�������ż�һ 
    	p_temp = p_temp->m_pNext;
	}
	p_temp1->m_pNext = p_new;    //���������ǰһ���ָ���½�㣬���½��ָ���һ��㣬��ɹ��� 
	p_new->m_pNext = p_temp2;
	p_new->m_nSign = n+1; 
}	 
