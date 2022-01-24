// -*- c++ -*-
//
// Copyright (c) 2000-2009, Texas Engineering Experiment Station (TEES), a
// component of the Texas A&M University System.
//
// All rights reserved.
//
// The information and source code contained herein is the exclusive
// property of TEES and may not be disclosed, examined or reproduced
// in whole or in part without explicit written authorization from TEES.
//
// Copyright 1997, 1998, 1999 University of Notre Dame.
// Authors: Andrew Lumsdaine, Jeremy G. Siek, Lie-Quan Lee
//
// This file is part of the Matrix Template Library
//
// You should have received a copy of the License Agreement for the
// Matrix Template Library along with the software;  see the
// file LICENSE.  If not, contact Office of Research, University of Notre
// Dame, Notre Dame, IN  46556.
//
// Permission to modify the code and to distribute modified code is
// granted, provided the text of this NOTICE is retained, a notice that
// the code was modified is included with the above COPYRIGHT NOTICE and
// with the COPYRIGHT NOTICE in the LICENSE file, and that the LICENSE
// file is distributed with the modified code.
//
// LICENSOR MAKES NO REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED.
// By way of example, but not limitation, Licensor MAKES NO
// REPRESENTATIONS OR WARRANTIES OF MERCHANTABILITY OR FITNESS FOR ANY
// PARTICULAR PURPOSE OR THAT THE USE OF THE LICENSED SOFTWARE COMPONENTS
// OR DOCUMENTATION WILL NOT INFRINGE ANY PATENTS, COPYRIGHTS, TRADEMARKS
// OR OTHER RIGHTS.
//
//===========================================================================

#include "mtl/utils.h"
#include "mtl/matrix.h"
#include "matrix_test.h"
#include "algo_test.h"

// matrix_attr.h is generated by make_and_test.pl and defines
// NUMTYPE, SHAPE, STORAGE, ORIEN, and TESTNAME
// you can create your own for testing purposes
#include "matrix_attr.h"


template <class Matrix>
void
do_test(Matrix& A, std::string test_name)
{
  using namespace mtl;

  typedef typename mtl::matrix_traits<Matrix>::value_type T;
  typedef typename mtl::matrix_traits<Matrix>::size_type Int;

  // matrix-matrix algo tests
  typedef typename Matrix::orientation Orien;
  enum { Orien_id = Orien::id };
  typedef typename IF< EQUAL<Orien_id, ROW_MAJOR>::RET,
                       typename mtl::matrix<T, rectangle<>, dense<>, row_major>::type,
                      typename mtl::matrix<T, rectangle<>, dense<>, column_major>::type
                     >::RET DenseMat;

  /* should also try with sparse C1,C2 when Matrix is sparse JGS */
  DenseMat C1(A.nrows(), A.ncols()), C2(A.nrows(), A.ncols());

  mtl::set_value(A, 0); mtl::set_value(C1, 0); mtl::set_value(C2, 0);

  matrix_fill(A);
  matrix_fill(C1);
  matrix_fill(C2);

  test_add(test_name, A, C1, C2);
}


int
main(int argc, char* argv[])
{
  if (argc < 5) {
    std::cerr << "matrix_test <M> <N> <SUB> <SUPER>" << std::endl;
    return -1;
  }

  using namespace mtl;
  using std::string;

  const int M = atoi(argv[1]);
  const int N = atoi(argv[2]);
  const int SUB = atoi(argv[3]);
  const int SUP = atoi(argv[4]);

  std::cout << "M: " << M << " N: " << N 
       << " SUB: " << SUB << " SUPER: " << SUP << std::endl;

  typedef matrix<NUMTYPE, SHAPE, STORAGE, ORIEN>::type Matrix;

  string test_name = TESTNAME;
  Matrix* a = 0;

  create_and_run(M, N, SUB, SUP, test_name, a, Matrix::shape());

  return 0;
}
