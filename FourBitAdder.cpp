#include "FourBitAdder.h"
#include <iostream>
#include <iomanip>

using namespace std;

FourBitAdder::FourBitAdder()
    : Circuit("4-Bit Ripple Carry Adder")
{
}

SimulationResult FourBitAdder::simulate(
    const std::vector<int>& inputs
)
{
    // Inputs:
    // A3 A2 A1 A0 B3 B2 B1 B0 Cin
    //
    // Internally we process from LSB to MSB.

    int carry = inputs[8];

    vector<int> sum(4);

    for (int i = 0; i < 4; ++i)
    {
        SimulationResult result =
            fullAdders[i].simulate(
                {
                    inputs[3 - i],      // A bit
                    inputs[7 - i],      // B bit
                    carry
                }
            );

        sum[3 - i] =
            result.getOutputs()[0];

        carry =
            result.getOutputs()[1];
    }

    // S3 S2 S1 S0 C4
    vector<int> outputs = sum;

    outputs.push_back(carry);

    return SimulationResult(
        inputs,
        outputs
    );
}


// ============================================================
// Display Ripple Carry Adder
// ============================================================

void FourBitAdder::displayCircuit(
    const std::vector<int>& inputs,
    int cin
) const
{
    // --------------------------------------------------------
    // Calculate the circuit result
    // --------------------------------------------------------

    int a3 = inputs[0];
    int a2 = inputs[1];
    int a1 = inputs[2];
    int a0 = inputs[3];

    int b3 = inputs[4];
    int b2 = inputs[5];
    int b1 = inputs[6];
    int b0 = inputs[7];

    // Carry values
    int c0 = cin;
    int c1, c2, c3, c4;

    int s0, s1, s2, s3;

    // FA0
    {
        int sum =
            (a0 ^ b0 ^ c0);

        c1 =
            (a0 & b0) |
            (c0 & (a0 ^ b0));

        s0 = sum;
    }

    // FA1
    {
        int sum =
            (a1 ^ b1 ^ c1);

        c2 =
            (a1 & b1) |
            (c1 & (a1 ^ b1));

        s1 = sum;
    }

    // FA2
    {
        int sum =
            (a2 ^ b2 ^ c2);

        c3 =
            (a2 & b2) |
            (c2 & (a2 ^ b2));

        s2 = sum;
    }

    // FA3
    {
        int sum =
            (a3 ^ b3 ^ c3);

        c4 =
            (a3 & b3) |
            (c3 & (a3 ^ b3));

        s3 = sum;
    }


    // ========================================================
    // Display
    // ========================================================

    cout << "\n";
    cout << "========================================================================\n";
    cout << "                    4-BIT RIPPLE CARRY ADDER BOX                      \n";
    cout << "========================================================================\n\n";


    cout << "         +------------+   +------------+   +------------+   +------------+\n";

    cout << "  A3 (" << a3 << ")-|            |   "
         << "|            |   "
         << "|            |   "
         << "|            |\n";

    cout << "  B3 (" << b3 << ")-|    FA 3    |   "
         << "|    FA 2    |   "
         << "|    FA 1    |   "
         << "|    FA 0    |\n";

    cout << "         |            |   "
         << "|            |   "
         << "|            |   "
         << "|            |\n";


    cout << " C4(" << c4 << ")<---| Cout  Cin |<--("
         << c3 << ")--| Cout  Cin |<--("
         << c2 << ")--| Cout  Cin |<--("
         << c1 << ")--| Cout  Cin |<--- Cin("
         << c0 << ")\n";


    cout << "         |            |   "
         << "|            |   "
         << "|            |   "
         << "|            |\n";


    cout << "  A2 (" << a2 << ")------------|            |   "
         << "|            |   "
         << "|            |\n";

    cout << "  B2 (" << b2 << ")------------|            |   "
         << "|            |   "
         << "|            |\n";


    cout << "  A1 (" << a1 << ")-------------------------|            |   "
         << "|            |\n";

    cout << "  B1 (" << b1 << ")-------------------------|            |   "
         << "|            |\n";


    cout << "  A0 (" << a0 << ")--------------------------------------|            |\n";

    cout << "  B0 (" << b0 << ")--------------------------------------|            |\n";


    cout << "         +-----+------+   +-----+------+   +-----+------+   +-----+------+\n";


    cout << "               |                |                |                |\n";


    cout << "            S3 (" << s3 << ")          "
         << "S2 (" << s2 << ")          "
         << "S1 (" << s1 << ")          "
         << "S0 (" << s0 << ")\n";


    cout << "\n------------------------------------------------------------------------\n";


    cout << "  INPUT A:  "
         << a3 << a2 << a1 << a0
         << " ("
         << (a3 * 8 + a2 * 4 + a1 * 2 + a0)
         << " in decimal)\n";


    cout << "  INPUT B:  "
         << b3 << b2 << b1 << b0
         << " ("
         << (b3 * 8 + b2 * 4 + b1 * 2 + b0)
         << " in decimal)\n";


    cout << "  CIN:      "
         << c0 << "\n";


    cout << "  RESULT:   "
         << c4
         << s3
         << s2
         << s1
         << s0
         << " ("
         << (c4 * 16 +
             s3 * 8 +
             s2 * 4 +
             s1 * 2 +
             s0)
         << " in decimal)\n";


    cout << "------------------------------------------------------------------------\n";
}