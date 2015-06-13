#ifndef WALKER_H
#define WALKER_H

#include "Character/Monster/monster.h"

class Walker : public Monster
{
public:
    Walker(int new_hp, int new_mp,
           int new_damage, int new_guard,
           int new_speed, int new_accuracy,
           int new_dodge, int new_range_damage,
           int new_critical, int new_pos_i,
           int new_pos_j, std::string new_img_way,
           std::string new_img_battle,
           Direction new_eye_direction);
    void walk();
};

#endif // WALKER_H
