//存储数据结构
//存储函数申明

#include "list.h"
//管理系统函数
void Mainmenu(Stu *p_head);  //主菜单显示函数 
void Maininput(Stu *p_head);  //主菜单输入函数函数
void Studentmenu(Stu *p_head);  //学生菜单显示函数 
void Studentinput(Stu *p_head);   //学生菜单输入函数
void Adminmenu(Stu *p_head);  //管理员菜单显示函数 
void Admininput(Stu *p_head);   //管理员菜单输入函数






//功能函数 
void Display(Stu *p_head);   //输出学生信息 
void InitSys(Stu *p_head);   //输入学生信息(初始化系统)
void SaveFile(Stu *p_head);   //保存文件 
int Pow(int num,int n); //传入数字，返回其n次方 
int Strtoint(char *str);    //传入0-100的字符串返回整型函数，若传入其他字符串，则返回-1
int Sort(Stu *p_head,int n_ID,int n_subject);  //院系排名，传入头指针、学生编号、所要排名的数据类型 
int ClassSort(Stu *p_head,int n_ID,int n_subject);   //班级排名，传入头指针、学生编号、所要排名的数据类型 
void Search(Stu *p_head,char *name);     //搜索学生信息，传入头指针，传入学生姓名
void Del(Stu *p_head,int n_ID);    //删除表，传入头指针，传入删除学生编号
double Strtodouble(char *str);  //传入0-100的字符串返回double型函数，若传入其他字符串，则返回-1
void AddList(Stu *p_head);    //尾部添加新同学
void Change(Stu *p_head);   //修改
void NoPass(Stu *p_head);   //传入头指针，输出所有不及格科目超过2科的学生名单
void InputScore(Stu *start , Stu *end , Stu *p_head ,char *subject);    //单科学习成绩录入，传入开始录入位置和结束录入位置，传入头指针 ,传入需要录入的学科
void ShowItem(Stu *p_list,Stu *p_head);  //传入指针，输出其学生信息  
void Fprint(Stu *p_head);   //将数据导出到当前路径下的StudentInformation.txt 
void ClassSortOutput(Stu *p_head,char *str_class,int subject);    //传入头指针，传入班级，传入学科
/*
Stu *Itzlink(int n_num);  //初始化链表 
Stu *Search(int n_ID,Stu *p_head);   //搜索学生    
void Display(Stu *p_head);   //输出所有表 
int Sort(Stu *p_head,int n_ID,int n_subject);    //全局排序 
void Del(Stu *p_head);     //删除表 
void Change(Stu *p_head);     // 修改值 
void Add(Stu *p_head);    //添加表
int ClassSort(Stu *p_head,int n_ID,int n_subject);   //班级排名 
void Fprint(Stu *p_head);    //文件保存 
void NoPass(Stu *p_head);   //未通过人员输出 
*/ 
