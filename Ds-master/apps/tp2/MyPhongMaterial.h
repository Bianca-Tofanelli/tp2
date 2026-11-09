#ifndef MY_PHONG_MATERIAL_H
#define MY_PHONG_MATERIAL_H

#include "MyMaterial.h"
#include "graphics/Color.h"
#include "graphics/Light.h"
#include "math/Vector3.h"

namespace cg {

    class MyPhongMaterial : public MyMaterial {
    public:
        Color ambient;
        Color diffuse;
        Color specular;
        float shininess;

        MyPhongMaterial(const Color& ambient = Color::black,
                         const Color& diffuse = Color::white,
                         const Color& specular = Color::white,
                         float shininess = 10.0f);

        virtual ~MyPhongMaterial();

        virtual Color shade(const vec3f& P, 
                            const vec3f& N, 
                            const vec3f& V, 
                            const Light& light) const override;

        virtual std::string getGLSLShaderCode() const override;
    };

} // namespace cg

#endif // MY_PHONG_MATERIAL_H