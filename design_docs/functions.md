# Program Functions
An outline of the various functions of the program along with some potential notes on how to approach implementing it.

## int main( *int argc, char \*argv[]* )
- Takes the command line arguments as input to determine which functions to call.

- Calls distro...() if the flags “`-d`” or “`--distro`” are used.
	- There is one function for every distro.

- Calls `helpInstructions()` if the flags “`-h`” or “`--help`” are used, if there are no arguments, or if invalid arguments are used.

- Calls closing message, `closingMsg()`, to let users know where to get an updated version of the program, submit bugs, and comments.

## int checkDistroFedora( *int version, char \*country* )
-  Called by `main()` when the user uses the flags "`-d`"/"`--distro`" and the argument "`fedora-42`".

- Calls the `download()` function to download the relevant files. 

- Calls `importPubKey()` to import the public key to the keyring.

- Calls `verifyChecksum()` to verifying that the checksum file's digest is legit.

- Calls `deleteKey()` to prompt the user if they want to delete the downloaded public key from the keyring and does it if requested.

- Calls `compareDigest()` to see if the digest from both hash functions match.

- Returns `0` if everything was okay, otherwise it returns a non-zero number (number helps determine the error for troubleshooting).

## int download( *char \*url* )
- Downloads the requested file from the Internet using the `curl` library.
- Return `0` if successful, `1` if it was not.

## void closingMsg()
- The closing message to let folks know where to get updates for the program, submit bugs, and comments.

## Changelog:
- **9/12/25**: Transferred stuff in other document format to markdown for easier editing and updating. Added functions for Fedora case and downloading.
