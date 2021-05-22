#include <stdio.h>
#include <iostream>
#include "_Matrix.h"
 
//带速度变量卡尔曼滤波
using namespace std;
 
//打印2维矩阵
void printf_matrix(_Matrix *A)
{
	int i = 0;
	int j = 0;
	int m = 0;
	int n = 0;
	
	m = A->m;
	n = A->n;
	for (i = 0;i < m;i++)
	{
		for (j = 0;j < n;j++)
		{
			printf("%f\t",A->read(i,j));
		}
		printf("\n");
	}
}
 
int main()
{
	int i = 0;
	int j = 0;
	int k = 0;
	_Matrix_Calc m_c;
	_Matrix m1(3,3);
	_Matrix m2(3,3);
	_Matrix m3(3,3);
	
	//初始化内存
	m1.init_matrix();
	m2.init_matrix();
	m3.init_matrix();
	
	//初始化数据
	k = 1;
	for (i = 0;i < m1.m;i++)
	{
		for (j = 0;j < m1.n;j++)
		{
			m1.write(i,j,k++);
		}
	}
	
	for (i = 0;i < m2.m;i++)
	{
		for (j = 0;j < m2.n;j++)
		{
			m2.write(i,j,k++);
		}
	}
	
	//原数据
	printf("A:\n");
	printf_matrix(&m1);
	printf("B:\n");
	printf_matrix(&m2);
	
	printf("A:行列式的值%f\n",m_c.det(&m1));
	
	//C = A + B
	if (m_c.add(&m1,&m2,&m3) > 0)
	{
		printf("C = A + B:\n");
		printf_matrix(&m3);
	}
	
	//C = A - B
	if (m_c.subtract(&m1,&m2,&m3) > 0)
	{
		printf("C = A - B:\n");
		printf_matrix(&m3);
	}
	
	//C = A * B
	if (m_c.multiply(&m1,&m2,&m3) > 0)
	{
		printf("C = A * B:\n");
		printf_matrix(&m3);
	}
	
	//C = AT
	if (m_c.transpos(&m1,&m3) > 0)
	{
		printf("C = AT:\n");
		printf_matrix(&m3);
	}
	
	/*
	m1.write(0,0,0);
	m1.write(0,1,1);
	m1.write(0,2,0);
	m1.write(1,0,1);
	m1.write(1,1,1);
	m1.write(1,2,-1);
	m1.write(2,0,0);
	m1.write(2,1,-2);
	m1.write(2,2,3);
	*/
	if (m_c.inverse(&m1,&m3) > 0)
	{
		printf("C = A^(-1):\n");
		printf_matrix(&m3);
	}
	
	getchar();
	return 0;
}