/****************************************************************
*																*
*iecsum.cc 														*
*Public Domain													*
*Standard of ISO/IEC 10118-3:2018								*
*created on 2023-09-10										 	*
*CHUHEI														    *
*That contains functions except RIPEMD , which is 15 out of 17  *
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
	cout <<"SHA2-256: " <<sha256().absorb(file).hexdigest() << endl;
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
	cout <<"         SM3: "<<sm3().absorb(file).hexdigest()<<"\t" << argv[1] << endl;
	else if(!strcmp(argv[1],"sha384"))
	cout <<"    SHA2-384: "<<sha384().absorb(file).hexdigest()<<"\t" << argv[1] << endl;
	else if(!strcmp(argv[1],"sha512"))
	cout <<"    SHA2-512: "<<sha512().absorb(file).hexdigest()<<"\t" << argv[1] << endl;
	else if(!strcmp(argv[1],"sha512/256"))
	cout <<"SHA2-512/256: "<<sha512(256).absorb(file).hexdigest()<<"\t" << argv[1] << endl;
	else if(!strcmp(argv[1],"sha3-256"))
	cout <<"    SHA3-256: "<<sha3(256).absorb(file).hexdigest()<<"\t" << argv[1] << endl;
	else if(!strcmp(argv[1],"sha3-384"))
	cout <<"    SHA3-384: "<<sha3(384).absorb(file).hexdigest()<<"\t" << argv[1] << endl;
	else if(!strcmp(argv[1],"sha3-512"))
	cout <<"    SHA3-512: "<<sha3(512).absorb(file).hexdigest() <<"\t" << argv[1]<< endl;
	else if(!strcmp(argv[1],"whirlpool"))
	cout <<"   WHIRLPOOL: "<<whirlpool().absorb(file).hexdigest()<<"\t" << argv[1] << endl;
	else if(!strcmp(argv[1],"sha"))
	cout <<"        SHA1: "<<sha1().absorb(file).hexdigest() <<"\t" << argv[1]<< endl;
	else if(!strcmp(argv[1],"sha224"))
	cout <<"    SHA2-224: "<<sha224().absorb(file).hexdigest() <<"\t" << argv[1]<< endl;
	else if(!strcmp(argv[1],"sha512/224"))
	cout <<"    SHA2-224: "<<sha512(224).absorb(file).hexdigest() <<"\t" << argv[1]<< endl;
	else if(!strcmp(argv[1],"sha3-224"))
	cout <<"    SHA3-224: "<<sha3(224).absorb(file).hexdigest() <<"\t" << argv[1]<< endl;
	else if(!strcmp(argv[1],"streebog-256"))
	cout <<"STREEBOG-256: "<<streebog(256).absorb(file).hexdigest()<<"\t" << argv[1] << endl;
	else if(!strcmp(argv[1],"streebog-512"))
	cout <<"STREEBOG-512: "<<streebog(512).absorb(file).hexdigest() <<"\t" << argv[1]<< endl;
	else
	cout <<"    SHA2-256: " <<sha256().absorb(file).hexdigest() <<"\t" << argv[1]<< endl;	
	
	}
	
	
	
	}
	
	
	
	
	if(argc !=3 )
	{
	
	cout << "File Integrity checker powered by digestpp" << endl;
	cout << "For just sha256 (SHA2-256): iecsum (filename) " << endl;
	cout << "For other methods: iecsum (sm3,sha,sha224,sha3-224,streebog-256,streebog-512,sha256,sha384,sha512,sha512/224,sha512/256,sha3-256,sha3-384,sha3-512 or whirlpool) (filename) " << endl;
	
	
	}
	
}


