#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include "ItemHasBeenTakenHeader.h"

using namespace std;

ExamineCommand(string room, string item, vector<string>&inventory) {

    if (room == "parking") {
        if (item == "CAR") {
            cout << "Your CAR looks the same as it always does. Your parking job isn't your best, but certainly not your worst either.";
        }
        else if (item == "LOT 28") {
            cout << "Ah, LOT 28. It's not radically different from the other parking lots, but this one just feels better for some reason.";
        }
        else if (item == "STRUCTURE") {
            cout << "The STRUCTURE is made of steel and casts a shadow over the whole parking lot. Its familiarity is oddly comforting.";
        }
        else if (item == "PARKING SPOT") {
            cout << "Your trusty parking spot. You park here whenever you have the chance. Once, you even found a lucky penny here.";
        }
        else {
            cout << "Now is not the time for examining " << item << ".";
        }
    }


    if (room == "campus") {
        if ((item == "PLANT") || (item == "PLANTS")) {
            cout << "You decide to admire the spikey desert PLANTS from a distance. Too many times have you been stabbed by them." << endl;
            if (ItemHasBeenTaken(inventory, "THUMB DRIVE") == false) {
                cout << "Looking at a particularly impressive plant, you see a small THUMB DRIVE tucked away between two of its spines." << endl;
                cout << "You could probably retrieve it with minimal bloodshed if you're careful.";
            }
        }
        else if ((item == "THUMBDRIVE") || (item == "THUMB DRIVE")) {
            if (ItemHasBeenTaken(inventory, "THUMB DRIVE") == false) {
                cout << "The THUMB DRIVE is red and has a small label with nothing written on it." << endl;
                cout << "It is small; approximately the size of a thumb. Hey, wait a minute!";
            }
            else {
                cout << "The THUMB DRIVE is safely tucked away in your INVENTORY.";
            }
        }

        else if ((item == "TREE") || (item == "TREES")) {
            cout << "The trees stand tall and proud. Safe havens to innumerable students, they tirelessly provide shade during even the sunniest of days." << endl;
            cout << "You wish you knew the species. Oak, maybe?";
        }
        else if (item == "SIDEWALK") {
            cout << "The SIDEWALK is grey and has a few cracks in it. Walking on it feels like any other sidewalk. Not really sure what you expected.";
        }
        else {
            cout << "Now is not the time for examining " << item << ".";
        }
    }

    if (room == "fountain") {
         if (item == "PLAQUE") {
            cout << "The bronze PLAQUE reads, " << endl;
            cout << "       \"INTERNATIONAL FOUNTAIN OF KNOWLEDGE" << endl;
            cout << "                  DEDICATED TO            " << endl;
            cout << "          A PROUD AND CONCERNED AMERICAN  " << endl;
            cout << "           LOYAL TO HIS MEXICAN HERITAGE  " << endl;
            cout << "       A BENEFACTOR OF COLLEGE OF THE DESERT" << endl;
            cout << "            DR. REYNALDO J. CARREON JR.   " << endl;
            cout << "                  AND HIS FAMILY          " << endl;
            cout << "                 OCTOBER 12, 1984\"         " << endl;
         }

         else if (item == "PENNY") {
            int i;
            int pennyTaken;
            for (i = 0; i < inventory.size(); ++i) {
                if (inventory.at(i) == "PENNY") {
                    pennyTaken = 1;
                }
                else {
                    pennyTaken = 0;
                }
            }

            if (pennyTaken != 1) {
                cout << "An American PENNY, stamped with the likeness of Abraham Lincoln.";
            }
            else {
                cout << "The unmistakable sense of luck that you feel is enough to tell you that the PENNY is already in your possession.";
            }
        }
        else {
            cout << "Now is not the time for examining " << item << ".";
        }
    }
    //return;

    if (room == "communications") {
        if ((item == "AC") || (item == "AC UNIT") || (item == "AIR CONDITIONING") ||(item == "AIR CONDITIONER") ||(item == "AIR CONDITIONING UNIT")) {
            cout << "You can't explain it. Maybe it was all the hot summer days where you found sancuary in here. Maybe it's supernatural.";
            cout << "Whatever it is, the AIR CONDITIONING UNIT in here was touched by an angel.";
        }
        else if ((item == "WHITEBOARD") || (item == "WHITE BOARD")) {
            cout << "The WHITEBOARD is covered in long, complex equations. Whatever class this was, it was clearly very high-level." << endl;
            cout << "A student has drawn an inappropriate picture in the bottom right corner.";
        }
        else if ((item == "DESK") || (item == "TEACHER'S DESK")) {
            cout << "The desk has papers strewn about. Whoever was here seems to have left in a hurry. Recognizing the fact that you're projecting" << endl;
            cout << "human emotions onto an inanimate object, you can't help but think that it looks kind of lonely without a teacher.";
        }
        else if (item == "COMPUTER") {
            cout << "You hear the hum of the COMPUTER fans coming from the tower. The monitor is glowing bright blue, with nothing on screen.";
        }
        else {
            cout << "Now is not the time for examining " << item << ".";
        }
    }

        if (room == "bookstore") {
        if ((item == "BOOK") || (item == "BOOKS")) {
            cout << "There are all sorts of books here! Math books, English books, Kinesiology books -- lots of Kinesiology books.";
            cout << "Sometimes, the publishers will put one of their textbooks on sale for as low as $400.";
        }
        else if ((item == "PAPER") || (item == "PAPERS")) {
            cout << "Lined paper, unlined paper, graph paper, graph paper with smaller squares, graph paper with bigger squares, graph paper " << endl;
            cout << "with long horizontal squares, even graph paper with no squares at all! Wait...";
        }
        else if ((item == "BINDER") || (item == "BINDERS")) {
            cout << "Binders for holding all of your work. It's amazing just how much space two covers and three rings can occupy.";
        }
        else if ((item == "PRINTER") || (item == "PRINTERS")) {
            cout << "You once asked an employee here how many PRINTERS they actually sell. They said around one per semester, which still seems generous to you.";
        }
        else if ((item == "COUNTER") || (item == "CHECKOUT COUNTER") || (item == "CHECK OUT COUNTER")) {
            cout << "It's a CHECKOUT COUNTER. You've checked out many an item at this very COUNTER.";
        }
        else if ((item == "FOUNTAIN PEN") || (item == "PEN")) {
            if (ItemHasBeenTaken(inventory, "PEN") == false) {
                cout << "The FOUNTAIN PEN on the counter is copper-colored and is lined with intricate, swirling designs. It has a small tag attached" << endl;
                cout << "to it that reads \"$30.00\". Sheesh. If there is a god out there, he really did not want to implement a whole money system." << endl;
                cout << "It is a really pretty PEN, though...";
            }
            else {
                cout << "You're down $30, but the weight of the FOUNTAIN PEN in your INVENTORY makes you feel a little better.";
            }
        }
        else {
            cout << "Now is not the time for examining " << item << ".";
        }
    }

     if (room == "vending") {
        if ((item == "CANDY") || (item == "CANDY BAR")) {
            cout << "The CANDY BAR that has caught your eye is made of decadent, factory-processed chocolate. It is equal parts delicious and threatening. $1.49.";
        }
        else if (item == "DIAL PAD") {
            cout << "The DIAL PAD has keys for the letters A to E and the numbers 0 to 9, allowing you to select an array of different items.";
        }
        else if (item == "SCREEN") {
            cout << "The LCD SCREEN tells you that someone had already put 1 dollar and 48 cents into the machine before leaving. Score!";
        }
        else {
            cout << "Now is not the time for examining " << item << ".";
        }
    }

    if (room == "cafe") {
        if ((item == "TABLE") || (item == "TABLES")) {
            cout << "You've spent hours at these TABLES chatting with people, eating, doing homework. BEEPS is like home, if home was a CAFE in your school.";
        }
        else if ((item == "CHAIR") || (item == "CHAIRS")) {
            cout << "The CHAIRS here come in various shapes and sizes, depending on the table. They all serve the same basic purpose, though.";
        }
        else if ((item == "SODA MACHINE") || (item == "SOFT DRINK MACHINE") || (item == "DRINK MACHINE")) {
            cout << "The SOFT DRINK MACHINE has plenty of options to choose from. You can mix them all together if you're feeling really crazy.";
        }
        else if (item == "ICE") {
            cout << "ICE sits in the SODA MACHINE, barely melted... whoever was here last must have left not long before you arrived.";
        }
        else if (item == "GARLIC") {
            cout << "Garlic, just a clove. A heavy-handed reference to ZORK. It had to happen eventually.";
        }
        else {
            cout << "Now is not the time for examining " << item << ".";
        }
    }

    if (room == "library") {
        if ((item == "PRINTER") || (item == "PRINTERS")) {
            cout << "The PRINTERS are reliable and fast, perfect for last minute assignments. The paper is always warm when it finished printing." << endl;
            cout << "You find this oddly comforting.";
        }
        else if ((item == "BOOK") || (item == "BOOKS")) {
            cout << "Nonfiction, fiction, mystery, sci-fi, biography, reference, self-help, poetry... If you're interested in a subject, chances are" << endl;
            cout << "the libarary has a BOOK for you.";
        }
        else if ((item == "SKYLIGHT") || (item == "SKY LIGHT")) {
            cout << "The glass SKYLIGHT on the ceiling gives the entire place a very fancy, sophisticated look. Plus, a little vitamin D never hurt anyone.";
        }
        else if (item == "TERMINAL") {
            cout << "Yeah, this definitely wasn't here before. The TERMINAL is on; the dark green screen and vintage keyboard look like they were made " << endl;
            cout << "sending secret messages. The blinking cursor suggests that you can input a password.";
        }
        else {
            cout << "Now is not the time for examining " << item << ".";
        }
    }

    if (room == "puzzle") {
        if ((item == "TORCH") || (item == "TORCHES")) {
            cout << "Flickering TORCHES along the walls cast a glow over the whole room. You make sure to be extra careful around them." << endl;
            cout << "You find this oddly comforting.";
        }
        else if ((item == "SHELF") || (item == "SHELVES")) {
            cout << "The wooden SHELVES have words carved into them in an unknown language. Books on magic, plants floating in jars of liquid, and strange crystals" << endl;
            cout << "line them.";
        }
        else if ((item == "POTION") || (item == "POTIONS")) {
            cout << "The POTIONS are in bottles of all shapes and sizes. Some cast a dull glow around them. You find no correlation between color and bottle shape.";
        }
        else if ((item == "IDOL") || (item == "IDOLS")) {
            cout << "Stone IDOLS sit in each corner, facing towards you. Oh wait, they're roadrunners! That's cute.";
        }
        else if ((item == "BOWL") || (item == "BOWLS")) {
            cout << "Two bronze BOWLS of equal size are attached to levers coming out of the wall. It would seem that they require a perfect balance of sorts.";
        }
        else {
            cout << "Now is not the time for examining " << item << ".";
        }
    }
}
