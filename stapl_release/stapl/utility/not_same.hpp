/*
// Copyright (c) 2000-2009, Texas Engineering Experiment Station (TEES), a
// component of the Texas A&M University System.

// All rights reserved.

// The information and source code contained herein is the exclusive
// property of TEES and may not be disclosed, examined or reproduced
// in whole or in part without explicit written authorization from TEES.
*/

#ifndef STAPL_UTILITY_NOT_SAME_HPP
#define STAPL_UTILITY_NOT_SAME_HPP

namespace stapl {

//////////////////////////////////////////////////////////////////////
/// @brief Negation of std::is_same.
//////////////////////////////////////////////////////////////////////
template<class,class>
struct not_same
  : std::true_type
{ };

template<class T>
struct not_same<T, T>
  : std::false_type
{ };


} // namespace stapl
#endif // STAPL_UTILITY_NOT_SAME_HPP
