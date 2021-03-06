#include "GLSLProgramBase.h"

GLSLProgramBase::~GLSLProgramBase()
{
  int x = 5; x;
}

void GLSLProgramBase::onWindowsResized(int x, int y)
{
  glViewport(0, 0, x, y);
  render();
}

void GLSLProgramBase::init_()
{
  shaderProgram_ = std::make_unique<GLSLShaderCompiler>(getVertexShaderCode_(), getFragmentShaderCode_());
  programId_ = shaderProgram_->getProgramId();

  // Enable alpha
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_DEPTH_TEST);
}
