#include <iostream>

using namespace std;
const int SIZE = 5;

string inv[SIZE] = {"CUCUMBER", "NONE", "NONE", "NONE", "NONE"};
string store[SIZE] = {"TOMATO-7", "NONE", "NONE", "NONE", "NONE"};

int invstock[SIZE] = {10, 0, 0, 0, 0};
int storestock[SIZE] = {500, 0, 0, 0, 0};

double storeprice[SIZE] = {10, 0, 0, 0, 0};

double money = 0.01;

void startSec(); //
//void sell();
void buy();

void showInv(); //
void showStore(); //

void eat(); //
void showMoney(); //

void invCheck(); //
void storeCheck(); //

void back(int userinput);
void invadd(string food, int amount);

int main(){
    invCheck();
    storeCheck();
    startSec();


    return 0;
}

void startSec(){
    int op;

    cout << "Welcome to grand bazaar" << endl;
    do {
    cout << "If you want to back to main menu from any menu please type '-1'" << endl; // cbb here
    cout << "1. SHOW STORE | 2. SELL | 3. BUY | 4. INVENTORY | 5. EAT | 6. SHOW MONEY | 7. | 8. | 9. EXIT" << endl;

    cin >> op;
    back(op);

    switch (op){
        case 1:
            showStore();
            main();
            break;
        case 2:
            //sell();
            main();
            break;
        case 3:
            buy();
            main();
            break;
        case 4:
            showInv();
            main();
            break;
        case 5:
            eat();
            main();
            break;
        case 6: 
            showMoney();
            main();
            break;
        case 9:
            cout << "Exitting..." << endl;
            break;
        default:
            cout << "Invalid option" << endl;
            break;
        }
    } while ( op != 9);

}
void showMoney(){
    cout << "You have $" << money << " dollars" << endl;
}

void invCheck(){
    // if 2 of inventory slot is same merges them
    for (int i = 0; i < SIZE; i++){
        if ( inv[i] == inv[i + 1]){
            invstock[i] += invstock[i + 1];
            invstock[i + 1] = 0;
            inv[i + 1] = "NONE";
        }
    }
    // if inventory slot is empty(zero) deletes item
    for (int i = 0; i < SIZE; i++){
        if ( invstock[i] == 0 ){
            inv[i] = "NONE";
        }
    }
    
}
void storeCheck(){
    // if 2 of store slot is same merges them
    for (int i = 0; i < SIZE; i++){
        if ( store[i] == store[i + 1]){
            storestock[i] += storestock[i + 1];
            storestock[i + 1] = 0;
            storeprice[i + 1] = 0;
            store[i + 1] = "NONE";
        }
    }
    // if store slot is empty(zero) deletes item
    for (int i = 0; i < SIZE; i++){
        if ( storestock[i] == 0 ){
            store[i] = "NONE";
        }
    }
    

}

void showInv(){
    cout << "YOUR INVENTORY" << endl;
    for (int i = 0; i < SIZE; i++){
        if(invstock[i > 0]){
        cout << "SLOT " << i + 1 << ": " << inv[i] << " - " << invstock[i] << endl; 
        }
    }
}
void showStore(){
    cout << "STORE SHELFS" << endl;
    for (int i = 0; i < SIZE; i++){
        if (storestock[i] > 0){
        cout << "SLOT " << i + 1 << ": " << store[i] << " - " << storestock[i] << " - " << storeprice[i] << endl; 
        }
    }
}

void eat(){
    int op, amount;
    showInv();
    cout << "Which one do you want to eat?: " << endl;
    cin >> op;
    back(op);

    if (op > 5 || op < 1){
        cout << "Invalid option." << endl;
        eat();
    } else {
        if ( invstock[op - 1] > 0 ){
            cout << "How much?: " << endl;
            do{
            cin >> amount;
            back(amount);

            if (amount <= 0){
                cout << "You can't eat that much" << endl;
            } else {
                if (invstock[op - 1] > amount){
                    invstock[op - 1] -= amount;
                    } else {
                    cout << "Insufficient Stock. Please re-entry the amount" << endl;
                }
            }
            } while (invstock[op - 1] < amount || amount <= 0);
        } else {
            cout << "You don't have any" << endl;
        }
    }

}

void back(int userinput){
    if(userinput == -1){
        cout << "Backing to main menu \n\n";
        main();
    }
}

void buy(){
    int op, amount;

    showStore();
    cout << "Which one do you want to buy" << endl;
    cin >> op;
    back(op);

    if ( op >= 1 && op <= 5){
        if (storestock[op - 1] > 0){

            cout << "How many? " << endl;
            do{
            cin >> amount;
            if ( amount > 0){
                if ( storestock[op - 1] >= amount){
                    storestock[op - 1] -= amount;
                    invadd(store[op - 1], amount);
                } else {
                    cout << " TOO MUCH MAN" << endl;
                }
                } else {
                cout << "Amount must be bigger than zero" << endl;
                }
            } while ( amount <= 0 || storestock[op - 1] < amount);
        } else {
            cout << "They don't have any" << endl;
        }

    } else {
        cout << "Invalid option" << endl;
        buy();
    }
}

void invadd(string food, int amount){
    for (int i = 0; i < SIZE; i++){
        if (inv[i] == "NONE"){
            inv[i] = food;
            invstock[i] = amount;
            break;
        }
    }
}
