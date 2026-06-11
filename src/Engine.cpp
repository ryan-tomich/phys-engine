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

    // initialize global shader for world
    world.configure_shader("../shaders/basic.vert", "../shaders/basic.frag");

    // initialize shader for debugger
    debug_shader = Shader("../shaders/basic.vert", "../shaders/basic.frag");
    const glm::mat4 projection = glm::ortho(0.0f, (float)window_width, (float)window_height, 0.0f, -1.0f,1.0f);
    debug_shader.use();
    debug_shader.setMatrix4("projection", projection);

    loop(window);
    glfwTerminate();
    return 0;
}

void Engine::loop(GLFWwindow* window) {
    // tests
    const std::vector meshes = {Mesh::getCircleMesh(1, 20), Mesh::getRectangleMesh(), Mesh::getTriangleMesh()};
    world.add_static_body(meshes[1], glm::vec2(400, 800), glm::vec2(100, 100), glm::vec3(0,1,1));
    world.add_rigid_body(meshes[0], glm::vec2(400, 100), glm::vec2(100, 100), glm::vec3(1, 0,1));
    //float test_acc = 0.0f;
    //float test_last = glfwGetTime();

    Debugger::add_filled(meshes[1], glm::vec2(500, 150), glm::vec2(200, 50), glm::vec3(0, 1, 0));

    // actual loop
    while (!glfwWindowShouldClose(window)) {
        //float test_curr = glfwGetTime();
        //float test_delta = test_curr - test_last;
        //test_last = test_curr;

        float current_time = glfwGetTime();
        float delta_time = current_time - last_time;
        last_time = current_time;

        // prevent spiral of death from lag
        if (delta_time > 0.25f) {
            delta_time = 0.25f;
        }
        //if (test_delta > 0.25f) {
        //    test_delta = 0.25f;
        //}

        accumulator += delta_time;
        //test_acc += test_delta;

        glfwPollEvents();

        while (accumulator >= FIXED_DELTA) {
            Physics::update(&world, FIXED_DELTA);
            CollisionEngine::update(&world, glm::vec2(0,0), glm::vec2(window_width, window_height));
            accumulator -= FIXED_DELTA;
        }
        //while (test_acc >= 0.01) {
        //    world.add_rigid_body(meshes[rand() % 3], glm::vec2(rand() % 1900, rand() % 600), glm::vec2(rand() % 201 + 25, rand() % 201 + 25), glm::vec3((rand() % 11) / 10.0f, (rand() % 11) / 10.0f, (rand() % 11) / 10.0f));
        //    test_acc -= 0.01;
        //}

        // clear screen
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // draw debug queue
        Debugger::draw(&debug_shader);

        // draw normal stuff
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
