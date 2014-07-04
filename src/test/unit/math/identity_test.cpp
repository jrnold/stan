#include <gtest/gtest.h>
#include <stan/math/identity.hpp>

TEST(MathIdentity,identity) {
  using stan::math::identity;
  Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic> x 
    = identity(2, 3);
  EXPECT_EQ(6,x.size());
  EXPECT_EQ(2,x.rows());
  EXPECT_EQ(3,x.cols());
  for (int i = 0; i < x.rows(); ++i)
    for (int j = 0; j < x.cols(); ++j)
      if (i == j)
	EXPECT_FLOAT_EQ(1.0, x(i,j));
      else
	EXPECT_FLOAT_EQ(0.0, x(i,j));
  EXPECT_THROW(identity(-1,3), std::domain_error);
  EXPECT_THROW(identity(1,-3), std::domain_error);

  Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic> x2
    = identity(2);
  EXPECT_EQ(4,x2.size());
  EXPECT_EQ(2,x2.rows());
  EXPECT_EQ(2,x2.cols());
  for (int i = 0; i < x2.rows(); ++i)
    for (int j = 0; j < x2.cols(); ++j)
      if (i == j)
  	EXPECT_FLOAT_EQ(1.0, x2(i,j));
      else
  	EXPECT_FLOAT_EQ(0.0, x2(i,j));
  EXPECT_THROW(identity(-1), std::domain_error);  

}
