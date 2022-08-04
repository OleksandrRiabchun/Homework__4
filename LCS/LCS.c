#include <stdio.h> 
#include <string.h> 
// 2. ������ ������ � ���������� ����� ������������ ������������������ � ������� �������.
int LCS(char* x, char* y) { // ������ ��� ���� � ���������
	if (*x == '\0' || *y == '\0') // ���� ���� �� ����� ����� �����
		return 0;
	else if (*x == *y)
		return LCS(x + 1, y + 1) + 1;
	else {
		int x1 = LCS(x + 1, y);
		int x2 = LCS(x, y + 1);
		return (x1 > x2) ? x1 : x2;
	}
}

void LCS_2(char* x, char* y) { // � ������� �������
	int matrix[20][20] = { 0 };
	for (int i = 1; i < strlen(y) + 1; i++)
	{
		for (int j = 1; j < strlen(x) + 1; j++)
		{
			if (y[i - 1] == x[j - 1])
			{
				matrix[i][j] = matrix[i - 1][j - 1] + 1;// ���� ����� ����������, �� �������� +1 � ��������
			}
			else
			{
				matrix[i][j] = (matrix[i - 1][j] > matrix[i][j - 1]) ? matrix[i - 1][j] : matrix[i][j - 1];
			}
		}
	}

	for (int n = 0; n < strlen(y) + 1; n++) // ����� �������
	{
		for (int m = 0; m < strlen(x) + 1; m++)
		{
			printf("%3d", matrix[n][m]);
		}
		printf("\n");
	}
}

void main() {
	char a[] = "geekbrains";
	char b[] = "geekminds";
	printf("%d\n\n", LCS(&a, &b));
	LCS_2(&a, &b);
}