//�洢���ݽṹ
//�洢��������

#include "list.h"
//����ϵͳ����
void Mainmenu(Stu *p_head);  //���˵���ʾ���� 
void Maininput(Stu *p_head);  //���˵����뺯������
void Studentmenu(Stu *p_head);  //ѧ���˵���ʾ���� 
void Studentinput(Stu *p_head);   //ѧ���˵����뺯��
void Adminmenu(Stu *p_head);  //����Ա�˵���ʾ���� 
void Admininput(Stu *p_head);   //����Ա�˵����뺯��






//���ܺ��� 
void Display(Stu *p_head);   //���ѧ����Ϣ 
void InitSys(Stu *p_head);   //����ѧ����Ϣ(��ʼ��ϵͳ)
void SaveFile(Stu *p_head);   //�����ļ� 
int Pow(int num,int n); //�������֣�������n�η� 
int Strtoint(char *str);    //����0-100���ַ����������ͺ����������������ַ������򷵻�-1
int Sort(Stu *p_head,int n_ID,int n_subject);  //Ժϵ����������ͷָ�롢ѧ����š���Ҫ�������������� 
int ClassSort(Stu *p_head,int n_ID,int n_subject);   //�༶����������ͷָ�롢ѧ����š���Ҫ�������������� 
void Search(Stu *p_head,char *name);     //����ѧ����Ϣ������ͷָ�룬����ѧ������
void Del(Stu *p_head,int n_ID);    //ɾ��������ͷָ�룬����ɾ��ѧ�����
double Strtodouble(char *str);  //����0-100���ַ�������double�ͺ����������������ַ������򷵻�-1
void AddList(Stu *p_head);    //β�������ͬѧ
void Change(Stu *p_head);   //�޸�
void NoPass(Stu *p_head);   //����ͷָ�룬������в������Ŀ����2�Ƶ�ѧ������
void InputScore(Stu *start , Stu *end , Stu *p_head ,char *subject);    //����ѧϰ�ɼ�¼�룬���뿪ʼ¼��λ�úͽ���¼��λ�ã�����ͷָ�� ,������Ҫ¼���ѧ��
void ShowItem(Stu *p_list,Stu *p_head);  //����ָ�룬�����ѧ����Ϣ  
void Fprint(Stu *p_head);   //�����ݵ�������ǰ·���µ�StudentInformation.txt 
void ClassSortOutput(Stu *p_head,char *str_class,int subject);    //����ͷָ�룬����༶������ѧ��
/*
Stu *Itzlink(int n_num);  //��ʼ������ 
Stu *Search(int n_ID,Stu *p_head);   //����ѧ��    
void Display(Stu *p_head);   //������б� 
int Sort(Stu *p_head,int n_ID,int n_subject);    //ȫ������ 
void Del(Stu *p_head);     //ɾ���� 
void Change(Stu *p_head);     // �޸�ֵ 
void Add(Stu *p_head);    //��ӱ�
int ClassSort(Stu *p_head,int n_ID,int n_subject);   //�༶���� 
void Fprint(Stu *p_head);    //�ļ����� 
void NoPass(Stu *p_head);   //δͨ����Ա��� 
*/ 
