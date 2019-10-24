set(MAIN_SRC main.cpp)

set(AUX_SRC stack.cpp stack.h queue.cpp queue.hpp animal_shelter.cpp animal_shelter.h)

add_executable(stack-queue ${MAIN_SRC} ${AUX_SRC})