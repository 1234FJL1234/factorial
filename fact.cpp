#include<iostream>
#include<string>		//�ַ���ģ����
#include<fstream>		//�ļ���д
#include<time.h>
#include"_calc.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main()
{
	string x3;	//������
	int n;		//��������
	long int i;	//��λ
	clock_t start, finish;	//��������ʱ��
	ofstream outfile;		//	����ļ�
	outfile.open("C:\\Users\\lim\\Desktop\\ssd.txt");//����ļ�·��
	while (1)
	{
		cout << "input a number:" << endl;
		cin >> n;
		cout << endl;
		start = clock() / CLOCKS_PER_SEC;

		x3 = fact(n);			//***�׳�

		finish = clock() / CLOCKS_PER_SEC;
		//**************************************������λ
		i = 0;
		while (x3[i] != '\0')
			++i;				//λ����׳˵Ĺ�ϵi=log(n!)+1
		//*****************************
		outfile << x3 << endl;
		outfile.close();
		//	cout<<endl;
		cout << "the length of number:" << i << endl;
		cout << "elapsed time:" << finish - start << "s" << endl;
	}

	return 0;
}
