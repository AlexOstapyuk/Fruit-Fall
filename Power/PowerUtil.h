#pragma once

#ifdef POW_MS_COMPILER
	#ifdef POW_LIB
		#define POW_API __declspec(dllexport)
	#else
		#define POW_API __declspec(dllimport)
	#endif
#else
	#define POW_API
#endif