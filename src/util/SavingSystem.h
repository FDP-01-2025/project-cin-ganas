#ifndef SAVESYSTEM_H
#define SAVESYSTEM_H

#include "../pet/Pet.h"
void Save(const Pet &p);
Pet Load();
bool FileExist();
void addCoins(int coins);

#endif