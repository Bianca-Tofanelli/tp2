#ifndef MY_MATERIAL_H
#define MY_MATERIAL_H

#include "graphics/Material.h"
#include "graphics/Light.h"
#include "math/Vector3.h" 
#include <string>

namespace cg {

    class MyMaterial : public Material {
    public:
        // Voltando para a sua lógica brilhante: o material nasce com uma cor!
        MyMaterial(const Color& color = Color::white);
        virtual ~MyMaterial();

        // Método de tonalização para o Ray Tracing (A1)
        virtual Color shade(const vec3f& P, 
                            const vec3f& N, 
                            const vec3f& V, 
                            const Light& light) const = 0;

        // Métodos de Ray Tracing secundário (A1)
        virtual bool isReflective() const { return false; }
        virtual bool isTransparent() const { return false; }
        virtual Color getReflectionColor() const { return Color::black; }
        virtual Color getRefractionColor() const { return Color::black; }

        // Método auxiliar para geração de código GLSL (A1)
        virtual std::string getGLSLShaderCode() const = 0;
    };

} // Fim do namespace cg

#endif