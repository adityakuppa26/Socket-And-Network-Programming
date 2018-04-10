 # Socket-Programming


# What is socket programming?

Socket programming is a way of connecting two nodes on a network to communicate with each other. One socket(node) listens on a particular port at an IP, while other socket reaches out to the other to form a connection. Server forms the listener socket while client reaches out to the server.

# Stages for server :

# 1.Socket creation: 
int sockfd = socket(domain, type, protocol)
sockfd: socket descriptor, an integer (like a file-handle)
domain: integer, communication domain e.g., AF_INET (IPv4 protocol) , AF_INET6 (IPv6 protocol)
type: communication type
SOCK_STREAM: TCP(reliable, connection oriented)
SOCK_DGRAM: UDP(unreliable, connectionless)
protocol: Protocol value for Internet Protocol(IP), which is 0. This is the same number which appears on protocol field in the IP header of a packet.(man protocols for more details)

# 2.Bind: 
int bind(int sockfd, const struct sockaddr *addr, 
                          socklen_t addrlen);
After creation of the socket, bind function binds the socket to the address and port number specified in addr(custom data structure). In the example code, we bind the server to the localhost, hence we use INADDR_ANY to specify the IP address.

# 3.Listen: 
int listen(int sockfd, int backlog);
It puts the server socket in a passive mode, where it waits for the client to approach the server to make a connection. The backlog, defines the maximum length to which the queue of pending connections for sockfd may grow. If a connection request arrives when the queue is full, the client may receive an error with an indication of ECONNREFUSED.

# 4.Accept: 
int new_socket= accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
It extracts the first connection request on the queue of pending connections for the listening socket, sockfd, creates a new connected socket, and returns a new file descriptor referring to that socket. At this point, connection is established between client and server, and they are ready to transfer data.

# Stages for Client

# 1.Socket connection: 
Exactly same as that of server’s socket creation

# 2.Connect: 
int connect(int sockfd, const struct sockaddr *addr,  
                             socklen_t addrlen);
The connect() system call connects the socket referred to by the file descriptor sockfd to the address specified by addr. Server’s address and port is specified in addr.

# The sockaddr_in structure :

struct sockaddr_in{
sa_family_t   sin_family   /*Address/Protocol Family*/ (we’ll use PF_INET)
unit16_t   sin_port     /* 16-bit Port number   --Network Byte Ordered-*/
struct in_addr  sin_addr /*A struct for the 32 bit IP Address  */ unsigned char sin_zero[8] /*Just ignore this it is just padding*/
struct in_addr
{ unit32_t     s_addr   /*32 bit IP Address   --Network Byte Ordered-- */ };
};

