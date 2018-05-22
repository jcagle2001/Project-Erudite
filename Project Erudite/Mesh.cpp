#include "Mesh.h"
  Mesh::Mesh ()
  {
    m_vbo.clear();
  }

  Mesh::~Mesh ()
  {
    m_vbo.erase(m_vbo.begin(), m_vbo.end() - 1);
  }

Mesh& Mesh::operator= ( const Mesh& rhs )
  {
    Mesh temp;

    if(!rhs.m_vbo.empty ())
    {
      for (unsigned int i = 0; i < temp.m_vbo.size(); ++i)
      {
        temp.m_vbo[i] = rhs.m_vbo[i];
      }
    }

    return temp;
  }
