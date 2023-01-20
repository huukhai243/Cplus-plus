#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int findMaxAreaByHistogram(int hist[], int length)
{
	stack<int> s;

	int max_area = 0;
	int tp;
	int area_with_top;

	int i = 0;
	while (i < length) {
		if (s.empty() || hist[s.top()] <= hist[i])
			s.push(i++);
		else {
			tp = s.top();
			s.pop();
			area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
			if (max_area < area_with_top)
				max_area = area_with_top;
		}
	}

	while (!s.empty()) {
		tp = s.top();
		s.pop();
		area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

		if (max_area < area_with_top)
			max_area = area_with_top;
	}

	return max_area;
}

int maxRectangle(int** matrix, int row, int col)
{
	int result = findMaxAreaByHistogram(matrix[0], col);

	for (int i = 1; i < row; i++) {
		for (int j = 0; j < col; j++)
			if (matrix[i][j] != 0)
				matrix[i][j] += matrix[i - 1][j];

		result = max(result, findMaxAreaByHistogram(matrix[i], col));
	}

	return result;
}
int main()
{
	int n, m;
	cin >> n;
	cin >> m;
	int** A = new int* [n];

	for (int i = 0; i < n; ++i)
	{
		A[i] = new int[m];
		for (int j = 0; j < m; ++j)
		{
			cin >> A[i][j];
		}
	}
	cout << maxRectangle(A, n, m);
	return 0;
}