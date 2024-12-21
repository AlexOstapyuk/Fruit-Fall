#pragma once

#ifdef POW_GLFW

	#define POW_KEY_SPACE              32
	#define POW_KEY_APOSTROPHE         39  /* ' */
	#define POW_KEY_COMMA              44  /* , */
	#define POW_KEY_MINUS              45  /* - */
	#define POW_KEY_PERIOD             46  /* . */
	#define POW_KEY_SLASH              47  /* / */
	#define POW_KEY_0                  48
	#define POW_KEY_1                  49
	#define POW_KEY_2                  50
	#define POW_KEY_3                  51
	#define POW_KEY_4                  52
	#define POW_KEY_5                  53
	#define POW_KEY_6                  54
	#define POW_KEY_7                  55
	#define POW_KEY_8                  56
	#define POW_KEY_9                  57
	#define POW_KEY_SEMICOLON          59  /* ; */
	#define POW_KEY_EQUAL              61  /* = */
	#define POW_KEY_A                  65
	#define POW_KEY_B                  66
	#define POW_KEY_C                  67
	#define POW_KEY_D                  68
	#define POW_KEY_E                  69
	#define POW_KEY_F                  70
	#define POW_KEY_G                  71
	#define POW_KEY_H                  72
	#define POW_KEY_I                  73
	#define POW_KEY_J                  74
	#define POW_KEY_K                  75
	#define POW_KEY_L                  76
	#define POW_KEY_M                  77
	#define POW_KEY_N                  78
	#define POW_KEY_O                  79
	#define POW_KEY_P                  80
	#define POW_KEY_Q                  81
	#define POW_KEY_R                  82
	#define POW_KEY_S                  83
	#define POW_KEY_T                  84
	#define POW_KEY_U                  85
	#define POW_KEY_V                  86
	#define POW_KEY_W                  87
	#define POW_KEY_X                  88
	#define POW_KEY_Y                  89
	#define POW_KEY_Z                  90
	#define POW_KEY_LEFT_BRACKET       91  /* [ */
	#define POW_KEY_BACKSLASH          92  /* \ */
	#define POW_KEY_RIGHT_BRACKET      93  /* ] */
	#define POW_KEY_GRAVE_ACCENT       96  /* ` */
	#define POW_KEY_WORLD_1            161 /* non-US #1 */
	#define POW_KEY_WORLD_2            162 /* non-US #2 */

	/* Function keys */
	#define POW_KEY_ESCAPE             256
	#define POW_KEY_ENTER              257
	#define POW_KEY_TAB                258
	#define POW_KEY_BACKSPACE          259
	#define POW_KEY_INSERT             260
	#define POW_KEY_DELETE             261
	#define POW_KEY_RIGHT              262
	#define POW_KEY_LEFT               263
	#define POW_KEY_DOWN               264
	#define POW_KEY_UP                 265
	#define POW_KEY_PAGE_UP            266
	#define POW_KEY_PAGE_DOWN          267
	#define POW_KEY_HOME               268
	#define POW_KEY_END                269
	#define POW_KEY_CAPS_LOCK          280
	#define POW_KEY_SCROLL_LOCK        281
	#define POW_KEY_NUM_LOCK           282
	#define POW_KEY_PRINT_SCREEN       283
	#define POW_KEY_PAUSE              284
	#define POW_KEY_F1                 290
	#define POW_KEY_F2                 291
	#define POW_KEY_F3                 292
	#define POW_KEY_F4                 293
	#define POW_KEY_F5                 294
	#define POW_KEY_F6                 295
	#define POW_KEY_F7                 296
	#define POW_KEY_F8                 297
	#define POW_KEY_F9                 298
	#define POW_KEY_F10                299
	#define POW_KEY_F11                300
	#define POW_KEY_F12                301
	#define POW_KEY_F13                302
	#define POW_KEY_F14                303
	#define POW_KEY_F15                304
	#define POW_KEY_F16                305
	#define POW_KEY_F17                306
	#define POW_KEY_F18                307
	#define POW_KEY_F19                308
	#define POW_KEY_F20                309
	#define POW_KEY_F21                310
	#define POW_KEY_F22                311
	#define POW_KEY_F23                312
	#define POW_KEY_F24                313
	#define POW_KEY_F25                314
	#define POW_KEY_KP_0               320
	#define POW_KEY_KP_1               321
	#define POW_KEY_KP_2               322
	#define POW_KEY_KP_3               323
	#define POW_KEY_KP_4               324
	#define POW_KEY_KP_5               325
	#define POW_KEY_KP_6               326
	#define POW_KEY_KP_7               327
	#define POW_KEY_KP_8               328
	#define POW_KEY_KP_9               329
	#define POW_KEY_KP_DECIMAL         330
	#define POW_KEY_KP_DIVIDE          331
	#define POW_KEY_KP_MULTIPLY        332
	#define POW_KEY_KP_SUBTRACT        333
	#define POW_KEY_KP_ADD             334
	#define POW_KEY_KP_ENTER           335
	#define POW_KEY_KP_EQUAL           336
	#define POW_KEY_LEFT_SHIFT         340
	#define POW_KEY_LEFT_CONTROL       341
	#define POW_KEY_LEFT_ALT           342
	#define POW_KEY_LEFT_SUPER         343
	#define POW_KEY_RIGHT_SHIFT        344
	#define POW_KEY_RIGHT_CONTROL      345
	#define POW_KEY_RIGHT_ALT          346
	#define POW_KEY_RIGHT_SUPER        347
	#define POW_KEY_MENU               348

#else
	#only_GLFW_is_supported_right_now
#endif