/*********************************************************************
*                  ����������ʵ�������Ƽ���ѧ�˶������ͳ��ϵͳ      *
*                  ���뻷����VS 2013                                 *
*                  �������壺������1601�����С��                    *
*                  ����ʱ�䣺2018.6.26                               *
*������															     *
*		1.����ĿC���Ա�д����Ӧ��.c�ļ��������ڼ���ͼ�ν���⣬		 *
*		  ��֧��C++���ԣ����Ը���Ϊ.cpp�ļ���						 *	
*		2.��ʱ��ԭ������ֻ��ϵͳ��ʼʱ������ͼ�ν���      		 *	   						 *
**********************************************************************/

#ifndef __SYSTEM_H__  //��ֹͷ�ļ����ظ�����
#define __SYSTEM_H__

#include <stdio.h>
#include <conio.h>	//���
#include <graphics.h>//TC2.0��������ͷ�ļ�,Ŀǰ��ͷ�ļ���ҪEeayXͼ�ο�֧�ֱ�����ֻ֧��c++
#include <mmsystem.h>//��ý���豸�ӿ�  �ײ�����
#pragma comment(lib,"winmm.lib")//����winmm��̬��



//ͼ�ν����С
#define WINDOS_WIDE 600
#define WINDOS_HIGH 400

#define N 20 //ѧУ�����Ŀ
#define M 20 //����Ŀ�����Ŀ
#define W 20 //Ů��Ŀ�����Ŀ

//��Ŀ��Ϣ
typedef struct Project
{
	int inum;//��Ŀ���
	int top; //������Ŀ
	int range[5]; //��������
	int mark[5];//����

}itemnode; 

//ѧУ��Ϣ
typedef struct school
{
	int snum;//ѧУ���
	int score;//ѧУ�ܷ�
	int mscore;//�������ܷ�
	int wscore;//Ů�����ܷ�
	itemnode t[M+W];//��Ŀ����

}snode;	
extern snode a[N];    //����һ��ѧУ����







//�˵�ѡ��
void meau();
//�����ʼ��
void BeginInit();
//���������
void Press();
//������Ϣ
void savetofile();
//��ȡ��Ϣ
void readfromfile();

// ����Ϣ����
void InputInformation(int n,int m,int w);
//// ��ͳ�����
void OutInformation(int n, int m, int w);
// ���������
void OutSort(int n,int m,int w);
// ����Ϣ��ѯ
void OutSearch(int n,int m,int w);





#endif	 //__SYSTEM_H__