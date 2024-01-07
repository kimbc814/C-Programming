#include <iostream>

#define	MAX_POINT	100000

using namespace std;

typedef long long ll;

typedef struct Point {
	int x;
	int y;
	bool operator<(const Point& p) {
		if (y != p.y) return x < p.x;
		else return y < p.y;
	}
	Point operator-(const Point& p) {
		Point ret = { x - p.x, y - p.y };
		return ret;
	}
} Point;

Point p[MAX_POINT];
int stack[MAX_POINT];
int N;

ll ccw(Point &A, Point &B, Point &C) {
	Point BO = B - A;
	Point CO = C - A;
	return 1LL * ((ll)BO.x * (ll)CO.y - (ll)BO.y * (ll)CO.x);
}
bool leftTurn(Point& A, Point& B, Point& C) { return ccw(A, B, C) > 0; }

bool comp(Point &A, Point &B)
{
	Point AO = A - p[0];
	Point BO = B - p[0];

	ll outerProduct = 1LL * ((ll)AO.x * (ll)BO.y - (ll)AO.y * (ll)BO.x);
	if (outerProduct != 0)
		return (outerProduct > 0);
	if (A.y != B.y)
		return A.y < B.y;
	return A.x < B.x;
}

void quickSortByAngle(int first, int last)
{
	if (first >= last) return;

	int pivot = first;
	int i = first + 1;
	int j = last;

	while (i <= j)
	{
		while (comp(p[i], p[pivot]) && i <= last) i++;
		while (!comp(p[j], p[pivot]) && j > first) j--;

		if (i >= j) break;

		Point tmp = p[i];
		p[i] = p[j];
		p[j] = tmp;
	}

	Point tmp = p[j];
	p[j] = p[pivot];
	p[pivot] = tmp;

	quickSortByAngle(first, j - 1);
	quickSortByAngle(j + 1, last);
}

int convexHull()
{
	int minX = 1000000000, minY = 1000000000, minIdx = 0;;
	for (int i = 0; i < N; i++) {
		if (minY > p[i].y || (minY == p[i].y && minX > p[i].x))
		{
			minX = p[i].x;
			minY = p[i].y;
			minIdx = i;
		}
	}
	p[minIdx].x = p[0].x;
	p[minIdx].y = p[0].y;
	p[0].x = minX;
	p[0].y = minY;

	quickSortByAngle(1, N - 1);

	int idx = -1;
	stack[++idx] = 0;
	stack[++idx] = 1;

	int next = 2;
	while (next < N)
	{
		while ((idx + 1) >= 2)
		{
			int second = stack[idx--];
			int first = stack[idx];

			if (leftTurn(p[first], p[second], p[next]))
			{
				stack[++idx] = second;
				break;
			}
		}

		stack[++idx] = next++;
	}

	return idx + 1;
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> p[i].x >> p[i].y;

	cout << convexHull() << '\n';

	return 0;
}
