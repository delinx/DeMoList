// Demo Header
//
// floats and ints seems to be 4 bytes
// header is 1062 bytes total?
//
// - first 16 bytes
// String   Header              8 characters, should be "HL2DEMO"+NULL
// Int      Demo Protocol       Demo protocol version (stored in little endian)
// Int      Network Protocol    Network protocol version number (stored in little endian)
// 
// next 1040 bytes
// String   Server name         260 characters long
// String   Client name         260 characters long
// String   Map name            260 characters long
// String   Game directory      260 characters long
//
// 16 bytes
// Float    Playback time       The length of the demo, in seconds 
// Int      Ticks               The number of ticks in the demo 
// Int      Frames              The number of frames in the demo
// Int      Sign on length      Length of the signon data (Init for first frame)
// 

#include <stdio.h>

#define ONE_BYTE 1
	
typedef struct S_DemoHeader
{
	char header[8];
	char ServerName[260];
	char ClientName[260];
	char MapName[260];
	char GameDirectory[260];

	float duration;

	int ticks;
	int frames;
	int signOnLenght;
	int  protocol;
	int  networkProtocol;
} DemoHeader;

// Read demo header 
DemoHeader readDemoHeader(char* demo)
{
	FILE *ptr;
	ptr = fopen(demo,"rb");  // r for read, b for binary
	// TODO: check if there is a while, did we open it? etc
	
	DemoHeader dh;

	int offset = 0;

	// read 8 bytes string header 
	fseek(ptr, offset, SEEK_SET);
	fread(dh.header, 8, ONE_BYTE, ptr);
	offset += 8;

	// read int for demo protocol
	fseek(ptr, offset, SEEK_SET);
	fread(&dh.protocol, 4, ONE_BYTE, ptr);
	offset += 4;

	// read int for network protocol
	fseek(ptr, offset, SEEK_SET);
	fread(&dh.networkProtocol, 4, ONE_BYTE, ptr);
	offset += 4;

	// read 260 chars of Server Name
	fseek(ptr, offset, SEEK_SET);
	fread(dh.ServerName, 260, ONE_BYTE, ptr);
	offset += 260;

	// read 260 chars of Client Name
	fseek(ptr, offset, SEEK_SET);
	fread(dh.ClientName, 260, ONE_BYTE, ptr);
	offset += 260;

	// read 260 chars of Map Name
	fseek(ptr, offset, SEEK_SET);
	fread(dh.MapName, 260, ONE_BYTE, ptr);
	offset += 260;

	// read 260 chars of Game Directory
	fseek(ptr, offset, SEEK_SET);
	fread(dh.GameDirectory, 260, ONE_BYTE, ptr);
	offset += 260;

	// read int for demo duration
	fseek(ptr, offset, SEEK_SET);
	fread(&dh.duration, 4, ONE_BYTE, ptr);
	offset += 4;

	// read int for ticks
	fseek(ptr, offset, SEEK_SET);
	fread(&dh.ticks, 4, ONE_BYTE, ptr);
	offset += 4;

	// read int for frames
	fseek(ptr, offset, SEEK_SET);
	fread(&dh.frames, 4, ONE_BYTE, ptr);
	offset += 4;

	// read int for Sign on length
	fseek(ptr, offset, SEEK_SET);
	fread(&dh.signOnLenght, 4, ONE_BYTE, ptr);

	fclose(ptr);

	return dh;
}

void printDemoHeader(DemoHeader *dh)
{
	printf("Header: %s\n", dh->header);
	printf("Demo Protocol: %d\n", dh->protocol);
	printf("Network Protocol: %d\n", dh->networkProtocol);
	printf("Server Name: %s\n", dh->ServerName);
	printf("Client Name: %s\n", dh->ClientName);
	printf("map Name: %s\n", dh->MapName);
	printf("Game Directory: %s\n", dh->GameDirectory);
	printf("Demo Duration (Seconds): %f\n", dh->duration);
	printf("Demo Ticks: %d\n", dh->ticks);
	printf("Demo Frames: %d\n", dh->frames);
	printf("Demo Sign on length: %d\n", dh->signOnLenght);
}

int main()
{   
	DemoHeader dh = readDemoHeader("F:\\Projects\\DML-DeMoList\\demo\\auto0-20220508-182807-1705382547-de_nuke-Opta-Allyance_CKRAS.dem");
	printDemoHeader(&dh);
	

	return 0;
}