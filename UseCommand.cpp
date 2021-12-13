#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include "ItemHasBeenTakenHeader.h"

using namespace std;


UseCommand(string room, string item, vector<string>&inventory, vector<string>&usedItemsList) {

    bool itemIsInInventory = ItemHasBeenTaken(inventory, item);
    int positionInInventory(string item, vector<string>inventory);
    bool itemHasBeenUsed(string usedItem, vector<string>itemList);

    if (room == "parking") {
        if (itemIsInInventory) {
            cout << "Now is not a good time to use your " << item << ".";
        }
        else {
            cout << "You don't have " << item << " in your INVENTORY.";
        }
    }

    if (room == "campus") {
        if (itemIsInInventory) {
            cout << "Now is not a good time to use " << item << ".";
        }
        else {
            cout << "You don't have " << item << " in your INVENTORY.";
        }
    }

    if (room == "fountain") {
        if (itemIsInInventory) {
            cout << "Now is not a good time to use " << item << ".";
        }
        else {
            cout << "You don't have " << item << " in your INVENTORY.";
        }
    }

    if (room == "bookstore") {

        if ((itemIsInInventory == true) && ((item == "THIRTY DOLLARS") || (item == "30 DOLLARS"))) {
            cout << "You take the 30 DOLLARS from your INVENTORY and leave it behind the COUNTER. Hopefully the right people will find it.";
            inventory.erase(inventory.begin());
            usedItemsList.push_back("THIRTY DOLLARS");
        }

        else if ((itemIsInInventory == true) && ((item != "THIRTY DOLLARS") || (item != "30 DOLLARS"))) {
            cout << "Now is not a good time to use " << item << ".";
        }
        else {
            cout << "You don't have " << item << " in your INVENTORY.";
        }
    }

    if (room == "communications") {
        if ((itemIsInInventory == true) && ((item == "THUMB DRIVE") || (item == "THUMBDRIVE")) ) {
            cout << "You stick the THUMB DRIVE into a free USB port on the COMPUTER. Suddenly a long string of numbers and letters appears on screen." << endl;
            cout << "The SECRET CODE looks like gibberish, and there's no way you're going to be able to remember it without writing it down.";
            inventory.erase(inventory.begin() + positionInInventory("THUMB DRIVE", inventory));
            usedItemsList.push_back("THUMB DRIVE");
        }

        else if ((itemIsInInventory == true) && (itemHasBeenUsed("THUMB DRIVE", usedItemsList) == true) && (itemHasBeenUsed("FOUNTAIN PEN", usedItemsList) == false) && ((item == "PEN") || (item == "FOUNTAIN PEN"))) {
                cout << "You quickly take out your FOUNTAIN PEN and jot down the SECRET CODE on a nearby piece of paper so you won't forget." << endl;
                cout << "You put the written down SECRET CODE in your INVENTORY.";
                inventory.push_back("SECRET CODE");
                usedItemsList.push_back("FOUNTAIN PEN");
            }

        else if ((itemIsInInventory == true) && (itemHasBeenUsed(item, usedItemsList) == false) && ((item != "THUMB DRIVE") || (item != "THUMBDRIVE"))) {
            cout << "Now is not a good time to use the " << item << ".";
        }
        else {
            cout << "You don't have a " << item << " in your INVENTORY.";
        }
    }

    if (room == "vending") {

        if ((itemIsInInventory == true) && (item == "PENNY")) {
            cout << "You take the PENNY and put it in the VENDING MACHINE. It's exactly enough to bump the $1.48 already in the vending machine up to" << endl;
            cout << "the $1.49 price of a CANDY BAR. Gosh, you knew this thing was lucky, but you didn't expect it to kick in so quickly!" << endl;
            cout << "Carefully pressing the correct button combo causes a mechanical arm to push the CANDY BAR down. You grab it and put it in your INVENTORY.";
            inventory.erase(inventory.begin() + positionInInventory("PENNY", inventory));
            inventory.push_back("CANDY BAR");
            usedItemsList.push_back("PENNY");
        }

        else if ((itemIsInInventory == true) && (item != "PENNY")) {
            cout << "Now is not a good time to use " << item << ".";
        }
        else {
            cout << "You don't have " << item << " in your INVENTORY.";
        }
    }

    if (room == "cafe") {
        if (itemIsInInventory) {
            cout << "Now is not a good time to use " << item << ".";
        }
        else {
            cout << "You don't have " << item << " in your INVENTORY.";
        }
    }

    if (room == "library") {

        if ((itemIsInInventory == true) && (item == "SECRET CODE")) {
            cout << "On a hunch, you decide to type the SECRET CODE you found earlier into the TERMINAL. Reading off of the paper, you quickly tap at the keys," << endl;
            cout << "glancing up every so often to make sure you're inputting it correctly. When you finish, you nervously push ENTER." << endl;
            cout << "As soon as you do, a panel on the floor to your NORTH opens up, revealing a stone staircase leading down underneath the library. Woah.";
            usedItemsList.push_back("SECRET CODE");
        }

        else if ((itemIsInInventory == true) && (item != "SECRET CODE")) {
            cout << "Now is not a good time to use " << item << ".";
        }
        else {
            cout << "You don't have " << item << " in your INVENTORY.";
        }
    }

    if (room == "puzzle") {

        if ((itemIsInInventory == true) && (item == "CANDY BAR")) {
            cout << "You place the CANDY BAR into one of the bowls. You hear the sound of scraping stone as the lever sinks down slightly." << endl;
            inventory.erase(inventory.begin() + positionInInventory("CANDY BAR", inventory));
            usedItemsList.push_back("CANDY BAR");
        }

        if ((itemIsInInventory == true) && (item == "GARLIC")) {
            cout << "You place the GARLIC clove into one a bowl. The level shifts downwards when you do." << endl;
            inventory.erase(inventory.begin() + positionInInventory("GARLIC", inventory));
            usedItemsList.push_back("GARLIC");
        }

        else if ((itemIsInInventory == true) && (item != "CANDY BAR") && (item != "GARLIC")) {
            cout << "Now is not a good time to use " << item << ".";
        }
        else {
            cout << "You don't have " << item << " in your INVENTORY.";
        }

        if ((itemHasBeenUsed("CANDY BAR", usedItemsList) == true) && (itemHasBeenUsed("GARLIC", usedItemsList) == true)) {
            cout << "Combining the balance of sweet and savory, the bowls sink down and both click into place. Suddenly, the wall slides away, " << endl;
            cout << "revealing a MYSTERIOUS PASSAGEWAY facing NORTH. You're proud of your clever work, but you are also focused on how  "<< endl;
            cout << "gross chocolate and garlic would be together, but clearly it worked well enough for whoever built this place.";
        }
    }


}

    //return


int positionInInventory(string item, vector<string>inventory) {
        int itemPosition;
        int i;
        for (i = 0; i < inventory.size(); ++i) {
            if (inventory.at(i) == item) {
                itemPosition = i;
            }
        }
        return itemPosition;
    }

    bool itemHasBeenUsed(string usedItem, vector<string>itemList) {
        bool itemUsed = false;
        int i;
        for (i = 0; i < itemList.size(); ++i) {
            if (itemList.at(i) == usedItem) {
                itemUsed = true;
            }
        }
        return itemUsed;
    }
