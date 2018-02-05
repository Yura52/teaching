#include <cmath>
#include <cstddef>
#include <iterator>

// =================================================================================================
namespace my_std {

// http://en.cppreference.com/w/cpp/iterator/iterator_tags
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};


// =================================================================================================
template<typename T>
class List {
    // inheritance from std::iterator is deprecated!
    // When you create a new Iterator class, you have to manually write five usings:
    class Iterator {
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type = ssize_t;
        // ...
    };
};

template<typename T>
class Vector {
    class Iterator {
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        using iterator_category = std::random_access_iterator_tag;
        using difference_type = ssize_t;
        // ...
    };
};

// =================================================================================================
// So, if "Iterator" is a class representing some iterator, then we can infer type to which
// such iterator points:
// Iterator::value_type
// Example: Vector<int>::Iterator::value_type == int
//
// But raw pointers are also iterators in some sence.
// We want to be able to infer "value_type" even if Iterator == T*
// For this purpose you should use std::iterator_traits

// http://en.cppreference.com/w/cpp/iterator/iterator_traits
template<typename Iterator>
struct iterator_traits {
    using value_type = typename Iterator::value_type;
    using pointer = typename Iterator::pointer;
    using reference = typename Iterator::reference;
    using iterator_category = typename Iterator::iterator_category;
    using difference_type = typename Iterator::difference_type;
};
// Example: iterator_traits<Vector<int>::Iterator>::value_type == Vector<int>::Iterator::value_type

template<typename T>
struct iterator_traits<T*> {
    using value_type = T;
    using pointer = T*;
    using reference = T&;
    using iterator_category = std::random_access_iterator_tag;
    // special type for difference between pointers, usually it's just "long"
    using difference_type = std::ptrdiff_t;
};
// Example: iterator_traits<int*>::value_type == int

// =================================================================================================
template<typename T>
struct less {
    bool operator()(const T& first, const T& second) const {
        return first < second;
    }
};
// Example: less<int>()(1, 2) == true;
// Example: less<int>()(2, 1) == false;

// =================================================================================================
// Let's write the signature of std::sort

// First attempt
template<typename RandomAccessIterator>
void sort1(RandomAccessIterator first, RandomAccessIterator last);
// Problem: how to pass a custom comparator instead of "<" ?

// Second attempt
template<typename RandomAccessIterator, typename Comparator>
void sort2(RandomAccessIterator first, RandomAccessIterator last, Comparator comparator);
// Problem: now we always have to pass comparator. It's not convenient.

// Third attempt
template<
    typename RandomAccessIterator,
    typename Comparator = less<typename RandomAccessIterator::value_type>
>
void sort3(RandomAccessIterator first, RandomAccessIterator last, Comparator comparator = {});
// Problem: it doesn't work for raw pointers

// The best attempt
template<
    typename RandomAccessIterator,
    typename Comparator = less<typename iterator_traits<RandomAccessIterator>::value_type>
>
void sort(RandomAccessIterator first, RandomAccessIterator last, Comparator comparator = {});


// =================================================================================================
// Let's write std::advance http://en.cppreference.com/w/cpp/iterator/advance
// Start reading from the function "advance" (at the end of the file), not from the "advance_helper"
// Here you can find similar example: http://en.cppreference.com/w/cpp/iterator/iterator_tags
// This technique is called "tag dispatching"

template<class RandomAccessIterator>
void advance_helper(
    RandomAccessIterator& iterator,
    typename std::iterator_traits<RandomAccessIterator>::difference_type n,
    std::random_access_iterator_tag)
{
    iterator += n;
}

template<class BidirectionalIterator>
void advance_helper(
    BidirectionalIterator& iterator,
    typename std::iterator_traits<BidirectionalIterator>::difference_type n,
    std::bidirectional_iterator_tag)
{
    if (n > 0) {
        for (int32_t i = 0; i < n; ++i) {
            ++iterator;
        }
    } else {
        for (int32_t i = 0; i < std::abs(n); ++i) {
            --iterator;
        }
    }
}

template<class InputIterator>
void advance_helper(
    InputIterator& iterator,
    typename std::iterator_traits<InputIterator>::difference_type n,
    std::input_iterator_tag)
{
    while(n--) {
        ++iterator;
    }
}

template<class Iterator>
void advance(
    Iterator& iterator,
    typename std::iterator_traits<Iterator>::difference_type n)
{
    advance_helper(
        iterator,
        n,
        std::iterator_traits<Iterator>::iterator_category()
    );
}

} // my_std

int main() {
    return 0;
}
