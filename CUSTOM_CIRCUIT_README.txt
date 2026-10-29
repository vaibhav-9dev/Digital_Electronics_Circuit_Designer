CUSTOM CIRCUIT FROM TRUTH TABLE - EXTENSION

New menu option:
  11. Build Your Own Circuit from a Truth Table

What it does:
1. Asks for 1 to 6 input variables and their names.
2. Asks for the output Y for every binary input combination.
3. Prints the canonical Sum of Products (SOP) expression.
4. Minimizes the SOP expression using the Quine-McCluskey method and an exact
   minimum-cover search. The optimization objective is the fewest product terms,
   then the fewest literals.
5. Constructs a gate network using the existing AND, OR, and NOT gate classes.
6. Tests every row from the supplied truth table against the generated circuit.
7. Allows manual input combinations to be simulated interactively.

Boolean notation:
  !A = NOT A
  A*B = A AND B
  A + B = A OR B

Truth-table order:
The first variable is the leftmost / most-significant bit. For three inputs,
the generated rows are 000, 001, 010, 011, 100, 101, 110, 111.

Files added:
  BooleanMinimizer.h / BooleanMinimizer.cpp
  CustomCircuit.h / CustomCircuit.cpp

File changed:
  main.cpp (adds menu option 11 and the user interaction flow)

Build from this project folder with GCC:
  g++ -std=c++17 *.cpp -o simulator

On Windows, run the generated executable from a terminal. In VS Code, make sure
your C++ compiler task includes all .cpp files in this directory. Do not compile
main.cpp alone, since the existing project is split across multiple source files.

Scope of this first version:
- 1 to 6 input variables.
- One output named Y.
- Canonical SOP and minimized SOP output.
- Gate network made from AND, OR, NOT gates.
- No don't-care conditions, POS minimization, multi-output minimization, or GUI
  schematic editor yet.

The old simulator menu items and existing circuit code are retained.
