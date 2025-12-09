#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

const std::string DATA_FILEPATH = "./input.txt";

std::vector<std::tuple<long long, long long>> get_ranges_from_file() {
  std::ifstream f(DATA_FILEPATH);
  std::string text = "";
  std::getline(f, text);

  std::vector<std::tuple<long long, long long>> ranges;

  long long start = 0;
  long long end = 0;
  bool dash_found = false;

  for (char ch : text) {
    if (isdigit(ch)) {
      if (!dash_found) {
        start = (start * 10) + (ch - '0');
      } else {
        end = (end * 10) + (ch - '0');
      }
    } else if (ch == '-') {
      dash_found = true;
    } else {
      ranges.push_back(std::make_tuple(start, end));

      start = 0;
      end = 0;
      dash_found = false;
    }
  }

  f.close();

  return ranges;
}

int main() {
  auto ranges = get_ranges_from_file();
  long long res = 0;
  for (auto range : ranges) {
    long long start = std::get<0>(range);
    long long end = std::get<1>(range);

    for (long long i = start; i <= end; i++) {
      std::string str_i = std::to_string(i);

      if (str_i.length() % 2 != 0) {
        continue;
      }

      std::string part_1 = str_i.substr(0, str_i.length() / 2);
      std::string part_2 = str_i.substr(str_i.length() / 2, str_i.length() / 2);

      if (part_1 == part_2) {
        res += i;
      }
    }
  }

  std::cout << res << std::endl;
  return 0;
}
