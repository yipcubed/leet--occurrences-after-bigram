#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

// https://leetcode.com/problems/occurrences-after-bigram/submissions/

#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

#ifndef WIN32
// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

#endif

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  vector<string> findOcurrences(string& text, string& first, string& second) {
    vector<string> r;
    if (text.empty())
      return r;
    istringstream ss(text);
    string w1, w2, w3;
    if (!(ss >> w1))
      return r;
    if (!(ss >> w2))
      return r;
    while (ss >> w3) {
      if (w1 == first && w2 == second) {
        r.push_back(w3);
      }
      w1 = w2;
      w2 = w3;
    }
    return r;
  }
};

void test1() {
  string text = "alice is a good girl she is a good student", first = "a", second = "good";

  cout << "[\"girl\",\"student\"] ? " << Solution().findOcurrences(text, first, second) << endl;

  string text2 = "we will we will rock you";
  string f2 = "we";
  string s2 = "will";
  cout << "[we, rock] ? " << Solution().findOcurrences(text2, f2, s2) << endl;
}

void test2() {

}

void test3() {

}