#pragma once
class Block
{
public:
	enum BlockType
	{
		NONE,
		ABLE,
		DISABLE,
		PLAYER,
		FOOTPRINT,
		START,
		END,
		DFSPRINT
	};

	Block();
	~Block();

	void Update();
	void Render(HDC hdc);


	BlockType GetType() { return _curType; }
	void SetType(BlockType type) { _curType = type; }
	void SetPos(Vector pos) { _rect->Center() = pos; }

private:
	shared_ptr<RectCollider> _rect; //Component Pattern  부품을 조립해서 쓰는 방법.
	BlockType _curType = BlockType::NONE;
	vector<HBRUSH> _brushes;
};

