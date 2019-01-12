#include "color.h"
#include "point.h"

class BuildLine
{
    public:
        CreatePoint fp;
        CreatePoint lp;
        ColorMake cc;

        BuildLine(CreatePoint fp1,CreatePoint lp1,ColorMake cc1)
        {
            fp=fp1,lp=lp1,cc=cc1;    
        }

        bool operator==(const BuildLine& anyOther)
        {
            if(fp==anyOther.fp && lp==anyOther.lp && cc==anyOther.cc)
                return true;
            else
                return false;
        }
};