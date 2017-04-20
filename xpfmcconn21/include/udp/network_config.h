#ifdef WIN32
	#include <winsock2.h>
	#include <ws2tcpip.h>
	#define sleep(x) Sleep((x)*1000)
	#define PERROR(x) printf(x", errno = %d", WSAGetLastError())
	#define REUSE SO_REUSEADDR
	typedef char socketOption_t;

#else
	#ifdef __linux__
		#define REUSE SO_REUSEADDR
	#else
		#define REUSE SO_REUSEPORT
	#endif

	#include <sys/socket.h>
	#include <sys/types.h>
	#include <arpa/inet.h>
	#include <netinet/in.h>
	#include <netdb.h>		// gethostby*
	#define PERROR(x) perror(x)
	typedef int socketOption_t;
#endif
