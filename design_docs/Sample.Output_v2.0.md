# Sample Run
## When the image is valid
```
$ peace0crap -d fedora-42

Downloading:
- Distro image...
- Checksum file...
- Public key

Importing public key to keyring

Decrypting checksum

Image is valid. It is more likely than not safe to use.

Would you like to remove the public key for this distro? y
Deleting the public key...

Thank you for using the program. Please submit any suggestions or bugs to the repo: https://github.com/phamtq/peace0crap
```

## When the image is invalid
```
$ peace0crap -d fedora-42

Downloading:
- Distro image...
- Checksum file...
- Public key

Importing public key to keyring

Decrypting checksum

*** Image is NOT valid. ***
This does not automatically indicate malicious activity. Files could have been damaged in transit.

Would you like to remove the public key for this distro? n

Thank you for using the program. Please submit any suggestions or bugs to the repo: https://github.com/phamtq/peace0crap
```



