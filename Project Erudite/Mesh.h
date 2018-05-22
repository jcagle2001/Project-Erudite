#pragma once
#include <glm/glm.hpp>
#include <vector>

struct Vertex
{
  glm::vec3 point;
  glm::vec4 color;
};

class Mesh
{
  public:
    Mesh();
    ~Mesh();
    Mesh& operator=(const Mesh& rhs);

  private:
    std::vector<Vertex> m_vbo;
};