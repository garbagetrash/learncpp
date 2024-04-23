#include "tutorial.h"
#include <fstream>
#include <ranges>
#include <string>
#include <vector>

// Listing 1.1 - Calculating the number of lines the imperative way
std::vector<int>
count_lines_in_files1(const std::vector<std::string>& files)
{
  std::vector<int> results;
  char c = 0;
  for (const auto& file : files) {
    int line_count = 0;
    std::ifstream in(file);
    while (in.get(c)) {
      if (c == '\n') {
        line_count++;
      }
    }
    results.push_back(line_count);
  }
  return results;
}

// Listing 1.2 - Using std::count to count newline characters
int count_lines(const std::string& filename)
{
  std::ifstream in(filename);
  return std::count(
      std::istreambuf_iterator<char>(in),
      std::istreambuf_iterator<char>(),
      '\n');
}

std::vector<int>
count_lines_in_files2(const std::vector<std::string>& files)
{
  std::vector<int> results;
  for (const auto& file : files) {
    results.push_back(count_lines(file));
  }
  return results;
}

// Listing 1.3 - Mapping files to line counts by using std::transform
std::vector<int>
count_lines_in_files3(const std::vector<std::string>& files)
{
  std::vector<int> results(files.size());
  std::transform(files.cbegin(), files.cend(),
      results.begin(),
      count_lines);
  return results;
}

// Listing 1.4 - Transformation using ranges
std::vector<int>
count_lines_in_files4(const std::vector<std::string>& files)
{
  auto t = files | std::views::transform(count_lines);
  return std::vector<int>(t.begin(), t.end());
}

int main() {
  return 0;
}
