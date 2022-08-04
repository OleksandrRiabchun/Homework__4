#include <stdio.h>
#define N 5
#define M 5
// 1.���������� ��������� � �������������.����������� ������ ������� � ������������ � ���������� ���������� ���������.
// (�� ���� ��� ������ ����������� ������������� �� ���� ������ ���� ��� ������)
//��������, �����:
//1 1 1
//0 1 0
//0 1 1 

int obstacleCourse(int x, int y) // ���������� ��������� � �������������
{
    int Map[N][M] = { {0,1,1,1,1},
                        {1,1,1,1,1},
                        {1,0,1,1,1},
                        {1,1,1,0,1},
                        {1,1,1,1,1} }; // ������ ����������� (���� - �����������)
    if (Map[x][y] == 0)
        return 0;
    else if (x == 0 || y == 0)
        return 1;
    else
        return obstacleCourse(x, y - 1) + obstacleCourse(x - 1, y);
}

int routeWithoutObstacles(int x, int y) // ���������� ��������� ��� �����������
{
    if (x == 0 && y == 0)
        return 0;
    else if (x == 0 || y == 0)
        return 1;
    else
        return routeWithoutObstacles(x, y - 1) + routeWithoutObstacles(x - 1, y);

}

void main()
{
    const int rows = N;
    const int cols = M;
    int arr[N][M];
    int i;
    int j;

    puts("Number of routes with obstacles");
    for (i = 0; i < rows; i++) // ���������� ��������� � �������������
    {
        for (j = 0; j < cols; j++)
        {
            arr[i][j] = obstacleCourse(i, j);
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }

    puts("Number of routes without obstacles");
    for (i = 0; i < rows; i++) // ���������� ��������� ��� �����������
    {
        for (j = 0; j < cols; j++)
        {
            arr[i][j] = routeWithoutObstacles(i, j);
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
}