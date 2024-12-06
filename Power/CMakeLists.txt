set(SOURCE_FILES
	StartOff.h
	include/Power.h
	PowerApp.h
	PowerApp.cpp
)

add_library(Power STATIC ${SOURCE_FILES})

target_compile_definitions(Power 
		PRIVATE 
			POW_LIB
		PUBLIC
			$<$<CONFIG:DEBUG>:POW_DEBUG=2>
			$<$<CONFIG:RelWithDebInfo>:POW_DEBUG=1>
			POW_OPENGL_STBI
)

if(MSVC)
	target_compile_definitions(Power PUBLIC POW_MS_COMPILER)
endif()

target_precompile_headers(Power PRIVATE pch.h)

target_link_libraries(Power glfw)