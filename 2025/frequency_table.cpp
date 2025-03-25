#include "frequency_table.hpp"

frequency_table::frequency_table(int size) : table_(size, 0) {}

void frequency_table::add(int key) {
  assert(0 <= key && key < table_.size());
  if (!table_[key]) {
    ++distinct_count_;
  }
  ++table_[key];
}

void frequency_table::remove(int key) {
  assert(0 <= key && key < table_.size());
  assert(table_[key]);
  --table_[key];
  if (!table_[key]) {
    --distinct_count_;
  }
}

int frequency_table::operator[](int key) const {
  assert(0 <= key && key < table_.size());
  return table_[key];
}

unsigned int frequency_table::size() const { return distinct_count_; }
