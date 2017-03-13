#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>
using namespace std; 

int main(void)
{
	char file1[50];
	char file2[50];
	unsigned int size1;
	unsigned int size2;
	char **txt1;
	char **txt2;
	unsigned int count = 0;

	ifstream fin1("C:\\cpp\\baumanclasses\\labstech\\sem2\\texts\\file1.txt");
	ifstream fin2("C:\\cpp\\baumanclasses\\labstech\\sem2\\texts\\file2.txt");
	
	if(!fin1.is_open() || !fin2.is_open()) cout << "Error: File was not found!" << endl;
		else 
		{
			cout << "The number of lines in file1 is ";
			cin >> size1;
			cout << "The number of lines in file2 is ";
			cin >> size2;
			txt1 = new char*[size1];
			txt2 = new char*[size2];

				for ( unsigned int i = 0; i < size1; ++i )
				{
					fin1.getline(file1, 49, '\n');
					txt1[i] = new char [strlen(file1)];
					for ( unsigned int j = 0; j < strlen(file1); ++j ) 
					{
						txt1[i][j] = file1[j];
					}
				}

				for ( unsigned int i = 0; i < size2; ++i )
				{
					fin2.getline(file2, 49, '\n');
					txt2[i] = new char [strlen(file2)];
					for ( unsigned int j = 0; j < strlen(file2); ++j ) 
					{
						txt2[i][j] = file2[j];
					}
				}

				for ( unsigned int i = 0; i < size1; ++i )
				{
					for ( unsigned int j = 0; j < size2; ++j )
					{
						for( unsigned int k = 0; k < strlen(file1); ++k )
						{
							if ( txt1[i][k] == txt2[j][k] )
							{
								txt2[j][k] = 0;
								txt1[i][k] = 0;
							} 
								
						}
					}

				}

				for ( unsigned int j = 0; j < size2; ++j )
					{
							if ( strlen(txt2[j]) != 0 ) cout << "File2 " << "Line: " << j+1 << " " << txt2[j];
						if ( strlen(txt2[j]) != 0 ) cout << endl;
					}

				for ( unsigned int j = 0; j < size1; ++j )
					{
							if ( strlen(txt1[j]) != 0 ) cout << "File1 " << "Line: " << j+1 << " " << txt1[j];
						if ( strlen(txt1[j]) != 0 ) cout << endl;
					}	
						
			for (unsigned int i = 0; i < size1; ++i) delete txt1[i]; 
			delete []txt1;
			for (unsigned int i = 0; i < size2; ++i) delete txt2[i]; 
			delete []txt2;
			
			
		} 

			fin1.close();
			fin2.close();
		
		cout << endl << endl << "Press any button to exit the program" << endl;
	_getch();
	return 0;
}