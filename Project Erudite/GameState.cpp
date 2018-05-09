/***************************************************************************************************************************************/
/*!
\file          GameState.cpp
\author        Justin Cagle
\par           justin.cagle\@outlook.com
\date          5/8/2018
\brief
Project Erudite - Copyright © 2018 Justin Cagle

*/
/***************************************************************************************************************************************/

#include "GameState.h"
void GameState::change_state ( Engine* engine, GameState* state )
{
  engine->change_state(state);
}
