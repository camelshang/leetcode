// Fizz Buzz

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> fizzbuzz(int n){
  vector<string> res;
  for(int i=1;i<=n;i++){
    /*string s;
    if (i%3 == 0 && i%5 ==0) s = "FizzBuzz";
    else if (i%3 == 0) s = "Fizz";
    else if (i%5 == 0) s = "Buzz";
    else s = to_string(i);
    res.push_back(s);*/
    res.push_back((i%3 == 0 && i%5 ==0)?"FizzBuzz":(i%3==0?"Fizz":(i%5==0?"Buzz":to_string(i))));
  }
  return res;
}

vector<string> fizzBuzz2(int n) {
        vector<string> res;
        for(int i = 1,fizz = 0, buzz = 0;i <= n; i++){
            fizz++;
            buzz++;
            if (fizz == 3 && buzz ==5){
                res.push_back("FizzBuzz");
                fizz = 0;
                buzz = 0;
            }
            else if (fizz == 3){
                res.push_back("Fizz");
                fizz = 0;
            }
            else if (buzz == 5){
                res.push_back("Buzz");
                buzz = 0;
            }
            else{
                res.push_back(to_string(i));
            }
            
        }
        return res;
}

vector<string> fizzBuzz3(int n) {
        vector<string> ret_vec(n);
        for(int i=1; i<=n; ++i)
        {
            if(i%3 == 0)
            {
                ret_vec[i-1] += string("Fizz");
            }
            if(i%5 == 0)
            {
                ret_vec[i-1] += string("Buzz");
            }
            if(ret_vec[i-1] == "")
            {
                ret_vec[i-1] += to_string(i);
            }
        }
        return ret_vec;
}


int main(){
  int n = 15;
  vector<string> res = fizzBuzz2(n);
  for(auto m:res){
    cout << m << endl;
  }
}