#ifndef STAN__AGRAD__FWD__FUNCTIONS__FLOOR_HPP
#define STAN__AGRAD__FWD__FUNCTIONS__FLOOR_HPP

#include <stan/agrad/fwd/fvar.hpp>
#include <stan/meta/traits.hpp>

namespace stan {

  namespace agrad {

    template <typename T>
    inline
    fvar<T>
    floor(const fvar<T>& x) {
      using std::floor;
        return fvar<T>(floor(x.val_), 0);
    }
  }
}
#endif
