#pragma once
class Block
{
public:
	enum BlockType
	{
		NONE,
		ABLE,
		DISABLE
	};

	Block();
	~Block();

	void Update();
	void Render(HDC hdc);

	void SetType(BlockType type) { _curType = type; }
	void SetPos(Vector pos) { _rect->Center() = pos; }

private:
	shared_ptr<RectCollider> _rect; //Component Pattern  ��ǰ�� �����ؼ� ���� ���.
	BlockType _curType = BlockType::NONE;
	vector<HBRUSH> _brushes;
};

