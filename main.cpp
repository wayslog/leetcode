#include <iostream>
#include <sstream>
#include <math.h>
#include <string>
#include <set>
#include <vector>
// for test
#include <fstream>
#include <assert.h>
// zigzag
// n=2,3... 第x(x=0,1..)第y(y=0,1..)列的值为
// z0 = x         0   1
// z1 = 4-x       4   3
// z2 = x + 1*4   4   5
// z3 = 4-x + 1*4 8   7
// z4 = x + 2*4   8   9
// z5 = 4-x + 2*4 12  11

//
// x=0 0   4   8     12    16
// x=1 1 3 5 7 9  11 13 15
// x=2 2   6   10    14

// n = 4
//
// x=0 0     6       12
// x=1 1   5 7    11 13
// x=2 2 4   8 10    14  16
// x=3 3     9       15

using namespace std;
class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows<=1) return s;
    size_t lenOfStr = s.size();

    vector<vector<int> > matrix ;

    for (int i = 0; i<numRows; i++) {
      vector<int> val = pickUp(lenOfStr, numRows, i);
      matrix.push_back(val);
    }
    return format(s, matrix);
  }

  string format(string ori,const vector<vector<int> > & ma) {
    string s(ori);
    int ord = 0;
    for (int i = 0; i< ma.size(); i++) {
      vector<int> vals = ma[i];
      cout<<endl;
      for (int j = 0; j<vals.size(); j++){
        int pos = vals[j];
        cout<<pos<<" ";
        s[ord++] = ori[pos];
      }
    }
    cout<<endl;
    return s;
  }

  vector<int> pickUp(size_t lenOfStr, int numRows, int row) {
    vector<int> ret;
    int last = -1;
    int pos = 0;
    for(size_t i = 0; ; i++){
      if (i%2==0) {
        pos = row + 2*(i/2)*(numRows-1);
      }else {
        pos = 2*numRows-2-row + 2*(i/2)*(numRows-1);
      }
      if (pos >= lenOfStr){
        return ret;
      }
      if (pos != last){
        last = pos;
        ret.push_back(last);
      }
    }
  }
};

int main() {
  ifstream ins("test.data");
  string ori;
  string out;
  int numRows;
  Solution sol;
  while(ins>>ori) {
    ins>>numRows;
    ins>>out;
    cout<<"ori:"<<ori<<endl
        <<"numRows:"<<numRows<<endl<<endl;
    string t = sol.convert(ori, numRows);
    assert(t==out);
    if (t!=out) {
      cout<<"converted:"<<t<<endl
          <<"expect   :"<<out<<endl;
      break;
    }
  }
}
