#include "Engine.h"

// temporary test
void Engine::test_function() {
    // current process of adding a RigidBody
    // (will probably turn this into a method)

    // Transform
    world.transforms.emplace_back(glm::vec2(100, 100), glm::vec2(600, 0));
    unsigned int index = world.transforms.size() - 1;

    // MeshRenderData
    const glm::mat4 projection = glm::ortho(0.0f, (float)window_width, (float)window_height, 0.0f, -1.0f,1.0f);
    Shader s("../shaders/basic.vert", "../shaders/basic.frag");
    s.use();
    s.setMatrix4("projection", projection);
    Mesh circle = Mesh::getCircleMesh(1, 20);
    world.mesh_render_data.emplace_back(circle, s, glm::vec3(0, 1, 1), index);

    // RigidBody
    world.rigid_bodies.emplace_back(index);
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
            Physics::update(&world, FIXED_DELTA);
            accumulator -= FIXED_DELTA;
        }

        // fraction of time until next step (used for interpolation)
        const float alpha = accumulator / FIXED_DELTA;
        Renderer::draw(&world, alpha);

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
