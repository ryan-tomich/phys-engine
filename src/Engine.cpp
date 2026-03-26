#include "Engine.h"

Engine::Engine() {
    last_time = glfwGetTime();
    accumulator = 0.0f;
}

int Engine::start() {
    // initialize glfw window
    if (!glfwInit()) {
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(window_width, window_height, "Unnamed Physics Engine", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    //glfwSwapInterval(1); // enable vsync
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // initialize input
    //glfwSetWindowUserPointer(window, &input);
    //glfwSetKeyCallback(window, Input::keyCallback);

    // initialize glad
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // initialize Renderer & Engine
    //const glm::mat4 projection = glm::ortho(0.0f, WIDTH, HEIGHT, 0.0f, -1.0f,1.0f);
    //const Shader s("../shaders/basic.vert", "../shaders/basic.frag");
    //s.use();
    //s.setMatrix4("projection", projection);

    //auto R = Renderer(s);
    //auto E = Engine();

    loop(window);

    glfwTerminate();
    return 0;
}

void Engine::loop(GLFWwindow* window) {
    while (!glfwWindowShouldClose(window)) {
        float currentTime = glfwGetTime();
        float deltaTime = currentTime - last_time;
        last_time = currentTime;

        // prevent spiral of death from lag
        if (deltaTime > 0.25f) {
            deltaTime = 0.25f;
        }

        accumulator += deltaTime;

        glfwPollEvents();

        while (accumulator >= FIXED_DELTA) {
            //std::cout << "doing stuff | ";
            accumulator -= FIXED_DELTA;
        }

        // fraction of time until next step
        //const float alpha = accumulator / FIXED_DELTA;

        // I'll have to save previous and current positions of
        // objects in order to interpolate using alpha
        //E.render(alpha);

        glfwSwapBuffers(window); // display the render
    }
}

void Engine::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    float aspectWidth;
    float aspectHeight;

    if ((float)width / (float)height > aspect_ratio) {
        aspectHeight = (float)height;
        aspectWidth = (float)height * aspect_ratio;
    } else {
        aspectWidth = (float)width;
        aspectHeight = (float)width / aspect_ratio;
    }
    float viewportX = ((float)width - aspectWidth) / 2.0f;
    float viewportY = ((float)height - aspectHeight) / 2.0f;
    glViewport((int)viewportX, (int)viewportY, (int)aspectWidth, (int)aspectHeight);
}
