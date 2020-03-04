//��������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sys.h"
//ϵͳ�������� 
void Mainmenu(Stu *p_head)  //���˵���ʾ���� 
{
     printf("��ӭ����ѧ������ϵͳ\n��ѡ��������:A:ѧ�� B:ϵͳ����Ա:");
	 Maininput(p_head);
} 

void Maininput(Stu *p_head)  //���˵����뺯������ 
{
    char choice[999];
	scanf("%s",choice);
	if(strcmp(choice,"A")==0)
	{   while(1)
		{
			Studentmenu(p_head); 
		}
	} 
	else if(strcmp(choice,"B")==0)
	{   while(1)
		{
			Adminmenu(p_head);
		}
		
	}
	else
	{
		printf("û�����������������ѡ��\n"); 
	}
} 

void Studentmenu(Stu *p_head)  //ѧ���˵���ʾ���� 
{
	printf("(Ȩ��:ѧ��)��������Ҫ���еĲ���\nA:�������ѧ����Ϣ B:����ѧ�� C:����������ϲ������ѧ������:"); 
	Studentinput(p_head);
}

void Studentinput(Stu *p_head)   //ѧ���˵����뺯��
{   char choice[999];
	scanf("%s",choice);
	if(strcmp(choice,"A")==0)
	{
		Display(p_head);
	}
	else if(strcmp(choice,"B")==0)
	{   char name[999]; 
	    printf("��������Ҫ����ѧ������:");
	    scanf("%s",name);
		Search(p_head,name);
	}
	else if(strcmp(choice,"C")==0)
	{   
	    NoPass(p_head); 
	}
	else
	{
		printf("û�����������������ѡ��\n"); 
	}
} 

void Adminmenu(Stu *p_head)  //����Ա�˵���ʾ���� 
{
	printf("(Ȩ��:����Ա)��������Ҫ���еĲ���\nA:�������ѧ����Ϣ B:����ѧ�� C:ɾ��ѧ�� D:���ѧ�� E:�޸�ѧ����Ϣ F:����������ϲ������ѧ������ G:ѧ�����Ƴɼ�¼��:"); 
	Admininput(p_head);
}
 

void Admininput(Stu *p_head)   //����Ա�˵����뺯��
{   char choice[999];
	scanf("%s",choice);
	if(strcmp(choice,"A")==0)
	{
		Display(p_head);
	}
	else if(strcmp(choice,"B")==0)
	{   char name[999]; 
	    printf("��������Ҫ����ѧ������:");
	    scanf("%s",name);
		Search(p_head,name);
	}
	else if(strcmp(choice,"C")==0)
	{   int n_ID ;
	    printf("��������Ҫɾ����ѧ���ı��:");
	    if(scanf("%d",&n_ID)!=1)
		{
		printf("��ʾ����û��������ȷ��Ż��߱�����ݹ��������\n");
		while(getchar()!='\n');
	    }
		else 
		{
		Del(p_head,n_ID);
	    printf("��ʾ��ɾ���ɹ�\n"); 
	    SaveFile(p_head); 
	    }
	}
	else if(strcmp(choice,"D")==0)
	{   
	    AddList(p_head); 
	    SaveFile(p_head);
	}
	else if(strcmp(choice,"E")==0)
	{   
	    Change(p_head);
		SaveFile(p_head); 
	}
	else if(strcmp(choice,"F")==0)
	{   
	    NoPass(p_head); 
	}
	else if(strcmp(choice,"G")==0)
	{   int start;
	    int end;
	    char subject[999];
	    printf("��������ʼλ�ñ��:");
	    if(scanf("%d",&start)!=1)
		{
		printf("��ʾ����û��������ȷ��Ż��߱�����ݹ��������\n");
		while(getchar()!='\n');
		return;
	    }
	    Stu *temp1=SearchItem(start , p_head);
        if(temp1==NULL || temp1->m_nSign==0)
        {
   	    	printf("��ʾ����ʼλ�ô���\n");
   	  		return;	
   		}
	    printf("�������յ�λ�ñ��:");
	    if(scanf("%d",&end)!=1)
		{
		printf("��ʾ����û��������ȷ��Ż��߱�����ݹ��������\n");
		while(getchar()!='\n');
		return;
	    }
	    Stu *temp2=SearchItem(end ,p_head);
   		if(temp2==NULL || temp2->m_nSign==0 ||temp1->m_nSign>temp2->m_nSign)
   		{
   	  		printf("��ʾ���յ�λ�ô���\n");
   	  		return;
   		}
	    printf("��������Ҫ¼���ѧ��(A����ѧB������C��Ӣ��D��רҵ):");
	    scanf("%s",subject);
		InputScore(temp1,temp2,p_head,subject); 
		SaveFile(p_head);
	}
	else
	{
		printf("û�����������������ѡ��\n"); 
	}
} 




//���ܺ��� 
void Display(Stu *p_head)   //�������������,����ͷָ�� 
{   
    int i = 1;
	Stu *p_temp = NextItem(p_head);
	while(p_temp)
	{   
		printf("|���:%d ",p_temp->m_nSign);
		printf("|����:%s ",p_temp->m_strName);
		printf("|�༶:%s\n",p_temp->m_strClass);
		printf("|��ѧ�ɼ�:%s Ժϵ����:%d �༶����:%d\n",p_temp->m_nMath,Sort(p_head,i,1),ClassSort(p_head,i,1));
		printf("|���ĳɼ�:%s Ժϵ����:%d �༶����:%d\n",p_temp->m_nChinese,Sort(p_head,i,2),ClassSort(p_head,i,2));
		printf("|Ӣ��ɼ�:%s Ժϵ����:%d �༶����:%d\n",p_temp->m_nEnglish,Sort(p_head,i,3),ClassSort(p_head,i,3));
		printf("|רҵ�ɼ�:%s Ժϵ����:%d �༶����:%d\n",p_temp->m_nComputer,Sort(p_head,i,4),ClassSort(p_head,i,4));
		printf("|�ܳɼ�:%.1f Ժϵ����:%d �༶����:%d\n\n",Strtodouble(p_temp->m_nComputer)+Strtodouble(p_temp->m_nEnglish)+Strtodouble(p_temp->m_nChinese)+Strtodouble(p_temp->m_nMath),Sort(p_head,i,5),ClassSort(p_head,i,5));
		i=i+1;
	    p_temp=NextItem(p_temp);
	}
}

void InitSys(Stu *p_head)      //��ʼ��ѧ��ϵͳ�󣬹���Ա�������ݲ� 
{       Stu *p_temp = NextItem(p_head);
        while(p_temp)
        {
		printf("����ѧ����Ϣ(���:%d):\n",p_temp->m_nSign);   //�Խ��д������
		printf("����(���:%d):",p_temp->m_nSign);
		scanf("%s",p_temp->m_strName);
		printf("�༶(���:%d):",p_temp->m_nSign);
		scanf("%s",p_temp->m_strClass);
/*		printf("��ѧ�ɼ�(���:%d):",p_temp->m_nSign);
		scanf("%s",p_temp->m_nMath);
		while(Strtodouble(p_temp->m_nMath) == -1)
		{   
			printf("��ʾ:��������������(�ɼ�Ϊ0-100������),����������:"); 
			scanf("%s",p_temp->m_nMath);
		}
		printf("���ĳɼ�(���:%d):",p_temp->m_nSign);
		scanf("%s",p_temp->m_nChinese);
		while(Strtodouble(p_temp->m_nChinese) == -1)
		{   
			printf("��ʾ:��������������(�ɼ�Ϊ0-100������),����������:");
			scanf("%s",p_temp->m_nChinese);
		}
		printf("Ӣ��ɼ�(���:%d):",p_temp->m_nSign);
		scanf("%s",p_temp->m_nEnglish);
		while(Strtodouble(p_temp->m_nEnglish) == -1)
		{   
			printf("��ʾ:��������������(�ɼ�Ϊ0-100������),����������:");
			scanf("%s",p_temp->m_nEnglish);
		}
		printf("רҵ�ɼ�(���:%d):",p_temp->m_nSign);
		scanf("%s",p_temp->m_nComputer);
		while(Strtodouble(p_temp->m_nComputer) == -1)
		{   
			printf("��ʾ:��������������(�ɼ�Ϊ0-100������),����������:");
			scanf("%s",p_temp->m_nComputer);
		}
		*/
        p_temp = NextItem(p_temp);
        }
} 

void SaveFile(Stu *p_head)   //�����ļ� 
{   FILE *pf2; 
	if((pf2 = fopen("data.wwy","wb")) == NULL) 
	{
		exit(1);
	}
    Stu *p_temp = p_head;
	while(p_temp)
	{
	fwrite(p_temp,sizeof(struct Stu),1,pf2);  //����˵����1.Ҫд������ݵĵ�ַ��2.һ��Ҫд�����ֽڣ�3.д���ٴΣ�4.д������ 
	p_temp = NextItem(p_temp);
    }
	
	fclose(pf2);	
}
int Pow(int num,int n) //�������֣�������n�η� 
{ if(n == 1)
  return num;
  else
  return num*Pow(num,n-1);
} 


int Strtoint(char *str)    //����0-100���ַ����������ͺ����������������ַ������򷵻�-1
{
   int sum = 0;
   while(*str!='\0')
   {
   	sum = 10*sum + *str - '0';
   	str++;
   }
   if(sum >= 0 && sum <= 100)
   return sum;
   else
   return -1;
} 
double Strtodouble(char *str)  //����0-100���ַ�������double�ͺ����������������ַ������򷵻�-1
{   int i;
	int sign = 0;
	int len = strlen(str);
	if(str[0] == '.'||str[len-1] == '.')
	{
				return -1;
	}
	for(i=0;i<len;i++)
	{
		if(str[i]<'0' || str[i]>'9')
		{
			if(str[i]!='.')
			{
				return -1;
			}
			if(str[i]=='.')
			{
				sign=sign+1;
				if(sign>1)
				{
					return -1;
				}
			}
		}
	}
    if (atof(str)<0.0 || atof(str)>100.0)
	{
		return -1;
	}
	else
	{
		return atof(str);
	}
}


void Search(Stu *p_head,char *name)     //����ѧ����Ϣ������ͷָ�룬����ѧ������ 
{   Stu *p_temp = NextItem(p_head);
    int i = 1;
    int sign=0;
    while(p_temp)
    {
	if(strcmp(name,p_temp->m_strName)==0)
	{   sign=1;
		printf("|���:%d ",p_temp->m_nSign);
		printf("|����:%s ",p_temp->m_strName);
		printf("|�༶:%s\n ",p_temp->m_strClass);
		printf("|��ѧ�ɼ�:%s Ժϵ����:%d �༶����:%d\n",p_temp->m_nMath,Sort(p_head,i,1),ClassSort(p_head,i,1));
		printf("|���ĳɼ�:%s Ժϵ����:%d �༶����:%d\n",p_temp->m_nChinese,Sort(p_head,i,2),ClassSort(p_head,i,2));
		printf("|Ӣ��ɼ�:%s Ժϵ����:%d �༶����:%d\n",p_temp->m_nEnglish,Sort(p_head,i,3),ClassSort(p_head,i,3));
		printf("|רҵ�ɼ�:%s Ժϵ����:%d �༶����:%d\n",p_temp->m_nComputer,Sort(p_head,i,4),ClassSort(p_head,i,4));
		printf("|�ܳɼ�:%d   Ժϵ����:%d �༶����:%d\n\n",Strtodouble(p_temp->m_nComputer)+Strtodouble(p_temp->m_nEnglish)+Strtodouble(+p_temp->m_nChinese)+Strtodouble(p_temp->m_nMath),Sort(p_head,i,5),ClassSort(p_head,i,5));
	}
	p_temp = NextItem(p_temp);
	i=i+1;
	}
	if(sign == 0)
	{
		printf("��ʾ���޴�ѧ��\n");
	}
	
}


void Del(Stu *p_head,int n_ID)    //ɾ��������ͷָ�룬����ɾ��ѧ����� 
{   if(SearchItem(n_ID,p_head)==NULL)
    {
    	printf("��ʾ��û��������\n");
	}
	else
	{
	free(SearchItem(n_ID,p_head));  //�ͷ��ڴ�ռ� 
    Stu *p_temp1=SearchItem(n_ID-1,p_head);   //ɾ�����ǰ����� 
    Stu *p_temp2=SearchItem(n_ID+1,p_head);  
    p_temp1->m_pNext = p_temp2;
    while(p_temp2)
    {
    	p_temp2->m_nSign = (p_temp2->m_nSign)-1;
    	p_temp2 = p_temp2->m_pNext;
	}   
			
    }
}


int Sort(Stu *p_head,int n_ID,int n_subject)   //Ժϵ������������ͷָ�롢ѧ����š���Ҫ�������������� 
{
    Stu *p_thisStudent=SearchItem(n_ID,p_head);
    int num;
	int i = 1;
	int sum = 1;
    if(n_subject == 1)   //��Search()������ÿһ�����ñ������ֵ���м����������ȱ���������ֵ��ʱsum+1
    {
    	num = Strtodouble(p_thisStudent->m_nMath);
    	while(SearchItem(i,p_head))
    	{
    	if(num < Strtodouble(SearchItem(i,p_head)->m_nMath))
		{
			if(SearchItem(i,p_head) != p_thisStudent)
		    	sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
	if(n_subject == 2)
	{
		num = Strtodouble(p_thisStudent->m_nChinese);
    	while(SearchItem(i,p_head))
    	{
    	if(num < Strtodouble(SearchItem(i,p_head)->m_nChinese))
		{
			if(SearchItem(i,p_head) != p_thisStudent)
		    	sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
	if(n_subject == 3)
	{
		num = Strtodouble(p_thisStudent->m_nEnglish);
    	while(SearchItem(i,p_head))
    	{
    	if(num < Strtodouble(SearchItem(i,p_head)->m_nEnglish))
		{
			if(SearchItem(i,p_head) != p_thisStudent)
		    	sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
	if(n_subject == 4)
	{
		num = Strtodouble(p_thisStudent->m_nComputer);
    	while(SearchItem(i,p_head))
    	{
    	if(num < Strtodouble(SearchItem(i,p_head)->m_nComputer))
		{
			if(SearchItem(i,p_head) != p_thisStudent)
		    	sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
	if(n_subject == 5)
	{
		num = Strtodouble(p_thisStudent->m_nComputer)+Strtodouble(p_thisStudent->m_nEnglish)+Strtodouble(p_thisStudent->m_nChinese)+Strtodouble(p_thisStudent->m_nMath);
    	while(SearchItem(i,p_head))
    	{
    	int n_sumScore = Strtodouble(SearchItem(i,p_head)->m_nComputer)+Strtodouble(SearchItem(i,p_head)->m_nEnglish)+Strtodouble(SearchItem(i,p_head)->m_nChinese)+Strtodouble(SearchItem(i,p_head)->m_nMath);
    	if(num < n_sumScore)
		{
			if(SearchItem(i,p_head) != p_thisStudent)
		    	sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
 } 
 
 int ClassSort(Stu *p_head,int n_ID,int n_subject)   //�༶����������ͷָ�롢ѧ����š���Ҫ�������������� 
{
    Stu *p_thisStudent=SearchItem(n_ID,p_head);
    int num;
	int i = 1;
	int sum = 1;
    if(n_subject == 1)   //��Search()������ÿһ�����ñ������ֵ���м����������ȱ���������ֵ��ʱsum+1
    {
    	num = Strtodouble(p_thisStudent->m_nMath);
    	while(SearchItem(i,p_head))
    	{
    	if(num < Strtodouble(SearchItem(i,p_head)->m_nMath) && strcmp(p_thisStudent->m_strClass,SearchItem(i,p_head)->m_strClass) == 0)
		{
			if(SearchItem(i,p_head) != p_thisStudent)
		    	sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
	if(n_subject == 2)
	{
		num = Strtodouble(p_thisStudent->m_nChinese);
    	while(SearchItem(i,p_head))
    	{
    	if(num < Strtodouble(SearchItem(i,p_head)->m_nChinese) && strcmp(p_thisStudent->m_strClass,SearchItem(i,p_head)->m_strClass) == 0)
		{
			if(SearchItem(i,p_head) != p_thisStudent)
		    	sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
	if(n_subject == 3)
	{
		num = Strtodouble(p_thisStudent->m_nEnglish);
    	while(SearchItem(i,p_head))
    	{
    	if(num < Strtodouble(SearchItem(i,p_head)->m_nEnglish) && strcmp(p_thisStudent->m_strClass,SearchItem(i,p_head)->m_strClass) == 0)
		{
			if(SearchItem(i,p_head) != p_thisStudent)
		    	sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
	if(n_subject == 4)
	{
		num = Strtodouble(p_thisStudent->m_nComputer);
    	while(SearchItem(i,p_head))
    	{
    	if(num < Strtodouble(SearchItem(i,p_head)->m_nComputer) && strcmp(p_thisStudent->m_strClass,SearchItem(i,p_head)->m_strClass) == 0)
		{
			if(SearchItem(i,p_head) != p_thisStudent)
		    	sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
	if(n_subject == 5)
	{
		num = Strtodouble(p_thisStudent->m_nComputer)+Strtodouble(p_thisStudent->m_nEnglish)+Strtodouble(p_thisStudent->m_nChinese)+Strtodouble(p_thisStudent->m_nMath);
    	while(SearchItem(i,p_head))
    	{
    	int n_sumScore = Strtodouble(SearchItem(i,p_head)->m_nComputer)+Strtodouble(SearchItem(i,p_head)->m_nEnglish)+Strtodouble(SearchItem(i,p_head)->m_nChinese)+Strtodouble(SearchItem(i,p_head)->m_nMath);
    	if(num < n_sumScore && strcmp(p_thisStudent->m_strClass,SearchItem(i,p_head)->m_strClass) == 0)
		{
			if(SearchItem(i,p_head) != p_thisStudent)
		    	sum = sum+1;
		}	
		i = i+1;
		}
		return sum;
	}
 } 
 
void AddList(Stu *p_head)    //β�������ͬѧ 
{   Stu *temp=p_head;
	
	while(temp->m_pNext)
    {
	 temp=NextItem(temp);
    } 
	AddItem(temp);
	temp=NextItem(temp);
	printf("����ѧ����Ϣ(���:%d):\n",temp->m_nSign);   //�Խ��д������
	printf("����(���:%d):",temp->m_nSign);
	scanf("%s",temp->m_strName);
	printf("�༶(���:%d):",temp->m_nSign);
	scanf("%s",temp->m_strClass);
}

void Change(Stu *p_head)   //�޸� 
{   
    char c_value[999];
    int n_ID;
    printf("�����������޸ĵ�ѧ����Ϣ�ı�ţ�");
    scanf("%d",&n_ID);
	Stu *p_temp = SearchItem(n_ID,p_head);    //ͨ������������λ�� 
	printf("��ѧ����Ϣ\n");
	printf("|���:%d ",p_temp->m_nSign);
	printf("|����:%s ",p_temp->m_strName);
	printf("|�༶:%s\n",p_temp->m_strClass);
	printf("|��ѧ�ɼ�:%s Ժϵ����:%d �༶����:%d\n",p_temp->m_nMath,Sort(p_head,n_ID,1),ClassSort(p_head,n_ID,1));
	printf("|���ĳɼ�:%s Ժϵ����:%d �༶����:%d\n",p_temp->m_nChinese,Sort(p_head,n_ID,2),ClassSort(p_head,n_ID,2));
	printf("|Ӣ��ɼ�:%s Ժϵ����:%d �༶����:%d\n",p_temp->m_nEnglish,Sort(p_head,n_ID,3),ClassSort(p_head,n_ID,3));
	printf("|רҵ�ɼ�:%s Ժϵ����:%d �༶����:%d\n",p_temp->m_nComputer,Sort(p_head,n_ID,4),ClassSort(p_head,n_ID,4));
	printf("|�ܳɼ�:%.1f Ժϵ����:%d �༶����:%d\n\n",Strtodouble(p_temp->m_nComputer)+Strtodouble(p_temp->m_nEnglish)+Strtodouble(p_temp->m_nChinese)+Strtodouble(p_temp->m_nMath),Sort(p_head,n_ID,5),ClassSort(p_head,n_ID,5));
	printf("��ѡ�������޸ĵ���Ϣ��A:������B:�༶��C:��ѧ�ɼ���D:���ĳɼ���E:Ӣ��ɼ���F:רҵ�ɼ�����");  
	scanf("%s",c_value);
	printf("���������޸ĺ�����ݣ�");
	if(strcmp(c_value,"A") == 0)
	    {
		scanf("%s",p_temp->m_strName);
	    printf("(��ʾ���޸ĳɹ���)");
	    } 
    else if(strcmp(c_value,"B") == 0)
	    {
		scanf("%s",p_temp->m_strClass);
	    printf("(��ʾ���޸ĳɹ���)");
	    } 
	else if (strcmp(c_value,"C") == 0)
		{
		scanf("%s",&p_temp->m_nMath);
		printf("(��ʾ���޸ĳɹ���)");
		} 
	else if (strcmp(c_value,"D") == 0)
		{
		scanf("%s",&p_temp->m_nChinese);
		printf("(��ʾ���޸ĳɹ���)");
		} 
	else if (strcmp(c_value,"E") == 0)
		{
		scanf("%s",&p_temp->m_nEnglish);
		printf("(��ʾ���޸ĳɹ���)");
		} 
	else if (strcmp(c_value,"F") == 0)
		{
		scanf("%s",&p_temp->m_nComputer);
		printf("(��ʾ���޸ĳɹ���)");
		} 
	else 
	    printf("��ʾ��û���������");   
}

void NoPass(Stu *p_head)   //����ͷָ�룬������в������Ŀ����2�Ƶ�ѧ������
{   int i = 1;
	Stu *p_temp = NextItem(p_head);
	int sum = 0;
	while(p_temp)   //�жϲ����� 
	{
		if(Strtodouble(p_temp->m_nMath) < 60)
		{
			sum = sum+1;
		}
		if(Strtodouble(p_temp->m_nEnglish) < 60)
		{
			sum = sum+1;
		}
		if(Strtodouble(p_temp->m_nChinese) < 60)
		{
			sum = sum+1;
		}
		if(Strtodouble(p_temp->m_nComputer) < 60)
		{
			sum = sum+1;
		}
		if(sum >= 2)
		{
			printf("|���:%d ",p_temp->m_nSign);
		    printf("|����:%s ",p_temp->m_strName);
		    printf("|�༶:%s\n",p_temp->m_strClass);
			printf("|��ѧ�ɼ�:%s Ժϵ����:%d �༶����:%d\n",p_temp->m_nMath,Sort(p_head,i,1),ClassSort(p_head,i,1));
			printf("|���ĳɼ�:%s Ժϵ����:%d �༶����:%d\n",p_temp->m_nChinese,Sort(p_head,i,2),ClassSort(p_head,i,2));
			printf("|Ӣ��ɼ�:%s Ժϵ����:%d �༶����:%d\n",p_temp->m_nEnglish,Sort(p_head,i,3),ClassSort(p_head,i,3));
			printf("|רҵ�ɼ�:%s Ժϵ����:%d �༶����:%d\n",p_temp->m_nComputer,Sort(p_head,i,4),ClassSort(p_head,i,4));
			printf("|�ܳɼ�:%.1f Ժϵ����:%d �༶����:%d\n\n",Strtodouble(p_temp->m_nComputer)+Strtodouble(p_temp->m_nEnglish)+Strtodouble(p_temp->m_nChinese)+Strtodouble(p_temp->m_nMath),Sort(p_head,i,5),ClassSort(p_head,i,5));
		}
		i=i+1;
		p_temp=NextItem(p_temp);
		sum=0;
	}
}

void InputScore(Stu *start , Stu *end , Stu *p_head ,char *subject)    //����ѧϰ�ɼ�¼�룬���뿪ʼ¼��λ�úͽ���¼��λ�ã�����ͷָ�� ,������Ҫ¼���ѧ�� 
{
   
   Stu *temp = start;
   
        if(strcmp(subject,"A")==0)
        {   while(temp != NextItem(end))
            {
	    		printf("%s����ѧ�ɼ�(���:%d)ԭΪ%s�֣��ָ�Ϊ:",temp->m_strName,temp->m_nSign,temp->m_nMath);
				scanf("%s",temp->m_nMath);
				while(Strtodouble(temp->m_nMath) == -1)
					{	   
						printf("��ʾ:��������������(�ɼ�Ϊ0-100������),����������:"); 
						scanf("%s",temp->m_nMath);
					}
				temp=NextItem(temp);
		   	} 
   		}
   		else if(strcmp(subject,"B")==0)
        {   while(temp != NextItem(end))
            {
	    		printf("%s�����ĳɼ�(���:%d)ԭΪ%s�֣��ָ�Ϊ:",temp->m_strName,temp->m_nSign,temp->m_nChinese);
				scanf("%s",temp->m_nChinese);
				while(Strtodouble(temp->m_nChinese) == -1)
					{	   
						printf("��ʾ:��������������(�ɼ�Ϊ0-100������),����������:"); 
						scanf("%s",temp->m_nChinese);
					}
				temp=NextItem(temp);
		   	} 
   		}
   		else if(strcmp(subject,"C")==0)
        {   while(temp != NextItem(end))
            {
	    		printf("%s��Ӣ��ɼ�(���:%d)ԭΪ%s�֣��ָ�Ϊ:",temp->m_strName,temp->m_nSign,temp->m_nEnglish);
				scanf("%s",temp->m_nMath);
				while(Strtodouble(temp->m_nEnglish) == -1)
					{	   
						printf("��ʾ:��������������(�ɼ�Ϊ0-100������),����������:"); 
						scanf("%s",temp->m_nEnglish);
					}
				temp=NextItem(temp);
		   	} 
   		}
   		else if(strcmp(subject,"D")==0)
        {   while(temp != NextItem(end))
            {
	    		printf("%s��רҵ�ɼ�(���:%d)ԭΪ%s�֣��ָ�Ϊ:",temp->m_strName,temp->m_nSign,temp->m_nComputer);
				scanf("%s",temp->m_nComputer);
				while(Strtodouble(temp->m_nComputer) == -1)
					{	   
						printf("��ʾ:��������������(�ɼ�Ϊ0-100������),����������:"); 
						scanf("%s",temp->m_nComputer);
					}
				temp=NextItem(temp);
		   	} 
   		}
   		else
   		{
   			 printf("��ʾ:�޴˹���:"); 
		}
}
 
/*
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
	printf("��ѡ�������޸ĵ�ֵ��A:������B:�༶��C:��ѧ�ɼ���D:���ĳɼ���E:Ӣ��ɼ���F:רҵ�ɼ�����");  
	scanf("%s",c_value);
	printf("���������޸ĺ�����ݣ�");
	if(strcmp(c_value,"A") == 0)
	    {
		scanf("%s",p_temp->m_strName);
	    printf("(��ʾ���޸ĳɹ���)");
	    } 
    else if(strcmp(c_value,"B") == 0)
	    {
		scanf("%s",p_temp->m_strClass);
	    printf("(��ʾ���޸ĳɹ���)");
	    } 
	else if (strcmp(c_value,"C") == 0)
		{
		scanf("%d",&p_temp->m_nMath);
		printf("(��ʾ���޸ĳɹ���)");
		} 
	else if (strcmp(c_value,"D") == 0)
		{
		scanf("%d",&p_temp->m_nChinese);
		printf("(��ʾ���޸ĳɹ���)");
		} 
	else if (strcmp(c_value,"E") == 0)
		{
		scanf("%d",&p_temp->m_nEnglish);
		printf("(��ʾ���޸ĳɹ���)");
		} 
	else if (strcmp(c_value,"F") == 0)
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
*/ 
