#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <fstream>
#include "globalfunctions.h"
#include "object.h"
#include "chest.h"
#include "stone.h"
//#include "interation.h"

class Character;
class Stone;

using namespace std;

class Map
{
private:
    string img_way;
    int size_i, size_j;
    int **m_base, **m_s_base, **m_obj, **m_iso, **m_s_iso, **m_col;
    static const int max_chest, min_chest, max_stone, min_stone;
    Object ***m_interation;
    Chest **chest_list;
    Stone **stone_list;
    bool *can_go;

public:
    Map(string new_arch_map, string new_img_way);
    ~Map();
    Cordenates getCordenates();
    bool hasColision(Cordenates cord);
    void updateColision(Character * update_character);
    void setAColision(Cordenates new_col);
    void removeAColision(Cordenates remove_col);
    void randMapInteration();
    //Interation * getInteration(Cordenates cord);
    void addObjects(Object *new_object, Cordenates cord_object);
    void removeObjects(Cordenates cord_remove);
    Object * getObjectMap(Cordenates cord);
    bool * getCanGo(Cordenates cord);
    int ** getColision();
    int ** getBase();
    int ** getSuperBase();
    int ** getObjects();
    int ** getIsometric();
    int ** getSuperIsometric();
    Object ***getMatIteration();
    std::string getImgWay();
};

#endif // MAP0_H
