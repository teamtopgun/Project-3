#include <iostream>
#include "GroceryData.h"
#include <string>
#include <fstream>
#include <map>
#include <iomanip>
using namespace std;


GroceryData::GroceryData()
{
	menuSelection = 0;
}
int GroceryData::GetMenuItem() const
{
    return menuSelection;
}
void GroceryData::DisplayMenu()
{
    cout << endl << "----------------------------------------" << endl;
    cout << "Corner Grocer Inventory Analysis Program" << endl;
    cout << "----------------------------------------" << endl;
    cout << "1) Get quantity of a specific item" << endl;
    cout << "2) Print a list with quantity of items sold" << endl;
    cout << "3) Print a histogram of sold items" << endl;
    cout << "4) Exit the program" << endl;
}
void GroceryData::SetMenuItem(int menuChoice)
{
    menuSelection = menuChoice;
}
void GroceryData::DisplayQuantity()
{
    ifstream inFS;
    ofstream outFS;
    string groceryItem; //declaration of variables
    int quantity;
    string itemName;
    map<string, int> groceryList;


    inFS.open("Groceries.txt");




    while (!inFS.fail()) {

        inFS >> groceryItem;
        quantity = groceryList.count(groceryItem);

        if (quantity == 1) {
            groceryList.at(groceryItem) = groceryList.at(groceryItem) + 1;
        }
        else {
            groceryList.emplace(groceryItem, 1);
        }

    }
    groceryList.at(groceryItem) = groceryList.at(groceryItem) - 1; //error in placing last item on list

    inFS.close(); // Done with file, so close both.

    cout << "Type an Item's Name to Display Quantity Sold: " << endl;
    try {
        cin >> itemName;
        cout << groceryList.at(itemName) << " " << itemName << " sold." << endl;
    }
    catch (...) {
        cout << "No items in the list share that name.";
    }

}
void GroceryData::GenerateNumList()
{
    ifstream inFS;
    ofstream outFS;
    string groceryItem; //declaration of variables
    int quantity;
    map<string, int> groceryList;

    inFS.open("Groceries.txt");
    outFS.open("Frequency.dat");

    while (!inFS.fail()) {

        inFS >> groceryItem;
        quantity = groceryList.count(groceryItem);

        if (quantity == 1) {
            groceryList.at(groceryItem) = groceryList.at(groceryItem) + 1;
        }
        else {
            groceryList.emplace(groceryItem, 1);

        }

    }
    groceryList.at(groceryItem) = groceryList.at(groceryItem) - 1; //error in placing last item on list

    for (auto const& t : groceryList)
        cout << t.first << " " << t.second << "\n";
    for (auto const& t : groceryList)
        outFS << t.first << " " << t.second << "\n";
    outFS.close();
    inFS.close(); // Done with file, so close both.
}
void GroceryData::DisplayHistogram()
{
    ifstream inFS;
    string groceryItem; //declaration of variables
    int quantity;
    map<string, int> groceryList;

    inFS.open("Groceries.txt");

    while (!inFS.fail()) {

        inFS >> groceryItem;
        quantity = groceryList.count(groceryItem);

        if (quantity == 1) {
            groceryList.at(groceryItem) = groceryList.at(groceryItem) + 1;
        }
        else {
            groceryList.emplace(groceryItem, 1);

        }

    }
    groceryList.at(groceryItem) = groceryList.at(groceryItem) - 1; //error in placing last item on list

    for (auto const& t : groceryList)
        cout << setfill(' ') << setw(15) << right << t.first << " " << setfill('*') << setw(t.second + 1) << "\n";

    inFS.close(); // Done with file, so close both.
}