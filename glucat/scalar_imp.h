#ifndef _GLUCAT_SCALAR_IMP_H
#define _GLUCAT_SCALAR_IMP_H
/***************************************************************************
    GluCat : Generic library of universal Clifford algebra templates
    scalar_imp.h : Define functions for scalar_t
                             -------------------
    begin                : 2001-12-20
    copyright            : (C) 2001-2014 by Paul C. Leopardi
 ***************************************************************************

    This library is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this library.  If not, see <http://www.gnu.org/licenses/>.

 ***************************************************************************
 This library is based on a prototype written by Arvind Raja and was
 licensed under the LGPL with permission of the author. See Arvind Raja,
 "Object-oriented implementations of Clifford algebras in C++: a prototype",
 in Ablamowicz, Lounesto and Parra (eds.)
 "Clifford algebras with numeric and symbolic computations, Birkhauser, 1996."
 ***************************************************************************
 See also Arvind Raja's original header comments and references in glucat.h
 ***************************************************************************/

#include "glucat/portability.h"

#include <boost/numeric/ublas/traits.hpp>

#include <cmath>
#include <limits>

namespace glucat
{
  /// Extra traits which extend numeric limits
  // Reference: [AA], 2.4, p. 30-31

  /// Cast to float
  template< >
  template< typename Other_Scalar_T >
  inline
  float
  numeric_traits<float>::
  to_scalar_t(const Other_Scalar_T& val)
  { return float(numeric_traits<Other_Scalar_T>::to_double(val)); }

  /// Cast to double
  template< >
  template< typename Other_Scalar_T >
  inline
  double
  numeric_traits<double>::
  to_scalar_t(const Other_Scalar_T& val)
  { return numeric_traits<Other_Scalar_T>::to_double(val); }

  /// Cast to promote
  template< typename Scalar_T >
  inline
  typename numeric_traits<Scalar_T>::promoted::type
  to_promote(const Scalar_T& val)
  { return numeric_traits<Scalar_T>::promoted::type(val); }

  /// Cast to demote
  template< typename Scalar_T >
  inline
  typename numeric_traits<Scalar_T>::demoted::type
  to_demote(const Scalar_T& val)
  { return numeric_traits<Scalar_T>::demoted::type(val); }

#if defined(_GLUCAT_USE_QD)
  /// Cast to demote
  template< >
  inline
  typename numeric_traits<dd_real>::demoted::type
  to_demote(const dd_real& val)
  { return numeric_traits<dd_real>::to_double(val); }
#endif
}

#endif // _GLUCAT_SCALAR_IMP_H