// 12d.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <conio.h> 
#include <time.h>
#include <iostream>
#include <windows.h>
#include <Shellapi.h>
#include <fstream>
#include <time.h>
#include <sys/timeb.h> // pomiar czasu 
#include <tchar.h>
using namespace std;

#define BITMAP_width11	0
#define BITMAP_height11	0

#define SLEEP			25

//#define LIMIT			64
//#define LIMIT			16


int szerokosc_1;
int wysokosc_1;
int szerokosc_2;
int wysokosc_2;

#pragma pack(push, 1)			// zeby nie dodawal sobie niepotrzebnych bitow (rozmiar nie podzielny przez 4) //

class Klasa {//source kuzyn: https://github.com/tom7c3
private:
    double *tablica; 
    int size; 
    int size2;
public: 
    Klasa(int SIZEX,int SIZEY,double v1):size(SIZEX),size2(SIZEY)
    {		//int SIZEY=SIZEX;
            //double **tablica = new double*[size];
			double **tablica = new double*[SIZEX*sizeof(int*)];
			for (int x = 0; x < SIZEX; x++) {
			//tablica[x] = new double[size2];
			tablica[x] = new double[SIZEY*sizeof(int)];
			}
        for (int i=0; i < SIZEX; i++)
        { 
			for (int j=0; j < SIZEY; j++)
			 {
            tablica[i][j] = v1;
            std::cout <<"  "<<SIZEX<<"  "<<SIZEY<<" tablica["<<i<<"]["<<j<<"] "<<tablica[i][j]<< "\n";
			system("pause");
			}
        }
        
    }

};

///////////////////


class cPixel11klasa
{//source kuzyn: https://github.com/tom7c3
public:
	char red11;
	char green11;
	char blue11;
};

class cdata1111klasa
{//source kuzyn: https://github.com/tom7c3
public:
 cPixel11klasa **pixel;
 int x, wysokosc_0;
 cdata1111klasa(){};
 cdata1111klasa(int wysokosc_0,int x);
 ~cdata1111klasa(); 
 int getx() {return x;}
 int gety() {return wysokosc_0;}
};

cdata1111klasa::cdata1111klasa(int wysokosc_0,int x)
 {//source kuzyn: https://github.com/tom7c3
  this->x = x;
  this->wysokosc_0 = wysokosc_0;
  pixel = new cPixel11klasa*[wysokosc_0];
  for ( int i = 0; i < wysokosc_0; ++i )
  {
   pixel[i] = new cPixel11klasa[x];
  }
 }

cdata1111klasa::~cdata1111klasa()
 {  //source kuzyn: https://github.com/tom7c3 
	 this->wysokosc_0 = wysokosc_0;
	 for(int i = 0; i < wysokosc_0; i++) 
	 delete[] pixel[i];
	 delete[] pixel;
 };

class cheadline11BMP11klasa
{//source kuzyn: https://github.com/tom7c3
public:
	char znaki11[2];
	long int rozmiar_plikui11;
	short int liczba_int111;
	short int liczba_int211;
	long int poczatek_danych11;
	long dlugosc;
	long x1;
	long y1;
	short warstwy11;
	short bity11;
	long kompresja11;
	long rozmiar_rysunku11;
	long rozdz_poz11;
	long rozdz_pion11;
	long kolory11;
	long reszta11;
};

class cBMP11klasa
{
public:
	void loadBMP11(cheadline11BMP11klasa*, cdata1111klasa*, std::string);
} bmp11;

#pragma pack(pop)
//////////////////////
cdata1111klasa* data11;//////////////
cdata1111klasa* actual_bitmap11;/////////////
cdata1111klasa* actual_bitmap12;/////////////
cdata1111klasa* actual_bitmap13;/////////////
///////////////////////
//int width11;
//int height11;
int *table11;
POINT po1;
int width11;
int height11;
FILE *control_file11;
///////////////////////

void cBMP11klasa::loadBMP11(cheadline11BMP11klasa* headline11, cdata1111klasa* data11, std::string path)
{//source kuzyn: https://github.com/tom7c3
	FILE *bmpfile;
	
	if ( (bmpfile = fopen (path.c_str(), "rb")) == NULL )
	{
		std::cout << "nieprawid³owa sciezka" << std::endl;
		return ;
	}
	fread (headline11, sizeof(cheadline11BMP11klasa), 1, bmpfile);
	// ladowanie danych //
	fseek (bmpfile, headline11->poczatek_danych11, 0);
	for ( int y = 0; y < wysokosc_1; ++y )
	{
		for ( int x = 0; x < szerokosc_1; ++x )
		{
			data11->pixel[y][x].blue11 = fgetc(bmpfile);
			data11->pixel[y][x].green11 = fgetc(bmpfile);
			data11->pixel[y][x].red11 = fgetc(bmpfile);
			//std::cout <<"pixel["<<y<<"]["<<x<<"] "<<data11->pixel[y][x].blue11<<" "<<data11->pixel[y][x].green11<<" "<<data11->pixel[y][x].red11<< std::endl;
		}
		//if ( headline11->x1 % 2 != 0 )
		//	fgetc(bmpfile);				// pobieranie wartosci 0 niepotrzebnej (w plikach bmp po kazdym wierszu jest dodawana wartosc char zerowa)
	}
	fclose (bmpfile);	
}	
	
void load_templates11(cheadline11BMP11klasa* headline11)
{
	bmp11.loadBMP11(headline11, &data11[0], "c://1/szablony4/0.bmp");
	bmp11.loadBMP11(headline11, &data11[1], "c://1/szablony4/1.bmp");	
	bmp11.loadBMP11(headline11, &data11[2], "c://1/szablony4/2.bmp");
	bmp11.loadBMP11(headline11, &data11[3], "c://1/szablony4/3.bmp");
	bmp11.loadBMP11(headline11, &data11[4], "c://1/szablony4/4.bmp");
	bmp11.loadBMP11(headline11, &data11[5], "c://1/szablony4/5.bmp");
	bmp11.loadBMP11(headline11, &data11[6], "c://1/szablony4/6.bmp");
	bmp11.loadBMP11(headline11, &data11[7], "c://1/szablony4/11.bmp");
	bmp11.loadBMP11(headline11, &data11[8], "c://1/szablony4/12.bmp");
	bmp11.loadBMP11(headline11, &data11[9], "c://1/szablony4/13.bmp");
	bmp11.loadBMP11(headline11, &data11[10], "c://1/szablony4/14.bmp");
	bmp11.loadBMP11(headline11, &data11[11], "c://1/szablony4/15.bmp");
	bmp11.loadBMP11(headline11, &data11[12], "c://1/szablony4/16.bmp");
	bmp11.loadBMP11(headline11, &data11[13], "c://1/szablony4/21.bmp");
	bmp11.loadBMP11(headline11, &data11[14], "c://1/szablony4/22.bmp");
	bmp11.loadBMP11(headline11, &data11[15], "c://1/szablony4/23.bmp");
	bmp11.loadBMP11(headline11, &data11[16], "c://1/szablony4/24.bmp");
	bmp11.loadBMP11(headline11, &data11[17], "c://1/szablony4/25.bmp");
	bmp11.loadBMP11(headline11, &data11[18], "c://1/szablony4/26.bmp");
}
void create_new_bitmap111(BITMAPINFO* bi1, HWND window,_TCHAR* str,int x2,int y2)//
{
//source:
//https://msdn.microsoft.com/pl-pl/library/windows/desktop/dd183402(v=vs.85).aspx
//https://4programmers.net/Forum/C_i_C++/71931-C++_Zrzuty_ekranu

//https://www.codeproject.com/script/Content/ViewAssociatedFile.aspx?rzp=%2FKB%2Ffiles%2Fzip_utils%2F%2Fzip_utils_src.zip&zep=examples%2Fsimple%2Fsimple.cpp&obid=7530&obtid=2&ovid=1
	HANDLE hf1;
	HDC sdc1 = GetWindowDC(window);
	BYTE *bits1; 
	HBITMAP hbm1 = CreateDIBSection(sdc1,bi1,DIB_RGB_COLORS,(void**)&bits1,NULL,0);
	HDC hdc1 = CreateCompatibleDC(sdc1); 
	HGDIOBJ hold = SelectObject(hdc1,hbm1);
	//StretchBlt(hdc1,0,0,bw,bh,sdc1,0,0,w1,h1,SRCCOPY);
	//StretchBlt(hdc1,0,0,bw,bh,sdc1,BITMAP_width11,BITMAP_height11,w1,h1,SRCCOPY);
	BitBlt(hdc1,(-788+x2),(-297+y2),1600,1600,sdc1,BITMAP_width11,BITMAP_height11,SRCCOPY);	

	SelectObject(hdc1,hold); 
	DeleteDC(hdc1); 
	ReleaseDC(0,sdc1);

	hf1=CreateFile((LPTSTR) str,GENERIC_WRITE,0,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
	BITMAPFILEHEADER bfh1; 
	ZeroMemory(&bfh1,sizeof(bfh1));
	bfh1.bfType=0x4d42; 
	bfh1.bfOffBits=sizeof(BITMAPFILEHEADER)+bi1->bmiHeader.biSize;
	bfh1.bfSize=bfh1.bfOffBits+bi1->bmiHeader.biSizeImage; 
	bfh1.bfReserved1=0; 
	bfh1.bfReserved2=0;
	DWORD writ; 
	WriteFile(hf1,& bfh1, sizeof(bfh1), &writ, NULL);
	WriteFile(hf1, &bi1->bmiHeader, sizeof(bi1->bmiHeader), &writ, NULL);
	WriteFile(hf1, bits1, bi1->bmiHeader.biSizeImage, &writ, NULL);
	CloseHandle(hf1);
	DeleteObject(hbm1);	
}
////////////////////////////////////////////////////////////////
void create_new_bitmap112(BITMAPINFO* bi1, HWND window)//
{
//source:
//https://msdn.microsoft.com/pl-pl/library/windows/desktop/dd183402(v=vs.85).aspx
//https://4programmers.net/Forum/C_i_C++/71931-C++_Zrzuty_ekranu

//https://www.codeproject.com/script/Content/ViewAssociatedFile.aspx?rzp=%2FKB%2Ffiles%2Fzip_utils%2F%2Fzip_utils_src.zip&zep=examples%2Fsimple%2Fsimple.cpp&obid=7530&obtid=2&ovid=1

	HANDLE hf1;
	HDC sdc1 = GetWindowDC(window);
	BYTE *bits1; 
	HBITMAP hbm1 = CreateDIBSection(sdc1,bi1,DIB_RGB_COLORS,(void**)&bits1,NULL,0);
	HDC hdc1 = CreateCompatibleDC(sdc1); 
	HGDIOBJ hold = SelectObject(hdc1,hbm1);
	//StretchBlt(hdc1,0,0,bw,bh,sdc1,0,0,w1,h1,SRCCOPY);
	//StretchBlt(hdc1,0,0,bw,bh,sdc1,BITMAP_width11,BITMAP_height11,w1,h1,SRCCOPY);
/*1*/	BitBlt(hdc1,(-788),(-297),1600,1600,sdc1,BITMAP_width11,BITMAP_height11,SRCCOPY);	

	SelectObject(hdc1,hold); 
	DeleteDC(hdc1); 
	ReleaseDC(0,sdc1);

	hf1=CreateFile(_T("sample104.bmp"),GENERIC_WRITE,0,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
	BITMAPFILEHEADER bfh1; 
	ZeroMemory(&bfh1,sizeof(bfh1));
	bfh1.bfType=0x4d42; 
	bfh1.bfOffBits=sizeof(BITMAPFILEHEADER)+bi1->bmiHeader.biSize;
	bfh1.bfSize=bfh1.bfOffBits+bi1->bmiHeader.biSizeImage; 
	bfh1.bfReserved1=0; 
	bfh1.bfReserved2=0;
	DWORD writ; 
	WriteFile(hf1,& bfh1, sizeof(bfh1), &writ, NULL);
	WriteFile(hf1, &bi1->bmiHeader, sizeof(bi1->bmiHeader), &writ, NULL);
	WriteFile(hf1, bits1, bi1->bmiHeader.biSizeImage, &writ, NULL);
	CloseHandle(hf1);
	DeleteObject(hbm1);	
}
////////////////////////////////////////////////////////////////
void create_new_bitmap113(BITMAPINFO* bi1, HWND window)//
{
//source:
//https://msdn.microsoft.com/pl-pl/library/windows/desktop/dd183402(v=vs.85).aspx
//https://4programmers.net/Forum/C_i_C++/71931-C++_Zrzuty_ekranu

//https://www.codeproject.com/script/Content/ViewAssociatedFile.aspx?rzp=%2FKB%2Ffiles%2Fzip_utils%2F%2Fzip_utils_src.zip&zep=examples%2Fsimple%2Fsimple.cpp&obid=7530&obtid=2&ovid=1

	HANDLE hf1;
	HDC sdc1 = GetWindowDC(window);
	BYTE *bits1; 
	HBITMAP hbm1 = CreateDIBSection(sdc1,bi1,DIB_RGB_COLORS,(void**)&bits1,NULL,0);
	HDC hdc1 = CreateCompatibleDC(sdc1); 
	HGDIOBJ hold = SelectObject(hdc1,hbm1);
	//StretchBlt(hdc1,0,0,bw,bh,sdc1,0,0,w1,h1,SRCCOPY);
	//StretchBlt(hdc1,0,0,bw,bh,sdc1,BITMAP_width11,BITMAP_height11,w1,h1,SRCCOPY);
/*1*/	BitBlt(hdc1,(-788),(-297),1600,1600,sdc1,BITMAP_width11,BITMAP_height11,SRCCOPY);	

	SelectObject(hdc1,hold); 
	DeleteDC(hdc1); 
	ReleaseDC(0,sdc1);

	hf1=CreateFile(_T("sample105.bmp"),GENERIC_WRITE,0,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
	BITMAPFILEHEADER bfh1; 
	ZeroMemory(&bfh1,sizeof(bfh1));
	bfh1.bfType=0x4d42; 
	bfh1.bfOffBits=sizeof(BITMAPFILEHEADER)+bi1->bmiHeader.biSize;
	bfh1.bfSize=bfh1.bfOffBits+bi1->bmiHeader.biSizeImage; 
	bfh1.bfReserved1=0; 
	bfh1.bfReserved2=0;
	DWORD writ; 
	WriteFile(hf1,& bfh1, sizeof(bfh1), &writ, NULL);
	WriteFile(hf1, &bi1->bmiHeader, sizeof(bi1->bmiHeader), &writ, NULL);
	WriteFile(hf1, bits1, bi1->bmiHeader.biSizeImage, &writ, NULL);
	CloseHandle(hf1);
	DeleteObject(hbm1);	
}
////////////////////////////////////////////////////////////////
int find_bitmap11(int m)
{
	bool _break = false;
	int counter = 0;
	int actual_number = -1;

	for ( int i = 1; i < 7; ++i )
	{
		for ( int y = 0; y < wysokosc_1; ++y )
		{
			for ( int x = 0; x < 10; ++x )//for ( int x = 0; x < szerokosc_1; ++x )
			{
				if ( (abs((int)actual_bitmap11[m].pixel[y][x].blue11) <= abs((int)data11[i].pixel[y][x].blue11)-2) ||(abs((int)actual_bitmap11[m].pixel[y][x].blue11) >= abs((int)data11[i].pixel[y][x].blue11)+2)
					|| (abs((int)actual_bitmap11[m].pixel[y][x].green11) <= abs((int)data11[i].pixel[y][x].green11)-2)||(abs((int)actual_bitmap11[m].pixel[y][x].green11) >= abs((int)data11[i].pixel[y][x].green11)+2)
					|| (abs((int)actual_bitmap11[m].pixel[y][x].red11) <= abs((int)data11[i].pixel[y][x].red11)-2)||(abs((int)actual_bitmap11[m].pixel[y][x].red11) >= abs((int)data11[i].pixel[y][x].red11)+2) ) 
				{
					//cout<<"wysokosc= "<<j<<"  szerokosc=  "<<k<<endl;
					//cout<<"1.  "<<abs((int)actual_bitmap11[m].pixel[y][x].blue11)<<" = "<<abs((int)data11[i].pixel[y][x].blue11)<<"    "<<abs((int)actual_bitmap11[m].pixel[y][x].green11)<<" = "<<abs((int)data11[i].pixel[y][x].green11)<<"    "<<abs((int)actual_bitmap11[m].pixel[y][x].red11)<<" = "<<abs((int)data11[i].pixel[y][x].red11)<<endl;
					//_break = true;
					//counter = 0;
					//break;
				}
				else
				{
					++counter;
					//std::cout << counter << ".. " << std::endl;
				}
				//cout<<"2.  "<<abs((int)actual_bitmap11[m].pixel[y][x].blue11)<<" = "<<abs((int)data11[i].pixel[y][x].blue11)<<"    "<<abs((int)actual_bitmap11[m].pixel[y][x].green11)<<" = "<<abs((int)data11[i].pixel[y][x].green11)<<"    "<<abs((int)actual_bitmap11[m].pixel[y][x].red11)<<" = "<<abs((int)data11[i].pixel[y][x].red11)<<endl;
				
				if ( (counter >= 10*wysokosc_1-20))
				{
					actual_number = i;
				    cout<<"i="<<i<<endl;
				//	std::cout << "Bitmapy sa sobie rowne_1" << std::endl;
				//	std::cout<< actual_number  << std::endl;
					//std::cout<< "2. counter= "<< counter << ".. " << std::endl;
				//	std::cout<< "1. counter= "<< counter<< "  .m= "<<m<< std::endl;
				//	system("pause");
					counter = 0;
					goto spr;
				//	_break = true;
				//	break;
				}
				else if(y>=wysokosc_1-1&&x>=9&&i>=6)
				{
					//std::cout << "Bitmapy sa nierowne_1" << std::endl;
					//std::cout<< "2. counter= "<< counter<< "  .m= "<<m<< std::endl;
					//goto spr;
					//cout<<"..i="<<i<<endl;
					//system("pause");
					_break = true;
					counter = 0;
					break;
				}			
			}
			if ( _break == true )
			{
				_break = false;
				break;
			}	
		}
		counter = 0;
		if ( actual_number != -1 )
			break;
	}
	return actual_number;
	spr:;
	//////////////////////////
	for ( int i = 1; i < 7; ++i )
	{
		for ( int y = 0; y < wysokosc_1; ++y )
		{
			for ( int x = 10; x < 16; ++x )
			{
				if ( (abs((int)actual_bitmap11[m].pixel[y][x].blue11) <= abs((int)data11[i].pixel[y][x].blue11)-2) ||(abs((int)actual_bitmap11[m].pixel[y][x].blue11) >= abs((int)data11[i].pixel[y][x].blue11)+2)
					|| (abs((int)actual_bitmap11[m].pixel[y][x].green11) <= abs((int)data11[i].pixel[y][x].green11)-2)||(abs((int)actual_bitmap11[m].pixel[y][x].green11) >= abs((int)data11[i].pixel[y][x].green11)+2)
					|| (abs((int)actual_bitmap11[m].pixel[y][x].red11) <= abs((int)data11[i].pixel[y][x].red11)-2)||(abs((int)actual_bitmap11[m].pixel[y][x].red11) >= abs((int)data11[i].pixel[y][x].red11)+2) ) 
				{				
					//_break = true;
					//counter = 0;
					//break;
				}
				else
				{
					++counter;
					//std::cout << counter << ".. " << std::endl;
				}
				
				if (counter >= 6*wysokosc_1-5)
				{
					actual_number = i;
				//	std::cout << "Bitmapy sa sobie rowne_2" << std::endl;
				//	std::cout<< actual_number  << std::endl;
				//	std::cout<< "11. counter= "<< counter << ".. " << std::endl;
				//	cout<<"..i="<<i<<endl;
				//	system("pause");
					_break = true;
					counter = 0;
					break;
				}
				else if(y>=wysokosc_1-1&&x>=15&&i>=6)
				{
				//	std::cout <<"Bitmapy sa nierowne_2" << std::endl;
				//	std::cout<< "12. counter= "<< counter<< "  .m= "<<m<< std::endl;
				//	cout<<"..i="<<i<<endl;
				//	system("pause");
					counter = 0;
					goto spr2;
				}
				
			}
			if ( _break == true )
			{
				_break = false;
				break;
			}	
		}counter = 0;
		if ( actual_number != -1 )
			break;
	}
	return actual_number;
	spr2:;
	//////////////////////////
	int flag1=0;
	for ( int i = 7; i < 13; ++i )
	{
		if(i==7){flag1=5;}
		if(i==8){flag1=7;}
		if(i==9){flag1=9;}
		if(i==10){flag1=8;}
		if(i==11){flag1=3;}
		if(i==12){flag1=0;}
		for ( int y = 0; y < wysokosc_1; ++y )
		{
			int m1=11;
			for ( int x = 11+flag1; x < 20+flag1; ++x )
			{
				if ( (abs((int)actual_bitmap11[m].pixel[y][x].blue11) <= abs((int)data11[i].pixel[m1][x].blue11)-2) ||(abs((int)actual_bitmap11[m].pixel[y][x].blue11) >= abs((int)data11[i].pixel[m1][x].blue11)+2)
					|| (abs((int)actual_bitmap11[m].pixel[y][x].green11) <= abs((int)data11[i].pixel[m1][x].green11)-2)||(abs((int)actual_bitmap11[m].pixel[y][x].green11) >= abs((int)data11[i].pixel[m1][x].green11)+2)
					|| (abs((int)actual_bitmap11[m].pixel[y][x].red11) <= abs((int)data11[i].pixel[m1][x].red11)-2)||(abs((int)actual_bitmap11[m].pixel[y][x].red11) >= abs((int)data11[i].pixel[m1][x].red11)+2) ) 
				{				
					//_break = true;
					//counter = 0;
					//break;
				}
				else
				{
					++counter;
					//std::cout << counter << ".. " << std::endl;
				}

				m1++;

				if (counter >= wysokosc_1*9-3)
				{
					std::cout <<"Bitmapy sa sobie rowne_3"<< std::endl;
					actual_number = i;
				//	std::cout<< actual_number  << std::endl;
					//std::cout<< "2. counter= "<< counter << ".. " << std::endl;
					cout<<"..i="<<i<<endl;
					system("pause");
					_break = true;
					counter = 0;
					break;
				}
				else if(y>=wysokosc_1-1&&x>=15&&i>=12)
				{
					std::cout <<"Bitmapy sa nierowne_3"<< std::endl;
					std::cout<< "2. counter= "<< counter<< "  .m= "<<m<< std::endl;
					cout<<"..i="<<i<<endl;
					system("pause");
					counter = 0;
					goto spr3;
				}
				
			}
			if ( _break == true )
			{
				_break = false;
				break;
			}	
		}
		counter = 0;
		if ( actual_number != -1 )
			break;
	}
	return actual_number;

	spr3:;
	//////////////////////////
	int flag2=0;
	for ( int i = 13; i < 19; ++i )
	{
		if(i==13){flag2=5;}
		if(i==14){flag2=7;}
		if(i==15){flag2=9;}
		if(i==16){flag2=8;}
		if(i==17){flag2=3;}
		if(i==18){flag2=0;}
		for ( int y = 0; y < wysokosc_1; ++y )
		{
			for ( int x = 11+flag2; x < 20+flag2; ++x )
			{
				if ( (abs((int)actual_bitmap11[m].pixel[y][x].blue11) <= abs((int)data11[i].pixel[y][x].blue11)-2) ||(abs((int)actual_bitmap11[m].pixel[y][x].blue11) >= abs((int)data11[i].pixel[y][x].blue11)+2)
					|| (abs((int)actual_bitmap11[m].pixel[y][x].green11) <= abs((int)data11[i].pixel[y][x].green11)-2)||(abs((int)actual_bitmap11[m].pixel[y][x].green11) >= abs((int)data11[i].pixel[y][x].green11)+2)
					|| (abs((int)actual_bitmap11[m].pixel[y][x].red11) <= abs((int)data11[i].pixel[y][x].red11)-2)||(abs((int)actual_bitmap11[m].pixel[y][x].red11) >= abs((int)data11[i].pixel[y][x].red11)+2) ) 
				{				
					//_break = true;
					//counter = 0;
					//break;
				}
				else
				{
					++counter;
					//std::cout << counter << ".. " << std::endl;
				}
				
				if (counter >= wysokosc_1*9-3)
				{
				//	std::cout << "w spr:; ,Bitmapy sa sobie rowne" << std::endl;
					actual_number = i;
				//	std::cout<< actual_number  << std::endl;
					//std::cout<< "2. counter= "<< counter << ".. " << std::endl;
					_break = true;
					counter = 0;
					break;
				}
				else if(y>=wysokosc_1-1&&x>=15&&i>=18)
				{
					std::cout <<"w spr3x:; ,Bitmapy sa nierowne" << std::endl;
				//	std::cout<< "2. counter= "<< counter<< "  .m= "<<m<< std::endl;
				//	goto spr4;
					_break = true;
					counter = 0;
					break;			
				}
				
			}
			if ( _break == true )
			{
				_break = false;
				break;
			}	
		}counter = 0;
		if ( actual_number != -1 )
			break;
	}
	return actual_number;

}
////////////////////////////////////////////////////////////////
int find_bitmap12()
{
	bool _break = false;
	int counter = 0;
	int actual_number = -1;

	for ( int i = 0; i < 1; ++i )
	{
		for ( int j = 0; j < wysokosc_2; ++j )
		{
			for ( int k = 0; k < szerokosc_2; ++k )
			{
				if ( (actual_bitmap12->pixel[j][k].blue11 != actual_bitmap13->pixel[j][k].blue11)
					|| (actual_bitmap12->pixel[j][k].green11 != actual_bitmap13->pixel[j][k].green11 )
					||( actual_bitmap12->pixel[j][k].red11 != actual_bitmap13->pixel[j][k].red11) ) 
				{
				//	std::cout << "x2 Bitmapy sa nierowne" << std::endl;
				//	std::cout << actual_number << " . " << std::endl;
				//	std::cout<< "1. counter= "<< counter << ".. " << std::endl;
				//	_break = true;
				//	counter = 0;
				//	break;
				}
				else
				{
					++counter;
				}
				
				if ( counter >= (szerokosc_2*wysokosc_2)/1.15f )
				{
				//	std::cout << "x2 Bitmapy sa sobie rowne" << std::endl;
					actual_number = i;
				//	std::cout << actual_number << " . " << std::endl;
				//	std::cout<< "2. counter= "<< counter << ".. " << std::endl;
					_break = true;
					counter = 0;
					break;
				}
				
			}
			if ( _break == true )
			{
				_break = false;
				break;
			}	
		}counter = 0;
		if ( actual_number != -1 )
			break;
	}
	return actual_number;
}
//////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
	srand((int) time(0));
	szerokosc_1=29;//x
	wysokosc_1=10;//y

	//cout<<"podaj x"<<endl;
	//cin>>szerokosc_1;
	//cout<<"podaj y"<<endl;
	//cin>>wysokosc_1;	
	cout<<"x="<<szerokosc_1<<endl;
	cout<<"y="<<wysokosc_1<<endl;

	szerokosc_2=400;
	wysokosc_2=360;
	data11=new cdata1111klasa[56];//////////////////////
	for(int i=0;i<56;i++)
	{
	data11[i].cdata1111klasa::cdata1111klasa(wysokosc_1,szerokosc_1);//////////////
	}
	actual_bitmap11=new cdata1111klasa[64];/////////////////////////
	//actual_bitmap11->cdata1111klasa::cdata1111klasa(wysokosc_1,szerokosc_1);////////////////	
	actual_bitmap12=new cdata1111klasa;/////////////////////////
	actual_bitmap12->cdata1111klasa::cdata1111klasa(wysokosc_2,szerokosc_2);////////////////
	actual_bitmap13=new cdata1111klasa;/////////////////////////
	actual_bitmap13->cdata1111klasa::cdata1111klasa(wysokosc_2,szerokosc_2);////////////////
	for(int i=0;i<64;i++)
	{
	actual_bitmap11[i].cdata1111klasa::cdata1111klasa(wysokosc_1,szerokosc_1);//////////////
	}
	//actual_bitmap11=new cdata1111klasa[1];/////////////////////////
	//actual_bitmap11[0].cdata1111klasa::cdata1111klasa(wysokosc_1,szerokosc_1);////////////////	
	//system("pause");

	//SetCursorPos(width11+200, height11+200);		
	//mouse_event(MOUSEEVENTF_LEFTDOWN,0 ,0,0,0);

	//Sleep(100);
	cheadline11BMP11klasa headline11;
	int x1 = szerokosc_1;
	int y1 = wysokosc_1;
	int _y1 = 0;
	headline11.znaki11[0] = 'B';
	headline11.znaki11[1] = 'M';
	headline11.rozmiar_plikui11 = sizeof(cPixel11klasa)*x1*y1 + sizeof(cheadline11BMP11klasa)+_y1;
	headline11.liczba_int111 = 0;
	headline11.liczba_int211 = 0;
	headline11.poczatek_danych11 = 54;
	headline11.dlugosc = 40;
	headline11.x1 = x1;
	headline11.y1 = y1;
	headline11.warstwy11 = 1;
	headline11.bity11 = 24;
	headline11.kompresja11 = 0;
	headline11.rozmiar_rysunku11 = sizeof(cPixel11klasa)*x1*y1 + _y1;
	headline11.rozdz_poz11 = 0;
	headline11.rozdz_pion11 = 0;
	headline11.kolory11 = 0;
	headline11.reszta11 = 0;
	load_templates11(&headline11);	
	//system("pause");
/////////////////////////////////////
	int w11 = szerokosc_1, h11 = wysokosc_1;
	int bw1 = szerokosc_1, bh1 = wysokosc_1;
	int bw41=(bw1+3)&0xFFFFFFFC;
	//HANDLE hf;	
	BITMAPINFO bi1; 
	bi1.bmiHeader.biBitCount=24; 
	bi1.bmiHeader.biClrImportant=0;
    bi1.bmiHeader.biClrUsed=0;
	bi1.bmiHeader.biCompression=BI_RGB; 
	bi1.bmiHeader.biHeight=bh1;
    bi1.bmiHeader.biPlanes=1; 
	bi1.bmiHeader.biSize=40; 
	bi1.bmiHeader.biSizeImage=bw41*bh1*3;
	//bi1.bmiHeader.biSizeImage=bw*bh*3;
    bi1.bmiHeader.biWidth=bw1; 
	bi1.bmiHeader.biXPelsPerMeter=3780; 
	bi1.bmiHeader.biYPelsPerMeter=3780;
    bi1.bmiColors[0].rgbBlue=0; 
	bi1.bmiColors[0].rgbGreen=0; 
	bi1.bmiColors[0].rgbRed=0; 
	bi1.bmiColors[0].rgbReserved=0;
	//Sleep(1000);
		int w12 = szerokosc_2, h12 = wysokosc_2;
	int bw2 = szerokosc_2, bh2 = wysokosc_2;
	int bw42=(bw2+3)&0xFFFFFFFC;
	//HANDLE hf;	
	BITMAPINFO bi2; 
	bi2.bmiHeader.biBitCount=24; 
	bi2.bmiHeader.biClrImportant=0;
    bi2.bmiHeader.biClrUsed=0;
	bi2.bmiHeader.biCompression=BI_RGB; 
	bi2.bmiHeader.biHeight=bh2;
    bi2.bmiHeader.biPlanes=1; 
	bi2.bmiHeader.biSize=40; 
	bi2.bmiHeader.biSizeImage=bw42*bh2*3;
	//bi1.bmiHeader.biSizeImage=bw*bh*3;
    bi2.bmiHeader.biWidth=bw2; 
	bi2.bmiHeader.biXPelsPerMeter=3780; 
	bi2.bmiHeader.biYPelsPerMeter=3780;
    bi2.bmiColors[0].rgbBlue=0; 
	bi2.bmiColors[0].rgbGreen=0; 
	bi2.bmiColors[0].rgbRed=0; 
	bi2.bmiColors[0].rgbReserved=0;
	//Sleep(1000);
	cheadline11BMP11klasa headline12;
	int x2 = szerokosc_2;//wys
	int y2 = wysokosc_2;//szer
	int _y2 = 0;
	headline12.znaki11[0] = 'B';
	headline12.znaki11[1] = 'M';
	headline12.rozmiar_plikui11 = sizeof(cPixel11klasa)*x2*y2 + sizeof(cheadline11BMP11klasa)+_y2;
	headline12.liczba_int111 = 0;
	headline12.liczba_int211 = 0;
	headline12.poczatek_danych11 = 54;
	headline12.dlugosc = 40;
	headline12.x1 = x2;
	headline12.y1 = y2;
	headline12.warstwy11 = 1;
	headline12.bity11 = 24;
	headline12.kompresja11 = 0;
	headline12.rozmiar_rysunku11 = sizeof(cPixel11klasa)*x2*y2 + _y2;
	headline12.rozdz_poz11 = 0;
	headline12.rozdz_pion11 = 0;
	headline12.kolory11 = 0;
	headline12.reszta11 = 0;
	//system("pause");

	po1.x = BITMAP_width11;
	po1.y = BITMAP_height11;
	POINT p1;
	HWND he1,hf1;
	GetCursorPos(&p1);
	//he = WindowFromPoint(p1);
	he1=GetDesktopWindow();
//he1=FindWindow(_T("IEFrame"),_T("WorldWinner Cash Competitions on GSN - Windows Internet Explorer"));
	//hf1 = WindowFromPoint(po1);
	//ClientToScreen(he,&po1);
	width11 = po1.x;
	height11 = po1.y;


////////////////////////////////////////
	_TCHAR str[64][15]={
		{_T("sample1.bmp")},
		{_T("sample2.bmp")},
		{_T("sample3.bmp")},
		{_T("sample4.bmp")},
		{_T("sample5.bmp")},
		{_T("sample6.bmp")},
		{_T("sample7.bmp")},
		{_T("sample8.bmp")},
		{_T("sample9.bmp")},
		{_T("sample10.bmp")},
		{_T("sample11.bmp")},
		{_T("sample12.bmp")},
		{_T("sample13.bmp")},
		{_T("sample14.bmp")},
		{_T("sample15.bmp")},
		{_T("sample16.bmp")},
		{_T("sample17.bmp")},
		{_T("sample18.bmp")},
		{_T("sample19.bmp")},
		{_T("sample20.bmp")},
		{_T("sample21.bmp")},
		{_T("sample22.bmp")},
		{_T("sample23.bmp")},
		{_T("sample24.bmp")},
		{_T("sample25.bmp")},
		{_T("sample26.bmp")},
		{_T("sample27.bmp")},
		{_T("sample28.bmp")},
		{_T("sample29.bmp")},
		{_T("sample30.bmp")},
		{_T("sample31.bmp")},
		{_T("sample32.bmp")},
		{_T("sample33.bmp")},
		{_T("sample34.bmp")},
		{_T("sample35.bmp")},
		{_T("sample36.bmp")},
		{_T("sample37.bmp")},
		{_T("sample38.bmp")},
		{_T("sample39.bmp")},
		{_T("sample40.bmp")},
		{_T("sample41.bmp")},
		{_T("sample42.bmp")},
		{_T("sample43.bmp")},
		{_T("sample44.bmp")},
		{_T("sample45.bmp")},
		{_T("sample46.bmp")},
		{_T("sample47.bmp")},
		{_T("sample48.bmp")},
		{_T("sample49.bmp")},
		{_T("sample50.bmp")},
		{_T("sample51.bmp")},
		{_T("sample52.bmp")},
		{_T("sample53.bmp")},
		{_T("sample54.bmp")},
		{_T("sample55.bmp")},
		{_T("sample56.bmp")},
		{_T("sample57.bmp")},
		{_T("sample58.bmp")},
		{_T("sample59.bmp")},
		{_T("sample60.bmp")},
		{_T("sample61.bmp")},
		{_T("sample62.bmp")},
		{_T("sample63.bmp")},
		{_T("sample64.bmp")}}; 
	
	char str2[64][15]={
		{"sample1.bmp"},
		{"sample2.bmp"},
		{"sample3.bmp"},
		{"sample4.bmp"},
		{"sample5.bmp"},
		{"sample6.bmp"},
		{"sample7.bmp"},
		{"sample8.bmp"},
		{"sample9.bmp"},
		{"sample10.bmp"},
		{"sample11.bmp"},
		{"sample12.bmp"},
		{"sample13.bmp"},
		{"sample14.bmp"},
		{"sample15.bmp"},
		{"sample16.bmp"},
		{"sample17.bmp"},
		{"sample18.bmp"},
		{"sample19.bmp"},
		{"sample20.bmp"},
		{"sample21.bmp"},
		{"sample22.bmp"},
		{"sample23.bmp"},
		{"sample24.bmp"},
		{"sample25.bmp"},
		{"sample26.bmp"},
		{"sample27.bmp"},
		{"sample28.bmp"},
		{"sample29.bmp"},
		{"sample30.bmp"},
		{"sample31.bmp"},
		{"sample32.bmp"},
		{"sample33.bmp"},
		{"sample34.bmp"},
		{"sample35.bmp"},
		{"sample36.bmp"},
		{"sample37.bmp"},
		{"sample38.bmp"},
		{"sample39.bmp"},
		{"sample40.bmp"},
		{"sample41.bmp"},
		{"sample42.bmp"},
		{"sample43.bmp"},
		{"sample44.bmp"},
		{"sample45.bmp"},
		{"sample46.bmp"},
		{"sample47.bmp"},
		{"sample48.bmp"},
		{"sample49.bmp"},
		{"sample50.bmp"},
		{"sample51.bmp"},
		{"sample52.bmp"},
		{"sample53.bmp"},
		{"sample54.bmp"},
		{"sample55.bmp"},
		{"sample56.bmp"},
		{"sample57.bmp"},
		{"sample58.bmp"},
		{"sample59.bmp"},
		{"sample60.bmp"},
		{"sample61.bmp"},
		{"sample62.bmp"},
		{"sample63.bmp"},
		{"sample64.bmp"}}; 
/////////////////////////////////////
	    //pID mozemy znalesc w cmd za pomoca polecenia --> tasklist
		DWORD *pID2 = new DWORD();//4bytes
        cout << "D:\\1\\gra 2 CLR v0.57a.exe"<<endl;
         //getchar();
        HWND testWindow2 = FindWindow(_T("ConsoleWindowClass"),_T("D:\\1\\gra 2 CLR v0.57a.exe"));
        //HWND testWindow = FindWindow(_L("ConsoleWindowClass"),_L("D:\\test1.exe")); //w UNICODE
       
        if(testWindow2 == NULL)
        {
           cout << "nie znaleziono okna2";
           getchar();
 /*.....*///          return 0;
        }
        else
        {
           cout << "Znaleziono oknoa2 \n";
        }
        GetWindowThreadProcessId(testWindow2, pID2);
        if(*pID2 == 0)
        {
           cout << "Nie znaleziono id procesu2 ";
           getchar();
 /*.....*///         return 0;
       }
        else
        {
           cout << "Znaleziono id procesu2:" << *pID2 << "\n";
           cout << "Znaleziono id procesu2:" << (unsigned int)*pID2 << "\n";
        }

        //HANDLE pHandletestu = OpenProcess(PROCESS_ALL_ACCESS, false, *pID);
        //HANDLE pHandletestu = OpenProcess(PROCESS_VM_READ | PROCESS_QUERY_INFORMATION, false, *pID);
        HANDLE pHandletestu2 = OpenProcess(PROCESS_VM_READ, false, *pID2);
        if(pHandletestu2 == NULL)
        {
           cout << "nie mo¿na otworzyæ procesu2 ";
           getchar();
  /*.....*///        return 0;
        }
        else
        {
           cout << "Otworzono proces2 \n";
        }
        //SetForegroundWindow(testWindow2);
		delete pID2;	
////////////////////////////////////////////

	srand((int) time(0));
	int tab_gry[8][8];
	int tab_gry_tmp[8][8]={-1};
	int a1=-1,a2=-2,a3=-3;
	int b1=-1,b2=-2,b3=-3,b4=-4;	
	int index10=0;
	int zmienna=0;
	int tab_ruchu[100][30][6]={0};
	int runda2=0;
	int licznik=0;
	int nr_indexu=0;
	int flaga5=0;
	int licznik2=0;

od_nowa:;
	licznik2=0;
	nr_indexu=0;
	flaga5=0;
	runda2=0;
	cout<<"start podaj opoznienie od 0 do 1000"<<endl;
	cin>>zmienna;
	//system("pause");

for(int runda=0;runda<16000;runda++)
{
	int index=0;
jeszczeraz:;


	if(kbhit()==1){goto od_nowa;}

	index10=0;

	SetForegroundWindow(testWindow2);	
	Sleep(rand()%50+170);
	
	
	for(int i3=0;i3<8;i3++)
	{
		for(int y3=0;y3<8;y3++)
		{
			if(i3==0){create_new_bitmap111(&bi1,he1,str[8*i3+y3],-y3*55-14,0-29);}
			if(i3==1){create_new_bitmap111(&bi1,he1,str[8*i3+y3],-y3*55-14,-54-29);}
			if(i3==2){create_new_bitmap111(&bi1,he1,str[8*i3+y3],-y3*55-14,-2*54-1-29);}
			if(i3==3){create_new_bitmap111(&bi1,he1,str[8*i3+y3],-y3*55-14,-2*54-55-29);}
			if(i3==4){create_new_bitmap111(&bi1,he1,str[8*i3+y3],-y3*55-14,-2*54-2*55-29);}
			if(i3==5){create_new_bitmap111(&bi1,he1,str[8*i3+y3],-y3*55-14,-3*54-2*55-29);}
			if(i3==6){create_new_bitmap111(&bi1,he1,str[8*i3+y3],-y3*55-14,-4*54-2*55-1-29);}
			if(i3==7){create_new_bitmap111(&bi1,he1,str[8*i3+y3],-y3*55-14,-4*54-3*55-29);}
		}
	}

	for(int i3=0;i3<8;i3++)
	{
		for(int y3=0;y3<8;y3++)
		{
			bmp11.loadBMP11(&headline11, &actual_bitmap11[8*i3+y3],str2[8*i3+y3]);

		}
	}
	//bmp11.loadBMP11(&headline11, &actual_bitmap11[0], "sample3.bmp");
	//bmp11.loadBMP11(&headline11, actual_bitmap11, "sample3.bmp");

	/////
	bmp11.loadBMP11(&headline12, actual_bitmap12, "sample105.bmp");
	create_new_bitmap112(&bi2,he1);//zapisuje do sample4
	bmp11.loadBMP11(&headline12, actual_bitmap13, "sample104.bmp");
	int actual_number2 = find_bitmap12();

	if ( actual_number2 == 0 )
	{
		create_new_bitmap113(&bi2,he1);//zapisuje do sample105
		std::cout << "dobrze nastepna karta" << std::endl;
		//plik << "....dobrze nastepna karta  ,  actual_number1="<<actual_number1<< std::endl;
		
	}	
	else
	{
		create_new_bitmap113(&bi2,he1);//zapisuje do sample105
		goto jeszczeraz;
	}

	/////
	system("pause");

	for(int i3=0;i3<8;i3++)
	{
		for(int y3=0;y3<8;y3++)
		{
			jeszczeraz1:;
			if(kbhit()==1){goto od_nowa;}

			Sleep(4);
			int actual_number1 = find_bitmap11(8*i3+y3);
			if ( actual_number1 == -1 )
			{
				//actual_number1=2;
			//	cout<<"  "<<actual_number1<<endl;
				index10++;			
				if(index10>=5){index10=0;goto jeszczeraz21;}
				goto jeszczeraz1;

				jeszczeraz21:;

			//	std::cout << "nieprawidlowy uchwyt okna, ustaw kursor na wlasciwe okno" << std::endl;
			//	system("pause");
			//	return 0;
			}
			cout<<"  "<<actual_number1<<endl;
			/*
			if(actual_number1==8){actual_number1=1;}
			if(actual_number1==9){actual_number1=2;}
			if(actual_number1==10){actual_number1=3;}
			if(actual_number1==11){actual_number1=4;}
			if(actual_number1==12){actual_number1=5;}
			if(actual_number1==13){actual_number1=6;}
			if(actual_number1==14){actual_number1=7;}
			*/
			tab_gry[i3][y3]=actual_number1;
		}
	}



	for(int i3=0;i3<8;i3++)
	{
		for(int y3=0;y3<8;y3++)
		{
			if(tab_gry_tmp[i3][y3]==tab_gry[i3][y3])
			{
				licznik++;
			}
		}
	}
	
	//if(licznik!=64){cout<<"licznik= "<<licznik<<endl;licznik=0;goto jeszczeraz;}	
	for(int i3=0;i3<8;i3++)
	{
		for(int y3=0;y3<8;y3++)
		{

			cout<<"  "<<tab_gry[i3][y3];
			tab_gry_tmp[i3][y3]=tab_gry[i3][y3];
		}
		cout<<endl;
	}

	SetForegroundWindow(testWindow2);
	for(int i3=0;i3<8;i3++)
	{
		for(int y3=0;y3<8;y3++)
		{
			if(tab_gry[i3][y3]==-1){cout<<endl;system("pause");}
		}
	}

	system("pause");


////////////////////////////////////////////
////////////////////////////////////////////			
	for(int y4=7;y4>=0;y4--)//od dolu do gory
	{
		for(int x4=0;x4<8;x4++) //od lewa do prawa
		{
			int flaga111=0;
			for (int ii2=0;ii2<4;ii2++){if(tab_gry[y4][x4-1]==tab_gry[y4][x4+ii2]&&ii2!=0&&x4+3<=7&&x4-1>=0){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4-1]>=13&&tab_gry[y4][x4-1]<=18){cout<<"1101  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4-1]>=7 &&tab_gry[y4][x4-1]<=12){cout<<"1201  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4-1]>=1 &&tab_gry[y4][x4-1]<=6 ){cout<<"1301  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4-1;tab_ruchu[nr_indexu][0][1]=y4;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4][x4-1]<<"  "<<tab_gry[y4][x4+1]<<"  "<<tab_gry[y4][x4+2]<<"  "<<tab_gry[y4][x4+3]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////
			for (int ii2=0;ii2<4;ii2++){if(tab_gry[y4][x4+4]==tab_gry[y4][x4+ii2]&&ii2!=3&&x4+4<=7){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"1102  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"1202  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"1302  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+4;tab_ruchu[nr_indexu][0][1]=y4;
				tab_ruchu[nr_indexu][0][2]=x4+3;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4][x4]<<"  "<<tab_gry[y4][x4+1]<<"  "<<tab_gry[y4][x4+2]<<"  "<<tab_gry[y4][x4+4]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////
			for (int ii2=0;ii2<4;ii2++){if(tab_gry[y4+1][x4]==tab_gry[y4][x4+ii2]&&ii2!=0&&x4+3<=7&&y4+1<=7){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4+1]>=13&&tab_gry[y4][x4+1]<=18){cout<<"1103  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4+1]>=7 &&tab_gry[y4][x4+1]<=12){cout<<"1203  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4+1]>=1 &&tab_gry[y4][x4+1]<=6 ){cout<<"1303  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4;tab_ruchu[nr_indexu][0][1]=y4+1;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4+1][x4]<<"  "<<tab_gry[y4][x4+1]<<"  "<<tab_gry[y4][x4+2]<<"  "<<tab_gry[y4][x4+3]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////
			for (int ii2=1;ii2<4;ii2++){if(tab_gry[y4-1][x4]==tab_gry[y4][x4+ii2]&&ii2!=0&&x4+3<=7&&y4-1>=0){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4+1]>=13&&tab_gry[y4][x4+1]<=18){cout<<"1104  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4+1]>=7 &&tab_gry[y4][x4+1]<=12){cout<<"1204  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4+1]>=1 &&tab_gry[y4][x4+1]<=6 ){cout<<"1304  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4;tab_ruchu[nr_indexu][0][1]=y4-1;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4-1][x4]<<"  "<<tab_gry[y4][x4+1]<<"  "<<tab_gry[y4][x4+2]<<"  "<<tab_gry[y4][x4+3]<<endl;
				nr_indexu++;
			}
			flaga111=0;			
			//////////
			for (int ii2=0;ii2<4;ii2++){if(tab_gry[y4+1][x4+1]==tab_gry[y4][x4+ii2]&&ii2!=1&&x4+3<=7&&y4+1<=7){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"1105  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"1205  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"1305  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+1;tab_ruchu[nr_indexu][0][1]=y4+1;
				tab_ruchu[nr_indexu][0][2]=x4+1;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4+1][x4+1]<<"  "<<tab_gry[y4][x4]<<"  "<<tab_gry[y4][x4+2]<<"  "<<tab_gry[y4][x4+3]<<endl;
				nr_indexu++;
			}
			flaga111=0;			
			//////////
			for (int ii2=0;ii2<4;ii2++){if(tab_gry[y4-1][x4+1]==tab_gry[y4][x4+ii2]&&ii2!=1&&x4+3<=7&&y4-1>=0){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"1106  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"1206  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"1306  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+1;tab_ruchu[nr_indexu][0][1]=y4-1;
				tab_ruchu[nr_indexu][0][2]=x4+1;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4-1][x4+1]<<"  "<<tab_gry[y4][x4]<<"  "<<tab_gry[y4][x4+2]<<"  "<<tab_gry[y4][x4+3]<<endl;
				nr_indexu++;
			}
			flaga111=0;			
			//////////
			for (int ii2=0;ii2<4;ii2++){if(tab_gry[y4+1][x4+2]==tab_gry[y4][x4+ii2]&&ii2!=2&&x4+3<=7&&y4+1<=7){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"1107  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"1207  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"1307  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+2;tab_ruchu[nr_indexu][0][1]=y4+1;
				tab_ruchu[nr_indexu][0][2]=x4+2;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4+1][x4+2]<<"  "<<tab_gry[y4][x4]<<"  "<<tab_gry[y4][x4+1]<<"  "<<tab_gry[y4][x4+3]<<endl;
				nr_indexu++;
			}
			flaga111=0;			
			//////////
			for (int ii2=0;ii2<4;ii2++){if(tab_gry[y4-1][x4+2]==tab_gry[y4][x4+ii2]&&ii2!=2&&x4+3<=7&&y4-1>=0){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"1108  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"1208  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"1308  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+2;tab_ruchu[nr_indexu][0][1]=y4-1;
				tab_ruchu[nr_indexu][0][2]=x4+2;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4-1][x4+2]<<"  "<<tab_gry[y4][x4]<<"  "<<tab_gry[y4][x4+1]<<"  "<<tab_gry[y4][x4+3]<<endl;
				nr_indexu++;
			}
			flaga111=0;			
			//////////
			for (int ii2=0;ii2<4;ii2++){if(tab_gry[y4+1][x4+3]==tab_gry[y4][x4+ii2]&&ii2!=3&&x4+3<=7&&y4+1<=7){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"1109  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"1209  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"1309  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+3;tab_ruchu[nr_indexu][0][1]=y4+1;
				tab_ruchu[nr_indexu][0][2]=x4+3;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4+1][x4+3]<<"  "<<tab_gry[y4][x4]<<"  "<<tab_gry[y4][x4+1]<<"  "<<tab_gry[y4][x4+2]<<endl;
				nr_indexu++;
			}
			flaga111=0;			
			//////////
			for (int ii2=0;ii2<4;ii2++){if(tab_gry[y4-1][x4+3]==tab_gry[y4][x4+ii2]&&ii2!=3&&x4+3<=7&&y4-1>=0){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"1110  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"1210  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"1310  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+3;tab_ruchu[nr_indexu][0][1]=y4-1;
				tab_ruchu[nr_indexu][0][2]=x4+3;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4-1][x4+3]<<"  "<<tab_gry[y4][x4]<<"  "<<tab_gry[y4][x4+1]<<"  "<<tab_gry[y4][x4+2]<<endl;
				nr_indexu++;
			}
			flaga111=0;			
			//////////////////////////////
			for (int ii2=0;ii2<4;ii2++){if(tab_gry[y4-1][x4]==tab_gry[y4+ii2][x4]&&ii2!=0&&y4-1>=0&&y4+3<=7){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4+1][x4]>=13&&tab_gry[y4+1][x4]<=18){cout<<"1111  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4+1][x4]>=7 &&tab_gry[y4+1][x4]<=12){cout<<"1211  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4+1][x4]>=1 &&tab_gry[y4+1][x4]<=6 ){cout<<"1311  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4;tab_ruchu[nr_indexu][0][1]=y4-1;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4-1][x4]<<"  "<<tab_gry[y4+1][x4]<<"  "<<tab_gry[y4+2][x4]<<"  "<<tab_gry[y4+3][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////
			for (int ii2=0;ii2<4;ii2++){if(tab_gry[y4+4][x4]==tab_gry[y4+ii2][x4]&&ii2!=3&&y4+4<=7){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"1112  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"1212  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"1312  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4;tab_ruchu[nr_indexu][0][1]=y4+4;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4+3;
				cout<<tab_gry[y4+4][x4]<<"  "<<tab_gry[y4][x4]<<"  "<<tab_gry[y4+1][x4]<<"  "<<tab_gry[y4+2][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;			
			//////////
			for (int ii2=0;ii2<4;ii2++){if(tab_gry[y4][x4+1]==tab_gry[y4+ii2][x4]&&ii2!=0&&y4+3<=7&&x4+1<=7){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4+1][x4]>=13&&tab_gry[y4+1][x4]<=18){cout<<"1113  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4+1][x4]>=7 &&tab_gry[y4+1][x4]<=12){cout<<"1213  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4+1][x4]>=1 &&tab_gry[y4+1][x4]<=6 ){cout<<"1313  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+1;tab_ruchu[nr_indexu][0][1]=y4;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4][x4+1]<<"  "<<tab_gry[y4+1][x4]<<"  "<<tab_gry[y4+2][x4]<<"  "<<tab_gry[y4+3][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;			
			//////////
			for (int ii2=0;ii2<4;ii2++){if(tab_gry[y4][x4-1]==tab_gry[y4+ii2][x4]&&ii2!=0&&y4+3<=7&&x4-1>=0){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4+1][x4]>=13&&tab_gry[y4+1][x4]<=18){cout<<"1114  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4+1][x4]>=7 &&tab_gry[y4+1][x4]<=12){cout<<"1214  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4+1][x4]>=1 &&tab_gry[y4+1][x4]<=6 ){cout<<"1314  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4-1;tab_ruchu[nr_indexu][0][1]=y4;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4][x4-1]<<"  "<<tab_gry[y4+1][x4]<<"  "<<tab_gry[y4+2][x4]<<"  "<<tab_gry[y4+3][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;			
			//////////
		    for (int ii2=0;ii2<4;ii2++){if(tab_gry[y4+1][x4+1]==tab_gry[y4+ii2][x4]&&ii2!=1&&y4+3<=7&&x4+1<=7){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"1115  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"1215  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"1315  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+1;tab_ruchu[nr_indexu][0][1]=y4+1;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4+1;
				cout<<tab_gry[y4+1][x4+1]<<"  "<<tab_gry[y4+0][x4]<<"  "<<tab_gry[y4+2][x4]<<"  "<<tab_gry[y4+3][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;			
			//////////
		    for (int ii2=0;ii2<4;ii2++){if(tab_gry[y4+1][x4-1]==tab_gry[y4+ii2][x4]&&ii2!=1&&y4+3<=7&&x4-1>=0){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"1116  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"1216  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"1316  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4-1;tab_ruchu[nr_indexu][0][1]=y4+1;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4+1;
				cout<<tab_gry[y4+1][x4-1]<<"  "<<tab_gry[y4+0][x4]<<"  "<<tab_gry[y4+2][x4]<<"  "<<tab_gry[y4+3][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;			
			//////////
		     for (int ii2=0;ii2<4;ii2++){if(tab_gry[y4+2][x4+1]==tab_gry[y4+ii2][x4]&&ii2!=2&&y4+3<=7&&x4+1<=7){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"1117  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"1217  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"1317  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+1;tab_ruchu[nr_indexu][0][1]=y4+2;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4+2;
				cout<<tab_gry[y4+2][x4+1]<<"  "<<tab_gry[y4+0][x4]<<"  "<<tab_gry[y4+1][x4]<<"  "<<tab_gry[y4+3][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;			
			//////////
		    for (int ii2=0;ii2<4;ii2++){if(tab_gry[y4+2][x4-1]==tab_gry[y4+ii2][x4]&&ii2!=2&&y4+3<=7&&x4-1>=0){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"1118  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"1218  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"1318  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4-1;tab_ruchu[nr_indexu][0][1]=y4+2;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4+2;
				cout<<tab_gry[y4+2][x4-1]<<"  "<<tab_gry[y4+0][x4]<<"  "<<tab_gry[y4+1][x4]<<"  "<<tab_gry[y4+3][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;			
			//////////
		     for (int ii2=0;ii2<4;ii2++){if(tab_gry[y4+3][x4+1]==tab_gry[y4+ii2][x4]&&ii2!=3&&y4+3<=7&&x4+1<=7){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"1119  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"1219  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"1319  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+1;tab_ruchu[nr_indexu][0][1]=y4+3;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4+3;
				cout<<tab_gry[y4+3][x4+1]<<"  "<<tab_gry[y4+0][x4]<<"  "<<tab_gry[y4+1][x4]<<"  "<<tab_gry[y4+2][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;			
			//////////
		    for (int ii2=0;ii2<4;ii2++){if(tab_gry[y4+3][x4-1]==tab_gry[y4+ii2][x4]&&ii2!=3&&y4+3<=7&&x4-1>=0){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"1120  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"1220  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"1320  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4-1;tab_ruchu[nr_indexu][0][1]=y4+3;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4+3;
				cout<<tab_gry[y4+3][x4-1]<<"  "<<tab_gry[y4+0][x4]<<"  "<<tab_gry[y4+1][x4]<<"  "<<tab_gry[y4+2][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;			
		    ////////////////////////////////////////
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4][x4-1]-6==tab_gry[y4][x4+1]&&tab_gry[y4][x4-1]-6==tab_gry[y4][x4+2]&&tab_gry[y4][x4-1]-6==tab_gry[y4][x4+3])||
				  (tab_gry[y4][x4-1]==tab_gry[y4][x4+1]-6&&tab_gry[y4][x4-1]==tab_gry[y4][x4+2]  &&tab_gry[y4][x4-1]==tab_gry[y4][x4+3])||
				  (tab_gry[y4][x4-1]==tab_gry[y4][x4+1]  &&tab_gry[y4][x4-1]==tab_gry[y4][x4+2]-6&&tab_gry[y4][x4-1]==tab_gry[y4][x4+3])||
				  (tab_gry[y4][x4-1]==tab_gry[y4][x4+1]  &&tab_gry[y4][x4-1]==tab_gry[y4][x4+2]  &&tab_gry[y4][x4-1]==tab_gry[y4][x4+3]-6))
				  &&x4+3<=7&&x4-1>=0)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4-1]>=13&&tab_gry[y4][x4-1]<=18){cout<<"2101  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4-1]>=7 &&tab_gry[y4][x4-1]<=12){cout<<"2201  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4-1]>=1 &&tab_gry[y4][x4-1]<=6 ){cout<<"2301  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4-1;tab_ruchu[nr_indexu][0][1]=y4;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4][x4-1]<<"  "<<tab_gry[y4][x4+1]<<"  "<<tab_gry[y4][x4+2]<<"  "<<tab_gry[y4][x4+3]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4][x4+4]-6==tab_gry[y4][x4+0]&&tab_gry[y4][x4+4]-6==tab_gry[y4][x4+1]&&tab_gry[y4][x4+4]-6==tab_gry[y4][x4+2])||
				  (tab_gry[y4][x4+4]==tab_gry[y4][x4+0]-6&&tab_gry[y4][x4+4]==tab_gry[y4][x4+1]  &&tab_gry[y4][x4+4]==tab_gry[y4][x4+2])||
				  (tab_gry[y4][x4+4]==tab_gry[y4][x4+0]  &&tab_gry[y4][x4+4]==tab_gry[y4][x4+1]-6&&tab_gry[y4][x4+4]==tab_gry[y4][x4+2])||
				  (tab_gry[y4][x4+4]==tab_gry[y4][x4+0]  &&tab_gry[y4][x4+4]==tab_gry[y4][x4+1]  &&tab_gry[y4][x4+4]==tab_gry[y4][x4+2]-6))
				  &&x4+4<=7)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"2102  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"2202  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"2302  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+4;tab_ruchu[nr_indexu][0][1]=y4;
				tab_ruchu[nr_indexu][0][2]=x4+3;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4][x4+4]<<"  "<<tab_gry[y4][x4+0]<<"  "<<tab_gry[y4][x4+1]<<"  "<<tab_gry[y4][x4+2]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4+1][x4+0]-6==tab_gry[y4][x4+1]&&tab_gry[y4+1][x4+0]-6==tab_gry[y4][x4+2]&&tab_gry[y4+1][x4+0]-6==tab_gry[y4][x4+3])||
				  (tab_gry[y4+1][x4+0]==tab_gry[y4][x4+1]-6&&tab_gry[y4+1][x4+0]==tab_gry[y4][x4+2]  &&tab_gry[y4+1][x4+0]==tab_gry[y4][x4+3])||
				  (tab_gry[y4+1][x4+0]==tab_gry[y4][x4+1]  &&tab_gry[y4+1][x4+0]==tab_gry[y4][x4+2]-6&&tab_gry[y4+1][x4+0]==tab_gry[y4][x4+3])||
				  (tab_gry[y4+1][x4+0]==tab_gry[y4][x4+1]  &&tab_gry[y4+1][x4+0]==tab_gry[y4][x4+2]  &&tab_gry[y4+1][x4+0]==tab_gry[y4][x4+3]-6))
				  &&x4+3<=7&&y4+1<=7)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4+1]>=13&&tab_gry[y4][x4+1]<=18){cout<<"2103  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4+1]>=7 &&tab_gry[y4][x4+1]<=12){cout<<"2203  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4+1]>=1 &&tab_gry[y4][x4+1]<=6 ){cout<<"2303  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+0;tab_ruchu[nr_indexu][0][1]=y4+1;
				tab_ruchu[nr_indexu][0][2]=x4+0;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4+1][x4+0]<<"  "<<tab_gry[y4][x4+1]<<"  "<<tab_gry[y4][x4+2]<<"  "<<tab_gry[y4][x4+3]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4-1][x4+0]-6==tab_gry[y4][x4+1]&&tab_gry[y4-1][x4+0]-6==tab_gry[y4][x4+2]&&tab_gry[y4-1][x4+0]-6==tab_gry[y4][x4+3])||
				  (tab_gry[y4-1][x4+0]==tab_gry[y4][x4+1]-6&&tab_gry[y4-1][x4+0]==tab_gry[y4][x4+2]  &&tab_gry[y4-1][x4+0]==tab_gry[y4][x4+3])||
				  (tab_gry[y4-1][x4+0]==tab_gry[y4][x4+1]  &&tab_gry[y4-1][x4+0]==tab_gry[y4][x4+2]-6&&tab_gry[y4-1][x4+0]==tab_gry[y4][x4+3])||
				  (tab_gry[y4-1][x4+0]==tab_gry[y4][x4+1]  &&tab_gry[y4-1][x4+0]==tab_gry[y4][x4+2]  &&tab_gry[y4-1][x4+0]==tab_gry[y4][x4+3]-6))
				  &&x4+3<=7&&y4-1>=0)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4+1]>=13&&tab_gry[y4][x4+1]<=18){cout<<"2104  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4+1]>=7 &&tab_gry[y4][x4+1]<=12){cout<<"2204  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4+1]>=1 &&tab_gry[y4][x4+1]<=6 ){cout<<"2304  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+0;tab_ruchu[nr_indexu][0][1]=y4-1;
				tab_ruchu[nr_indexu][0][2]=x4+0;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4-1][x4+0]<<"  "<<tab_gry[y4][x4+1]<<"  "<<tab_gry[y4][x4+2]<<"  "<<tab_gry[y4][x4+3]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4+1][x4+1]-6==tab_gry[y4][x4+0]&&tab_gry[y4+1][x4+1]-6==tab_gry[y4][x4+2]&&tab_gry[y4+1][x4+1]-6==tab_gry[y4][x4+3])||
				  (tab_gry[y4+1][x4+1]==tab_gry[y4][x4+0]-6&&tab_gry[y4+1][x4+1]==tab_gry[y4][x4+2]  &&tab_gry[y4+1][x4+1]==tab_gry[y4][x4+3])||
				  (tab_gry[y4+1][x4+1]==tab_gry[y4][x4+0]  &&tab_gry[y4+1][x4+1]==tab_gry[y4][x4+2]-6&&tab_gry[y4+1][x4+1]==tab_gry[y4][x4+3])||
				  (tab_gry[y4+1][x4+1]==tab_gry[y4][x4+0]  &&tab_gry[y4+1][x4+1]==tab_gry[y4][x4+2]  &&tab_gry[y4+1][x4+1]==tab_gry[y4][x4+3]-6))
				  &&x4+3<=7&&y4+1<=7)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"2105  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"2205  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"2305  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+1;tab_ruchu[nr_indexu][0][1]=y4+1;
				tab_ruchu[nr_indexu][0][2]=x4+1;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4+1][x4+1]<<"  "<<tab_gry[y4][x4+0]<<"  "<<tab_gry[y4][x4+2]<<"  "<<tab_gry[y4][x4+3]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4-1][x4+1]-6==tab_gry[y4][x4+0]&&tab_gry[y4-1][x4+1]-6==tab_gry[y4][x4+2]&&tab_gry[y4-1][x4+1]-6==tab_gry[y4][x4+3])||
				  (tab_gry[y4-1][x4+1]==tab_gry[y4][x4+0]-6&&tab_gry[y4-1][x4+1]==tab_gry[y4][x4+2]  &&tab_gry[y4-1][x4+1]==tab_gry[y4][x4+3])||
				  (tab_gry[y4-1][x4+1]==tab_gry[y4][x4+0]  &&tab_gry[y4-1][x4+1]==tab_gry[y4][x4+2]-6&&tab_gry[y4-1][x4+1]==tab_gry[y4][x4+3])||
				  (tab_gry[y4-1][x4+1]==tab_gry[y4][x4+0]  &&tab_gry[y4-1][x4+1]==tab_gry[y4][x4+2]  &&tab_gry[y4-1][x4+1]==tab_gry[y4][x4+3]-6))
				  &&x4+3<=7&&y4-1>=0)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"2106  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"2206  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"2306  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+1;tab_ruchu[nr_indexu][0][1]=y4-1;
				tab_ruchu[nr_indexu][0][2]=x4+1;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4-1][x4+1]<<"  "<<tab_gry[y4][x4+0]<<"  "<<tab_gry[y4][x4+2]<<"  "<<tab_gry[y4][x4+3]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4+1][x4+2]-6==tab_gry[y4][x4+0]&&tab_gry[y4+1][x4+2]-6==tab_gry[y4][x4+1]&&tab_gry[y4+1][x4+2]-6==tab_gry[y4][x4+3])||
				  (tab_gry[y4+1][x4+2]==tab_gry[y4][x4+0]-6&&tab_gry[y4+1][x4+2]==tab_gry[y4][x4+1]  &&tab_gry[y4+1][x4+2]==tab_gry[y4][x4+3])||
				  (tab_gry[y4+1][x4+2]==tab_gry[y4][x4+0]  &&tab_gry[y4+1][x4+2]==tab_gry[y4][x4+1]-6&&tab_gry[y4+1][x4+2]==tab_gry[y4][x4+3])||
				  (tab_gry[y4+1][x4+2]==tab_gry[y4][x4+0]  &&tab_gry[y4+1][x4+2]==tab_gry[y4][x4+1]  &&tab_gry[y4+1][x4+2]==tab_gry[y4][x4+3]-6))
				  &&x4+3<=7&&y4+1<=7)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"2107  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"2207  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"2307  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+2;tab_ruchu[nr_indexu][0][1]=y4+1;
				tab_ruchu[nr_indexu][0][2]=x4+2;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4+1][x4+2]<<"  "<<tab_gry[y4][x4+0]<<"  "<<tab_gry[y4][x4+1]<<"  "<<tab_gry[y4][x4+3]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4-1][x4+2]-6==tab_gry[y4][x4+0]&&tab_gry[y4-1][x4+2]-6==tab_gry[y4][x4+1]&&tab_gry[y4-1][x4+2]-6==tab_gry[y4][x4+3])||
				  (tab_gry[y4-1][x4+2]==tab_gry[y4][x4+0]-6&&tab_gry[y4-1][x4+2]==tab_gry[y4][x4+1]  &&tab_gry[y4-1][x4+2]==tab_gry[y4][x4+3])||
				  (tab_gry[y4-1][x4+2]==tab_gry[y4][x4+0]  &&tab_gry[y4-1][x4+2]==tab_gry[y4][x4+1]-6&&tab_gry[y4-1][x4+2]==tab_gry[y4][x4+3])||
				  (tab_gry[y4-1][x4+2]==tab_gry[y4][x4+0]  &&tab_gry[y4-1][x4+2]==tab_gry[y4][x4+1]  &&tab_gry[y4-1][x4+2]==tab_gry[y4][x4+3]-6))
				  &&x4+3<=7&&y4-1>=0)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"2108  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"2208  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"2308  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+2;tab_ruchu[nr_indexu][0][1]=y4-1;
				tab_ruchu[nr_indexu][0][2]=x4+2;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4-1][x4+2]<<"  "<<tab_gry[y4][x4+0]<<"  "<<tab_gry[y4][x4+1]<<"  "<<tab_gry[y4][x4+3]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4+1][x4+3]-6==tab_gry[y4][x4+0]&&tab_gry[y4+1][x4+3]-6==tab_gry[y4][x4+1]&&tab_gry[y4+1][x4+3]-6==tab_gry[y4][x4+2])||
				  (tab_gry[y4+1][x4+3]==tab_gry[y4][x4+0]-6&&tab_gry[y4+1][x4+3]==tab_gry[y4][x4+1]  &&tab_gry[y4+1][x4+3]==tab_gry[y4][x4+2])||
				  (tab_gry[y4+1][x4+3]==tab_gry[y4][x4+0]  &&tab_gry[y4+1][x4+3]==tab_gry[y4][x4+1]-6&&tab_gry[y4+1][x4+3]==tab_gry[y4][x4+2])||
				  (tab_gry[y4+1][x4+3]==tab_gry[y4][x4+0]  &&tab_gry[y4+1][x4+3]==tab_gry[y4][x4+1]  &&tab_gry[y4+1][x4+3]==tab_gry[y4][x4+2]-6))
				  &&x4+3<=7&&y4+1<=7)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"2109  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"2209  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"2309  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+3;tab_ruchu[nr_indexu][0][1]=y4+1;
				tab_ruchu[nr_indexu][0][2]=x4+3;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4+1][x4+3]<<"  "<<tab_gry[y4][x4+0]<<"  "<<tab_gry[y4][x4+1]<<"  "<<tab_gry[y4][x4+2]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4-1][x4+3]-6==tab_gry[y4][x4+0]&&tab_gry[y4-1][x4+3]-6==tab_gry[y4][x4+1]&&tab_gry[y4-1][x4+3]-6==tab_gry[y4][x4+2])||
				  (tab_gry[y4-1][x4+3]==tab_gry[y4][x4+0]-6&&tab_gry[y4-1][x4+3]==tab_gry[y4][x4+1]  &&tab_gry[y4-1][x4+3]==tab_gry[y4][x4+2])||
				  (tab_gry[y4-1][x4+3]==tab_gry[y4][x4+0]  &&tab_gry[y4-1][x4+3]==tab_gry[y4][x4+1]-6&&tab_gry[y4-1][x4+3]==tab_gry[y4][x4+2])||
				  (tab_gry[y4-1][x4+3]==tab_gry[y4][x4+0]  &&tab_gry[y4-1][x4+3]==tab_gry[y4][x4+1]  &&tab_gry[y4-1][x4+3]==tab_gry[y4][x4+2]-6))
				  &&x4+3<=7&&y4-1>=0)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"2110  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"2210  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"2310  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+3;tab_ruchu[nr_indexu][0][1]=y4-1;
				tab_ruchu[nr_indexu][0][2]=x4+3;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4-1][x4+3]<<"  "<<tab_gry[y4][x4+0]<<"  "<<tab_gry[y4][x4+1]<<"  "<<tab_gry[y4][x4+2]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			////////////////////
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4-1][x4]-6==tab_gry[y4+1][x4]&&tab_gry[y4-1][x4]-6==tab_gry[y4+2][x4]&&tab_gry[y4-1][x4]-6==tab_gry[y4+3][x4])||
				  (tab_gry[y4-1][x4]==tab_gry[y4+1][x4]-6&&tab_gry[y4-1][x4]==tab_gry[y4+2][x4]  &&tab_gry[y4-1][x4]==tab_gry[y4+3][x4])||
				  (tab_gry[y4-1][x4]==tab_gry[y4+1][x4]  &&tab_gry[y4-1][x4]==tab_gry[y4+2][x4]-6&&tab_gry[y4-1][x4]==tab_gry[y4+3][x4])||
				  (tab_gry[y4-1][x4]==tab_gry[y4+1][x4]  &&tab_gry[y4-1][x4]==tab_gry[y4+2][x4]  &&tab_gry[y4-1][x4]==tab_gry[y4+3][x4]-6))
				  &&y4-1>=0&&y4+3<=7)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4+1][x4]>=13&&tab_gry[y4+1][x4]<=18){cout<<"2111  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4+1][x4]>=7 &&tab_gry[y4+1][x4]<=12){cout<<"2211  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4+1][x4]>=1 &&tab_gry[y4+1][x4]<=6 ){cout<<"2311  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4;tab_ruchu[nr_indexu][0][1]=y4-1;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4-1][x4]<<"  "<<tab_gry[y4+1][x4]<<"  "<<tab_gry[y4+2][x4]<<"  "<<tab_gry[y4+3][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////		
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4+4][x4]-6==tab_gry[y4+0][x4]&&tab_gry[y4+4][x4]-6==tab_gry[y4+1][x4]&&tab_gry[y4+4][x4]-6==tab_gry[y4+2][x4])||
				  (tab_gry[y4+4][x4]==tab_gry[y4+0][x4]-6&&tab_gry[y4+4][x4]==tab_gry[y4+1][x4]  &&tab_gry[y4+4][x4]==tab_gry[y4+2][x4])||
				  (tab_gry[y4+4][x4]==tab_gry[y4+0][x4]  &&tab_gry[y4+4][x4]==tab_gry[y4+1][x4]-6&&tab_gry[y4+4][x4]==tab_gry[y4+2][x4])||
				  (tab_gry[y4+4][x4]==tab_gry[y4+0][x4]  &&tab_gry[y4+4][x4]==tab_gry[y4+1][x4]  &&tab_gry[y4+4][x4]==tab_gry[y4+2][x4]-6))
				  &&y4+4<=7)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4+1][x4]>=13&&tab_gry[y4+1][x4]<=18){cout<<"2112  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4+1][x4]>=7 &&tab_gry[y4+1][x4]<=12){cout<<"2212  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4+1][x4]>=1 &&tab_gry[y4+1][x4]<=6 ){cout<<"2312  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4;tab_ruchu[nr_indexu][0][1]=y4+4;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4+3;
				cout<<tab_gry[y4+4][x4]<<"  "<<tab_gry[y4+0][x4]<<"  "<<tab_gry[y4+1][x4]<<"  "<<tab_gry[y4+2][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////			
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4+0][x4+1]-6==tab_gry[y4+1][x4]&&tab_gry[y4+0][x4+1]-6==tab_gry[y4+2][x4]&&tab_gry[y4+0][x4+1]-6==tab_gry[y4+3][x4])||
				   (tab_gry[y4+0][x4+1]==tab_gry[y4+1][x4]-6&&tab_gry[y4+0][x4+1]==tab_gry[y4+2][x4]  &&tab_gry[y4+0][x4+1]==tab_gry[y4+3][x4])||
				   (tab_gry[y4+0][x4+1]==tab_gry[y4+1][x4]  &&tab_gry[y4+0][x4+1]==tab_gry[y4+2][x4]-6&&tab_gry[y4+0][x4+1]==tab_gry[y4+3][x4])||
				   (tab_gry[y4+0][x4+1]==tab_gry[y4+1][x4]  &&tab_gry[y4+0][x4+1]==tab_gry[y4+2][x4]  &&tab_gry[y4+0][x4+1]==tab_gry[y4+3][x4]-6))
				  &&y4+3<=7&&x4+1<=7)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4+1][x4]>=13&&tab_gry[y4+1][x4]<=18){cout<<"2113  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4+1][x4]>=7 &&tab_gry[y4+1][x4]<=12){cout<<"2213  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4+1][x4]>=1 &&tab_gry[y4+1][x4]<=6 ){cout<<"2313  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+1;tab_ruchu[nr_indexu][0][1]=y4+0;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4+0;
				cout<<tab_gry[y4+0][x4+1]<<"  "<<tab_gry[y4+1][x4]<<"  "<<tab_gry[y4+2][x4]<<"  "<<tab_gry[y4+3][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////	
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4+0][x4-1]-6==tab_gry[y4+1][x4]&&tab_gry[y4+0][x4-1]-6==tab_gry[y4+2][x4]&&tab_gry[y4+0][x4-1]-6==tab_gry[y4+3][x4])||
				   (tab_gry[y4+0][x4-1]==tab_gry[y4+1][x4]-6&&tab_gry[y4+0][x4-1]==tab_gry[y4+2][x4]  &&tab_gry[y4+0][x4-1]==tab_gry[y4+3][x4])||
				   (tab_gry[y4+0][x4-1]==tab_gry[y4+1][x4]  &&tab_gry[y4+0][x4-1]==tab_gry[y4+2][x4]-6&&tab_gry[y4+0][x4-1]==tab_gry[y4+3][x4])||
				   (tab_gry[y4+0][x4-1]==tab_gry[y4+1][x4]  &&tab_gry[y4+0][x4-1]==tab_gry[y4+2][x4]  &&tab_gry[y4+0][x4-1]==tab_gry[y4+3][x4]-6))
				   &&y4+3<=7&&x4-1>=0)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4+1][x4]>=13&&tab_gry[y4+1][x4]<=18){cout<<"2114  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4+1][x4]>=7 &&tab_gry[y4+1][x4]<=12){cout<<"2214  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4+1][x4]>=1 &&tab_gry[y4+1][x4]<=6 ){cout<<"2314  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4-1;tab_ruchu[nr_indexu][0][1]=y4+0;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4+0;
				cout<<tab_gry[y4+0][x4-1]<<"  "<<tab_gry[y4+1][x4]<<"  "<<tab_gry[y4+2][x4]<<"  "<<tab_gry[y4+3][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////			
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4+1][x4+1]-6==tab_gry[y4+0][x4]&&tab_gry[y4+1][x4+1]-6==tab_gry[y4+2][x4]&&tab_gry[y4+1][x4+1]-6==tab_gry[y4+3][x4])||
				   (tab_gry[y4+1][x4+1]==tab_gry[y4+0][x4]-6&&tab_gry[y4+1][x4+1]==tab_gry[y4+2][x4]  &&tab_gry[y4+1][x4+1]==tab_gry[y4+3][x4])||
				   (tab_gry[y4+1][x4+1]==tab_gry[y4+0][x4]  &&tab_gry[y4+1][x4+1]==tab_gry[y4+2][x4]-6&&tab_gry[y4+1][x4+1]==tab_gry[y4+3][x4])||
				   (tab_gry[y4+1][x4+1]==tab_gry[y4+0][x4]  &&tab_gry[y4+1][x4+1]==tab_gry[y4+2][x4]  &&tab_gry[y4+1][x4+1]==tab_gry[y4+3][x4]-6))
				  &&y4+3<=7&&x4+1<=7)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"2115  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"2215  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"2315  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+1;tab_ruchu[nr_indexu][0][1]=y4+1;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4+1;
				cout<<tab_gry[y4+1][x4+1]<<"  "<<tab_gry[y4+0][x4]<<"  "<<tab_gry[y4+2][x4]<<"  "<<tab_gry[y4+3][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////	
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4+1][x4-1]-6==tab_gry[y4+0][x4]&&tab_gry[y4+1][x4-1]-6==tab_gry[y4+2][x4]&&tab_gry[y4+1][x4-1]-6==tab_gry[y4+3][x4])||
				   (tab_gry[y4+1][x4-1]==tab_gry[y4+0][x4]-6&&tab_gry[y4+1][x4-1]==tab_gry[y4+2][x4]  &&tab_gry[y4+1][x4-1]==tab_gry[y4+3][x4])||
				   (tab_gry[y4+1][x4-1]==tab_gry[y4+0][x4]  &&tab_gry[y4+1][x4-1]==tab_gry[y4+2][x4]-6&&tab_gry[y4+1][x4-1]==tab_gry[y4+3][x4])||
				   (tab_gry[y4+1][x4-1]==tab_gry[y4+0][x4]  &&tab_gry[y4+1][x4-1]==tab_gry[y4+2][x4]  &&tab_gry[y4+1][x4-1]==tab_gry[y4+3][x4]-6))
				   &&y4+3<=7&&x4-1>=0)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"2116  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"2216  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"2316  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4-1;tab_ruchu[nr_indexu][0][1]=y4+1;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4+1;
				cout<<tab_gry[y4+1][x4-1]<<"  "<<tab_gry[y4+0][x4]<<"  "<<tab_gry[y4+2][x4]<<"  "<<tab_gry[y4+3][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////			
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4+2][x4+1]-6==tab_gry[y4+0][x4]&&tab_gry[y4+2][x4+1]-6==tab_gry[y4+1][x4]&&tab_gry[y4+2][x4+1]-6==tab_gry[y4+3][x4])||
				   (tab_gry[y4+2][x4+1]==tab_gry[y4+0][x4]-6&&tab_gry[y4+2][x4+1]==tab_gry[y4+1][x4]  &&tab_gry[y4+2][x4+1]==tab_gry[y4+3][x4])||
				   (tab_gry[y4+2][x4+1]==tab_gry[y4+0][x4]  &&tab_gry[y4+2][x4+1]==tab_gry[y4+1][x4]-6&&tab_gry[y4+2][x4+1]==tab_gry[y4+3][x4])||
				   (tab_gry[y4+2][x4+1]==tab_gry[y4+0][x4]  &&tab_gry[y4+2][x4+1]==tab_gry[y4+1][x4]  &&tab_gry[y4+2][x4+1]==tab_gry[y4+3][x4]-6))
				  &&y4+3<=7&&x4+1<=7)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"2117  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"2217  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"2317  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+1;tab_ruchu[nr_indexu][0][1]=y4+2;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4+2;
				cout<<tab_gry[y4+2][x4+1]<<"  "<<tab_gry[y4+0][x4]<<"  "<<tab_gry[y4+1][x4]<<"  "<<tab_gry[y4+3][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////	
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4+2][x4-1]-6==tab_gry[y4+0][x4]&&tab_gry[y4+2][x4-1]-6==tab_gry[y4+1][x4]&&tab_gry[y4+2][x4-1]-6==tab_gry[y4+3][x4])||
				   (tab_gry[y4+2][x4-1]==tab_gry[y4+0][x4]-6&&tab_gry[y4+2][x4-1]==tab_gry[y4+1][x4]  &&tab_gry[y4+2][x4-1]==tab_gry[y4+3][x4])||
				   (tab_gry[y4+2][x4-1]==tab_gry[y4+0][x4]  &&tab_gry[y4+2][x4-1]==tab_gry[y4+1][x4]-6&&tab_gry[y4+2][x4-1]==tab_gry[y4+3][x4])||
				   (tab_gry[y4+2][x4-1]==tab_gry[y4+0][x4]  &&tab_gry[y4+2][x4-1]==tab_gry[y4+1][x4]  &&tab_gry[y4+2][x4-1]==tab_gry[y4+3][x4]-6))
				   &&y4+3<=7&&x4-1>=0)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"2118  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"2218  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"2381  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4-1;tab_ruchu[nr_indexu][0][1]=y4+2;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4+2;
				cout<<tab_gry[y4+2][x4-1]<<"  "<<tab_gry[y4+0][x4]<<"  "<<tab_gry[y4+1][x4]<<"  "<<tab_gry[y4+3][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////			
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4+3][x4+1]-6==tab_gry[y4+0][x4]&&tab_gry[y4+3][x4+1]-6==tab_gry[y4+1][x4]&&tab_gry[y4+3][x4+1]-6==tab_gry[y4+2][x4])||
				   (tab_gry[y4+3][x4+1]==tab_gry[y4+0][x4]-6&&tab_gry[y4+3][x4+1]==tab_gry[y4+1][x4]  &&tab_gry[y4+3][x4+1]==tab_gry[y4+2][x4])||
				   (tab_gry[y4+3][x4+1]==tab_gry[y4+0][x4]  &&tab_gry[y4+3][x4+1]==tab_gry[y4+1][x4]-6&&tab_gry[y4+3][x4+1]==tab_gry[y4+2][x4])||
				   (tab_gry[y4+3][x4+1]==tab_gry[y4+0][x4]  &&tab_gry[y4+3][x4+1]==tab_gry[y4+1][x4]  &&tab_gry[y4+3][x4+1]==tab_gry[y4+2][x4]-6))
				  &&y4+3<=7&&x4+1<=7)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"2119  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"2219  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"2319  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+1;tab_ruchu[nr_indexu][0][1]=y4+3;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4+3;
				cout<<tab_gry[y4+3][x4+1]<<"  "<<tab_gry[y4+0][x4]<<"  "<<tab_gry[y4+1][x4]<<"  "<<tab_gry[y4+2][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////	
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4+3][x4-1]-6==tab_gry[y4+0][x4]&&tab_gry[y4+3][x4-1]-6==tab_gry[y4+1][x4]&&tab_gry[y4+3][x4-1]-6==tab_gry[y4+2][x4])||
				   (tab_gry[y4+3][x4-1]==tab_gry[y4+0][x4]-6&&tab_gry[y4+3][x4-1]==tab_gry[y4+1][x4]  &&tab_gry[y4+3][x4-1]==tab_gry[y4+2][x4])||
				   (tab_gry[y4+3][x4-1]==tab_gry[y4+0][x4]  &&tab_gry[y4+3][x4-1]==tab_gry[y4+1][x4]-6&&tab_gry[y4+3][x4-1]==tab_gry[y4+2][x4])||
				   (tab_gry[y4+3][x4-1]==tab_gry[y4+0][x4]  &&tab_gry[y4+3][x4-1]==tab_gry[y4+1][x4]  &&tab_gry[y4+3][x4-1]==tab_gry[y4+2][x4]-6))
				   &&y4+3<=7&&x4-1>=0)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"2120  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"2220  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"2320  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4-1;tab_ruchu[nr_indexu][0][1]=y4+3;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4+3;
				cout<<tab_gry[y4+3][x4-1]<<"  "<<tab_gry[y4+0][x4]<<"  "<<tab_gry[y4+1][x4]<<"  "<<tab_gry[y4+2][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////			
			
			
			   
		}
	}		
////////////////////////////////////////////
////////////////////////////////////////////
	for(int y4=7;y4>=0;y4--)//od dolu do gory
	{
		for(int x4=0;x4<8;x4++) //od lewa do prawa
		{
			int flaga111=0;
			for (int ii2=0;ii2<3;ii2++){if(tab_gry[y4][x4-1]==tab_gry[y4][x4+ii2]&&ii2!=0&&x4+2<=7&&x4-1>=0){flaga111++;}}
			if(flaga111==2)
			{
				if(tab_gry[y4][x4-1]>=13&&tab_gry[y4][x4-1]<=18){cout<<"3101  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4-1]>=7 &&tab_gry[y4][x4-1]<=12){cout<<"3201  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4-1]>=1 &&tab_gry[y4][x4-1]<=6 ){cout<<"3301  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4-1;tab_ruchu[nr_indexu][0][1]=y4;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4][x4-1]<<"  "<<tab_gry[y4][x4+1]<<"  "<<tab_gry[y4][x4+2]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////
			for (int ii2=0;ii2<3;ii2++){if(tab_gry[y4][x4+3]==tab_gry[y4][x4+ii2]&&ii2!=2&&x4+3<=7){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"3102  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"3202  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"3302  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+3;tab_ruchu[nr_indexu][0][1]=y4;
				tab_ruchu[nr_indexu][0][2]=x4+2;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4][x4+0]<<"  "<<tab_gry[y4][x4+1]<<"  "<<tab_gry[y4][x4+3]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////
			for (int ii2=0;ii2<3;ii2++){if(tab_gry[y4+1][x4]==tab_gry[y4][x4+ii2]&&ii2!=0&&x4+2<=7&&y4+1<=7){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4+1]>=13&&tab_gry[y4][x4+1]<=18){cout<<"3103  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4+1]>=7 &&tab_gry[y4][x4+1]<=12){cout<<"3203  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4+1]>=1 &&tab_gry[y4][x4+1]<=6 ){cout<<"3303  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4;tab_ruchu[nr_indexu][0][1]=y4+1;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4+1][x4+0]<<"  "<<tab_gry[y4][x4+1]<<"  "<<tab_gry[y4][x4+2]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////
			for (int ii2=1;ii2<3;ii2++){if(tab_gry[y4-1][x4]==tab_gry[y4][x4+ii2]&&ii2!=0&&x4+2<=7&&y4-1>=0){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4+1]>=13&&tab_gry[y4][x4+1]<=18){cout<<"3104  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4+1]>=7 &&tab_gry[y4][x4+1]<=12){cout<<"3204  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4+1]>=1 &&tab_gry[y4][x4+1]<=6 ){cout<<"3304  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4;tab_ruchu[nr_indexu][0][1]=y4-1;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4-1][x4+0]<<"  "<<tab_gry[y4][x4+1]<<"  "<<tab_gry[y4][x4+2]<<endl;
				nr_indexu++;
			}
			flaga111=0;			
			//////////
			for (int ii2=0;ii2<3;ii2++){if(tab_gry[y4+1][x4+1]==tab_gry[y4][x4+ii2]&&ii2!=1&&x4+2<=7&&y4+1<=7){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"3105  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"3205  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"3305  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+1;tab_ruchu[nr_indexu][0][1]=y4+1;
				tab_ruchu[nr_indexu][0][2]=x4+1;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4+1][x4+1]<<"  "<<tab_gry[y4][x4]<<"  "<<tab_gry[y4][x4+2]<<endl;
				nr_indexu++;
			}
			flaga111=0;			
			//////////
			for (int ii2=0;ii2<3;ii2++){if(tab_gry[y4-1][x4+1]==tab_gry[y4][x4+ii2]&&ii2!=1&&x4+2<=7&&y4-1>=0){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"3106  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"3206  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"3306  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+1;tab_ruchu[nr_indexu][0][1]=y4-1;
				tab_ruchu[nr_indexu][0][2]=x4+1;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4-1][x4+1]<<"  "<<tab_gry[y4][x4]<<"  "<<tab_gry[y4][x4+2]<<endl;
				nr_indexu++;
			}
			flaga111=0;			
			//////////
			for (int ii2=0;ii2<3;ii2++){if(tab_gry[y4+1][x4+2]==tab_gry[y4][x4+ii2]&&ii2!=2&&x4+2<=7&&y4+1<=7){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"3107  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"3207  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"3307  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+2;tab_ruchu[nr_indexu][0][1]=y4+1;
				tab_ruchu[nr_indexu][0][2]=x4+2;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4+1][x4+2]<<"  "<<tab_gry[y4][x4+0]<<"  "<<tab_gry[y4][x4+1]<<endl;
				nr_indexu++;
			}
			flaga111=0;			
			//////////
			for (int ii2=0;ii2<3;ii2++){if(tab_gry[y4-1][x4+2]==tab_gry[y4][x4+ii2]&&ii2!=2&&x4+2<=7&&y4-1>=0){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"3108  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"3208  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"3308  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+2;tab_ruchu[nr_indexu][0][1]=y4-1;
				tab_ruchu[nr_indexu][0][2]=x4+2;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4-1][x4+2]<<"  "<<tab_gry[y4][x4+0]<<"  "<<tab_gry[y4][x4+1]<<endl;
				nr_indexu++;
			}
			flaga111=0;		
			//////////////////////////////
			for (int ii2=0;ii2<3;ii2++){if(tab_gry[y4-1][x4]==tab_gry[y4+ii2][x4]&&ii2!=0&&y4-1>=0&&y4+2<=7){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4+1][x4]>=13&&tab_gry[y4+1][x4]<=18){cout<<"3109  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4+1][x4]>=7 &&tab_gry[y4+1][x4]<=12){cout<<"3209  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4+1][x4]>=1 &&tab_gry[y4+1][x4]<=6 ){cout<<"3309  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4;tab_ruchu[nr_indexu][0][1]=y4-1;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4-1][x4]<<"  "<<tab_gry[y4+1][x4]<<"  "<<tab_gry[y4+2][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////
			for (int ii2=0;ii2<3;ii2++){if(tab_gry[y4+3][x4]==tab_gry[y4+ii2][x4]&&ii2!=2&&y4+3<=7){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"3110  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"3210  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"3310  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4;tab_ruchu[nr_indexu][0][1]=y4+3;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4+2;
				cout<<tab_gry[y4+3][x4]<<"  "<<tab_gry[y4+0][x4]<<"  "<<tab_gry[y4+1][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;			
			//////////
			for (int ii2=0;ii2<3;ii2++){if(tab_gry[y4+0][x4+1]==tab_gry[y4+ii2][x4]&&ii2!=0&&y4+2<=7&&x4+1<=7){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4+1][x4]>=13&&tab_gry[y4+1][x4]<=18){cout<<"3111  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4+1][x4]>=7 &&tab_gry[y4+1][x4]<=12){cout<<"3211  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4+1][x4]>=1 &&tab_gry[y4+1][x4]<=6 ){cout<<"3311  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+1;tab_ruchu[nr_indexu][0][1]=y4;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4+0][x4+1]<<"  "<<tab_gry[y4+1][x4]<<"  "<<tab_gry[y4+2][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;			
			//////////
			for (int ii2=0;ii2<3;ii2++){if(tab_gry[y4+0][x4-1]==tab_gry[y4+ii2][x4]&&ii2!=0&&y4+2<=7&&x4-1>=0){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4+1][x4]>=13&&tab_gry[y4+1][x4]<=18){cout<<"3112  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4+1][x4]>=7 &&tab_gry[y4+1][x4]<=12){cout<<"3212  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4+1][x4]>=1 &&tab_gry[y4+1][x4]<=6 ){cout<<"3312  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4-1;tab_ruchu[nr_indexu][0][1]=y4;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4+0][x4-1]<<"  "<<tab_gry[y4+1][x4]<<"  "<<tab_gry[y4+2][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;			
			//////////
		    for (int ii2=0;ii2<3;ii2++){if(tab_gry[y4+1][x4+1]==tab_gry[y4+ii2][x4]&&ii2!=1&&y4+2<=7&&x4+1<=7){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"3113  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"3213  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"3313  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+1;tab_ruchu[nr_indexu][0][1]=y4+1;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4+1;
				cout<<tab_gry[y4+1][x4+1]<<"  "<<tab_gry[y4+0][x4]<<"  "<<tab_gry[y4+2][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;			
			//////////
		    for (int ii2=0;ii2<3;ii2++){if(tab_gry[y4+1][x4-1]==tab_gry[y4+ii2][x4]&&ii2!=1&&y4+2<=7&&x4-1>=0){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"3114  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"3214  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"3314  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4-1;tab_ruchu[nr_indexu][0][1]=y4+1;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4+1;
				cout<<tab_gry[y4+1][x4-1]<<"  "<<tab_gry[y4+0][x4]<<"  "<<tab_gry[y4+2][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;			
			//////////
		     for (int ii2=0;ii2<3;ii2++){if(tab_gry[y4+2][x4+1]==tab_gry[y4+ii2][x4]&&ii2!=2&&y4+2<=7&&x4+1<=7){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"3115  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"3215  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"3315  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+1;tab_ruchu[nr_indexu][0][1]=y4+2;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4+2;
				cout<<tab_gry[y4+2][x4+1]<<"  "<<tab_gry[y4+0][x4]<<"  "<<tab_gry[y4+1][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;			
			//////////
		    for (int ii2=0;ii2<3;ii2++){if(tab_gry[y4+2][x4-1]==tab_gry[y4+ii2][x4]&&ii2!=2&&y4+2<=7&&x4-1>=0){flaga111++;}}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"3116  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"3216  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"3316  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4-1;tab_ruchu[nr_indexu][0][1]=y4+2;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4+2;
				cout<<tab_gry[y4+2][x4-1]<<"  "<<tab_gry[y4+0][x4]<<"  "<<tab_gry[y4+1][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;			
			//////////
		    ////////////////////////////////////////
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4][x4-1]-6==tab_gry[y4][x4+1]&&tab_gry[y4][x4-1]-6==tab_gry[y4][x4+2])||
				  (tab_gry[y4][x4-1]==tab_gry[y4][x4+1]-6&&tab_gry[y4][x4-1]==tab_gry[y4][x4+2]  )||
				  (tab_gry[y4][x4-1]==tab_gry[y4][x4+1]  &&tab_gry[y4][x4-1]==tab_gry[y4][x4+2]-6))
				  &&x4+3<=7&&x4-1>=0)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4-1]>=13&&tab_gry[y4][x4-1]<=18){cout<<"4101  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4-1]>=7 &&tab_gry[y4][x4-1]<=12){cout<<"4201  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4-1]>=1 &&tab_gry[y4][x4-1]<=6 ){cout<<"4301  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4-1;tab_ruchu[nr_indexu][0][1]=y4;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4][x4-1]<<"  "<<tab_gry[y4][x4+1]<<"  "<<tab_gry[y4][x4+2]<<"  "<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4][x4+3]-6==tab_gry[y4][x4+0]&&tab_gry[y4][x4+3]-6==tab_gry[y4][x4+1])||
				  (tab_gry[y4][x4+3]==tab_gry[y4][x4+0]-6&&tab_gry[y4][x4+3]==tab_gry[y4][x4+1]  )||
				  (tab_gry[y4][x4+3]==tab_gry[y4][x4+0]  &&tab_gry[y4][x4+3]==tab_gry[y4][x4+1]-6))
				  &&x4+4<=7)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"4102  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"4202  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"4302  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+3;tab_ruchu[nr_indexu][0][1]=y4;
				tab_ruchu[nr_indexu][0][2]=x4+2;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4][x4+3]<<"  "<<tab_gry[y4][x4+0]<<"  "<<tab_gry[y4][x4+1]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4+1][x4+0]-6==tab_gry[y4][x4+1]&&tab_gry[y4+1][x4+0]-6==tab_gry[y4][x4+2])||
				  (tab_gry[y4+1][x4+0]==tab_gry[y4][x4+1]-6&&tab_gry[y4+1][x4+0]==tab_gry[y4][x4+2]  )||
				  (tab_gry[y4+1][x4+0]==tab_gry[y4][x4+1]  &&tab_gry[y4+1][x4+0]==tab_gry[y4][x4+2]-6))
				  &&x4+3<=7&&y4+1<=7)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4+1]>=13&&tab_gry[y4][x4+1]<=18){cout<<"4103  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4+1]>=7 &&tab_gry[y4][x4+1]<=12){cout<<"4203  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4+1]>=1 &&tab_gry[y4][x4+1]<=6 ){cout<<"4303  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+0;tab_ruchu[nr_indexu][0][1]=y4+1;
				tab_ruchu[nr_indexu][0][2]=x4+0;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4+1][x4+0]<<"  "<<tab_gry[y4][x4+1]<<"  "<<tab_gry[y4][x4+2]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4-1][x4+0]-6==tab_gry[y4][x4+1]&&tab_gry[y4-1][x4+0]-6==tab_gry[y4][x4+2])||
				  (tab_gry[y4-1][x4+0]==tab_gry[y4][x4+1]-6&&tab_gry[y4-1][x4+0]==tab_gry[y4][x4+2]  )||
				  (tab_gry[y4-1][x4+0]==tab_gry[y4][x4+1]  &&tab_gry[y4-1][x4+0]==tab_gry[y4][x4+2]-6))
				  &&x4+3<=7&&y4-1>=0)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4+1]>=13&&tab_gry[y4][x4+1]<=18){cout<<"4104  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4+1]>=7 &&tab_gry[y4][x4+1]<=12){cout<<"4204  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4+1]>=1 &&tab_gry[y4][x4+1]<=6 ){cout<<"4304  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+0;tab_ruchu[nr_indexu][0][1]=y4-1;
				tab_ruchu[nr_indexu][0][2]=x4+0;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4-1][x4+0]<<"  "<<tab_gry[y4][x4+1]<<"  "<<tab_gry[y4][x4+2]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4+1][x4+1]-6==tab_gry[y4][x4+0]&&tab_gry[y4+1][x4+1]-6==tab_gry[y4][x4+2])||
				  (tab_gry[y4+1][x4+1]==tab_gry[y4][x4+0]-6&&tab_gry[y4+1][x4+1]==tab_gry[y4][x4+2]  )||
				  (tab_gry[y4+1][x4+1]==tab_gry[y4][x4+0]  &&tab_gry[y4+1][x4+1]==tab_gry[y4][x4+2]-6))
				  &&x4+3<=7&&y4+1<=7)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"4105  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"4205  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"4305  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+1;tab_ruchu[nr_indexu][0][1]=y4+1;
				tab_ruchu[nr_indexu][0][2]=x4+1;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4+1][x4+1]<<"  "<<tab_gry[y4][x4+0]<<"  "<<tab_gry[y4][x4+2]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4-1][x4+1]-6==tab_gry[y4][x4+0]&&tab_gry[y4-1][x4+1]-6==tab_gry[y4][x4+2])||
				  (tab_gry[y4-1][x4+1]==tab_gry[y4][x4+0]-6&&tab_gry[y4-1][x4+1]==tab_gry[y4][x4+2]  )||
				  (tab_gry[y4-1][x4+1]==tab_gry[y4][x4+0]  &&tab_gry[y4-1][x4+1]==tab_gry[y4][x4+2]-6))
				  &&x4+3<=7&&y4-1>=0)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"4106  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"4206  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"4306  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+1;tab_ruchu[nr_indexu][0][1]=y4-1;
				tab_ruchu[nr_indexu][0][2]=x4+1;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4-1][x4+1]<<"  "<<tab_gry[y4][x4+0]<<"  "<<tab_gry[y4][x4+2]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4+1][x4+2]-6==tab_gry[y4][x4+0]&&tab_gry[y4+1][x4+2]-6==tab_gry[y4][x4+1])||
				  (tab_gry[y4+1][x4+2]==tab_gry[y4][x4+0]-6&&tab_gry[y4+1][x4+2]==tab_gry[y4][x4+1]  )||
				  (tab_gry[y4+1][x4+2]==tab_gry[y4][x4+0]  &&tab_gry[y4+1][x4+2]==tab_gry[y4][x4+1]-6))
				  &&x4+3<=7&&y4+1<=7)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"4107  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"4207  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"4307  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+2;tab_ruchu[nr_indexu][0][1]=y4+1;
				tab_ruchu[nr_indexu][0][2]=x4+2;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4+1][x4+2]<<"  "<<tab_gry[y4][x4+0]<<"  "<<tab_gry[y4][x4+1]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4-1][x4+2]-6==tab_gry[y4][x4+0]&&tab_gry[y4-1][x4+2]-6==tab_gry[y4][x4+1])||
				  (tab_gry[y4-1][x4+2]==tab_gry[y4][x4+0]-6&&tab_gry[y4-1][x4+2]==tab_gry[y4][x4+1]  )||
				  (tab_gry[y4-1][x4+2]==tab_gry[y4][x4+0]  &&tab_gry[y4-1][x4+2]==tab_gry[y4][x4+1]-6))
				  &&x4+3<=7&&y4-1>=0)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"4108  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"4208  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"4308  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+2;tab_ruchu[nr_indexu][0][1]=y4-1;
				tab_ruchu[nr_indexu][0][2]=x4+2;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4-1][x4+2]<<"  "<<tab_gry[y4][x4+0]<<"  "<<tab_gry[y4][x4+1]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			////////////////////
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4-1][x4]-6==tab_gry[y4+1][x4]&&tab_gry[y4-1][x4]-6==tab_gry[y4+2][x4])||
				  (tab_gry[y4-1][x4]==tab_gry[y4+1][x4]-6&&tab_gry[y4-1][x4]==tab_gry[y4+2][x4]  )||
				  (tab_gry[y4-1][x4]==tab_gry[y4+1][x4]  &&tab_gry[y4-1][x4]==tab_gry[y4+2][x4]-6))
				  &&y4-1>=0&&y4+2<=7)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4+1][x4]>=13&&tab_gry[y4+1][x4]<=18){cout<<"4109  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4+1][x4]>=7 &&tab_gry[y4+1][x4]<=12){cout<<"4209  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4+1][x4]>=1 &&tab_gry[y4+1][x4]<=6 ){cout<<"4309  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4;tab_ruchu[nr_indexu][0][1]=y4-1;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4;
				cout<<tab_gry[y4-1][x4]<<"  "<<tab_gry[y4+1][x4]<<"  "<<tab_gry[y4+2][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////		
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4+3][x4]-6==tab_gry[y4+0][x4]&&tab_gry[y4+3][x4]-6==tab_gry[y4+1][x4])||
				  (tab_gry[y4+3][x4]==tab_gry[y4+0][x4]-6&&tab_gry[y4+3][x4]==tab_gry[y4+1][x4]  )||
				  (tab_gry[y4+3][x4]==tab_gry[y4+0][x4]  &&tab_gry[y4+3][x4]==tab_gry[y4+1][x4]-6))
				  &&y4+3<=7)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4+1][x4]>=13&&tab_gry[y4+1][x4]<=18){cout<<"4110  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4+1][x4]>=7 &&tab_gry[y4+1][x4]<=12){cout<<"4210  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4+1][x4]>=1 &&tab_gry[y4+1][x4]<=6 ){cout<<"4310  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4;tab_ruchu[nr_indexu][0][1]=y4+3;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4+2;
				cout<<tab_gry[y4+3][x4]<<"  "<<tab_gry[y4+0][x4]<<"  "<<tab_gry[y4+1][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////			
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4+0][x4+1]-6==tab_gry[y4+1][x4]&&tab_gry[y4+0][x4+1]-6==tab_gry[y4+2][x4])||
				   (tab_gry[y4+0][x4+1]==tab_gry[y4+1][x4]-6&&tab_gry[y4+0][x4+1]==tab_gry[y4+2][x4]  )||
				   (tab_gry[y4+0][x4+1]==tab_gry[y4+1][x4]  &&tab_gry[y4+0][x4+1]==tab_gry[y4+2][x4]-6))
				  &&y4+2<=7&&x4+1<=7)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4+1][x4]>=13&&tab_gry[y4+1][x4]<=18){cout<<"4111  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4+1][x4]>=7 &&tab_gry[y4+1][x4]<=12){cout<<"4211  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4+1][x4]>=1 &&tab_gry[y4+1][x4]<=6 ){cout<<"4311  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+1;tab_ruchu[nr_indexu][0][1]=y4+0;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4+0;
				cout<<tab_gry[y4+0][x4+1]<<"  "<<tab_gry[y4+1][x4]<<"  "<<tab_gry[y4+2][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////	
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4+0][x4-1]-6==tab_gry[y4+1][x4]&&tab_gry[y4+0][x4-1]-6==tab_gry[y4+2][x4])||
				   (tab_gry[y4+0][x4-1]==tab_gry[y4+1][x4]-6&&tab_gry[y4+0][x4-1]==tab_gry[y4+2][x4]  )||
				   (tab_gry[y4+0][x4-1]==tab_gry[y4+1][x4]  &&tab_gry[y4+0][x4-1]==tab_gry[y4+2][x4]-6))
				   &&y4+2<=7&&x4-1>=0)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4+1][x4]>=13&&tab_gry[y4+1][x4]<=18){cout<<"4112  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4+1][x4]>=7 &&tab_gry[y4+1][x4]<=12){cout<<"4212  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4+1][x4]>=1 &&tab_gry[y4+1][x4]<=6 ){cout<<"4312  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4-1;tab_ruchu[nr_indexu][0][1]=y4+0;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4+0;
				cout<<tab_gry[y4+0][x4-1]<<"  "<<tab_gry[y4+1][x4]<<"  "<<tab_gry[y4+2][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////			
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4+1][x4+1]-6==tab_gry[y4+0][x4]&&tab_gry[y4+1][x4+1]-6==tab_gry[y4+2][x4])||
				   (tab_gry[y4+1][x4+1]==tab_gry[y4+0][x4]-6&&tab_gry[y4+1][x4+1]==tab_gry[y4+2][x4]  )||
				   (tab_gry[y4+1][x4+1]==tab_gry[y4+0][x4]  &&tab_gry[y4+1][x4+1]==tab_gry[y4+2][x4]-6))
				  &&y4+2<=7&&x4+1<=7)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"4113  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"4213  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"4313  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+1;tab_ruchu[nr_indexu][0][1]=y4+1;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4+1;
				cout<<tab_gry[y4+1][x4+1]<<"  "<<tab_gry[y4+0][x4]<<"  "<<tab_gry[y4+2][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////	
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4+1][x4-1]-6==tab_gry[y4+0][x4]&&tab_gry[y4+1][x4-1]-6==tab_gry[y4+2][x4])||
				   (tab_gry[y4+1][x4-1]==tab_gry[y4+0][x4]-6&&tab_gry[y4+1][x4-1]==tab_gry[y4+2][x4]  )||
				   (tab_gry[y4+1][x4-1]==tab_gry[y4+0][x4]  &&tab_gry[y4+1][x4-1]==tab_gry[y4+2][x4]-6))
				   &&y4+2<=7&&x4-1>=0)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"4114  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"4214  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"4314  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4-1;tab_ruchu[nr_indexu][0][1]=y4+1;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4+1;
				cout<<tab_gry[y4+1][x4-1]<<"  "<<tab_gry[y4+0][x4]<<"  "<<tab_gry[y4+2][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////			
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4+2][x4+1]-6==tab_gry[y4+0][x4]&&tab_gry[y4+2][x4+1]-6==tab_gry[y4+1][x4])||
				   (tab_gry[y4+2][x4+1]==tab_gry[y4+0][x4]-6&&tab_gry[y4+2][x4+1]==tab_gry[y4+1][x4]  )||
				   (tab_gry[y4+2][x4+1]==tab_gry[y4+0][x4]  &&tab_gry[y4+2][x4+1]==tab_gry[y4+1][x4]-6))
				  &&y4+2<=7&&x4+1<=7)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"4115  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"4215  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"4315  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4+1;tab_ruchu[nr_indexu][0][1]=y4+2;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4+2;
				cout<<tab_gry[y4+2][x4+1]<<"  "<<tab_gry[y4+0][x4]<<"  "<<tab_gry[y4+1][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////	
			for (int ii2=0;ii2<4;ii2++)
			{
				if(((tab_gry[y4+2][x4-1]-6==tab_gry[y4+0][x4]&&tab_gry[y4+2][x4-1]-6==tab_gry[y4+1][x4]&&tab_gry[y4+2][x4-1]-6==tab_gry[y4+3][x4])||
				   (tab_gry[y4+2][x4-1]==tab_gry[y4+0][x4]-6&&tab_gry[y4+2][x4-1]==tab_gry[y4+1][x4]  &&tab_gry[y4+2][x4-1]==tab_gry[y4+3][x4])||
				   (tab_gry[y4+2][x4-1]==tab_gry[y4+0][x4]  &&tab_gry[y4+2][x4-1]==tab_gry[y4+1][x4]-6&&tab_gry[y4+2][x4-1]==tab_gry[y4+3][x4]))
				   &&y4+2<=7&&x4-1>=0)
				{flaga111++;}
			}
			if(flaga111==3)
			{
				if(tab_gry[y4][x4]>=13&&tab_gry[y4][x4]<=18){cout<<"4116  ";tab_ruchu[nr_indexu][0][4]=12;}
				if(tab_gry[y4][x4]>=7 &&tab_gry[y4][x4]<=12){cout<<"4216  ";tab_ruchu[nr_indexu][0][4]=8; }
				if(tab_gry[y4][x4]>=1 &&tab_gry[y4][x4]<=6 ){cout<<"4316  ";tab_ruchu[nr_indexu][0][4]=4; }

				tab_ruchu[nr_indexu][0][0]=x4-1;tab_ruchu[nr_indexu][0][1]=y4+2;
				tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4+2;
				cout<<tab_gry[y4+2][x4-1]<<"  "<<tab_gry[y4+0][x4]<<"  "<<tab_gry[y4+1][x4]<<endl;
				nr_indexu++;
			}
			flaga111=0;
			//////////						   
		}
	}		
////////////////////////////////////////////



////////////////////////////////////////////
/*
int nr_indexu4=nr_indexu;
nr_indexu=0;
for( int i3=0;i3<nr_indexu4+1;i3++)
{
	///////////
	for(int y3=0;y3<8;y3++)
	{
		for(int x4=0;x4<8;x4++)
		{
			tab_gry_tmp[y3][x4]=tab_gry[y3][x4];
		}
	}
	///////////
	//wybor ruchu:
	int tmp=0;
	tmp=tab_gry_tmp[tab_ruchu[nr_indexu][0][3]][tab_ruchu[nr_indexu][0][2]];
	tab_gry_tmp[tab_ruchu[nr_indexu][0][3]][tab_ruchu[nr_indexu][0][2]]=tab_gry_tmp[tab_ruchu[nr_indexu][0][1]][tab_ruchu[nr_indexu][0][0]];
	tab_gry_tmp[tab_ruchu[nr_indexu][0][1]][tab_ruchu[nr_indexu][0][0]]=tmp;
	///////////	
	licznik2=0;

	nst:;

	//////////
	for(int y3=0;y3<8;y3++)
	{
		for(int x4=0;x4<8;x4++)
		{
			//////////			
			if((tab_gry[y3][x4]-6)==tab_gry[y3+1][x4]&&(tab_gry[y3][x4]-6)==tab_gry[y3+2][x4]&&(tab_gry[y3][x4]-6)==tab_gry[y3+3][x4]&&(y3+3)<=7)
			{
				tab_gry[y3][x4]=0;
				tab_gry[y3+1][x4]=0;
				tab_gry[y3+2][x4]=0;
				tab_gry[y3+3][x4]=0;
				licznik2=licznik2+11;
				flaga5++;
			}
			if(tab_gry[y3][x4]==(tab_gry[y3+1][x4]-6)&&tab_gry[y3][x4]==tab_gry[y3+2][x4]&&tab_gry[y3][x4]==tab_gry[y3+3][x4]&&(y3+3)<=7)
			{
				tab_gry[y3][x4]=0;
				tab_gry[y3+1][x4]=0;
				tab_gry[y3+2][x4]=0;
				tab_gry[y3+3][x4]=0;
				licznik2=licznik2+10;
				flaga5++;
			}		
			if(tab_gry[y3][x4]==tab_gry[y3+1][x4]&&tab_gry[y3][x4]==(tab_gry[y3+2][x4]-6)&&tab_gry[y3][x4]==tab_gry[y3+3][x4]&&(y3+3)<=7)
			{
				tab_gry[y3][x4]=0;
				tab_gry[y3+1][x4]=0;
				tab_gry[y3+2][x4]=0;
				tab_gry[y3+3][x4]=0;
				licznik2=licznik2+10;
				flaga5++;
			}				
			if(tab_gry[y3][x4]==tab_gry[y3+1][x4]&&tab_gry[y3][x4]==tab_gry[y3+2][x4]&&tab_gry[y3][x4]==(tab_gry[y3+3][x4]-6)&&(y3+3)<=7)
			{
				tab_gry[y3][x4]=0;
				tab_gry[y3+1][x4]=0;
				tab_gry[y3+2][x4]=0;
				tab_gry[y3+3][x4]=0;
				licznik2=licznik2+11;
				flaga5++;
			}		
			if(tab_gry[y3][x4]==tab_gry[y3+1][x4]&&tab_gry[y3][x4]==tab_gry[y3+2][x4]&&tab_gry[y3][x4]==tab_gry[y3+3][x4]&&(y3+3)<=7)
			{
				tab_gry[y3][x4]=0;
				tab_gry[y3+1][x4]=0;
				tab_gry[y3+2][x4]=0;
				tab_gry[y3+3][x4]=0;
				licznik2=licznik2+4;
				flaga5++;
			}
			//////////
			if((tab_gry[y3][x4]-6)==tab_gry[y3][x4+1]&&(tab_gry[y3][x4]-6)==tab_gry[y3][x4+2]&&(tab_gry[y3][x4]-6)==tab_gry[y3][x4+3]&&(x4+3)<=7)
			{
				tab_gry[y3][x4]=0;
				tab_gry[y3][x4+1]=0;
				tab_gry[y3][x4+2]=0;
				tab_gry[y3][x4+3]=0;
				licznik2=licznik2+11;
			}
			if(tab_gry[y3][x4]==(tab_gry[y3][x4+1]-6)&&tab_gry[y3][x4]==tab_gry[y3][x4+2]&&tab_gry[y3][x4]==tab_gry[y3][x4+3]&&(x4+3)<=7)
			{
				tab_gry[y3][x4]=0;
				tab_gry[y3][x4+1]=0;
				tab_gry[y3][x4+2]=0;
				tab_gry[y3][x4+3]=0;
				licznik2=licznik2+10;
				flaga5++;
			}
			if(tab_gry[y3][x4]==tab_gry[y3][x4+1]&&tab_gry[y3][x4]==(tab_gry[y3][x4+2]-6)&&tab_gry[y3][x4]==tab_gry[y3][x4+3]&&(x4+3)<=7)
			{
				tab_gry[y3][x4]=0;
				tab_gry[y3][x4+1]=0;
				tab_gry[y3][x4+2]=0;
				tab_gry[y3][x4+3]=0;
				licznik2=licznik2+10;
			}
			if(tab_gry[y3][x4]==tab_gry[y3][x4+1]&&tab_gry[y3][x4]==tab_gry[y3][x4+2]&&tab_gry[y3][x4]==(tab_gry[y3][x4+3]-6)&&(x4+3)<=7)
			{
				tab_gry[y3][x4]=0;
				tab_gry[y3][x4+1]=0;
				tab_gry[y3][x4+2]=0;
				tab_gry[y3][x4+3]=0;
				licznik2=licznik2+11;
				flaga5++;
			}
			if(tab_gry[y3][x4]==tab_gry[y3][x4+1]&&tab_gry[y3][x4]==tab_gry[y3][x4+2]&&tab_gry[y3][x4]==tab_gry[y3][x4+3]&&(x4+3)<=7)
			{
				tab_gry[y3][x4]=0;
				tab_gry[y3][x4+1]=0;
				tab_gry[y3][x4+2]=0;
				tab_gry[y3][x4+3]=0;
				licznik2=licznik2+4;
			}
			//////////
			if((tab_gry[y3][x4]-6)==tab_gry[y3+1][x4]&&(tab_gry[y3][x4]-6)==tab_gry[y3+2][x4]&&(y3+2)<=7)
			{
				tab_gry[y3][x4]=0;
				tab_gry[y3+1][x4]=0;
				tab_gry[y3+2][x4]=0;
				licznik2=licznik2+10;
				flaga5++;
			}
			if(tab_gry[y3][x4]==(tab_gry[y3+1][x4]-6)&&tab_gry[y3][x4]==tab_gry[y3+2][x4]&&(y3+2)<=7)
			{
				tab_gry[y3][x4]=0;
				tab_gry[y3+1][x4]=0;
				tab_gry[y3+2][x4]=0;
				licznik2=licznik2+9;
				flaga5++;
			}
			if(tab_gry[y3][x4]==tab_gry[y3+1][x4]&&tab_gry[y3][x4]==(tab_gry[y3+2][x4]-6)&&(y3+2)<=7)
			{
				tab_gry[y3][x4]=0;
				tab_gry[y3+1][x4]=0;
				tab_gry[y3+2][x4]=0;
				licznik2=licznik2+10;
				flaga5++;
			}
			if(tab_gry[y3][x4]==tab_gry[y3+1][x4]&&tab_gry[y3][x4]==tab_gry[y3+2][x4]&&(y3+2)<=7)
			{
				tab_gry[y3][x4]=0;
				tab_gry[y3+1][x4]=0;
				tab_gry[y3+2][x4]=0;
				licznik2=licznik2+3;
				flaga5++;
			}
			//////////
			if((tab_gry[y3][x4]-6)==tab_gry[y3][x4+1]&&(tab_gry[y3][x4]-6)==tab_gry[y3][x4+2]&&(x4+2)<=7)
			{
				tab_gry[y3][x4]=0;
				tab_gry[y3][x4+1]=0;
				tab_gry[y3][x4+2]=0;
				licznik2=licznik2+10;
				flaga5++;
			}
			if(tab_gry[y3][x4]==(tab_gry[y3][x4+1]-6)&&tab_gry[y3][x4]==tab_gry[y3][x4+2]&&(x4+2)<=7)
			{
				tab_gry[y3][x4]=0;
				tab_gry[y3][x4+1]=0;
				tab_gry[y3][x4+2]=0;
				licznik2=licznik2+9;
				flaga5++;
			}
			if(tab_gry[y3][x4]==tab_gry[y3][x4+1]&&tab_gry[y3][x4]==(tab_gry[y3][x4+2]-6)&&(x4+2)<=7)
			{
				tab_gry[y3][x4]=0;
				tab_gry[y3][x4+1]=0;
				tab_gry[y3][x4+2]=0;
				licznik2=licznik2+10;
				flaga5++;
			}
			if(tab_gry[y3][x4]==tab_gry[y3][x4+1]&&tab_gry[y3][x4]==tab_gry[y3][x4+2]&&(x4+2)<=7)
			{
				tab_gry[y3][x4]=0;
				tab_gry[y3][x4+1]=0;
				tab_gry[y3][x4+2]=0;
				licznik2=licznik2+3;
				flaga5++;
			}
			//////////
		}
	}//for(int y3=0;y3<8;y3++)
	//////////
	for(int y3=0;y3<8;y3++)
	{
		for(int x4=0;x4<8;x4++)
		{
			if(tab_gry[y3][x4]==0&&(y3-1)>=0)
			{
				tab_gry[y3][x4]=tab_gry[y3-1][x4];
				tab_gry[y3-1][x4]=0;
			}
		}
	}
	//////////	
	if(	flaga5>=1){flaga5=0;goto nst;}	
	flaga5=0;
	///////////
	for(int y3=0;y3<8;y3++)
	{
		for(int x4=0;x4<8;x4++)
		{
			tab_gry[y3][x4]=tab_gry_tmp[y3][x4];
		}
	}
	///////////
	//zapisac punkty ruchu (licznik2) do tablicy

	nr_indexu++;
}//for( int i3=0;i3<nr_indexu+1;i3++)
////////////////////////////////////////////
*/
	//for(int y4=7;y4>=0;y4--)//od dolu do gory
	//for(int x4=0;x4<8;x4++) //od lewa do prawa
	//tab_ruchu[nr_indexu][0][0]=x4-1;tab_ruchu[nr_indexu][0][1]=y4+2;
	//tab_ruchu[nr_indexu][0][2]=x4;tab_ruchu[nr_indexu][0][3]=y4+2;
							
	nr_indexu=0;

	if(tab_ruchu[nr_indexu][0][1]==0)
	{
		SetCursorPos((788+tab_ruchu[nr_indexu][0][0]*55+rand()%30+10),(297+0+rand()%30+10));
		goto ruch;
	}
	if(tab_ruchu[nr_indexu][0][1]==1)
	{
		SetCursorPos((788+tab_ruchu[nr_indexu][0][0]*55+rand()%30+10),(297+54+rand()%30+10));
		goto ruch;
	}
	if(tab_ruchu[nr_indexu][0][1]==2)
	{
		SetCursorPos((788+tab_ruchu[nr_indexu][0][0]*55+rand()%30+10),(297+54+55+rand()%30+10));
		goto ruch;
	}
	if(tab_ruchu[nr_indexu][0][1]==3)
	{
		SetCursorPos((788+tab_ruchu[nr_indexu][0][0]*55+rand()%30+10),(297+2*54+55+rand()%30+10));
		goto ruch;
	}
	if(tab_ruchu[nr_indexu][0][1]==4)
	{
		SetCursorPos((788+tab_ruchu[nr_indexu][0][0]*55+rand()%30+10),(297+2*54+2*55+rand()%30+10));
		goto ruch;
	}
	if(tab_ruchu[nr_indexu][0][1]==5)
	{
		SetCursorPos((788+tab_ruchu[nr_indexu][0][0]*55+rand()%30+10),(297+3*54+2*55+rand()%30+10));
		goto ruch;
	}
	if(tab_ruchu[nr_indexu][0][1]==6)
	{
		SetCursorPos((788+tab_ruchu[nr_indexu][0][0]*55+rand()%30+10),(297+3*54+3*55+rand()%30+10));
		goto ruch;
	}
	if(tab_ruchu[nr_indexu][0][1]==7)
	{
		SetCursorPos((788+tab_ruchu[nr_indexu][0][0]*55+rand()%30+10),(297+4*54+3*55+rand()%30+10));
		goto ruch;
	}
	
ruch:;
	Sleep((rand()%40+80));
	mouse_event(MOUSEEVENTF_LEFTDOWN,0 ,0,0,0);
	Sleep((rand()%50+100));
		
	if(tab_ruchu[nr_indexu][0][3]==0)
	{
		SetCursorPos((788+tab_ruchu[nr_indexu][0][2]*55+rand()%30+10),(297+0+rand()%30+10));
	}
	if(tab_ruchu[nr_indexu][0][3]==1)
	{
		SetCursorPos((788+tab_ruchu[nr_indexu][0][2]*55+rand()%30+10),(297+54+rand()%30+10));
	}
	if(tab_ruchu[nr_indexu][0][3]==2)
	{
		SetCursorPos((788+tab_ruchu[nr_indexu][0][2]*55+rand()%30+10),(297+54+55+rand()%30+10));
	}
	if(tab_ruchu[nr_indexu][0][3]==3)
	{
		SetCursorPos((788+tab_ruchu[nr_indexu][0][2]*55+rand()%30+10),(297+2*54+55+rand()%30+10));
	}
	if(tab_ruchu[nr_indexu][0][3]==4)
	{
		SetCursorPos((788+tab_ruchu[nr_indexu][0][2]*55+rand()%30+10),(297+2*54+2*55+rand()%30+10));
	}
	if(tab_ruchu[nr_indexu][0][3]==5)
	{
		SetCursorPos((788+tab_ruchu[nr_indexu][0][2]*55+rand()%30+10),(297+3*54+2*55+rand()%30+10));
	}
	if(tab_ruchu[nr_indexu][0][3]==6)
	{
		SetCursorPos((788+tab_ruchu[nr_indexu][0][2]*55+rand()%30+10),(297+3*54+3*55+rand()%30+10));
	}
	if(tab_ruchu[nr_indexu][0][3]==7)
	{
		SetCursorPos((788+tab_ruchu[nr_indexu][0][2]*55+rand()%30+10),(297+4*54+3*55+rand()%30+10));
	}
	Sleep((rand()%30+70));
	mouse_event(MOUSEEVENTF_LEFTUP,0 ,0,0,0);
	Sleep((rand()%40+100));
	
	cout<<"z:  "<<tab_ruchu[nr_indexu][0][0]<<"  "<<tab_ruchu[nr_indexu][0][1]<<endl;
	cout<<"do:  "<<tab_ruchu[nr_indexu][0][2]<<"  "<<tab_ruchu[nr_indexu][0][3]<<endl;



	SetCursorPos((788+450+rand()%360+10),(rand()%297+10));
//next3:;			

	
			

	nr_indexu=0;
	runda2++;
	cout<<"	nr rundy:  "<<runda2<<endl;
	//if(a1>0&&a2>0&&a3>0)
	//{
	b1=tab_gry[0][0];b2=tab_gry[0][1];b3=tab_gry[0][2];b4=tab_gry[0][3];
	//}
	/*for(int y3=0;y3<8;y3++)
	{
		for(int x4=0;x4<8;x4++)
		{
			tab_gry_tmp[y3][x4]=tab_gry[y3][x4];					
		}
	}
	*/

//next4:;


	Sleep(zmienna);
	Sleep(100+rand()%200);
	Sleep(100);

	if(kbhit()==1){goto od_nowa;}




}//nastepny ruch for(int runda=0;runda<40;runda++)

		system("pause");
/////////////////////////////////////

	for(int i=0;i<15;i++)
	{	
		for(int j=0;j<15;j++)
		{
		std::cout <<" "<<data11[2].pixel[i][j].red11<<"  "<<data11[2].pixel[i][j].green11<<"  "<<data11[2].pixel[i][j].blue11<< "\n";
		std::cout <<" "<<actual_bitmap11[0].pixel[i][j].red11<<"  "<<actual_bitmap11[0].pixel[i][j].green11<<"  "<<actual_bitmap11[0].pixel[i][j].blue11<< "\n";
		}
	}
		system("pause");
	
Klasa a(2,3,7.9);
system("pause");
	return 0;
}

