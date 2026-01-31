#define MAX_PATH_FIND 15
#define TW_CHARACTER	( 0x0002)	//  캐릭터가 차지하고 있음

#define pPathFinding2	((bool(__cdecl*)(int sx,int sy,int tx,int ty, PATH_t *a, float fDistance, int iDefaultWall)) 0x00542D20)
#define pSendMove		((bool(__cdecl*)(int c, int o)) 0x005A3C70)

typedef struct _PATH_t
{
	BYTE CurrentPath;
	BYTE CurrentPathFloat;
	BYTE PathNum;
	BYTE PathX[MAX_PATH_FIND];
	BYTE PathY[MAX_PATH_FIND];

	bool Success;
	bool Error;
	BYTE x, y;
	BYTE Direction;
	BYTE Run;
	int	 Count;

	_PATH_t()
	{
		CurrentPath = 0;
		CurrentPathFloat = 0;
		PathNum = 0;

		for (int i = 0; i < MAX_PATH_FIND; ++i)
		{
			PathX[i] = 0;
			PathY[i] = 0;
		}

		Success = 0;
		Error = 0;
		x = 0, y = 0;
		Direction = 0;
		Run = 0;
		Count = 0;
	}

} PATH_t;

class cSkillMove
{
public:
	cSkillMove();
	~cSkillMove();
	void Load();
	bool CheckPathFinding(int sx, int sy, int tx, int ty, PATH_t *a, float fDistance = 0.0f, int iDefaultWall = TW_CHARACTER);
	bool Method;
private:

};

extern cSkillMove SkillMove;