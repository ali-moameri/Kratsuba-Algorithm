#include <algorithm>
#include <cmath>
#include <string>

class Kratsuba {

  static int char_to_int(char ch) { return ch - '0'; }

  static int digit_to_char(int digit) { return digit + '0'; }

  static void padStart(std::string &str, const std::string &str2, size_t count) {
    for (size_t i = 0; i < count; ++i)
      str.insert(0, str2);
  }

  static std::string largeAdd(std::string x, std::string y) {
    size_t len = std::max(x.length(), y.length());

    padStart(x, "0", len - x.length());
    padStart(y, "0", len - y.length());

    std::string result{};

    unsigned carry{0};
    int sum;

    for (int i = len - 1; i >= 0; --i) {
      sum = char_to_int(x[i]) + char_to_int(y[i]) + carry;

      result.insert(0, std::to_string((sum % 10)));

      carry = sum / 10;
    }

    if (carry)
      result.insert(0, std::to_string(carry));

    return result.erase(
        0, std::min(result.find_first_not_of('0'), result.size() - 1));
  }

  // the x should be greater than y
  static std::string largeSub(std::string x, std::string y) {
    size_t len = std::max(x.length(), y.length());

    padStart(x, "0", len - x.length());
    padStart(y, "0", len - y.length());

    int sub{0};
    std::string result{};

    for (int i = len - 1; i >= 0; --i) {
      sub = char_to_int(x[i]) - char_to_int(y[i]);

      if (sub < 0) {
        int j = i - 1;
        while (x[j] == '0' && j >= 0)
          --j;
        --x[j++];

        while (j < i) {
          x[j] = digit_to_char(char_to_int(x[j]) + 9);
          ++j;
        }
        sub += 10;
      }
      result.insert(0, std::to_string(sub));
    }
    return result.erase(
        0, std::min(result.find_first_not_of('0'), result.size() - 1));
  }

public:
  static std::string multiply(std::string x, std::string y) {
    size_t len = std::max(x.length(), y.length());

    // makes the sizes power of 2
    while (std::log2(len) - int(std::log2(len)) != 0)
      ++len;

    padStart(x, "0", len - x.length());
    padStart(y, "0", len - y.length());

    if (len == 1)
      return std::to_string(char_to_int(x[0]) * char_to_int(y[0]));

    else {
      std::string a{x.substr(0, x.length() / 2)};
      std::string b{x.substr(x.length() / 2)};
      std::string c{y.substr(0, y.length() / 2)};
      std::string d{y.substr(y.length() / 2)};

      std::string p{largeAdd(a, b)}; // a + b
      std::string q{largeAdd(c, d)}; // c + d

      std::string ac{multiply(a, c)}; // ac
      std::string bd{multiply(b, d)}; // bd

      std::string pq{multiply(p, q)}; // pq

      // pq - (ac + bd)
      std::string adbc{largeSub(pq, largeAdd(ac, bd))};

      // 10^n * ac
      for (size_t i = 0; i < len; ++i)
        ac.push_back('0');

      // 10^(n/2) * adbc
      for (size_t i = 0; i < len / 2; ++i)
        adbc.push_back('0');

      // 10^n * ac + 10^(n/2) * adbc + bd
      std::string result{largeAdd(largeAdd(ac, adbc), bd)};

      return result.erase(0, std::min(result.find_first_not_of('0'), result.size() - 1));
    }
  }
};