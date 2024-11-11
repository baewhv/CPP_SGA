#pragma once

class Forest :
    public World
{
public:
    virtual void PlayScene() override;

    void SearchGoblin();
    void AttackGoblin(int count);
    bool CheckResult();
    

private:
    vector<Creature*> goblins;
};

