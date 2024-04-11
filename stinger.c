#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define a structure to hold port information
struct PortInfo {
    int port;
    const char *service;
};

// Function to perform port scanning
void portscan(char *ip, int port, struct PortInfo *ports, int num_ports) {
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
        // Search for the service name based on the port
        const char *service = "Unknown";
        for (int i = 0; i < num_ports; i++) {
            if (ports[i].port == port) {
                service = ports[i].service;
                break;
            }
        }
        printf("Port %d is open and it's using %s\n", port, service);
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
    printf("Y&Ss         S&S       S&S  S%S    S&S  S&S       S&S_Ss  S&S   .S*S  \n");
    printf("`S&&S        S&S       S&S  S&S    S&S  S&S       S&S~SP  S&S_sdSSS   \n");
    printf("  `S*S       S&S       S&S  S&S    S&S  S*b `S%%  S*b     S*S   `S%%b \n");
    printf("   l*S       S*S       S*S  S*S    S*S  S*S   S%%  S*S.    S*S    S%%S \n");
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

    // Open the ports.txt file
    FILE *file = fopen("ports.txt", "r");
    if (file == NULL) {
        perror("Error opening ports.txt");
        exit(-1);
    }

    // Read port numbers and service names from ports.txt
    struct PortInfo ports[100]; // Assuming a maximum of 100 ports
    int num_ports = 0;
    while (fscanf(file, "%d %s", &ports[num_ports].port, ports[num_ports].service) != EOF) {
        num_ports++;
    }
    fclose(file);

    // Perform port scanning for each port in the ports array
    for (int i = 0; i < num_ports; i++) {
        portscan(ip, ports[i].port, ports, num_ports);
    }

    return 0;
}
