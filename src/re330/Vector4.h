#ifndef __Vector4_h__
#define __Vector4_h__

#include "RE330_global.h"

namespace RE330 
{
  class RE330_EXPORT Vector4
  {
  private:
    float x, y, z, w;
  public:
    float getXComp() { return x; }
    float getYComp() { return y; }
    float getZComp() { return z; }
    float getWComp() { return w; }

    void setXComp(float x2) { x = x2; }
    void setYComp(float y2) { y = y2; }
    void setZComp(float z2) { z = z2; }
    void setWComp(float z2) { w = w2; }

    Vector4 operator+(const Vector4& rhs)
    {
      Vector4 result;

      result.x = x + rhs.getXComp();
      result.y = y + rhs.getYComp();
      result.z = z + rhs.getZComp();
      result.w = w + rhs.getWComp();

      return result;

    }

    Vector4 operator-(const Vector4& rhs)
    {
      Vector4 result;

      result.x = x - rhs.getXComp();
      result.y = y - rhs.getYComp();
      result.z = z - rhs.getZComp();
      result.w = w - rhs.getWComp();

      return result;
    }

    void operator*(float scaleFactor) {
      x = x * scaleFactor;
      y = y * scaleFactor;
      z = z * scaleFactor;
      w = w * scaleFactor;
    }

    float dotProduct(Vector4 rhs) {
      float dotProduct = x*rhs.getXComp() +
	                 y*rhs.getYComp() +
	                 z*rhs.getZComp() +
	                 w*rhs.getWComp();
      return dotProduct;
		  
    }

    float magnitude() {
      float magnitude = sqrt(pow(x, 2) +
			     pow(y, 2) + 
			     pow(z, 2) +
			     pow(w, 2));

      return magnitude;
    }

    void normalize() {
      float magnitude = magnitude();
      
      x = x/magnitude;
      y = y/magnitude;
      z = z/magnitude;
      z = w/magnitude;
    }

  };

}

#endif

