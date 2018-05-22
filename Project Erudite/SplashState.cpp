/***************************************************************************************************************************************/
/*!
\file          SplashState.cpp
\author        Justin Cagle
\par           justin.cagle\@outlook.com
\date          5/8/2018
\brief
Project Erudite - Copyright © 2018 Justin Cagle

*/
/***************************************************************************************************************************************/

#include "SplashState.h"
#include <GL/glew.h>

SplashState SplashState::splashstate;

void SplashState::init ( )
{
  SDL_Window* window = SDL_GL_GetCurrentWindow();
  glClearColor(0, 0, 1, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  SDL_GL_SwapWindow(window);

  const char* vertex_shader =
    "#version 330 core\n\
    layout (location = 0) in vec3 aPos;\
    void main()\
    {\
      gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f);\
    }";

  const char* frag_shader =
    "#version 330 core\n\
    out vec4 FragColor;\
    void main()\
    {\
      FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\
    }";

  unsigned int vertexShader;
  vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertex_shader, NULL);
  glCompileShader(vertexShader);

  unsigned int fragShader;
  fragShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragShader, 1, &frag_shader, NULL);
  glCompileShader(fragShader);

  unsigned int program;
  program = glCreateProgram();

  glAttachShader(program, vertexShader);
  glAttachShader(program, fragShader);
  glLinkProgram(program);

  glUseProgram(program);

  glDeleteShader(vertexShader);
  glDeleteShader(fragShader);
}

void SplashState::shutdown ( )
{
  
}

void SplashState::pause ( )
{
  
}

void SplashState::resume ( )
{
  
}

void SplashState::handle_events ( Engine* engine )
{
  if(SDL_PollEvent(&event))
  {
    if (event.key.keysym.sym == SDLK_ESCAPE || event.window.event == SDL_WINDOWEVENT_CLOSE)
      engine->quit();
  }
}

void SplashState::update ( Engine* engine )
{

}

void SplashState::draw ( Engine* engine )
{
  

}

