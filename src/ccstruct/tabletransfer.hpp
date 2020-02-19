#pragma once
#include <memory>
#include <vector>
#include "rect.h"


/// Structure for data transfer from table detector 
struct MyTable {
  TBOX box;
  std::vector<TBOX> rows;
  std::vector<TBOX> cols;
};

/** \brief You can use this small template function to ensure that one and
 *   only one object of type T exists. It implements the Singleton Pattern.
 *
 * T must be default-constructable.
 * Usage examples:
 *   A& a = uniqueInstance<A>();
 *   a.xyz();
 *   uniqueInstance<A>(make_unique<A>(42)); // replace instance
 *   a.foo();
 * or
 *   uniqueInstance<A>().xyz();
 */
template<typename T>
T& uniqueInstance(std::unique_ptr<T> new_instance = nullptr)
{
  static std::unique_ptr<T> _instance = std::make_unique<T>();

  if(new_instance)
    _instance = std::move(new_instance);

  return *_instance.get();
}

/// return const version of \see uniqueInstance
template<typename T>
const T& constUniqueInstance(std::unique_ptr<T> new_instance = nullptr)
{
  return uniqueInstance<T>(std::move(new_instance));
}
