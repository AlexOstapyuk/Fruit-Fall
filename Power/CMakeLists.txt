set(SOURCE_FILES
	StartOff.h
	include/Power.h
	PowerApp.h
	PowerApp.cpp
	Image.h
	Image.cpp
	ImageImpl.h
	codeOpenGL/OpenGLImage.h
	codeOpenGL/OpenGLImage.cpp
	Shaders.h
	Shaders.cpp
	ShadersImpl.h
	codeOpenGL/OpenGLShaders.h
	codeOpenGL/OpenGLShaders.cpp
	Renderer.h
	Renderer.cpp
	RendererImpl.h
	codeOpenGL/OpenGLRenderer.h
	codeOpenGL/OpenGLRenderer.cpp
	PowerWindow.h
	PowerWindow.cpp
	codeGLFW/WindowGLFW.h
	codeGLFW/WindowGLFW.cpp
	KeyCodes.h
	PowerEvents.h
	PowerEvents.cpp
	PowerUtil.h
	Unit.h
	Unit.cpp
)

add_library(Power SHARED ${SOURCE_FILES})

target_compile_definitions(Power 
		PRIVATE 
			POW_LIB
		PUBLIC
			$<$<CONFIG:DEBUG>:POW_DEBUG=2>
			$<$<CONFIG:RelWithDebInfo>:POW_DEBUG=1>
			POW_OPENGL_STBI
			POW_GLFW
)

if(MSVC)
	target_compile_definitions(Power PUBLIC POW_MS_COMPILER)
endif()

target_precompile_headers(Power PRIVATE pch.h)

target_link_libraries(Power glfw glad stbi)

include_directories("../glad/include")
include_directories("../glfw/include")
include_directories("../stbi")
include_directories("../Power/")