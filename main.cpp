#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include "Nand.h"
#include "Nor.h"
#include "Not.h"
#include "And.h"
#include "Or.h"
#include "Xor.h"
#include "HalfAdder.h"
#include "FullAdder.h"
#include "FourBitAdder.h"
#include "FourBitCounter.h"
#include "Mux.h"
#include "Encoder.h"
#include "Decoder.h"
#include "ALU.h"
#include "CSVOutput.h"
#include "CircuitStorage.h"
#include <limits>
#include "BooleanMinimizer.h"
#include "CustomCircuit.h"
#include <cctype>

using namespace std;
vector<int> get4BitInput(string name)
{
    string input;

    while (true)
    {
        cout << "Enter 4-bit input " << name << " (only 0 or 1): ";
        cin >> input;

        if (input.length() != 4)
        {
            cout << "Invalid input! Enter exactly 4 bits.\n";
            continue;
        }

        bool valid = true;

        for (char c : input)
        {
            if (c != '0' && c != '1')
            {
                valid = false;
                break;
            }
        }

        if (!valid)
        {
            cout << "Invalid input! Use only 0 and 1.\n";
            continue;
        }

        vector<int> bits;

        for (char c : input)
            bits.push_back(c - '0');

        return bits;
    }
}
int getBinaryInput(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value && (value == 0 || value == 1)) {
            return value; // Valid binary input
        }
        
        // Handle invalid input (letters, invalid numbers, etc.)
        cout << "Invalid input! Please enter only 0 or 1.\n";
        cin.clear(); // Clear the error flag on cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    }
}

void line() { cout << "============================================\n"; }

void testBasicGates() {
    cout<<"\nTell a specific gate in these to test:\n";
    cout<<" 1.NAND\n";
    cout<<" 2.NOR\n";
    cout<<" 3.AND\n";
    cout<<" 4.OR\n";
    cout<<" 5.XOR\n";
    cout<<" 6.All at once\n";
    cout<<" 0. Back to main menu\n";
    int x=0;
    cin>>x;
    NAND nandGate; NOR norGate; NOT notGate; AND andGate; OR orGate; XOR xorGate;
    if(x==1){
        
        int y=0;
        cout<<" Selected NAND Gate\n";
        line();
        while(1){
            
            cout<<" 1.To Test\n 2.Exit\n 0. Back to main menu\n";
            cin>>y;
            if(y==1){
                cout<<"  Testing NAND Gate:\n";
                
                int a = getBinaryInput("Enter a: ");
                int b = getBinaryInput("Enter b: ");
                

                cout << "\n--- NAND Gate Circuit ---\n\n";
                cout << "         +-------\\          \n";
                cout << "  " << a << " -----|        \\         \n";
                cout << "         |  NAND   )O----- " << nandGate.evaluate(a,b) << "\n";
                cout << "  " << b << " -----|        /         \n";
                cout << "         +-------/          \n\n";

                cout<<"Output: "<<nandGate.evaluate(a,b)<<'\n';



            }
            else{
                cout<<"Exiting\n";
                break;
            }
        }
        

    }
    else if(x==2){
        
        int y=0;
        cout<<"Selected NOR Gate\n";
        line();
        while(1){
            
            cout<<" 1.To Test\n 2.Exit\n 0. Back to main menu\n";
            cin>>y;
            if(y==1){
                cout<<"   Testing NOR Gate:\n";
                
                int a = getBinaryInput("Enter a: ");
                
                int b = getBinaryInput("Enter b: ");
                
                

                cout << "\n--- NOR Gate ---\n";
                cout << "         \\--------\\          \n";
                cout << "  " << a << " -----| )        \\         \n";
                cout << "         |  )  NOR   )O----- " << norGate.evaluate(a,b) << "\n";
                cout << "  " << b << " -----| )        /         \n";
                cout << "         /--------/          \n";

                cout<<"Output: "<<norGate.evaluate(a,b)<<'\n';



            }
            else{
                cout<<"Exiting\n";
                break;
            }
        }

    }
    else if(x==3){
        
        int y=0;
        cout<<"Selected AND Gate\n";
        line();
        while(1){
            
            cout<<" 1.To Test\n 2.Exit\n 0. Back to main menu\n";
            cin>>y;
            if(y==1){
                cout<<"    Testing AND gate:\n";
                
                
                int a = getBinaryInput("Enter a: ");
                
                int b = getBinaryInput("Enter b: ");

                cout << "\n--- AND Gate ---\n";
                cout << "         +-------\\          \n";
                cout << "  " << a << " -----|        \\         \n";
                cout << "         |   AND   )------ " << andGate.evaluate(a,b) << "\n";
                cout << "  " << b << " -----|        /         \n";
                cout << "         +-------/          \n";

                cout<<"Output: "<<andGate.evaluate(a,b)<<'\n';



            }
            else{
                cout<<"Exiting\n";
                break;
            }
        }

    }
    else if(x==4){
        
        int y=0;
        cout<<"Selected OR Gate\n";
        while(1){
            cout<<" 1.To Test\n 2.Exit\n 0. Back to main menu\n";
            cin>>y;
            if(y==1){
                cout<<"    Testing OR gate:\n";
                
                int a = getBinaryInput("Enter a: ");
                int b = getBinaryInput("Enter b: ");
                

                cout << "\n--- OR Gate ---\n";
                cout << "         \\--------\\          \n";
                cout << "  " << a << " -----| )        \\         \n";
                cout << "         |  )  OR    )------ " << orGate.evaluate(a,b) << "\n";
                cout << "  " << b << " -----| )        /         \n";
                cout << "         /--------/          \n";

                cout<<"Output: "<<orGate.evaluate(a,b)<<'\n';



            }
            else{
                cout<<"Exiting\n";
                break;
            }
        }

    }
    else if(x==5){
        
        int y=0;
        cout<<"Selected XOR Gate\n";
        line();
        while(1){
            cout<<" 1.To Test\n 2.Exit\n 0. Back to main menu\n";
            cin>>y;
            if(y==1){
                cout<<"    Testing XOR Gate:\n";
                
                int a = getBinaryInput("Enter a: ");
                int b = getBinaryInput("Enter b: ");
                

                cout << "\n--- XOR Gate ---\n";
                cout << "           \\--------\\          \n";
                cout << "  " << a << " ---)---| )        \\         \n";
                cout << "           |  )  XOR    )------ " << xorGate.evaluate(a,b) << "\n";
                cout << "  " << b << " ---)---| )        /         \n";
                cout << "           /--------/          \n";

                cout<<"Output: "<<xorGate.evaluate(a,b)<<'\n';



            }
            else{
                cout<<"Exiting\n";
                break;
            }
        }

    }
    else if(x==6){
    line(); cout << "             BASIC LOGIC GATES\n"; line();
    
    cout << "\nA B | NAND NOR AND OR XOR\n-------------------------\n";
    for (int a=0;a<=1;++a) for (int b=0;b<=1;++b)
        cout << a << " " << b << " |  "
             << nandGate.evaluate(a,b) << "    "
             << norGate.evaluate(a,b) << "   "
             << andGate.evaluate(a,b) << "   "
             << orGate.evaluate(a,b) << "   "
             << xorGate.evaluate(a,b) << "\n";
    cout << "\nNOT Gate\nA | NOT\n--------\n";
    cout << "0 | " << notGate.evaluate(0) << "\n";
    cout << "1 | " << notGate.evaluate(1) << "\n\n";
    }
    else if(x==0){
        return ;
    }
    else{
        cout<<"Please enter proper number.\n";
        testBasicGates();
    }
}

void testHalfAdder() {
    int x;
    cout<<"Testing Half Adder.\n";
    line();
    cout<<"1.Testing specific values\n";
    cout<<"2.Overall Testing\n";
    cout<<"0.Back to main menu\n";
    cin>>x;
    if(x==1){

    while(1){
        int y=0;
        
        cout<<" 1.To Test\n";
        cout<<" 2.Exit\n 0. Back to main menu\n";
        cin>>y;
        if(y==1){
        cout<<"Testing for Specific Values:\n";
        int a = getBinaryInput("Enter a: ");
        int b = getBinaryInput("Enter b: ");
        HalfAdder h;
        auto r=h.simulate({a,b});
        
        cout << "         +-------------------------+\n";
        cout << "  A (" << a << ") --|                         |\n";
        cout << "         |                         |-- SUM   (" << r.getOutputs()[0] << ")\n";
        cout << "         |       HALF ADDER        |\n";
        cout << "         |                         |-- CARRY (" << r.getOutputs()[1]  << ")\n";
        cout << "  B (" << b << ") --|                         |\n";
        cout << "         +-------------------------+\n\n";
        cout<<"Sum: "<<r.getOutputs()[0]<<'\n';
        cout<<"Carry: "<<r.getOutputs()[1]<<'\n';
        }
        else{
            cout<<"Exiting...\n";
            break;
        }

    }
}
else if(x==2){
    
    line(); cout << "                 HALF ADDER\n"; line();
    HalfAdder h;
    cout << "\nA B | SUM CARRY\n---------------\n";
    for (int a=0;a<=1;++a) for (int b=0;b<=1;++b) {
        auto r=h.simulate({a,b});
        cout << a << " " << b << " |  "
             << r.getOutputs()[0] << "    " << r.getOutputs()[1] << "\n";
    }
    cout << "\n";
}
}

void testFullAdder() {
    int x;
    line();
    cout<<"Testing Full Adder.\n";
    cout<<"1.Testing specific values\n";
    cout<<"2.Overall Testing\n";
    cout<<"0.Back to main menu\n";
    cin>>x;
    if(x==1){
        while(1){
        int y=0;
        
        cout<<" 1.To Test\n";
        cout<<" 2.Exit\n";
        cin>>y;
        if(y==1){
        cout<<"Testing for Specific Values:\n";
        int a = getBinaryInput("Enter a: ");
        int b = getBinaryInput("Enter b: ");
        int c=getBinaryInput("Enter Cin: ");
        FullAdder f;
        auto r=f.simulate({a,b,c});
        
        cout << "         +-------------------------+\n";
    cout << "  A (" << a << ") --|                         |\n";
    cout << "         |                         |-- SUM  (" << r.getOutputs()[0] << ")\n";
    cout << "  B (" << b << ") --|       FULL ADDER        |\n";
    cout << "         |                         |-- COUT (" << r.getOutputs()[1] << ")\n";
    cout << "Cin (" << c << ") --|                         |\n";
    cout << "         +-------------------------+\n\n";
    cout<<"Sum: "<<r.getOutputs()[0]<<'\n';
    cout<<"Carry: "<<r.getOutputs()[1]<<'\n';
        }
        else{
            cout<<"Exiting...\n";
            break;
        }

    }


    }
    else if(x==2){
    line(); cout << "                 FULL ADDER\n"; line();
    FullAdder f;
    cout << "\nA B Cin | SUM CARRY\n------------------\n";
    for (int a=0;a<=1;++a) for (int b=0;b<=1;++b) for (int cin=0;cin<=1;++cin) {
        auto r=f.simulate({a,b,cin});
        cout << a << " " << b << "  " << cin << "   |  "
             << r.getOutputs()[0] << "    " << r.getOutputs()[1] << "\n";
    }
    cout << "\n";
}
}

void testFourBitAdder() {
    line();
    cout<<"Selected Four Bit Adder.\n";
    cout<<" 1.Test specific Values.\n";
    cout<<" 2.Given example.\n";
    cout<<"0.Back to main menu\n";
    int x=0;
    cin>>x;
    if(x==1){
    FourBitAdder adder;
    vector<int> a = get4BitInput("Enter a: ");
    vector<int> b = get4BitInput("Enter b: ");
    int c=getBinaryInput("Enter Cin: ");

    vector<int> inputs =
    {
        a[0], a[1], a[2], a[3],     // A3 A2 A1 A0
        b[0], b[1], b[2], b[3]      // B3 B2 B1 B0
        
    };

    adder.displayCircuit(inputs, c);
}
else if(x==2){
    FourBitAdder adder;
    
    cout<<"A: 1101(13)"<<'\n';
    cout<<"B: 1000(8)"<<'\n';
    cout<<"Cin: 0"<<'\n';

    vector<int> inputs =
    {
        1, 1, 0, 1,     // A3 A2 A1 A0
        1, 0, 0, 0      // B3 B2 B1 B0
        
    };
    adder.displayCircuit(inputs, 0);

}
}

void testCounter() {
    FourBitCounter counter;

    cout << "\n+---------------------------------------+\n";
    cout << "|         4-BIT BINARY COUNTER          |\n";
    cout << "+---------------------------------------+\n";

    cout << "\nStarting counter...\n\n";

    for (int clk = 0; clk < 16; ++clk)
    {
        vector<int> state = counter.getState();

        cout << "  CLK   (" << clk << ") --->|                               |\n";
        cout << "  RESET (0) --->|   +-------+-------+-------+-------+   |\n";
        cout << "             |   | Q3    | Q2    | Q1    | Q0    |   |\n";
        cout << "             |   |  "
             << state[3] << "    |  "
             << state[2] << "    |  "
             << state[1] << "    |  "
             << state[0] << "    |   |\n";
        cout << "             |   +-------+-------+-------+-------+   |\n";

        cout << "             +---------------------------------------+\n";

        cout << "                 OUTPUT: "
             << state[0]
             << state[1]
             << state[2]
             << state[3];

        int decimal =
            state[0] * 1 +
            state[1] * 2 +
            state[2] * 4 +
            state[3] * 8;

        cout << " (" << decimal << ")\n";

        cout << "\n-----------------------------------------------\n";

        // Wait for 1 second before next clock pulse
        this_thread::sleep_for(chrono::seconds(1));

        counter.tick();
    }
}


// Helper: read a submenu choice safely.
int getSubmenuChoice(const string& prompt, int minValue, int maxValue)
{
    int choice;
    while (true)
    {
        cout << prompt;
        if (cin >> choice && choice >= minValue && choice <= maxValue)
            return choice;

        cout << "Invalid choice. Enter a number from "
             << minValue << " to " << maxValue << ".\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Convert an integer in [0, 15] to a vector ordered MSB to LSB.
vector<int> numberToBits4(int value)
{
    return {
        (value >> 3) & 1,
        (value >> 2) & 1,
        (value >> 1) & 1,
        value & 1
    };
}

void testMUX()
{
    MUX mux;
    line();
    cout << "                 2:1 MULTIPLEXER\n";
    line();
    cout << "1. Test specific values\n";
    cout << "2. Overall testing (truth table)\n";
    cout << "0. Back to main menu\n";

    int choice = getSubmenuChoice("Enter choice: ", 0, 2);
    if (choice == 0) return;

    if (choice == 1)
    {
        do
        {
            int i0 = getBinaryInput("Enter I0: ");
            int i1 = getBinaryInput("Enter I1: ");
            int sel = getBinaryInput("Enter Select S: ");
            SimulationResult result = mux.simulate({i0, i1, sel});

            cout << "\n         +-------------------------+\n";
            cout << " I0(" << i0 << ") --|                         |\n";
            cout << " I1(" << i1 << ") --|         2:1 MUX         |-- Y(";
            cout << result.getOutputs()[0] << ")\n";
            cout << " S (" << sel << ") --|                         |\n";
            cout << "         +-------------------------+\n";
            cout << "Selected input: I" << sel
                 << ", output Y = " << result.getOutputs()[0] << "\n\n";

            int again = getSubmenuChoice("1. Test again  0. Back: ", 0, 1);
            if (again == 0) break;
        } while (true);
    }
    else
    {
        cout << "\nI0 I1 S | Y\n";
        cout << "--------+--\n";
        for (int i0 = 0; i0 <= 1; ++i0)
            for (int i1 = 0; i1 <= 1; ++i1)
                for (int sel = 0; sel <= 1; ++sel)
            {
                SimulationResult result = mux.simulate({i0, i1, sel});
                cout << " " << i0 << "  " << i1 << " " << sel
                     << " | " << result.getOutputs()[0] << "\n";
            }
    }
}

void testEncoder()
{
    Encoder encoder;
    line();
    cout << "                   4:2 ENCODER\n";
    line();
    cout << "Inputs are one-hot: exactly one of D0-D3 must be 1.\n";
    cout << "1. Test specific values\n";
    cout << "2. Overall testing (valid truth table)\n";
    cout << "0. Back to main menu\n";

    int choice = getSubmenuChoice("Enter choice: ", 0, 2);
    if (choice == 0) return;

    if (choice == 1)
    {
        do
        {
            vector<int> d(4);
            d[3] = getBinaryInput("Enter D3: ");
            d[2] = getBinaryInput("Enter D2: ");
            d[1] = getBinaryInput("Enter D1: ");
            d[0] = getBinaryInput("Enter D0: ");

            int count = d[0] + d[1] + d[2] + d[3];
            if (count != 1)
            {
                cout << "Invalid encoder input: exactly one input must be 1.\n";
            }
            else
            {
                SimulationResult result = encoder.simulate(d);
                cout << "        +-------------------------+\n";
    cout << " I0 (" << d[3] << ") --|                         |\n";
    cout << " I1 (" << d[2] << ") --|                         |-- Y0 (" << result.getOutputs()[0] << ")\n";
    cout << " I2 (" << d[1] << ") --|       4:2 ENCODER       |\n";
    cout << " I3 (" << d[0] << ") --|                         |-- Y1 (" << result.getOutputs()[1] << ")\n";
    cout << "        |                         |\n";
    cout << "        +-------------------------+\n\n";
    cout << "Y0: " << result.getOutputs()[0] << '\n';
    cout << "Y1: " << result.getOutputs()[1] << '\n';
                cout << "\nD3 D2 D1 D0 = "
                     << d[3] << d[2] << d[1] << d[0] << "\n";
                cout << "Y1 Y0 = " << result.getOutputs()[0]
                     << result.getOutputs()[1] << "\n";
            }

            int again = getSubmenuChoice("1. Test again  0. Back: ", 0, 1);
            if (again == 0) break;
        } while (true);
    }
    else
    {
        cout << "\nD3 D2 D1 D0 | Y1 Y0\n";
        cout << "------------+------\n";
        for (int active = 0; active < 4; ++active)
        {
            // active=0 -> D0, active=1 -> D1, etc.
            vector<int> d(4, 0);
            d[active] = 1;
            SimulationResult result = encoder.simulate(d);
            cout << " " << d[3] << "  " << d[2] << "  "
                 << d[1] << "  " << d[0] << "   |  "
                 << result.getOutputs()[0]
                 << result.getOutputs()[1] << "\n";
        }
        cout << "All four valid one-hot inputs tested.\n";
    }
}

void testDecoder()
{
    Decoder decoder;
    line();
    cout << "                   2:4 DECODER\n";
    line();
    cout << "1. Test specific values\n";
    cout << "2. Overall testing (truth table)\n";
    cout << "0. Back to main menu\n";

    int choice = getSubmenuChoice("Enter choice: ", 0, 2);
    if (choice == 0) return;

    if (choice == 1)
    {
        do
        {
            int a = getBinaryInput("Enter A1: ");
            int b = getBinaryInput("Enter A0: ");
            SimulationResult result = decoder.simulate({a, b});
            const auto& out = result.getOutputs(); // Y0, Y1, Y2, Y3

            cout << "\n         +-------------------------+\n";
            cout << " A1(" << a << ") --|                         |-- Y3 (" << out[3] << ")\n";
            cout << "         |        2:4 DECODER     |-- Y2 (" << out[2] << ")\n";
            cout << " A0(" << b << ") --|                         |-- Y1 (" << out[1] << ")\n";
            cout << "         +-------------------------+-- Y0 (" << out[0] << ")\n";
            cout << "Output Y3 Y2 Y1 Y0 = "
                 << out[3] << out[2] << out[1] << out[0] << "\n";

            int again = getSubmenuChoice("1. Test again  0. Back: ", 0, 1);
            if (again == 0) break;
        } while (true);
    }
    else
    {
        cout << "\nA1 A0 | Y3 Y2 Y1 Y0\n";
        cout << "------+------------\n";
        for (int a = 0; a <= 1; ++a)
            for (int b = 0; b <= 1; ++b)
            {
                SimulationResult result = decoder.simulate({a, b});
                const auto& out = result.getOutputs();
                cout << " " << a << "  " << b << "  |  "
                     << out[3] << "  " << out[2] << "  "
                     << out[1] << "  " << out[0] << "\n";
            }
    }
}

void testALU()
{
    ALU circuit;
    line();
    cout << "                    4-BIT ALU\n";
    line();
    cout << "Select codes: 00=ADD, 01=SUB, 10=AND, 11=XOR\n";
    cout << "1. Test specific values\n";
    cout << "2. Overall testing (exhaustive 1024 combinations)\n";
    cout << "0. Back to main menu\n";

    int choice = getSubmenuChoice("Enter choice: ", 0, 2);
    if (choice == 0) return;

    if (choice == 1)
    {
        do
        {
            vector<int> a = get4BitInput("A (A3 A2 A1 A0)");
            vector<int> b = get4BitInput("B (B3 B2 B1 B0)");
            int s1 = getBinaryInput("Enter select S1: ");
            int s0 = getBinaryInput("Enter select S0: ");

            vector<int> inputs = {a[0], a[1], a[2], a[3],
                                  b[0], b[1], b[2], b[3], s1, s0};
            try
            {
                SimulationResult result = circuit.simulate(inputs);
                const auto& out = result.getOutputs(); // R3 R2 R1 R0 Flag
                int operation = (s1 << 1) | s0;
                const char* names[] = {"Addition", "Subtraction", "Bitwise AND", "Bitwise XOR"};

               cout << "\n        +----------------------------------------+\n";
    cout << "        | A = " << a[0] << a[1] << a[2] << a[3] 
         << "  |  B = " << b[0] << b[1] << b[2] << b[3] << "      |\n";
    cout << "        |              4-BIT ALU                 |\n";
    cout << "        | OP = " << s1 << s0 << " (" << names[operation] << ")                   |\n";
    cout << "        +----------------------------------------+\n";
    cout << "        | Result (R3 R2 R1 R0) = " 
         << out[0] << out[1] << out[2] << out[3] << "       |\n";
    cout << "        +----------------------------------------+\n\n";
                if (operation == 0)
                    cout << "Carry-out = " << out[4] << "\n";
                else if (operation == 1)
                    cout << "Borrow = " << out[4] << "\n";
                else
                    cout << "Flag = 0 (unused for logical operations)\n";
            }
            catch (const exception& e)
            {
                cout << "ALU error: " << e.what() << "\n";
            }

            int again = getSubmenuChoice("1. Test again  0. Back: ", 0, 1);
            if (again == 0) break;
        } while (true);
    }
    else
    {
        // Exhaustively compare every ALU operation and operand pair
        // against an independent arithmetic/bitwise reference result.
        int total = 0;
        int passed = 0;
        for (int av = 0; av < 16; ++av)
            for (int bv = 0; bv < 16; ++bv)
                for (int op = 0; op < 4; ++op)
                {
                    vector<int> a = numberToBits4(av);
                    vector<int> b = numberToBits4(bv);
                    vector<int> inputs = {a[0], a[1], a[2], a[3],
                                          b[0], b[1], b[2], b[3],
                                          (op >> 1) & 1, op & 1};
                    SimulationResult result = circuit.simulate(inputs);
                    const auto& out = result.getOutputs();

                    int expectedValue = 0;
                    int expectedFlag = 0;
                    if (op == 0)
                    {
                        expectedValue = (av + bv) & 0xF;
                        expectedFlag = (av + bv) > 15 ? 1 : 0;
                    }
                    else if (op == 1)
                    {
                        expectedValue = (av - bv) & 0xF;
                        expectedFlag = av < bv ? 1 : 0;
                    }
                    else if (op == 2)
                        expectedValue = av & bv;
                    else
                        expectedValue = av ^ bv;

                    int actualValue = (out[0] << 3) | (out[1] << 2)
                                    | (out[2] << 1) | out[3];
                    ++total;
                    if (actualValue == expectedValue && out[4] == expectedFlag)
                        ++passed;
                    else
                        cout << "Mismatch: A=" << av << ", B=" << bv
                             << ", opcode=" << op << "\n";
                }

        cout << "\nALU exhaustive test completed.\n";
        cout << "Cases passed: " << passed << " / " << total << "\n";
        if (passed == total)
            cout << "PASS: all ALU combinations match expected results.\n";
        else
            cout << "FAIL: one or more ALU combinations did not match.\n";
    }
}

void saveCircuitMenu()
{
    int choice;

    cout << "\n============================================\n";
    cout << "              SAVE CIRCUIT\n";
    cout << "============================================\n";
    cout << "  1. Half Adder\n";
    cout << "  2. Full Adder\n";
    cout << "  3. 4-Bit Adder\n";
    cout << "  4. 4-Bit Counter\n";
    cout << "  5. 2:1 MUX\n";
    cout << "  6. 4:2 Encoder\n";
    cout << "  7. 2:4 Decoder\n";
    cout << "  8. 4-Bit ALU\n";
    cout << "  0. Back\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 0)
        return;

    string filename;
    cout << "Enter CSV filename (example: half_adder.csv): ";
    cin >> filename;

    if (choice == 1)
    {
        int a = getBinaryInput("Enter A: ");
        int b = getBinaryInput("Enter B: ");

        HalfAdder circuit;
        SimulationResult result = circuit.simulate({a, b});

        if (CircuitStorage::save(
                filename,
                "HalfAdder",
                result.getInputs(),
                result.getOutputs()))
            cout << "Circuit saved successfully to " << filename << "\n";
        else
            cout << "Could not save circuit.\n";
    }
    else if (choice == 2)
    {
        int a = getBinaryInput("Enter A: ");
        int b = getBinaryInput("Enter B: ");
        int cinValue = getBinaryInput("Enter Cin: ");

        FullAdder circuit;
        SimulationResult result = circuit.simulate({a, b, cinValue});

        if (CircuitStorage::save(
                filename,
                "FullAdder",
                result.getInputs(),
                result.getOutputs()))
            cout << "Circuit saved successfully to " << filename << "\n";
        else
            cout << "Could not save circuit.\n";
    }
    else if (choice == 3)
    {
        FourBitAdder circuit;
        vector<int> a = get4BitInput("A");
        vector<int> b = get4BitInput("B");
        int cinValue = getBinaryInput("Enter Cin: ");

        vector<int> inputs = {
            a[0], a[1], a[2], a[3],
            b[0], b[1], b[2], b[3],
            cinValue
        };

        SimulationResult result = circuit.simulate(inputs);

        if (CircuitStorage::save(
                filename,
                "FourBitAdder",
                result.getInputs(),
                result.getOutputs()))
            cout << "Circuit saved successfully to " << filename << "\n";
        else
            cout << "Could not save circuit.\n";
    }
    else if (choice == 4)
    {
        FourBitCounter circuit;
        vector<int> state = circuit.getState();

        cout << "Current counter state: "
             << state[3] << state[2] << state[1] << state[0] << "\n";
        cout << "How many clock ticks should be applied before saving? ";

        int ticks;
        cin >> ticks;

        if (ticks < 0)
            ticks = 0;

        for (int i = 0; i < ticks; ++i)
            circuit.tick();

        state = circuit.getState();

        if (CircuitStorage::save(
                filename,
                "FourBitCounter",
                {ticks},
                {},
                state))
            cout << "Counter saved successfully to " << filename << "\n";
        else
            cout << "Could not save counter.\n";
    }
    else if (choice == 5)
    {
        MUX circuit;
        int i0 = getBinaryInput("Enter I0: ");
        int i1 = getBinaryInput("Enter I1: ");
        int s = getBinaryInput("Enter Select S: ");
        SimulationResult result = circuit.simulate({i0, i1, s});
        if (CircuitStorage::save(filename, "MUX", result.getInputs(), result.getOutputs()))
            cout << "MUX saved successfully to " << filename << "\n";
        else
            cout << "Could not save MUX.\n";
    }
    else if (choice == 6)
    {
        Encoder circuit;
        vector<int> d(4);
        d[0] = getBinaryInput("Enter D0: ");
        d[1] = getBinaryInput("Enter D1: ");
        d[2] = getBinaryInput("Enter D2: ");
        d[3] = getBinaryInput("Enter D3: ");
        if (d[0] + d[1] + d[2] + d[3] != 1)
        {
            cout << "Exactly one encoder input must be 1. Not saved.\n";
            return;
        }
        SimulationResult result = circuit.simulate(d);
        if (CircuitStorage::save(filename, "Encoder", result.getInputs(), result.getOutputs()))
            cout << "Encoder saved successfully to " << filename << "\n";
        else
            cout << "Could not save Encoder.\n";
    }
    else if (choice == 7)
    {
        Decoder circuit;
        int a = getBinaryInput("Enter A: ");
        int b = getBinaryInput("Enter B: ");
        SimulationResult result = circuit.simulate({a, b});
        if (CircuitStorage::save(filename, "Decoder", result.getInputs(), result.getOutputs()))
            cout << "Decoder saved successfully to " << filename << "\n";
        else
            cout << "Could not save Decoder.\n";
    }
    else if (choice == 8)
    {
        vector<int> a = get4BitInput("A");
        vector<int> b = get4BitInput("B");
        int s1 = getBinaryInput("Enter select S1 (00=ADD, 01=SUB, 10=AND, 11=XOR): ");
        int s0 = getBinaryInput("Enter select S0: ");
        vector<int> inputs = {a[0], a[1], a[2], a[3],
                              b[0], b[1], b[2], b[3], s1, s0};
        ALU circuit;
        try {
            SimulationResult result = circuit.simulate(inputs);
            if (CircuitStorage::save(filename, "ALU", result.getInputs(), result.getOutputs()))
                cout << "4-Bit ALU saved successfully to " << filename << "\n";
            else
                cout << "Could not save 4-Bit ALU.\n";
        } catch (const exception& e) {
            cout << "ALU error: " << e.what() << "\n";
        }
    }
    else
    {
        cout << "Invalid choice.\n";
    }
}

void loadCircuitMenu()
{
    string filename;

    cout << "\n============================================\n";
    cout << "              LOAD CIRCUIT\n";
    cout << "============================================\n";
    cout << "Enter CSV filename: ";
    cin >> filename;

    string circuitType;
    vector<int> inputs;
    vector<int> outputs;
    vector<int> state;

    if (!CircuitStorage::load(
            filename,
            circuitType,
            inputs,
            outputs,
            state))
    {
        cout << "Could not load circuit or invalid CSV file.\n";
        return;
    }

    cout << "Loaded circuit type: " << circuitType << "\n";

    if (circuitType == "HalfAdder")
    {
        if (inputs.size() != 2)
        {
            cout << "Invalid Half Adder file.\n";
            return;
        }

        HalfAdder circuit;
        SimulationResult result = circuit.simulate(inputs);

        cout << "A = " << inputs[0]
             << ", B = " << inputs[1] << "\n";
        cout << "SUM = " << result.getOutputs()[0]
             << ", CARRY = " << result.getOutputs()[1] << "\n";
    }
    else if (circuitType == "FullAdder")
    {
        if (inputs.size() != 3)
        {
            cout << "Invalid Full Adder file.\n";
            return;
        }

        FullAdder circuit;
        SimulationResult result = circuit.simulate(inputs);

        cout << "A = " << inputs[0]
             << ", B = " << inputs[1]
             << ", Cin = " << inputs[2] << "\n";
        cout << "SUM = " << result.getOutputs()[0]
             << ", COUT = " << result.getOutputs()[1] << "\n";
    }
    else if (circuitType == "FourBitAdder")
    {
        if (inputs.size() != 9)
        {
            cout << "Invalid 4-Bit Adder file.\n";
            return;
        }

        FourBitAdder circuit;
        SimulationResult result = circuit.simulate(inputs);

        vector<int> displayInputs(
            inputs.begin(), inputs.begin() + 8);

        circuit.displayCircuit(displayInputs, inputs[8]);

        const auto& loadedOutput = result.getOutputs();
        if (loadedOutput.size() == 5)
        {
            cout << "Loaded result: "
                 << loadedOutput[4]
                 << loadedOutput[0]
                 << loadedOutput[1]
                 << loadedOutput[2]
                 << loadedOutput[3]
                 << "\n";
        }
    }
    else if (circuitType == "FourBitCounter")
    {
        if (state.size() != 4)
        {
            cout << "Invalid 4-Bit Counter file.\n";
            return;
        }

        FourBitCounter circuit;
        circuit.setState(state);

        cout << "Counter restored successfully.\n";
        cout << "Restored state: "
             << state[3] << state[2]
             << state[1] << state[0] << "\n";

        int decimal =
            state[0] * 1 +
            state[1] * 2 +
            state[2] * 4 +
            state[3] * 8;

        cout << "Decimal value: " << decimal << "\n";
    }
    else if (circuitType == "MUX")
    {
        if (inputs.size() != 3)
        {
            cout << "Invalid MUX file.\n";
            return;
        }
        MUX circuit;
        SimulationResult result = circuit.simulate(inputs);
        cout << "I0 = " << inputs[0] << ", I1 = " << inputs[1]
             << ", S = " << inputs[2] << "\n";
        cout << "Y = " << result.getOutputs()[0] << "\n";
    }
    else if (circuitType == "Encoder")
    {
        if (inputs.size() != 4)
        {
            cout << "Invalid Encoder file.\n";
            return;
        }
        Encoder circuit;
        SimulationResult result = circuit.simulate(inputs);
        cout << "D3 D2 D1 D0 = " << inputs[3] << inputs[2] << inputs[1] << inputs[0] << "\n";
        cout << "Y1 Y0 = " << result.getOutputs()[0] << result.getOutputs()[1] << "\n";
    }
    else if (circuitType == "Decoder")
    {
        if (inputs.size() != 2)
        {
            cout << "Invalid Decoder file.\n";
            return;
        }
        Decoder circuit;
        SimulationResult result = circuit.simulate(inputs);
        const auto& out = result.getOutputs();
        cout << "A B = " << inputs[0] << " " << inputs[1] << "\n";
        cout << "Y3 Y2 Y1 Y0 = " << out[3] << out[2] << out[1] << out[0] << "\n";
    }
    else if (circuitType == "ALU")
    {
        if (inputs.size() != 10)
        {
            cout << "Invalid 4-Bit ALU file.\n";
            return;
        }
        ALU circuit;
        try {
            SimulationResult result = circuit.simulate(inputs);
            const auto& out = result.getOutputs();
            int operation = (inputs[8] << 1) | inputs[9];
            const char* operationNames[] = {"Addition", "Subtraction", "Bitwise AND", "Bitwise XOR"};
            cout << "Operation: " << operationNames[operation] << "\n";
            cout << "A = " << inputs[0] << inputs[1] << inputs[2] << inputs[3] << "\n";
            cout << "B = " << inputs[4] << inputs[5] << inputs[6] << inputs[7] << "\n";
            cout << "Result = " << out[0] << out[1] << out[2] << out[3] << "\n";
            if (operation == 0) cout << "Carry-out = " << out[4] << "\n";
            else if (operation == 1) cout << "Borrow = " << out[4] << "\n";
            else cout << "Flag = 0 (not used for logical operations)\n";
        } catch (const exception& e) {
            cout << "Could not simulate saved ALU: " << e.what() << "\n";
        }
    }
    else
    {
        cout << "Unknown circuit type in CSV file.\n";
    }
}
bool isValidVariableName(const string& name) {
    if (name.empty()) return false;
    unsigned char first = static_cast<unsigned char>(name[0]);
    if (!(isalpha(first) || name[0] == '_')) return false;
    for (char ch : name) {
        unsigned char c = static_cast<unsigned char>(ch);
        if (!(isalnum(c) || ch == '_')) return false;
    }
    return true;
}

vector<int> bitsForRow(int row, int numberOfVariables) {
    vector<int> bits;
    bits.reserve(numberOfVariables);
    for (int i = 0; i < numberOfVariables; ++i) {
        int shift = numberOfVariables - 1 - i;
        bits.push_back((row >> shift) & 1);
    }
    return bits;
}

void buildCustomCircuit() {
    cout<<" 1. Build Circuit\n";
    cout<<" 0. Return to Main Menu\n";
    int choice;
    cin>>choice;
    if(choice==1){
    cout << "\n========== BUILD YOUR OWN CIRCUIT ==========\n";
    cout << "This first version supports 1 to 6 inputs and one output (Y).\n";

    int numberOfVariables = 0;
    while (true) {
        cout << "Enter number of inputs (1-6): ";
        if (cin >> numberOfVariables && numberOfVariables >= 1 && numberOfVariables <= 6) {
            break;
        }
        cout << "Invalid input. Enter an integer from 1 to 6.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<string> variableNames;
    for (int i = 0; i < numberOfVariables; ++i) {
        while (true) {
            string name;
            cout << "Enter name for input " << (i + 1)
                 << " (letters, digits, underscore; first character cannot be a digit): ";
            cin >> name;
            bool duplicate = false;
            for (const string& existing : variableNames) {
                if (existing == name) duplicate = true;
            }
            if (!isValidVariableName(name)) {
                cout << "Invalid variable name. Try again.\n";
            } else if (duplicate) {
                cout << "That variable name is already used. Choose a unique name.\n";
            } else {
                variableNames.push_back(name);
                break;
            }
        }
    }

    const int rowCount = 1 << numberOfVariables;
    vector<int> outputValues(rowCount, 0);
    cout << "\nEnter the output Y for each generated input combination.\n";
    cout << "The first variable is the leftmost bit.\n\n";

    for (int row = 0; row < rowCount; ++row) {
        vector<int> bits = bitsForRow(row, numberOfVariables);
        cout << "Row " << row << ": ";
        for (int i = 0; i < numberOfVariables; ++i) {
            cout << variableNames[i] << '=' << bits[i] << ' ';
        }
        outputValues[row] = getBinaryInput("| Enter Y (0 or 1): ");
    }

    try {
        const string canonical = BooleanMinimizer::canonicalSOP(variableNames, outputValues);
        const vector<Implicant> minimizedTerms =
            BooleanMinimizer::minimizeSOP(variableNames, outputValues);
        const string minimized =
            BooleanMinimizer::minimizedSOP(variableNames, minimizedTerms);

        cout << "\n========== BOOLEAN EXPRESSIONS ==========\n";
        cout << "Notation: ! means NOT, * means AND, + means OR.\n";
        cout << "Canonical SOP: Y = " << canonical << '\n';
        cout << "Minimized SOP: Y = " << minimized << '\n';
        cout << "=========================================\n";

        CustomCircuit circuit("User-defined circuit", variableNames, minimizedTerms);
        circuit.printGateNetwork(cout);

        int incorrectRows = 0;
        for (int row = 0; row < rowCount; ++row) {
            vector<int> bits = bitsForRow(row, numberOfVariables);
            SimulationResult result = circuit.simulate(bits);
            if (result.getOutputs().empty() || result.getOutputs()[0] != outputValues[row]) {
                ++incorrectRows;
                cout << "Mismatch at row " << row << ". Expected " << outputValues[row];
                if (!result.getOutputs().empty()) cout << ", got " << result.getOutputs()[0];
                cout << ".\n";
            }
        }

        cout << "\n========== AUTOMATIC VERIFICATION ==========\n";
        cout << "Truth-table rows tested: " << rowCount << '\n';
        cout << "Incorrect outputs: " << incorrectRows << '\n';
        if (incorrectRows == 0) {
            cout << "Result: CIRCUIT VERIFIED SUCCESSFULLY\n";
        } else {
            cout << "Result: VERIFICATION FAILED\n";
        }
        cout << "============================================\n";

        while (true) {
            cout << "\nEnter an input bit string to test (e.g. 101), or q to return to the menu: ";
            string entered;
            cin >> entered;
            if (entered == "q" || entered == "Q") break;
            if (entered.size() != static_cast<size_t>(numberOfVariables)) {
                cout << "Please enter exactly " << numberOfVariables << " bits.\n";
                continue;
            }
            bool valid = true;
            vector<int> bits;
            for (char ch : entered) {
                if (ch != '0' && ch != '1') {
                    valid = false;
                    break;
                }
                bits.push_back(ch - '0');
            }
            if (!valid) {
                cout << "Only 0 and 1 are allowed.\n";
                continue;
            }
            SimulationResult result = circuit.simulate(bits);
            cout << "Inputs: ";
            for (int i = 0; i < numberOfVariables; ++i) {
                cout << variableNames[i] << '=' << bits[i] << ' ';
            }
            cout << " => Y = " << result.getOutputs()[0] << '\n';
        }
    } catch (const exception& error) {
        cout << "Could not build the custom circuit: " << error.what() << '\n';
    }
}
}

void showMenu() {
    cout << "\n============================================\n";
    cout << "       DIGITAL CIRCUIT SIMULATOR\n";
    cout << "============================================\n";
    cout << "  1. Basic Logic Gates\n";
    cout << "  2. Half Adder\n";
    cout << "  3. Full Adder\n";
    cout << "  4. 4-Bit Adder\n";
    cout << "  5. 4-Bit Counter\n";
    cout << "  6. 2:1 Multiplexer (MUX)\n";
    cout << "  7. 4:2 Encoder\n";
    cout << "  8. 2:4 Decoder\n";
    cout << "  9. 4-Bit ALU\n";
    cout << " 10. Save Circuit to CSV\n";
    cout << " 11. Load Circuit from CSV\n";
    cout << " 12. Build Custom Circuit\n";
    cout << "  0. Exit\n";
    cout << "============================================\n";
    cout << "\nEnter choice: ";
}

int main() {
    int choice;
    do {
        showMenu();
        if (!(cin >> choice)) {
            cin.clear(); cin.ignore(10000, '\n');
            cout << "\nInvalid input. Please enter a number.\n";
            continue;
        }
        cout << "\n";
        switch(choice) {
            case 1: testBasicGates(); break;
            case 2: testHalfAdder(); break;
            case 3: testFullAdder(); break;
            case 4: testFourBitAdder(); break;
            case 5: testCounter(); break;
            case 6: testMUX(); break;
            case 7: testEncoder(); break;
            case 8: testDecoder(); break;
            case 9: testALU(); break;
            case 10: saveCircuitMenu(); break;
            case 11: loadCircuitMenu(); break;
            case 12: buildCustomCircuit(); break;
            case 0: cout << "Exiting simulator...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while(choice != 0);
    return 0;
}
