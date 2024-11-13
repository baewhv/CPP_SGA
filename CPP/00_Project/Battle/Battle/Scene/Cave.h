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
    vector<shared_ptr<Creature>> Players;
    shared_ptr<Creature> _boss;
    
};

