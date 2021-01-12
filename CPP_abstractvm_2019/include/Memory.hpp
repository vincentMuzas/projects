//#include "IOperand.hpp"
#ifndef DEF_MEMORY
#define DEF_MEMORY

#include <algorithm>
#include <memory>
#include <string>
#include <sstream>
#include <vector>
#include "IComponents.hpp"
#include "IOperand.hpp"
class Memory : IComponents
{
public: 
    Memory(); // Constructeur
    ~Memory(); // Destructeur

    // Stack the v value at the top
    void push(const IOperand *rhs);

    // Unstack the v value at the top
    void pop(void);

    // Clear the stack
    void clear(void);

    // Duplicates the value at the top of the stack
    void dup();

    // Reverses the order of (swaps) the top two values on the stack
    void swap(void);

    // Display values in the stack
    void PrintStack(void);

    // Display the  ASCII value for the last stack value ( < 8bits)
    std::string print(void) const;

    // Get the register value and stack it a the top of the Stack
    void load(const IOperand *rhs);

    // Delete the top value and return it for the register
    const IOperand &store();
    void assert(const IOperand *rhs);
    std::string dump(void);
    //IOperand getLastValues(void) const; // Return the two last value of the stack

    private :
        std::vector<const IOperand *> operation;    
};
#endif