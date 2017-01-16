#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return proc->pid;
}
int
sys_GetPPID(void)
{

return proc-> parent -> pid;


}
//prj
int getPerformanceData(int *wtime, int *rtime)
{
 struct proc *p;
  int havekids, pid;

  acquire(&ptable.lock);
  for(;;){
    // Scan through table looking for exited children.
    havekids = 0;
    for(p = ptable.proc; p < &ptable.proc[NPROC]; p++){
      if(p->parent != proc)
        continue;
      havekids = 1;
      if(p->state == ZOMBIE){ 

//prj////////////////////////////////////////////////////////////////
	*wtime = etime - ctime - rtime ;
	*rtime = rtime ;

        // Found one.
        pid = p->pid;
        kfree(p->kstack);
        p->kstack = 0;
        freevm(p->pgdir);
        p->pid = 0;
        p->parent = 0;
        p->name[0] = 0;
        p->killed = 0;
        p->state = UNUSED;
        release(&ptable.lock);
//prj////////////////////////////////////////////////////////////////
	*wtime = etime - ctime - rtime ;
	  *rtime = rtime ;
        return pid;
      }

}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = proc->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(proc->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

////////////////// OUR FUNCTION /////////////////////

//struct pstat pstat; 
/*
int
sys_GetAllPIDs(void)
{

struct pstat *st;
	if (argptr( 0, (void*)&st, sizeof(*st) ) < 0 )
		return -1;
	int i; 
	for(i=0 ; i< NPROC ; i++)
		st-> inuse[i] = pstat.inuse[i],
		st-> pid[i] = pstat.pid[i],
		st-> name[i][0] = pstat.name[i][0],
			st->name[i][1] = pstat.name[i][1],
				st-> name[i][2] = pstat.name[i][2],
		st-> inuse[i] = pstat.hticks[i],
		st-> lticks[i] = pstat.lticks[i];

	return 0 ;

}

*/











































