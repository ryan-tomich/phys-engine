#include "Engine.h"

// temp testing
void Engine::test_function() {
    Mesh circle = Mesh::getCircleMesh(1, 20);
    //Mesh rectangle = Mesh::getRectangleMesh();
    //Mesh triangle = Mesh::getTriangleMesh();

    const auto t = Transform(glm::vec2(100, 100), glm::vec2(600, 400));

    const glm::mat4 projection = glm::ortho(0.0f, (float)window_width, (float)window_height, 0.0f, -1.0f,1.0f);
    Shader s("../shaders/basic.vert", "../shaders/basic.frag");
    s.use();
    s.setMatrix4("projection", projection);

    auto mr = MeshRenderData(circle, s, glm::vec3(0, 1, 1), t);
    world.mesh_render_data.push_back(mr);
}

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

    test_function();

    loop(window);

    glfwTerminate();
    return 0;
}

void Engine::loop(GLFWwindow* window) {
    while (!glfwWindowShouldClose(window)) {
        float current_time = glfwGetTime();
        float delta_time = current_time - last_time;
        last_time = current_time;

        // prevent spiral of death from lag
        if (delta_time > 0.25f) {
            delta_time = 0.25f;
        }

        accumulator += delta_time;

        glfwPollEvents();

        while (accumulator >= FIXED_DELTA) {
            Physics::update(&world);
            accumulator -= FIXED_DELTA;
        }

        // draw with interpolation here
        Renderer::draw(world);

        // fraction of time until next step
        //const float alpha = accumulator / FIXED_DELTA;

        glfwSwapBuffers(window); // display the render
    }
}

void Engine::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    float aspect_width;
    float aspect_height;

    if ((float)width / (float)height > aspect_ratio) {
        aspect_height = (float)height;
        aspect_width = (float)height * aspect_ratio;
    } else {
        aspect_width = (float)width;
        aspect_height = (float)width / aspect_ratio;
    }
    float viewportX = ((float)width - aspect_width) / 2.0f;
    float viewportY = ((float)height - aspect_height) / 2.0f;
    glViewport((int)viewportX, (int)viewportY, (int)aspect_width, (int)aspect_height);
}
