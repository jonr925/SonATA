/*
Module : AARISETRANSITSET.H
Purpose: Implementation for the algorithms which obtain the Rise, Transit and Set times
Created: PJN / 29-12-2003

Copyright (c) 2003 - 2009 by PJ Naughter (Web: www.naughter.com, Email: pjna@naughter.com)

All rights reserved.

Copyright / Usage Details:

You are allowed to include the source code in any product (commercial, shareware, freeware or otherwise) 
when your product is released in binary form. You are allowed to modify the source code in any way you want 
except you cannot modify the copyright details at the top of each module. If you want to distribute source 
code with your application, then you are only allowed to distribute versions released by the author. This is 
to maintain a single distribution point for the source code. 

*/


/////////////////////// Macros / Defines //////////////////////////////////////

#if _MSC_VER > 1000
#pragma once
#endif

#ifndef __AARISETRANSITSET_H__
#define __AARISETRANSITSET_H__

#ifndef AAPLUS_EXT_CLASS
#define AAPLUS_EXT_CLASS
#endif


/////////////////////// Classes ///////////////////////////////////////////////

class AAPLUS_EXT_CLASS CAARiseTransitSetDetails
{
public:
//Constructors / Destructors
  CAARiseTransitSetDetails() : bValid(false), 
                               Rise(0), 
                               Transit(0), 
                               Set(0) 
  {
  };

//Member variables
  bool   bValid;
  double Rise;
  double Transit;
  double Set;
};

class AAPLUS_EXT_CLASS CAARiseTransitSet
{
public:
//Static methods
  static CAARiseTransitSetDetails Rise(double JD, double Alpha1, double Delta1, double Alpha2, double Delta2, double Alpha3, double Delta3, double Longitude, double Latitude, double h0);
};

#endif //__AARISETRANSITSET_H__
