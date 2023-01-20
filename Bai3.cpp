#include <iostream>
#include <vector>

using namespace std;

int sparseTable[106][106];

int min(int a, int b)
{
	if (a < b) return a;
	return b;
}

void preprocess(int a[], int n)
{
	for (int i = 0; i < n; i++)
		sparseTable[i][0] = a[i];

	for (int j = 1; (1 << j) <= n; j++) { // (1 << j) means power(2,j) = 2^j
		for (int i = 0; (i + (1 << j) - 1) < n; i++) {
			if (sparseTable[i][j - 1] <
				sparseTable[i + (1 << (j - 1))][j - 1])
				sparseTable[i][j] = sparseTable[i][j - 1];
			else
				sparseTable[i][j] =
				sparseTable[i + (1 << (j - 1))][j - 1];
		}
	}
}

int rmq(int l, int r)
{
	int j = (int)log2(r - l + 1);
	if (sparseTable[l][j] <= sparseTable[r - (1 << j) + 1][j])
		return sparseTable[l][j];
	else
		return sparseTable[r - (1 << j) + 1][j];
}

int main()
{
	int n, m, i, j, k, sum;
	int a[106];

	cin >> n;
	for (k = 0; k < n; ++k)
	{
		cin >> a[k];
	}

	preprocess(a, n);

	sum = 0;
	cin >> m;
	for (k = 0; k < m; ++k)
	{
		cin >> i >> j;
		sum += rmq(i, j);
	}
	cout << sum;
}