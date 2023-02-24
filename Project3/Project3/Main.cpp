//Kyle Gilbert
//    2/15/23
// This code creates displays for 3 different styles of output
// you can select one item to see how much 

using namespace std;
#include "GroceryData.h"

int main() {
    int input = 0;  
    GroceryData listGeneration;
    do {
        listGeneration.DisplayMenu();
        cin >> input;
        listGeneration.SetMenuItem(input);
        if (listGeneration.GetMenuItem() == 1) {
            listGeneration.DisplayQuantity();
        }
        else if (listGeneration.GetMenuItem() == 2) {
            listGeneration.GenerateNumList();
        }
        else if (listGeneration.GetMenuItem() == 3) {
            listGeneration.DisplayHistogram();
        }
        else{
            cout << "Enter a valid input" << endl;
        }
    } while (listGeneration.GetMenuItem() != 4);
    return 0;
}