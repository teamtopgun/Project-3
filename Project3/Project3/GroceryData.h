#pragma once
#include <iostream>


class GroceryData
{
public:
    GroceryData();
    void SetMenuItem(int menuChoice);
    int GetMenuItem() const;
    void DisplayMenu();
    void GenerateNumList();
    void DisplayQuantity();
    void DisplayHistogram();

private:
    int menuSelection;
};