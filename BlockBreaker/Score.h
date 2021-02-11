#pragma once

class Combo;
class Tama;

class Score
{
private:
	int scoreboardG;
	int score;
public:
	Score();
	~Score();
	void update(int);
	void draw(Tama&)const;
};
