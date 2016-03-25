#include <iostream>
#include <vector>
#include <deque>
using namespace std;
struct MyPoint {
	int x;
	int y;
	MyPoint() : x(0), y(0) {}
	MyPoint(int x_, int y_) :x(x_), y(y_) {}
};
struct Line {
	MyPoint start;
	MyPoint end;
	Line() :start(MyPoint()), end(MyPoint()) {}
	Line(int x1, int y1, int x2, int y2) :start(MyPoint(x1, y1)), end(MyPoint(x2, y2)) {}
	Line(MyPoint s, MyPoint e) :start(MyPoint(s.x, s.y)), end(MyPoint(e.x,e.y)) {}
};
enum Direction { UP, DOWN, LEFT, RIGHT };
class Solution {
public:
	bool isSelfCrossing(vector<int>& x) {
		deque<Line> lines;
		Direction direction = Direction::RIGHT;
		if (x.size() <= 3)
			return false;
		lines.push_back(Line(0, 0, 0, 0));
		lines.push_back(Line(0, 0, 0, 0));
		lines.push_back(Line(0, 0, 0, x[0]));
		lines.push_back(Line(0, x[0], -x[1], x[0]));
		lines.push_back(Line(-x[1], x[0], -x[1], x[0] - x[2]));
		MyPoint current(-x[1], x[0] - x[2]);
		for (auto it = x.begin() + 3; it != x.end(); ++it) {
			MyPoint now(current.x, current.y);
			switch (direction)
			{
			case Direction::UP:
				now.y += *it;
				direction = ::LEFT;
				break;
			case Direction::LEFT:
				now.x -= *it;
				direction = ::DOWN;
				break;
			case Direction::DOWN:
				now.y -= *it;
				direction = ::RIGHT;
				break;
			case Direction::RIGHT:
				now.x += *it;
				direction = ::UP;
				break;
			}
			Line nowl(current, now);
			if (cross(nowl, *(lines.end() - 3)) ) {
				return true;
			}
			if (cross(nowl, *(lines.end() - 5))) {
				return true;
			}
			current = now;
			lines.push_back(nowl);
			lines.pop_front();
		}
		return false;
	}

	bool cross(const Line &aa, const Line &bb) {
		Line a, b;
		if (aa.start.x == aa.end.x) {
			a.start = MyPoint(aa.start);
			a.end = MyPoint(aa.end);
			b.start = MyPoint(bb.start);
			b.end = MyPoint(bb.end);
		}
		else {
			b.start = MyPoint(aa.start);
			b.end = MyPoint(aa.end);
			a.start = MyPoint(bb.start);
			a.end = MyPoint(bb.end);
		}

		auto ax = a.start.x;
		auto by = b.start.y;
		if ((b.start.x <= ax && ax<=b.end.x || b.end.x <= ax && ax<=b.start.x) &&
			(a.start.y <= by && by<=a.end.y || a.end.y <= by && by<=a.start.y))
			return true;
		return false;
	}
};

int main() {
	Solution s;
	vector<int> a = { 1, 1, 2, 1,1 };
	cout<<s.isSelfCrossing(a);
	getchar();
	return 0;
}