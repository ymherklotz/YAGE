#ifndef YAGE_EXPERIMENTAL_LOADER_H
#define YAGE_EXPERIMENTAL_LOADER_H

#include <string>
#include <vector>

#include <glad/glad.h>
#include <glm/glm.hpp>

namespace yage
{

extern void load_obj(std::string filename, std::vector<glm::vec4> &vertices,
                     std::vector<glm::vec3> &normals,
                     std::vector<GLushort> &elements);

} // namespace yage

#endif
