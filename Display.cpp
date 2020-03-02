void display(link *p)
{   int i=1;
	link *temp=p;
	while(temp)
	{   if(temp->sign>0)
		{
		printf("|编号:%d ",temp->sign);
		printf("|姓名:%s ",temp->name);
		printf("|年级:%s ",temp->grade);
		printf("|班级:%s ",temp->classs);
		printf("|数学成绩:%d 名次:%d",temp->math,sort(p,i,1));
		printf("|语文成绩:%d 名次:%d",temp->chinese,sort(p,i,2));
		printf("|英语成绩:%d 名次:%d",temp->english,sort(p,i,3));
		printf("|专业成绩:%d 名次:%d\n",temp->computer,sort(p,i,4));
		i=i+1;
	   }
	   temp=temp->next;
	}
}
