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
#include <gpgme.h>

int main() {
	gpgme_error_t error;
	gpgme_ctx_t context;

	gpgme_data_t pubkey;

	// Initialize subsystems, etc...
	gpgme_check_version(NULL);
	gpgme_data_new_from_file(&pubkey, "pubkey.asc", 0);
	

	//gpgme_data_release(keyData);
	gpgme_release(context);
	
	return 0;
}
