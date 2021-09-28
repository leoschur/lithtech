project(LIB_ILTSound)

if (ENABLE_OPENAL)
	add_definitions(-DUSE_OPENAL)
endif(ENABLE_OPENAL)

include_directories(src
	../../sdk/inc)

add_library(${PROJECT_NAME} STATIC
	src/iltsound.cpp)

if(LINUX)
    set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "-fpermissive -fPIC")
endif(LINUX)
