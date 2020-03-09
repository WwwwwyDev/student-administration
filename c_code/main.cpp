#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "list.h"
#include "menu.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{   SetConsoleTitle("学生管理系统(设计by大连民族大学2019082323)"); 
    printf("当前运行目录%s\n",argv[0]); 
    Stu *p_head = NULL;
//文件读取层 
    FILE *pf; 
    int i,num;
	int sign=0; 
	  //未找到文件需要初始化文件
	if((pf = fopen("data.wwy","r")) == NULL)
	    {
	      sign=1; 
	    }
	fclose(pf);   
	if(sign == 1)
	{
	printf("首次使用未找到历史文件，请初始化文件，请输入学生数量(输入0，则不录入任何数据):");
	    while(scanf("%d",&num)!=1 || num<0)
		{
		printf("提示：你没有输入正确值，请重新输入:");
		fflush(stdin);//while(getchar()!='\n');
	    }
	    fflush(stdin);
	     p_head = InitList(num);  //开num个空间的链表 
	     InitSys(p_head);      //输入数据域 
	     SaveFile(p_head);   //保存文件 
	     printf("欢迎来到学生管理系统(设计by2019082323)\n");
     }
     else
	{   
    if((pf = fopen("data.wwy","rb")) == NULL) 
	{   
	   exit(1);   
	}
         //找到文件，将文件读入链表 
	    p_head = InitList(0);
	    Stu *p_temp = p_head;
        while(fread(p_temp,sizeof(struct Stu),1,pf) == 1)
		{    
			AddItem(p_temp); 
		    p_temp = NextItem(p_temp);
		}
		Del(p_head,p_temp->m_nSign);
		printf("提示：读取成功\n欢迎来到学生管理系统(设计by2019082323)\n");
		fclose(pf);
	}

//工作层 
	while(1)
	{
		Mainmenu(p_head);
	}
	
	return 0;
}	
	
	
	
