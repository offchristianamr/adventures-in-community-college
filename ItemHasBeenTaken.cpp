#include <vector>
#include <string>

using namespace std;

bool ItemHasBeenTaken(vector<string>inventory, string item) {
    int i;
        bool itemTaken;
        for (i = 0; i < inventory.size(); ++i) {
            if (inventory.at(i) == item) {
                itemTaken = true;
            }
            else if ((inventory.at(i) != item) && (itemTaken != true)) {
                itemTaken = false;
            }
        }

    return itemTaken;
}
