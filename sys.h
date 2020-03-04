//存储数据结构
//存储函数申明

#include "list.h"
//管理系统函数






//辅助函数 
void Display(Stu *p_head);   //输出学生信息 
void InitSys(Stu *p_head);   //输入学生信息(初始化系统)
int Pow(int num,int n); //传入数字，返回其n次方 
int Strtoint(char *str);    //传入0-100的字符串返回整型函数，若传入其他字符串，则返回-1

 
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
