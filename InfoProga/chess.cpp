#include <iostream>
#include <string>
using namespace std;

struct queueNode
{
	int x, y;
	queueNode* next;
};
struct queue 
{
	queueNode* head;
	queueNode* tail;

	queue() : head(nullptr), tail(nullptr) {}

	void push(int x, int y)
	{
		queueNode* newN = new queueNode;
		newN->x = x;
		newN->y = y;
		newN->next = nullptr;

		if (!head && !tail)
		{
			head = tail = newN;
		}
		else
		{
			tail->next = newN;
			tail = newN;
		}
	}

	void pop()
	{
		if (head)
		{
			queueNode* temp = head;
			head = head->next;
			if (!head)
			{
				tail = nullptr;
			}
			delete temp;
		}
	}

	int frontX()
	{
		return head ? head->x : -1;
	}
	int frontY()
	{
		return head ? head->y : -1;
	}

	bool empty()
	{
		return head == nullptr;
	}
};

const int dx[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
const int dy[] = { 1, -1, 1, -1, 2, -2, 2, -2 };


string formatChange(int x, int y)
{
	string cell = "";
	cell += char('A' + x);
	cell += char('1' + y);
	return cell;
}


string ShortestPath(const string& start, const string& end)
{
	int startX = start[0] - 'A';
	int startY = start[1] - '1';
	int endX = end[0] - 'A';
	int endY = end[1] - '1';

	if (startX == endX && startY == endY)
	{
		return start;
	}

	bool used[8][8] = { false };

	int parentX[8][8];
	int parentY[8][8];

	for (int i = 0; i < 8; i += 1)
	{
		for (int j = 0; j < 8; j += 1)
		{
			parentX[i][j] = -1;
			parentY[i][j] = -1;
		}
	}

	queue q;

	used[startX][startY] = true;
	q.push(startX, startY);


	while (!q.empty())
	{
		int x = q.frontX();
		int y = q.frontY();
		q.pop();

		if (x == endX && y == endY)
		{
			break;
		}
		for (int i = 0; i < 8; i += 1)
		{
			int newX = x + dx[i];
			int newY = y + dy[i];
			if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8 && !used[newX][newY])
			{
				used[newX][newY] = true;
				parentX[newX][newY] = x;
				parentY[newX][newY] = y;
				q.push(newX, newY);
			}
		}
	}

	int pathX[64];
	int pathY[64];
	int pathLen = 0;

	int curX = endX, curY = endY;
	while (!(curX == startX && curY == startY))
	{
		pathX[pathLen] = curX;
		pathY[pathLen] = curY;
		pathLen+=1;

		int nextX = parentX[curX][curY];
		int nextY = parentY[curX][curY];
		curX = nextX;
		curY = nextY;
	}
	pathX[pathLen] = startX;
	pathY[pathLen] = startY;
	pathLen += 1;

	string res = "";
	for (int i = pathLen - 1; i >= 0; i-=1) 
	{
		res += formatChange(pathX[i], pathY[i]);
		if (i > 0) res += " ";
	}

	return res;
}

int main()
{
	string start, end;

	cout << "Input the starting cell:";
	cin >> start;
	cout << "Input the ending cell:";
	cin >> end;

	string path = ShortestPath(start, end);
	cout << "Input Shortest Path: " << path << endl;

}