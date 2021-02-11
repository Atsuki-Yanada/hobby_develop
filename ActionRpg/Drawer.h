#pragma once
#include"Singleton.h"
#include<functional>
#include<memory>
#include<queue>

//前方宣言
class Camera;
class IPlayerInfo;

class Drawer : public Singleton<Drawer>
{
public:
	class DrawnThing {
	public:
		float _priority;
		double _x, _y;
		double _size;//-=================================今だけ================================
		int _handle;
		int _color;
	};
private:
	std::unique_ptr<Camera> _camera;

	//描画対象のユニットの並び替えを定義するラムダ式
	std::function<bool(const DrawnThing&, const DrawnThing&)> lambda =
		[](const DrawnThing& u1, const DrawnThing& u2) -> bool {return u1._priority < u2._priority; };

	//描画オブジェクト
	std::priority_queue < DrawnThing, std::vector<DrawnThing>, decltype(lambda)> _drawnThing;
public:
	Drawer();
	~Drawer();

	void setUnitManager(const std::shared_ptr<IPlayerInfo>& playerInfo);
	void update();

	void addDrawnThing(DrawnThing&& drawnThing);
	void draw();

};

