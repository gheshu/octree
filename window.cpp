#include "window.h"

#include "myglheaders.h"
#include <iostream>

using namespace std;

Window::Window(int width, int height, int major_ver, int minor_ver, const string& title){
    glfwSetErrorCallback(error_callback);
    if(!glfwInit()){
        cerr << "Failed to initialize gflw" << endl;
        exit(1);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major_ver);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor_ver);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    if (!window){
        cerr << "Failed to create window" << endl;
        glfwTerminate();
        exit(1);
    }
    glfwMakeContextCurrent(window);
    glewExperimental=true;
	glViewport(0, 0, width, height);
    if(glewInit() != GLEW_OK){
        cerr << "Failed to initialize GLEW" << endl;
        exit(1);
    }
    glGetError();	// invalid enumerant shows up here, just part of glew being itself.
    glfwSwapInterval(1);
}

Window::~Window(){
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::error_callback(int error, const char* description){
    fputs(description, stderr);
}