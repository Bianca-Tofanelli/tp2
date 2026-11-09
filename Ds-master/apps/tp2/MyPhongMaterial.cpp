#include "MyPhongMaterial.h"
#include <algorithm>
#include <cmath>

namespace cg {

    MyPhongMaterial::MyPhongMaterial(const Color& ambient,
                                     const Color& diffuse,
                                     const Color& specular,
                                     float shininess)
        : MyMaterial(diffuse),
          ambient(ambient),
          diffuse(diffuse),
          specular(specular),
          shininess(shininess) {
    }

    MyPhongMaterial::~MyPhongMaterial() {
    }

    Color MyPhongMaterial::shade(const vec3f& P, 
                                 const vec3f& N, 
                                 const vec3f& V, 
                                 const Light& light) const {
        // 1. Posição da luz usando o método position()
        vec3f lightPos = light.position();
        vec3f L = (lightPos - P).normalize();

        // 2. Cor da luz (no framework cg, usa-se a cor da própria fonte de luz)
        Color lightColor = Color::white; // Cor base da fonte de luz

        // Parcela Difusa (Lambertiana)
        float cosTheta = std::max(N.dot(L), 0.0f);
        Color diffuseComponent = diffuse * lightColor * cosTheta;

        // Parcela Especular (Phong)
        vec3f R = (N * (2.0f * N.dot(L)) - L).normalize();
        float cosAlpha = std::max(R.dot(V), 0.0f);
        float specFactor = std::pow(cosAlpha, shininess);
        Color specularComponent = specular * lightColor * specFactor;

        // Retorna a combinação das componentes difusa e especular
        return diffuseComponent + specularComponent;
    }

    std::string MyPhongMaterial::getGLSLShaderCode() const {
        return R"(
            vec3 L = normalize(lightPosition - vPos);
            vec3 V = normalize(cameraPosition - vPos);
            vec3 N = normalize(vNormal);

            vec3 amb = u_ambient;
            float diff = max(dot(N, L), 0.0);
            vec3 diffComp = u_diffuse * lightColor * diff;

            vec3 R = reflect(-L, N);
            float spec = pow(max(dot(R, V), 0.0), u_shininess);
            vec3 specComp = u_specular * lightColor * spec;

            fragColor = vec4(amb + diffComp + specComp, 1.0);
        )";
    }

} // namespace cg