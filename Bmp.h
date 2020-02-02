#pragma once
#ifndef BITMAP_H
#define BITMAP_H

struct BMP_Header {
	char Tipo[2];
	int Tamano;
	char Reservado[4];
	int OffsetData;
};

struct BMP_InfoHeader {
	int Tamano;
	int Anchura;
	int Altura;
	char Planes[2];
	char ContadorBits[2];
	int Compresion;
	int TamanoImagen;
	int Pixeles_X;
	int Pixeles_Y;
	int Colores_Usados;
	int Colores_Importantes;
};

class Bitmap
{
private:
	BMP_Header Header;
	BMP_InfoHeader InfoHeader;
public:
	Bitmap ();
	Bitmap (char*);
	void ObtenerBmp_Header(char*);
	void ObtenerBmp_InfoHeader (char*);
};
#endif // !BITMAP_H

