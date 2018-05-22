#pragma once
#include <SDL2/SDL.h>
#include <GL/glew.h>


class Window
{
  public:
    Window();
    ~Window();

  private:
    SDL_Window* m_window;
    SDL_GLContext m_context;
};

