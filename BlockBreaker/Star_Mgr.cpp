#include "Star_Mgr.h"
#include "Define.h"
#include "DxLib.h"


Star_Mgr::Star_Mgr()
{
	for (int i = 0; i < STAR_NUM; ++i)
		star[i] = new Star;
}


Star_Mgr::~Star_Mgr()
{
	for (int i = 0; i < STAR_NUM; ++i)
		delete star[i];
}

void Star_Mgr::update()
{
	for (int i = 0; i < STAR_NUM; ++i)
		star[i]->update();
}

void Star_Mgr::draw()
{
	for (int i = 0; i < STAR_NUM; ++i)
		star[i]->draw();
}
