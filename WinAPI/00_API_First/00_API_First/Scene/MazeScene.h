#pragma once
#include "Scene.h"

class Maze;
class MazeScene :
    public Scene
{
public:
    MazeScene();
    ~MazeScene();

    // Scene��(��) ���� ��ӵ�
    void PostInitialize() override;
    void Update() override;
    void Render(HDC hdc) override;
private:
    //shared_ptr<Block> _block;
    shared_ptr<Maze> _maze;
};

