#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    int sockfd, port, n;
    char fname[100], buf[100];
    FILE *fp;
    struct sockaddr_in server;

    printf("Enter port: ");
    scanf("%d",&port);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sockfd,(struct sockaddr *)&server,sizeof(server));

    printf("Enter the existing file name to fetch: ");
    scanf("%s", fname);

    send(sockfd, fname, strlen(fname), 0);

    printf("Enter the new file name to save as: ");
    scanf("%s", fname);

    fp = fopen(fname, "w");

    while((n = recv(sockfd, buf, sizeof(buf), 0)) > 0)
        fprintf(fp,"%.*s",n,buf);

    fclose(fp);
    close(sockfd);

    printf("File received successfully\n");

    return 0;
}