class CreatePoint
{
	public:
		int x;
		int y;

		CreatePoint(){
            x=0,y=0;
		}

		CreatePoint(int x1, int y1) {
			x = x1;
			y = y1;
		}

		bool operator==(const CreatePoint& anyOther) {
			if( x == anyOther.x && y == anyOther.y)
                return true;
            else
                return false;
		}
};