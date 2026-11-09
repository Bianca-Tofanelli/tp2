#include "MyMaterial.h"

namespace cg {

    // Repassando a cor para a classe mãe, exatamente como você tinha feito!
    MyMaterial::MyMaterial(const Color& color) : Material(color) {
    }

    MyMaterial::~MyMaterial() {
    }

} // Fim do namespace cg