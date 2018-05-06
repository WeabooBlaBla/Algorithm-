#include "iostream"
#include "cstdlib"

using namespace std;
int recursion1(int n);
int nonRecursion1(int n);

int main() {

  cout<<"recursion:" << recursion1(5) << "\n";
  cout<<"nonRecursion:" << nonRecursion1(5) << "\n";

  return 0;
}

int recursion1(int n){
  if (n==1||n==2) {
    cout<< "n recursion = " << n << "\n";
    return 1;
  }
  else{
    cout<< "n recursion = " << n << "\n";
    return recursion1(n-1) + (n-1)*recursion1(n-2);
  }
}

int nonRecursion1(int n){
  if (n==1||n==2) {
    return 1;
  }
  else{
    int *array;
    array = new (nothrow)int[n+1];
    array[1]= 1;
    array[2]= 1;
    for(int i=3; i <= n; i++ ){
      array[i] = array[i-1] + (i-1)*array[i-2];
    }
    return array[n];
  }
}
