#include <iostream>
#include <string>
#include <vector>

#include "ExamineTakeHeader.h"
#include "GetCommandAndItemHeader.h"
#include "ItemHasBeenTakenHeader.h"

using namespace std;

string CommandPrompt();

void ParkingLot();
void CampusEntrance();
void FountainOfKnowledge();
void Bookstore();
void CommunicationsBuilding();
void Library();
void BeepsCafe();
void VendingMachine();
void PuzzleRoom();
void Hallway();

string userCommand;

string currentRoom;

void HelpCommand();
void InventoryCommand(vector<string>inventory);

vector<string> userInventory {"THIRTY DOLLARS"};
vector<string> usedItemsList;

bool itemHasBeenUsedMain(string usedItem, vector<string>itemList);

int hasMoved = 0;
int i;

int main()
{


    cout << "Welcome to ADVENTURES IN COMMUNITY COLLEGE, a text adventure by CHRISTIAN RODRIGUEZ!" << endl;
    cout << "By playing this game, you are sure to gain the full COMMUNITY COLLEGE experience, right from the comfort of your home." << endl << endl;
    cout << "You may type commands to execute an action. Some actions will require a single word, like 'look', but others will require" << endl;
    cout << "two commands (for example, to TAKE a BOOK, you would type 'take book'). CAPITALIZED words often distinguish important OBJECTS" << endl;
    cout << "that can be EXAMINED or TAKEN. However, your commands do not have to be capitalized." << endl;
    cout << "Once you start the adventure, you may type HELP at any time to view the full list of commands and a description of each." << endl << endl;

    cout << "Ready to begin your journey? Type START to enter the PARKING LOT.";

    string startAction;
    cout << endl << endl << "ENTER COMMAND >> ";
    cin >> startAction;

    int i;
    for (i = 0; i < startAction.size(); ++i) {
        startAction[i] = toupper(startAction[i]);
    }

    while (startAction != "START") {
        cout << endl << "Type START to enter the PARKING LOT.";
        cout << endl << endl << "ENTER COMMAND >> ";
        cin >> startAction;
        int i;
        for (i = 0; i < startAction.size(); ++i) {
        startAction[i] = toupper(startAction[i]);
        }
    }

    ParkingLot();

    return 0;
}

string CommandPrompt() {
    string action;
    cout << endl << endl << "ENTER COMMAND >> ";
    cin.clear();
    cin.sync();
    //i don't actually know what those last two lines do, but getline wasn't waiting for input so i googled it and found out
    //that you need those if you want to mix cin with getline.
    getline(cin, action);

    int i;
    for (i = 0; i < action.size(); ++i) {
        action[i] = toupper(action[i]);
    }

    return action;
}

void ParkingLot() {
    currentRoom = "parking";
    hasMoved = 0;
    cout << endl;
    cout << "PARKING LOT" << endl;
    cout << "    After parking in your favorite PARKING SPOT, you exit your CAR and take in the sight of the iconic LOT 28." << endl;
    cout << "    A large STRUCTURE overhead faithfully provides you shelter from the elements." << endl;
    cout << "    The parking spaces are painted extra wide to accommodate the questionable parking skills of its many students." << endl << endl;
    cout << "    NORTH of you is the COLLEGE OF THE DESERT campus. You're not sure if it's actually north because the school map doesn't" << endl;
    cout << "    label the cardinal directions, but that is of little importance to you right now. More concerning is that, upon looking " << endl;
    cout << "    around, you notice that your car is the only one in the parking lot." << endl;
    cout << "    It is eerily quiet.";



    while (hasMoved != 1) {

        string userInput = CommandPrompt();

        userCommand = GetUserCommand(userInput);

        if (userCommand == "HELP") {
            hasMoved = 0;
            HelpCommand();
        }

        else if (userCommand == "INVENTORY") {
            hasMoved = 0;
            InventoryCommand(userInventory);
        }


        else if (userCommand == "NORTH") {
            hasMoved = 1;
            cout << "You walk NORTH, and step into the CAMPUS ENTRANCE." << endl << endl;
            CampusEntrance();
        }

        else if ((userCommand == "EAST" || (userCommand == "WEST") || (userCommand == "SOUTH"))) {
            hasMoved = 0;
            cout << "On your " << userCommand << " side is more empty parking spaces. Not a soul is in sight.";
        }

        else if (userCommand == "LOOK") {
            hasMoved = 0;
            ParkingLot();
        }

        else if (userCommand == "EXAMINE") {
            hasMoved = 0;
            ExamineCommand(currentRoom, GetUserItem(userInput), userInventory);
        }

        else if (userCommand == "TAKE") {
            hasMoved = 0;
            TakeCommand(currentRoom, GetUserItem(userInput), userInventory);
        }
        else if (userCommand == "USE") {
            hasMoved = 0;
            UseCommand(currentRoom,GetUserItem(userInput), userInventory, usedItemsList);
        }
        else {
            hasMoved = 0;
            cout << "Command not recognized. Try again.";
        }

    }
    return;
}

void CampusEntrance() {
    currentRoom = "campus";
    hasMoved = 0;
    cout << endl;
    cout << "CAMPUS ENTRANCE" << endl;
    cout << "    You head NORTH and step foot onto the beautiful COLLEGE OF THE DESERT campus. It is truly the community college of your dreams." << endl;
    cout << "    It feels like the first time in years -- in fact, you had begun to miss it so much that you almost considered making" << endl;
    cout << "    an entire TEXT ADVENTURE video game based on it. Yikes!" << endl;
    cout << "    Large buildings surround you on all sides. Small PLANTS and TREES line the SIDEWALK. The air smells of education." << endl << endl;

    cout << "    Looking WEST, you see the COMMUNICATIONS BUILDING, where you once took an English class. There air conditioning in there is great." << endl;
    cout << "    To your EAST, is the CRAVENS STUDENT SERVICES CENTER. It houses the BOOKSTORE, where you buy the textbooks you can't pirate online." << endl;
    cout << "    On your SOUTH side is the LOT 28 PARKING LOT where your car is parked." << endl;
    cout << "    You instantly notice that you don't see a single student on campus. The contrast from the usual hustle and bustle is unsettling." << endl;
    cout << "    The only sound you hear is the water running through a FOUNTAIN to your NORTH.";

    while (hasMoved != 1) {

        string userInput = CommandPrompt();

        userCommand = GetUserCommand(userInput);

        if (userCommand == "HELP") {
            hasMoved = 0;
            HelpCommand();
        }

        else if (userCommand == "INVENTORY") {
            hasMoved = 0;
            InventoryCommand(userInventory);
        }


        else if (userCommand == "NORTH") {
            hasMoved = 1;
            cout << "Moving NORTH, you approach the lonely FOUNTAIN." << endl << endl;
            FountainOfKnowledge();
        }

        else if (userCommand == "EAST") {
            hasMoved = 1;
            cout << "You decide to go EAST. After entering the CRAVENS STUDENT SERVICES CENTER, you throw open the doors to the BOOKSTORE and step inside." << endl << endl;
            Bookstore();
        }

        else if (userCommand == "WEST") {
            hasMoved = 1;
            cout << "You begin walking WESTWARD towards the COMMUNICATIONS CENTER. The automatic doors silently slide open for you." << endl << endl;
            CommunicationsBuilding();
        }

        else if (userCommand == "SOUTH") {
            hasMoved == 1;
            cout << "You head back SOUTH to the PARKING LOT. You're not ready to go home yet, so perhaps you just miss the STRUCTURE." << endl << endl;
            ParkingLot();
        }

        else if (userCommand == "LOOK") {
            hasMoved = 0;
            CampusEntrance();
        }

        else if (userCommand == "EXAMINE") {
            hasMoved = 0;
            ExamineCommand(currentRoom, GetUserItem(userInput), userInventory);
        }

        else if (userCommand == "TAKE") {
            hasMoved = 0;
            TakeCommand(currentRoom, GetUserItem(userInput), userInventory);
        }

        else if (userCommand == "USE") {
            hasMoved = 0;
            UseCommand(currentRoom,GetUserItem(userInput), userInventory, usedItemsList);
        }

        else {
            hasMoved = 0;
            cout << "Command not recognized. Try again.";
        }

    }
    return;
}

void FountainOfKnowledge() {
    currentRoom = "fountain";
    hasMoved = 0;
    cout << endl;
    cout << "FOUNTAIN OF KNOWLEDGE" << endl;
    cout << "    You walk to the FOUNTAIN OF KNOWLEDGE. You can practically feel the knowledge eminating from it." << endl;
    cout << "    The fountain is huge, and you've never actually seen it running before. In fact, you've never even really noticed it." << endl;
    cout << "    The sound of the water splashing soothes your nerves. A small PLAQUE is visible at the foot of the fountain." << endl;
            if (ItemHasBeenTaken(userInventory, "PENNY") == false) {
                cout << "    Looking inside the fountain, you see a single PENNY.";
            }
    cout << endl << endl;
    cout << "    You can't see it from where you are, but if you walk far enough to the NORTH, you'll eventually end up at the LIBRARY." << endl;
    cout << "    To your EAST is BEEPS CAFE. Perfect for hanging out and getting something to eat in between classes." << endl;
    cout << "    To the WEST is a trusty vending machine, filled with all the snacks you could ever want." << endl;
    cout << "    SOUTH of you is the CAMPUS ENTRANCE. You can go all sorts of places from there." << endl;
    cout << "    You call out a loud \"hello\", hoping to get a response from a fellow student, but you receive no reply." << endl;

    while (hasMoved != 1) {

        string userInput = CommandPrompt();

        userCommand = GetUserCommand(userInput);

        if (userCommand == "HELP") {
            hasMoved = 0;
            HelpCommand();
        }

        else if (userCommand == "INVENTORY") {
            hasMoved = 0;
            InventoryCommand(userInventory);
        }


        else if (userCommand == "NORTH") {
            hasMoved = 1;
            cout << "You decide to head NORTH, making the arduious treck to the LIBRARY." << endl << endl;
            Library();
        }

        else if (userCommand == "EAST") {
            hasMoved = 1;
            cout << "Maybe you'll find another student in BEEPS CAFE! Or, worst case scanario, you can find something to eat." << endl;
            cout << "You head EAST to check it out." << endl << endl;
            BeepsCafe();
        }

        else if (userCommand == "WEST") {
            hasMoved = 1;
            cout << "You walk to your WEST towards the VENDING MACHINE. Lots of goodies in there. Maybe you can buy a snack for later." << endl << endl;
            VendingMachine();
        }

        else if (userCommand == "SOUTH") {
            hasMoved == 1;
            cout << "You decide to go SOUTH, back towards the campus entrance." << endl << endl;
            CampusEntrance();
        }

        else if (userCommand == "LOOK") {
            hasMoved = 0;
            FountainOfKnowledge();
        }

        else if (userCommand == "EXAMINE") {
            hasMoved = 0;
            ExamineCommand(currentRoom, GetUserItem(userInput), userInventory);
        }

        else if (userCommand == "TAKE") {
            hasMoved = 0;
            TakeCommand(currentRoom, GetUserItem(userInput), userInventory);
        }

        else if (userCommand == "USE") {
            hasMoved = 0;
            UseCommand(currentRoom,GetUserItem(userInput), userInventory, usedItemsList);
        }

        else {
            hasMoved = 0;
            cout << "Command not recognized. Try again.";
        }
    }
}

void Bookstore() {
    currentRoom = "bookstore";
    hasMoved = 0;
    cout << endl;
    cout << "BOOKSTORE" << endl;
    cout << "    You enter the small BOOKSTORE and admire the wide collection of assorted wares within." << endl;
    cout << "    BOOKS for every subject stock the shelves. You also spy various varities of PAPER, and some BINDERS." << endl;

    if (ItemHasBeenTaken(userInventory, "FOUNTAIN PEN") == false) {
        cout << "    In front of you is the CHECKOUT COUNTER, on which lies a beautiful FOUNTAIN PEN. Behind the COUNTER are some PRINTERS for sale." << endl;
    }
    else {
        cout << "    In front of you is the CHECKOUT COUNTER. Behind it are some PRINTERS for sale." << endl;
    }

    cout << "    Usually, there is a student manning the CHECKOUT COUNTER. Today, there is no one else in the store at all." << endl << endl;
    cout << "    If you go WEST, you can exit the BOOKSTORE and the CRAVENS STUDENT SERVICES CENTER, taking you back to the CAMPUS ENTRANCE.";


    while (hasMoved != 1) {

        string userInput = CommandPrompt();

        userCommand = GetUserCommand(userInput);

        if (userCommand == "HELP") {
            hasMoved = 0;
            HelpCommand();
        }

        else if (userCommand == "INVENTORY") {
            hasMoved = 0;
            InventoryCommand(userInventory);
        }


        else if (userCommand == "WEST") {
            hasMoved = 1;
            cout << "You exit the BOOKSTORE, walk out of the CRAVENS STUDENT SERVICES CENTER, and return to the CAMPUS ENTRANCE." << endl << endl;
            CampusEntrance();
        }

        else if ((userCommand == "NORTH" || (userCommand == "EAST") || (userCommand == "SOUTH"))) {
            hasMoved = 0;
            cout << "There are no additional doors to your " << userCommand << ", just more of the store." << endl << endl;
        }

        else if (userCommand == "LOOK") {
            hasMoved = 0;
            Bookstore();
        }

        else if (userCommand == "EXAMINE") {
            hasMoved = 0;
            ExamineCommand(currentRoom, GetUserItem(userInput), userInventory);
        }

        else if (userCommand == "TAKE") {
            hasMoved = 0;
            TakeCommand(currentRoom, GetUserItem(userInput), userInventory);
        }
        else if (userCommand == "USE") {
            hasMoved = 0;
            UseCommand(currentRoom,GetUserItem(userInput), userInventory, usedItemsList);
        }
        else {
            hasMoved = 0;
            cout << "Command not recognized. Try again.";
        }

    }
    return;
}

void CommunicationsBuilding() {
    currentRoom = "communications";
    hasMoved = 0;
    cout << endl;
    cout << "COMMUNICATIONS BUILDING" << endl;
    cout << "    Upon entering the COMMUNICATIONS BUILDING, you instantly feel the cool air hit your face. That particular AC unit just hits different." << endl;
    cout << "    You walk through the door of an empty CLASSROOM. A large WHITEBOARD takes up the entire wall to your right." << endl;
    cout << "    In the upper left corner of the room, there is a teacher's DESK. In the center of the room, a single COMPUTER is turned on." << endl << endl;
    cout << "    The only exit is to your EAST, leading back to the CAMPUS ENTRANCE.";

    while (hasMoved != 1) {

        string userInput = CommandPrompt();

        userCommand = GetUserCommand(userInput);

        if (userCommand == "HELP") {
            hasMoved = 0;
            HelpCommand();
        }

        else if (userCommand == "INVENTORY") {
            hasMoved = 0;
            InventoryCommand(userInventory);
        }


        else if (userCommand == "EAST") {
            hasMoved = 1;
            cout << "Bidding the air conditioning fairwell, you go EAST, back to the CAMPUS ENTRANCE." << endl << endl;
            CampusEntrance();
        }

        else if ((userCommand == "NORTH" || (userCommand == "WEST") || (userCommand == "SOUTH"))) {
            hasMoved = 0;
            cout << "The classroom does not have any additional rooms to the " << userCommand << "." << endl << endl;
        }

        else if (userCommand == "LOOK") {
            hasMoved = 0;
            CommunicationsBuilding();
        }

        else if (userCommand == "EXAMINE") {
            hasMoved = 0;
            ExamineCommand(currentRoom, GetUserItem(userInput), userInventory);
        }

        else if (userCommand == "TAKE") {
            hasMoved = 0;
            TakeCommand(currentRoom, GetUserItem(userInput), userInventory);
        }
        else if (userCommand == "USE") {
            hasMoved = 0;
            UseCommand(currentRoom,GetUserItem(userInput), userInventory, usedItemsList);
        }
        else {
            hasMoved = 0;
            cout << "Command not recognized. Try again.";
        }

    }
    return;
}

void Library() {
    currentRoom = "library";
    hasMoved = 0;
    cout << endl;
    cout << "LIBRARY" << endl;
    cout << "    After what feels like hours of walking, you arrive at the beautiful LIBRARY. The automatic doors activate, and you walk inside." << endl;
    cout << "    You have written so many essays here an hour before they were due, and the PRINTERS never once failed you." << endl;
    cout << "    There are BOOKS everywhere, free to check out with a trusty library card. The glass SKYLIGHT allows sunlight to shine down onto you." << endl;
    cout << "    A TERMINAL with a glowing green screen sits in the middle of the room. That's definitely new." << endl;

    if (itemHasBeenUsedMain("SECRET CODE", usedItemsList) == true) {
        cout << "Further NORTH, a large panel has slid away, revealing a staircase leading downwards.";
    }
    cout << "    The silence doesn't feel so strange here." << endl << endl;
    cout << "    If you head SOUTH, you can return to the FOUNTAIN OF KNOWLEDGE.";

    while (hasMoved != 1) {

        string userInput = CommandPrompt();

        userCommand = GetUserCommand(userInput);

        if (userCommand == "HELP") {
            hasMoved = 0;
            HelpCommand();
        }

        else if (userCommand == "INVENTORY") {
            hasMoved = 0;
            InventoryCommand(userInventory);
        }


        else if (userCommand == "SOUTH") {
            hasMoved = 1;
            cout << "You decide to make the walk all the way back to the FOUNTAIN OF KNOWLEDGE to the SOUTH. This takes a while." << endl << endl;
            FountainOfKnowledge();
        }

        else if ((userCommand == "WEST") || (userCommand == "EAST")) {
            hasMoved = 0;
            cout << userCommand << " of you, there are bookshelves lined with dozens upon dozens of books." << endl << endl;
        }

        else if (userCommand == "NORTH") {
            if (itemHasBeenUsedMain("SECRET CODE", usedItemsList) == true) {
                cout << "Walking NORTH, you slowly head down the staircase, into the underground. Here goes nothing.";
                PuzzleRoom();
            }
            else {
                cout << "To your NORTH is not anything interesting, but the floor does look slightly different than usual. Make of that what you will.";
            }
        }

        else if (userCommand == "LOOK") {
            hasMoved = 0;
            Library();
        }

        else if (userCommand == "EXAMINE") {
            hasMoved = 0;
            ExamineCommand(currentRoom, GetUserItem(userInput), userInventory);
        }

        else if (userCommand == "TAKE") {
            hasMoved = 0;
            TakeCommand(currentRoom, GetUserItem(userInput), userInventory);
        }
        else if (userCommand == "USE") {
            hasMoved = 0;
            UseCommand(currentRoom,GetUserItem(userInput), userInventory, usedItemsList);
        }
        else {
            hasMoved = 0;
            cout << "Command not recognized. Try again.";
        }

    }
}

    void PuzzleRoom() {
        currentRoom = "puzzle";
        hasMoved = 0;
        cout << endl;
        cout << "MYSTERIOUS CHAMBER" << endl;
        cout << "    At the end of the staircase is a MYSTERIOUS CHAMBER. TORCHES line the walls. SHELVES are filled with ancient magical texts." << endl;
        cout << "    Mist escapes from bottles holding POTIONS of all different colors. Stone IDOLS representing ancient bird gods are in each corner." << endl;
        cout << "    In front of you are two BOWLS. There is writing on the wall above them:" << endl;
        cout << "            \"YOU HAVE SHOWN FANTASTIC TALENTS..." << endl;
        cout << "             BUT CAN YOU FIND A PERFECT BALANCE?\" " << endl;
        cout << "    Perhaps this MYSTERIOUS CHAMBER once belonged to Shakespeare himself.";
        if ((itemHasBeenUsedMain("CANDY BAR", usedItemsList) == true) && (itemHasBeenUsedMain("GARLIC", usedItemsList)== true)) {
                    cout << "The wall with the BOWLS to your NORTH has opened up to reveal a MYSTERIOUS PASSAGEWAY.";
                    Hallway();
                }
        cout << endl << endl;
        cout << "    It's not too late to go SOUTH, back up the staircase.";

        while (hasMoved != 1) {

            string userInput = CommandPrompt();

            userCommand = GetUserCommand(userInput);

            if (userCommand == "HELP") {
                hasMoved = 0;
                HelpCommand();
            }

            else if (userCommand == "INVENTORY") {
                hasMoved = 0;
                InventoryCommand(userInventory);
            }


            else if (userCommand == "SOUTH") {
                hasMoved = 1;
                cout << "As cool as the MYSTERIOUS CHAMBER is, you decide to go SOUTH, back up the staircase and into the LIBRARY." << endl << endl;
                Library();
            }

            else if ((userCommand == "WEST") || (userCommand == "EAST")) {
                hasMoved = 0;
                cout << userCommand << " of you, there are bookshelves lined with dozens upon dozens of books." << endl << endl;
            }

            else if (userCommand == "NORTH") {
                if ((itemHasBeenUsedMain("CANDY BAR", usedItemsList) == true) && (itemHasBeenUsedMain("GARLIC", usedItemsList)== true)) {
                    cout << "Pleased with your work, you go through the opening to your NORTH and enter the MYSTERIOUS PASSAGEWAY.";
                    Hallway();
                }
                else {
                    cout << "To your NORTH are the two mysterious BOWLS.";
                }
            }

            else if (userCommand == "LOOK") {
                hasMoved = 0;
                Library();
            }

            else if (userCommand == "EXAMINE") {
                hasMoved = 0;
                ExamineCommand(currentRoom, GetUserItem(userInput), userInventory);
            }

            else if (userCommand == "TAKE") {
                hasMoved = 0;
                TakeCommand(currentRoom, GetUserItem(userInput), userInventory);
            }
            else if (userCommand == "USE") {
                hasMoved = 0;
                UseCommand(currentRoom,GetUserItem(userInput), userInventory, usedItemsList);
            }
            else {
                hasMoved = 0;
                cout << "Command not recognized. Try again.";
            }
        }
    }

void Hallway() {
    currentRoom = "hallway";
    hasMoved = 0;
    cout << endl;
    cout << "MYSTERIOUS PASSAGEWAY" << endl;
    cout << "    You find yourself in a simple stone passageway. It splits into three different paths with labels written above them." << endl;
    cout << "    To your WEST, the tunnel is labeled \"GOLD.\"" << endl;
    cout << "    To your NORTH, the tunnel is labeled \"LOVE.\"" << endl;
    cout << "    To your EAST, the tunnel is labeled \"FAME.\"" << endl << endl;
    cout << "    If for some reason you REALLY want to turn back now, I guess you could still go SOUTH, back to the MYSTERIOUS CHAMBER.";

    while (hasMoved != 1) {

        string userInput = CommandPrompt();

        userCommand = GetUserCommand(userInput);

        if (userCommand == "HELP") {
            hasMoved = 0;
            HelpCommand();
        }

        else if (userCommand == "INVENTORY") {
            hasMoved = 0;
            InventoryCommand(userInventory);
        }


        else if (userCommand == "NORTH") {
            hasMoved = 1;
            cout << "You walk into the NORTHERN tunnel -- LOVE. You walk down the hall and find a room that is completely empty except for a piece of paper." << endl;
            cout << "The paper reads, \"Maybe, the real love was within you all along. P.S. Everyone is back at COD, thank you for saving them.\"" << endl;
            cout << "That's kind of cute, I guess. You're not sure what you expected, but it wasn't that. In any case, you have saved everyone at COD" << endl;
            cout << "through your exploration skills and wit, and for that, you should be very proud. Maybe, you're so proud that you love yourself a little bit more. Right?" << endl << endl;
            cout << "Hi! I'm sorry for the abrupt ending, there had to be three endings to this to get full credit and it is 6:30 AM and I haven't slept." << endl;
            cout << "I really do hope you've enjoyed this little adventure, I had a ton of fun making it and it was truly a labor of love." << endl;
            cout << "Thanks so much for playing. --Christian <3";
        }

        else if (userCommand == "WEST") {
            hasMoved = 1;
            cout << "You walk into the WESTERN tunnel -- GOLD. You walk down the hall and find a room that is completely empty except for a piece of paper." << endl;
            cout << "The paper reads, \"Maybe, the real gold was within you all along. P.S. Everyone is back at COD, thank you for saving them.\"" << endl;
            cout << "What? That doesn't even make sense. You feel kind of ripped off by the ancient wizards that built this place. I guess gold wasn't in the budget." << endl;
            cout << "In any case, you have saved everyone at COD through your exploration skills and wit, and for that, you should be very proud." << endl;
            cout << "That is the most valuable thing of all! Even more valuable than gold, maybe. What's the current value of gold?" << endl << endl;
            cout << "Hi! I'm sorry for the abrupt ending, there had to be three endings to this to get full credit and it is 6:30 AM and I haven't slept." << endl;
            cout << "I really do hope you've enjoyed this little adventure, I had a ton of fun making it and it was truly a labor of love." << endl;
            cout << "Thanks so much for playing. --Christian <3";
        }

        else if (userCommand == "EAST") {
            hasMoved = 1;
            cout << "You walk into the EASTERN tunnel -- FAME. You walk down the hall and find a room that is completely empty except for a piece of paper." << endl;
            cout << "The paper reads, \"Maybe, the being famous was never what you truly wanted. P.S. Everyone is back at COD, thank you for saving them.\"" << endl;
            cout << "You clearly chose this passageway. Why would they assume you didn't want fame? Is there a lesson here that is going over my head?" << endl;
            cout << "Maybe you wouldn't like certain aspects of fame. Maybe that's what they're talking about. But still, they're making a lot of assumptions here." << endl;
            cout << "In any case, you have saved everyone at COD through your exploration skills and wit, and for that, you should be very proud." << endl;
            cout << "Maybe if you tell them your story, you'll be famous among the COD students! If it's any consolation, you're famous to me, in a way." << endl << endl;
            cout << "Hi! I'm sorry for the abrupt ending, there had to be three endings to this to get full credit and it is 6:30 AM and I haven't slept." << endl;
            cout << "I really do hope you've enjoyed this little adventure, I had a ton of fun making it and it was truly a labor of love." << endl;
            cout << "Thanks so much for playing. --Christian <3";
        }

        else if (userCommand == "LOOK") {
            hasMoved = 0;
            Hallway();
        }

        else if (userCommand == "EXAMINE") {
            hasMoved = 0;
            cout << "There is nothing to examine here.";
        }

        else if (userCommand == "TAKE") {
            hasMoved = 0;
            cout << "There is nothing to take here.";
        }
        else if (userCommand == "USE") {
            hasMoved = 0;
            cout << "No need to use anything in here.";
        }
        else {
            hasMoved = 0;
            cout << "Command not recognized. Try again.";
        }

    }
}


void BeepsCafe() {
    currentRoom = "cafe";
    hasMoved = 0;
    cout << endl;
    cout << "BEEPS CAFE" << endl;
    cout << "    EASTWARD bound, decide to try going to BEEPS CAFE. If you're going to find another student, this is definitely the place." << endl;
    cout << "    In addition to being a popular hangout spot, the CAFE is also one of the only places to get food on campus." << endl;
    cout << "    You can't count how many grilled cheeses you've ordered from here. It was the only thing that kept you from withering away on long school days." << endl;
    cout << "    You step into the CAFE and you're instantly greeted by the smell of fried food. There are TABLES and CHAIRS all around, but no one to fill them." << endl;
    cout << "    The SOFT DRINK MACHINE is full of recently discarded ICE. A clove of GARLIC sits on a nearby table." << endl << endl;
    cout << "    Going WEST would take you back to the FOUNTAIN OF KNOWLEDGE.";

    while (hasMoved != 1) {

        string userInput = CommandPrompt();

        userCommand = GetUserCommand(userInput);

        if (userCommand == "HELP") {
            hasMoved = 0;
            HelpCommand();
        }

        else if (userCommand == "INVENTORY") {
            hasMoved = 0;
            InventoryCommand(userInventory);
        }


        else if (userCommand == "WEST") {
            hasMoved = 1;
            cout << "Exiting BEEPS CAFE, you head WEST to the the FOUNTAIN OF KNOWLEDGE. For a second, this almost feels like a regular school day." << endl << endl;
            FountainOfKnowledge();
        }

        else if ((userCommand == "NORTH" || (userCommand == "WEST") || (userCommand == "SOUTH"))) {
            hasMoved = 0;
            cout << "To your " << userCommand << " is more of the CAFE. With no other students around, the silence and lack of claustrophobia feels horribly wrong." << endl << endl;
        }

        else if (userCommand == "LOOK") {
            hasMoved = 0;
            BeepsCafe();
        }

        else if (userCommand == "EXAMINE") {
            hasMoved = 0;
            ExamineCommand(currentRoom, GetUserItem(userInput), userInventory);
        }

        else if (userCommand == "TAKE") {
            hasMoved = 0;
            TakeCommand(currentRoom, GetUserItem(userInput), userInventory);
        }
        else if (userCommand == "USE") {
            hasMoved = 0;
            UseCommand(currentRoom,GetUserItem(userInput), userInventory, usedItemsList);
        }
        else {
            hasMoved = 0;
            cout << "Command not recognized. Try again.";
        }

    }
}

void VendingMachine() {
    currentRoom = "vending";
    hasMoved = 0;
    cout << endl;
    cout << "VENDING MACHINE" << endl;
    cout << "    You decide to go to the VENDING MACHINE. Often the quickest source of food between classes, there's no telling how many lives" << endl;
    cout << "    this thing has saved. Looking inside, a CANDY BAR catches your attention. There is a DIAL PAD that provides you the means of" << endl;
    cout << "    selecting your desired snack. The seven segment display on a small SCREEN provides valuable feedback on the current activities of the machine." << endl << endl;
    cout << "    EAST of you, the FOUNTAIN OF KNOWLEDGE continues to fountain knowingly.";

    while (hasMoved != 1) {

        string userInput = CommandPrompt();

        userCommand = GetUserCommand(userInput);

        if (userCommand == "HELP") {
            hasMoved = 0;
            HelpCommand();
        }

        else if (userCommand == "INVENTORY") {
            hasMoved = 0;
            InventoryCommand(userInventory);
        }


        else if (userCommand == "EAST") {
            hasMoved = 1;
            cout << "You've been going to college to get more knowledge, so a whole FOUNTAIN dedicated to it is right up your alley." << endl;
            cout << "Always hungry to learn, you decide to go back EAST to the FOUNTAIN OF KNOWLEDGE." << endl << endl;
            FountainOfKnowledge();
        }

        else if ((userCommand == "NORTH" || (userCommand == "WEST") || (userCommand == "SOUTH"))) {
            hasMoved = 0;
            cout << "To your " << userCommand << " is unexplored territory. That part of campus feels like it belongs to someone else." << endl << endl;
        }

        else if (userCommand == "LOOK") {
            hasMoved = 0;
            VendingMachine();
        }

        else if (userCommand == "EXAMINE") {
            hasMoved = 0;
            ExamineCommand(currentRoom, GetUserItem(userInput), userInventory);
        }

        else if (userCommand == "TAKE") {
            hasMoved = 0;
            TakeCommand(currentRoom, GetUserItem(userInput), userInventory);
        }
        else if (userCommand == "USE") {
            hasMoved = 0;
            UseCommand(currentRoom,GetUserItem(userInput), userInventory, usedItemsList);
        }
        else {
            hasMoved = 0;
            cout << "Command not recognized. Try again.";
        }

    }
}

void InventoryCommand(vector<string> inventory) {
    cout << endl;
    if (inventory.size() == 0) {
        cout << "Your bag is empty.";
    }
    else {
        cout << "INVENTORY: ";
        for (i = 0; i < inventory.size(); ++i) {
            cout << i + 1 << "\) " << inventory.at(i);
            if (i != inventory.size() - 1) {
                cout << ", ";
            }
        }
    }
    return;
}

bool itemHasBeenUsedMain(string usedItem, vector<string>itemList) {
        bool itemUsed = false;
        int i;
        for (i = 0; i < itemList.size(); ++i) {
            if (itemList.at(i) == usedItem) {
                itemUsed = true;
            }
        }
        return itemUsed;
    }

void HelpCommand() {
    cout << endl << endl;
    cout << "COMMANDS allow you to interact with ADVENTURES IN COMMUNITY COLLEGE. The following COMMANDS are available:" << endl;
    cout << "    HELP - shows available commands." << endl;
    cout << "    INVENTORY - lists the items in your inventory." << endl;
    cout << "    NORTH / SOUTH / EAST / WEST - travel in a specific direction." << endl;
    cout << "    LOOK - view your surroundings." << endl;
    cout << "    EXAMINE - typing the name of an OBJECT after this command might allow you to get a closer look." << endl;
    cout << "    TAKE - typing the name of an OBJECT after this command might allow you to add it to your INVENTORY." << endl;
    cout << "    USE - typing the name of an OBJECT after this command while in the correct LOCATION might allow you to use it." << endl;
}

