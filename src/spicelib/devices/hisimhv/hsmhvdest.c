/***********************************************************************

 HiSIM (Hiroshima University STARC IGFET Model)
 Copyright (C) 2010 Hiroshima University & STARC

 MODEL NAME : HiSIM_HV 
 ( VERSION : 1  SUBVERSION : 2  REVISION : 1 )
 Model Parameter VERSION : 1.21
 FILE : hsmhvdest.c

 DATE : 2010.11.02

 released by 
                Hiroshima University &
                Semiconductor Technology Academic Research Center (STARC)
***********************************************************************/

#include "ngspice.h"
#include <stdio.h>
#include "hsmhvdef.h"
#include "suffix.h"

void HSMHVdestroy(
     GENmodel **inModel)
{
  HSMHVmodel **model = (HSMHVmodel**)inModel;
  HSMHVinstance *here;
  HSMHVinstance *prev = NULL;
  HSMHVmodel *mod = *model;
  HSMHVmodel *oldmod = NULL;
  
  for ( ;mod ;mod = mod->HSMHVnextModel ) {
    if (oldmod) FREE(oldmod);
    oldmod = mod;
    prev = (HSMHVinstance *)NULL;
    for ( here = mod->HSMHVinstances ;here ;here = here->HSMHVnextInstance ) {
      if (prev) FREE(prev);
      prev = here;
    }
    if (prev) FREE(prev);
  }
  if (oldmod) FREE(oldmod);
  *model = NULL;
}

