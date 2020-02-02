#include <iostream>
#include <fstream>
#include <limits>
#include <stdio.h>
#include <stdint.h> 
#include <inttypes.h>
#include <cstring>
#include "Bmp.h"
#pragma warning(disable:4996)
using namespace std;

int main () {
	Bitmap bmp((char*)"lena_gray.bmp");
	/*
	char bmp_header[14];
	int offs;
	char tipo[3];
	char offset[4];
	char str_size[4];
	ifstream file_bmp;
	int size;
	///InfoHeader
	char infoheader[40];
	char with_size[4];
	char height_size[4];
	int width;
	int height;

	file_bmp.open ("m.bmp", ifstream::in | ifstream::binary);
	file_bmp.read (bmp_header, sizeof (bmp_header));
	tipo[2] = '\0';
	tipo[0] = bmp_header[0];
	tipo[1] = bmp_header[1];

	cout << "Tipo: " << tipo << endl;
	str_size[0] = bmp_header[2];
	str_size[1] = bmp_header[3];
	str_size[2] = bmp_header[4];
	str_size[3] = bmp_header[5];
	memcpy (&size, str_size, 4);

	cout << "Size: " << size << endl;
	offset[0] = bmp_header[10];
	offset[1] = bmp_header[11];
	offset[2] = bmp_header[12];
	offset[3] = bmp_header[13];
	memcpy (&offs, offset, 4);
	cout << "Offs: " << offs << endl;
	//cout << (int)bmp_header[0] << " "<<(int)bmp_header[1] << bmp_header[2] << endl;
	//printf ("%c%c\n",bmp_header[0],bmp_header[1]);
	file_bmp.close();
	file_bmp.open ("m.bmp", ifstream::in | ifstream::binary);
	file_bmp.read (infoheader, sizeof (infoheader));

	//memcpy (&size2, str_size2, 4);
	cout << "Size: " << sizeof (infoheader) << endl;
	with_size[0] = infoheader[18];
	with_size[1] = infoheader[19];
	with_size[2] = infoheader[20];
	with_size[3] = infoheader[21];
	memcpy (&width, with_size, 4);
	cout << "Withd: " << width << endl;

	height_size[0] = infoheader[22];
	height_size[1] = infoheader[23];
	height_size[2] = infoheader[24];
	height_size[3] = infoheader[25];
	memcpy (&height, height_size, 4);
	cout << "Weight: " << height << endl;

	return 0;
	*/
}


