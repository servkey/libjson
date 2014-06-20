
#ifndef _json_inttypes_h_
#define _json_inttypes_h_

#include "json_config.h"

#ifdef WIN32
	#ifndef INFINITY
	union MSVC_EVIL_FLOAT_HACK
	{
	   unsigned __int8 Bytes[4];
	   float Value; 
	};
	static union MSVC_EVIL_FLOAT_HACK INFINITY_HACK = {{0x00, 0x00, 0x80, 0x7F}};

	#define INFINITY (INFINITY_HACK.Value)
	#define HAVE_DECL_INFINITY
	#endif

	#ifndef NAN
			static const unsigned long __nan[2] = {0xffffffff, 0x7fffffff};
			#define NAN (*(const float *) __nan)
			#define HAVE_DECL_NAN
	#endif
	#include <stdint.h>
	#if defined(_MSC_VER)
	  #include <Windows.h>
	#endif

#endif

#if defined(_MSC_VER) && _MSC_VER <= 1700

	/* Anything less than Visual Studio C++ 10 is missing stdint.h and inttypes.h */
	#define PRId64 "I64d" 
	#define SCNd64 "I64d"
	typedef signed char  int8_t;
	typedef signed short int16_t;
	typedef signed int   int32_t;
	typedef unsigned char  uint8_t;
	typedef unsigned short uint16_t;
	typedef unsigned int   uint32_t;
	typedef signed long long   int64_t;
	typedef unsigned long long uint64_t;

#else

#ifdef JSON_C_HAVE_INTTYPES_H
#include <inttypes.h>
#endif
/* inttypes.h includes stdint.h */
#endif
#endif
