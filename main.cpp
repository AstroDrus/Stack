#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>


template < typename T >
class Stack
{
public:
    Stack();
    Stack(const Stack< T >& other);
    Stack(Stack< T >&& other);
    Stack& operator=(Stack< T >& other);
    Stack& operator=(Stack< T >&& other);

    ~Stack();

public:
    void push(const T& num);
    void pop();
    const T& top();

private:
    void CheckOneMorePush();

private:
    T* data_;
    int size_;
    int capacity_;
};


template < typename T >
Stack< T >::Stack() : data_(nullptr), size_(0), capacity_(0)
{

}

template < typename T >
Stack< T >::Stack(const Stack< T >& other)
{
    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = new T[capacity_];

    for (int i = 0; i < size_; ++i)
    {
        data_[i] = other.data_[i];
    }
}

template < typename T >
Stack< T >::Stack(Stack< T >&& other)
{
    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = other.data_;

    other.data_ = nullptr;
    other.capacity_ = 0;
    other.size_ = 0;
}


template < typename T >
Stack< T >& Stack< T >::operator=(Stack< T >& other)
{   
    if(*this != other)
    {
    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = new T [other.data_];
    for (int i = 0; i < size_; ++i)
    {
        data_[i] = other.data_[i];
    }

    }
    return *this;
}


template < typename T >
Stack< T >& Stack< T >::operator=(Stack< T >&& other)
{
    if(*this != other)
    {
    delete[] data_;

    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = other.data_;
    other.size_ = 0;
    other.capacity_ = 0;
    other.data_ = nullptr;
    }
    return *this;
}

template < typename T >
Stack< T >::~Stack()
{
    delete[] data_;
}

template < typename T >
void Stack< T >::CheckOneMorePush()
{
    if (size_ == 0)
    {
        capacity_ = 5;
        data_ = new T[capacity_];
    }

    else if (size_ == capacity_)
    {
        T* buffer = new T[size_];
        for (int i = 0; i < size_; ++i)
        {
            buffer[i] = data_[i];

        }
        capacity_ += 5;
        delete[] data_;
        data_ = new T[capacity_];

        for (int i = 0; i < size_; ++i)
        {
            data_[i] = buffer[i];

        }

        delete[] buffer;
    }

}

template < typename T >
void Stack< T >::push(const T& num)
{
    CheckOneMorePush();

    data_[size_] = num;
    ++size_;
}

template < typename T >
void Stack< T >::pop()
{
    --size_;
}

template < typename T >
const T& Stack< T >::top()
{
    if (size_ == 0)
    {
        throw std::underflow_error("is empty ");
    }
    else
    {
        return data_[size_ - 1];
    }
}



int main()
{
    
    try {
        //int
        Stack <int> stackI;
        std::cout << "let's check ints" << std::endl;
        stackI.push(1);                                                 
        std::cout << "last element is - " << stackI.top() << '\n';
        stackI.push(2);                                                  
        std::cout << "last element is - " << stackI.top() << '\n';
        stackI.push(3);      
        std::cout << "last element is - " << stackI.top() << '\n';                                              
        stackI.push(4);                                             
        std::cout << "last element is - " << stackI.top() << '\n';       
        stackI.push(5);                                             
        std::cout << "last element is - " << stackI.top() << '\n';       
        stackI.push(6);                                                  
        std::cout << "last element is - " << stackI.top() << '\n';
        stackI.push(7);                                                 
        std::cout << "last element is - " << stackI.top() << '\n';
        stackI.pop();
        std::cout << "last element after pop is - " << stackI.top() << '\n';                                                    
        stackI.pop();                                                   
        std::cout << "last element after pop is - " << stackI.top() << '\n'; 

        std::cout << "Test of rule of 5" << '\n';
        Stack <int> stack1 = stackI;
        std::cout << "last element after AO is - " << stack1.top() << '\n';
        Stack <int> stack2 {stack1};
        std::cout << "last element after CC is - " << stack2.top() << '\n';
        Stack <int> stack3 = std::move(stack2);
        std::cout << "last element after move AO is - " << stack3.top() << '\n';
        Stack <int> stack4 {std::move(stack3)};
        std::cout << "last element after move CC is - " << stack4.top() << '\n';


        
 
        //double
        Stack <double> stackD;
        std::cout << "let's check doubles" << std::endl;
        stackD.push(1.0);                                                 
        std::cout << "last element is - " << stackD.top() << '\n';
        stackD.push(2.9);                                                  
        std::cout << "last element is - " << stackD.top() << '\n';
        stackD.push(3.1);
        std::cout << "last element is - " << stackD.top() << '\n';                                                    
        stackD.push(4.4);                                           
        std::cout << "last element is - " << stackD.top() << '\n';         
        stackD.push(5.8);                                           
        std::cout << "last element is - " << stackD.top() << '\n';         
        stackD.push(6.2);                                                  
        std::cout << "last element is - " << stackD.top() << '\n';
        stackD.push(7.0);                                                 
        std::cout << "last element is - " << stackD.top() << '\n';
        stackD.pop();
        std::cout << "last element after pop is - " << stackD.top() << '\n';                                                    
        stackD.pop();                                                   
        std::cout << "last element after pop is - " << stackD.top() << '\n'; 

        //std::string
        Stack <std::string> stackS;
        std::cout << "let's check strings" << std::endl;
        stackS.push(" A ");                                                 
        std::cout << "last element is - " << stackS.top() << '\n';
        stackS.push(" B ");                                                  
        std::cout << "last element is - " << stackS.top() << '\n';
        stackS.push(" C ");
        std::cout << "last element is - " << stackS.top() << '\n';                                                    
        stackS.push(" D ");
        std::cout << "last element is - " << stackS.top() << '\n';                                                    
        stackS.push(" E ");                                         
        std::cout << "last element is - " << stackS.top() << '\n';           
        stackS.push(" F ");                                                  
        std::cout << "last element is - " << stackS.top() << '\n';
        stackS.push(" G ");                                                 
        std::cout << "last element is - " << stackS.top() << '\n';
        stackS.pop();
        std::cout << "last element after pop is - " << stackS.top() << '\n';                                                    
        stackS.pop();                                                   
        std::cout << "last element after pop is - " << stackS.top() << '\n'; 
    
        //char
        Stack <char> stackC;
        std::cout << "let's check chars" << std::endl;
        stackC.push('a');                                                 
        std::cout << "last element is - " << stackC.top() << '\n';
        stackC.push('b');                                                  
        std::cout << "last element is - " << stackC.top() << '\n';
        stackC.push('c');
        std::cout << "last element is - " << stackC.top() << '\n';                                                  
        stackC.push('d');
        std::cout << "last element is - " << stackC.top() << '\n';                                                  
        stackC.push('e');
        std::cout << "last element is - " << stackC.top() << '\n';                                                  
        stackC.push('f');                                                  
        std::cout << "last element is - " << stackC.top() << '\n';
        stackC.push('g');                                                 
        std::cout << "last element is - " << stackC.top() << '\n';
        stackC.pop();
        std::cout << "last element after pop is - " << stackC.top() << '\n';                                              
        stackC.pop();                                                   
        std::cout << "last element after pop is - " << stackC.top() << '\n'; 
    
    }
    catch (const std::underflow_error& er)
    {
        std::cout << er.what();
    }

}