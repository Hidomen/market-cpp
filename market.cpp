#include <iostream>

const int SIZE = 5;
                    // for test
std::string inv[SIZE] = {"TOMATO-7", "AAA0", "AAA1", "AAA2", "AAA3"};
std::string store[SIZE] = {"POTATO", "NONE", "NONE", "NONE", "NONE"};

int invstock[SIZE] = {100, 50, 10, 20, 30};
int storestock[SIZE] = {45, 0, 0, 0, 0};

double storeprice[SIZE] = {0, 0, 0, 0, 0};

double money = 0.01;

void startSec();
void sell();
void buy();

void showInv();
void showStore();

void eat();
void showMoney();

void invCheck();
void storeCheck();

void back(int userinput);
void invadd(int op, std::string food, int amount);
void storeadd(int op, std::string food, int amount, double price);

int main(){
    invCheck();
    storeCheck();
    startSec();


    return 0;
}

void startSec(){
    int op;

    std::cout << "Welcome to grand bazaar\n";
    do {
    std::cout << "If you want to back to main menu from any menu please type '-1'\n"; // cbb here
    std::cout << "1. STORE | 2. INVENTORY | 3. SELL | 4. BUY | 5. EAT | 6. MONEY | 9. EXIT\n";

    std::cin >> op;
    back(op);

    switch (op){
        case 1:
            showStore();
            main();
            break;
        case 2:
            showInv();
            main();
            break;
        case 3:
            sell();
            main();
            break;
        case 4:
            buy();
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
            std::cout << "Exitting...\n";
            break;
        default:
            std::cout << "Invalid option\n";
            break;
        }
    } while ( op != 9);

}
void showMoney(){
    std::cout << "You have $" << money << " dollars\n";
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
    std::cout << "YOUR INVENTORY\n";
    for (int i = 0; i < SIZE; i++){
        if(invstock[i > 0]){
        std::cout << "SLOT " << i + 1 << ": " << inv[i] << " - " << invstock[i] << '\n'; 
        }
    }
}
void showStore(){
    std::cout << "STORE SHELFS\n";
    for (int i = 0; i < SIZE; i++){
        if (storestock[i] > 0){
        std::cout << "SLOT " << i + 1 << ": " << store[i] << " - " << storestock[i] << " - " << storeprice[i] << '\n'; 
        }
    }
}

void eat(){
    int op, amount;
    showInv();
    std::cout << "Which one do you want to eat?: \n";
    std::cin >> op;
    back(op);

    if (op > 5 || op < 1){
        std::cout << "Invalid option.\n";
        eat();
    } else {
        if ( invstock[op - 1] > 0 ){
            std::cout << "How much?: \n";
            do{
            std::cin >> amount;
            back(amount);

            if (amount <= 0){
                std::cout << "You can't eat that much\n";
            } else {
                if (invstock[op - 1] > amount){
                    invstock[op - 1] -= amount;
                    } else {
                    std::cout << "Insufficient Stock. Please re-entry the amount\n";
                }
            }
            } while (invstock[op - 1] < amount || amount <= 0);
        } else {
            std::cout << "You don't have any\n";
        }
    }

}

void back(int userinput){
    if(userinput == -1){
        std::cout << "Backing to main menu \n\n";
        main();
    }
}

void buy(){
    int op, amount;

    showStore();
    std::cout << "Which one do you want to buy\n";
    std::cin >> op;
    back(op);

    if ( op >= 1 && op <= 5){
        if (storestock[op - 1] > 0){

            std::cout << "How many? \n";
            do{
            std::cin >> amount;
            if ( amount > 0){
                if ( storestock[op - 1] >= amount){
                    invadd(op, store[op - 1], amount); // SUCESS
                } else {
                    std::cout << " TOO MUCH MAN\n";
                }
                } else {
                std::cout << "Amount must be bigger than zero\n";
                }
            } while ( amount <= 0 || storestock[op - 1] < amount);
        } else {
            std::cout << "They don't have any\n";
        }

    } else {
        std::cout << "Invalid option\n";
        buy();
    }
}
void sell(){
    int op, amount, price;
    showInv();
    std::cout << "What do you want to sell?\n";
    std::cin >> op;
    back(op);

        if( op < SIZE && op > 0){
            if(inv[op - 1] != "NONE"){
                std::cout << "How many?: \n";
                std::cin >> amount;
                back(amount);

                if(invstock[op - 1] > amount){
                    std::cout << "Whats the price ?: \n";
                    std::cin >> price;
                    back(price);

                    if(price > 0){
                        storeadd(op, inv[op - 1], amount, price);
                    } else {
                        std::cout << "price must be bigger than 0\n";
                        sell();
                    }

                } else {
                    std::cout << "You dont have that much\n";
                    sell();
                }
            } else {
                std::cout << "You dont have any\n";
                sell();
            }
        }

}

void invadd(int op, std::string food, int amount){
    for (int i = 0; i < SIZE; i++){
        if (inv[i] == "NONE"){
            inv[i] = food;
            invstock[i] = amount;
            storestock[op - 1] -= amount;
            break;
        } else if(i == SIZE - 1){
            std::cout << "THERE IS NO SPACE\n";
        }
    }
}
void storeadd(int op, std::string food, int amount, double price){
    for (int i = 0; i < SIZE; i++){
        if(store[i] == "NONE"){
            store[i] = food;
            storestock[i] = amount;
            storeprice[i] = price;
            break;
        }
    }
}
