#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
	int maxPoints(vector<Point> &points) {
		if (points.size() <= 2)
			return points.size();
	}
};

int main()
{
	return 0;
}