#ifndef SAVESYSTEM_H
#define SAVESYSTEM_H

#include "../pet/Pet.h"
void Save(const Pet &p);
Pet Load();
bool FileExist();
void finishGame(int coins, int happiness, int hunger, int energy);
void checkPetDeath(Pet &p);

#endif