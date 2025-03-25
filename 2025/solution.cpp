#include <tuple>

#include "frequency_table.hpp"

std::tuple<int, int, int> solve(int k) {
  int best{}, best_x{}, best_y{};

  for (int x{}; x < 4 * k; ++x) {
    frequency_table st(10 * k);

    for (int i{}; i < k; ++i) {
      for (int j{}; j < k; ++j) {
        st.add((x + i) ^ j);
      }
    }

    for (int y{}; y < 4 * k; ++y) {
      if (best < st.size()) {
        best = st.size();
        best_x = x;
        best_y = y;
      }

      for (int i{}; i < k; ++i) {
        st.remove((x + i) ^ y);
        st.add((x + i) ^ (y + k));
      }
    }
  }

  return {best, best_x, best_y};
}