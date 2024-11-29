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


#if POW_DEBUG==2
	#define POW_LOG(x) std::cout<<x<<std::endl;
	#define POW_ERROR(x) std::cout << x <<std::endl;
#elif POW_DEBUG==1
	#define POW_LOG(x)
	#define POW_ERROR(x) std::cout << x << std::endl;
#else
	#define POW_LOG(x)
	#define POW_ERROR(x)
#endif