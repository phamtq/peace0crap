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
#include <sched.h>

int main() {
	gpgme_error_t error;
	gpgme_ctx_t context;

	gpgme_check_version(NULL);

}
