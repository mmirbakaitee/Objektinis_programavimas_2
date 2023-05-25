#include "vsourceVV.h"


void classfunctiontest () {
  cout << "\n----------------------------------------Vector CLASS TEST----------------------------------------" << endl;
   Vector <int> vec;

cout << "ELEMENT ACCESS TEST:" << endl;
  vec.push_back(10);
  vec.push_back(20);
  vec.push_back(30);
  cout << "Original Array: "; 
  for (const auto& element : vec) {
    cout << element << " ";
  }
  cout << endl;
  cout << "Element at index 1 (operator[]): " << vec[1] << endl;
  cout << "Element index 2 (at()): " << vec.at(2) << endl;
  cout << "First element (front()): " << vec.front() << endl;
  cout << "Last element (back()): " << vec.back() << endl;
  vec[0] = 100;
  vec.at(1) = 200;
  cout << "Modified Array: "; 
  for (const auto& element : vec) {
    cout << element << " ";
  }
  cout << endl;
  vec.clear();

  cout << "\nITERATORS TEST:" << endl;
  vec = {1, 2, 3, 4, 10};
  cout << "Original Array: "; 
  for (const auto& element : vec) {
    cout << element << " ";
  }
  cout << endl;
  cout << "Forward Iteration (begin, end): ";
  for (auto it = vec.begin(); it != vec.end(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
  cout << "Forward Iteration (cbegin, cend): ";
  for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
  cout << "Reverse Iteration (rbegin, rend): ";
  for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
  cout << "Reverse Iteration (crbegin, crend): ";
  for (auto it = vec.crbegin(); it != vec.crend(); ++it) {
    cout << *it << " ";
  }
  vec.clear();

  cout << "\n\nCAPACITY TEST:" << endl;
  cout << "--------Original Array: " << endl;
  cout << "Empty? " << (vec.empty() ? "Yes" : "No") << ",  ";  
  for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
  cout << "Max Size: " << vec.max_size() << ", " << "Size: " << vec.size() << ", " << "Capacity: " << vec.capacity() << endl;
  vec.reserve(10);
  cout << "--------After Reserve (10): " << endl;
  cout << "Empty? " << (vec.empty() ? "Yes" : "No") << ",  ";  
  for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
  cout << "Max Size: " << vec.max_size() << ", " << "Size: " << vec.size() << ", " << "Capacity: " << vec.capacity() << endl;
  vec.resize(5);
  cout << "--------After Resize (5): " << endl;
  cout << "Empty? " << (vec.empty() ? "Yes" : "No") << ",  ";  
  for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
  cout << "Max Size: " << vec.max_size() << ", " << "Size: " << vec.size() << ", " << "Capacity: " << vec.capacity() << endl;
  vec.shrink_to_fit();
  cout << "--------After Shrink to Fit: " << endl;
  cout << "Empty? " << (vec.empty() ? "Yes" : "No") << ",  ";  
  for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
  cout << "Max Size: " << vec.max_size() << ", " << "Size: " << vec.size() << ", " << "Capacity: " << vec.capacity() << endl;
  vec.clear();

  cout << "\nMODIFIERS TEST:" << endl;
  vec.push_back(10);
  vec.push_back(20);
  vec.push_back(30);
  cout << "Original Array: "; 
  for (const auto& element : vec) {
   cout << element << " ";
  }
  cout << endl;
  vec.clear(); 
  cout << "After Clear: "; 
 for (const auto& element : vec) {
   cout << element << " ";
  }
  cout << endl;
  vec.assign(3, 40);
  cout << "After Assign: "; 
 for (const auto& element : vec) {
   cout << element << " ";
  }
  cout << endl;
  vec.insert(vec.begin(), 10);
  typename Vector<int>::allocator_type allocator = vec.get_allocator();
cout << "Vector Allocator Max Size: " << allocator.max_size() << endl;
  cout << "After insert: "; 
  for (const auto& element : vec) {
   cout << element << " ";
  }
  cout << endl;
  vec.emplace(vec.begin() + 1, 80);
  cout << "After Emplace: "; 
  for (const auto& element : vec) {
   cout << element << " ";
  }
  cout << endl;
  vec.erase(vec.begin() + 2);
  cout << "After Erase: "; 
 for (const auto& element : vec) {
   cout << element << " ";
  }
  cout << endl;
  vec.push_back(90);
  cout << "After Push Back: "; 
  for (const auto& element : vec) {
   cout << element << " ";
  }
  cout << endl;
  vec.emplace_back(100);
  cout << "After Emplace Back: "; 
for (const auto& element : vec) {
   cout << element << " ";
  }
  cout << endl;
  vec.pop_back();
  cout << "After Pop Back: "; 
for (const auto& element : vec) {
   cout << element << " ";
  }
  cout << endl;
  vec.resize(6);
  cout << "After Resize: "; 
  for (const auto& element : vec) {
   cout << element << " ";
  }
  cout << endl;
  Vector<int> otherVec = {200, 300};
  vec.swap(otherVec);
  cout << "After Swap: "; 
  for (const auto& element : vec) {
   cout << element << " ";
  }
  cout << endl;
  vec.clear(); 
}
void stdVectorfunctiontest () {
 cout << "\n----------------------------------------std::vector TEST----------------------------------------" << endl;
    std::vector <int> vec;

cout << "ELEMENT ACCESS TEST:" << endl;
  vec.push_back(10);
  vec.push_back(20);
  vec.push_back(30);
  cout << "Original Array: "; 
  for (const auto& element : vec) {
    cout << element << " ";
  }
  cout << endl;
  cout << "Element at index 1 (operator[]): " << vec[1] << endl;
  cout << "Element index 2 (at()): " << vec.at(2) << endl;
  cout << "First element (front()): " << vec.front() << endl;
  cout << "Last element (back()): " << vec.back() << endl;
  vec[0] = 100;
  vec.at(1) = 200;
  cout << "Modified Array: "; 
  for (const auto& element : vec) {
    cout << element << " ";
  }
  cout << endl;
  vec.clear();

  cout << "\nITERATORS TEST:" << endl;
  vec = {1, 2, 3, 4, 10};
  cout << "Original Array: "; 
  for (const auto& element : vec) {
    cout << element << " ";
  }
  cout << endl;
  cout << "Forward Iteration (begin, end): ";
  for (auto it = vec.begin(); it != vec.end(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
  cout << "Forward Iteration (cbegin, cend): ";
  for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
  cout << "Reverse Iteration (rbegin, rend): ";
  for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
  cout << "Reverse Iteration (crbegin, crend): ";
  for (auto it = vec.crbegin(); it != vec.crend(); ++it) {
    cout << *it << " ";
  }
  vec.clear();

  cout << "\n\nCAPACITY TEST:" << endl;
  cout << "--------Original Array: " << endl;
  cout << "Empty? " << (vec.empty() ? "Yes" : "No") << ",  ";  
  for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
  cout << "Max Size: " << vec.max_size() << ", " << "Size: " << vec.size() << ", " << "Capacity: " << vec.capacity() << endl;
  vec.reserve(10);
  cout << "--------After Reserve (10): " << endl;
  cout << "Empty? " << (vec.empty() ? "Yes" : "No") << ",  ";  
  for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
  cout << "Max Size: " << vec.max_size() << ", " << "Size: " << vec.size() << ", " << "Capacity: " << vec.capacity() << endl;
  vec.resize(5);
  cout << "--------After Resize (5): " << endl;
  cout << "Empty? " << (vec.empty() ? "Yes" : "No") << ",  ";  
  for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
  cout << "Max Size: " << vec.max_size() << ", " << "Size: " << vec.size() << ", " << "Capacity: " << vec.capacity() << endl;
  vec.shrink_to_fit();
  cout << "--------After Shrink to Fit: " << endl;
  cout << "Empty? " << (vec.empty() ? "Yes" : "No") << ",  ";  
  for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
  cout << "Max Size: " << vec.max_size() << ", " << "Size: " << vec.size() << ", " << "Capacity: " << vec.capacity() << endl;
  vec.clear();

  cout << "\nMODIFIERS TEST:" << endl;
  vec.push_back(10);
  vec.push_back(20);
  vec.push_back(30);
  cout << "Original Array: "; 
  for (const auto& element : vec) {
   cout << element << " ";
  }
  cout << endl;
  vec.clear(); 
  cout << "After Clear: "; 
 for (const auto& element : vec) {
   cout << element << " ";
  }
  cout << endl;
  vec.assign(3, 40);
  cout << "After Assign: "; 
 for (const auto& element : vec) {
   cout << element << " ";
  }
  cout << endl;
  vec.insert(vec.begin(), 10);
  typename std::vector<int>::allocator_type allocator = vec.get_allocator();
cout << "std::vector Allocator Max Size: " << allocator.max_size() << endl;
  cout << "After insert: "; 
  for (const auto& element : vec) {
   cout << element << " ";
  }
  cout << endl;
  vec.emplace(vec.begin() + 1, 80);
  cout << "After Emplace: "; 
  for (const auto& element : vec) {
   cout << element << " ";
  }
  cout << endl;
  vec.erase(vec.begin() + 2);
  cout << "After Erase: "; 
 for (const auto& element : vec) {
   cout << element << " ";
  }
  cout << endl;
  vec.push_back(90);
  cout << "After Push Back: "; 
  for (const auto& element : vec) {
   cout << element << " ";
  }
  cout << endl;
  vec.emplace_back(100);
  cout << "After Emplace Back: "; 
for (const auto& element : vec) {
   cout << element << " ";
  }
  cout << endl;
  vec.pop_back();
  cout << "After Pop Back: "; 
for (const auto& element : vec) {
   cout << element << " ";
  }
  cout << endl;
  vec.resize(6);
  cout << "After Resize: "; 
  for (const auto& element : vec) {
   cout << element << " ";
  }
  cout << endl;
  std::vector<int> otherVec = {200, 300};
  vec.swap(otherVec);
  cout << "After Swap: "; 
  for (const auto& element : vec) {
   cout << element << " ";
  }
  cout << endl;
  vec.clear(); 
}
void timetest () {
  cout << "\n----------------------------------------TIME TEST (INT)----------------------------------------" << endl;
unsigned int sz1 = 10000; 
unsigned int sz2 = 100000;  
unsigned int sz3 = 1000000;  
unsigned int sz4 = 10000000;  
unsigned int sz5 = 100000000;  

std::vector<int> v1;
Vector<int> V1;

auto startestv1 = std::chrono::high_resolution_clock::now();
for (int i = 1; i <= sz1; ++i)
    v1.push_back(i);
    auto endtestv1 = std::chrono::high_resolution_clock::now();
    auto durationtestv1 = std::chrono::duration_cast<std::chrono::microseconds>(endtestv1 - startestv1);
    v1.clear();

auto startestV1 = std::chrono::high_resolution_clock::now();
for (int i = 1; i <= sz1; ++i)
  V1.push_back(i);
  auto endtestV1 = std::chrono::high_resolution_clock::now();
  auto durationtestV1 = std::chrono::duration_cast<std::chrono::microseconds>(endtestV1 - startestV1);
  V1.clear();

 cout << left << "std::Vector laikas:       " << left << durationtestv1.count() / 1000000.0 << " seconds. " << endl;
 cout << left << "Vector class laikas:      " << left << durationtestV1.count() / 1000000.0 << " seconds. " << endl;
}
void studentimetest () {
  cout << "\n----------------------------------------TIME TEST (STUDENT)----------------------------------------" << endl;
unsigned int sz1 = 10000; 
unsigned int sz2 = 100000;  
unsigned int sz3 = 1000000;    
unsigned int sz4 = 10000000; 
unsigned int sz5 = 100000000; 

Student a;
std::vector<Student> v1;
Vector<Student> V1;

auto startestv1 = std::chrono::high_resolution_clock::now();
for (int i = 1; i <= sz1; ++i)
    v1.push_back(a);
    auto endtestv1 = std::chrono::high_resolution_clock::now();
    auto durationtestv1 = std::chrono::duration_cast<std::chrono::microseconds>(endtestv1 - startestv1);
    v1.clear();

auto startestV1 = std::chrono::high_resolution_clock::now();
for (int i = 1; i <= sz1; ++i)
  V1.push_back(a);
  auto endtestV1 = std::chrono::high_resolution_clock::now();
  auto durationtestV1 = std::chrono::duration_cast<std::chrono::microseconds>(endtestV1 - startestV1);
  V1.clear();

 cout << left << "std::Vector laikas:       " << left << durationtestv1.count() / 1000000.0 << " seconds. " << endl;
 cout << left << "Vector class laikas:      " << left << durationtestV1.count() / 1000000.0 << " seconds. " << endl;
}

int main() {
      classfunctiontest ();
      stdVectorfunctiontest ();
      timetest ();
      studentimetest ();
      cout << "\n" << endl;
  return 0;
}
