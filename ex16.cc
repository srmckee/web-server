// Copyright
//
// Spencer McKee
// 1841180
// srmckee@cs.washington.edu

#include <arpa/inet.h>
#include <assert.h>
#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>

#include "./network.h"

using namespace std;

void Usage(char *progname);

int main(int argc, char** argv) {
  // check if port number passed
  if (argc != 2) {
    Usage(argv[0]);
  }
  // listen for client
  int sock_family;
  int listen_fd = Listen(argv[1], &sock_family);
  if (listen_fd <= 0) {
    cerr << "Couldn't bind to any addresses." << endl;
    return EXIT_FAILURE;
  }
  while (1) {
    struct sockaddr_storage caddr;
    socklen_t caddr_len = sizeof(caddr);
    int client_fd = accept(listen_fd, reinterpret_cast<struct sockaddr *>
        (&caddr), &caddr_len);
    if (client_fd < 0) {
      if ((errno == EINTR) || (errno == EAGAIN) || (errno == EWOULDBLOCK))
        continue;
      cerr << "Failure on accept: " << strerror(errno) << endl;
      break;
    } else {
      // accept client
      HandleClient(client_fd, reinterpret_cast<struct sockaddr *>
          (&caddr), caddr_len, sock_family);
      break;
    }
  }
  // close connection
  close(listen_fd);
  return EXIT_SUCCESS;
}

void Usage(char *progname) {
  cerr << "Usage: " << progname << " port" << endl;
}
