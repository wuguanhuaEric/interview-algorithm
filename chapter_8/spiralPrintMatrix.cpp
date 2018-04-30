#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void spiralPrintMatrix(vector<vector<int> > &matrix)
{
	if (matrix.empty())
		return;
	int m = matrix.size();
	int n = matrix[0].size();

	int tRow = 0, tCol = 0, dRow = m - 1, dCol = n - 1;
	if (tRow == dRow)
	{
		for (int i = tCol; i <= dCol; ++i)
		{
			cout << matrix[tRow][i] << " ";
		}
	}
	else if (tCol == dCol)
	{
		for (int i = tRow; i <= dRow; ++i)
		{
			cout << matrix[i][tCol] << " ";
		}
	}
	else
	{
		while (tRow <= dRow && tCol <= dCol)
		{
			int r = tRow, c = tCol;
			for (; c < dCol; ++c)
				cout << matrix[r][c] << " ";
			for (; r < dRow; ++r)
				cout << matrix[r][c] << " ";
			for (; c > tCol; --c)
				cout << matrix[r][c] << " ";
			for (; r > tRow; --r)
				cout << matrix[r][c] << " ";

			++tRow; ++tCol;
			--dRow; --dCol;
		}
	}

	cout << endl;
}

int main()
{
	vector<vector<int> > matrix = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
	vector<vector<int> > matrix2 = { {1, 2, 3, 4} };
	vector<vector<int> > matrix3 = { { 1 }, { 2 }, { 3 }, { 4 } };

	spiralPrintMatrix(matrix);
	spiralPrintMatrix(matrix2);
	spiralPrintMatrix(matrix3);

	system("pause");
	return 0;
}