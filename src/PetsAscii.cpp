#include <iostream>
using namespace std;
#include "PetsASCII.h"

/**
 * This script will show the pets as an ASCII art
 */

void ShowOwl()
{
    cout << R"(
                __              __
                \ `-._......_.-` /
                 `.  '.    .'  .'
                  //  _`\/`_  \\
                 ||  /\O||O/\  ||
                 |\  \_/||\_/  /|
                 \ '.   \/   .' /
                 / ^ `'~  ~'`   \
                /  _-^_~ -^_ ~-  |
                | / ^_ -^_- ~_^\ |
                | |~_ ^- _-^_ -| |
                | \  ^-~_ ~-_^ / |
                \_/;-.,____,.-;\_/
         ==========(_(_(==)_)_)=========
    )";
}

void ShowSquirrel()
{
    cout << R"(
                 (\__/)  .~    ~. ))
                 /O O  ./      .'
                {O__,   \    {
                  / .  . )    \
                  |-| '-' \    }
                 .(   _(   )_.'
                '---.~_ _ _&    
    )";
}
