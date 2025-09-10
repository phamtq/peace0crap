/*****************************************************************************
# Author:			Timothy Q Pham
# Date:				Sept 09, 2025
# Version:			0.1 (Last Update: Sept 09, 2025)
# Description:		This program downloads the Linux ISO and all associated
#					files needed to verify the authenticity of the ISO. It does
#					this by downing the files from different sources.
# Sources:			https://www.gnupg.org/software/gpgme/
#****************************************************************************/

#include <gpgme-64.h>
#include <stdio.h>
#include <gpgme.h>

int main() {
	// Create variable for context, data, and error
	gpgme_ctx_t context;
	gpgme_data_t inputData;
	gpgme_err_code_t errorType;

	const char *version;

	// Checks to see if it's running the library version I'm using to make
	// this program. Also initializes sub-systems.
	version = gpgme_check_version("1.24.3");
	if(version == NULL) {
		printf("Requires version 1.24.3 or greater to run.\n");
		return 1;
	}
	
	printf("Library Version: %s\n", version);

	// TEST
	printf("Success! At least to this point...\n");
	
	return 0;
}
