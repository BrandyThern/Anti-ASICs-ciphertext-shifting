#include "Variant256.h"


void HexToBytes(unsigned char* Target, unsigned char* Base) // No Error Checking
{
	int i;
	unsigned char Tmp;
	unsigned char c;
	for (i = 0; i < strlen(Base) - 1; i += 2)
	{
		c = Base[i];
		if (c > 47 && c < 58)
			Tmp = ((c - 48) << 4);
		else if (c > 64 && c < 71)
			Tmp = ((10 + (c - 65)) << 4);
		else if (c > 96 && c < 103)
			Tmp = ((10 + (c - 97)) << 4);

		c = Base[i + 1];
		if (c > 47 && c < 58)
			Tmp += (c - 48);
		else if (c > 64 && c < 71)
			Tmp += (10 + (c - 65));
		else if (c > 96 && c < 103)
			Tmp += (10 + (c - 97));
		Target[(i == 0) ? 0 : i / 2] = Tmp;
	}
}

void main()
{
	unsigned char Buffer[65];
	unsigned char CipherText[32];
	unsigned char ShiftedCipherText[32];
	int i;
	strcpy(Buffer, "834267f3ba3914325f7b218a9c69c9550e7a2f1f69690b0b4d48bbcc3fea3b0b");
	HexToBytes(CipherText, Buffer);
	for (i = 0; i < 32; i++)
	{
		printf("%02x", CipherText[i]);
	}
	printf("\n");
	ShiftCipherText(Buffer, CipherText);
	UnShiftCipherText(CipherText, Buffer);
	for (i = 0; i < 32; i++)
	{
		printf("%02x", CipherText[i]);
	}
	printf("\n");
}
