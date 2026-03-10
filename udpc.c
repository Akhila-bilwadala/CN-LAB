#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    int sock_desc, sum;
    struct sockaddr_in server;
    int slen;

    int a, b;

    sock_desc = socket(AF_INET, SOCK_DGRAM, 0);

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(3003);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    slen = sizeof(server);

    printf("enter first number: ");
    scanf("%d", &a);

    printf("enter second number: ");
    scanf("%d", &b);

    sendto(sock_desc, &a, sizeof(a), 0, (struct sockaddr *)&server, slen);
    sendto(sock_desc, &b, sizeof(b), 0, (struct sockaddr *)&server, slen);

    recvfrom(sock_desc, &sum, sizeof(sum), 0, NULL, NULL);

    printf("sum received from server: %d\n", sum);

    close(sock_desc);

    return 0;
}