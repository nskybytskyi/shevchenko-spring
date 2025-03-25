#include <chrono>
#include <fstream>
#include <iostream>

#include "solution.hpp"

int main() {
  const auto all_start{std::chrono::high_resolution_clock::now()};

  std::ofstream fout("table.csv");
  if (!fout.is_open()) {
    std::cerr << "Failed to open the output file.\n";
    return 1;
  }

  fout << "k, x_0, y_0, size\n" << std::flush;
  std::cerr << std::fixed << std::setprecision(6);

  constexpr auto K{(1 << 9) + 2};
  for (int k{1}; k <= K; ++k) {
    const auto start{std::chrono::high_resolution_clock::now()};
    const auto [size, x_0, y_0] = solve(k);
    const auto end{std::chrono::high_resolution_clock::now()};
    std::chrono::duration<double> elapsed{end - start};

    fout << k << ", " << x_0 << ", " << y_0 << ", " << size << "\n"
         << std::flush;

    std::cerr << "Time taken for k = " << std::setw(3) << k << ": "
              << std::setw(10) << elapsed.count() << " seconds\n";
  }

  const auto all_end{std::chrono::high_resolution_clock::now()};
  std::chrono::duration<double> all_elapsed{all_end - all_start};

  std::cerr << "Time taken for k ≤ " << std::setw(3) << K << ": "
            << std::setw(10) << all_elapsed.count() << " seconds\n";
}
