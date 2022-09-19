cmake_minimum_required(VERSION 3.15)
project(test_task LANGUAGES CXX)

# подключаем OpenMP
include(FindOpenMP)
if(OPENMP_FOUND)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif(OPENMP_FOUND)

#set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# стандарт языка
set(CMAKE_CXX_STANDARD 14)

# пути до исходников
include_directories(${CMAKE_SOURCE_DIR}/src)

# добавление исходников
set(SOURCES_DIR ${CMAKE_SOURCE_DIR}/src)
set(SOURCES_FILES ${SOURCES_DIR}/curve.h
			      ${SOURCES_DIR}/curve.cpp
			      ${SOURCES_DIR}/ellipse.h
			      ${SOURCES_DIR}/ellipse.cpp
			      ${SOURCES_DIR}/circle.h
			      ${SOURCES_DIR}/circle.cpp
			      ${SOURCES_DIR}/helix.h
			      ${SOURCES_DIR}/helix.cpp				  
			      ${SOURCES_DIR}/config.h			  
)

# цель dll
add_library(curves SHARED ${SOURCES_FILES})
target_compile_definitions(curves PRIVATE CURVE_DLL)

# цель консольная версия
add_executable(curves_console ${SOURCES_DIR}/main.cpp)

# параллельная компиляция
if (MSVC)
	target_compile_options(curves_console PRIVATE "$<$<COMPILE_LANGUAGE:CXX>:$<$<CXX_COMPILER_ID:MSVC>:/MP>>" )	
	target_compile_options(curves PRIVATE "$<$<COMPILE_LANGUAGE:CXX>:$<$<CXX_COMPILER_ID:MSVC>:/MP>>" )	
endif()

# линковка библиотек
target_link_libraries(curves_console PRIVATE curves)
