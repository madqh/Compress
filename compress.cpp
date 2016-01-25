/* 
 * Madeline Hsia
 * Timothy Koh
 * File: compress.cpp
 * main for encoding
 */ 

#include "HCTree.hpp"
#include "HCNode.hpp"
#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char** argv) {

	/* scan textfile to compute frequencies
	 * build huffman tree
	 * find code for every symbol
	 * create new compressed file by saving entire code at top of file
	 * followed by code for each symbol
	 */ 

	 ifstream inFile;
	 inFile.open(argv[1],ifstream::in);

	 vector<int> freqs(256,0);

	 //computing frequency
	 while (1) {
	 	int theSymbol = inFile.get();
	 	if (inFile.eof()) break;
	 	freqs[theSymbol]++;
	 }

	 inFile.close();

	 //build huffman tree
	 HCTree huffmanTree;
	 huffmanTree.build(freqs);

	 //create new file to write
	 ofstream outFile;
	 outFile.open(argv[2],ofstream::out);

	 //for each element, print its frequency
	 for (int i=0; i<freqs.size(); i++) {
	 	outFile << freqs[i] << "\n";
	 }

	 inFile.open(argv[1],ifstream::in);

	 //loop to output file using encoded code
	 while(1) {
	 	char symbol = inFile.get();
	 	if (inFile.eof()) break;
	 	huffmanTree.encode(symbol, outFile);
	 }
	 return 0;
}