#pragma once

#ifdef CURVE_DLL
#   ifdef _MSC_VER
#       define CURVE_API __declspec(dllexport)
#   else
#       define CURVE_API 
#   endif
#else
#   ifdef _MSC_VER
#       define CURVE_API 
#   else
#       define CURVE_API 
#   endif
#endif