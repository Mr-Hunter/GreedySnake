
#define _CRT_SECURE_NO_WARNINGS 1

#include "ScoreSystem.h"
snode a[N];    //����һ��ѧУ����


int main()
{	
	int n, m, w;
	int input;
	initgraph(WINDOS_WIDE, WINDOS_HIGH);//����ͼ�ν���
	BeginInit();
	Press();
	printf("\n\n\t\t\t**************��ӭʹ��************\n");
	printf("�������˶�����Ҫ��Ϣ:\n");
	printf("\t������ѧУ����>:");
	scanf("%d", &n);
	printf("\t����������Ŀ����>:");
	scanf("%d", &m);
	printf("\t������Ů��Ŀ����>:");
	scanf("%d", &w);

	do
	{  
		meau();
		scanf("%d", &input);
		system("cls");//����

		switch (input)
		{
		case 1:
			// ����Ϣ����
			
			InputInformation(n,m,w);
			break;
		case 2:
			// ��ͳ�����
			OutInformation(n,m,w);
			break;
		case 3:
			// ���������
			OutSort(n,m,w);
			break;
		case 4:
			// ����Ϣ��ѯ
			OutSearch(n,m,w);
			break;
		case 0:
			// 0 �˳�ϵͳ
			printf("\n\n\t\t\t*************��ӭ�ٴ�ʹ��***********\n");

			break;
		default:
			printf("\t\t\t������������������:\n");
		}
		

	} while (input);

	//vs2013��ֹ����
	system("pause");
	return 0;
}

