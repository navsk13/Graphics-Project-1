#ifndef __Vector3_h__
#define __Vector3_h__

#include "RE330_global.h"
#include <math.h>

namespace RE330
{
  class RE330_EXPORT Vector3
  {
  private:
    float x, y, z;
  public:
    float getXComp() { return x; }
    float getYComp() { return y; }
    float getZComp() { return z; }

    void setXComp(float x2) { x = x2; }
    void setYComp(float y2) { y = y2; }
    void setZComp(float z2) { z = z2; }

    Vector3 operator+(const Vector3& left, const Vector3& right)
    {
      Vector3 result;
      float resultX = left.getXComp() + left.getXComp();
      float resultY = left.getYComp() + left.getYComp();
      float resultZ = left.getZComp() + left.getZComp();

      result.x = resultX;
      result.y = resultY;
      result.z = resultZ;

      return result;

    }

    Vector3 operator-(const Vector3& left, const Vector3& right)
    {
      Vector3 result;
      float resultX = left.getXComp() - left.getXComp();
      float resultY = left.getYComp() - left.getYComp();
      float resultZ = left.getZComp() - left.getZComp();

      result.x = resultX;
      result.y = resultY;
      result.z = resultZ;

      return result;

    }
  };
}

#endif
