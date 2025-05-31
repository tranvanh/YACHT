#pragma once
#include <iostream>
#include <memory>
#include <utility>

// \todo Bi 2024-12 move the file somewhere else 

#define CASSERT(Expr, Msg) IMPL_Assert(#Expr, Expr, __FILE__, __LINE__, Msg)

[[maybe_unused]] static void IMPL_Assert(const char* expr_str, bool expr, const char* file, int line, const char* msg) {
    if (!expr) {
        std::cerr << "Assert failed:\t" << msg << "\n"
                  << "Expected:\t" << expr_str << "\n"
                  << "Source:\t\t" << file << ", line " << line << "\n";
        abort();
    }
}

using EntityId = int;

#define YACHT_NAMESPACE_BEGIN namespace YACHT{
#define YACHT_NAMESPACE_END };

#define PACMAN_NAMESPACE_BEGIN namespace YACHT::PACMAN{
#define PACMAN_NAMESPACE_END };
