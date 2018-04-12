#include "loader.h"

#include "../core/exception.h"

#include <algorithm>
#include <fstream>
#include <regex>
#include <sstream>

namespace yage
{

const std::vector<std::regex> ele_regs({"^(\\d+)$", "^(\\d+)\\/(\\d+)$",
                                        "^(\\d+)\\/\\/(\\d+)$",
                                        "^(\\d+)\\/(\\d+)\\/(\\d+)$"});

void load_obj(std::string filename, std::vector<glm::vec4> &vertices,
              std::vector<glm::vec3> &normals, std::vector<GLushort> &elements)
{
    std::ifstream in(filename, std::ios::in);

    if (!in.is_open()) {
        throw FileLoadException("Could not load obj file '" + filename + "'");
    }

    std::string line;

    while (getline(in, line)) {
        if (line.substr(0, 2) == "v ") {
            std::istringstream s(line.substr(2));
            glm::vec4 v;
            s >> v.x >> v.y >> v.z;
            v.w = 1.f;
            vertices.push_back(v);
        } else if (line.substr(0, 2) == "f ") {
            std::istringstream s(line.substr(2));
            GLushort a, b, c;
            s >> a >> b >> c;
            a--, b--, c--;
            elements.push_back(a);
            elements.push_back(b);
            elements.push_back(c);
        } else if (line.substr(0, 2) == "vn ") {
            std::for_each(ele_regs.begin(), ele_regs.end(), [](std::regex re) {
                        
            });
            std::istringstream s(line.substr(2));
            glm::vec3 v;
            s >> v.x >> v.y >> v.z;
            normals.push_back(v);
        } else {
            // do nothing otherwise
        }
    }

    in.close();
}

} // namespace yage
