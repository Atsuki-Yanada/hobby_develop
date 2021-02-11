#pragma once
class Combo
{
private:
	int combo;
public:
	Combo();
	~Combo();
	void plus() { combo++; }
	void zero() { combo = 0; }
	void draw()const;
	int getCombo() { return combo; }
};

