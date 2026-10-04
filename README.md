DIGITAL CIRCUIT DESIGNER & SIMULATOR
======================================

C++17 project.

Features:
- NAND, NOR, NOT, AND, OR, XOR
- NAND/NOR-based derived gates
- Half Adder
- Full Adder
- 4-Bit Adder
- 4-Bit Counter
- 1 Hz counter clock simulation
- CSV output
- OOP: abstraction, inheritance, polymorphism, encapsulation, composition

Build:
    g++ -std=c++17 *.cpp -o simulator

Run:
    ./simulator

ADDITIONAL COMBINATIONAL CIRCUITS
----------------------------------
The simulator now also includes:

1. 2:1 Multiplexer (MUX)
   Inputs: I0, I1, Select S
   Output: Y = I0.S' + I1.S

2. 4:2 Encoder
   Inputs: D0, D1, D2, D3 (one-hot input)
   Outputs: Y1, Y0
   Y1 = D2 + D3
   Y0 = D1 + D3

3. 2:4 Decoder
   Inputs: A, B
   Outputs: Y0, Y1, Y2, Y3
   Exactly one output is HIGH for each input combination.

These circuits are implemented as classes derived from Circuit and use
existing Gate and Wire abstractions. They can also be saved to and loaded
from CSV through CircuitStorage.

MAIN MENU
---------
1  Basic Logic Gates
2  Half Adder
3  Full Adder
4  4-Bit Adder
5  4-Bit Counter
6  2:1 Multiplexer (MUX)
7  4:2 Encoder
8  2:4 Decoder
9  Save Circuit to CSV
10 Load Circuit from CSV
0  Exit

BUILD AND RUN
-------------
g++ -std=c++17 *.cpp -o simulator
./simulator
