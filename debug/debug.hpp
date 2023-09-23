#pragma once

#ifndef NDEBUG

#define $ std::cerr << "I'm here File: " << __FILE__ << ", Line: " << __LINE__ << std::endl;

#define $dump(arg) std::cerr << "Var: '" << #arg << "', Val: " << arg << ", File: " << __FILE__ << ", Line: " << __LINE__ << std::endl;

#else
        #define $
        #define $dump(arg)

#endif /*NDEBUG*/