#pragma once
#include "Collider.h"
class RectangleCollider :
    public Collider
{
public:
    RectangleCollider(Vector center, Vector size, float angle);

    void Update() override;
    void Render(HDC hdc) override;

    void SetSize(Vector size) { _halfSize = size * 0.5; }
    Vector GetSize() {return _halfSize; }

    bool IsCollision(const Vector& pos) const override;
    bool IsCollision(shared_ptr<CircleCollider> other) const override;
    bool IsCollision(shared_ptr<RectCollider> other) const override;
    Vector& Direction() { return _direction; }
    

private:
    Vector _halfSize;
    Vector _direction;
    Vector _topLeft;
    Vector _topRight;
    Vector _bottomRight;
    Vector _bottomLeft;

    void AngleToDir(float angle);
    void SetAngle();
};

