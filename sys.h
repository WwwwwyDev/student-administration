//�洢���ݽṹ
//�洢��������

#include "struct.h" 
Stu *Itzlink(int n);   //��ʼ������ 
Stu *Search(int n_ID,Stu *p_head);   //����ѧ��    
void Display(Stu *p_head);   //������б� 
int Sort(Stu *p_head,int n_ID,int n_subject);    //ȫ������ 
void Del(Stu *p_head);     //ɾ���� 
void Change(Stu *p_head);     // �޸�ֵ 
void Add(Stu *p_head);    //��ӱ�
int ClassSort(Stu *p_head,int n_ID,int n_subject);   //�༶���� 
void Fprint(Stu *p_head);    //�ļ����� 
void NoPass(Stu *p_head);   //δͨ����Ա��� 
