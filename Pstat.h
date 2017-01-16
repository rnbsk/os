#ifndef_PSTAT_H_
#define_PSTAT_H_

#include "param.h"


struct pstat {

int inuse[NPROC]; 
int pid[NPROC][16]; 
char name[NPROC]; 
int hticks[NPROC]; 
int lticks[NPROC]; 


#endif

}
