#include <dve/header.h>

void opengl::updateFramebuffer(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void opengl::changeColorWindow(float red, float green, float blue, float alpha) {
    glClearColor(red, green, blue, alpha);
    glClear(GL_COLOR_BUFFER_BIT);
}

void opengl::userInput(GLFWwindow* window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

void opengl::Shader::readSources(int& size) {
    std::ifstream myfile(this->shader_path);
    if(!myfile.is_open()) {
        std::cout << "ERROR::SHADER::" << this->shader_type << "::UNABLE_TO_READ_SOURCES" << std::endl;
        return;
    }

    // Read the source and store it using array of strings
    std::string temporary_string;
    while(getline(myfile, temporary_string)) {
        this->shader_sources.push_back(temporary_string);
        this->shader_sources.push_back("\n");
    }
    myfile.close();

    size = this->shader_sources.size();
}

void opengl::Shader::compileShader() {
    int shader_sources_size = 0;
    this->readSources(shader_sources_size);

    // Convert it to array of const char*
    // be carefull to not 'destroy' the array of string
    // before passing it to the function.
    std::vector<const char*> sources;
    for(auto& i : this->shader_sources) {
        sources.push_back(i.c_str());
    }
    // const char* is a pointer, so it points the memory address of each strings.

    glShaderSource(this->id, shader_sources_size, &sources[0], NULL);
    glCompileShader(this->id);

    int success = 1;
    glGetShaderiv(this->id, GL_COMPILE_STATUS, &success);
    if(!success) {
        char infoLog[GL_INFO_LOG_LENGTH];
        glGetShaderInfoLog(this->id, GL_INFO_LOG_LENGTH, NULL, infoLog);
        std::cout << "ERROR::SHADER::" << this->shader_type << "::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}

void opengl::Shader::createShader(GLenum type, std::string path) {
    if(type == GL_VERTEX_SHADER) {
        this->shader_type = "VERTEX";
    }
    else if(type == GL_FRAGMENT_SHADER) {
        this->shader_type = "FRAGMENT";
    }
    this->id = glCreateShader(type);
    this->shader_path = path;

    this->compileShader();
}

void opengl::Program::checkSuccess(std::string name) {
    int success;
    glGetProgramiv(this->id, GL_LINK_STATUS, &success);
    if(!success) {
        char infoLog[GL_INFO_LOG_LENGTH];
        glGetProgramInfoLog(this->id, GL_INFO_LOG_LENGTH, NULL, infoLog);
        std::cout << "ERROR::LINKING_SHADER::" << name << "::UNABLE_TO_LINK_THE_SHADERS\n" << infoLog << std::endl;
    }
}

opengl::Program::Program(unsigned int vertex, unsigned int fragment) {
    this->id = glCreateProgram();

    glAttachShader(this->id, vertex);
    glAttachShader(this->id, fragment);

    glLinkProgram(this->id);
}

void opengl::Object::generate() {
    glGenVertexArrays(1, &this->vao);
    glBindVertexArray(this->vao);

    glGenBuffers(1, &this->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
    glBufferData(GL_ARRAY_BUFFER, this->u_size_ver, this->u_ver, GL_STATIC_DRAW);

    this->properties();

    glGenBuffers(1, &this->ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->u_size_ind, this->u_ind, GL_STATIC_DRAW);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

opengl::Object::Object(size_t size_ver, const float* ver, 
                        size_t size_ind, const unsigned int* ind) {
    this->u_size_ver = size_ver;
    this->u_ver = ver;
    this->u_size_ind = size_ind;
    this->u_ind = ind;
}

void opengl::Texture::generate(std::string path, std::string name) {
    stbi_set_flip_vertically_on_load(true);
    int width, height, nChannel = (this->edit.imageType == GL_RGB ? 3 : 4);
    unsigned char* image = stbi_load(path.c_str(), &width, &height, &nChannel, nChannel);
    
    if(!image) {
        std::cout << "ERROR::TEXTURE::" << name << "::UNABLE_TO_LOAD_IMAGE" << std::endl;
        return;
    }

    glGenTextures(1, &this->id);
    glBindTexture(GL_TEXTURE_2D, this->id);

    this->properties();

    glTexImage2D(GL_TEXTURE_2D, 0, this->edit.imageType, width, height, 0,
                    this->edit.imageType, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(image);
}

const float obj::triangle_vertices[] = {
    // positions          // colors         
     1.0f,  1.0f, 0.0f,   0.0f, 1.0f, 0.0f, // top right
    -1.0f,  1.0f, 0.0f,   0.0f, 0.0f, 1.0f, // top left 
     0.0f,  0.0f, 0.0f,   0.0f, 1.0f, 1.0f, // bottom
};

const unsigned int obj::triangle_indices[] = {
    0, 1, 2   // first triangle
};
