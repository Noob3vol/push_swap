# Push_swap

Given a certain framework (2 stacks and basic manipulation instructions, implemented by you) 
you are required to output the most apropriate sort algorithm using this framework for nbr (int) given as input


## Framework
### Data

Nbr given as argument should be stocked in a stack-like structure. we will name it 'a'.
A second stack-like structure (named 'b') is available as free stock space


note thate i said stack-like because implementation is data type free

### Instruction

instruction go as follow

` pa / pb `  `Push top node to stack named`
` ra / rb / rr ` `rotate a stack (or both for rr) : first node become last, seconde become first, etc`
` rra / rrb / rrr ` `reverse rotate a stack (or both for rrr) : last node become first, first become seconde, etc`
` sa / sb ` `swap first and second node of a stack`

## Sorting algorithm selection

To decide which algorithm to choose i stock instruction in a list then compare instruction of all algorithm to select
the one with lower instruction, we assume that all instruction include the same complexity since they are executed by a tierce binary and notation scale is the same for all instruction

Sorting algorithm are often separated in two group, those who tend to have a quadratic complexity and those who have a quasi-linear complexity.

## Sorting algorithm

### Selection sort :
	selection sort find the lowest element of the stack, rotate to it and push it on stack b.  When all element are push to b the stack b is sorted from highest to lowest and you just need to push every element back to stack 'a' 

### Insertion sort :
	insertion sort start by putting an element in stack b,
if next element (we will call him '2a')  is higher than all stack b it is pushed then rotated
else element in b are rotated until '2a' fit higher than first element but lower than last (or lowest of the stack)
Redo until stack b is sorted by decreasin order and push all node to a

---

### Quicksort :
	Quicksort use divide and conquer strategy dividing input in sublist and sorting middle element recursivly.

Optimisation include pivot choose and using quadratic sort to counter explosion of temporal complexity with these algorithm.

---

## Extra

### Quicksort Pivot choose :
	divided stack part is exported as an array and sorted using an implemented quicksort to find best pivot picking middle element of sorted part

### Part sorting algorithm : hiatus
	Quadratic Part sorting algorithm is provided to sort small divided part where
quicksort pivot optimized is less effective. it is actually on hiatus because non optimized
quadratic sort are not more effective and a lot of work for small result should not hinder
school cursus progression

### Launching script : WIP
	A script is provided to test binary. It generate n random number 
(only positive, negative number error checking should be done manually) and test
input with both bonus checker and linux-checker. WIP because it should not be error-prone

### Review :
	I liked this project because it made me realise the importance of strategy.
- You should always think project globally before implementing it. A lot of tactics and technical sugar don't replace a well thinked strategy.

- Information gathering can affect your strategy and your decision making so having an analitics framework is a must-have.

- You should always compare time-invested/Algorithm-optimisation-return to know which optimisation/functionnality shall be implemented first. don't waste time building unelegant gas-factory code : they are hard to maintain, hard to work with, and usually less effective than simple well thinked code.
