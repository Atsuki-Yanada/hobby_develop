#pragma once

class Velocity {
public:
	double _x, _y;
	
	Velocity() : _x(0), _y(0) {}
	Velocity(double x, double y) : _x(x), _y(y) {}
	/*
	static Velocity max(const Velocity& vec1, const Velocity& vec2){
		Velocity vec;
		vec = ((vec1._x * vec1._x + vec1._y * vec1._y >= vec2._x * vec2._x + vec2._y * vec2._y) ? vec1 : vec2);
		return vec;
	}
	
	static Velocity min(const Velocity& vec1, const Velocity& vec2){
		Velocity vec;
		vec = ((vec1._x * vec1._x + vec1._y * vec1._y <= vec2._x * vec2._x + vec2._y * vec2._y) ? vec1 : vec2);
		return vec;
	}

	bool operator<=(const Velocity& right) {
		return (_x * _x + _y * _y <= right._x * right._x + right._y * right._y);
	}

	bool operator>=(const Velocity& right) {
		return (_x * _x + _y * _y >= right._x * right._x + right._y * right._y);
	}

	bool operator<(const Velocity& right) {
		return (_x * _x + _y * _y < right._x * right._x + right._y * right._y);
	}

	bool operator>(const Velocity& right) {
		return (_x * _x + _y * _y > right._x * right._x + right._y * right._y);
	}

	bool operator==(const Velocity& right) {
		return (_x == right._x && _y == right._y);
	}
	*/
};