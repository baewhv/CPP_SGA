#include "framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	myCircle1 = make_shared<CircleCollider>(Vector(100, 100), 100);
	myCircle2 = make_shared<CircleCollider>(Vector(400, 400), 100);
}

CollisionScene::~CollisionScene()
{
}

void CollisionScene::Update()
{
	myCircle1->Center() = mousePos;

	if (myCircle2->IsCollision(myCircle1))
		myCircle2->SetRed();
	else
		myCircle2->SetGreen();
	myCircle1->Update();
	myCircle2->Update();
	
}

void CollisionScene::Render(HDC hdc)
{

	myCircle1->Render(hdc);
	myCircle2->Render(hdc);

}
