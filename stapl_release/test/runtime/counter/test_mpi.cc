/*
// Copyright (c) 2000-2009, Texas Engineering Experiment Station (TEES), a
// component of the Texas A&M University System.

// All rights reserved.

// The information and source code contained herein is the exclusive
// property of TEES and may not be disclosed, examined or reproduced
// in whole or in part without explicit written authorization from TEES.
*/


#define STAPL_RUNTIME_TEST_MODULE mpi_wtime_timer
#include "utility.h"
#include <chrono>
#include <thread>
#include <stapl/runtime/counter/counter.hpp>
#include <stapl/runtime/counter/mpi/mpi_wtime_timer.hpp>
#include <cmath>

using namespace stapl;

static void loop(void)
{
  std::this_thread::sleep_for(std::chrono::seconds{1});
}

BOOST_AUTO_TEST_CASE( test_mpi_wtime_timer )
{
  counter<mpi_wtime_timer> c;
  std::cout << c.native_name() << ": " << c.read() << ' ';

  c.start();
  loop();
  std::cout << c.stop() << std::endl;
}
