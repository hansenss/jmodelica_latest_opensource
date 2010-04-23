/* $Id: elapsed_seconds.cpp 1653 2010-02-09 14:25:30Z bradbell $ */
/* --------------------------------------------------------------------------
CppAD: C++ Algorithmic Differentiation: Copyright (C) 2003-10 Bradley M. Bell

CppAD is distributed under multiple licenses. This distribution is under
the terms of the 
                    Common Public License Version 1.0.

A copy of this license is included in the COPYING file of this distribution.
Please visit http://www.coin-or.org/CppAD/ for information on other licenses.
-------------------------------------------------------------------------- */

/*
$begin elapsed_seconds.cpp$$
$spell
	Cpp
	Lu
$$

$section Elapsed Seconds: Example and Test$$

$index elapsed, seconds$$
$index seconds, elapsed$$
$index example, timer$$
$index test, timer$$

$code
$verbatim%speed/example/elapsed_seconds.cpp%0%// BEGIN PROGRAM%// END PROGRAM%1%$$
$$

$end
*/
// BEGIN PROGRAM
# include <cppad/elapsed_seconds.hpp>

# include <iostream>
# include <algorithm>
# include <cmath>

bool elapsed_seconds(void)
{	bool ok = true;

	double max_diff = 0.;
	double s0 = CppAD::elapsed_seconds();
	double s1 = CppAD::elapsed_seconds();
	double s2 = CppAD::elapsed_seconds();
	while(s2 - s0 < 1.)
	{	max_diff = std::max(s2 - s1, max_diff);
		s1 = s2;
		s2 = CppAD::elapsed_seconds();

	}
# ifdef CPPAD_DEBUG_NEW_TESTS
	std::cout << "max_diff = " << max_diff << std::endl;
# else
	ok &= 0. < max_diff && max_diff < .02;
# endif
	return ok;
}

// END PROGRAM
