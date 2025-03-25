#include <cassert>
#include <vector>

class frequency_table {
 public:
  // Constructor that initializes an empty table with a given size
  explicit frequency_table(int);

  // Add an element to the frequency table
  void add(int);

  // Remove an element from the frequency table
  void remove(int);

  // Get the frequency of an element
  int operator[](int) const;

  // Get the number of distinct elements
  unsigned int size() const;

 private:
  std::vector<int> table_;
  unsigned int distinct_count_ = 0;
};