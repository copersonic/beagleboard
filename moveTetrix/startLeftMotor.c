#include <stdio.h>
#include <sys/time.h>

int main(){

	FILE *left;
	FILE *ratioL;
	int highTimeL, lowTimeL, oldHighTimeL, oldLowTimeL;
	struct timeval lastUpdateL, curTime;
	gettimeofday(&lastUpdateL, NULL);
	gettimeofday(&curTime, NULL);
	
	system("echo 137 > ~/../../sys/class/gpio/export");
	system("echo 138 > ~/../../sys/class/gpio/export");
	system("echo 139 > ~/../../sys/class/gpio/export");

	
	

	while(1){

		oldHighTimeL = highTimeL;
		oldLowTimeL = lowTimeL;
		
		//Read ratioL values in
		ratioL = fopen("ratioL", "r");
		fscanf(ratioL, "%d", &highTimeL);
		fscanf(ratioL, "%d", &lowTimeL);
		fclose(ratioL);
		
		//Update lastUpdate time if necessary	
		gettimeofday(&curTime, NULL);
		if(highTimeL != oldHighTimeL || lowTimeL != oldLowTimeL){
			gettimeofday(&lastUpdateL, NULL);
		}
		
		
		if(curTime.tv_sec - lastUpdateL.tv_sec < 5){ 		
			
			
			if(highTimeL > 0){
				left = fopen("/../../../../sys/devices/virtual/gpio/gpio139/direction", "w");				
				fprintf(left, "high");				
				fclose(left);
			}	
			usleep(highTimeL);
			
			if(lowTimeL>0){
				left = fopen("/../../../../sys/devices/virtual/gpio/gpio139/direction", "w");
				fprintf(left, "low");
				fclose(left);			
			}

			usleep(lowTimeL);
			
		} else {
			left = fopen("/../../../../sys/devices/virtual/gpio/gpio139/direction", "w");
			fprintf(left, "high");
			fclose(left);
				
			usleep(134);
		
			left = fopen("/../../../../sys/devices/virtual/gpio/gpio139/direction", "w");
			fprintf(left, "low");
			fclose(left);
			usleep(50);
		}
			
	}
	
	return 0;
}
