#include <iostream>
#include <queue>

using namespace std;

struct Location
{
	int x;
	int y;
};

struct QueueNode
{
	Location loc;
	int distance;
};

// These arrays are used to get row and column numbers of 4 neighbours of a given cell
int rowNum[] = { -1, 0, 0, 1 };
int colNum[] = { 0, -1, 1, 0 };

int BFS(int** matrix, int row, int col, Location src)
{
	if (matrix[src.x][src.y] == 1)
		return -1;

	bool** visited = new bool* [row];
	for (int i = 0; i < row; ++i)
	{
		visited[i] = new bool[col];
		for (int j = 0; j < col; ++j)
		{
			visited[i][j] = false;
		}
	}

	visited[src.x][src.y] = true;

	queue<QueueNode> q;
	q.push({ src, 1 });

	while (!q.empty())
	{
		QueueNode curr = q.front();
		Location loc = curr.loc;

		if (loc.x == 0 || loc.y == 0 || loc.x == row - 1 || loc.y == col - 1)
			return curr.distance;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int r = loc.x + rowNum[i];
			int c = loc.y + colNum[i];

			if (matrix[r][c] == 0 && !visited[r][c])
			{
				visited[r][c] = true;
				QueueNode AdjCell = { {r, c}, curr.distance + 1 };
				q.push(AdjCell);
			}
		}
	}
	return -1;
}

int main()
{
	int n, m, r, c;
	cin >> n >> m >> r >> c;

	int** A = new int* [n];

	for (int i = 0; i < n; ++i)
	{
		A[i] = new int[m];
		for (int j = 0; j < m; ++j)
		{
			cin >> A[i][j];
		}
	}

	cout << BFS(A, n, m, { r - 1,c - 1 });
}