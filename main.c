/*****************************************************************************
# Author:			Timothy Q Pham
# Date:				Sept 09, 2025
# Version:			0.1 (Last Update: Nov 14, 2025)
# Description:		This program downloads the Linux ISO and all associated
#					files needed to verify the authenticity of the ISO. It does
#					this by downing the files from different sources.
# Sources:			https://www.gnupg.org/software/gpgme/
#****************************************************************************/

#include <gpgme-64.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#include <gpgme.h>

int main() {
	gpgme_error_t error;
	gpgme_ctx_t context;
	gpgme_data_t cipherText;
	gpgme_data_t plainText;

	const char * path = "./secret_msg.txt.gpg";
	int fileDescriptor;
	int flag = O_RDONLY;

	// Initialize GPGme and display the version number
	const char * version =  gpgme_check_version(NULL);
	printf("Using GPG version %s...\n", version);

	error = gpgme_new(&context);
	if(error != GPG_ERR_NO_ERROR) {
		printf("Couldn't create a new context!\n");
	}

	// Decrypt file (symmetric encryption)
	fileDescriptor = open(path, flag);
	if(fileDescriptor == -1) {
		printf("Error opening file!\n");
		printf("Reason: %i\n", errno);
	
		return EXIT_FAILURE;
	}

	// Load contents of file into cipherText
	error = gpgme_data_new_from_fd(&cipherText, fileDescriptor);
	if(error) {
		printf("Error loading cipherText!\n");
	}
	
	// Decrypt file
	error = gpgme_op_decrypt(context, cipherText, plainText);
	if(error) {
		printf("Error creating decrypting!\n");
	}

	// Clean up
	close(fileDescriptor);
	version = NULL;
	gpgme_release(context);
	gpgme_data_release(cipherText);
	return 0;
}
