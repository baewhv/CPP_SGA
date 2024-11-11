#pragma once
#include "World.h"
class Cave :
    public World
{
public:
    virtual void PlayScene();

    void AttackBoss();
    bool CheckResult();

private:
    vector<Creature*> Players;
    Boss* _boss;
};

