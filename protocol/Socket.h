#ifndef SOCKET_H
#define SOCKET_H
#include <string>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

class Socket
{
private:
    int m_socketNum;
    // the ip version. either AF_INET or AF_INET6.
    int m_ipV;

protected:
    /**
     * set the socket number.
     */
    void setSocketNum(const int socket);
    /**
     * get the socket number.
     */
    int getSocketNum() const;
    /**
     * set the Ip version.
     */
    void setIpV(const int ipV);
    /**
     * get the Ip version
     */
    int getIpV() const;

public:
    /**
     * binding the socket IP to the socket port.
     */
    void bindSocket(const char *sourceIp, const int sourcePort);

    /**
     * close the socket.
     */
    void closeSocket();

    /**
     * initialize the socket.
     */
    virtual void init(const int ipV) = 0;

    /**
     * connect to a socket.
     */
    virtual void connectSocket(const char *destIp, const int destPort) = 0;

    virtual void acceptSocket() = 0;

    /**
     * sending a messege to another socket.
     */
    virtual void sendSocket(std::string message) = 0;

    /**
     * receiving a messege from another socket.
     */
    virtual void recvSocket(char *buffer, int len) = 0;
};
#endif