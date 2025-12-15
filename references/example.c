#include <gpgme.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <locale.h>

#define SIZE 1024

int main() {
	char * p;
	gpgme_error_t err;
	gpgme_engine_info_t enginfo;
	gpgme_ctx_t ceofcontext;
	gpgme_data_t data;
	int tmp;
	size_t read_bytes;

	setlocale(LC_ALL, "");
	p =(char *) gpgme_check_version(NULL);
	printf("version=%s\n",p);
	gpgme_set_locale(NULL, LC_CTYPE, setlocale (LC_CTYPE, NULL));

	/* check for OpenPGP support */
	err = gpgme_engine_check_version(GPGME_PROTOCOL_OpenPGP);
	if(err != GPG_ERR_NO_ERROR) return 1;
	p = (char *) gpgme_get_protocol_name(GPGME_PROTOCOL_OpenPGP);
	printf("Protocol name: %s\n",p);

	/* get engine information */
	err = gpgme_get_engine_info(&enginfo);
	if(err != GPG_ERR_NO_ERROR) return 2;
	printf("file=%s, home=%s, engine_version=%s, req_version=%s\n", 
			enginfo->file_name,enginfo->home_dir, enginfo->version, 
			enginfo->req_version);

	/* create our own context */
	err = gpgme_new(&ceofcontext);
	if(err != GPG_ERR_NO_ERROR) return 3;

	/* set protocol to use in our context */
	err = gpgme_set_protocol(ceofcontext,GPGME_PROTOCOL_OpenPGP);
	if(err != GPG_ERR_NO_ERROR) return 4;

	/* set engine info in our context */
	err = gpgme_ctx_set_engine_info (ceofcontext, GPGME_PROTOCOL_OpenPGP,
               enginfo->file_name,enginfo->home_dir);
	if(err != GPG_ERR_NO_ERROR) return 5;

	/* do ascii armor data, so output is readable in console */
	gpgme_set_armor(ceofcontext, 1);

	/* create buffer for data exchange with gpgme*/
	err = gpgme_data_new(&data);
	if(err != GPG_ERR_NO_ERROR) return 6;

	/* set encoding for the buffer... */
	err = gpgme_data_set_encoding(data,GPGME_DATA_ENCODING_ARMOR);
	if(err != GPG_ERR_NO_ERROR) return 7;

	/* verify encoding: not really needed */
	tmp = gpgme_data_get_encoding(data);
	if(tmp == GPGME_DATA_ENCODING_ARMOR) {
		printf("encode ok\n");
	} else {
    	printf("encode broken\n");
	}

	/* with NULL it exports all public keys */
	err = gpgme_op_export(ceofcontext,NULL,0,data);
	if(err != GPG_ERR_NO_ERROR) return 8;

	read_bytes = gpgme_data_seek (data, 0, SEEK_END);
	printf("end is=%d\n",read_bytes);
	if(read_bytes == -1) {
    	p = (char *) gpgme_strerror(errno);
    	printf("data-seek-err: %s\n",p);
    	return 9;
	}
	read_bytes = gpgme_data_seek (data, 0, SEEK_SET);
	printf("start is=%d (should be 0)\n",read_bytes);
}
