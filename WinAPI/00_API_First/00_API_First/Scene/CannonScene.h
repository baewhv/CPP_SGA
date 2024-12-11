#pragma once
#include "./Contents/GameObject/Fortress/Cannon.h"

class CannonScene : public Scene
{
public:
	CannonScene();
	~CannonScene();

	void PostInitialize() override ;
	void Update() override;
	void Render(HDC hdc) override;

private:
	shared_ptr<class Cannon> _cannon;

};
