/****************************************************************
*																*
*sha256sum.cc  													*
*Public Domain													*
*Formarly ISO/IEC 10118-3:2004									*
*Being Revised by ISO/IEC 10118-3:2018					 		*
*Standard of NIST FIPS-180-4					 				*
*CHUHEI														    *
*created on 2023-09-10											*
****************************************************************/


#include "../digestpp.hpp"
#include <numeric>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
using namespace digestpp;


int main(int argc, char *argv[])
{
	
	/*
	This requires digestpp;
	if just typing the exe just output how to use that
	The filename just like *nix style
	If input es deux then check if file exist
	Not exist? Then Send back to the start
	Else
	Read file in binary mode, checking the hash and that's it.
	*/
	
	/*How fast? Golang requires Interpreter to do a thing while c++ may point something deeper */
	
	if (argc != 2){
	cout << "File Integrity checker powered by digestpp" << endl;
	cout << "Usage: sha256sum (filename) " << endl;
	
	}
	else{
	ifstream file(argv[1], ios_base::in|ios_base::binary);
	
	
	if (!file)
	{ /*File is empty*/
	cout << "File not found, please double check the correct location trying again." << endl;
	}
	else{
	cout << "SHA256(" <<argv[1] << ")= "<<sha256().absorb(file).hexdigest() << endl;
	}
	}
}