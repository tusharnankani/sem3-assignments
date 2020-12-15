import java.io.*;
import java.lang.*;
import java.util.*;

class Account {
    long int accountNumber;
    String name;
    Account(long int an, String n) {
        accountNumber = an;
        n = name;
    }
    // withdraw, deposit
}

class SavingsAccount extends Account {
    float balance;
    // display
    
}

class DepositAccount extends Account {
    float amountToBeDeposited;
    String startDate, endDate;
    // display
}

class ShortTermDepositAccount extends DepositAccount {
    // 12 months
}

class LongTermDepositAccount extends DepositAccount {
    // years
}

class Bank {
    public static void void(String args[]) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);

    }
}
