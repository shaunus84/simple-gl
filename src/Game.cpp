#include "Game.h"

#include "glad\glad.h"

using simplegl::Game;

bool Game::Initialise(int screenWidth, int screenHeight) {
    m_screenWidth  = screenWidth;
    m_screenHeight = screenHeight;

    SDL_Log("Initialising SDL...");

    int sdlResult = SDL_Init(SDL_INIT_VIDEO);

    if (sdlResult != 0) {
        SDL_Log("Unable to initialise SDL: %s", SDL_GetError());

        return false;
    }

    SDL_Log("-- Success --");

    // Set OpenGL attributes
    // Use the core OpenGL profile
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    // Specify version 3.3
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    // Request a color buffer with 8-bits per RGBA channel
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    // Enable double buffering
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    // Force OpenGL to use hardware acceleration
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

    SDL_Log("Creating SDL Window - W:%d H:%d", m_screenWidth, m_screenHeight);

    m_pWindow = SDL_CreateWindow("SIMPLE-GL", 100, 100, m_screenWidth, m_screenHeight, SDL_WINDOW_OPENGL);

    if (m_pWindow == nullptr) {
        SDL_Log("Failed to initialise SDL_Window: %s", SDL_GetError());
        return false;
    }

    SDL_Log("-- Success --");

    // Create an OpenGL context
    m_glContext = SDL_GL_CreateContext(m_pWindow);


    SDL_Log("Initialising GLAD...");
    // use glad to map GL functions
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        SDL_Log("Failed to initialize GLAD");
        return false;
    }

    SDL_Log("-- Success --");

    m_ticksCount = SDL_GetTicks();
    m_bIsRunning = true;

    SDL_Log("Game Initialisation Successful");
    return true;
}

void Game::RunLoop() {

    SDL_Log("Entering Run Loop");
    while (m_bIsRunning) {
        HandleInput();
        Update();
        Render();
    }
}

void Game::Shutdown() {

    SDL_Log("Shutting Down...");

    SDL_GL_DeleteContext(m_glContext);
    SDL_DestroyWindow(m_pWindow);
    SDL_Quit();
}

void Game::HandleInput() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                m_bIsRunning = false;
                break;
        }
    }

    const Uint8* state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_ESCAPE]) {
        m_bIsRunning = false;
    }
}

void Game::Update() {
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), m_ticksCount + 16))
        ;

    float deltaTime = (SDL_GetTicks() - m_ticksCount) / 1000.0f;

    if (deltaTime > 0.05f) {
        deltaTime = 0.05f;
    }

    // -- Update Here -- //
}
void Game::Render() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // -- Render Here -- //

    SDL_GL_SwapWindow(m_pWindow);
}
