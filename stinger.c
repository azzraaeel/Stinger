#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void portscan(char *ip, int port) {
    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Failed to create socket");
        exit(-1);
    }

    // Prepare the socket address
    struct sockaddr_in addr;
    addr.sin_family = AF_INET; // IPv4
    addr.sin_addr.s_addr = inet_addr(ip); // IP address
    addr.sin_port = htons(port); // Port number

    // Connect to remote server
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        fprintf(stderr, "Port %d is closed\n", port);
    }
    else {
        if (port == 80 || port == 443) {
            printf("Port %d is open it's using HTTP/HTTPS\n", port);
        }
        if (port == 21) {
            printf("Port %d is open it's using FTP\n", port);
        }
        if (port == 22) {
            printf("Port %d is open it's using SSH\n", port);
        }
        if (port == 25) {
            printf("Port %d is open it's using SMTP\n", port);
        }
        if (port == 110) {
            printf("Port %d is open it's using POP3\n", port);
        }
        if (port == 143) {
            printf("Port %d is open it's using IMAP\n", port);
        }
        if (port == 53) {
            printf("Port %d is open it's using DNS\n", port);
        }
        if (port == 23) {
            printf("Port %d is open it's using Telnet\n", port);
        }
        if (port == 161) {
            printf("Port %d is open it's using SNMP\n", port);
        }
        if (port == 3389) {
            printf("Port %d is open it's using RDP\n", port);
        }
        if (port == 3306) {
            printf("Port %d is open it's using MySQL\n", port);
        }
    }

    close(sock); // Close socket
}

int main() {
    printf("\033[1;35m"); // Set color to pink
    printf("  sSSs  sdSS_SSSSSSbs   .S   .S_sSSs      sSSSSs    sSSs   .S_sSSs    \n");
    printf(" d%%SP  YSSS~S%%SSSSSP  .SS  .SS~YS%%b    d%%%%SP   d%%SP  .SS~YS%%b   \n");
    printf("d%S'         S%S       S%S  S%S   `S%%b  d%S'      d%S'    S%S   `S%%b  \n");
    printf("S%%|          S%S       S%S  S%S    S%S  S%S       S%S     S%S    S%S  \n");
    printf("S&S          S&S       S&S  S%S    S&S  S&S       S&S     S%S    d*S  \n");
    printf("Y&Ss         S&S       S&S  S&S    S&S  S&S       S&S_Ss  S&S   .S*S  \n");
    printf("`S&&S        S&S       S&S  S&S    S&S  S&S       S&S~SP  S&S_sdSSS   \n");
    printf("  `S*S       S&S       S&S  S&S    S&S  S&S sSSs  S&S     S&S~YSY%%b  \n");
    printf("   l*S       S*S       S*S  S*S    S*S  S*b `S%%  S*b     S*S   `S%%b \n");
    printf("  .S*P       S*S       S*S  S*S    S*S  S*S   S%%  S*S.    S*S    S%%S \n");
    printf("sSS*S        S*S       S*S  S*S    S*S   SS_sSSS   SSSbs  S*S    S&S  \n");
    printf("YSS'         S*S       S*S  S*S    SSS    Y~YSSY    YSSP  S*S    SSS  \n");
    printf("             SP        SP   SP                            SP           \n");
    printf("             Y         Y    Y                             Y            \n");
    printf("\033[0m"); // Reset color
    printf("Port Scanner by: Azrael\n");

    char ip[20];
    printf("\nIP Address: ");
    scanf("%s", ip);

    // Define port numbers and corresponding service names
    const struct PortService services[] = {
        {80, "HTTP"},
        {443, "HTTPS"},
        {21, "FTP"},
        {22, "SSH"},
        {25, "SMTP"},
        {110, "POP3"},
        {143, "IMAP"},
        {53, "DNS"},
        {23, "Telnet"},
        {161, "SNMP"},
        {3389, "RDP"},
        {3306, "MySQL"}
    };

    // Calculate the number of services
    const int NUM_SERVICES = sizeof(services) / sizeof(services[0]);

    for (int i = 0; i < sizeof(ports) / sizeof(ports[0]); i++) {
        portscan(ip, ports[i]);
    }
    return 0;
}
