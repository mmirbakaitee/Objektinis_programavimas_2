#include "vectorclass.h"

void classfunctiontest () {
  cout << "----------------------------------------VECTOR CLASS TEST----------------------------------------" << endl;
    Vector <int> vec;

cout << "\nELEMENT ACCESS TEST:" << endl;
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
  vec.resize(5);
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
void stdvectorfunctiontest () {
 cout << "----------------------------------------STD::VECTOR TEST----------------------------------------" << endl;
    vector <int> vec;

cout << "\nELEMENT ACCESS TEST:" << endl;
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
  typename vector<int>::allocator_type allocator = vec.get_allocator();
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
  vec.resize(5);
  cout << "After Resize: "; 
  for (const auto& element : vec) {
   cout << element << " ";
  }
  cout << endl;
  vector<int> otherVec = {200, 300};
  vec.swap(otherVec);
  cout << "After Swap: "; 
  for (const auto& element : vec) {
   cout << element << " ";
  }
  cout << endl;
  vec.clear(); 
}

void timetest () {
  cout << "----------------------------------------TIME TEST----------------------------------------" << endl;
unsigned int sz1 = 10000; 
unsigned int sz2 = 100000;  
unsigned int sz3 = 1000000;  
unsigned int sz4 = 10000000;  
unsigned int sz5 = 100000000;  

std::vector<int> v1;
Vector<int> v2;

auto startestv1 = std::chrono::high_resolution_clock::now();
for (int i = 1; i <= sz1; ++i)
    v1.push_back(i);
    auto endtestv1 = std::chrono::high_resolution_clock::now();
    auto durationtestv1 = std::chrono::duration_cast<std::chrono::microseconds>(endtestv1 - startestv1);
    v1.clear();
auto startestv2 = std::chrono::high_resolution_clock::now();
for (int i = 1; i <= sz2; ++i)
    v1.push_back(i);
    auto endtestv2 = std::chrono::high_resolution_clock::now();
    auto durationtestv2 = std::chrono::duration_cast<std::chrono::microseconds>(endtestv2 - startestv2);
    v1.clear();
auto startestv3 = std::chrono::high_resolution_clock::now();
for (int i = 1; i <= sz3; ++i)
    v1.push_back(i);
    auto endtestv3 = std::chrono::high_resolution_clock::now();
    auto durationtestv3 = std::chrono::duration_cast<std::chrono::microseconds>(endtestv3 - startestv3);
    v1.clear();
auto startestv4 = std::chrono::high_resolution_clock::now();
for (int i = 1; i <= sz4; ++i)
    v1.push_back(i);
    auto endtestv4 = std::chrono::high_resolution_clock::now();
    auto durationtestv4 = std::chrono::duration_cast<std::chrono::microseconds>(endtestv4 - startestv4);
    v1.clear();
auto startestv5 = std::chrono::high_resolution_clock::now();
for (int i = 1; i <= sz5; ++i)
    v1.push_back(i);
    auto endtestv5 = std::chrono::high_resolution_clock::now();
    auto durationtestv5 = std::chrono::duration_cast<std::chrono::microseconds>(endtestv5 - startestv5);
    v1.clear();

auto startestV1 = std::chrono::high_resolution_clock::now();
for (int i = 1; i <= sz1; ++i)
  v2.push_back(i);
  auto endtestV1 = std::chrono::high_resolution_clock::now();
  auto durationtestV1 = std::chrono::duration_cast<std::chrono::microseconds>(endtestV1 - startestV1);
  v2.clear();
auto startestV2 = std::chrono::high_resolution_clock::now();
for (int i = 1; i <= sz2; ++i)
  v2.push_back(i);
  auto endtestV2 = std::chrono::high_resolution_clock::now();
  auto durationtestV2 = std::chrono::duration_cast<std::chrono::microseconds>(endtestV2 - startestV2);
  v2.clear();
auto startestV3 = std::chrono::high_resolution_clock::now();
for (int i = 1; i <= sz3; ++i)
  v2.push_back(i);
  auto endtestV3 = std::chrono::high_resolution_clock::now();
  auto durationtestV3 = std::chrono::duration_cast<std::chrono::microseconds>(endtestV3 - startestV3);
  v2.clear();
auto startestV4 = std::chrono::high_resolution_clock::now();
for (int i = 1; i <= sz4; ++i)
  v2.push_back(i);
  auto endtestV4 = std::chrono::high_resolution_clock::now();
  auto durationtestV4 = std::chrono::duration_cast<std::chrono::microseconds>(endtestV4 - startestV4);
  v2.clear();
auto startestV5 = std::chrono::high_resolution_clock::now();
for (int i = 1; i <= sz5; ++i)
  v2.push_back(i);
  auto endtestV5 = std::chrono::high_resolution_clock::now();
  auto durationtestV5 = std::chrono::duration_cast<std::chrono::microseconds>(endtestV5 - startestV5);
  v2.clear();


 cout << left << "std::vector laikas (10000):      " << left << durationtestv1.count() / 1000000.0 << " seconds. " << endl;
 cout << left << "std::vector laikas (100000):     " << left << durationtestv2.count() / 1000000.0 << " seconds. " << endl;
 cout << left << "std::vector laikas (1000000):    " << left << durationtestv3.count() / 1000000.0 << " seconds. " << endl;
 cout << left << "std::vector laikas (10000000):   " << left << durationtestv4.count() / 1000000.0 << " seconds. " << endl;
 cout << left << "std::vector laikas (100000000):  " << left << durationtestv5.count() / 1000000.0 << " seconds. " << endl;
 cout << endl;
 cout << left << "Vector class laikas (1000):      " << left << durationtestV1.count() / 1000000.0 << " seconds. " << endl;
 cout << left << "Vector class laikas (10000):     " << left << durationtestV2.count() / 1000000.0 << " seconds. " << endl;
 cout << left << "Vector class laikas (100000):    " << left << durationtestV3.count() / 1000000.0 << " seconds. " << endl;
 cout << left << "Vector class laikas (1000000):   " << left << durationtestV4.count() / 1000000.0 << " seconds. " << endl;
 cout << left << "Vector class laikas (10000000):  " << left << durationtestV5.count() / 1000000.0 << " seconds. " << endl;

}

int main() {
    int choice1, choice2;

    cout << "\nAr norite palyginti std::vector ir Vector class laikus? Jei taip iveskite 1, kitu atveju 0: ";
    cin >> choice1;
    while (cin.fail() || (choice1 != 1 && choice1 != 0)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Neteisingas pasirinkimas. Iveskite 1 arba 0: ";
        cin >> choice1;
    }

    cout << "\nAr norite pamatyti visu Vector class testus? Jei taip iveskite 1, kitu atveju 0: ";
    cin >> choice2;
    while (cin.fail() || (choice2 != 1 && choice2 != 0)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Neteisingas pasirinkimas. Iveskite 1 arba 0: ";
                cin >> choice2;
            }

    if (choice1 == 1) {
            timetest();
            if (choice2 == 1) {
                classfunctiontest();
                stdvectorfunctiontest();
            } 
            else if (choice2 == 0) {
                exit(0);
            }
             exit(0);
        }
    
    else if (choice1 == 0) {
              if (choice2 == 1) {
                classfunctiontest();
                stdvectorfunctiontest();
            }
            else if (choice2 == 0) {
                exit(0);
            }
            exit(0);
        }

  return 0;
}
