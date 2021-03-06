#pragma once
#include "glimac/common.hpp"
#include <vector>

namespace glimac {

    class CubeGL{
        private:
            std::vector<ShapeVertex> m_vertices;
            GLsizei m_size_vertices; //faster access, don't change in time
            void addTriangle(glm::vec3 const& first_position, glm::vec3 const& switch_position1, glm::vec3 const& switch_position2,
                             glm::vec3 const& third_position, glm::vec3 const& normal, glm::vec2 *texCoords);
        public:
            CubeGL();
            ~CubeGL();
            GLuint m_vbo;

            const ShapeVertex * getDataPointer() const;
            GLsizei sizeVertices() const;

            void generateVbo(GLuint * vbo) const; //vbo parameter: customizable for outside
            void configureVao(GLuint *vao, const int indexPositionShader, const int indexNormalShader, const int indexTextureCoordShader) const;
    };
}
