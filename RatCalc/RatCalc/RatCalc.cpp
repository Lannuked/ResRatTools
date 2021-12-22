#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

//Thanks MusicalProgrammer!
double dividedValue;
string ratioIn;

string calcFinalVals(double WhichRat)
{
    stringstream MakeFinal;
    MakeFinal << floor(WhichRat * dividedValue);
    string FinalRat;
    FinalRat = MakeFinal.str();
    return FinalRat;
}

double cutStringUp(int Value1, int Value2 = -1)
{
    stringstream RatVal;
    RatVal << ratioIn.substr(Value1, Value2);
    double Rat;
    RatVal >> Rat;
    return Rat;
}
int main()
{
    int ratioSeperator;
    double resVal;

    cout << "Input a ratio like this '16:9': ";
    cin >> ratioIn;
    cout << "Input Value: ";
    cin >> resVal;

    ratioSeperator = static_cast<int>(ratioIn.find(":"));

    double RatVals[] = { cutStringUp(0, ratioSeperator), cutStringUp(ratioSeperator + 1) };
    vector < string > FinalVals = {};
    for (int i = 0; i < 2; i++) {
        dividedValue = resVal / RatVals[i];
        FinalVals.push_back(calcFinalVals(RatVals[0]) + "x" + calcFinalVals(RatVals[1]));
    }
    cout << "X " + FinalVals[0] + "\nY " + FinalVals[1];
    cout << "\nPress any key to continue . . . ";
    cin.ignore();
    cin.get();
}