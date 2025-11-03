#include <bits/stdc++.h>

using namespace std;

int EvalutePostfix(vector < string > & postfix) {
  stack < int > st;
  for (auto & token: postfix) {
    if (token == "+" || token == "-" || token == "*" || token == "/") {
      int first = st.top();
      st.pop();
      int second = st.top();
      st.pop();
      if (token == "+")
        st.push(first + second);
      else if (token == "-")
        st.push(second - first);
      else if (token == "*")
        st.push(first * second);
      else
        st.push(second / first);
    } else
      st.push(stoi(token));
  }
  return st.top();
}
