#include <iostream>
#include <string>
#include "ShoppingCart.h"
#include "ItemToPurchase.h"

using namespace std;

void PrintMenu();
void ExecuteMenu(char option, ShoppingCart& cart);

int main() {
    string customerName;
    string currentDate;
    char choice = '?';

    cout << "Enter customer's name:" << endl;
    getline(cin, customerName);
    cout << "Enter today's date:" << endl;
    getline(cin, currentDate);
    ShoppingCart cart1(customerName, currentDate);

    cout << endl << "Customer name: " << cart1.GetCustomerName() << endl;
    cout << "Today's date: " << cart1.GetDate() << endl << endl;
    
    while(choice != 'q'){
        cout << "MENU" << endl;
        PrintMenu();
        cout << endl;
        cout << "Choose an option:" << endl;
        cin >> choice;
        if(choice == 'f'){
           cout << "Choose an option:" << endl;
           cin >> choice;
            if(choice == 's'){
               cout << "Choose an option:" << endl;
               cin >> choice;
               if(choice == 'q'){
                  break;
               }
            }
        }
        ExecuteMenu(choice, cart1);
    }

    return 0;
}

void PrintMenu() {
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl;
}

void ExecuteMenu(char option, ShoppingCart& cart) {
    cin.ignore();
    string itemName;
    string itemDescription;
    int itemPrice;
    int itemQuantity;
    ItemToPurchase newItem;

    switch (option) {
        case 'a':
            cout << "ADD ITEM TO CART" << endl;
            cout << "Enter the item name:" << endl;
            getline(cin, itemName);
            cout << "Enter the item description:" << endl;
            getline(cin, itemDescription);
            cout << "Enter the item price:" << endl;
            cin >> itemPrice;
            cout << "Enter the item quantity:" << endl << endl;
            cin >> itemQuantity;
            newItem = ItemToPurchase(itemName, itemDescription, itemPrice, itemQuantity);
            cart.AddItem(newItem);
            break;
        case 'd':
            cout << "REMOVE ITEM FROM CART" << endl;
            cout << "Enter name of item to remove:" << endl;
            getline(cin, itemName);
            cart.RemoveItem(itemName);
            break;
        case 'c':
            cout << "CHANGE ITEM QUANTITY" << endl;
            cout << "Enter the item name:" << endl;
            getline(cin, itemName);
            cout << "Enter the new quantity:" << endl;
            cin >> itemQuantity;
            newItem.SetName(itemName);
            newItem.SetQuantity(itemQuantity);
            cart.ModifyItem(newItem);
            break;
        case 'i':
            cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
            cart.PrintDescriptions();
            cout << endl;
            break;
        case 'o':
            cout << "OUTPUT SHOPPING CART" << endl;
            cart.PrintTotal();
            cout << endl;
            break;
        case 'q':
            
            break;
    }
}
