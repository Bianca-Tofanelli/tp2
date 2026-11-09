#ifndef MY_MATERIAL_H
#define MY_MATERIAL_H

#include "graphics/Material.h"
#include "math/Vector3.h" 
#include "graphics/Light.h"

class MyMaterial : public cg::Material {
public:
    MyMaterial(const cg::Color& color = cg::Color::white);
    virtual ~MyMaterial();

    virtual cg::Color shade(const cg::vec3f& P, const cg::vec3f& N, const cg::vec3f& V, const cg::Light& light) const = 0;

    virtual bool isReflective() const = 0;
    virtual bool isTransparent() const = 0;
    virtual cg::Color getReflectionColor() const = 0;
    virtual cg::Color getRefractionColor() const = 0;

    virtual void setupShader() const = 0;
};

#endif