#define _CRT_SECURE_NO_WARNINGS 1

#include "ScoreSystem.h"

//�˵�
void meau()
{
		printf("\n\n\t\t\t**************��ӭʹ��************\n");
		printf("\n\n\t\t\t������������������������������������������������������������������\n");
		printf("\t\t\t�� �����Ƽ���ѧ�˶���Ʒ�ϵͳϵͳ��\n");
		printf("\t\t\t�ǩ���������������������������������������������������������������\n");
		printf("\t\t\t��	   ����Ϣ����		��\n");
		printf("\t\t\t�ǩ���������������������������������������������������������������\n");
		printf("\t\t\t��	   ��ͳ�����		��\n");
		printf("\t\t\t�ǩ���������������������������������������������������������������\n");
		printf("\t\t\t�� 	   ���������		��\n");
		printf("\t\t\t�ǩ���������������������������������������������������������������\n");
		printf("\t\t\t��	   ����Ϣ��ѯ		��\n");
		printf("\t\t\t�ǩ���������������������������������������������������������������\n");
		printf("\t\t\t��	   0 �˳�ϵͳ		��\n");
		printf("\t\t\t������������������������������������������������������������������\n");
		printf("\t\t\t��ѡ��:>");

}

//�����ʼ��
void BeginInit()
{
	IMAGE bkImg, bk1;
	//MP3��ʽ
	mciSendString(L"open ./music/bkmusic.mp3 alias bgm", 0, 0, 0);//����ȡ����bgm
	mciSendString(L"play bgm repeat", 0, 0, 0);
	//WAV��ʽ
	//PlaySound(L"./music/b.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	loadimage(&bkImg, L"./photo/b.jpg", 600, 400);//���ձ������ż���
	loadimage(&bk1, L"./photo/c.jpg", 200, 50);//���ձ������ż���
	putimage(0, 0, &bkImg);
	

	settextstyle(30, 0, L"����");
	settextcolor(RGB(0, 0, 255));
	setbkmode(TRANSPARENT);	//����͸��
	outtextxy(100, 20, L"�˶������ͳ��ϵͳ 1.0 -v");

	outtextxy(210, 165, L"���Here����");

	outtextxy(320, 340, L"2018.6.25����");
	outtextxy(355, 370, L" ---by ����С��");

}

//���������
void Press()
{
	//���������Ϣ
	MOUSEMSG msg = { 0 };
	while (true)
	{
		msg = GetMouseMsg();

		//uMsg  ��굱ǰ��Ϣ
		switch (msg.uMsg)
		{
			//�������
		case WM_LBUTTONDOWN:
			if (msg.x >= 180 && msg.x <= 380 && msg.y >= 160 && msg.y <= 210)
			{

				closegraph();

			}


			goto flag;
		}
	}
flag:
	;
}

//������Ϣ���ļ�
void savetofile()
{
	FILE *fp;
	int i;
	if ((fp = fopen("file.txt", "w")) == NULL)
	{
		printf("cannot open the file\n");
		return;
	}
	for (i = 0; i<N; i++)
	{
		if (a[i].snum != '\0')
		if (fwrite(&a[i], sizeof(snode), 1, fp) != 1)
		{
			printf("file write error\n");
			return;
		}
	}
	fclose(fp);
}
//���ļ��ж�ȡ
void readfromfile() 
{
	int i;
	FILE *fp;
	if ((fp = fopen("file.txt", "rb")) == NULL)
	{
		printf("���ܴ��ļ�\n");
		return;
	}
	for (i = 0; i<N; i++)
		fread(&a[i], sizeof(snode), 1, fp);
	fclose(fp);
}
// ����Ϣ����
void InputInformation(int n, int m, int w)
{ 
	printf("\n\n\t\t\t������������������������������������������������������������������\n");
	printf("\t\t\t�� �����Ƽ���ѧ�˶���Ʒ�ϵͳϵͳ��\n");
	printf("\t\t\t�ǩ���������������������������������������������������������������\n");
	printf("\t\t\t��	   ����Ϣ����		��\n");
	printf("\t\t\t������������������������������������������������������������������\n");

	int i, j, s, k, q = 0;
	for (i = 1; i<n + 1; i++)
	{
		printf("��%d��ѧУ��� :", i);
		scanf("%d", &a[i].snum); /* ����ѧУ��Ϣ */
		for (j = 0; j<m + w; j++)
		{
			printf(" ��Ŀ��� :");
			scanf("%d", &a[i].t[j].inum);
			printf(" ��Ŀȡǰ 3 ����ǰ 5 ��(3 �� 5):");
			scanf("%d", &a[i].t[j].top);
			if (a[i].t[j].top == 3)
				printf("������θ��� (1-3)��");
			else
				printf("������θ��� (1-5)��");
			scanf("%d", &k); /* ������Ŀ��Ϣ */
			for (s = 0; s<k; s++)
			{
				if (a[i].t[j].top == 3)
					printf(" �������� (1--3):");
				else
					printf(" �������� (1--5):");
				scanf("%d", &a[i].t[j].range[s]); /* ��������������Ϣ */
			}
			printf("\n");
		}
	}
	for (i = 0; i<n; i++)
	{
		a[i].score = 0;
		a[i].mscore = 0;
		a[i].wscore = 0;
	} /* ��ʼ������ */
	for (i = 0; i<n+1; i++)
	for (j = 0; j<m + w; j++)
	for (s = 0; s<5; s++)
	{
		if (a[i].t[j].top == 3)
			switch (a[i].t[j].range[s])
		{
			case 0: a[i].t[j].mark[s] = 0; break;
			case 1: a[i].t[j].mark[s] = 5; break;
			case 2: a[i].t[j].mark[s] = 3; break;
			case 3: a[i].t[j].mark[s] = 2; break;
			case 4: a[i].t[j].mark[s] = 0; break;
			case 5: a[i].t[j].mark[s] = 0; break;
		}
		else if (a[i].t[j].top == 5)
			switch (a[i].t[j].range[s])
		{
			case 0: a[i].t[j].mark[s] = 0; break;
			case 1: a[i].t[j].mark[s] = 7; break;
			case 2: a[i].t[j].mark[s] = 5; break;
			case 3: a[i].t[j].mark[s] = 3; break;
			case 4: a[i].t[j].mark[s] = 2; break;
			case 5: a[i].t[j].mark[s] = 1; break;
		}
		a[i].score = a[i].score + a[i].t[j].mark[s]; /*��ѧУ�ܷ� */
		if (j <= m - 1)
			a[i].mscore = a[i].mscore + a[i].t[j].mark[s]; /*�����������ܷ� */
		else
			a[i].wscore = a[i].wscore + a[i].t[j].mark[s]; /*��Ů�������ܷ� */
	}
	printf(" ������� !����? 1 �� 2 ��\n"); /*���ز˵� */
	scanf("%d", &q);
	printf("\n");
	if (q != 1)
		printf("�����������Ϣ !");
	printf("\n");
	savetofile(); /*����Ϣ�����ļ� file*/
	system("cls");//����

} 
// ��ͳ�����
void OutInformation(int n, int m, int w)
{
	printf("\n\n\t\t\t������������������������������������������������������������������\n");
	printf("\t\t\t�� �����Ƽ���ѧ�˶���Ʒ�ϵͳϵͳ��\n");
	printf("\t\t\t�ǩ���������������������������������������������������������������\n");
	printf("\t\t\t��	   ��ͳ�����		��\n");
	printf("\t\t\t������������������������������������������������������������������\n");
	readfromfile();
	int i, j, s, q = 0;
	for (i = 0; i<n; i++) /*��ʾ��� */
	{
		printf("ѧУ���:%d\t ѧУ�ܷ�:%d\t �����ܷ�:%d\t Ů���ܷ�:%d\n", a[i].snum, a[i].score, a[i].mscore, a[i].wscore);
		for (j = 0; j<m + w; j++)
		{
			printf("��Ŀ���:%d ��ȡ��������:%d\n", a[i].t[j].inum, a[i].t[j].top);
			for (s = 0; s<5; s++)
			{
				if (a[i].t[j].range[s] != 0)
					printf("����:%d\t ����:%d\n", a[i].t[j].range[s], a[i].t[j].mark[s]);
			}
		}
		printf("\n");
	}
	printf("��ѡ��:1.�������˵� 2.������ѯ"); /*���ز˵��������ѯ */
	scanf("%d", &q);
	printf("\n");
	system("cls");//����


}
// ���������
void OutSort(int n, int m, int w)
{
	readfromfile();
	int c, i, j, k, q = 0;
	int temp[N];
	printf("\n\n\t\t\t������������������������������������������������������������������\n");
	printf("\t\t\t�� �����Ƽ���ѧ�˶���Ʒ�ϵͳϵͳ��\n");
	printf("\t\t\t�ǩ���������������������������������������������������������������\n");
	printf("\t\t\t��	   ���������		��\n");
	printf("\t\t\t�ǩ���������������������������������������������������������������\n");
	printf("\t\t\t��	1. ��ѧУ������	��\n");
	printf("\t\t\t�ǩ���������������������������������������������������������������\n");
	printf("\t\t\t��	2. ��ѧУ�ܷ����	��\n");
	printf("\t\t\t�ǩ���������������������������������������������������������������\n");
	printf("\t\t\t�� 	3. �������ܷ����	��\n");
	printf("\t\t\t�ǩ���������������������������������������������������������������\n");
	printf("\t\t\t��	4. ��Ů���ܷ����	��\n");
	printf("\t\t\t������������������������������������������������������������������\n");

	do
	{
		printf("��ѡ��Ҫʵ�ֹ��ܵı�� (1--4):");
		scanf("%d", &c);
		switch (c)
		{
		case 1:
			for (i = 0; i<n; i++)
				temp[i] = i;
			for (i = 0; i<n; i++)
			{
				for (j = i + 1; j<n; j++)
				if (a[temp[i]].snum>a[j].snum)
				{
					k = temp[i];
					temp[i] = temp[j];
					temp[j] = k;
				}
			} /* ��ð�����򷽷����� */
			for (i = 0; i<n; i++)
			{
				printf("ѧУ���:%d\t ѧУ�ܷ�:%d\t �����ܷ�:%d\t Ů���ܷ�:%d\n", a[temp[i]].snum, a[temp[i]].score, a[temp[i]].mscore, a[temp[i]].wscore);
			} /*��ѧУ������ */
			break;
		case 2:
			for (i = 0; i<n; i++)
				temp[i] = i;
			for (i = 0; i<n; i++)
			{
				for (j = i + 1; j<n; j++)
				if (a[temp[i]].score<a[j].score)
				{
					k = temp[i];
					temp[i] = temp[j];
					temp[j] = k;
				}
			} /* ��ð�����򷽷����� */
			for (i = 0; i<n; i++)
			{
				printf("ѧУ���:%d\t ѧУ�ܷ�:%d\t �����ܷ�:%d\t Ů���ܷ�:%d\n", a[temp[i]].snum, a[temp[i]].score, a[temp[i]].mscore, a[temp[i]].wscore);
			} /* ��ѧУ�ܷ���� */
			break;
		case 3:
			for (i = 0; i<n; i++)
				temp[i] = i;
			for (i = 0; i<n; i++)
			{
				for (j = i + 1; j<n; j++)
				if (a[temp[i]].mscore<a[j].mscore)
				{
					k = temp[i];
					temp[i] = temp[j];
					temp[j] = k;
				}
			} /* ��ð�����򷽷����� */
			for (i = 0; i<n; i++)
			{
				printf("ѧУ���:%d\t ѧУ�ܷ�:%d\t �����ܷ�:%d\t Ů���ܷ�:%d\n", a[temp[i]].snum, a[temp[i]].score, a[temp[i]].mscore, a[temp[i]].wscore);
			} /* �������ܷ���� */
			break;
		case 4:
			for (i = 0; i<n; i++)
				temp[i] = i;
			for (i = 0; i<n; i++)
			{
				for (j = i + 1; j<n; j++)
				if (a[temp[i]].wscore<a[j].wscore)
				{
					k = temp[i];
					temp[i] = temp[j];
					temp[j] = k;
				}
			} /* ��ð�����򷽷����� */
			for (i = 0; i<n; i++)
			{
				printf("ѧУ���:%d\t ѧУ�ܷ�:%d\t �����ܷ�:%d\t Ů���ܷ�:%d\n", a[temp[i]].snum, a[temp[i]].score, a[temp[i]].mscore, a[temp[i]].wscore);
			} /* ��Ů���ܷ���� */
			break;
		default:
			printf("������� ,������\n");
		}
		printf("��ѡ�񣺰�1�������˵�  ��2��������"); /*���ز˵���������� */
		scanf("%d", &q);
		printf("\n");
	} while (q == 2);
	printf("\n");
	system("cls");//����

}
// ����Ϣ��ѯ
void OutSearch(int n, int m, int w)
{
	readfromfile();
	int c, i, j, k, d, l, q = 0;
	printf("\n\n\t\t\t������������������������������������������������������������������\n");
	printf("\t\t\t�� �����Ƽ���ѧ�˶���Ʒ�ϵͳϵͳ��\n");
	printf("\t\t\t�ǩ���������������������������������������������������������������\n");
	printf("\t\t\t��	   ����Ϣ��ѯ		��\n");
	printf("\t\t\t�ǩ���������������������������������������������������������������\n");
	printf("\t\t\t��	1. ��ѧУ��Ų�ѯ	��\n");
	printf("\t\t\t�ǩ���������������������������������������������������������������\n");
	printf("\t\t\t��	2. ��ѧУ�ֲܷ�ѯ	��\n");
	printf("\t\t\t������������������������������������������������������������������\n");

	do
	{
		k = -1; d = -1; l = -1;
		printf(" ��ѡ��Ҫʵ�ֹ��ܵı�� (1--2):");
		scanf("%d", &c);
		switch (c)
		{
		case 1:
			printf(" Ҫ��ѯ��ѧУ��� :"); /*����ѧУ����±� */
			scanf("%d", &c);
			for (i = 0; i<n; i++)
			{
				if (a[i].snum == c)
					k = i;
			}
			if (k == -1)
				printf("��ѧУδ�μӴ˴��˶��� !\n");
			else
			{
				printf("Ҫ��ѯ����Ŀ���:"); /*������Ŀ����±� */
				scanf("%d", &c);
				for (j = 0; j<m + w; j++)
				{
					if (a[k].t[j].inum == c)
						d = j;
				}
				if (d == -1)
					printf("�˴��˶���û�������Ŀ\n");
				else /* ��ʾ��� */
				{
					printf("�����Ŀȡǰ%d��,��ѧУ�ĳɼ�����:\n", a[k].t[d].top);
					for (i = 0; i<5; i++)
					if (a[k].t[d].range[i] != 0)
						printf("����:%d\n", a[k].t[d].range[i]);
				}
			}
			break;
		case 2:
			printf("Ҫ��ѯ����Ŀ���:"); /*������Ŀ����±� */
			scanf("%d", &c);
			for (i = 0; i<n; i++)
			for (j = 0; j<m + w; j++)
			if (a[i].t[j].inum == c)
				l = j;
			if (l == -1)
				printf("�˴��˶���û�������Ŀ \n");
			else /*��ʾ��� */
			{
				printf("����Ŀȡǰ%d��,ȡ�����ε�ѧУ\n", a[0].t[l].top);
				for (i = 0; i<n; i++)
				for (j = 0; j<5; j++)
				if (a[i].t[l].range[j] != 0)
					printf("ѧУ���:%d,����:%d\n", a[i].snum, a[i].t[l].range[j]);
			}
			break;
		default:
			printf("�������,������\n");
		}
		printf("��ѡ��:1.�������˵� 2.������ѯ"); /*���ز˵��������ѯ */
		scanf("%d", &q);
		printf("\n");
	} while (q == 2);
	printf("\n");
	system("cls");//����

}
// ���˳�ϵͳ