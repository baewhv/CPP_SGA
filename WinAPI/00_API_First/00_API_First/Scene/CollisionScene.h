#pragma once

class CollisionScene : public Scene
{
public:
	CollisionScene();
	~CollisionScene();

	// Scene��(��) ���� ��ӵ�
	void Update() override;
	void Render(HDC hdc) override;

private:
	//shared_ptr<Collider> cursorCircle;
	shared_ptr<Collider> cursorRect;
	shared_ptr<Collider> myCircle;
	shared_ptr<Collider> myRect1;
	//shared_ptr<Collider> myRectAngle;

	
};
