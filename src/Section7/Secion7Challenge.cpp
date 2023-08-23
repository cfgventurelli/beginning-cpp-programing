#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{

  cout << "vector1" << endl;
  vector<int> vector1 {};
  vector1.push_back(10);
  vector1.push_back(20);

  cout << vector1.at(0) << endl;
  cout << vector1.at(1) << endl;
  cout << "vector1 contains " << vector1.size() << " elements" << endl;
  cout << endl;

  cout << "vector2" << endl;
  vector<int> vector2 {};
  vector2.push_back(100);
  vector2.push_back(200);

  cout << vector2.at(0) << endl;
  cout << vector2.at(1) << endl;
  cout << "vector2 contains " << vector2.size() << " elements" << endl;
  cout << endl;

  cout << "vector2d" << endl;
  vector<vector<int>> vector2d {};
  vector2d.push_back(vector1);
  vector2d.push_back(vector2);

  cout << vector2d.at(0).at(0) << " " << vector2d.at(0).at(1) << endl;
  cout << vector2d.at(1).at(0) << " " << vector2d.at(1).at(1) << endl;
  cout << endl;

  vector1.at(0) = 100;

  cout << "vector2d" << endl;
  cout << vector2d.at(0).at(0) << " " << vector2d.at(0).at(1) << endl;
  cout << vector2d.at(1).at(0) << " " << vector2d.at(1).at(1) << endl;
  cout << endl;

  cout << "vector1" << endl;
  cout << vector1.at(0) << endl;
  cout << vector1.at(1) << endl;
  cout << "vector1 contains " << vector1.size() << " elements" << endl;
  cout << endl;

  return 0;
}