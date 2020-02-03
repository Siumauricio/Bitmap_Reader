#include "Bmp.h"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

Bitmap::Bitmap () {}

Bitmap::Bitmap (char* Filename) {
	ObtenerBmp_Header (Filename);
	ObtenerBmp_InfoHeader (Filename);
}

void Bitmap::ObtenerBmp_Header (char* Filename) {
	ifstream File;
	File.open (Filename, ifstream::in | ifstream::binary);
	char* Header_Posiciones =new char[sizeof(BMP_Header)];
	File.read (Header_Posiciones, sizeof (BMP_Header));
	char informacion[4];
	int Posicion_Byte = 1;
	int Posicion_Info = 0;


	for (int i = 1; i <= 4; i++) {
		informacion[Posicion_Info] = Header_Posiciones[Posicion_Byte + i];
		if (i == 4) {
			if (Posicion_Byte == 1) {
				memcpy (&Header.Tamano, informacion, 4);
			} else if (Posicion_Byte == 9) {
				memcpy (&Header.OffsetData, informacion, 4);
				break;
			}
			Posicion_Byte += (i * 2);
			i = 0;
			Posicion_Info = 0;
		} else {
			Posicion_Info++;
		}
	}
	cout << setw (15) << "Header" << endl;
	cout << "Tipo: " << Header_Posiciones[0]<< Header_Posiciones[1] << endl;
	cout << "Tamano Archivo: " << Header.Tamano << endl;
	cout << "Espacio Reservado: " << sizeof (Header.Reservado) << endl;
	cout << "DataOffset: " << Header.OffsetData << endl;
	cout << endl;
	File.close ();
}

void Bitmap::ObtenerBmp_InfoHeader (char* Filename) {
	ifstream File;
	File.open (Filename, ifstream::in | ifstream::binary);
	if (File.fail ()) {
		return;
	}
	char* Info_Posiciones = new char[sizeof (BMP_InfoHeader)+sizeof(BMP_Header)];
	File.read (Info_Posiciones, sizeof (BMP_InfoHeader) + sizeof (BMP_Header));
	char informacion[4];
	int Posicion_Byte = 17;
	int Posicion_Info = 0;

	for (int i = 1; i <= 4; i++) {
		informacion[Posicion_Info] = Info_Posiciones[Posicion_Byte + i];
		if (i == 2 && Posicion_Byte == 25) {
			memcpy (&InfoHeader.Planes, informacion, 2);
			Posicion_Byte = 27;
			Posicion_Info = 0;
			i = 0;
			int x = 0;
		} else if (i == 2 && Posicion_Byte == 27) {
			memcpy (&InfoHeader.ContadorBits, informacion, 2);
			Posicion_Byte = 29;
			Posicion_Info = 0;
			i = 0;
		} else if (i == 4) {
			if (Posicion_Byte == 17) {
				memcpy (&InfoHeader.Anchura, informacion, 4);
				Posicion_Byte = 21;
			} else if (Posicion_Byte == 21) {
				memcpy (&InfoHeader.Altura, informacion, 4);
				Posicion_Byte = 25;
			} else if (Posicion_Byte == 29) {
				memcpy (&InfoHeader.Compresion, informacion, 4);
				Posicion_Byte = 33;
			} else if (Posicion_Byte == 33) {
				memcpy (&InfoHeader.TamanoImagen, informacion, 4);
				Posicion_Byte = 37;
			} else if (Posicion_Byte == 37) {
				memcpy (&InfoHeader.Pixeles_X, informacion, 4);
				Posicion_Byte = 41;
			} else if (Posicion_Byte == 41) {
				memcpy (&InfoHeader.Pixeles_Y, informacion, 4);
				Posicion_Byte = 45;
			} else if (Posicion_Byte == 45) {
				memcpy (&InfoHeader.Colores_Usados, informacion, 4);
				Posicion_Byte = 49;
			} else if (Posicion_Byte == 49) {
				memcpy (&InfoHeader.Colores_Importantes, informacion, 4);
				break;
			}
			Posicion_Info = 0;
			i = 0;
		} else {
			Posicion_Info++;
		}
	}
	cout << setw (15) << "Infoheader" << endl;
	cout << "Tamano: " << sizeof (BMP_InfoHeader) << endl;
	cout << "Anchura: " << InfoHeader.Anchura << endl;
	cout << "Altura: " << InfoHeader.Altura << endl;
	cout << "Planos: " << (int)InfoHeader.Planes[0] << endl;
	cout << "Contador Bits: " << (int)InfoHeader.ContadorBits[0] << endl;
	cout << "Compresion: " << InfoHeader.Compresion << endl;
	cout << "Tamano Imagen: " << InfoHeader.TamanoImagen << endl;
	cout << "Pixel X: " << InfoHeader.Pixeles_X << endl;
	cout << "Pixel Y: " << InfoHeader.Pixeles_Y << endl;
	cout << "Colores U: " << InfoHeader.Colores_Usados << endl;
	cout << "Colores I: " << InfoHeader.Colores_Importantes << endl;
	File.close ();
}

