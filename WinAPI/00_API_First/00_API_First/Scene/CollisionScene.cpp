#include "framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	cursorCircle = make_shared<CircleCollider>(Vector(100, 100), 100);
	cursorRect = make_shared<RectCollider>(Vector(100, 100), Vector(100, 100));
	myCircle = make_shared<CircleCollider>(Vector(400, 400), 100);
	myRect1 = make_shared<RectCollider>(Vector(800, 400), Vector(200, 200));
}

CollisionScene::~CollisionScene()
{
}

void CollisionScene::Update()
{
	cursorCircle->Center() = mousePos;
	cursorRect->Center() = mousePos;

	if (myCircle->IsCollision(cursorRect))
		myCircle->SetRed();
	else
		myCircle->SetGreen();

	if (myRect1->IsCollision(cursorRect))
		myRect1->SetRed();
	else
		myRect1->SetGreen();
	//if (cursorCircle->IsCollision(myRect1))
	//	myRect1->SetRed();
	//else
	//	myRect1->SetGreen();
	myCircle->Update();
	myRect1->Update();
	//cursorCircle->Update();
	cursorRect->Update();


}

void CollisionScene::Render(HDC hdc)
{
	myCircle->Render(hdc);
	myRect1->Render(hdc);
	//cursorCircle->Render(hdc);
	cursorRect->Render(hdc);

}
