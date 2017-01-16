#include"types.h"
#include"user.h"

int main (void){

int childPID= fork();
if (childPID < 0)
	printf(1, "Fork Failed%d\n", childPID);
else if(childPID > 0){
	printf(1, "I'm parent and my PID is %d , child ID is %d\n" , getpid() , childPID);
wait();	

}

else{
	printf(1,"I'm child and my PID is %d, my parent ID is %d\n",getpid() ,GetPPID() );
}
exit();
}

