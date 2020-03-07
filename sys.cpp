//函数定义
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sys.h"
//系统操作函数 
void Mainmenu(Stu *p_head)  //主菜单显示函数 
{
     printf("请选择你的身份:A:学生 B:系统管理员:");
	 Maininput(p_head);
} 

void Maininput(Stu *p_head)  //主菜单输入函数函数 
{
    char choice[999]= "\0";  //字符数组初始化\0
	gets(choice);//fgets(choice,998,stdin); 避免读入空格 
	//while(getchar()!='\n');
	if(strcmp(choice,"A")==0)
	{   
			Studentmenu(p_head); 
	} 
	else if(strcmp(choice,"B")==0)
	{   
			char admin[999]= "\0";
            printf("请输入管理员密匙：");
        	gets(admin);
    		if(strcmp(admin,"123")==0)
			{
			Adminmenu(p_head); 
			}
			else
	    	{   
	    	printf("提示：密匙错误\n");
			return;
			}
	}
	else
	{
		printf("没有这个操作，请重新选择\n"); 
	}
} 

void Studentmenu(Stu *p_head)  //学生菜单显示函数 
{   while(1)
	{
	printf("    功能菜单\nA:输出所有学生信息 \nB:查找学生 \nC:输出两门以上不及格的学生名单 \nD:保存为文件 \nE:输出班级单科排名 \nF:更改权限为管理员 \n(权限:学生)请输入你要进行的操作:"); 
	Studentinput(p_head);
	}
}

void Studentinput(Stu *p_head)   //学生菜单输入函数
{   char choice[999]="\0";
	gets(choice);
	if(strcmp(choice,"A")==0)
	{
		Display(p_head);
	}
	else if(strcmp(choice,"B")==0)
	{   char name[999]="\0"; 
	    printf("请输入你要查找学生姓名:");
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
	{   printf("请输入班级:");
	    char str_class[999]="\0";
	    char str_subject[999]="\0"; 
		gets(str_class); 
		printf("请输入你要排名的学科(A：数学B：语文C：英语D：专业):");
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
	    printf("提示：没有这个学科\n"); 
	}
	else if(strcmp(choice,"F")==0)
	{   char admin[999];
        printf("请输入管理员密匙：");
        gets(admin);
    	if(strcmp(admin,"123")==0)
		{
		Adminmenu(p_head); 
		}
		else
	    {   
	    printf("提示：密匙错误\n");
		return;
	    }
	} 
	else
	{
		printf("没有这个操作，请重新选择\n"); 
	}
} 

void Adminmenu(Stu *p_head)  //管理员菜单显示函数 
{   while(1)
    { 
	printf("    功能菜单\nA:输出所有学生信息 \nB:查找学生 \nC:删除学生 \nD:添加学生 \nE:修改学生信息 \nF:输出两门以上不及格的学生名单 \nG:学生单科成绩录入 \nH:保存为文件 \nI:输出班级单科排名 \n(权限:管理员)请输入你要进行的操作:"); 
	Admininput(p_head);
	}	
}
 

void Admininput(Stu *p_head)   //管理员菜单输入函数
{   char choice[999]="\0";
	gets(choice);
	if(strcmp(choice,"A")==0)
	{
		Display(p_head);
	}
	else if(strcmp(choice,"B")==0)
	{   char name[999]="\0"; 
	    printf("请输入你要查找学生姓名:");
	    gets(name);
		Search(p_head,name);
	}
	else if(strcmp(choice,"C")==0)
	{   int n_ID ;
	    printf("请输入你要删除的学生的编号:");
	    if(scanf("%d",&n_ID)!=1)
		{
		printf("提示：你没有输入正确编号\n");
		fflush(stdin);//while(getchar()!='\n');
	    }
		else 
		{
		fflush(stdin);
		Del2(p_head,n_ID);
	    //printf("提示：删除成功\n"); 
	    
	    SaveFile(p_head); 
	    }
	}
	else if(strcmp(choice,"D")==0)
	{   int num,num1;
	    printf("请输入你要添加学生的数量:");
	    if(scanf("%d",&num)!=1)
		{
		printf("提示：你没有输入正确数量\n");
		fflush(stdin);
	    } 
	    fflush(stdin);
	    num1=num; 
	    while(num)
	    {
	    printf("提示：你当前正在添加第%d个学生\n",num1-num+1);
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
	    printf("请输入起始位置编号:");
	    if(scanf("%d",&start)!=1)
		{
		printf("提示：你没有输入正确编号\n");
		fflush(stdin);
		return;
	    }
	    fflush(stdin);
	    Stu *temp1=SearchItem(start , p_head);
        if(temp1==NULL || temp1->m_nSign==0)
        {
   	    	printf("提示：起始位置错误\n");
   	  		return;	
   		}
	    printf("请输入终点位置编号:");
	    if(scanf("%d",&end)!=1)
		{
		printf("提示：你没有输入正确编号\n");
		fflush(stdin);
		return;
	    }
	    fflush(stdin);   //清除缓存区 
	    Stu *temp2=SearchItem(end ,p_head);
   		if(temp2==NULL || temp2->m_nSign==0 ||temp1->m_nSign>temp2->m_nSign)
   		{
   	  		printf("提示：终点位置错误\n");
   	  		return;
   		}
	    printf("请输入你要录入的学科(A：数学B：语文C：英语D：专业):");
	    gets(subject);
		InputScore(temp1,temp2,p_head,subject); 
		SaveFile(p_head);
	}
	else if(strcmp(choice,"H")==0)
	{   
	    Fprint(p_head); 
	}
	else if(strcmp(choice,"I")==0)
	{   printf("请输入班级:");
	    char str_class[999];
	    char str_subject[999]; 
		gets(str_class); 
		printf("请输入你要排名的学科(A：数学B：语文C：英语D：专业):");
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
	    printf("提示：没有这个学科\n"); 
	}
	else
	{
		printf("没有这个操作，请重新选择\n"); 
	}
} 




//功能函数 
void ShowItem(Stu *p_list,Stu *p_head)  //传入指针，输出其学生信息 
{        
        printf("|编号:%d ",p_list->m_nSign);
		printf("|姓名:%s ",p_list->m_strName);
		printf("|班级:%s\n",p_list->m_strClass);
		printf("|数学成绩:%-3s 院系名次:%-3d 班级名次:%-3d\n",p_list->m_nMath,Sort(p_head,p_list->m_nSign,1),ClassSort(p_head,p_list->m_nSign,1));
		printf("|语文成绩:%-3s 院系名次:%-3d 班级名次:%-3d\n",p_list->m_nChinese,Sort(p_head,p_list->m_nSign,2),ClassSort(p_head,p_list->m_nSign,2));
		printf("|英语成绩:%-3s 院系名次:%-3d 班级名次:%-3d\n",p_list->m_nEnglish,Sort(p_head,p_list->m_nSign,3),ClassSort(p_head,p_list->m_nSign,3));
		printf("|专业成绩:%-3s 院系名次:%-3d 班级名次:%-3d\n",p_list->m_nComputer,Sort(p_head,p_list->m_nSign,4),ClassSort(p_head,p_list->m_nSign,4));
		printf("|总成绩:%-5.1f 院系名次:%-3d 班级名次:%-3d\n\n",Strtodouble(p_list->m_nComputer)+Strtodouble(p_list->m_nEnglish)+Strtodouble(p_list->m_nChinese)+Strtodouble(p_list->m_nMath),Sort(p_head,p_list->m_nSign,5),ClassSort(p_head,p_list->m_nSign,5));
 
} 

void Display(Stu *p_head)   //遍历并输出链表,传入头指针 
{   
	Stu *p_temp = NextItem(p_head);
	while(p_temp)
	{   
		ShowItem(p_temp,p_head);
	    p_temp=NextItem(p_temp);
	}
}

void InitSys(Stu *p_head)      //初始化学生系统后，管理员输入数据层 
{       Stu *p_temp = NextItem(p_head);
        while(p_temp)
        {
		printf("输入学生信息(编号:%d):\n",p_temp->m_nSign);   //对结点写入数据
		printf("姓名(编号:%d):",p_temp->m_nSign);
		scanf("%s",p_temp->m_strName);
		printf("班级(编号:%d):",p_temp->m_nSign);
		scanf("%s",p_temp->m_strClass);
        p_temp = NextItem(p_temp);
        }
        fflush(stdin);
} 

void SaveFile(Stu *p_head)   //保存文件 
{   FILE *pf2; 
	if((pf2 = fopen("data.wwy","wb")) == NULL) 
	{
		exit(1);
	}
    Stu *p_temp = p_head;
	while(p_temp)
	{
	fwrite(p_temp,sizeof(struct Stu),1,pf2);  //参数说明：1.要写入的数据的地址，2.一次要写多少字节，3.写多少次，4.写到哪里 
	p_temp = NextItem(p_temp);
    }	
	fclose(pf2);	
}
int Pow(int num,int n) //传入数字，返回其n次方 
{ if(n == 1)
  return num;
  else
  return num*Pow(num,n-1);
} 


int Strtoint(char *str)    //传入符串返回整型函数，若传入其他字符串，则返回-1
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
double Strtodouble(char *str)  //传入0-100的字符串返回double型函数，若传入其他字符串，则返回-1
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


void Search(Stu *p_head,char *name)     //搜索学生信息，传入头指针，传入学生姓名 
{   Stu *p_temp = NextItem(p_head);
    int sign=0;    //记录是否有学生 
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
		printf("提示：无此学生\n");
	}
	
}


void Del(Stu *p_head,int n_ID)    //删除表，传入头指针，传入删除学生编号 
{   if(SearchItem(n_ID,p_head)==NULL)
    {
    	printf("提示：没有这个编号\n");
	}
	else
	{
	free(SearchItem(n_ID,p_head));  //释放内存空间 
    Stu *p_temp1=SearchItem(n_ID-1,p_head);   //删除结点前后关联 
    Stu *p_temp2=SearchItem(n_ID+1,p_head);  
    p_temp1->m_pNext = p_temp2;
    while(p_temp2)
    {
    	p_temp2->m_nSign = (p_temp2->m_nSign)-1;
    	p_temp2 = NextItem(p_temp2);
	}   		
    }
}

void Del2(Stu *p_head,int n_ID)    //删除表，传入头指针，传入删除学生编号 
{   if(SearchItem(n_ID,p_head)==NULL)
    {
    	printf("提示：没有这个编号\n");
	}
	else
	{
	free(SearchItem(n_ID,p_head));  //释放内存空间 
    Stu *p_temp1=SearchItem(n_ID-1,p_head);   //删除结点前后关联 
    Stu *p_temp2=SearchItem(n_ID+1,p_head);  
    p_temp1->m_pNext = p_temp2;
    while(p_temp2)
    {
    	p_temp2->m_nSign = (p_temp2->m_nSign)-1;
    	p_temp2 = NextItem(p_temp2);
	}   	
	printf("提示：删除成功\n");	
    }
}


int Sort(Stu *p_head,int n_ID,int n_subject)   //院系总排名，传入头指针、学生编号、所要排名的数据类型 
{
    Stu *p_thisStudent=SearchItem(n_ID,p_head);
    int num;
	int i = 1;
	int sum = 1;
    if(n_subject == 1)   //用Search()函数对每一个结点该编号数据值进行检索，遇到比被排序结点数值大时sum+1
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
 
 int ClassSort(Stu *p_head,int n_ID,int n_subject)   //班级排名，传入头指针、学生编号、所要排名的数据类型 
{
    Stu *p_thisStudent=SearchItem(n_ID,p_head);
    int num;
	int i = 1;
	int sum = 1;
    if(n_subject == 1)   //用Search()函数对每一个结点该编号数据值进行检索，遇到比被排序结点数值大时sum+1
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
 
void AddList(Stu *p_head)    //尾部添加新同学 
{   Stu *temp=p_head;
	
	while(temp->m_pNext)
    {
	 temp=NextItem(temp);
    } 
	AddItem(temp);
	temp=NextItem(temp);
	printf("输入学生信息(编号:%d):\n",temp->m_nSign);   //对结点写入数据
	printf("姓名(编号:%d):",temp->m_nSign);
	gets(temp->m_strName);
	printf("班级(编号:%d):",temp->m_nSign);
	gets(temp->m_strClass);
}

void Change(Stu *p_head)   //修改 
{   
    char c_value[999]="\0";
    int n_ID;
    printf("请输入你想修改的学生信息的编号：");
    //scanf("%d",&n_ID);
     if(scanf("%d",&n_ID)!=1)
	{
		printf("提示：你没有输入正确编号\n");
		fflush(stdin);//while(getchar()!='\n');
		return;
	}
	Stu *p_temp = SearchItem(n_ID,p_head);    //通过编号搜索结点位置 
	if(p_temp == NULL)
	{
		printf("提示：未找到这个编号\n");
		fflush(stdin);
		return; 
	}
	printf("    该学生信息\n");
	ShowItem(p_temp,p_head);
	printf("请选择你想修改的信息（A:姓名，B:班级，C:数学成绩，D:语文成绩，E:英语成绩，F:专业成绩）："); 
	fflush(stdin); //消除回车 
	gets(c_value);
	
	if(strcmp(c_value,"A") == 0)
	    {
	    printf("请输入你修改后的内容：");
		gets(p_temp->m_strName);
	    printf("提示：修改成功！\n");
	    } 
    else if(strcmp(c_value,"B") == 0)
	    {
	    printf("请输入你修改后的内容：");
		gets(p_temp->m_strClass);
	    printf("提示：修改成功！\n");
	    } 
	else if (strcmp(c_value,"C") == 0)
		{
		printf("请输入你修改后的内容：");
		gets(p_temp->m_nMath);
		while(Strtodouble(p_temp->m_nMath) == -1)
		{	   
			printf("提示:您的输入有问题(成绩为0-100的整数),请重新输入:"); 
			gets(p_temp->m_nMath);
		}
		printf("提示：修改成功！\n");
		} 
	else if (strcmp(c_value,"D") == 0)
		{
		printf("请输入你修改后的内容：");
		gets(p_temp->m_nChinese);
		while(Strtodouble(p_temp->m_nChinese) == -1)
		{	   
			printf("提示:您的输入有问题(成绩为0-100的整数),请重新输入:"); 
			gets(p_temp->m_nChinese);
		}
		printf("提示：修改成功！\n");
		} 
	else if (strcmp(c_value,"E") == 0)
		{
		printf("请输入你修改后的内容：");	
		gets(p_temp->m_nEnglish);
		while(Strtodouble(p_temp->m_nEnglish) == -1)
		{	   
			printf("提示:您的输入有问题(成绩为0-100的整数),请重新输入:"); 
			gets(p_temp->m_nEnglish);
		}
		printf("提示：修改成功！\n");
		} 
	else if (strcmp(c_value,"F") == 0)
		{
		printf("请输入你修改后的内容：");
		gets(p_temp->m_nComputer);
		while(Strtodouble(p_temp->m_nComputer) == -1)
		{	   
			printf("提示:您的输入有问题(成绩为0-100的整数),请重新输入:"); 
			gets(p_temp->m_nComputer);
		}
		printf("提示：修改成功！\n");
		} 
	else 
	    printf("提示：没有这个功能\n");   
}

void NoPass(Stu *p_head)   //传入头指针，输出所有不及格科目超过2科的学生名单
{   Stu *p_temp = NextItem(p_head);
	int sum = 0;
	while(p_temp)   //判断不及格 
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

void InputScore(Stu *start , Stu *end , Stu *p_head ,char *subject)    //单科学习成绩录入，传入开始录入位置和结束录入位置，传入头指针 ,传入需要录入的学科 
{
   
   Stu *temp = start;
   
        if(strcmp(subject,"A")==0)
        {   while(temp != NextItem(end))
            {
	    		printf("%s的数学成绩(编号:%d)原为%s分，现改为:",temp->m_strName,temp->m_nSign,temp->m_nMath);
				gets(temp->m_nMath);
				while(Strtodouble(temp->m_nMath) == -1)
					{	   
						printf("提示:您的输入有问题(成绩为0-100的整数),请重新输入:"); 
						gets(temp->m_nMath);
					}
				temp=NextItem(temp);
		   	} 
   		}
   		else if(strcmp(subject,"B")==0)
        {   while(temp != NextItem(end))
            {
	    		printf("%s的语文成绩(编号:%d)原为%s分，现改为:",temp->m_strName,temp->m_nSign,temp->m_nChinese);
				gets(temp->m_nChinese);
				while(Strtodouble(temp->m_nChinese) == -1)
					{	   
						printf("提示:您的输入有问题(成绩为0-100的整数),请重新输入:"); 
						gets(temp->m_nChinese);
					}
				temp=NextItem(temp);
		   	} 
   		}
   		else if(strcmp(subject,"C")==0)
        {   while(temp != NextItem(end))
            {
	    		printf("%s的英语成绩(编号:%d)原为%s分，现改为:",temp->m_strName,temp->m_nSign,temp->m_nEnglish);
				gets(temp->m_nEnglish);
				while(Strtodouble(temp->m_nEnglish) == -1)
					{	   
						printf("提示:您的输入有问题(成绩为0-100的整数),请重新输入:"); 
						gets(temp->m_nEnglish);
					}
				temp=NextItem(temp);
		   	} 
   		}
   		else if(strcmp(subject,"D")==0)
        {   while(temp != NextItem(end))
            {
	    		printf("%s的专业成绩(编号:%d)原为%s分，现改为:",temp->m_strName,temp->m_nSign,temp->m_nComputer);
				gets(temp->m_nComputer);
				while(Strtodouble(temp->m_nComputer) == -1)
					{	   
						printf("提示:您的输入有问题(成绩为0-100的整数),请重新输入:"); 
						gets(temp->m_nComputer);
					}
				temp=NextItem(temp);
		   	} 
   		}
   		else
   		{
   			 printf("提示:无此功能:"); 
		}
}

void Fprint(Stu *p_head)   //将数据导出到当前路径下的StudentInformation.txt 
{   
    char Str[256];
    int i = 1; 
    Stu *p_temp = p_head->m_pNext; 
    FILE *fp;
    fp = fopen("StudentInformation.txt", "w");    //以写入打开文件 
    if (fp == NULL)
    {
    printf("文件打开失败");
    return;
    }
    while(p_temp)  //写入文件 
	{   
	    sprintf(Str,"|编号:%d",p_temp->m_nSign); //将字符串赋给str 
		fputs(Str,fp );
		fputs("|姓名:",fp );
		fputs(p_temp->m_strName,fp );
		fputs("|班级:",fp );
		fputs(p_temp->m_strClass,fp );
		sprintf(Str,"|数学成绩:%s",p_temp->m_nMath);
		fputs(Str,fp );
		sprintf(Str,"|院系排名:%d",Sort(p_head,i,1));
		fputs(Str,fp );
		sprintf(Str,"|班级排名:%d",ClassSort(p_head,i,1));
		fputs(Str,fp );
		sprintf(Str,"|语文成绩:%s",p_temp->m_nChinese);
		fputs(Str,fp );
		sprintf(Str,"|院系排名:%d",Sort(p_head,i,2));
		fputs(Str,fp );
		sprintf(Str,"|班级排名:%d",ClassSort(p_head,i,2));
		fputs(Str,fp );
		sprintf(Str,"|英语成绩:%s",p_temp->m_nEnglish);
		fputs(Str,fp );
		sprintf(Str,"|院系排名:%d",Sort(p_head,i,3));
		fputs(Str,fp );
		sprintf(Str,"|班级排名:%d",ClassSort(p_head,i,3));
		fputs(Str,fp );
		sprintf(Str,"|专业成绩:%s",p_temp->m_nComputer);
		fputs(Str,fp );
		sprintf(Str,"|院系排名:%d",Sort(p_head,i,4));
		fputs(Str,fp );
		sprintf(Str,"|班级排名:%d",ClassSort(p_head,i,4));
		fputs(Str,fp );
		sprintf(Str,"|总成绩:%.1f",Strtodouble(p_temp->m_nComputer)+Strtodouble(p_temp->m_nEnglish)+Strtodouble(p_temp->m_nChinese)+Strtodouble(p_temp->m_nMath));
		fputs(Str,fp );
		sprintf(Str,"|院系排名:%d",Sort(p_head,i,5));
		fputs(Str,fp );
		sprintf(Str,"|班级排名:%d\n",ClassSort(p_head,i,5));
		fputs(Str,fp );
	    i=i+1;
	    p_temp=p_temp->m_pNext;
	
	} 
	printf("提示:文件已保存在当前目录下，文件名：StudentInformation.txt\n"); 
	fclose(fp);	
} 
void ClassSortOutput(Stu *p_head,char *str_class,int subject)    //传入头指针，传入班级，传入学科 桶排序 
{
	int list[999];    //将收集到的编号传入数组； 
	Stu *temp=NextItem(p_head);
	int num=0; 
	int sign=0;
	int i;
	int len=0;
	for(i=0;i<998;i++) 
	{
		list[i]=0;   //初始化 
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
		printf("提示:没有这个班级\n");
		return;
	}
	else
	{
	for ( i=1;i<=num;i++)
	{   if(subject==1)
	    printf("%s班该科第%d名:%s 数学成绩为%s\n",str_class,i,SearchItem(list[i],p_head)->m_strName,SearchItem(list[i],p_head)->m_nMath);
	    if(subject==2)
	    printf("%s班该科第%d名:%s 语文成绩为%s\n",str_class,i,SearchItem(list[i],p_head)->m_strName,SearchItem(list[i],p_head)->m_nChinese);
	    if(subject==3)
	    printf("%s班该科第%d名:%s 英语成绩为%s\n",str_class,i,SearchItem(list[i],p_head)->m_strName,SearchItem(list[i],p_head)->m_nEnglish);
	    if(subject==4)
	    printf("%s班该科第%d名:%s 专业成绩为%s\n",str_class,i,SearchItem(list[i],p_head)->m_strName,SearchItem(list[i],p_head)->m_nComputer);
	}
	}
	
 } 

