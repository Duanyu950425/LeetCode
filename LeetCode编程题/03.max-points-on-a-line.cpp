#include<iostream>
#include<stack>
#include<vector>
#include<map>
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
	bool compare(double a, double b)
	{
		if (fabs(a - b) < 1e-6)
			return true;
		else
			return false;
	}
	int maxPoints(vector<Point> &points) 
	{
		if (points.size() <= 2)
			return points.size();

		int ret = 0;
		for (int i = 0; i < points.size(); i++)
		{
			map<double, int> info;
			int vCn = 0;//垂直点
			int dCn = 0;//重复点
			int curmax = 1;//当前最大连接点数
			for (int j = i + 1; j < points.size(); j++)
			{
				double x_dis = points[i].x - points[j].x;
				double y_dis = points[j].y - points[j].y;
				if (compare(points[i].x, points[j].x) && compare(points[i].y, points[j].y))
					++dCn;
				else if (compare(x_dis, 0.0))
				{
					if (vCn == 0)
						vCn = 2;
					else
						++vCn;
					curmax = curmax > vCn ? curmax : vCn;
				}
				else
				{
					double k = y_dis / x_dis;
					if (info[k] == 0)
						info[k] = 2;
					else
						info[k]++;
					curmax = curmax > info[k] ? curmax : info[k];
				}
			}
			ret = ret > (curmax + dCn) ? ret : (curmax + dCn);
		}
		return ret;
	}
};

int main03()
{
	vector<Point> v;
	Point p1(0, 0), p2(-1, -1), p3(2, 2), p4(3, 4), p5(5, 0), p6(2, 0), p7(1, 3);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	//v.push_back(p4);
	//v.push_back(p5);
	//v.push_back(p6);
	//v.push_back(p7);

	Solution s;
	cout << s.maxPoints(v) << endl;
	
	return 0;
}