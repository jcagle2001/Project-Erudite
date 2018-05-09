/***************************************************************************************************************************************/
/*!
\file          SplashState.h
\author        Justin Cagle
\par           justin.cagle\@outlook.com
\date          5/8/2018
\brief
Project Erudite - Copyright © 2018 Justin Cagle

*/
/***************************************************************************************************************************************/

#pragma once
#include "GameState.h"

class SplashState : public GameState
{
public:
  void init() override;
  void shutdown() override;

  void pause() override;
  void resume() override;

  void handle_events(Engine* engine) override;
  void update(Engine* engine) override;
  void draw(Engine* engine) override;

  static SplashState* instance() { return &splashstate; }

protected:
  SplashState() {};
private:
  static SplashState splashstate;
  SDL_Event event;
};

