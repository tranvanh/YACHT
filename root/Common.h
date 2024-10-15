#pragma once

#include <iostream>
#include <memory>
#include <utility>


// \todo FIX THIS SHIT AND MAKE IT WORK
#ifndef NDEBUG
#   define CASSERT(Expr, Msg) IMPL_Assert(#   Expr, Expr, __FILE__, __LINE__, Msg)
#else
#   define CASSERT(Expr, Msg)
#endif

static void IMPL_Assert(const char* expr_str, bool expr, const char* file, int line, const char* msg) {
    if (!expr) {
        std::cerr << "Assert failed:\t" << msg << "\n"
                  << "Expected:\t" << expr_str << "\n"
                  << "Source:\t\t" << file << ", line " << line << "\n";
        abort();
    }
}