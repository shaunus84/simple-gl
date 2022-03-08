#pragma once

#include <SDL.h>

//--- Game.h ---//

namespace simplegl {

class Game {
   public:
    bool Initialise(int screenWidth, int screenHeight);

    void RunLoop();

    void Shutdown();

   private:
    void HandleInput();
    void Update();
    void Render();

   private:
    SDL_Window* m_pWindow{nullptr};
    SDL_GLContext m_glContext;

    bool m_bIsRunning{false};

    uint32_t m_ticksCount{0};
    int      m_screenWidth{0};
    int      m_screenHeight{0};
};

}  // namespace simplegl
