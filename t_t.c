#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#define PORT 8080 

int Random(int lower, int upper,int count)
{
        int i;
        for (i = 0; i < count; i++) {
                int num = (rand() %
                (upper - lower + 1)) + lower;
                return num;
        }

}
        // structure containing data
        struct temp     {
                int id;
                int packet_number;
                int num;
                int seconds;
        }t;


int main()
{
        struct temp cs;

        int lower = -100, upper = 100, count = 10;
        srand(time(0));

        int random =Random(lower, upper, count);

time_t seconds;

    seconds = time(NULL);

        // Program ID
        int id=1;
        t.id=id;
        t.num=random;
        t.packet_number=1;
        t.seconds=seconds;



        int sock = 0;
        struct sockaddr_in serv_addr;
        char buffer[1024] = {0};
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        {
                printf("\n Socket creation error \n");
                return -1;
        }

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(PORT);


        if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
        {
                printf("\nInvalid address/ Address not supported \n");
                return -1;
        }

        if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        {
                printf("\nConnection Failed \n");
         return -1;
        }
        send(sock ,  &t, sizeof(t) , 0);
        return 0;
}                                                                                                  


