#ifndef _GLUCAT_ERRORS_H
#define _GLUCAT_ERRORS_H
/***************************************************************************
    GluCat : Generic library of universal Clifford algebra templates
    errors.h : Declare error classes and functions
                             -------------------
    begin                : Sun 2001-12-09
    copyright            : (C) 2001 by Paul C. Leopardi
    email                : leopardi@bigpond.net.au
 ***************************************************************************
 *   This library is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Lesser General Public License as        *
 *   published by the Free Software Foundation; either version 2.1 of the  *
 *   License, or (at your option) any later version.                       *
 *   See http://www.fsf.org/copyleft/lesser.html for details               *
 ***************************************************************************
 This library is based on a prototype written by Arvind Raja and was
 licensed under the LGPL with permission of the author. See Arvind Raja,
 "Object-oriented implementations of Clifford algebras in C++: a prototype",
 in Ablamowicz, Lounesto and Parra (eds.)
 "Clifford algebras with numeric and symbolic computations", Birkhauser, 1996.
 ***************************************************************************
     See also Arvind Raja's original header comments in glucat.h
 ***************************************************************************/

namespace glucat
{
  /// Abstract exception class
  class glucat_error : public std::logic_error
  {
  public:
    glucat_error(const std::string& context, const std::string& msg)
    : logic_error(msg), name(context)
    { }
    ~glucat_error() throw()
    { }
    virtual const std::string heading() const throw() =0;
    virtual const std::string classname() const throw() =0;
    virtual void print_error_msg() const =0;
    std::string name;
  };

  /// Specific exception class
  template< class Class_T >
  class error : public glucat_error
  {
  public:
    error(const std::string& msg);
    error(const std::string& context, const std::string& msg);
    virtual const std::string heading() const throw();
    virtual const std::string classname() const throw();
    virtual void print_error_msg() const;
  };
  
  /// For exception catching: pointer to function returning int
  typedef int (*intfn)();
  
  /// Exception catching for functions returning int
  int try_catch(intfn f);
  
  /// For exception catching: pointer to function of int returning int
  typedef int (*intintfn)(int);
  
  /// Exception catching for functions of int returning int
  int try_catch(intintfn f, int arg);
}
#endif // _GLUCAT_ERRORS_H
