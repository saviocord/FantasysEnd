#include "monster.h"

std::string Monster::img_monster_die = "Images/PNG/cursorSword_bronze.png";
int Monster::quantity_monster = 0;
int Monster::all_is_walking = 0;
int Monster::cont_monster = 0;
int Monster::max_item = 5;

Monster::Monster(int new_level_monster,
                 int new_hp, int new_mp,
                 int new_damage, int new_guard,
                 int new_speed, int new_accuracy,
                 int new_dodge, int new_range_damage,
                 int new_critical, int new_pos_i,
                 int new_pos_j, std::string new_img_way,
                 std::string new_img_battle,
                 Direction new_eye_direction = DOWN) : Character(new_speed, new_accuracy,
                                                                   new_dodge, new_range_damage,
                                                                   new_critical, new_pos_i,
                                                                   new_pos_j, new_img_way,
                                                                   new_img_battle, new_eye_direction),
                                                                   player(NULL), monster_level(new_level_monster)
{
    hp = hp_max = new_hp;
    mp = mp_max = new_mp;
    damage = new_damage;
    guard = new_guard;
    quantity_monster++;
    drop_xp = damage * monster_level / 2;
}

Monster::~Monster() {
    quantity_monster --;
}

bool Monster::addItens(Item *new_item)
{
    if (int(itens_list.size()) + 1 < max_item) {
        itens_list.push_back(new_item);
        return true;
    }
    return false;
}

void Monster::update(Map *my_map)
{
    if (all_is_walking) {
        if (all_is_walking < limit)
            monsterUpdate();
    }
    else {
            monsterUpdate();
            walk();
            my_map->updateColision(this);
    }
}


int Monster::getDropXP()
{
    return drop_xp;
}

bool Monster::canAddItem()
{
    if(int(itens_list.size() + 1) < max_item)
        return true;
    return false;
}

std::vector<Item *> Monster::dropItens()
{
    return itens_list;
}

int Monster::getMonsterLevel()
{
    return monster_level;
}

void Monster::setStalk(Object *player)
{
    this->player = player;
}

void Monster::move()
{
    switch (walk_direction) {
    case UP:
        pos_i--;
        break;
    case DOWN:
        pos_i++;
        break;

    case LEFT:
        pos_j--;
        break;

    case RIGHT:
        pos_j++;
        break;

    default:
        break;
    }
}

void Monster::setCanGo(bool * can)
{
    can_go = can;
}

void Monster::die(Map *my_map)
{
    my_map->removeAColision(Cordenates(this->pos_i, this->pos_j));
    Chest * chest_temp = new Chest(this->pos_i,this->pos_j,img_monster_die,dropItens());
    my_map->addObjects(chest_temp,Cordenates(this->pos_i,this->pos_j));
}

void Monster::setImgMonsterDie(string new_img_die)
{
    img_monster_die = new_img_die;
}

bool Monster::getMonsterIsWalking()
{
    return all_is_walking;
}

void Monster::monsterUpdate()
{
    if (cont_monster < (quantity_monster - 1))
        cont_monster++;
    else {
        cont_monster = 0;
        all_is_walking++;
        if(all_is_walking == limit) {//isso pode estar errado. Confira se necessario! Não tá :D
            all_is_walking = 0;
        }
    }
}

int Monster::getCont()
{
    return all_is_walking;
}

int Monster::getContMonster()
{
    return all_is_walking;
}
