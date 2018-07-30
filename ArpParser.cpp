// ArpParser.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>


int main()
{
	FILE *fp;
	char cmdOutput[128];

	fp = _popen("arp -a", "r");

	std::ofstream tempFile;
	tempFile.open("temp.txt");
	tempFile << "\t\t--ARP Table Results--\n\n";
	tempFile << "\tIP\t\t\tMAC\t\tType\n";
	tempFile << "______________________________________________________\n\n";

	std::vector<char *> arrOfIP;


	const char * substr1 = "In";
	const char * substr2 = "  In";
	const char * substr3 = "\n";

	while (std::fgets(cmdOutput, sizeof(cmdOutput), fp) != NULL)
	{
		if ((strncmp(cmdOutput, substr1, strlen(substr1)) == 0) || (strncmp(cmdOutput, substr2, strlen(substr2)) == 0) ||
			(strncmp(cmdOutput, substr3, strlen(substr3)) == 0)) {
			continue; // Do nothing
		}
		else {
			tempFile << cmdOutput << "\n";
			arrOfIP.push_back(cmdOutput);
		}
	}

	tempFile.close();
	_pclose(fp);

	return 0;
}