#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>


#define DEVICE_FILE_NAME "/dev/chr_dev"

 

int main(int argc, char *argv[]) {
    int device;
   
	char wbuf[128] = "" ; 
	char rbuf[128] = "";
	int n = atoi (argv[1]);
	// read 먼저 
	// 그리고 write 해보기
	// set_battery_value, read_battery_value implements
	device = open(DEVICE_FILE_NAME, O_RDWR | O_NDELAY) ;
	if (device >= 0 ) {
        printf("Device file open\n");
        ioctl(device , n );
		write(device,argv[2] , 10);
		printf("write requested %s \n", argv[2]);
		read(device ,rbuf, 10);
		printf("read value %c \n", read(device ,rbuf, 10));
    } else {
        perror("Error open device (sudo needed)");
    }
    return 0 ;
}