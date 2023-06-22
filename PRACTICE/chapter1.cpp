#include <dve/header.h>

int main() {
    std::cout << "\n\nCH 1 : GETTING STARTED\n";

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    GLFWwindow* window = glfwCreateWindow(800, 600, "TITLE", NULL, NULL);
    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)(glfwGetProcAddress))) {
        std::cout << "GLAD FAILED!\n";
        return -1;
    }

    glfwSetFramebufferSizeCallback(window, opengl::updateFramebuffer);

    // Paths
    std::string par_path = "C:/Users/devit/C++ Program VSCode/zOpenGL/PRACTICE/";
    std::string v_path = par_path + "vertex.glsl";
    std::string f_path = par_path + "fragment.glsl";
    
    // Setting up Vertex shader and fragment shader, and linking them into one program shader
    opengl::Shader vertexShader;
    vertexShader.createShader(GL_VERTEX_SHADER, v_path);

    opengl::Shader fragmentShader;
    fragmentShader.createShader(GL_FRAGMENT_SHADER, f_path);

    opengl::Program shader_program(vertexShader.getId(), fragmentShader.getId());
    shader_program.checkSuccess("shader_program");

    vertexShader.deleteShader();
    fragmentShader.deleteShader();

    // Setting up VAO, VBO, EBO
    opengl::Object draw(sizeof(obj::triangle_vertices), obj::triangle_vertices,
                        sizeof(obj::triangle_indices), obj::triangle_indices);
    draw.generate();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glfwSetTime(1.0);

    while(!glfwWindowShouldClose(window)) {
        // INPUT
        opengl::userInput(window);

        float time = glfwGetTime();
        float speed = 20.0;

        float ittScale = glfwGetTime() * speed;
        if(time > 2.6051) glfwSetTime(1.0);        

        float scaling = (1.0/(ittScale*pow(3, time)));

        // RENDER
        opengl::changeColorWindow(0.0, 0.0, 0.0, 1.0);
        glUseProgram(shader_program.getId());
        glBindVertexArray(draw.getID());

        glm::mat4 res = glm::scale(glm::mat4(1.0), glm::vec3(glm::vec2(scaling), 1.0));
        drawRecursive(glm::vec3(0.0f), res, shader_program.getId(), 0, 10, 0.5, true);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void drawRecursive(glm::vec3 translate, glm::mat4 res, int id, int depth, int mny, float p, bool flag) {
    if(depth >= 6) {
        return;
    }

    res = glm::translate(res, translate);
    res = glm::scale(res, glm::vec3(glm::vec2(p), 1.0));

    int loc = glGetUniformLocation(id, "transformation");
    glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(res));  
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

    if(p < 1.0) {
        drawRecursive(glm::vec3(0.0f,  1.0f, 0.0f), res, id, depth+1, mny, 0.5, false);
    }
    drawRecursive(glm::vec3(1.0f,  0.0, 0.0f), res, id, depth+1, mny, 0.5, false);
    drawRecursive(glm::vec3(-1.0f, 0.0f, 0.0f), res, id, depth+1, mny, 0.5, false);
    if(flag && mny > 0) {
        drawRecursive(glm::vec3(0.0f, -2.0f, 0.0f), res, id, depth, mny-1, 2.0, true);
    }
}
