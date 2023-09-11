#include <iostream>
// tomato-7
using namespace std;
    string product;
    double money = 1000, price;
    string stock1 = "NONE", stock2 = "NONE", stock3 = "NONE", stock4 = "NONE", stock5 = "NONE";
    string inv1 = "NONE", inv2 = "NONE", inv3 = "NONE", inv4 = "NONE", inv5 = "NONE";
    double p1, p2, p3, p4, p5;
    int space = 0;
    int stocka1 = 0, stocka2 = 0, stocka3 = 0, stocka4 = 0, stocka5 = 0;
    int inva1 = 0, inva2 = 0, inva3 = 0, inva4 = 0, inva5 = 0;
    string addproduct;
    string addto;
    void stockCheck(){
        if (stocka1 = 0){
            stock1 = "NONE";
        } else if (stocka2 = 0){
            stock2 = "NONE";
        } else if (stocka3 = 0){
            stock3 = "NONE";
        } else if (stocka4 = 0){
            stock4 = "NONE";
        } else if (stocka5 = 0){
            stock5 = "NONE";
        }
    }
    void invCheck(){
        if (inva1 = 0){
            inv1 = "NONE";
        } else if (inva2 = 0){
            inv2 = "NONE";
        } else if (inva3 = 0){
            inv3 = "NONE";
        } else if (inva4 = 0){
            inv4 = "NONE";
        } else if (inva5 = 0){
            inv5 = "NONE";
        }
    }
    void showMoney(){
        cout << "You have $ " << money << " dollars." << endl; 
    }
    void showInventory(){
        if (inv1 == inv2) {
            inv2 = "NONE";
            inva1 = inva1 + inva2;
            inva2 = 0;
        }
        else if (inv2 == inv3) {
            inv3 = "NONE";
            inva2 = inva2 + inva3;
            inva3 = 0;
        }
        else if (inv3 == inv4) {
            inv4 = "NONE";
            inva3 = inva3 + inva4;
            inva4 = 0;
        }
        else if (inv4 == inv5) {
            inv5 = "NONE";
            inva4 = inva4 + inva5;
            inva5 = 0;
        }

        cout <<"Your inventory "<< endl 
        << "Slot-1: " << inv1 << " - " << inva1 << endl
        << "Slot-2: " << inv2 << " - " << inva2 << endl
        << "Slot-3: " << inv3 << " - " << inva3 << endl
        << "Slot-4: " << inv4 << " - " << inva4 << endl
        << "Slot-5: " << inv5 << " - " << inva5 << endl;

    }
    void addInventorySlot(){
        if ( inv1 == "NONE" ){
            space = 1;
        } else if ( inv2 == "NONE") {
            space = 2;
        } else if ( inv3 == "NONE") {
            space = 3;
        } else if ( inv4 == "NONE") {
            space = 4;
        } else if ( inv5 == "NONE") {
            space = 5;
        } else {
            space = -1;
        }
    }
    void showStocks(){
        cout <<"Current stocks: "<< endl 
        << "Stock-1: " << stock1 << " - " << stocka1 << " unit" << " - " << p1 << "$" << endl
        << "Stock-2: " << stock2 << " - " << stocka2 << " unit" << " - " << p2 << "$" << endl
        << "Stock-3: " << stock3 << " - " << stocka3 << " unit" << " - " << p3 << "$" << endl
        << "Stock-4: " << stock4 << " - " << stocka4 << " unit" << " - " << p4 << "$" << endl
        << "Stock-5: " << stock5 << " - " << stocka5 << " unit" << " - " << p5 << "$" << endl;
    }
    void addStocks(){
        int amount;
        int addto;
        int already = 0;
        cout << "What are you selling?: " << endl;
        cin >> addproduct;

        if (addproduct == stock1) {
            addto = 1;
            already = stocka1;
        } else if (addproduct == stock2) {
            addto = 2;
            already = stocka2;
        } else if (addproduct == stock3) {
            addto = 3;
            already = stocka3;
        } else if (addproduct == stock4) {
            addto = 4;
            already = stocka4;
        } else if (addproduct == stock5) {
            addto = 5;
            already = stocka5;
        } else {
        cout << "Which shelf do you want to replace it with? : " << endl;
        showStocks();
        cin >> addto;
        }

        cout << "How many?: " << endl;
        cin >> amount;

        cout << "What is the price of them?: " << endl;
        cin >> price;
        money = money + (price * amount);
        switch(addto){
            case 1:
                stock1 = addproduct;
                stocka1 = amount + already;
                p1 = price * 11/10;
                break;
            case 2:
                stock2 = addproduct;
                stocka2 = amount + already;
                p2 = price * 11/10;
                break;
            case 3:
                stock3 = addproduct;
                stocka3 = amount + already;
                p3 = price * 11/10;
                break;
            case 4:
                stock4 = addproduct;
                stocka4 = amount + already;
                p4 = price * 11/10;
                break;
            case 5:
                stock5 = addproduct;
                stocka5 = amount + already;
                p5 = price * 11/10;
                break;
            default:
                cout << "Invalid place.";
                break;
        }
        
    }
    void market(){
        int choice, amount;
        double cost;
        showStocks();
        cout << "Choose a product to buy" << endl;
        cin >> choice;
        cout << "How many do you wish to?" << endl;
        cin >> amount;
        switch (choice){
            case 1:
                cost = p1 * amount;
                break;
            case 2:
                cost = p2 * amount;
                break;
            case 3:
                cost = p3 * amount;
                break;
            case 4:
                cost = p4 * amount;
                break;
            case 5:
                cost = p5 * amount;
                break;
        }
        if ( cost <= money) {
            if (amount <= stocka1 || amount <= stocka2 || amount <= stocka3 || amount <= stocka4 || amount <= stocka5 ){
                money = money - cost;
            } else {
                cout << "Insufficient Stock." << endl;
            }
        addInventorySlot();
            if (space == -1){
                cout << "you don't have enough space!" << endl;
                } else {
                switch(space) {
            case 1:
                switch(choice) {
                    case 1:
                        inv1 = stock1;
                        break;
                    case 2:
                        inv1 = stock2;
                        break;
                    case 3:
                        inv1 = stock3;
                        break;
                    case 4:
                        inv1 = stock4;
                        break;
                    case 5:
                        inv1 = stock5;
                        break;   
                }
                inva1 = amount;
                break;
            case 2:
                switch(choice) {
                    case 1:
                        inv2 = stock1;
                        break;
                    case 2:
                        inv2 = stock2;
                        break;
                    case 3:
                        inv2 = stock3;
                        break;
                    case 4:
                        inv2 = stock4;
                        break;
                    case 5:
                        inv2 = stock5;
                        break;
                }
                inva2 = amount;
                break;
            case 3:
                switch(choice) {
                    case 1:
                        inv3 = stock1;
                        break;
                    case 2:
                        inv3 = stock2;
                        break;
                    case 3:
                        inv3 = stock3;
                        break;
                    case 4:
                        inv3 = stock4;
                        break;
                    case 5:
                        inv3 = stock5;
                        break;   
                }
                inva3 = amount;
                break;
            case 4:
                switch(choice) {
                    case 1:
                        inv4 = stock1;
                        break;
                    case 2:
                        inv4 = stock2;
                        break;
                    case 3:
                        inv4 = stock3;
                        break;
                    case 4:
                        inv4 = stock4;
                        break;
                    case 5:
                        inv4 = stock5;
                        break;   
                }
                inva4 = amount;
                break;
            case 5:
                switch(choice) {
                    case 1:
                        inv5 = stock1;
                        break;
                    case 2:
                        inv5 = stock2;
                        break;
                    case 3:
                        inv5 = stock3;
                        break;
                    case 4:
                        inv5 = stock4;
                        break;
                    case 5:
                        inv5 = stock5;
                        break;   
                }
                inva5 = amount;
                break;
            }
        switch(choice){
            case 1:
                if( amount <= stocka1 ){
                    stocka1 = stocka1 - amount;
                }
                break;
            case 2:
                if( amount <= stocka2 ){
                    stocka2 = stocka2 - amount;
                }
                break;
            case 3:
                if( amount <= stocka3 ){
                    stocka3 = stocka3 - amount;
                }
                break;
            case 4:
                if( amount <= stocka4 ){
                    stocka4 = stocka4 - amount;
                }
                break;
            case 5:
                if( amount <= stocka5 ){
                    stocka5 = stocka5 - amount;
                }
                break;
            default:
                cout << "The Market doesn't have enough stock" << endl;
                break;
    }
    }
    } else {
        cout << "You don't have enough money." << endl;
    }
    }
    void eat(){
        int eat, amount;
        cout << "Which food do you wanna eat?" << endl;
        showInventory();
        cin >> eat;
        cout << "How many do you wanna eat?" << endl;
        cin >> amount;

        switch(eat){
            case 1:
                if ( amount <= inva1 ){
                    inva1 = inva1 - amount;
                    //random event?
                    cout << "You ate " << amount << " " << stock1 << endl;
                } else { 
                    cout << "You don't have enough of " << stock1 << endl;
                }
                break;
            case 2:
                if ( amount <= inva2 ){
                    inva2 = inva2 - amount;
                    cout << "You ate " << amount << " " << stock2 << endl;
                } else { 
                    cout << "You don't have enough of " << stock2 << endl;
                }
                break;
            case 3:
                if ( amount <= inva3 ){
                    inva3 = inva3 - amount;
                    cout << "You ate " << amount << " " << stock3 << endl;
                } else { 
                    cout << "You don't have enough of " << stock3 << endl;
                }
                break;
            case 4:
                if ( amount <= inva4 ){
                    inva4 = inva4 - amount;
                    cout << "You ate " << amount << " " << stock4 << endl;
                } else { 
                    cout << "You don't have enough of " << stock4 << endl;
                }
                break;
            case 5:
                if ( amount <= inva5 ){
                    inva5 = inva5 - amount;
                    cout << "You ate " << amount << " " << stock5 << endl;
                } else { 
                    cout << "You don't have enough of " << stock5 << endl;
                }

                break;
            default:
                cout << "Invalid option" << endl;
                break;
        }
    }
int main(){
    int choice;

    do{
    cout << "************* MARKET *************" << endl;
    cout << "You have $" << money << " dollars." << endl;
    cout << "1. STOCKS \n" << "2. SELL \n" << "3. BUY \n" << "4. INVENTORY \n" << "5. EAT \n" << "6. MONEY \n" << "9.EXIT \n" ;
    cin >> choice;
    
    if(choice == 1){
        showStocks();
    } else if ( choice == 2 ) {
        addStocks();
    } else if ( choice == 3 ){
        market();
    } else if ( choice == 4 ){
        showInventory();
    } else if ( choice == 5 ){
        eat();
    } else if ( choice == 6 ){
        showMoney();
    }

    } while (choice != 9);

    return 0;
}