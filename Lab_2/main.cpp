#include <iostream>

using namespace std;

int factorial(int number){
	if (number <= 1) return number;
	else return number * factorial(number - 1);
}

int A(int k, int n){
  return factorial(n) / factorial(n - k);
}

void combinations(int k, int n, int currentLength, int currentCombination[]){
  if (currentLength == k){
    for (int i = 0; i < k; i++){
      cout << currentCombination[i] << " ";
    }
    cout << endl;
    return;
  }
  for (int i = 1; i <= n; i++){
    bool used = false;
    for (int j = 0; j < currentLength; j++){
      if (currentCombination[j] == i){
        used = true;
        break;
      }
    }
    if (!used){
      currentCombination[currentLength] = i;
      combinations(k, n, currentLength + 1, currentCombination);
    }
  }
}

int main(){
  int k;
  int n;
  cout << "Enter k(length of combination): ";
  cin >> k;
  cout << "Enter n(number of elements): ";
  cin >> n;

  int currentCombination[k];
  combinations(k, n, 0, currentCombination);

  cout << "A = " << A(k, n) << endl;
}