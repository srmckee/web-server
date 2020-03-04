// Copyright
//
// Spencer McKee
// 1841180
// srmckee@cs.washington.edu

#ifndef _HOMES_IWS_SRMCKEE_EX16_NETWORK_H_
#define _HOMES_IWS_SRMCKEE_EX16_NETWORK_H_

void PrintOut(int fd, struct sockaddr *addr, size_t addrlen);
void PrintReverseDNS(struct sockaddr *addr, size_t addrlen);
void PrintServerSide(int client_fd, int sock_family);
int  Listen(char *portnum, int *sock_family);
void HandleClient(int c_fd, struct sockaddr *addr, size_t addrlen,
                      int sock_family);

#endif  // _HOMES_IWS_SRMCKEE_EX16_NETWORK_H_
