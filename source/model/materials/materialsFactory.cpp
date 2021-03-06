#include "materialsFactory.h"

namespace MaterialsFactory
{
const Color Black = { 0, 0, 0 };
const Color White = { 255, 255, 255 };
const Color Red = { 255, 0, 0 };
const Color Lime = { 0, 255, 0 };
const Color Blue = { 0, 0, 255 };
const Color Yellow = { 255, 255, 0 };
const Color Aqua = { 0, 255, 255 };
const Color Magenta = { 255, 0, 255 };
const Color Silver = { 192, 192, 192 };
const Color Gray = { 128, 128, 128 };
const Color Maroon = { 128, 0, 0 };
const Color Olive = { 128, 128, 0 };
const Color Green = { 0, 128, 0 };
const Color Purple = { 128, 0, 128 };
const Color Teal = { 0, 128, 128 };
const Color Navy = { 0, 0, 128 };


Material Specular(const Color& color, float sharpness)
{
  Material result;
  result.ambient = 0.5 * color;
  result.diffuse = 0.3 * color;
  result.specular = 0.7 * color;
  result.sharpness = sharpness;
  return result;
}

Material Diffuse(const Color & color, float sharpness)
{
  Material result;
  result.ambient = 0.2 * color;
  result.diffuse = 0.8 * color;
  result.sharpness = sharpness;
  return result;
}

}
