#ifndef __STAN__MATH__IDENTITY_HPP__
#define __STAN__MATH__IDENTITY_HPP__

#include <boost/math/tools/promotion.hpp>
#include <stan/math/error_handling/check_nonnegative.hpp>
#include <stan/math/matrix/Eigen.hpp>

namespace stan {

  namespace math {

    /**
     * Return the identity matrix of a specified size.
     * @param[in] m Number of rows
     * @param[in] n Number of columns
     * @return Identity matrix of size m x n.
     */
    template <T>
    inline Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic>
    identity(int m, int n) {
      check_nonnegative("identity(%1%)", m,"rows", (double*)0);
      check_nonnegative("identity(%1%)", n,"cols", (double*)0);
      return Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic>::Identity(m,n);
    }

    /**
     * Return a square identity matrix of specified size.
     * @param[in] m Number of rows and columns.
     * @return Identity matrix of size m x m.
     */
    inline Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic>
    identity(int m) {
      return identity(m, m);
    }
    
  }
}

#endif
