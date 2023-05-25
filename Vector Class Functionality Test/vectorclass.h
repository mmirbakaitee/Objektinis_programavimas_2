#include "studentlib.h"

template <typename T, typename Allocator = std::allocator<T>> class Vector {
private:
  std::vector<T> data;
  Allocator allocator;
public:
  // Constructors
   Vector() {}
  Vector(std::initializer_list<T> init) : data(init) {}
  ~Vector() {}

  // Capacity
  size_t size() const { return data.size(); }
  size_t max_size() const { return data.max_size(); }
  size_t capacity() const { return data.capacity(); }
  void resize(size_t n) { data.resize(n); }
  bool empty() const { return data.empty(); }
  void shrink_to_fit() { data.shrink_to_fit(); }
  void reserve(size_t n) { data.reserve(n); }

  // Element access
  Vector(size_t n) : data(n) {
  for (size_t i = 0; i < n; i++) {
    duomenys[i] = static_cast<T>(i + 1);
  }
}
  T& operator[](size_t g) { return data[g]; }
  const T& operator[](size_t g) const { return data[g]; }
  T& at(size_t g) { return data.at(g); }
  const T& at(size_t g) const { return data.at(g); }
  T& front() { return data.front(); }
  const T& front() const { return data.front(); }
  T& back() { return data.back(); }
  const T& back() const { return data.back(); }

  typename std::vector<T>::iterator begin() { return data.begin(); }
  typename std::vector<T>::const_iterator begin() const { return data.begin(); }
  typename std::vector<T>::iterator end() { return data.end(); }
  typename std::vector<T>::const_iterator end() const { return data.end(); }
  typename std::vector<T>::const_iterator cbegin() const { return data.cbegin(); }
  typename std::vector<T>::const_iterator cend() const { return data.cend(); }
  typename std::vector<T>::reverse_iterator rbegin() { return data.rbegin(); }
  typename std::vector<T>::const_reverse_iterator rbegin() const { return data.rbegin(); }
  typename std::vector<T>::reverse_iterator rend() { return data.rend(); }
  typename std::vector<T>::const_reverse_iterator rend() const { return data.rend(); }
  typename std::vector<T>::const_reverse_iterator crbegin() const { return data.crbegin(); }
  typename std::vector<T>::const_reverse_iterator crend() const { return data.crend(); }
  
    using allocator_type = Allocator;
    const Allocator& get_allocator() const {
        return allocator;
    }
  
  // Modifiers
template <typename InputIt>
void assign(InputIt first, InputIt last) {
  clear();
  append_range(first, last);
}
void assign(size_t count, const T& value) {
  clear();
  append_range(count, value);
}
void assign(const std::initializer_list<T>& init) {
  clear();
  append_range(init.begin(), init.end());
}
typename std::vector<T>::iterator insert(typename std::vector<T>::iterator po, typename std::vector<T>::const_iterator first,
typename std::vector<T>::const_iterator last) {
    return data.insert(po, first, last);
}

  void push_back(const T& value) {
    data.push_back(value);
  }
  void pop_back() { data.pop_back(); }
  void swap(Vector& other) { data.swap(other.data); }
  void clear() { data.clear(); }

  typename std::vector<T>::iterator insert(typename std::vector<T>::const_iterator pos, const T& value) {
    return data.insert(pos, value);
  }
  typename std::vector<T>::iterator erase(typename std::vector<T>::const_iterator pos) {
    return data.erase(pos);
  }
  typename std::vector<T>::iterator erase(typename std::vector<T>::const_iterator first,
                                          typename std::vector<T>::const_iterator last) {
    return data.erase(first, last);
  }
  template <typename... Args>
  typename std::vector<T>::iterator emplace(typename std::vector<T>::const_iterator pos, Args&&... args) {
    return data.emplace(pos, std::forward<Args>(args)...);
  }
  template <typename... Args>
  void emplace_back(Args&&... args) { data.emplace_back(std::forward<Args>(args)...); }

   // Custom Modifiers
template <typename InputIt>
void append_range(InputIt first, InputIt last) {
  assert(first <= last && "Invalid range!");
  data.insert(data.end(), first, last);
}
};


