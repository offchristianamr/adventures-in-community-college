#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include "ItemHasBeenTakenHeader.h"
using namespace std;

TakeCommand(string room, string item, vector<string>&inventory) {

    if (room == "parking") {
        if (item == "CAR") {
            cout << "Your CAR is way too heavy to even consider taking with you to class. It will be safe here, though.";
        }
        else if (item == "LOT 28") {
            cout << "The entire parking lot?! As much as you appreciate LOT 28, it belongs at COD.";
        }
        else if (item == "STRUCTURE") {
            cout << "You don't spend too long thinking about how you would take the entire STRUCTURE. Even the largest of backpacks couldn't hold it.";
        }
        else if (item == "PARKING SPOT") {
            cout << "I guess, in a way, you already took the PARKING SPOT. That's the most you'll entertain that idea.";
        }
        else {
            cout << "Sorry, you can't take the " << item << " with you right now.";
        }
    }

    if (room == "campus") {
        if ((item == "PLANT") || (item == "PLANTS")) {
            cout << "You briefly consider trying to uproot the PLANTS, but the last thing you need is a vandalsim fine.";
        }

        else if ((item == "THUMB DRIVE") || (item == "THUMBDRIVE")) {
            if (ItemHasBeenTaken(inventory, "THUMB DRIVE") == false) {
                cout << "Reaching in carefully between the spines of the PLANT, you grab the mysterious THUMB DRIVE and put it in your inventory." << endl;
                inventory.push_back("THUMB DRIVE");
            }
            else {
                cout << "You already took the THUMB DRIVE. It is safely tucked away in your INVENTORY.";
            }
        }
        else if ((item == "TREE") || (item == "TREES")) {
            cout << "The TREES are firmly rooted in place, and, besides, they looks nice where it they are.";
        }
        else if (item == "SIDEWALK") {
            cout << "Flashing back to your attempt to take the PARKING SPACE, any taking of the SIDEWALK that you do is purely metaphorical.";
        }
        else {
            cout << "Sorry, you can't take the " << item << " with you right now.";
        }
    }

    if (room == "fountain") {
        if (item == "PLAQUE") {
            cout << "The PLAQUE is firmly cemented down. What would you do with a PLAQUE, anyways?";
        }

        else if (item == "PENNY") {
            if (ItemHasBeenTaken(inventory, "PENNY") == false) {
                cout << "The thought of reaching into a fountain is kind of gross, but you know to never pass up a lucky PENNY." << endl;
                cout << "You roll up your sleeves and quickly grab the PENNY, putting it in your INVENTORY.";
                inventory.push_back("PENNY");
            }
            else {
                cout << "The unmistakable sense of luck that you feel is enough to tell you that the PENNY is already in your possession.";
            }
        }
        else {
            cout << "Sorry, you can't take the " << item << " with you right now.";
        }
    }

    if (room == "bookstore") {
        if ((item == "BOOK") || (item == "BOOKS")) {
            cout << "There's no way you're taking any of the BOOKS. You already spent all your FAFSA money on avacado toast and fancy cheese platters.";
        }
        else if ((item == "PAPER") || (item == "PAPERS")) {
            cout << "You usually just borrow paper from a classmate. It's a bad habit, but it sure saves a lot of money on paper.";
        }
        else if ((item == "BINDER") || (item == "BINDERS")) {
            cout << "Taking the binder would overflow the 32 bit integer limit of the vector that represents the space in your bag.";
        }
        else if ((item == "PRINTER") || (item == "PRINTERS")) {
            cout << "You don't like the idea of carrying around a PRINTER in your bag. Besides, there's one missing, meaning they already met the semester quota.";
        }
        else if ((item == "COUNTER") || (item == "CHECKOUT COUNTER") || (item == "CHECK OUT COUNTER")) {
            cout << "How will people check out their items if you take the CHECKOUT COUNTER? You decide to leave it for the good of your fellow students.";
        }
        else if ((item == "FOUNTAIN PEN") || (item == "PEN")) {
            //use this to check if the money has been used already.
            if (ItemHasBeenTaken(inventory, "THIRTY DOLLARS") == true) {
                cout << "You're not a theif! There's no one here to catch you, but the guilt would overwhelm you.";
            }
            else {
                cout << "Having paid for the FOUNTAIN PEN, you feel comfortable taking it with you. You put it in your INVENTORY.";
                inventory.push_back("FOUNTAIN PEN");
            }
        }
        else {
            cout << "Sorry, you can't take the " << item << " with you right now.";
        }
    }

        if (room == "communications") {
            if ((item == "AC") || (item == "AC UNIT") || (item == "AIR CONDITIONING") ||(item == "AIR CONDITIONER") ||(item == "AIR CONDITIONING UNIT")) {
                cout << "Gosh, you wish you could take the AIR CONDITIONING UNIT with you. If you could carry it, it would be in your bag right now.";
            }
            else if ((item == "WHITEBOARD") || (item == "WHITE BOARD")) {
                cout << "You can't take the entire WHITEBOARD, but you can take all the knowlege it offers. Isn't that beautiful?" << endl;
            }
            else if ((item == "DESK") || (item == "TEACHER'S DESK")) {
                cout << "You can't steal the DESK! When you find out where everyone went, they're going to totally know it was you who took it." << endl;
            }
            else if (item == "COMPUTER") {
                cout << "You have a COMPUTER at home already. This one probably has all sorts of tracking software on it anyways.";
            }
            else {
                cout << "Sorry, you can't take the " << item << " with you right now.";
            }
    }

        if (room == "vending") {
            if ((item == "CANDY") || (item == "CANDY BAR")) {
                cout << "You probably can't squeeze into the vending machine, so your only option for getting a CANDY BAR is to pay up.";
            }
            else if (item == "DIAL PAD") {
                cout << "If you had the brute strength to rip the DIAL PAD clean off of a VENDING MACHINE, you kind of deserve to keep it." << endl;
                cout << "Unfortunately, you don't have such strength.";
            }
            else if (item == "SCREEN") {
                cout << "You remember that a SCREEN like that could be bought pretty cheap if you wanted one for personal projects. Not worth stealing it.";
            }
            else {
                cout << "Sorry, you can't take the " << item << " with you right now.";
            }
        }

        if (room == "cafe") {
        if ((item == "TABLE") || (item == "TABLES")) {
            cout << "Owning an authentic BEEPS CAFE TABLE would be one of the strangest bragging rights ever. You're not looking to impress anyone right now.";
        }
        else if ((item == "CHAIR") || (item == "CHAIRS")) {
            cout << "So many to choose from! The though of picking just one CHAIR is too overwhelming, so you leave them be.";
        }
        else if ((item == "SODA MACHINE") || (item == "SOFT DRINK MACHINE") || (item == "DRINK MACHINE")) {
            cout << "Owning a SOFT DRINK MACHINE is a childhood dream of yours. You're older now, though, and the having to maintain such a specialized" << endl;
            cout << "piece of machinery is not something you can take on right now.";
        }
        else if (item == "ICE") {
            cout << "Too cold! Besides, it would end up melting in your bag anyways.";
        }
        else if (item == "GARLIC")  {
            if (ItemHasBeenTaken(inventory, "GARLIC") == false) {
                cout << "You snatch the GARLIC and put it in your INVENTORY. Vampires don't stand a chance against you!" << endl;
                inventory.push_back("GARLIC");
            }
            else {
                cout << "The GARLIC is in your INVENTORY. Endless cooking possibilites." << endl;
            }
        }

        else {
                cout << "Sorry, you can't take the " << item << " with you right now.";
        }
    }

    if (room == "library") {
        if ((item == "PRINTER") || (item == "PRINTERS")) {
            cout << "Having a printer like this would be great, but you use them so often at the library that taking them would probably result" << endl;
            cout << "in you failing a class.";
        }
        else if ((item == "BOOK") || (item == "BOOKS")) {
            cout << "Unfortunately, you forgot your library card at home. You're trying to get back into reading, so you do make a mental note" << endl;
            cout << "to bring it with you next time.";
        }
        else if ((item == "SKYLIGHT") || (item == "SKY LIGHT")) {
            cout << "An entire SKYLIGHT? How are you even going to get up there? This is your most ambitious TAKE command yet.";
        }
        else if (item == "TERMINAL") {
            cout << "Taking the TERMINAL wouldn't do much good. You don't even know what it's here for." << endl;
        }
        else {
                cout << "Sorry, you can't take the " << item << " with you right now.";
        }
    }

    if (room == "puzzle") {
        if ((item == "TORCH") || (item == "TORCHES")) {
            cout << "You can't take the TORCHES. I do understand why a TORCH might come in handy later, but just trust me on this.";
        }
        else if ((item == "SHELF") || (item == "SHELVES")) {
            cout << "You couldn't take the SHELVES without spilling all of their precious contents." << endl;
        }
        else if ((item == "POTION") || (item == "POTIONS")) {
            cout << "You want to stay as far away from the POTIONS as possible. Who knows what they might do to you?.";
        }
        else if ((item == "IDOL") || (item == "IDOLS")) {
            cout << "The stone IDOLS are too heavy, but you'll definitely pitch the idea of stone roadrunners around campus once you find everyone.";
        }
        else if ((item == "BOWL") || (item == "BOWLS")) {
            cout << "The BOWLS are firmly secured to the levers in the wall.";
        }
        else {
                cout << "Sorry, you can't take the " << item << " with you right now.";
        }
    }
    //return
}
