/****************************************************************
*																*
*9in1sum.cc 													*
*Public Domain													*
*Standard of ISO/IEC 10118-3:2018								*
*created on 2023-09-10										 	*
*CHUHEI														    *
*That 9 methods are proven still fine by cryptanalysts          *
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
	//char* instr = argv[1];
	
	if(argc==2){
		
	cout << "Default method is set as SHA2-256" << endl;	
	
	ifstream file(argv[1], ios_base::in|ios_base::binary);
	
	if (!file)
	{ /*File is empty*/
	cout << "File not found, please double check the correct location trying again." << endl;
	}
	else
	{
	cout <<"SHA256(" <<argv[1] << ")= "<<sha256().absorb(file).hexdigest() << endl;
	}
	
	
	
	}
	else if (argc==3){
	
	
	
	ifstream file(argv[2], ios_base::in|ios_base::binary);
	
	if (!file)
	{ /*File is empty*/
	cout << "File not found, please double check the correct location trying again." << endl;
	}
	else{
	
	if(!strcmp(argv[1],"sm3"))
	cout <<"SM3(" <<argv[1] << ")= "<<sm3().absorb(file).hexdigest() << endl;
	else if(!strcmp(argv[1],"sha384"))
	cout <<"SHA384(" <<argv[1] << ")= "<<sha384().absorb(file).hexdigest() << endl;
	else if(!strcmp(argv[1],"sha512"))
	cout <<"SHA512(" <<argv[1] << ")= "<<sha512().absorb(file).hexdigest() << endl;
	else if(!strcmp(argv[1],"sha512/256"))
	cout <<"SHA512/256(" <<argv[1] << ")= "<<sha512(256).absorb(file).hexdigest() << endl;
	else if(!strcmp(argv[1],"sha3-256"))
	cout <<"SHA3-256(" <<argv[1] << ")= "<<sha3(256).absorb(file).hexdigest() << endl;
	else if(!strcmp(argv[1],"sha3-384"))
	cout <<"SHA3-384(" <<argv[1] << ")= "<<sha3(384).absorb(file).hexdigest() << endl;
	else if(!strcmp(argv[1],"sha3-512"))
	cout <<"SHA3-512(" <<argv[1] << ")= ""<<sha3(512).absorb(file).hexdigest() << endl;
	else if(!strcmp(argv[1],"whirlpool"))
	cout <<"WHIRLPOOL(" <<argv[1] << ")= "<<whirlpool().absorb(file).hexdigest() << endl;
	else
	cout <<"SHA256(" <<argv[1] << ")= "<<sha256().absorb(file).hexdigest() << endl;	
	
	}
	
	
	
	}
	
	
	
	
	if(argc !=3 )
	{
	
	cout << "File Integrity checker powered by digestpp" << endl;
	cout << "For just sha256 (SHA2-256): 9in1sum (filename) " << endl;
	cout << "For other methods: 9in1sum (sm3,sha256,sha384,sha512,sha512/256,sha3-256,sha3-384,sha3-512 or whirlpool) (filename) " << endl;
	
	
	}
	
}


