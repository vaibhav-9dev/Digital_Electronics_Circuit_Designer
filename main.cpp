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
#include "CSVOutput.h"
#include "CircuitStorage.h"
#include <limits>

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
    int x=0;
    cin>>x;
    NAND nandGate; NOR norGate; NOT notGate; AND andGate; OR orGate; XOR xorGate;
    if(x==1){
        
        int y=0;
        cout<<" Selected NAND Gate\n";
        line();
        while(1){
            
            cout<<" 1.To Test\n 2.Exit\n";
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
            
            cout<<" 1.To Test\n 2.Exit\n";
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
            
            cout<<" 1.To Test\n 2.Exit\n";
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
            cout<<" 1.To Test\n 2.Exit\n";
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
            cout<<" 1.To Test\n 2.Exit\n";
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


void testMUX()
{
    MUX mux;
    cout << "\n============================================\n";
    cout << "              2:1 MULTIPLEXER\n";
    cout << "============================================\n";
    cout << "Inputs: I0, I1, Select(S)\n";
    cout << "Output: Y = I0.S' + I1.S\n\n";

    int i0 = getBinaryInput("Enter I0: ");
    int i1 = getBinaryInput("Enter I1: ");
    int s  = getBinaryInput("Enter Select S: ");

    SimulationResult r = mux.simulate({i0, i1, s});
    cout << "\nI0 = " << i0 << ", I1 = " << i1 << ", S = " << s << "\n";
    cout << "MUX OUTPUT Y = " << r.getOutputs()[0] << "\n";

    cout << "\nTruth table:\n";
    cout << "I0 I1 S | Y\n";
    cout << "0  0  0 | 0\n";
    cout << "0  0  1 | 0\n";
    cout << "0  1  0 | 0\n";
    cout << "0  1  1 | 1\n";
    cout << "1  0  0 | 1\n";
    cout << "1  0  1 | 0\n";
    cout << "1  1  0 | 1\n";
    cout << "1  1  1 | 1\n";
}

void testEncoder()
{
    Encoder encoder;
    cout << "\n============================================\n";
    cout << "                4:2 ENCODER\n";
    cout << "============================================\n";
    cout << "Enter one-hot inputs D3 D2 D1 D0.\n";
    cout << "Exactly one input must be 1.\n\n";

    vector<int> d(4);
    d[0] = getBinaryInput("Enter D0: ");
    d[1] = getBinaryInput("Enter D1: ");
    d[2] = getBinaryInput("Enter D2: ");
    d[3] = getBinaryInput("Enter D3: ");

    int count = d[0] + d[1] + d[2] + d[3];
    if (count != 1)
    {
        cout << "Invalid encoder input: exactly one input must be 1.\n";
        return;
    }

    SimulationResult r = encoder.simulate(d);
    cout << "\nD3 D2 D1 D0 = " << d[3] << d[2] << d[1] << d[0] << "\n";
    cout << "Y1 Y0 = " << r.getOutputs()[0] << r.getOutputs()[1] << "\n";
}

void testDecoder()
{
    Decoder decoder;
    cout << "\n============================================\n";
    cout << "                2:4 DECODER\n";
    cout << "============================================\n";

    int a = getBinaryInput("Enter A: ");
    int b = getBinaryInput("Enter B: ");

    SimulationResult r = decoder.simulate({a, b});
    const auto& out = r.getOutputs();

    cout << "\nA B | Y3 Y2 Y1 Y0\n";
    cout << a << " " << b << " | "
         << out[3] << "  " << out[2] << "  "
         << out[1] << "  " << out[0] << "\n";

    cout << "\nDecoder truth table:\n";
    cout << "A B | Y3 Y2 Y1 Y0\n";
    cout << "0 0 | 0  0  0  1\n";
    cout << "0 1 | 0  0  1  0\n";
    cout << "1 0 | 0  1  0  0\n";
    cout << "1 1 | 1  0  0  0\n";
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
    else
    {
        cout << "Unknown circuit type in CSV file.\n";
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
    cout << "  9. Save Circuit to CSV\n";
    cout << " 10. Load Circuit from CSV\n";
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
            case 9: saveCircuitMenu(); break;
            case 10: loadCircuitMenu(); break;
            case 0: cout << "Exiting simulator...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while(choice != 0);
    return 0;
}
