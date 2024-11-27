set(SOURCE_FILES
	StartOff.h
	include/Power.h
	PowerApp.h
	PowerApp.cpp
)

add_library(Power STATIC ${SOURCE_FILES})

target_compile_definitions(Power PRIVATE POW_LIB)

if(MSVC)
	target_compile_definitions(Power PUBLIC POW_MS_COMPILER)
endif()

target_precompile_headers(Power PRIVATE pch.h)