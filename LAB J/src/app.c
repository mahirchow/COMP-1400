/*
 * What is Caesar Cipher?
 *
 * It is one of the simplest encryption technique
 * in which each character in plain text is replaced
 * by a character some fixed number of positions down to it.
 *
 * For example, if key is 3 then we have to replace character
 * by another character that is 3 position down to it. Like A
 * will be replaced by D, C will be replaced by F and so on.
 *
 *  Created on: Nov. 25, 2019
 *      Author: Mahir Daian Chowdhury
 */

#include<stdio.h>
#include <string.h>

void encrypt(char text[100], int key) {
	char ch; //temp char variable

	//loop until you your reach the end of the text
	for (int i = 0; text[i] != '\0'; ++i) {
		ch = text[i]; //let temp ch equal the first char

		if (ch >= 'a' && ch <= 'z') { //[a-z]
			ch = ch + key;

			if (ch > 'z') {
				ch = ch - 'z' + 'a' - 1;
			}

			text[i] = ch; //replace that char with the new char
		} else if (ch >= 'A' && ch <= 'Z') { //[A-Z]
			ch = ch + key;

			if (ch > 'Z') {
				ch = ch - 'Z' + 'A' - 1;
			}

			text[i] = ch;
		}
	}

	printf("Encrypted message: %s\n", text);
}

void decrypt(char text[100], int key) {
	char ch;

	for (int i = 0; text[i] != '\0'; ++i) {
		ch = text[i];

		if (ch >= 'a' && ch <= 'z') {
			ch = ch - key;

			if (ch < 'a') {
				ch = ch + 'z' - 'a' + 1;
			}

			text[i] = ch;
		} else if (ch >= 'A' && ch <= 'Z') {
			ch = ch - key;

			if (ch < 'A') {
				ch = ch + 'Z' - 'A' + 1;
			}

			text[i] = ch;
		}
	}

	printf("Decrypted message: %s\n", text);
}

int main() {
	char text[100];
	int key;

	puts("\n0o0o0o0o0o0o0o0o0o0o0o0o0o0o0o0\n");

	printf("Enter a message to encrypt: ");
	scanf("%s", text);
	printf("Enter key: ");
	scanf("%d", &key);
	encrypt(text, key);

	puts("\n0o0o0o0o0o0o0o0o0o0o0o0o0o0o0o0\n");

	printf("Enter a message to decrypt: ");
	scanf("%s", text);
	printf("Enter key: ");
	scanf("%d", &key);
	decrypt(text, key);

	return 0;
}
