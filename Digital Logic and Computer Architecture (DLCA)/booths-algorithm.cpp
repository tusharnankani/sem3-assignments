#include <bits/stdc++.h>

using namespace std;

string M, A, Q, MD;

string binary(int n)
{
    int a[50], i, flag = 0;
    string s = "";

    // for positive;
    if(n > 0)
    {
        for(i=0; n>0; i++)
        {
            a[i] = n % 2;
            n = n / 2;
        }
        // Adding 0 for the sign bit;
        s += "0";
        for(i = i - 1; i >= 0; i--)
        {
            s += ('0' + a[i]);
            // printf("%d", a[i]);
        }
    }
    // For negative;
    else
    {
        n *= -1;
        for(i = 0; n>0; i++)
        {
            a[i] = n % 2;
            n = n / 2;
        }
        //
        a[i] = 0;
        int t = i;

        // debug
        //for(i = t; i >= 0; i--)
            //printf("%d", a[i]);
        //printf("\n");
        // debug

        for(i = t; i >= 0; i--)
            a[i] = !a[i];
            // 1 --> 0

        // debug
        //for(i = t; i >= 0; i--)
            //printf("%d", a[i]);
        //printf("\n");
        // debug

        int carry = 0;

        if(a[0] == 1) {
            a[0] = 0;
            carry = 1;
        }
        else {
            a[0] = 1;
            carry = 0;
        }
        for(i = 1; i <= t; i++) {
            if(a[i] && carry)
                a[i] = 0, carry = 1;
            else if(a[i] == 0 && carry)
                a[i] = 1, carry = 0;
        }

        if(carry)
        {
            // printf("1");
            s += "1";
        }
        for(i = t; i >= 0; i--)
            s += ('0' + a[i]);
    }
    cout << "Binary: " << s << endl;
    return s;
}

int checkLastTwo(string s)
{
    int len = s.length(), ok = -1;
    if(s[len - 2] == s[len - 1])    // 00 || 11
        ok = 0;
    else if(s[len - 2] == '0' && s[len - 1] == '1')     // addition;
        ok = 1, cout << "A = A + M\t";
    else if(s[len - 2] == '1' && s[len - 1] == '0')     // subtraction;
        ok = 2, cout << "A = A - M\t";

    return ok;
}

void rightShift()
{
    // A, Q;
    int ql = Q.length(), al = A.length();
    //  0000 0101
    for(int i = ql - 1; i >= 0 ; --i)
    {
        if(i == 0)
            Q[i] = A[al - 1];
        else
            Q[i] = Q[i - 1];
    }
    for(int i = al - 1; i >= 0 ; --i)
    {
        if(i == 0)
            continue;
        else
            A[i] = A[i - 1];
    }
}

void add(string y)
{
    int l = A.length(), carry = 0;
    for(int i = l - 1; i >= 0; --i)
    {
        if(A[i] == '1' && y[i] == '1' && carry)
            A[i] = '1', carry = 1;
        else if(((A[i] == '1' && y[i] == '0') || (A[i] == '0' && y[i] == '1')) && carry)
            A[i] = '0', carry = 1;
        else if(A[i] == '0' && y[i] == '0' && carry)
            A[i] = '1', carry = 0;

        else if(A[i] == '1' && y[i] == '1')
            A[i] = '0', carry = 1;
        else if((A[i] == '1' && y[i] == '0') || (A[i] == '0' && y[i] == '1'))
            A[i] = '1', carry = 0;
        else if(A[i] == '0' && y[i] == '0')
            A[i] = '0', carry = 0;
    }
}

// A = A + M or A = A - M;
void operate(int ok)
{
    //cout << "\nA: " << A << endl;
    if(ok == 1)
        add(M);
    else if(ok == 2)
        add(MD);
    //cout << "\nA: " << A << endl;
}

string twoComplement(string x)
{
    int t = x.length();
    string a = x;

    for(int i = t; i >= 0; i--)
            a[i] = ('0' + (1 - (a[i] - '0')));
    // 0101
    // 1010
    //   +1
    // 1011
    int carry = 0;

    // bug fixed --> a[0] to a[t - 1]
    if(a[t - 1] == '1') {
        a[t - 1] = '0';
        carry = 1;
    }
    else {
        a[t - 1] = '1';
        carry = 0;
    }
    for(int i = t - 2; i >= 0; --i) {
        if(a[i] == '1' && carry)
            a[i] = '0', carry = 1;
        else if(a[i] == '0' && carry)
            a[i] = '1', carry = 0;
    }
    return a;
}

void go()
{
    cout << "M: " << M;
    cout << "   A: " << A;
    cout << "   Q: " << Q;
    cout << endl;
}

int main()
{
    cout << "\nWelcome to Booth's Multiplication Algorithm!" << endl;
    int a, b;
    cout << "\nEnter two numbers (a and b) for multiplication: " << endl;
    cout << "Enter a:  ";
    cin >> a;
    cout << "Enter b:  ";
    cin >> b;
    cout << endl;
    M = binary(a), Q = binary(b);
    if(M.length() < Q.length())
        swap(M, Q);

    int cnt = Q.length();
    Q += '0';
    int ml = M.length(), ql = Q.length();
    A = "", MD = twoComplement(M);
    cout << "MD: " << MD << endl;

    for(int i = 0; i < ml; ++i)
        A += "0";
    go();
    for(int i = 0; i < cnt; ++i)
    {
        cout << "\nIteration " << i + 1 << ":" << endl;
        int opt = checkLastTwo(Q);
        if(opt) {
            operate(opt);
            go();
        }
        cout << "RS(A.Q)\t\t";
        rightShift();
        go();
    }

    cout << "\nFinal Answer:  " << A << Q.substr(0, ql - 1) << endl;
    cout << "In decimal: " << a * b << endl;
    return 0;
}


