#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    int sock_desc, temp_sock_desc;
    struct sockaddr_in server, client;
    char a[20], b[20];
    int client_len;

    // 1️⃣ Create socket
    sock_desc = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_desc == -1)
    {
        printf("Error in socket creation\n");
        return 1;
    }

    // 2️⃣ Clear server structure
    memset(&server, 0, sizeof(server));

    // 3️⃣ Set server details
    server.sin_family = AF_INET;
    server.sin_port = htons(3003);
    server.sin_addr.s_addr = INADDR_ANY;

    // 4️⃣ Bind socket
    if(bind(sock_desc, (struct sockaddr*)&server, sizeof(server)) == -1)
    {
        printf("Error in binding\n");
        return 1;
    }

    // 5️⃣ Listen for connection
    listen(sock_desc, 5);
    printf("Server waiting for connection...\n");

    client_len = sizeof(client);

    // 6️⃣ Accept connection
    temp_sock_desc = accept(sock_desc, (struct sockaddr*)&client, &client_len);
    if(temp_sock_desc == -1)
    {
        printf("Error in accepting connection\n");
        return 1;
    }

    printf("Client connected\n");

    // 7️⃣ Receive first number
    recv(temp_sock_desc, a, sizeof(a), 0);
    printf("First number: %s", a);

    // 8️⃣ Receive second number
    recv(temp_sock_desc, b, sizeof(b), 0);
    printf("Second number: %s", b);

    int n1 = atoi(a);
int n2 = atoi(b);
printf("Sum = %d\n", n1+n2);
    // 9️⃣ Close sockets
    close(temp_sock_desc);
    close(sock_desc);

    return 0;
}