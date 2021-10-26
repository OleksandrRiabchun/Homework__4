#include <stdio.h> 
#define N 8 // ������ ����
#define M 8 // ���������� �����
//3.��������� ������ ���� ��������� ����� �������� NxM, ������ ����� ��� ���� �����
//�� ������ ����.����� �������� ������� ����� ��, ��� � � ������ � 8 ������.
//������� ������ � �������� ��������� ����.

const int HODx[M] = { 1, 2, 2, 1, -1, -2, -2, -1 };
const int HODy[M] = { 2, 1, -1, -2, -2, -1, 1, 2 };

void PrintField(int A[N][N])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%4d", A[i][j]);
        }
        printf("\n");
    }
}

void Horse(int field[N][N], int num, int y, int x)
{
    static long count = 0; //���������� ����� ����� ����
    field[y][x] = num++; // �������� ��� ���� �� ������, � ������� �� �����
    count++;
    if (num > N * N) // ���� ��� ���� �������
    {
        printf("Number of total knight moves = %d\n\n", count); // �� ���� �������
        PrintField(field); // ����� ����
        exit();
    }
    for (int i = 0; i < M; i++)
    {
        int iNew = y + HODy[i]; // ����� ��� �� ��� y
        int jNew = x + HODx[i]; // ����� ��� �� ��� �

        if ((field[iNew][jNew] != 0) || (iNew < 0 || iNew > N - 1) || (jNew < 0 || jNew > N - 1))
            continue;
        Horse(field, num, iNew, jNew); // ��� ����� �� ��������� ������ 

        field[iNew][jNew] = 0; // �������� ������, ���� � ����� �� ������� �������
    }
}

void Zero(int a[N][N])
{
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            a[i][j] = 0;
}

void main()
{
    int Field[N][N]; // ��������� ����
    Zero(Field);     // ��������� ����
    Horse(Field, 1, 0, 0);
}