#pragma once
#include "triangleSprite.h"

class MondelbrotSprite : public TriangleSprite
{
public:
  virtual void init() override;
  virtual void render(int x, int y);
private:
  GLint fadeUniform_ = 0;

  virtual std::string getVertexShaderCode_() const;
  virtual std::string getFragmentShaderCode_() const;
};

