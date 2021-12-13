#ifndef EXAMINETAKEHEADER_H_INCLUDED
#define EXAMINETAKEHEADER_H_INCLUDED

#include <string>
#include <vector>

using namespace std;

void ExamineCommand(string room, string item, vector<string>&inventory);

void TakeCommand(string room, string item, vector<string>&inventory);

void UseCommand(string room, string item, vector<string>&inventory, vector<string>&usedItemsList);

#endif // EXAMINETAKEHEADER_H_INCLUDED


