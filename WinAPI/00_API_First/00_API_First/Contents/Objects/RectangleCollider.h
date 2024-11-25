#pragma once
#include "Collider.h"
class RectangleCollider :
    public Collider
{
public:
    RectangleCollider(Vector center, Vector size, float angle);

    void Update() override;
    void Render(HDC hdc) override;
    bool IsCollision(const Vector& pos) const override;
    bool IsCollision(shared_ptr<CircleCollider> other) const override;
    bool IsCollision(shared_ptr<RectCollider> other) const override;

private:
    Vector _halfSize;
    float _angle;
    Vector _topLeft;
    Vector _topRight;
    Vector _bottomRight;
    Vector _bottomLeft;

    void SetAnglePoint();
};

