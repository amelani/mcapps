#include <cstdio>
#include <cstdlib>
using namespace std;

//Syntax: CopyPasteV3.exe <adt> <adt2> <x> <y> <x2> <y2>
int quadrat(int x, int y, int x2)
{
	for( ; x <= x2; ++x)
	{
		for(int y2 = x2; y2 >= y; --y2)
		{
			printf("x");
		}
		printf("\n");
	}
	return 0;
}

int main(int argc, char* argv[])
{
	int x, y, x2;
	char name [256];

	if(argc < 5)
	{
		printf("Syntax: CopyPasteV3.exe <adt> <adt2> <x> <y> <x2>");
		return 0;
	}
	FILE* input = fopen(argv[1], "rb");
	if(!input)
	{
		printf("Cannot open data.");
		return 0;
	}
	fseek(input, 0, SEEK_END);
	long size = ftell(input);
	fseek(input, 0, SEEK_SET);

	char* buffer = new char[size];
	fread(buffer, 1, size ,input);
	fclose(input);

	x = atoi(argv[3]);
	y = atoi(argv[4]);
	x2 = atoi(argv[5]);

	printf("\n");
	quadrat(x, y, x2);

	for( ; x <= x2; ++x)
	{	
		for(int y2 = x2; y2 >= y; --y2)
		{	
			if(x < 9 || y2 < 9)
			{
				sprintf_s(name,"%s_0%d_0%d.adt", argv[2], x, y2);
			}
			else
			{
				sprintf_s(name,"%s_%d_%d.adt", argv[2], x, y2);
			}
			FILE* output = fopen(name,"wb");
			if(!output)
			{
				printf("Cannot create data.");
				return 0;
			}
			fwrite(buffer, 1, size, output);
			
			fclose(output);
		}
	}

	delete[] buffer;

	return 0;
}