package main

import (
	"fmt"
	"strconv"
)


//功能函数

//初始化学生系统后，管理员输入数据层
func InitImformation(phead *Stu){
	ptemp := phead.p_next
	for ptemp != nil{
		fmt.Printf("输入学生信息(编号:%d):\n",ptemp.n_id)  //对结点写入数据
		fmt.Printf("姓名(编号:%d):",ptemp.n_id)
		fmt.Scanf("%s",&ptemp.str_name)
		fmt.Printf("班级(编号:%d):",ptemp.n_id)
		fmt.Scanf("%s",&ptemp.str_class)
		ptemp = ptemp.p_next
	}
}
//字符串转float64
func Strtodouble(str string) float64{
	num, err := strconv.ParseFloat(str, 64)
	if err != nil {
		return -1
	} else if num<0||num>100{
		return -1
	}else{
		return num
	}
}
//院系总排名，传入头指针、学生编号、所要排名的数据类型
func SortAll(phead *Stu,nid int,nsubject int) int{
    pthisStudent := SearchItem(nid,phead)
    sum := 1
    ptemp := phead.p_next
    if nsubject == 1 {
      for ptemp!=nil{
		  if Strtodouble(pthisStudent.str_math)<Strtodouble(ptemp.str_math)&&pthisStudent!=ptemp{
			  sum=sum+1
		  }
		  ptemp=ptemp.p_next
	  }
	  return sum
	}
	if nsubject == 2 {
		for ptemp!=nil{
			if Strtodouble(pthisStudent.str_chinese)<Strtodouble(ptemp.str_chinese)&&pthisStudent!=ptemp{
				sum=sum+1
			}
			ptemp=ptemp.p_next
		}
		return sum
	}
	if nsubject == 3 {
		for ptemp!=nil{
			if Strtodouble(pthisStudent.str_english)<Strtodouble(ptemp.str_english)&&pthisStudent!=ptemp{
				sum=sum+1
			}
			ptemp=ptemp.p_next
		}
		return sum
	}
	if nsubject == 4 {
		for ptemp!=nil{
			if Strtodouble(pthisStudent.str_computer)<Strtodouble(ptemp.str_computer)&&pthisStudent!=ptemp{
				sum=sum+1
			}
			ptemp=ptemp.p_next
		}
		return sum
	}
	return 0
}
//班级排名
func SortClass(phead *Stu,nid int,nsubject int) int{
	pthisStudent := SearchItem(nid,phead)
	sum := 1
	ptemp := phead.p_next
	if nsubject == 1 {
		for ptemp!=nil{
			if Strtodouble(pthisStudent.str_math)<Strtodouble(ptemp.str_math)&&pthisStudent!=ptemp&&pthisStudent.str_math==ptemp.str_math{
				sum=sum+1
			}
			ptemp=ptemp.p_next
		}
		return sum
	}
	if nsubject == 2 {
		for ptemp!=nil{
			if Strtodouble(pthisStudent.str_chinese)<Strtodouble(ptemp.str_chinese)&&pthisStudent!=ptemp&&pthisStudent.str_chinese==ptemp.str_chinese{
				sum=sum+1
			}
			ptemp=ptemp.p_next
		}
		return sum
	}
	if nsubject == 3 {
		for ptemp!=nil{
			if Strtodouble(pthisStudent.str_english)<Strtodouble(ptemp.str_english)&&pthisStudent!=ptemp&&pthisStudent.str_english==ptemp.str_english{
				sum=sum+1
			}
			ptemp=ptemp.p_next
		}
		return sum
	}
	if nsubject == 4 {
		for ptemp!=nil{
			if Strtodouble(pthisStudent.str_computer)<Strtodouble(ptemp.str_computer)&&pthisStudent!=ptemp&&pthisStudent.str_computer==ptemp.str_computer{
				sum=sum+1
			}
			ptemp=ptemp.p_next
		}
		return sum
	}
	return 0
}
//输出数据域
func ShowItem(plist *Stu,phead *Stu){
	fmt.Printf("|编号%d",plist.n_id)
	fmt.Printf("|姓名%s",plist.str_name)
	fmt.Printf("|班级%s\n",plist.str_class)
	fmt.Printf("|数学成绩%s|院系排名%d|班级排名%d\n",plist.str_math,SortAll(phead,plist.n_id,1),SortClass(phead,plist.n_id,1))
	fmt.Printf("|语文成绩%s|院系排名%d|班级排名%d\n",plist.str_chinese,SortAll(phead,plist.n_id,2),SortClass(phead,plist.n_id,2))
	fmt.Printf("|英语成绩%s|院系排名%d|班级排名%d\n",plist.str_english,SortAll(phead,plist.n_id,3),SortClass(phead,plist.n_id,3))
	fmt.Printf("|专业成绩%s|院系排名%d|班级排名%d\n",plist.str_computer,SortAll(phead,plist.n_id,4),SortClass(phead,plist.n_id,4))
}

func Display(phead *Stu){
	ptemp := phead.p_next
	for ptemp!=nil{
		ShowItem(ptemp,phead)
		ptemp=ptemp.p_next
	}
}
