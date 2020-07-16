
// Copyright (c) 2020 Paul Raffer.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#if __cplusplus >= 201103L

#ifndef RAFFER_LANG_CPP_CPP_HPP
#define RAFFER_LANG_CPP_CPP_HPP

#define raffer_cpplib_lang__              202006L
#define raffer_cpplib_lang_cpp_version__  202006L
#define raffer_cpplib_lang_cpp_compiler__ 202005L


namespace raffer // interface
{
namespace lang
{
namespace cpp
{
	
enum class version : long
{
	cpp20 = 202002L,
	cpp17 = 201703L,
	cpp14 = 201402L,
	cpp11 = 201103L,
	cpp98 = 199711L,
};

enum class compiler
{
	AMD_Optimizing_C_Cpp_Compiler,
	Arm_Compiler_for_Linux,
	CppBuilder_classic,
	CppBuilder_modern,
	Turbo_Cpp,
	CINT,
	Cfront,
	Clang,
	Comeau_C_Cpp,
	Cray_C_Cpp,
	Digital_Mars_C_Cpp,
	EDG_Cpp_Front_End,
	EKOPath,
	GCC,
	HP_aCpp,
	IAR_C_Cpp_Compilers,
	Intel_Cpp_Compiler,
	KAI_Cpp,
	Microtec_C_Cpp,
	EDGE_C_Cpp,
	Open64,
	PGCpp,
	ProDev_WorkShop,
	RealView_Compilation_Tools,
	armcc,
	armclang,
	Salford_Cpp_Compiler,
	SAS_C_Cpp,
	SCORE_Cpp,
	Oracle_Cpp_Compiler,
	TenDRA,
	VectorC,
	Visual_Cpp,
	XL_C_Cpp,
	Diab_Compiler,
};

} // namespace cpp
} // namespace lang
} // namespace raffer


#endif // RAFFER_LANG_CPP_CPP_HPP

#endif // __cplusplus >= 201103L
