set(MAIN_SRC main.cpp)

set(AUX_SRC string_compression.cpp)

get_filename_component(exec_name ${MAIN_SRC} NAME_WE)

add_executable(${exec_name} ${MAIN_SRC} ${AUX_SRC})