#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    char a[20], b[20];
    int k;
    int sock_desc;
    struct sockaddr_in server;

    // 1️⃣ Create socket
    sock_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_desc == -1)
    {
        printf("Error in creating socket\n");
        return 1;
    }

    // 2️⃣ Clear server structure
    memset(&server, 0, sizeof(server));

    // 3️⃣ Set server details
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");  // localhost
    server.sin_port = htons(3003);  // port number

    // 4️⃣ Connect to server
    k = connect(sock_desc, (struct sockaddr*)&server, sizeof(server));
    if (k == -1)
    {
        printf("Error in connecting\n");
        return 1;
    }

    printf("Connected to server successfully\n");

    // 5️⃣ Send first number
    printf("Enter first number: ");
    fgets(a, sizeof(a), stdin);

    k = send(sock_desc, a, strlen(a), 0);
    if (k == -1)
    {
        printf("Error in sending first number\n");
        return 1;
    }

    // 6️⃣ Send second number
    printf("Enter second number: ");
    fgets(b, sizeof(b), stdin);

    k = send(sock_desc, b, strlen(b), 0);
    if (k == -1)
    {
        printf("Error in sending second number\n");
        return 1;
    }

    // 7️⃣ Close socket
    close(sock_desc);
    printf("Connection closed\n");

    return 0;
}