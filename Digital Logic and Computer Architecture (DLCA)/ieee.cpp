#include <bits/stdc++.h>

using namespace std;

string binary(int n)
{
    int a[50], i, flag = 0;
    string s = "";

    for(i=0; n>0; i++)
    {
        a[i] = n % 2;
        n = n / 2;
    }
    for(i = i - 1; i >= 0; i--)
    {
        s += ('0' + a[i]);
    }
    return s;
}


int main()
{
    cout << "IEEE 754 Conversion\n" << endl;
    int n;
    cout << "Enter a number to be converted: ";
    cin >> n;

    const int extra = 127, exp = 8, man = 23;
    string exponent, mantissa;
    char sign = ((n > 0) ? '0' : '1');

    string binaryNum = binary(abs(n));

    exponent = binary(binaryNum.length() - 1 + 127);
    mantissa = binaryNum.substr(1);

    for(int i = 0; i < man - binaryNum.length() + 1; ++i)
        mantissa += '0';

    cout << "\n - - - - - IEEE Format - - - - - \n";
    cout << " SIGN |   EXPONENT |    MANTISSA  " << endl;
    cout << "+---------------------------------------------+" << endl;
    cout << "|  " << sign << "  |  " << exponent << "  |  " << mantissa << " |" << endl;
    cout << "+---------------------------------------------+" << endl;


    return 0;
}
