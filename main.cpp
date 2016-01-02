#include <iostream>
#include <sstream>
#include <math.h>
#include <string>
#include <vector>
#include <stack>
#include <limits.h>


// for test
#include <fstream>
#include <assert.h>

// 2147483647
// 3000000001

using namespace std;
class Solution {
public:
  int reverse(int x) {
    if (x==0) return 0;
    bool nag = false;
    int val = x;
    if(x<0){
      nag=true;
      val = -val;
    }
    stack<short> q = split(val);
    int ret = int_concat(q);
    return nag ? -ret : ret;
  }
  stack<short> split(int val){
    stack<short> q;
    bool canPush = false;
    for (; val != 0;) {
      int left = val/10;
      short mod = val%10;
      if (mod != 0 || canPush){
        q.push(mod);
        canPush = true;
      }
      val = left;
    }
    return q;
  }
  int int_concat(stack<short>& q){
    long ret = 0;
    int times = 0;
    while(!q.empty()){
      ret += q.top() * long_pow(10, times++);
      q.pop();
    }
    //cout<<endl<<ret<<endl;
    if (ret > INT_MAX || ret<INT_MIN){
      return 0;
    }
    return int(ret);
  }
  long long_pow(int ori, int times) {
    long ret = 1;
    for (int i =1; i<=times; i++){
      ret *= ori;
    }
    return ret;
  }
};

int main() {
  ifstream ins("test.data");
  Solution sol;
  stack<short> qtest;
  qtest.push(1);
  qtest.push(2);
  assert(sol.split(21)==qtest);
  assert(sol.int_concat(qtest)==12);
  assert(sol.long_pow(10,2)==100);
  int num;
  int result;
  while(ins>>num) {
    ins>>result;
    int ret = sol.reverse(num);
    if (ret != result){
      cout<<"expect:"<<result<<endl
          <<"butget:"<< ret<<endl;
      break;
    }
  }
}
