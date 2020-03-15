#include <iostream>

template <typename T>
class property
{
protected:
    T value;

public:
    property(T const & value = T());

    operator T const &() const;
    property<T>& operator=(T const & value);

    T const & get() const;
    property<T>& set(T const & value);

    //virtual T* operator->() { return &value; }
};

template <typename T> property<T>::property(T const & value) : value{value} {}

template <typename T> property<T>::operator T const &() const { return value; }
template <typename T> property<T>& property<T>::operator=(T const & value) { this->value = value; return *this; }

template <typename T> T const & property<T>::get() const { return value; }
template <typename T> property<T>& property<T>::set(T const & value) { this->value = value; return *this; }


/*
template <typename T>
requires std::is_class<T>
class property
{
protected:
    T value;

public:
    property(T const & value = T());

    operator T() const;
    property<T>& operator=(T value);

    T get() const;
    property<T>& set(T value);

    //virtual T* operator->() { return &value; }
};

*/
struct B
{
    int i;
};


struct A
{
    class : public property<int> {
    public:
        using property::operator=;
        operator int const &() const { static int i = 3 * value; return i; };
    } i{9};
};

int main()
{
    A a;
    a.i = 3;
    std::cout << a.i;
}
