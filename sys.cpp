//��������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sys.h"
//ϵͳ�������� 
void Mainmenu(Stu *p_head)  //���˵���ʾ���� 
{
     printf("��ѡ��������:A:ѧ�� B:ϵͳ����Ա:");
	 Maininput(p_head);
} 

void Maininput(Stu *p_head)  //���˵����뺯������ 
{
    char choice[999]= "\0";  //�ַ������ʼ��\0
	gets(choice);//fgets(choice,998,stdin); �������ո� 
	//while(getchar()!='\n');
	if(strcmp(choice,"A")==0)
	{   
			Studentmenu(p_head); 
	} 
	else if(strcmp(choice,"B")==0)
	{   
			char admin[999]= "\0";
            printf("���������Ա�ܳף�");
        	gets(admin);
    		if(strcmp(admin,"123")==0)
			{
			Adminmenu(p_head); 
			}
			else
	    	{   
	    	printf("��ʾ���ܳ״���\n");
			return;
			}
	}
	else
	{
		printf("û�����������������ѡ��\n"); 
	}
} 

void Studentmenu(Stu *p_head)  //ѧ���˵���ʾ���� 
{   while(1)
	{
	printf("    ���ܲ˵�\nA:�������ѧ����Ϣ \nB:����ѧ�� \nC:����������ϲ������ѧ������ \nD:����Ϊ�ļ� \nE:����༶�������� \nF:����Ȩ��Ϊ����Ա \n(Ȩ��:ѧ��)��������Ҫ���еĲ���:"); 
	Studentinput(p_head);
	}
}

void Studentinput(Stu *p_head)   //ѧ���˵����뺯��
{   char choice[999]="\0";
	gets(choice);
	if(strcmp(choice,"A")==0)
	{
		Display(p_head);
	}
	else if(strcmp(choice,"B")==0)
	{   char name[999]="\0"; 
	    printf("��������Ҫ����ѧ������:");
	    gets(name);
		Search(p_head,name);
	}
	else if(strcmp(choice,"C")==0)
	{   
	    NoPass(p_head); 
	}
	else if(strcmp(choice,"D")==0)
	{   
	    Fprint(p_head); 
	}
	else if(strcmp(choice,"E")==0)
	{   printf("������༶:");
	    char str_class[999]="\0";
	    char str_subject[999]="\0"; 
		gets(str_class); 
		printf("��������Ҫ������ѧ��(A����ѧB������C��Ӣ��D��רҵ):");
	    gets(str_subject);
	    if(strcmp(str_subject,"A")==0) 
	    ClassSortOutput(p_head,str_class,1); 
	    else if(strcmp(str_subject,"B")==0)
	    ClassSortOutput(p_head,str_class,2); 
	    else if(strcmp(str_subject,"C")==0)
	    ClassSortOutput(p_head,str_class,3); 
	    else if(strcmp(str_subject,"D")==0)
	    ClassSortOutput(p_head,str_class,4); 
	    else
	    printf("��ʾ��û�����ѧ��\n"); 
	}
	else if(strcmp(choice,"F")==0)
	{   char admin[999];
        printf("���������Ա�ܳף�");
        gets(admin);
    	if(strcmp(admin,"123")==0)
		{
		Adminmenu(p_head); 
		}
		else
	    {   
	    printf("��ʾ���ܳ״���\n");
		return;
	    }
	} 
	else
	{
		printf("û�����������������ѡ��\n"); 
	}
} 

void Adminmenu(Stu *p_head)  //����Ա�˵���ʾ���� 
{   while(1)
    { 
	printf("    ���ܲ˵�\nA:�������ѧ����Ϣ \nB:����ѧ�� \nC:ɾ��ѧ�� \nD:���ѧ�� \nE:�޸�ѧ����Ϣ \nF:����������ϲ������ѧ������ \nG:ѧ�����Ƴɼ�¼�� \nH:����Ϊ�ļ� \nI:����༶�������� \n(Ȩ��:����Ա)��������Ҫ���еĲ���:"); 
	Admininput(p_head);
	}	
}
 

void Admininput(Stu *p_head)   //����Ա�˵����뺯��
{   char choice[999]="\0";
	gets(choice);
	if(strcmp(choice,"A")==0)
	{
		Display(p_head);
	}
	else if(strcmp(choice,"B")==0)
	{   char name[999]="\0"; 
	    printf("��������Ҫ����ѧ������:");
	    gets(name);
		Search(p_head,name);
	}
	else if(strcmp(choice,"C")==0)
	{   int n_ID ;
	    printf("��������Ҫɾ����ѧ���ı��:");
	    if(scanf("%d",&n_ID)!=1)
		{
		printf("��ʾ����û��������ȷ���\n");
		fflush(stdin);//while(getchar()!='\n');
	    }
		else 
		{
		fflush(stdin);
		Del2(p_head,n_ID);
	    //printf("��ʾ��ɾ���ɹ�\n"); 
	    
	    SaveFile(p_head); 
	    }
	}
	else if(strcmp(choice,"D")==0)
	{   int num,num1;
	    printf("��������Ҫ���ѧ��������:");
	    if(scanf("%d",&num)!=1)
		{
		printf("��ʾ����û��������ȷ����\n");
		fflush(stdin);
	    } 
	    fflush(stdin);
	    num1=num; 
	    while(num)
	    {
	    printf("��ʾ���㵱ǰ������ӵ�%d��ѧ��\n",num1-num+1);
		AddList(p_head); 
		num--;
		}  
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
		printf("��ʾ����û��������ȷ���\n");
		fflush(stdin);
		return;
	    }
	    fflush(stdin);
	    Stu *temp1=SearchItem(start , p_head);
        if(temp1==NULL || temp1->m_nSign==0)
        {
   	    	printf("��ʾ����ʼλ�ô���\n");
   	  		return;	
   		}
	    printf("�������յ�λ�ñ��:");
	    if(scanf("%d",&end)!=1)
		{
		printf("��ʾ����û��������ȷ���\n");
		fflush(stdin);
		return;
	    }
	    fflush(stdin);   //��������� 
	    Stu *temp2=SearchItem(end ,p_head);
   		if(temp2==NULL || temp2->m_nSign==0 ||temp1->m_nSign>temp2->m_nSign)
   		{
   	  		printf("��ʾ���յ�λ�ô���\n");
   	  		return;
   		}
	    printf("��������Ҫ¼���ѧ��(A����ѧB������C��Ӣ��D��רҵ):");
	    gets(subject);
		InputScore(temp1,temp2,p_head,subject); 
		SaveFile(p_head);
	}
	else if(strcmp(choice,"H")==0)
	{   
	    Fprint(p_head); 
	}
	else if(strcmp(choice,"I")==0)
	{   printf("������༶:");
	    char str_class[999];
	    char str_subject[999]; 
		gets(str_class); 
		printf("��������Ҫ������ѧ��(A����ѧB������C��Ӣ��D��רҵ):");
	    gets(str_subject);
	    if(strcmp(str_subject,"A")==0) 
	    ClassSortOutput(p_head,str_class,1); 
	    else if(strcmp(str_subject,"B")==0)
	    ClassSortOutput(p_head,str_class,2); 
	    else if(strcmp(str_subject,"C")==0)
	    ClassSortOutput(p_head,str_class,3); 
	    else if(strcmp(str_subject,"D")==0)
	    ClassSortOutput(p_head,str_class,3); 
	    else
	    printf("��ʾ��û�����ѧ��\n"); 
	}
	else
	{
		printf("û�����������������ѡ��\n"); 
	}
} 




//���ܺ��� 
void ShowItem(Stu *p_list,Stu *p_head)  //����ָ�룬�����ѧ����Ϣ 
{        
        printf("|���:%d ",p_list->m_nSign);
		printf("|����:%s ",p_list->m_strName);
		printf("|�༶:%s\n",p_list->m_strClass);
		printf("|��ѧ�ɼ�:%-3s Ժϵ����:%-3d �༶����:%-3d\n",p_list->m_nMath,Sort(p_head,p_list->m_nSign,1),ClassSort(p_head,p_list->m_nSign,1));
		printf("|���ĳɼ�:%-3s Ժϵ����:%-3d �༶����:%-3d\n",p_list->m_nChinese,Sort(p_head,p_list->m_nSign,2),ClassSort(p_head,p_list->m_nSign,2));
		printf("|Ӣ��ɼ�:%-3s Ժϵ����:%-3d �༶����:%-3d\n",p_list->m_nEnglish,Sort(p_head,p_list->m_nSign,3),ClassSort(p_head,p_list->m_nSign,3));
		printf("|רҵ�ɼ�:%-3s Ժϵ����:%-3d �༶����:%-3d\n",p_list->m_nComputer,Sort(p_head,p_list->m_nSign,4),ClassSort(p_head,p_list->m_nSign,4));
		printf("|�ܳɼ�:%-5.1f Ժϵ����:%-3d �༶����:%-3d\n\n",Strtodouble(p_list->m_nComputer)+Strtodouble(p_list->m_nEnglish)+Strtodouble(p_list->m_nChinese)+Strtodouble(p_list->m_nMath),Sort(p_head,p_list->m_nSign,5),ClassSort(p_head,p_list->m_nSign,5));
 
} 

void Display(Stu *p_head)   //�������������,����ͷָ�� 
{   
	Stu *p_temp = NextItem(p_head);
	while(p_temp)
	{   
		ShowItem(p_temp,p_head);
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
        p_temp = NextItem(p_temp);
        }
        fflush(stdin);
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


int Strtoint(char *str)    //��������������ͺ����������������ַ������򷵻�-1
{
   int sum = 0;
   while(*str!='\0')
   {
   	sum = 10*sum + *str - '0';
   	str++;
   }
   if(sum >= 0)
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
    int sign=0;    //��¼�Ƿ���ѧ�� 
    while(p_temp)
    {
	if(strcmp(name,p_temp->m_strName)==0)
	{   sign=1;
		ShowItem(p_temp,p_head);
	}
	p_temp = NextItem(p_temp);
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
    	p_temp2 = NextItem(p_temp2);
	}   		
    }
}

void Del2(Stu *p_head,int n_ID)    //ɾ��������ͷָ�룬����ɾ��ѧ����� 
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
    	p_temp2 = NextItem(p_temp2);
	}   	
	printf("��ʾ��ɾ���ɹ�\n");	
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
	gets(temp->m_strName);
	printf("�༶(���:%d):",temp->m_nSign);
	gets(temp->m_strClass);
}

void Change(Stu *p_head)   //�޸� 
{   
    char c_value[999]="\0";
    int n_ID;
    printf("�����������޸ĵ�ѧ����Ϣ�ı�ţ�");
    //scanf("%d",&n_ID);
     if(scanf("%d",&n_ID)!=1)
	{
		printf("��ʾ����û��������ȷ���\n");
		fflush(stdin);//while(getchar()!='\n');
		return;
	}
	Stu *p_temp = SearchItem(n_ID,p_head);    //ͨ������������λ�� 
	if(p_temp == NULL)
	{
		printf("��ʾ��δ�ҵ�������\n");
		fflush(stdin);
		return; 
	}
	printf("    ��ѧ����Ϣ\n");
	ShowItem(p_temp,p_head);
	printf("��ѡ�������޸ĵ���Ϣ��A:������B:�༶��C:��ѧ�ɼ���D:���ĳɼ���E:Ӣ��ɼ���F:רҵ�ɼ�����"); 
	fflush(stdin); //�����س� 
	gets(c_value);
	
	if(strcmp(c_value,"A") == 0)
	    {
	    printf("���������޸ĺ�����ݣ�");
		gets(p_temp->m_strName);
	    printf("��ʾ���޸ĳɹ���\n");
	    } 
    else if(strcmp(c_value,"B") == 0)
	    {
	    printf("���������޸ĺ�����ݣ�");
		gets(p_temp->m_strClass);
	    printf("��ʾ���޸ĳɹ���\n");
	    } 
	else if (strcmp(c_value,"C") == 0)
		{
		printf("���������޸ĺ�����ݣ�");
		gets(p_temp->m_nMath);
		while(Strtodouble(p_temp->m_nMath) == -1)
		{	   
			printf("��ʾ:��������������(�ɼ�Ϊ0-100������),����������:"); 
			gets(p_temp->m_nMath);
		}
		printf("��ʾ���޸ĳɹ���\n");
		} 
	else if (strcmp(c_value,"D") == 0)
		{
		printf("���������޸ĺ�����ݣ�");
		gets(p_temp->m_nChinese);
		while(Strtodouble(p_temp->m_nChinese) == -1)
		{	   
			printf("��ʾ:��������������(�ɼ�Ϊ0-100������),����������:"); 
			gets(p_temp->m_nChinese);
		}
		printf("��ʾ���޸ĳɹ���\n");
		} 
	else if (strcmp(c_value,"E") == 0)
		{
		printf("���������޸ĺ�����ݣ�");	
		gets(p_temp->m_nEnglish);
		while(Strtodouble(p_temp->m_nEnglish) == -1)
		{	   
			printf("��ʾ:��������������(�ɼ�Ϊ0-100������),����������:"); 
			gets(p_temp->m_nEnglish);
		}
		printf("��ʾ���޸ĳɹ���\n");
		} 
	else if (strcmp(c_value,"F") == 0)
		{
		printf("���������޸ĺ�����ݣ�");
		gets(p_temp->m_nComputer);
		while(Strtodouble(p_temp->m_nComputer) == -1)
		{	   
			printf("��ʾ:��������������(�ɼ�Ϊ0-100������),����������:"); 
			gets(p_temp->m_nComputer);
		}
		printf("��ʾ���޸ĳɹ���\n");
		} 
	else 
	    printf("��ʾ��û���������\n");   
}

void NoPass(Stu *p_head)   //����ͷָ�룬������в������Ŀ����2�Ƶ�ѧ������
{   Stu *p_temp = NextItem(p_head);
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
		if(sum > 2)
		{
			ShowItem(p_temp,p_head);
		}
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
				gets(temp->m_nMath);
				while(Strtodouble(temp->m_nMath) == -1)
					{	   
						printf("��ʾ:��������������(�ɼ�Ϊ0-100������),����������:"); 
						gets(temp->m_nMath);
					}
				temp=NextItem(temp);
		   	} 
   		}
   		else if(strcmp(subject,"B")==0)
        {   while(temp != NextItem(end))
            {
	    		printf("%s�����ĳɼ�(���:%d)ԭΪ%s�֣��ָ�Ϊ:",temp->m_strName,temp->m_nSign,temp->m_nChinese);
				gets(temp->m_nChinese);
				while(Strtodouble(temp->m_nChinese) == -1)
					{	   
						printf("��ʾ:��������������(�ɼ�Ϊ0-100������),����������:"); 
						gets(temp->m_nChinese);
					}
				temp=NextItem(temp);
		   	} 
   		}
   		else if(strcmp(subject,"C")==0)
        {   while(temp != NextItem(end))
            {
	    		printf("%s��Ӣ��ɼ�(���:%d)ԭΪ%s�֣��ָ�Ϊ:",temp->m_strName,temp->m_nSign,temp->m_nEnglish);
				gets(temp->m_nEnglish);
				while(Strtodouble(temp->m_nEnglish) == -1)
					{	   
						printf("��ʾ:��������������(�ɼ�Ϊ0-100������),����������:"); 
						gets(temp->m_nEnglish);
					}
				temp=NextItem(temp);
		   	} 
   		}
   		else if(strcmp(subject,"D")==0)
        {   while(temp != NextItem(end))
            {
	    		printf("%s��רҵ�ɼ�(���:%d)ԭΪ%s�֣��ָ�Ϊ:",temp->m_strName,temp->m_nSign,temp->m_nComputer);
				gets(temp->m_nComputer);
				while(Strtodouble(temp->m_nComputer) == -1)
					{	   
						printf("��ʾ:��������������(�ɼ�Ϊ0-100������),����������:"); 
						gets(temp->m_nComputer);
					}
				temp=NextItem(temp);
		   	} 
   		}
   		else
   		{
   			 printf("��ʾ:�޴˹���:"); 
		}
}

void Fprint(Stu *p_head)   //�����ݵ�������ǰ·���µ�StudentInformation.txt 
{   
    char Str[256];
    int i = 1; 
    Stu *p_temp = p_head->m_pNext; 
    FILE *fp;
    fp = fopen("StudentInformation.txt", "w");    //��д����ļ� 
    if (fp == NULL)
    {
    printf("�ļ���ʧ��");
    return;
    }
    while(p_temp)  //д���ļ� 
	{   
	    sprintf(Str,"|���:%d",p_temp->m_nSign); //���ַ�������str 
		fputs(Str,fp );
		fputs("|����:",fp );
		fputs(p_temp->m_strName,fp );
		fputs("|�༶:",fp );
		fputs(p_temp->m_strClass,fp );
		sprintf(Str,"|��ѧ�ɼ�:%s",p_temp->m_nMath);
		fputs(Str,fp );
		sprintf(Str,"|Ժϵ����:%d",Sort(p_head,i,1));
		fputs(Str,fp );
		sprintf(Str,"|�༶����:%d",ClassSort(p_head,i,1));
		fputs(Str,fp );
		sprintf(Str,"|���ĳɼ�:%s",p_temp->m_nChinese);
		fputs(Str,fp );
		sprintf(Str,"|Ժϵ����:%d",Sort(p_head,i,2));
		fputs(Str,fp );
		sprintf(Str,"|�༶����:%d",ClassSort(p_head,i,2));
		fputs(Str,fp );
		sprintf(Str,"|Ӣ��ɼ�:%s",p_temp->m_nEnglish);
		fputs(Str,fp );
		sprintf(Str,"|Ժϵ����:%d",Sort(p_head,i,3));
		fputs(Str,fp );
		sprintf(Str,"|�༶����:%d",ClassSort(p_head,i,3));
		fputs(Str,fp );
		sprintf(Str,"|רҵ�ɼ�:%s",p_temp->m_nComputer);
		fputs(Str,fp );
		sprintf(Str,"|Ժϵ����:%d",Sort(p_head,i,4));
		fputs(Str,fp );
		sprintf(Str,"|�༶����:%d",ClassSort(p_head,i,4));
		fputs(Str,fp );
		sprintf(Str,"|�ܳɼ�:%.1f",Strtodouble(p_temp->m_nComputer)+Strtodouble(p_temp->m_nEnglish)+Strtodouble(p_temp->m_nChinese)+Strtodouble(p_temp->m_nMath));
		fputs(Str,fp );
		sprintf(Str,"|Ժϵ����:%d",Sort(p_head,i,5));
		fputs(Str,fp );
		sprintf(Str,"|�༶����:%d\n",ClassSort(p_head,i,5));
		fputs(Str,fp );
	    i=i+1;
	    p_temp=p_temp->m_pNext;
	
	} 
	printf("��ʾ:�ļ��ѱ����ڵ�ǰĿ¼�£��ļ�����StudentInformation.txt\n"); 
	fclose(fp);	
} 
void ClassSortOutput(Stu *p_head,char *str_class,int subject)    //����ͷָ�룬����༶������ѧ�� Ͱ���� 
{
	int list[999];    //���ռ����ı�Ŵ������飻 
	Stu *temp=NextItem(p_head);
	int num=0; 
	int sign=0;
	int i;
	int len=0;
	for(i=0;i<998;i++) 
	{
		list[i]=0;   //��ʼ�� 
	}
	while(temp)
	{   if(strcmp(str_class,temp->m_strClass)==0)
		{
			if(list[ClassSort(p_head,temp->m_nSign,subject)+len]==0)
			{
				list[ClassSort(p_head,temp->m_nSign,subject)+len]=temp->m_nSign;
				len=0; 
				num=num+1;
			}
			else
			{
				len=len+1; 
			}
		
		sign = 1;
		}
		if(len==0)
		{
		temp=NextItem(temp);
		}
	}
	if(sign == 0)
	{
		printf("��ʾ:û������༶\n");
		return;
	}
	else
	{
	for ( i=1;i<=num;i++)
	{   if(subject==1)
	    printf("%s��ÿƵ�%d��:%s ��ѧ�ɼ�Ϊ%s\n",str_class,i,SearchItem(list[i],p_head)->m_strName,SearchItem(list[i],p_head)->m_nMath);
	    if(subject==2)
	    printf("%s��ÿƵ�%d��:%s ���ĳɼ�Ϊ%s\n",str_class,i,SearchItem(list[i],p_head)->m_strName,SearchItem(list[i],p_head)->m_nChinese);
	    if(subject==3)
	    printf("%s��ÿƵ�%d��:%s Ӣ��ɼ�Ϊ%s\n",str_class,i,SearchItem(list[i],p_head)->m_strName,SearchItem(list[i],p_head)->m_nEnglish);
	    if(subject==4)
	    printf("%s��ÿƵ�%d��:%s רҵ�ɼ�Ϊ%s\n",str_class,i,SearchItem(list[i],p_head)->m_strName,SearchItem(list[i],p_head)->m_nComputer);
	}
	}
	
 } 

