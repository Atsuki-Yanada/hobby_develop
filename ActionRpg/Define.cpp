#include "Define.h"

const bool Define::DEBUG_FLAG = true;
const int Define::GAME_WINDOW_X = 1200;
const int Define::GAME_WINDOW_Y = 600;
const double Define::PLAYER_SIZE = 30.0;
const int Define::PLAYER_JUMP_COUNT = 1;
const double Define::STAGE_BLOCK_SIZE = 50.0;
const int Define::STAGE_BLOCK_NUM_X = static_cast<int>(Define::GAME_WINDOW_X / Define::STAGE_BLOCK_SIZE);
const int Define::STAGE_BLOCK_NUM_Y = static_cast<int>(Define::GAME_WINDOW_Y / Define::STAGE_BLOCK_SIZE);

Define::Define()
{
}


Define::~Define()
{
}