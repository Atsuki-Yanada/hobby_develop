#pragma once

class OnWhere {
public:
	bool _ground;
	bool _ceiling;
	bool _right;
	bool _left;
	OnWhere() : _ground(false), _ceiling(false), _right(false), _left(false) {}
	OnWhere(bool g, bool c, bool rw, bool lw): _ground(g), _ceiling(c), _right(rw), _left(lw){}
	void initialize(){
		_ground = false;
		_ceiling = false;
		_right = false;
		_left = false;
	}
};