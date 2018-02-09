#include "_calc.h"
/*
	��������F_multi(string num1, string num2)
	���ܣ��ַ����˷�
*/
string F_multi(string num1, string num2)//************num1>num2
{
	string rlt, num3;				//��� 
	int s1, s2;						//λ��   
	s1 = num1.length();			//��ȡλ�� 	
	s2 = num2.length();
	int i, j, k, pls;
	//**********************************************��̬��ά����

	int **a = new int *[s2];

	for (i = 0; i<s2; i++)
	{
		a[i] = new int[s1 + s2];
		memset(a[i], 0, (s1 + s2)*sizeof(int));
	}

	//************************************************λ��� 
	k = 0; pls = 0;
	for (i = 0; i<s2; i++)
	{

		for (j = 0; j<s1; j++)
		{

			k = (num1[s1 - j - 1] - 48)*(num2[s2 - i - 1] - 48) + pls;
			pls = 0;					//��λ���� 

			a[i][s1 + s2 - 1 - j - i] = k % 10;
			pls = k / 10;

			if (j == s1 - 1)
				a[i][s1 + s2 - 2 - j - i] = pls;		//���λ��λ 
		}
		pls = 0;						//���н�λ���� 
	}
	//********************************************************λ��� 

	pls = 0; k = 0;
	for (j = 0; j<s1 + s2; j++)
	{

		for (i = 0; i<s2; i++)		//���ۼ� 
			k += a[i][s1 + s2 - j - 1];

		k += pls;
		pls = 0;				//��λ���� 

		num3 += k % 10 + 48;
		pls = k / 10;

		k = 0;				//���ۼ����� 
	}
	//************************************************* 
	j = 0;
	while (num3[num3.length() - j - 1] == '0')
		++j;
												//ȥ�����λǰ��� 0						
	for (i = 0; i<num3.length() - j; i++)
		rlt += num3[num3.length() - i - j - 1];
	//**************************************************
	//�ͷſռ�
	for (int i = 0; i<s2; i++)
	{
		delete[] a[i];
		a[i] = NULL;
	}
	delete[] a;
	a = NULL;
	return rlt;
}
/*
	��������F_plus(string num1,string num2)
	����   ��ʵ���ַ����ӷ�����
*/
string F_plus(string num1, string num2)	
{
	int i;
	string rlt, num3;
	int s1, s2, s;
	s1 = num1.length();
	s2 = num2.length();
	s = s1 >= s2 ? s1 : s2;
	if (s1>s2)
	{
		for (i = 0; i<s1 - s2; i++)
			num2 = "0" + num2;
	}
	else if (s1<s2)
	{
		for (i = 0; i<s1 - s2; i++)
			num1 = "0" + num1;
	}

	int k;
	int pls = 0;
	for (i = 0; i<s; i++)
	{

		k = (num1[s - i - 1] - 48) + (num2[s - i - 1] - 48) + pls;
		pls = 0;
		num3 += k % 10 + 48;
		pls = k / 10;
		k = 0;
	}
	if (pls)
		num3 += pls + 48;
	for (i = 0; i<num3.length(); i++)
		rlt += num3[num3.length() - i - 1];
	return rlt;
}
/*
	��������fact(int n)
	���ܣ�����׳�
*/
string fact(int n)
{
	string x1 = "1";
	string x2 = "1";
	int i;
	for (i = 1; i<n; i++)
	{

		x2 = F_plus(x2, "1");			
		x1 = F_multi(x1, x2);

	}
	return x1;
}