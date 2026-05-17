#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    // Definir una ruta
    fs::path mi_ruta = "documentos/proyectos";

    // Unir rutas (agrega / o \ automáticamente)
    mi_ruta /= "reporte.pdf";

    std::cout << "Ruta completa: " << mi_ruta << "\n";
    std::cout << "Solo el archivo: " << mi_ruta.filename() << "\n";
    std::cout << "Extensión: " << mi_ruta.extension() << "\n";
    std::cout << "Carpeta superior: " << mi_ruta.parent_path() << "\n";

    return 0;
}
