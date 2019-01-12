class ColorMake
{
   public:
	double r;
	double g;
	double b;
	ColorMake(){
      r=1;b=1;g=1;
	}
    ColorMake(double r1, double g1, double b1) {
		r = r1;
		g = g1;
	    b = b1;
	}
	bool operator==(const ColorMake& anyOther) 
    {
		if(r == anyOther.r && g == anyOther.g && b == anyOther.b)
            return true;
        else
            return false;
	}
};