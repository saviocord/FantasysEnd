#include "battle.h"

const std::string Battle::background_img_way = "Battle/battle.png";
const std::string Battle::cursor_img_way = "Images/PNG/arrowBeige_right.png";
const std::string Battle::cursor_change_sound = "Music/interface1.wav";
const std::string Battle::options_sounds[4] = {"Music/sword-unsheathe2.wav", "", "", ""};
std::string Battle::img_monster = "";

Battle::Battle(Character *fighter_one, Character *fighter_two) :
    attacker_fighter(fighter_one),
    defenser_fighter(fighter_two)
{
    img_monster = defenser_fighter->getImgBatlle();
}

int Battle::attack()
{
    try {
        int atk = attacker_fighter->attack();
        (defenser_fighter)->defense(atk);
        Character *change_fighter = defenser_fighter;
        defenser_fighter = attacker_fighter;
        attacker_fighter = change_fighter;
        return atk;
    } catch (Exceptions exc) {
        if (exc == CHARACTER_DIE) {
            throw defenser_fighter;
        }
        Character *change_fighter = defenser_fighter;
        defenser_fighter = attacker_fighter;
        attacker_fighter = change_fighter;
        throw;
    }
}

void Battle::magicSpecial()
{

}

void Battle::item()
{

}

void Battle::run()
{

}

string Battle::getImgWayMonster()
{
    return img_monster;
}
