#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "list.h"
#include "menu.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{   SetConsoleTitle("ѧ������ϵͳ(���by���������ѧ2019082323)"); 
    printf("��ǰ����Ŀ¼%s\n",argv[0]); 
    Stu *p_head = NULL;
//�ļ���ȡ�� 
    FILE *pf; 
    int i,num;
	int sign=0; 
	  //δ�ҵ��ļ���Ҫ��ʼ���ļ�
	if((pf = fopen("data.wwy","r")) == NULL)
	    {
	      sign=1; 
	    }
	fclose(pf);   
	if(sign == 1)
	{
	printf("�״�ʹ��δ�ҵ���ʷ�ļ������ʼ���ļ���������ѧ������(����0����¼���κ�����):");
	    while(scanf("%d",&num)!=1 || num<0)
		{
		printf("��ʾ����û��������ȷֵ������������:");
		fflush(stdin);//while(getchar()!='\n');
	    }
	    fflush(stdin);
	     p_head = InitList(num);  //��num���ռ������ 
	     InitSys(p_head);      //���������� 
	     SaveFile(p_head);   //�����ļ� 
	     printf("��ӭ����ѧ������ϵͳ(���by2019082323)\n");
     }
     else
	{   
    if((pf = fopen("data.wwy","rb")) == NULL) 
	{   
	   exit(1);   
	}
         //�ҵ��ļ������ļ��������� 
	    p_head = InitList(0);
	    Stu *p_temp = p_head;
        while(fread(p_temp,sizeof(struct Stu),1,pf) == 1)
		{    
			AddItem(p_temp); 
		    p_temp = NextItem(p_temp);
		}
		Del(p_head,p_temp->m_nSign);
		printf("��ʾ����ȡ�ɹ�\n��ӭ����ѧ������ϵͳ(���by2019082323)\n");
		fclose(pf);
	}

//������ 
	while(1)
	{
		Mainmenu(p_head);
	}
	
	return 0;
}	
	
	
	
