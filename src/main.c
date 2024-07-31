#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

const char *TITLE = "Yessir x3";

const uint32_t WIDTH = 640;
const uint32_t HEIGHT = 480;

typedef struct App {
    GLFWwindow *window;
} App;

void initWindow(App *pApp);
void initVulkan(void);
void mainLoop(App *pApp);
void cleanup(App *pApp);

int main(void) {
    App app = {0};

    initWindow(&app);
    initVulkan();
    mainLoop(&app);
    cleanup(&app);

    return 0;
}

void initWindow(App *pApp) {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    pApp->window = glfwCreateWindow(WIDTH, HEIGHT, TITLE, NULL, NULL);
}

void initVulkan(void) {}
void mainLoop(App *pApp) {
    while (!glfwWindowShouldClose(pApp->window)) {
        glfwPollEvents();
    }
}
void cleanup(App *pApp) {
    glfwDestroyWindow(pApp->window);
    
    glfwTerminate();
}
