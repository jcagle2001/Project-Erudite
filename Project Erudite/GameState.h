/***************************************************************************************************************************************/
/*!
\file          GameState.h
\author        Justin Cagle
\par           justin.cagle\@outlook.com
\date          5/8/2018
\brief
Project Erudite - Copyright © 2018 Justin Cagle

*/
/***************************************************************************************************************************************/

#pragma once
#include "Engine.h"

class Engine;

class GameState
{
public:
  virtual ~GameState () = default;

  virtual void init() = 0;
  virtual void shutdown() = 0;

  virtual void pause() = 0;
  virtual void resume() = 0;

  virtual void handle_events(Engine* engine) = 0;
  virtual void update(Engine* engine) = 0;
  virtual void draw(Engine* engine) = 0;

  void change_state(Engine* engine, GameState* state);

protected:
  GameState() {}
};
