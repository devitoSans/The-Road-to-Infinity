#pragma once


#include <bits/stdc++.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


namespace opengl {
    void updateFramebuffer(GLFWwindow* window, int width, int height);
    void changeColorWindow(float red, float green, float blue, float alpha);
    void userInput(GLFWwindow* window);

    class Shader {
        // NOTE : when accessing a variable or function of the class,
        //        remember to use a keyword 'this'. 
        //        Otherwise, it will behave differently in an unexpected time.
        private:
            unsigned int id;
            std::string shader_path;
            std::string shader_type;
            std::vector<std::string> shader_sources;

            void readSources(int& size_of_sources);
            void compileShader();
        
        public:
            void createShader(GLenum type, std::string path);
            unsigned int getId() {
                return this->id;
            }
            void deleteShader() {
                glDeleteShader(this->id);
            }

    };

    class Program {
        private:
            unsigned int id;
        public:
            Program(unsigned int vertex, unsigned int fragment);
            void checkSuccess(std::string name);
            unsigned int getId() {
                return this->id;
            }
            int getUniLoc(std::string name) {
                return glGetUniformLocation(this->id, name.c_str());
            }
    };

    class Object {
        private:
            unsigned int vao;
            unsigned int vbo;
            unsigned int ebo;

            size_t u_size_ver;
            const float* u_ver;
            size_t u_size_ind;
            const unsigned int* u_ind;

            void properties() {
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)0);

                glEnableVertexAttribArray(1);
                glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)(3*sizeof(float)));
            }
        public:
            struct {
                
            } edit;

            Object(size_t size_ver, const float* ver, 
                    size_t size_ind = 0, const unsigned int* ind = NULL);
            void generate();
            unsigned int getID() {
                return this->vao;
            }
    };

    class Texture {
        private:
            unsigned int id;

            void properties() {
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->edit.wrapType);	
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->edit.wrapType);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
            }
        public:
            struct {
                unsigned int wrapType = GL_REPEAT;
                unsigned int imageType = GL_RGBA;
            } edit;

            void generate(std::string path, std::string name);
            unsigned int getId() {
                return this->id;
            }
    };
};

namespace obj {
    extern const float triangle_vertices[3 * 6];
    extern const unsigned int triangle_indices[1 * 3];
};

void drawRecursive(glm::vec3 translate, glm::mat4 res, int id, int depth, int mny, float p, bool flag);