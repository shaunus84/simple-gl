include(FetchContent)

FetchContent_Declare(
    SDL2
    GIT_REPOSITORY "https://github.com/libsdl-org/SDL"
    GIT_TAG release-2.0.14
    )
	


add_subdirectory(SDL2)
add_subdirectory(glad)
add_subdirectory(opengl)
