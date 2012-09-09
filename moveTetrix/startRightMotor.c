#include <stdio.h>
#include <sys/time.h>

int main(){
	FILE *right;
	FILE *ratioR;
	int highTimeR, lowTimeR, oldHighTimeR, oldLowTimeR;
	struct timeval lastUpdateR, curTime;
	gettimeofday(&lastUpdateR, NULL);
	gettimeofday(&curTime, NULL);

	while(1){
		oldHighTimeR = highTimeR;
		oldLowTimeR = lowTimeR;
		
		ratioR = fopen("ratioR", "r");
		fscanf(ratioR, "%d", &highTimeR);
		fscanf(ratioR, "%d", &lowTimeR);
		fclose(ratioR);
		
		if(highTimeR != oldHighTimeR || lowTimeR != oldLowTimeR){
			gettimeofday(&lastUpdateR, NULL);
		}
	
		gettimeofday(&curTime, NULL);
		//printf("curTime.tv_sec - lastUpdateR.tv_sec < 5 = %d\n", curTime.tv_sec - lastUpdateR.tv_sec < 5);
		
		if(curTime.tv_sec - lastUpdateR.tv_sec < 5){ 		

			if(highTimeR > 0){
				right = fopen("/../../../../sys/devices/virtual/gpio/gpio138/direction", "w");
				fprintf(right, "high");
				fclose(right);
			}	
			usleep(highTimeR);
		

			if(lowTimeR>0){
				right = fopen("/../../../../sys/devices/virtual/gpio/gpio138/direction", "w");
				fprintf(right, "low");
				fclose(right);			
			}

			usleep(lowTimeR);	
		} else {
			right = fopen("/../../../../sys/devices/virtual/gpio/gpio138/direction", "w");
			fprintf(right, "high");
			fclose(right);
				
			usleep(135);		
			right = fopen("/../../../../sys/devices/virtual/gpio/gpio138/direction", "w");
			fprintf(right, "low");
			fclose(right);
			usleep(50);
		}
	}
}
