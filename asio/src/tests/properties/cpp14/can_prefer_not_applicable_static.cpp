//
// cpp14/can_prefer_not_applicable_static.cpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2025 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include "asio/prefer.hpp"
#include <cassert>

template <int>
struct prop
{
  static constexpr bool is_preferable = true;
  template <typename> static constexpr bool static_query_v = true;
  static constexpr bool value() { return true; }
};

template <int>
struct object
{
};

int main()
{
  static_assert(!asio::can_prefer_v<object<1>, prop<1>>, "");
  static_assert(!asio::can_prefer_v<object<1>, prop<1>, prop<1>>, "");
  static_assert(!asio::can_prefer_v<object<1>, prop<1>, prop<1>, prop<1>>, "");
  static_assert(!asio::can_prefer_v<const object<1>, prop<1>>, "");
  static_assert(!asio::can_prefer_v<const object<1>, prop<1>, prop<1>>, "");
  static_assert(!asio::can_prefer_v<const object<1>, prop<1>, prop<1>, prop<1>>, "");
}
