#include <Arduino.h>

bool usuarioDesejaContinuar = true;
String textoUsuario;
int numeroUsuario;
float numeroFlutuanteUsuario;

void setup()
{
    Serial.begin(9600);
    while (!Serial)
    {
        delay(10);
    }
}

void loop()
{
    if (usuarioDesejaContinuar)
    {
        Serial.println("Digite um texto:");
        while (Serial.available() == 0)
        {
            delay(10);
        }
        textoUsuario = Serial.readString();

        Serial.println("Digite um número inteiro:");
        while (Serial.available() == 0)
        {
            delay(10);
        }
        numeroUsuario = Serial.parseInt();

        Serial.println("Digite um número flutuante:");
        while (Serial.available() == 0)
        {
            delay(10);
        }
        numeroFlutuanteUsuario = Serial.parseFloat();

        if (numeroUsuario > 10)
        {
            Serial.println("O número inteiro é maior que 10.");

            if (numeroFlutuanteUsuario > 20.0)
            {
                Serial.println("O número flutuante é maior que 20.0.");
            }
        }
        else
        {
            Serial.println("O número inteiro é menor ou igual a 10.");
        }

        if (textoUsuario.length() >= 5)
        {
            Serial.println("O texto inserido tem 5 ou mais caracteres.");
        }
        else
        {
            Serial.println("O texto inserido tem menos de 5 caracteres.");
        }

        Serial.println("Imprimindo os primeiros " + String(numeroUsuario) + " números inteiros:");
        for (int i = 1; i <= numeroUsuario; i++)
        {
            Serial.println(i);
        }

        Serial.println("Digite 1 para continuar ou 0 para encerrar.");
        while (Serial.available() == 0)
        {
            delay(10);
        }
        usuarioDesejaContinuar = static_cast<bool>(Serial.parseInt());
    }
    else
    {
        Serial.println("Programa encerrado.");
        while (true)
        {
            delay(10);
        }
    }
}
