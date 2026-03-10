#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    int sd, nsd, port, n;
    char fname[100], buf[100];
    struct sockaddr_in server, client;
    socklen_t len;
    FILE *fp;

    printf("Enter port: ");
    scanf("%d",&port);

    sd = socket(AF_INET,SOCK_STREAM,0);

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(sd,(struct sockaddr *)&server,sizeof(server));

    listen(sd,5);

    len = sizeof(client);
    nsd = accept(sd,(struct sockaddr *)&client,&len);

    recv(nsd,fname,sizeof(fname),0);

    fp = fopen(fname,"r");

    if(fp==NULL)
        printf("File not found\n");
    else
        while((n=fread(buf,1,sizeof(buf),fp))>0)
            send(nsd,buf,n,0);

    fclose(fp);
    close(nsd);
    close(sd);

    return 0;
}