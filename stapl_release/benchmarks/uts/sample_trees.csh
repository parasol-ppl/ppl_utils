# Copyright (c) 2000-2009, Texas Engineering Experiment Station (TEES), a
# component of the Texas A&M University System.
#
# All rights reserved.
#
# The information and source code contained herein is the exclusive
# property of TEES and may not be disclosed, examined or reproduced
# in whole or in part without explicit written authorization from TEES.


#        ---- The Unbalanced Tree Search (UTS) Benchmark ----
#
# Copyright (c) 2010 See UTS_AUTHORS file for copyright holders
#
# This file is part of the unbalanced tree search benchmark.  This
# project is licensed under the MIT Open Source license.  See the UTS_LICENSE
# file for copyright and licensing information.
#
# UTS is a collaborative project between researchers at the University of
# Maryland, the University of North Carolina at Chapel Hill, and the Ohio
# State University.  See UTS_AUTHORS file for more information.


#-----------------------------------------------------------------------------#
# Sample UTS Workloads:
#
#  This file contains sample workloads for UTS, along with the tree statistics
#  for verifying correct output from the benchmark.  This file is intended to
#  be used in shell scripts or from the shell so that UTS can be run by:
#
#   $ source sample_workloads.csh
#   $ ./uts $T1
#
#-----------------------------------------------------------------------------#

# ====================================
# Small Workloads (~4 million nodes):
# ====================================

# (T1) Geometric [fixed] ------- Tree size = 4130071, tree depth = 10, num leaves = 3305118 (80.03%)
setenv T1 "-t 1 -a 3 -d 10 -b 4 -r 19"

# (T5) Geometric [linear dec.] - Tree size = 4147582, tree depth = 20, num leaves = 2181318 (52.59%)
setenv T5 "-t 1 -a 0 -d 20 -b 4 -r 34"

# (T2) Geometric [cyclic] ------ Tree size = 4117769, tree depth = 81, num leaves = 2342762 (56.89%)
setenv T2 "-t 1 -a 2 -d 16 -b 6 -r 502"

# (T3) Binomial ---------------- Tree size = 4112897, tree depth = 1572, num leaves = 3599034 (87.51%)
setenv T3 "-t 0 -b 2000 -q 0.124875 -m 8 -r 42"

# (T4) Hybrid ------------------ Tree size = 4132453, tree depth = 134, num leaves = 3108986 (75.23%)
setenv T4 "-t 2 -a 0 -d 16 -b 6 -r 1 -q 0.234375 -m 4 -r 1"

# ====================================
# Large Workloads (~100 million nodes):
# ====================================

# (T1L) Geometric [fixed] ------ Tree size = 102181082, tree depth = 13, num leaves = 81746377 (80.00%)
setenv T1L "-t 1 -a 3 -d 13 -b 4 -r 29"

# (T2L) Geometric [cyclic] ----- Tree size = 96793510, tree depth = 67, num leaves = 53791152 (55.57%)
setenv T2L "-t 1 -a 2 -d 23 -b 7 -r 220"

# (T3L) Binomial --------------- Tree size = 111345631, tree depth = 17844, num leaves = 89076904 (80.00%)
setenv T3L "-t 0 -b 2000 -q 0.200014 -m 5 -r 7"

# ====================================
# Extra Large (XL) Workloads (~1.6 billion nodes):
# ====================================

# (T1XL) Geometric [fixed] ----- Tree size = 1635119272, tree depth = 15, num leaves = 1308100063 (80.00%)
setenv T1XL "-t 1 -a 3 -d 15 -b 4 -r 29"

# ====================================
# Extra Extra Large (XXL) Workloads (~3-10 billion nodes):
# ====================================

# (T1XXL) Geometric [fixed] ---- Tree size = 4230646601, tree depth = 15 
setenv T1XXL "-t 1 -a 3 -d 15 -b 4 -r 19"

# (T3XXL) Binomial ------------- Tree size = 2793220501 
setenv T3XXL "-t 0 -b 2000 -q 0.499995 -m 2 -r 316"

# (T2XXL) Binomial ------------- Tree size = 10612052303, tree depth = 216370, num leaves = 5306027151 (50.00%) 
setenv T2XXL "-t 0 -b 2000 -q 0.499999995 -m 2 -r 0"

# ====================================
# Wicked Large Workloads (~150-300 billion nodes):
# ====================================

# (T1WL) Geometric [fixed] ----- Tree size = 270751679750, tree depth = 18, num leaves = 216601257283 (80.00%)
setenv T1WL "-t 1 -a 3 -d 18 -b 4 -r 19"

# (T2WL) Binomial -------------- Tree size = 295393891003, tree depth = 1021239, num leaves = 147696946501 (50.00%)
setenv T2WL "-t 0 -b 2000 -q 0.4999999995 -m 2 -r 559"

# (T3WL) Binomial -------------- Tree size = 157063495159, tree depth = 758577, num leaves = 78531748579 (50.00%) 
setenv T3WL "-t 0 -b 2000 -q 0.4999995 -m 2 -r 559"

