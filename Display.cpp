void display(link *p)
{   int i=1;
	link *temp=p;
	while(temp)
	{   if(temp->sign>0)
		{
		printf("|���:%d ",temp->sign);
		printf("|����:%s ",temp->name);
		printf("|�꼶:%s ",temp->grade);
		printf("|�༶:%s ",temp->classs);
		printf("|��ѧ�ɼ�:%d ����:%d",temp->math,sort(p,i,1));
		printf("|���ĳɼ�:%d ����:%d",temp->chinese,sort(p,i,2));
		printf("|Ӣ��ɼ�:%d ����:%d",temp->english,sort(p,i,3));
		printf("|רҵ�ɼ�:%d ����:%d\n",temp->computer,sort(p,i,4));
		i=i+1;
	   }
	   temp=temp->next;
	}
}
