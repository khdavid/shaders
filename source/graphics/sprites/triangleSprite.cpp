#include <array>
#include "triangleSprite.h"


TriangleSprite::TriangleSprite(Triangle2D triangle):
  triangle_(triangle)
{
  std::array<float, 6> vertexData;

  vertexData[0] = triangle[0].x();
  vertexData[1] = triangle[0].y();

  vertexData[2] = triangle[1].x();
  vertexData[3] = triangle[1].y();

  vertexData[4] = triangle[2].x();
  vertexData[5] = triangle[2].y();

  // Enable alpha
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glGenBuffers(1, &vboId_);
  glBindBuffer(GL_ARRAY_BUFFER, vboId_);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData.data(), GL_STATIC_DRAW);

}

 TriangleSprite::~TriangleSprite()
{
  if (vboId_)
  {
    glDeleteBuffers(1, &vboId_);
  }
}


void TriangleSprite::render(int x, int y)
{

  const char* name = "vertexPosition";
  auto attribute_coord2d = glGetAttribLocation(1, name);
  const int cDim = 2;

  glVertexAttribPointer(
    attribute_coord2d, // attribute
    cDim,              // number of elements per vertex, here (x,y)
    GL_FLOAT,          // the type of each element
    GL_FALSE,          // take our values as-is
    0,                 // no extra data between each position
    0);                // offset of first element
  glDrawArrays(GL_TRIANGLES, 0, 3);

}


