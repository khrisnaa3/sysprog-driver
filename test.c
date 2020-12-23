#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define DEVICE "/dev/pen0"


int main() {
    int i,fd;
    char ch, write_buf[100] = "bobby",read_buf[100];

    ;

    if((fd = open(DEVICE,O_RDWR)) == -1)
    {
        printf("file %s does not exist\n",DEVICE);
	return -1;
    }

    printf("r = read from device\nw = write from device\nenter command : ");
    scanf("%c",&ch);

    switch(ch)
    {
        case 'w':
            printf("enter data: ");
            fflush(stdin);
            //scanf("%s",write_buf);
            write(fd,write_buf,sizeof(write_buf));
            break;
        case 'r':
            read(fd,read_buf,sizeof(read_buf)); 
            read(fd,read_buf,sizeof(read_buf)); 
            printf("device: %s\n", read_buf);
            break;
        default:
            printf("command not recognized\n");
            break;

    }

return 0;

}