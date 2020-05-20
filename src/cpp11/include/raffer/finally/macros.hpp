#ifndef RAFFER_FINALLY_MACROS_HPP
#define RAFFER_FINALLY_MACROS_HPP

#if __cplusplus >= 201103L

#define FINALLY finally finally__{[&]{
#define END }};

#endif // __cplusplus >= 201103L

#endif // RAFFER_FINALLY_MACROS_HPP
