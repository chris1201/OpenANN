#pragma once

#include <OpenANN/Learner.h>
#include <Eigen/Dense>

namespace OpenANN {

/**
 * @namespace FiniteDifferences
 *
 * Numerical gradient approximation techniques.
 *
 * We can approximate the derivative of some error function \f$ E \f$ with
 * respect to some parameter \f$ x \f$ with finite differences:
 *
 * \f$ \frac{\partial E(x)}{\partial x} =
 *     \frac{E(x+\epsilon) - E(x-\epsilon)}{2 \epsilon} + O(\epsilon^2), \f$
 *
 * where \f$ \epsilon \f$ is a small number. It should be small to obtain high
 * precision. However, it must not be too small, otherwise we get numerical
 * errors.
 */
namespace FiniteDifferences
{

/**
 * Approximate the derivatives of the error function of a Learner with respect
 * to the inputs numerically.
 *
 * Note that the data set of the learner will be set!
 *
 * @param x inputs
 * @param y desired outputs
 * @param learner learner that implements an error function
 * @param eps determines the precision
 */
Eigen::VectorXd inputGradient(const Eigen::VectorXd& x,
                              const Eigen::VectorXd& y, Learner& learner,
                              const double eps = 1e-2);
/**
 * Approximate the derivatives of the error function of an Optimizable with
 * respect to the parameters numerically.
 *
 * Note that a training set is required.
 *
 * @param n instance of the training set that is used to calculate the
 *          gradient
 * @param opt the optimizable
 * @param eps determines the precision
 */
Eigen::VectorXd parameterGradient(int n, Optimizable& opt,
                                  const double eps = 1e-2);
}

}