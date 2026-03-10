#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    int sock_desc, sum;
    struct sockaddr_in server, client;
    int clen;

    int a, b;

    sock_desc = socket(AF_INET, SOCK_DGRAM, 0);

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(3003);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(sock_desc, (struct sockaddr *)&server, sizeof(server));

    clen = sizeof(client);

    recvfrom(sock_desc, &a, sizeof(a), 0, (struct sockaddr *)&client, &clen);
    recvfrom(sock_desc, &b, sizeof(b), 0, (struct sockaddr *)&client, &clen);

    sum = a + b;

    sendto(sock_desc, &sum, sizeof(sum), 0, (struct sockaddr *)&client, clen);

    printf("numbers received: %d %d\n", a, b);
    printf("sum sent: %d\n", sum);

    close(sock_desc);

    return 0;
}