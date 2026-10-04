DIGITAL CIRCUIT DESIGNER & SIMULATOR
======================================

C++17 project.

TEAM MEMBERS
------------
1. Vaibhav - Circuit Design & C++ Implementation
2. Rahul - Logic Gate & Adder Implementation
3. Rohit - Counter & Combinational Circuits
4. Bhargav - Testing, CSV Storage & Documentation


FEATURES
--------
- NAND, NOR, NOT, AND, OR, XOR
- NAND/NOR-based derived gates
- Half Adder
- Full Adder
- 4-Bit Adder
- 4-Bit Counter
- 1 Hz counter clock simulation
- CSV output
- Circuit save/load using CSV
- OOP: abstraction, inheritance, polymorphism, encapsulation, composition


ADDITIONAL COMBINATIONAL CIRCUITS
----------------------------------

The simulator also includes:

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

These circuits are implemented as classes derived from Circuit
and use existing Gate and Wire abstractions.

Circuits can also be saved to and loaded from CSV through
CircuitStorage.


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


OOP CONCEPTS USED
-----------------

- Abstraction
- Encapsulation
- Inheritance
- Polymorphism
- Composition
- Classes and Objects
- Modular Circuit Design


BUILD AND RUN
-------------

Compile:

    g++ -std=c++17 *.cpp -o simulator

Run:

    ./simulator


PROJECT OBJECTIVE
-----------------

The objective of this project is to design and simulate digital
circuits using C++ and object-oriented programming principles.

Basic gates are constructed using NAND/NOR gates, and these
building blocks are combined to implement more complex circuits
such as adders, counters, multiplexers, encoders, and decoders.

The simulator accepts appropriate inputs, performs the required
logic operations, and generates formatted outputs to demonstrate
the working of each circuit.
