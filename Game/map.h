#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <fstream>
#include "globalfunctions.h"
#include "object.h"
#include "Character/character.h"

using namespace std;

class Map
{
private:
    string img_way;
    int size_i, size_j;
    int **m_base, **m_s_base, **m_obj, **m_iso, **m_s_iso, **m_col;
    bool *can_go;
public:
    Map(string new_arch_map, string new_img_way);
    ~Map();
    int ** getColision();
    Cordenates getCordenates();
    bool hasColision(Cordenates cord);
    bool * getCanGo(Cordenates cord);
    void updateColision(Character * update_character);
    void setAcolision(Cordenates new_col);
    void removeAcolision(Cordenates remove_col);
};

#endif // MAP0_H
