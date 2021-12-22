#include <iostream>
#include <string>
#include <sstream>
#include <numeric>
using namespace std;

//Thanks MusicalProgrammer!
string ratioIn;

int cutStringUp(int Value1, int Value2 = -1)
{
    stringstream RatVal;
    RatVal << ratioIn.substr(Value1, Value2);
    int Rat;
    RatVal >> Rat;
    return Rat;
}
int main()
{
    int ratioSeperator;

    cout << "Input a ratio like this '1280x720': ";
    cin >> ratioIn;

    ratioSeperator = static_cast<int>(ratioIn.find("x"));
    int RatVals[] = { cutStringUp(0, ratioSeperator), cutStringUp(ratioSeperator + 1) };
    int ratioFromRes = gcd(RatVals[0], RatVals[1]);
    int finalVals[] = { RatVals[0] / ratioFromRes , RatVals[1] / ratioFromRes };

    cout << finalVals[0] << ":" << finalVals[1];
    cout << "\nPress any key to continue . . . ";
    cin.ignore();
    cin.get();
}