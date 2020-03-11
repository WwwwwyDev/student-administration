package main

import (
	"fmt"
	"strconv"
)
func Menu(phead *Stu){
	fmt.Println("功能菜单")
	fmt.Println("A:输出所有学生信息B:查找学生C:删除学生D:添加学生E:修改学生信息F:输出两门以上不及格学生G:单科成绩录入")
	fmt.Printf("请选择你的操作:")
	choice := "0"
	fmt.Scanf("%s",&choice)
	MenuInput(choice,phead)
}
func MenuInput(choice string,phead *Stu){
	switch choice{
	case "A":Display(phead)
	         break
	case "B":name := "0"
		fmt.Printf("请输入学生姓名:")
		fmt.Scanf("%s",&name)
		Search(phead,name)
		break
	case "C":nid:=0
		fmt.Printf("请输入要删除的编号:")
		fmt.Scanf("%d",&nid)
		if nid <= 0{
			fmt.Println("无此编号")
		}else{
			Del(phead,nid)
		}
		break
	case "D":AddList(phead)
		break
	case "E":nid:=0
		fmt.Printf("请输入要修改的编号:")
		fmt.Scanf("%d",&nid)
		if nid <= 0{
			fmt.Println("无此编号")
		}else {
			Change(phead, nid)
		}
		break
	case "F":NoPass(phead)
		break
	case "G":ScoreInput(phead)
		break
	default:fmt.Println("无此操作")
	        break
	}

}
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
//查找学生，通过姓名
func Search(phead *Stu,name string){
	ptemp:=phead.p_next
	sign:=0
	for ptemp!=nil{
		if(ptemp.str_name==name){
			sign=1
			ShowItem(ptemp,phead)
		}
		ptemp=ptemp.p_next
	}
	if sign==0{
		fmt.Println("无此学生")
	}
}

//删除学生
func Del(phead *Stu,nid int){
	if SearchItem(nid,phead)==nil{
		fmt.Println("无此编号")
	}else{
		SearchItem(nid-1,phead).p_next=SearchItem(nid+1,phead)
		ptemp:=SearchItem(nid+1,phead)
		for ptemp!=nil{
			ptemp.n_id--
			ptemp=ptemp.p_next
		}
		fmt.Println("删除成功")
	}
}


func AddList(phead *Stu){
	ptemp :=phead
	for ptemp.p_next!=nil{
		ptemp=ptemp.p_next
	}
	AddItem(ptemp)
	ptemp= ptemp.p_next
	fmt.Printf("输入学生信息(编号:%d):\n",ptemp.n_id)  //对结点写入数据
	fmt.Printf("姓名(编号:%d):",ptemp.n_id)
	fmt.Scanf("%s",&ptemp.str_name)
	fmt.Printf("班级(编号:%d):",ptemp.n_id)
	fmt.Scanf("%s",&ptemp.str_class)
}

func Change(phead *Stu,nid int){
	ptemp := SearchItem(nid,phead)
	if ptemp==nil{
		 fmt.Println("无此编号")
		return
	}
	fmt.Printf("输入修改后学生信息(编号:%d):\n",ptemp.n_id)  //对结点写入数据
	fmt.Printf("姓名(编号:%d):",ptemp.n_id)
	fmt.Scanf("%s",&ptemp.str_name)
	fmt.Printf("班级(编号:%d):",ptemp.n_id)
	fmt.Scanf("%s",&ptemp.str_class)
	fmt.Printf("数学成绩(编号:%d):",ptemp.n_id)
	fmt.Scanf("%s",&ptemp.str_math)
	fmt.Printf("语文成绩(编号:%d):",ptemp.n_id)
	fmt.Scanf("%s",&ptemp.str_chinese)
	fmt.Printf("英语成绩(编号:%d):",ptemp.n_id)
	fmt.Scanf("%s",&ptemp.str_english)
	fmt.Printf("专业成绩(编号:%d):",ptemp.n_id)
	fmt.Scanf("%s",&ptemp.str_computer)
}

func NoPass(phead *Stu){
	ptemp:=phead.p_next
	sum :=0
	for ptemp!=nil{
		if Strtodouble(ptemp.str_math)<60{
			sum=sum+1
		}
		if Strtodouble(ptemp.str_chinese)<60{
			sum=sum+1
		}
		if Strtodouble(ptemp.str_english)<60{
			sum=sum+1
		}
		if Strtodouble(ptemp.str_computer)<60{
			sum=sum+1
		}
		if sum>2{
			ShowItem(ptemp,phead)
		}
		ptemp=ptemp.p_next
		sum=0
	}
}

func ScoreInput(phead *Stu){
	ptemp:=phead.p_next
	subject :=""
	fmt.Printf("请输入你要输入成绩的学科A:数学B:语文C:英语D:专业:")
	fmt.Scanf("%s",&subject)
	switch subject {
	case "A":
		for ptemp!=nil{
			fmt.Printf("%s的数学成绩原为%s现改为:",ptemp.str_name,ptemp.str_math)
			fmt.Scanf("%s",&ptemp.str_math)
			ptemp=ptemp.p_next
		}
		break
	case "B":
		for ptemp!=nil{
			fmt.Printf("%s的语文成绩原为%s现改为:",ptemp.str_name,ptemp.str_chinese)
			fmt.Scanf("%s",&ptemp.str_chinese)
			ptemp=ptemp.p_next
		}
		break
	case "C":
		for ptemp!=nil{
			fmt.Printf("%s的英语成绩原为%s现改为:",ptemp.str_name,ptemp.str_english)
			fmt.Scanf("%s",&ptemp.str_english)
			ptemp=ptemp.p_next
		}
		break
	case "D":
		for ptemp!=nil{
			fmt.Printf("%s的专业成绩原为%s现改为:",ptemp.str_name,ptemp.str_computer)
			fmt.Scanf("%s",&ptemp.str_computer)
			ptemp=ptemp.p_next
		}
		break
	default:
		fmt.Println("没有这个科目")
		break
	}
}