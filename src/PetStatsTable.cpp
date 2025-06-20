#include <iostream>
using namespace std;
#include "PetStatsTable.h"

/**
 * This script will show the pet stats in a table
 */
void ShowPetStatsTable(string pet, string name, int happiness, int energy, int hunger)
{
    cout << R"(
 ________              __                      __  __              __      __                               
/        |            /  |                    /  |/  |            /  |    /  |                              
$$$$$$$$/   _______  _$$ |_     ______    ____$$ |$$/   _______  _$$ |_   $$/   _______   ______    _______ 
$$ |__     /       |/ $$   |   /      \  /    $$ |/  | /       |/ $$   |  /  | /       | /      \  /       |
$$    |   /$$$$$$$/ $$$$$$/    $$$$$$  |/$$$$$$$ |$$ |/$$$$$$$/ $$$$$$/   $$ |/$$$$$$$/  $$$$$$  |/$$$$$$$/ 
$$$$$/    $$      \   $$ | __  /    $$ |$$ |  $$ |$$ |$$      \   $$ | __ $$ |$$ |       /    $$ |$$      \ 
$$ |_____  $$$$$$  |  $$ |/  |/$$$$$$$ |$$ \__$$ |$$ | $$$$$$  |  $$ |/  |$$ |$$ \_____ /$$$$$$$ | $$$$$$  |
$$       |/     $$/   $$  $$/ $$    $$ |$$    $$ |$$ |/     $$/   $$  $$/ $$ |$$       |$$    $$ |/     $$/ 
$$$$$$$$/ $$$$$$$/     $$$$/   $$$$$$$/  $$$$$$$/ $$/ $$$$$$$/     $$$$/  $$/  $$$$$$$/  $$$$$$$/ $$$$$$$/                                                                                               
                   

)";
    cout << "+-------------------------------+\n";
    cout << "  - Mascota: " << pet << "\n";
    cout << "  - Nombre: " << name << "\n";
    cout << "  - Felicidad: " << happiness << "\n";
    cout << "  - Energia: " << energy << "\n";
    cout << "  - Hambre: " << hunger << "\n";
    cout << "+-------------------------------+\n";
}
