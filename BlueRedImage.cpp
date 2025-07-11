#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream image("images/Imagem.ppm");

    if (!image.is_open())
    {
        cerr << "Erro ao criar o arquivo!" << endl;
        return 1;
    }

    int width = 70;
    int height = 50;

    // Cabeçalho do PPM (formato P3 = texto ASCII)
    image << "P3\n";
    image << width << " " << height << "\n";
    image << "255\n"; // valor máximo para cada canal RGB

    // Gera cada linha da imagem
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (x < width / 2)
            {
                image << "255 0 0 "; // vermelho
            }
            else
            {
                image << "0 0 255 "; // azul
            }
        }
        image << "\n";
    }

    image.close();
    cout << "Imagem gerada com sucesso!" << endl;
    return 0;
}
