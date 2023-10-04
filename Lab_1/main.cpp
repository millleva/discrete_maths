#include <iostream>
#include <set>
#include <vector>
#include <sstream>

using namespace std;

void printSet(set<int> s){
  for(auto el : s){
    cout << el << " ";
  }
  cout << endl;
}

void printMatrix(int** matrix, int rows, int cols){
  for(int row = 0; row < rows; row++){
    for(int col = 0; col < cols; col++){
      cout << matrix[row][col] << "\t";
    }
    cout << endl;
  }
  cout << endl;
}

void printVector(vector<int> v){
  for(auto el : v) cout << el << " ";
  cout << endl;
}

set<int> unionSets(set<int> a, set<int> b){
  set<int> result = a;
  for(auto el : b) result.insert(el);
  return result;
}

int conditionResult(int a, int b){
  return ((2*a - b) < 3) ? 1 : 0;
}

int** initMatrix(int rows, int cols){
  int** matrix = new int*[rows];
  for(int row = 0; row < rows; row++){
    matrix[row] = new int[cols];
    for(int col = 0; col < cols; col++){
      matrix[row][col] = -1;
    }
  }
  return matrix;
}

int** binaryRelationMatrix(set<int> a, set<int> b){
  int rows = a.size();
  int cols = b.size();
  int** matrix = initMatrix(rows, cols);

  vector<int> va(a.begin(), a.end());
  vector<int> vb(b.begin(), b.end());

  for(int row = 0; row < rows; row++)
    for(int col = 0; col < cols; col++)
      matrix[row][col] = conditionResult(va[row], vb[col]);
  
  return matrix;
}

void printBRM(int** matrix, set<int> a, set<int> b){
  vector<int> va(a.begin(), a.end());
  vector<int> vb(b.begin(), b.end());

  cout << "A↓ B→" << "\t";
  for(auto el : vb) cout << el << "\t";
  cout << endl;

  for(int row = 0; row < a.size(); row++){
    cout << va[row] << "\t";
    for(int col = 0; col < b.size(); col++){
      cout << matrix[row][col] << "\t";
    }
    cout << endl;
  }
  cout << endl;
}

set<int> getSetFromUser(char letter){
  string buf;
  cout << "Enter set " << letter << " separated by spaces: ";
  getline(cin, buf);
  stringstream ss(buf);
  string element;
  set<int> result; 
  while(getline(ss, element, ' ')){
    result.insert(stoi(element));
  }
  return result;
}

int main(){

  // set<int> a {1, 3, 7, 10, 13, 20};
  // set<int> b {2, 3, 5, 7, 11, 13, 15, 19};
  set<int> a = getSetFromUser('A');
  set<int> b = getSetFromUser('B');

  cout << "A U B: ";
  printSet(unionSets(a, b));
  // int rows = a.size();
  // int cols = b.size();
  int** matrix = binaryRelationMatrix(a, b);
  cout << "Binary related matrix: " << endl;
  printBRM(matrix, a, b);

  return 0;
}