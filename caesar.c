#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // Testar primeiro se há argumento!
    if (argc != 2)
    {
        printf("usage : ./caesar key \n");
        return 1;
    }

    // Checar se a chave contém apenas números
    string keys = argv[1];

    for (int i = 0; i < strlen(keys); i++)
    {
        if (isalpha(keys[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);

    // De A a Z, maiusculos ou minusculos, considerando a = 0 e z = 26)
    if (key > 26)
    {
        key %= 26;
    }

    string plaintext = get_string("TEXTO SIMPLES: ");
    int tam_texto = strlen(plaintext);

    // Criptografar letra a letra
    for (int i = 0; i < tam_texto; i++)

    {
        if ((plaintext[i] >= 'a' && plaintext[i] <= 'z') || (plaintext[i] >= 'A' && plaintext[i] <= 'Z'))
        {
            if ((isupper(plaintext[i]) && plaintext[i] + key > 90) || (islower(plaintext[i]) && plaintext[i] + key > 122))
            {
                plaintext[i] = (int)plaintext[i] - 26;
            }

            plaintext[i] = (int)plaintext[i] + key;
        }
    }
    // Saída esperada
    printf("ciphertext: %s\n", plaintext); // escreve a mensagem criptografada
    return 0;
}
